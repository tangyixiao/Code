import { useEffect, useMemo, useState } from 'react'
import DOMPurify from 'dompurify'
import { marked } from 'marked'
import hljs from 'highlight.js/lib/common'
import renderMathInElement from 'katex/contrib/auto-render'
import 'katex/dist/katex.min.css'
import { AnimatePresence, motion, useReducedMotion } from 'motion/react'

type Kind = 'cpp' | 'md'
type Entry = { name: string; path: string; type: Kind; size: number }
type Manifest = { schemaVersion: 1; commit: string; generatedAt: string; count: number; files: Entry[] }

const RAW = 'https://raw.githubusercontent.com/tangyixiao/Code/'
const rawPath = (path: string) => path.split('/').map(encodeURIComponent).join('/')
const counterpart = (path: string, files: Entry[]) => files.find((file) => file.path === path.replace(/\.(cpp|md)$/i, (_, ext) => ext === 'cpp' ? '.md' : '.cpp'))
const hashPath = () => {
  try { return decodeURIComponent(location.hash.replace(/^#file=/, '')) }
  catch { return '' }
}

function App() {
  const [manifest, setManifest] = useState<Manifest | null>(null)
  const [error, setError] = useState('')
  const [query, setQuery] = useState('')
  const [filter, setFilter] = useState<'all' | Kind>('all')
  const [selectedPath, setSelectedPath] = useState(hashPath)
  const [mobileView, setMobileView] = useState<'list' | 'viewer'>(() => hashPath() ? 'viewer' : 'list')
  const reduced = useReducedMotion()

  useEffect(() => { document.body.dataset.motion = reduced ? 'reduced' : 'full' }, [reduced])
  useEffect(() => { document.body.dataset.mobileView = mobileView }, [mobileView])

  const load = () => fetch('./files.json')
    .then((response) => response.ok ? response.json() : Promise.reject(new Error(`清单加载失败 (${response.status})`)))
    .then((data: Manifest) => {
      if (data.schemaVersion !== 1 || !Array.isArray(data.files) || !data.files.length || data.count !== data.files.length) {
        throw new Error('文件清单格式不兼容或为空')
      }
      setManifest(data)
      setError('')
      if (!selectedPath || !data.files.some((file) => file.path === selectedPath)) {
        const firstPath = data.files[0].path
        history.replaceState(null, '', `#file=${encodeURIComponent(firstPath)}`)
        setSelectedPath(firstPath)
        setMobileView('list')
      }
    })
    .catch((reason: Error) => setError(reason.message))

  useEffect(() => { void load() }, [])
  useEffect(() => {
    const onHash = () => {
      const path = hashPath()
      setSelectedPath(path)
      if (path) setMobileView('viewer')
    }
    addEventListener('hashchange', onHash)
    return () => removeEventListener('hashchange', onHash)
  }, [])

  const select = (path: string) => {
    location.hash = `file=${encodeURIComponent(path)}`
    setSelectedPath(path)
    setMobileView('viewer')
  }
  const files = useMemo(() => manifest?.files.filter((file) =>
    (filter === 'all' || file.type === filter) && file.name.toLocaleLowerCase().includes(query.toLocaleLowerCase())
  ) ?? [], [manifest, filter, query])
  const selected = manifest?.files.find((file) => file.path === selectedPath) ?? null

  return <main className="app-shell">
    <AuroraField />
    <ArchiveTopbar count={manifest?.count} />
    {error
      ? <section className="error-card" role="alert"><p>{error}</p><button onClick={() => void load()}>重试加载</button></section>
      : <div className="workspace">
        <FileBrowser
          files={files}
          total={manifest?.count ?? 0}
          selectedPath={selectedPath}
          query={query}
          filter={filter}
          onQuery={setQuery}
          onFilter={setFilter}
          onSelect={select}
        />
        <ReaderPane
          manifest={manifest}
          selected={selected}
          reduced={Boolean(reduced)}
          onSelect={select}
          onBack={() => setMobileView('list')}
        />
      </div>}
  </main>
}

function AuroraField() {
  return <div className="aurora-field" aria-hidden="true">
    <span className="aurora-band aurora-band-a" />
    <span className="aurora-band aurora-band-b" />
    <span className="star-dust" />
  </div>
}

function ArchiveTopbar({ count }: { count?: number }) {
  return <header className="topbar">
    <a className="home-link" href="https://tangyixiao.github.io/" aria-label="返回个人主页">TY<span>↗</span></a>
    <div className="brand-lockup">
      <h1 className="brand-name">Paradox Praxis Clinamen</h1>
      <p className="brand-cn">佯谬·践履·偏斜</p>
    </div>
    <svg className="clinamen-mark" viewBox="0 0 320 34" role="img" aria-label="偏斜轨迹">
      <path className="orbit-line" d="M2 17H112C141 17 142 6 165 6S187 28 210 28 235 17 258 17h60" />
      <circle cx="165" cy="6" r="3" />
      <circle cx="210" cy="28" r="2" />
    </svg>
    <p className="archive-status"><span className="status-pulse" />{count ? `${count.toLocaleString()} FILES` : 'SYNCING'}</p>
  </header>
}

type BrowserProps = {
  files: Entry[]
  total: number
  selectedPath: string
  query: string
  filter: 'all' | Kind
  onQuery: (value: string) => void
  onFilter: (value: 'all' | Kind) => void
  onSelect: (path: string) => void
}

function FileBrowser({ files, total, selectedPath, query, filter, onQuery, onFilter, onSelect }: BrowserProps) {
  return <aside className="sidebar" aria-label="文件列表">
    <div className="browser-head">
      <div className="browser-title"><div><p className="utility-label">ALGORITHM ARCHIVE</p><h2>算法档案</h2></div><span>{total.toLocaleString()}</span></div>
      <label className="search"><span aria-hidden="true">⌕</span><input aria-label="搜索文件" placeholder="搜索题目编号或文件名" value={query} onChange={(event) => onQuery(event.target.value)} /></label>
      <div className="filters" aria-label="文件类型筛选">
        <button className={filter === 'all' ? 'active' : ''} onClick={() => onFilter('all')}>全部</button>
        <button className={filter === 'cpp' ? 'active' : ''} onClick={() => onFilter('cpp')}>C++</button>
        <button className={filter === 'md' ? 'active' : ''} onClick={() => onFilter('md')}>Markdown</button>
      </div>
      <p className="count">显示 {files.length} / {total} 个文件</p>
    </div>
    <div className="file-list">
      {files.map((file) => <button
        key={file.path}
        aria-label={`${file.type === 'cpp' ? 'C++' : 'Markdown'} ${file.name}`}
        aria-current={file.path === selectedPath ? 'true' : undefined}
        className={`file-row ${file.path === selectedPath ? 'selected' : ''}`}
        onClick={() => onSelect(file.path)}
      >
        <span className={`file-kind ${file.type}`}>{file.type === 'cpp' ? 'C++' : 'MD'}</span>
        <span className="file-name">{file.name}</span>
        <span className="file-arrow" aria-hidden="true">↗</span>
      </button>)}
    </div>
  </aside>
}

type ReaderProps = {
  manifest: Manifest | null
  selected: Entry | null
  reduced: boolean
  onSelect: (path: string) => void
  onBack: () => void
}

function ReaderPane({ manifest, selected, reduced, onSelect, onBack }: ReaderProps) {
  const pair = selected ? counterpart(selected.path, manifest?.files ?? []) : undefined
  const sourceUrl = selected && manifest ? `${RAW}${manifest.commit}/${rawPath(selected.path)}` : ''
  return <section className="reader" id="viewer" aria-live="polite">
    <div className="reader-toolbar">
      <button className="mobile-back" onClick={onBack} aria-label="返回文件列表">← 文件</button>
      <div className="open-file"><p className="utility-label">OPEN FILE</p><strong id="meta-name">{selected?.name ?? '选择文件'}</strong></div>
      {selected ? <div className="reader-actions">
        <a href={sourceUrl} target="_blank" rel="noreferrer">原文 ↗</a>
        <button onClick={() => navigator.clipboard.writeText(sourceUrl)}>复制链接</button>
        {pair ? <button onClick={() => onSelect(pair.path)}>查看{pair.type === 'cpp' ? '代码' : '题解'}</button> : null}
      </div> : null}
    </div>
    <div className="reader-body">
      <AnimatePresence mode="wait" initial={false}>
        {selected && manifest ? <motion.div
          key={selected.path}
          className="reader-document"
          initial={reduced ? false : { opacity: 0, y: 8 }}
          animate={{ opacity: 1, y: 0 }}
          exit={reduced ? undefined : { opacity: 0, y: -4 }}
          transition={{ duration: reduced ? 0 : 0.18, ease: 'easeOut' }}
        ><Source entry={selected} commit={manifest.commit} /></motion.div> : null}
      </AnimatePresence>
    </div>
  </section>
}

function Source({ entry, commit }: { entry: Entry; commit: string }) {
  const [source, setSource] = useState('')
  const [error, setError] = useState('')
  const [attempt, setAttempt] = useState(0)
  useEffect(() => {
    let live = true
    setSource('')
    setError('')
    fetch(`${RAW}${commit}/${rawPath(entry.path)}`)
      .then((response) => response.ok ? response.text() : Promise.reject(new Error(`正文加载失败 (${response.status})`)))
      .then((text) => { if (live) setSource(text) })
      .catch((reason: Error) => { if (live) setError(reason.message) })
    return () => { live = false }
  }, [entry.path, commit, attempt])

  if (error) return <div className="reader-state reader-error"><p>{error}</p><button onClick={() => setAttempt((value) => value + 1)}>重试正文</button></div>
  if (!source) return <div className="reader-state reader-loading"><span />正在读取正文…</div>
  if (entry.type === 'cpp') return <pre className="code"><code dangerouslySetInnerHTML={{ __html: hljs.highlight(source, { language: 'cpp' }).value }} /></pre>
  return <Markdown source={source} />
}

function Markdown({ source }: { source: string }) {
  const [element, setElement] = useState<HTMLElement | null>(null)
  const html = useMemo(() => DOMPurify.sanitize(marked.parse(source) as string), [source])
  useEffect(() => {
    if (element) renderMathInElement(element, {
      delimiters: [
        { left: '$$', right: '$$', display: true },
        { left: '$', right: '$', display: false },
        { left: '\\(', right: '\\)', display: false },
        { left: '\\[', right: '\\]', display: true },
      ],
      throwOnError: false,
    })
  }, [element, html])
  return <article className="markdown-body" ref={setElement} dangerouslySetInnerHTML={{ __html: html }} />
}

export default App
