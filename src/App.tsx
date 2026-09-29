import { lazy, Suspense, useEffect, useLayoutEffect, useMemo, useRef, useState, type CSSProperties } from 'react'
import DOMPurify from 'dompurify'
import hljs from 'highlight.js/lib/common'
import powershell from 'highlight.js/lib/languages/powershell'
import latex from 'highlight.js/lib/languages/latex'
import dos from 'highlight.js/lib/languages/dos'
import renderMathInElement from 'katex/contrib/auto-render'
import 'katex/dist/katex.min.css'
import { renderMarkdown } from './markdown'
import type { GitHistoryData } from './GitHistory'

type Kind = string
type CodeTheme = 'dark' | 'light'
type SortOrder = 'recent' | 'oldest' | 'name'
type Entry = { name: string; path: string; type: Kind; size: number; updatedAt: string; lastCommit: string }
type Folder = { name: string; path: string; count: number; updatedAt: string }
type Manifest = { schemaVersion: 2; commit: string; generatedAt: string; count: number; files: Entry[] }

const RAW = 'https://raw.githubusercontent.com/tangyixiao/Code/'
const GitHistory = lazy(() => import('./GitHistory'))
hljs.registerLanguage('powershell', powershell)
hljs.registerLanguage('latex', latex)
hljs.registerLanguage('dos', dos)
const languageNames: Record<string, string> = { cpp: 'C++', md: 'Markdown', py: 'Python', php: 'PHP', c: 'C', h: 'C/C++', hpp: 'C++', js: 'JavaScript', ts: 'TypeScript', tsx: 'TSX', html: 'HTML', css: 'CSS', sh: 'Shell', ps1: 'PowerShell', bat: 'Batch', tex: 'LaTeX', java: 'Java', go: 'Go', rs: 'Rust', cs: 'C#', sql: 'SQL', lua: 'Lua', rb: 'Ruby', swift: 'Swift', kt: 'Kotlin' }
const codeTypes = new Set(Object.keys(languageNames).filter((type) => type !== 'md'))
const textTypes = new Set([...codeTypes, 'md', 'txt', 'in', 'out', 'ans', 'json', 'yml', 'yaml', 'xml', 'svg', 'bib', 'gitignore', 'gitattributes', 'clang-format', 'cjs', 'mjs', 'toml', 'ini', 'cfg', 'csv', 'tsv'])
const imageTypes = new Set(['png', 'jpg', 'jpeg', 'gif', 'webp', 'svg'])
const highlightLanguages: Record<string, string> = { cpp: 'cpp', c: 'c', h: 'cpp', hpp: 'cpp', py: 'python', js: 'javascript', ts: 'typescript', tsx: 'typescript', html: 'xml', css: 'css', sh: 'bash', ps1: 'powershell', bat: 'dos', tex: 'latex', cjs: 'javascript', mjs: 'javascript', yml: 'yaml', svg: 'xml' }
const kindLabel = (type: string) => languageNames[type] ?? type.toUpperCase()
const badges: Record<string, string> = { cpp: 'C++', md: 'MD', py: 'PY', js: 'JS', ts: 'TS', tsx: 'TSX', php: 'PHP', html: 'HTML' }
const kindBadge = (type: string) => badges[type] ?? type.toUpperCase().slice(0, 4)
const isTextFile = (entry: Entry) => textTypes.has(entry.type) || ['.gitignore', '.gitattributes', '.clang-format', 'Makefile', 'Dockerfile'].includes(entry.name)
const highlightedCode = (source: string, type: string) => {
  const language = highlightLanguages[type] ?? type
  return hljs.getLanguage(language) ? hljs.highlight(source, { language }).value : source.replaceAll('&', '&amp;').replaceAll('<', '&lt;').replaceAll('>', '&gt;')
}
const fileNameCollator = new Intl.Collator('en', { numeric: true, sensitivity: 'base' })
const rawPath = (path: string) => path.split('/').map(encodeURIComponent).join('/')
const parentPath = (path: string) => path.includes('/') ? path.slice(0, path.lastIndexOf('/')) : ''
const counterpart = (path: string, files: Entry[]) => files.find((file) => file.path === path.replace(/\.(cpp|md)$/i, (_, ext) => ext === 'cpp' ? '.md' : '.cpp'))
const hashPath = () => {
  if (!location.hash.startsWith('#file=')) return ''
  try { return decodeURIComponent(location.hash.slice(6)) }
  catch { return '' }
}
const hashDirectory = () => {
  if (!location.hash.startsWith('#dir=')) return ''
  try { return decodeURIComponent(location.hash.slice(5)) }
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
  const [sortOrder, setSortOrder] = useState<SortOrder>('recent')
  const [selectedPath, setSelectedPath] = useState(hashPath)
  const [directory, setDirectory] = useState(() => parentPath(hashPath()) || hashDirectory())
  const [browsing, setBrowsing] = useState(() => Boolean(hashPath()) || location.hash.startsWith('#dir='))
  const [historyOpen, setHistoryOpen] = useState(() => location.hash === '#history')
  const [gitHistory, setGitHistory] = useState<GitHistoryData | null>(null)
  const [historyError, setHistoryError] = useState('')
  const [mobileView, setMobileView] = useState<'list' | 'viewer'>(() => hashPath() ? 'viewer' : 'list')
  const [readerScrollRestoreTop, setReaderScrollRestoreTop] = useState(0)
  const readerScrollTopRef = useRef(0)
  const [sidebarWidth, setSidebarWidth] = useState(() => {
    const saved = Number(localStorage.getItem('archive-sidebar-width'))
    return Number.isFinite(saved) && saved >= 240 ? saved : 296
  })
  const workspaceRef = useRef<HTMLDivElement>(null)
  const resizeWidthRef = useRef(sidebarWidth)
  const sidebarLimit = () => Math.max(240, (workspaceRef.current?.clientWidth ?? window.innerWidth) - 320)
  const setWorkspaceWidth = (width: number) => {
    const next = Math.max(240, Math.min(sidebarLimit(), width))
    resizeWidthRef.current = next
    workspaceRef.current?.style.setProperty('--sidebar-width', `${next}px`)
    workspaceRef.current?.querySelector('.pane-resizer')?.setAttribute('aria-valuenow', String(Math.round(next)))
  }
  const finishResize = () => {
    setSidebarWidth(resizeWidthRef.current)
    localStorage.setItem('archive-sidebar-width', String(Math.round(resizeWidthRef.current)))
  }
  useEffect(() => {
    if (!browsing) return
    const clampToViewport = () => {
      if (window.innerWidth <= 760 || resizeWidthRef.current <= sidebarLimit()) return
      setWorkspaceWidth(resizeWidthRef.current)
      finishResize()
    }
    clampToViewport()
    addEventListener('resize', clampToViewport)
    return () => removeEventListener('resize', clampToViewport)
  }, [browsing])

  useEffect(() => {
    document.documentElement.dataset.theme = theme
    document.querySelector('meta[name="theme-color"]')?.setAttribute('content', theme === 'dark' ? '#11161c' : '#f6f7f9')
  }, [theme])
  useEffect(() => { document.body.dataset.mobileView = mobileView }, [mobileView])
  useEffect(() => {
    if (!historyOpen || gitHistory || historyError) return
    let live = true
    fetch('./history.json')
      .then((response) => response.ok ? response.json() : Promise.reject(new Error(`提交历史加载失败 (${response.status})`)))
      .then((data: GitHistoryData) => {
        if (data.schemaVersion !== 1 || !Array.isArray(data.rows) || !Array.isArray(data.branches)) throw new Error('提交历史格式不兼容')
        if (live) setGitHistory(data)
      })
      .catch((reason: Error) => { if (live) setHistoryError(reason.message) })
    return () => { live = false }
  }, [historyOpen, gitHistory, historyError])

  const load = () => fetch('./files.json')
    .then((response) => response.ok ? response.json() : Promise.reject(new Error(`清单加载失败 (${response.status})`)))
    .then((data: Manifest) => {
      if (data.schemaVersion !== 2 || !Array.isArray(data.files) || !data.files.length || data.count !== data.files.length || !data.files.every((file) => file.updatedAt && file.lastCommit)) {
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
      if (location.hash === '#history') {
        setHistoryOpen(true)
        setSelectedPath('')
        setBrowsing(false)
        setMobileView('list')
        return
      }
      setHistoryOpen(false)
      const path = hashPath()
      setDirectory(path ? parentPath(path) : hashDirectory())
      setSelectedPath(path)
      setBrowsing(Boolean(path) || location.hash.startsWith('#dir='))
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
    setDirectory(parentPath(path))
    setBrowsing(true)
    setHistoryOpen(false)
    setMobileView('viewer')
    requestAnimationFrame(() => {
      const readerBody = document.querySelector<HTMLElement>('.reader-body')
      if (readerBody) readerBody.scrollTop = readerScrollTop
    })
  }
  const files = useMemo(() => {
    const matching = manifest?.files.filter((file) =>
      (filter === 'all' || (filter === 'other' ? !codeTypes.has(file.type) && file.type !== 'md' : file.type === filter)) &&
      (query ? file.path.toLocaleLowerCase().includes(query.toLocaleLowerCase()) : parentPath(file.path) === directory)
    ) ?? []
    if (sortOrder === 'recent') return matching
    return matching.sort((a, b) => sortOrder === 'name'
      ? fileNameCollator.compare(a.name, b.name)
      : Date.parse(a.updatedAt) - Date.parse(b.updatedAt) || fileNameCollator.compare(a.name, b.name))
  }, [manifest, filter, query, sortOrder, directory])
  const folders = useMemo(() => {
    const all = new Map<string, Folder>()
    for (const file of manifest?.files ?? []) {
      const parts = file.path.split('/')
      for (let index = 1; index < parts.length; index += 1) {
        const path = parts.slice(0, index).join('/')
        const folder = all.get(path) ?? { name: parts[index - 1], path, count: 0, updatedAt: file.updatedAt }
        folder.count += 1
        if (Date.parse(file.updatedAt) > Date.parse(folder.updatedAt)) folder.updatedAt = file.updatedAt
        all.set(path, folder)
      }
    }
    return [...all.values()].filter((folder) => parentPath(folder.path) === directory).sort((a, b) => sortOrder === 'name'
      ? fileNameCollator.compare(a.name, b.name)
      : (Date.parse(b.updatedAt) - Date.parse(a.updatedAt)) * (sortOrder === 'oldest' ? -1 : 1) || fileNameCollator.compare(a.name, b.name))
  }, [manifest, directory, sortOrder])
  const availableKinds = useMemo(() => [...new Set(manifest?.files.map((file) => file.type).filter((type) => codeTypes.has(type) && type !== 'cpp') ?? [])].sort((a, b) => fileNameCollator.compare(kindLabel(a), kindLabel(b))), [manifest])
  const selected = manifest?.files.find((file) => file.path === selectedPath) ?? null
  const openHome = () => {
    history.pushState(null, '', location.pathname + location.search)
    setSelectedPath('')
    setDirectory('')
    setBrowsing(false)
    setHistoryOpen(false)
    setMobileView('list')
    readerScrollTopRef.current = 0
    setReaderScrollRestoreTop(0)
  }
  const openBrowser = () => {
    history.pushState(null, '', location.pathname + location.search)
    setSelectedPath('')
    setDirectory('')
    setBrowsing(true)
    setHistoryOpen(false)
    setMobileView('list')
  }
  const openHistory = () => {
    history.pushState(null, '', '#history')
    setSelectedPath('')
    setBrowsing(false)
    setHistoryOpen(true)
    setMobileView('list')
  }
  const openDirectory = (path: string) => {
    location.hash = `dir=${encodeURIComponent(path)}`
    setDirectory(path)
    setSelectedPath('')
    setQuery('')
    setBrowsing(true)
    setHistoryOpen(false)
    setMobileView('list')
  }

  return <main className="app-shell" data-theme={theme}>
    <ArchiveTopbar count={manifest?.count} theme={theme} view={historyOpen ? 'history' : browsing ? 'files' : 'home'} onHome={openHome} onBrowse={openBrowser} onHistory={openHistory} onToggleTheme={() => {
      const next = theme === 'dark' ? 'light' : 'dark'
      localStorage.setItem('archive-theme', next)
      setTheme(next)
    }} />
    {historyOpen
      ? historyError ? <section className="error-card" role="alert"><p>{historyError}</p><button onClick={() => setHistoryError('')}>重试加载</button></section>
        : gitHistory ? <Suspense fallback={<div className="history-state">正在准备提交图…</div>}><GitHistory data={gitHistory} /></Suspense>
          : <div className="history-state">正在读取提交历史…</div>
      : error
      ? <section className="error-card" role="alert"><p>{error}</p><button onClick={() => void load()}>重试加载</button></section>
      : !browsing ? <ArchiveLanding manifest={manifest} onBrowse={openBrowser} onSelect={select} />
      : <div className="workspace" ref={workspaceRef} style={{ '--sidebar-width': `${sidebarWidth}px` } as CSSProperties}>
        <FileBrowser
          files={files}
          folders={query ? [] : folders}
          directory={directory}
          availableKinds={availableKinds}
          total={manifest?.count ?? 0}
          selectedPath={selectedPath}
          query={query}
          filter={filter}
          sortOrder={sortOrder}
          onQuery={setQuery}
          onFilter={setFilter}
          onSortOrder={setSortOrder}
          onSelect={select}
          onDirectory={openDirectory}
        />
        <div className="pane-resizer" role="separator" tabIndex={0} aria-label="调整文件列表宽度" aria-orientation="vertical" aria-valuemin={240} aria-valuemax={sidebarLimit()} aria-valuenow={sidebarWidth}
          onPointerDown={(event) => { if (event.button === 0) event.currentTarget.setPointerCapture(event.pointerId) }}
          onPointerMove={(event) => { if (event.currentTarget.hasPointerCapture(event.pointerId)) setWorkspaceWidth(event.clientX - (workspaceRef.current?.getBoundingClientRect().left ?? 0)) }}
          onPointerUp={(event) => { if (event.currentTarget.hasPointerCapture(event.pointerId)) { event.currentTarget.releasePointerCapture(event.pointerId); finishResize() } }}
          onPointerCancel={finishResize}
          onDoubleClick={() => { setWorkspaceWidth(296); finishResize() }}
          onKeyDown={(event) => {
            const next = event.key === 'ArrowLeft' ? sidebarWidth - 24 : event.key === 'ArrowRight' ? sidebarWidth + 24 : event.key === 'Home' ? 240 : event.key === 'End' ? sidebarLimit() : null
            if (next !== null) { event.preventDefault(); setWorkspaceWidth(next); finishResize() }
          }}
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

function ArchiveTopbar({ count, theme, view, onHome, onBrowse, onHistory, onToggleTheme }: { count?: number; theme: CodeTheme; view: 'home' | 'files' | 'history'; onHome: () => void; onBrowse: () => void; onHistory: () => void; onToggleTheme: () => void }) {
  return <header className="topbar">
    <div className="brand-lockup">
      <h1 className="brand-name"><button onClick={onHome} title="返回档案首页">算法档案</button></h1>
      <p className="brand-cn">tangyixiao / 代码与题解</p>
    </div>
    <nav className="site-nav" aria-label="站点导航">
      <button className={view === 'files' ? 'active' : ''} aria-current={view === 'files' ? 'page' : undefined} onClick={onBrowse}>文件</button>
      <button className={view === 'history' ? 'active' : ''} aria-current={view === 'history' ? 'page' : undefined} onClick={onHistory}>Git 历程</button>
    </nav>
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
      <p className="landing-description">浏览仓库中的代码、题解与项目文件。按题目编号、文件名或路径查找，打开后可直接查看原文件。</p>
      <div className="landing-actions">
        <button className="browse-button" onClick={onBrowse}>浏览文件 <span aria-hidden="true">↗</span></button>
        <span>{manifest ? `${manifest.count.toLocaleString()} 个文件` : '正在读取目录…'}</span>
      </div>
    </div>
    <div className="landing-preview" aria-label="目录预览">
      <div className="preview-head"><span>目录预览</span><span>REPOSITORY</span></div>
      <div className="preview-list">
        {preview.map((file) => <button key={file.path} onClick={() => onSelect(file.path)}>
          <span className="preview-kind">{kindBadge(file.type)}</span>
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
  folders: Folder[]
  directory: string
  availableKinds: string[]
  total: number
  selectedPath: string
  query: string
  filter: Kind
  sortOrder: SortOrder
  onQuery: (value: string) => void
  onFilter: (value: Kind) => void
  onSortOrder: (value: SortOrder) => void
  onSelect: (path: string) => void
  onDirectory: (path: string) => void
}

function FileBrowser({ files, folders, directory, availableKinds, total, selectedPath, query, filter, sortOrder, onQuery, onFilter, onSortOrder, onSelect, onDirectory }: BrowserProps) {
  const crumbs = directory ? directory.split('/') : []
  const [folderHeight, setFolderHeight] = useState(() => {
    const saved = Number(localStorage.getItem('archive-folder-height'))
    return Number.isFinite(saved) && saved >= 80 ? saved : 185
  })
  const [foldersCollapsed, setFoldersCollapsed] = useState(() => localStorage.getItem('archive-folders-collapsed') === 'true')
  const sidebarRef = useRef<HTMLElement>(null)
  const folderHeightRef = useRef(folderHeight)
  const folderLimit = () => Math.max(80, (sidebarRef.current?.clientHeight ?? window.innerHeight) - (sidebarRef.current?.querySelector<HTMLElement>('.browser-head')?.offsetHeight ?? 0) - 145)
  const resizeFolders = (height: number) => {
    const next = Math.max(80, Math.min(folderLimit(), height))
    folderHeightRef.current = next
    sidebarRef.current?.style.setProperty('--folder-pane-height', `${next}px`)
    sidebarRef.current?.querySelector('.stack-resizer')?.setAttribute('aria-valuenow', String(Math.round(next)))
  }
  const saveFolderHeight = () => {
    setFolderHeight(folderHeightRef.current)
    localStorage.setItem('archive-folder-height', String(Math.round(folderHeightRef.current)))
  }
  useEffect(() => {
    const clampToViewport = () => {
      if (folderHeightRef.current <= folderLimit()) return
      resizeFolders(folderHeightRef.current)
      saveFolderHeight()
    }
    clampToViewport()
    addEventListener('resize', clampToViewport)
    return () => removeEventListener('resize', clampToViewport)
  }, [])
  return <aside ref={sidebarRef} className={`sidebar${folders.length ? ' has-folders' : ''}${foldersCollapsed ? ' folders-collapsed' : ''}`} style={{ '--folder-pane-height': `${folderHeight}px` } as CSSProperties} aria-label="文件列表">
    <div className="browser-head">
      <div className="browser-title"><div><p className="utility-label">浏览目录</p><h2>文件</h2></div><span>{total.toLocaleString()}</span></div>
      <label className="search"><span aria-hidden="true">⌕</span><input aria-label="搜索文件" placeholder="搜索文件名或路径" value={query} onChange={(event) => onQuery(event.target.value)} /></label>
      <div className="filters" aria-label="文件类型筛选">
        <button className={filter === 'all' ? 'active' : ''} onClick={() => onFilter('all')}>全部</button>
        <button className={filter === 'cpp' ? 'active' : ''} onClick={() => onFilter('cpp')}>C++</button>
        <button className={filter === 'md' ? 'active' : ''} onClick={() => onFilter('md')}>Markdown</button>
        <select aria-label="其他语言与文件类型" value={filter === 'all' || filter === 'cpp' || filter === 'md' ? '' : filter} onChange={(event) => onFilter(event.target.value)}>
          <option value="" disabled>更多类型</option>
          {availableKinds.map((kind) => <option key={kind} value={kind}>{kindLabel(kind)}</option>)}
          <option value="other">其他文件</option>
        </select>
      </div>
      <nav className="folder-breadcrumb" aria-label="当前目录"><button onClick={() => onDirectory('')}>仓库</button>{crumbs.map((name, index) => <span key={index}><span aria-hidden="true">/</span><button onClick={() => onDirectory(crumbs.slice(0, index + 1).join('/'))}>{name}</button></span>)}</nav>
      <div className="list-meta">
        <p className="count">显示 {files.length} / {total} 个文件</p>
        <label className="sort-label">排序
          <select aria-label="文件排序" value={sortOrder} onChange={(event) => onSortOrder(event.target.value as SortOrder)}>
            <option value="recent">最近提交</option>
            <option value="oldest">最早提交</option>
            <option value="name">文件名</option>
          </select>
        </label>
      </div>
    </div>
    {folders.length ? <><div className="folder-area"><div className="folder-area-title"><button aria-label={foldersCollapsed ? '展开文件夹' : '折叠文件夹'} aria-expanded={!foldersCollapsed} onClick={() => {
      setFoldersCollapsed((value) => { localStorage.setItem('archive-folders-collapsed', String(!value)); return !value })
    }}><span aria-hidden="true">{foldersCollapsed ? '▸' : '▾'}</span> 文件夹</button><span>{folders.length}</span></div><div className="folder-list">{folders.map((folder) => <button className="folder-row" key={folder.path} onClick={() => onDirectory(folder.path)} title={folder.path}><span className="folder-icon" aria-hidden="true">▸</span><span className="folder-name">{folder.name}</span><span className="folder-count">{folder.count}</span></button>)}</div></div>
      <div className="stack-resizer" role="separator" tabIndex={foldersCollapsed ? -1 : 0} aria-label="调整文件夹区域高度" aria-orientation="horizontal" aria-valuemin={80} aria-valuemax={folderLimit()} aria-valuenow={folderHeight}
        onPointerDown={(event) => { if (event.button === 0) event.currentTarget.setPointerCapture(event.pointerId) }}
        onPointerMove={(event) => { if (event.currentTarget.hasPointerCapture(event.pointerId)) resizeFolders(event.clientY - (sidebarRef.current?.querySelector('.folder-area')?.getBoundingClientRect().top ?? 0)) }}
        onPointerUp={(event) => { if (event.currentTarget.hasPointerCapture(event.pointerId)) { event.currentTarget.releasePointerCapture(event.pointerId); saveFolderHeight() } }}
        onPointerCancel={saveFolderHeight}
        onDoubleClick={() => { resizeFolders(185); saveFolderHeight() }}
        onKeyDown={(event) => {
          const next = event.key === 'ArrowUp' ? folderHeight - 24 : event.key === 'ArrowDown' ? folderHeight + 24 : event.key === 'Home' ? 80 : event.key === 'End' ? folderLimit() : null
          if (next !== null) { event.preventDefault(); resizeFolders(next); saveFolderHeight() }
        }}
      /></> : null}
    <div className="file-list">
      {files.length === 0 && folders.length === 0 && total > 0 ? <p className="empty-list">没有找到匹配的文件</p> : null}
      {files.map((file) => <button
        key={file.path}
        aria-label={`${kindLabel(file.type)} ${file.path}`}
        aria-current={file.path === selectedPath ? 'true' : undefined}
        className={`file-row ${file.path === selectedPath ? 'selected' : ''}`}
        onMouseDown={(event) => { event.preventDefault(); onSelect(file.path) }}
        onClick={(event) => { if (event.detail === 0) onSelect(file.path) }}
      >
        <span className={`file-kind ${file.type}`}>{kindBadge(file.type)}</span>
        <span className="file-name" title={file.path}>{query ? file.path : file.name}</span>
        <time className="file-date" dateTime={file.updatedAt}>{file.updatedAt.slice(0, 10)}</time>
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
      {selected && manifest ? <div key={selected.path} className={`reader-document ${selected.type !== 'md' && isTextFile(selected) ? 'reader-code-document' : ''}`}><Source entry={selected} commit={manifest.commit} onReady={scrollRestoreTop > 0 ? restoreReaderScroll : undefined} /></div> : <div className="reader-empty">从左侧选择一个文件</div>}
    </div>
  </section>
}

function Source({ entry, commit, onReady }: { entry: Entry; commit: string; onReady?: () => void }) {
  const [source, setSource] = useState<string | null>(null)
  const [error, setError] = useState('')
  const [attempt, setAttempt] = useState(0)
  const previewable = isTextFile(entry) && !imageTypes.has(entry.type)
  const sourceUrl = `${RAW}${commit}/${rawPath(entry.path)}`
  useEffect(() => {
    if (!previewable) return
    let live = true
    setSource(null)
    setError('')
    fetch(sourceUrl)
      .then((response) => response.ok ? response.text() : Promise.reject(new Error(`正文加载失败 (${response.status})`)))
      .then((text) => { if (live) { setSource(text); onReady?.() } })
      .catch((reason: Error) => { if (live) setError(reason.message) })
    return () => { live = false }
  }, [entry.path, commit, attempt, previewable])
  useLayoutEffect(() => {
    if (source !== null) onReady?.()
  }, [source])

  if (imageTypes.has(entry.type)) return <div className="asset-preview"><img src={sourceUrl} alt={entry.name} /><p>{entry.path}</p></div>
  if (!previewable) return <div className="binary-preview"><span className="binary-icon" aria-hidden="true">◇</span><h2>{entry.name}</h2><p>{entry.path}</p><p>{(entry.size / 1024).toLocaleString('zh-CN', { maximumFractionDigits: 1 })} KB · 此文件无法在网页中预览</p><a href={sourceUrl} target="_blank" rel="noreferrer">打开原文件 ↗</a></div>
  if (error) return <div className="reader-state reader-error"><p>{error}</p><button onClick={() => setAttempt((value) => value + 1)}>重试正文</button></div>
  if (source === null) return <div className="reader-state reader-loading"><span />正在读取正文…</div>
  if (entry.type !== 'md') return <div className="code-editor">
    <pre className="code-gutter" aria-hidden="true">{Array.from({ length: source.split(/\r\n|\r|\n/).length }, (_, index) => index + 1).join('\n')}</pre>
    <pre className="code"><code className="hljs" dangerouslySetInnerHTML={{ __html: highlightedCode(source, entry.type) }} /></pre>
  </div>
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
