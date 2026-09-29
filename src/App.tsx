import { useEffect, useLayoutEffect, useMemo, useRef, useState } from 'react'
import DOMPurify from 'dompurify'
import hljs from 'highlight.js/lib/common'
import renderMathInElement from 'katex/contrib/auto-render'
import 'katex/dist/katex.min.css'
import { renderMarkdown } from './markdown'

type Kind = 'cpp' | 'md'
type CodeTheme = 'dark' | 'light'
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
  const [theme, setTheme] = useState<CodeTheme>(() => {
    const saved = localStorage.getItem('archive-theme')
    return saved === 'light' ? 'light' : 'dark'
  })
  const [manifest, setManifest] = useState<Manifest | null>(null)
  const [error, setError] = useState('')
  const [query, setQuery] = useState('')
  const [filter, setFilter] = useState<'all' | Kind>('all')
  const [selectedPath, setSelectedPath] = useState(hashPath)
  const [browsing, setBrowsing] = useState(() => Boolean(hashPath()))
  const [mobileView, setMobileView] = useState<'list' | 'viewer'>(() => hashPath() ? 'viewer' : 'list')
  const [readerScrollRestoreTop, setReaderScrollRestoreTop] = useState(0)
  const readerScrollTopRef = useRef(0)

  useEffect(() => {
    document.documentElement.dataset.theme = theme
    document.querySelector('meta[name="theme-color"]')?.setAttribute('content', theme === 'dark' ? '#11161c' : '#f6f7f9')
  }, [theme])
  useEffect(() => { document.body.dataset.mobileView = mobileView }, [mobileView])

  const load = () => fetch('./files.json')
    .then((response) => response.ok ? response.json() : Promise.reject(new Error(`清单加载失败 (${response.status})`)))
    .then((data: Manifest) => {
      if (data.schemaVersion !== 1 || !Array.isArray(data.files) || !data.files.length || data.count !== data.files.length) {
        throw new Error('文件清单格式不兼容或为空')
      }
      setManifest(data)
      setError('')
      if (selectedPath && !data.files.some((file) => file.path === selectedPath)) {
        history.replaceState(null, '', location.pathname + location.search)
        setSelectedPath('')
        setBrowsing(false)
        setMobileView('list')
      }
    })
    .catch((reason: Error) => setError(reason.message))

  useEffect(() => { void load() }, [])
  useEffect(() => {
    const onHash = () => {
      const path = hashPath()
      setSelectedPath(path)
      setBrowsing(Boolean(path))
      setMobileView(path ? 'viewer' : 'list')
    }
    addEventListener('hashchange', onHash)
    return () => removeEventListener('hashchange', onHash)
  }, [])

  const select = (path: string) => {
    const readerScrollTop = readerScrollTopRef.current || document.querySelector<HTMLElement>('.reader-body')?.scrollTop || 0
    setReaderScrollRestoreTop(readerScrollTop)
    location.hash = `file=${encodeURIComponent(path)}`
    setSelectedPath(path)
    setBrowsing(true)
    setMobileView('viewer')
    requestAnimationFrame(() => {
      const readerBody = document.querySelector<HTMLElement>('.reader-body')
      if (readerBody) readerBody.scrollTop = readerScrollTop
    })
  }
  const files = useMemo(() => manifest?.files.filter((file) =>
    (filter === 'all' || file.type === filter) && file.name.toLocaleLowerCase().includes(query.toLocaleLowerCase())
  ) ?? [], [manifest, filter, query])
  const selected = manifest?.files.find((file) => file.path === selectedPath) ?? null

  return <main className="app-shell" data-theme={theme}>
    <ArchiveTopbar count={manifest?.count} theme={theme} onHome={() => {
      history.pushState(null, '', location.pathname + location.search)
      setSelectedPath('')
      setBrowsing(false)
      setMobileView('list')
      readerScrollTopRef.current = 0
      setReaderScrollRestoreTop(0)
    }} onToggleTheme={() => {
      const next = theme === 'dark' ? 'light' : 'dark'
      localStorage.setItem('archive-theme', next)
      setTheme(next)
    }} />
    {error
      ? <section className="error-card" role="alert"><p>{error}</p><button onClick={() => void load()}>重试加载</button></section>
      : !browsing ? <ArchiveLanding manifest={manifest} onBrowse={() => setBrowsing(true)} onSelect={select} />
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
          codeTheme={theme}
          scrollRestoreTop={readerScrollRestoreTop}
          onReaderScroll={(value) => { readerScrollTopRef.current = value }}
          onSelect={select}
          onBack={() => setMobileView('list')}
        />
      </div>}
  </main>
}

function ArchiveTopbar({ count, theme, onHome, onToggleTheme }: { count?: number; theme: CodeTheme; onHome: () => void; onToggleTheme: () => void }) {
  return <header className="topbar">
    <div className="brand-lockup">
      <h1 className="brand-name"><button onClick={onHome} title="返回档案首页">算法档案</button></h1>
      <p className="brand-cn">tangyixiao / 代码与题解</p>
    </div>
    <div className="topbar-meta">
      <p className="archive-status">{count ? `收录 ${count.toLocaleString()} 个文件` : '正在加载文件清单'}</p>
      <button className="theme-toggle" onClick={onToggleTheme} aria-label={`切换为${theme === 'dark' ? '浅色' : '深色'}模式`}>
        <span aria-hidden="true">{theme === 'dark' ? '☀' : '☾'}</span>{theme === 'dark' ? '浅色' : '深色'}
      </button>
      <a className="home-link" href="https://tangyixiao.github.io/">个人主页 ↗</a>
    </div>
  </header>
}

function ArchiveLanding({ manifest, onBrowse, onSelect }: { manifest: Manifest | null; onBrowse: () => void; onSelect: (path: string) => void }) {
  const featured = ['P1001 A+B Problem.cpp', 'P1241 括号序列.cpp', 'P1241 括号序列.md', 'P9709 [KMOI R1] 军事行动.md']
  const matched = manifest ? featured.map((path) => manifest.files.find((file) => file.path === path)).filter((file): file is Entry => Boolean(file)) : []
  const preview = matched.length ? matched : manifest?.files.slice(0, 4) ?? []
  return <section className="landing" aria-labelledby="landing-title">
    <div className="landing-copy">
      <p className="landing-label">TANGYIXIAO / CODE ARCHIVE</p>
      <h2 id="landing-title">代码与题解，<br />都在这里。</h2>
      <p className="landing-description">收录 C++ 解题代码和 Markdown 题解。按题目编号或文件名查找，打开后可直接阅读原文件。</p>
      <div className="landing-actions">
        <button className="browse-button" onClick={onBrowse}>浏览文件 <span aria-hidden="true">↗</span></button>
        <span>{manifest ? `${manifest.count.toLocaleString()} 个文件` : '正在读取目录…'}</span>
      </div>
    </div>
    <div className="landing-preview" aria-label="目录预览">
      <div className="preview-head"><span>目录预览</span><span>CPP / MD</span></div>
      <div className="preview-list">
        {preview.map((file) => <button key={file.path} onClick={() => onSelect(file.path)}>
          <span className="preview-kind">{file.type === 'cpp' ? 'C++' : 'MD'}</span>
          <span className="preview-name">{file.name}</span>
          <span aria-hidden="true">↗</span>
        </button>)}
        {!manifest ? <p className="preview-loading">正在读取文件清单…</p> : null}
      </div>
      <p className="preview-note">选择文件，打开代码或题解</p>
    </div>
  </section>
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
      <div className="browser-title"><div><p className="utility-label">浏览目录</p><h2>文件</h2></div><span>{total.toLocaleString()}</span></div>
      <label className="search"><span aria-hidden="true">⌕</span><input aria-label="搜索文件" placeholder="搜索题目编号或文件名" value={query} onChange={(event) => onQuery(event.target.value)} /></label>
      <div className="filters" aria-label="文件类型筛选">
        <button className={filter === 'all' ? 'active' : ''} onClick={() => onFilter('all')}>全部</button>
        <button className={filter === 'cpp' ? 'active' : ''} onClick={() => onFilter('cpp')}>C++</button>
        <button className={filter === 'md' ? 'active' : ''} onClick={() => onFilter('md')}>Markdown</button>
      </div>
      <p className="count">显示 {files.length} / {total} 个文件</p>
    </div>
    <div className="file-list">
      {files.length === 0 && total > 0 ? <p className="empty-list">没有找到匹配的文件</p> : null}
      {files.map((file) => <button
        key={file.path}
        aria-label={`${file.type === 'cpp' ? 'C++' : 'Markdown'} ${file.name}`}
        aria-current={file.path === selectedPath ? 'true' : undefined}
        className={`file-row ${file.path === selectedPath ? 'selected' : ''}`}
        onMouseDown={(event) => { event.preventDefault(); onSelect(file.path) }}
        onClick={(event) => { if (event.detail === 0) onSelect(file.path) }}
      >
        <span className={`file-kind ${file.type}`}>{file.type === 'cpp' ? 'C++' : 'MD'}</span>
        <span className="file-name">{file.name}</span>
        <span className="file-arrow" aria-hidden="true">›</span>
      </button>)}
    </div>
  </aside>
}

type ReaderProps = {
  manifest: Manifest | null
  selected: Entry | null
  codeTheme: CodeTheme
  scrollRestoreTop: number
  onReaderScroll: (value: number) => void
  onSelect: (path: string) => void
  onBack: () => void
}

function ReaderPane({ manifest, selected, codeTheme, scrollRestoreTop, onReaderScroll, onSelect, onBack }: ReaderProps) {
  const readerBodyRef = useRef<HTMLDivElement>(null)
  const readerScrollRef = useRef(0)
  const pair = selected ? counterpart(selected.path, manifest?.files ?? []) : undefined
  const sourceUrl = selected && manifest ? `${RAW}${manifest.commit}/${rawPath(selected.path)}` : ''
  const restoreReaderScroll = () => {
    let frames = 0
    const restore = () => {
      if (readerBodyRef.current) {
        readerScrollRef.current = scrollRestoreTop
        readerBodyRef.current.scrollTop = scrollRestoreTop
      }
      frames += 1
      if (frames < 90) requestAnimationFrame(restore)
    }
    requestAnimationFrame(restore)
  }
  useEffect(() => {
    if (!selected || scrollRestoreTop <= 0) return
    const restore = () => {
      const readerBody = readerBodyRef.current
      if (readerBody) {
        readerBody.scrollTop = Math.min(scrollRestoreTop, readerBody.scrollHeight - readerBody.clientHeight)
      }
    }
    const observer = new MutationObserver(restore)
    if (readerBodyRef.current) observer.observe(readerBodyRef.current, { subtree: true, childList: true, characterData: true })
    const frame = requestAnimationFrame(restore)
    const settles = [100, 300, 700].map((delay) => window.setTimeout(restore, delay))
    return () => {
      cancelAnimationFrame(frame)
      settles.forEach((timer) => window.clearTimeout(timer))
      observer.disconnect()
    }
  }, [selected?.path, scrollRestoreTop])
  return <section className="reader" id="viewer" data-code-theme={codeTheme} aria-live="polite">
    <div className="reader-toolbar">
      <button className="mobile-back" onClick={onBack} aria-label="返回文件列表">← 文件</button>
      <div className="open-file"><p className="utility-label">当前文件</p><strong id="meta-name">{selected?.name ?? '选择文件'}</strong></div>
      {selected ? <div className="reader-actions">
        <a href={sourceUrl} target="_blank" rel="noreferrer">原文 ↗</a>
        <button onClick={() => navigator.clipboard.writeText(sourceUrl)}>复制链接</button>
        {pair ? <button onClick={() => onSelect(pair.path)}>查看{pair.type === 'cpp' ? '代码' : '题解'}</button> : null}
      </div> : null}
    </div>
    <div ref={readerBodyRef} className="reader-body" onScroll={(event) => {
      readerScrollRef.current = event.currentTarget.scrollTop
      onReaderScroll(event.currentTarget.scrollTop)
    }}>
      {selected && manifest ? <div key={selected.path} className="reader-document"><Source entry={selected} commit={manifest.commit} onReady={scrollRestoreTop > 0 ? restoreReaderScroll : undefined} /></div> : <div className="reader-empty">从左侧选择一个文件</div>}
    </div>
  </section>
}

function Source({ entry, commit, onReady }: { entry: Entry; commit: string; onReady?: () => void }) {
  const [source, setSource] = useState('')
  const [error, setError] = useState('')
  const [attempt, setAttempt] = useState(0)
  useEffect(() => {
    let live = true
    setSource('')
    setError('')
    fetch(`${RAW}${commit}/${rawPath(entry.path)}`)
      .then((response) => response.ok ? response.text() : Promise.reject(new Error(`正文加载失败 (${response.status})`)))
      .then((text) => { if (live) { setSource(text); onReady?.() } })
      .catch((reason: Error) => { if (live) setError(reason.message) })
    return () => { live = false }
  }, [entry.path, commit, attempt])
  useLayoutEffect(() => {
    if (source) onReady?.()
  }, [source])

  if (error) return <div className="reader-state reader-error"><p>{error}</p><button onClick={() => setAttempt((value) => value + 1)}>重试正文</button></div>
  if (!source) return <div className="reader-state reader-loading"><span />正在读取正文…</div>
  if (entry.type === 'cpp') return <pre className="code"><code className="hljs" dangerouslySetInnerHTML={{ __html: hljs.highlight(source, { language: 'cpp' }).value }} /></pre>
  return <Markdown source={source} onReady={onReady} />
}

function Markdown({ source, onReady }: { source: string; onReady?: () => void }) {
  const [element, setElement] = useState<HTMLElement | null>(null)
  const html = useMemo(() => DOMPurify.sanitize(renderMarkdown(source)), [source])
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
    onReady?.()
  }, [element, html, onReady])
  return <article className="markdown-body" ref={setElement} dangerouslySetInnerHTML={{ __html: html }} />
}

export default App
