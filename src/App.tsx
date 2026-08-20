import { useEffect, useMemo, useState } from 'react'
import DOMPurify from 'dompurify'
import { marked } from 'marked'
import hljs from 'highlight.js/lib/common'
import renderMathInElement from 'katex/contrib/auto-render'
import 'katex/dist/katex.min.css'
import { motion, useReducedMotion } from 'motion/react'

type Kind = 'cpp' | 'md'
type Entry = { name: string; path: string; type: Kind; size: number }
type Manifest = { schemaVersion: 1; commit: string; generatedAt: string; count: number; files: Entry[] }
const RAW = 'https://raw.githubusercontent.com/tangyixiao/Code/'
const rawPath = (path: string) => path.split('/').map(encodeURIComponent).join('/')
const counterpart = (path: string, files: Entry[]) => files.find((file) => file.path === path.replace(/\.(cpp|md)$/i, (_, ext) => ext === 'cpp' ? '.md' : '.cpp'))

function App() {
  const [manifest, setManifest] = useState<Manifest | null>(null)
  const [error, setError] = useState('')
  const [query, setQuery] = useState('')
  const [filter, setFilter] = useState<'all' | Kind>('all')
  const [selectedPath, setSelectedPath] = useState(() => decodeURIComponent(location.hash.replace(/^#file=/, '')) || '')
  const [mobileView, setMobileView] = useState<'list' | 'viewer'>('list')
  const reduced = useReducedMotion()
  useEffect(() => { document.body.dataset.motion = reduced ? 'reduced' : 'full' }, [reduced])
  useEffect(() => { document.body.dataset.mobileView = mobileView }, [mobileView])
  const load = () => fetch('./files.json').then((r) => r.ok ? r.json() : Promise.reject(new Error(`清单加载失败 (${r.status})`))).then((data: Manifest) => {
    if (data.schemaVersion !== 1 || !Array.isArray(data.files) || !data.files.length || data.count !== data.files.length) throw new Error('文件清单格式不兼容或为空')
    setManifest(data); setError('')
    if (!selectedPath || !data.files.some((file) => file.path === selectedPath)) {
      const firstPath = data.files[0].path
      location.hash = `file=${encodeURIComponent(firstPath)}`
      setSelectedPath(firstPath)
    }
  }).catch((reason: Error) => setError(reason.message))
  useEffect(() => { void load() }, [])
  useEffect(() => { const onHash = () => setSelectedPath(decodeURIComponent(location.hash.replace(/^#file=/, ''))); addEventListener('hashchange', onHash); return () => removeEventListener('hashchange', onHash) }, [])
  const select = (path: string) => { location.hash = `file=${encodeURIComponent(path)}`; setSelectedPath(path); setMobileView('viewer') }
  const files = useMemo(() => manifest?.files.filter((file) => (filter === 'all' || file.type === filter) && file.name.toLocaleLowerCase().includes(query.toLocaleLowerCase())) ?? [], [manifest, filter, query])
  const selected = manifest?.files.find((file) => file.path === selectedPath) ?? null
  return <main className="app-shell">
    <motion.header initial={reduced ? false : { opacity: 0, y: -16 }} animate={{ opacity: 1, y: 0 }} className="masthead">
      <a className="back-link" href="https://tangyixiao.github.io/">← 个人主页</a><div><p className="eyebrow">TANG YIXIAO / ARCHIVE</p><h1>Code<span>Hub</span></h1></div><p className="status">{manifest ? `${manifest.count.toLocaleString()} FILES` : 'LOADING'}</p>
    </motion.header>
    <section className="manifesto"><span>/* 思考 · 实现 · 迭代 */</span><strong>让每一次推导都有可追溯的代码。</strong></section>
    {error ? <section className="error-card"><p>{error}</p><button onClick={() => void load()}>重试加载</button></section> : <div className="workspace">
      <aside className="sidebar" aria-label="文件列表">
        <label className="search"><span>⌕</span><input placeholder="搜索题目编号或文件名" value={query} onChange={(event) => setQuery(event.target.value)} /></label>
        <div className="filters"><button className={filter === 'all' ? 'active' : ''} onClick={() => setFilter('all')}>全部</button><button className={filter === 'cpp' ? 'active' : ''} onClick={() => setFilter('cpp')}>C++</button><button className={filter === 'md' ? 'active' : ''} onClick={() => setFilter('md')}>Markdown</button></div>
        <p className="count">显示 {files.length} / {manifest?.count ?? 0} 个文件</p>
        <div className="file-list">{files.map((file) => <button key={file.path} aria-label={`${file.type === 'cpp' ? 'C++' : 'Markdown'} ${file.name}`} className={`file-row ${file.path === selectedPath ? 'selected' : ''}`} onClick={() => select(file.path)}><span className={file.type}>{file.type === 'cpp' ? 'C++' : 'MD'}</span>{file.name}</button>)}</div>
      </aside>
      <section className="reader" id="viewer" aria-live="polite">
        <div className="reader-toolbar"><button className="mobile-back" onClick={() => setMobileView('list')} aria-label="返回文件列表">← 文件</button><div><p className="eyebrow">OPEN FILE</p><strong id="meta-name">{selected?.name ?? '选择文件'}</strong></div>{selected && <div className="reader-actions"><a href={`${RAW}${manifest?.commit}/${rawPath(selected.path)}`} target="_blank" rel="noreferrer">原文</a><button onClick={() => navigator.clipboard.writeText(`${RAW}${manifest?.commit}/${rawPath(selected.path)}`)}>复制链接</button>{counterpart(selected.path, manifest?.files ?? []) && <button onClick={() => select(counterpart(selected.path, manifest?.files ?? [])!.path)}>查看配对文件</button>}</div>}</div>
        {selected && <Source entry={selected} commit={manifest!.commit} />}
      </section>
    </div>}
  </main>
}

function Source({ entry, commit }: { entry: Entry; commit: string }) {
  const [source, setSource] = useState(''); const [error, setError] = useState('')
  useEffect(() => { let live = true; setSource(''); setError(''); fetch(`${RAW}${commit}/${rawPath(entry.path)}`).then((r) => r.ok ? r.text() : Promise.reject(new Error(`正文加载失败 (${r.status})`))).then((text) => { if (live) setSource(text) }).catch((reason: Error) => { if (live) setError(reason.message) }); return () => { live = false } }, [entry.path, commit])
  if (error) return <div className="reader-error">{error}</div>
  if (!source) return <div className="reader-loading">正在读取正文…</div>
  if (entry.type === 'cpp') return <pre className="code"><code dangerouslySetInnerHTML={{ __html: hljs.highlight(source, { language: 'cpp' }).value }} /></pre>
  return <Markdown source={source} />
}

function Markdown({ source }: { source: string }) {
  const [element, setElement] = useState<HTMLElement | null>(null)
  const html = DOMPurify.sanitize(marked.parse(source) as string)
  useEffect(() => { if (element) renderMathInElement(element, { delimiters: [{ left: '$$', right: '$$', display: true }, { left: '$', right: '$', display: false }, { left: '\\(', right: '\\)', display: false }, { left: '\\[', right: '\\]', display: true }], throwOnError: false }) }, [element, html])
  return <article className="markdown-body" ref={setElement} dangerouslySetInnerHTML={{ __html: html }} />
}

export default App
