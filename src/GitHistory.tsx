import { useEffect, useMemo, useRef, useState } from 'react'
import './history.css'

type CommitRow = { graph: string; sha?: string; parents?: string[]; committedAt?: string; author?: string; subject?: string }
type Branch = { name: string; sha: string; remote: boolean }
type PushRun = { id: number; head_sha: string; created_at: string; status: string; conclusion: string | null; html_url: string }
export type GitHistoryData = {
  schemaVersion: 1
  generatedAt: string
  buildCommit: string
  pushEvent: boolean
  remoteMain: string | null
  branches: Branch[]
  rows: CommitRow[]
}

const shortSha = (sha: string) => sha.slice(0, 7)
const dateText = (value?: string) => value ? new Intl.DateTimeFormat('zh-CN', { dateStyle: 'medium', timeStyle: 'short' }).format(new Date(value)) : ''
const runStatus = (run: PushRun) => run.status !== 'completed' ? '部署中' : run.conclusion === 'success' ? '部署成功' : run.conclusion === 'failure' ? '部署失败' : '已结束'

function Graph({ value, columns, connector = false, selected = false, root = false }: { value: string; columns: number; connector?: boolean; selected?: boolean; root?: boolean }) {
  const height = connector ? 22 : 44
  const width = 24 + columns * 12
  return <svg className="git-graph" width={width} height={height} viewBox={`0 0 ${width} ${height}`} aria-hidden="true">
    {Array.from(value).map((char, index) => {
      const x = 12 + index * 12
      const lane = char === '\\' ? Math.ceil(index / 2) : Math.floor(index / 2)
      const path = char === '|' || char === '*'
        ? `M ${x} 0 V ${root && char === '*' ? height / 2 : height}`
        : char === '\\' ? `M ${x - 12} 0 Q ${x} ${height / 2} ${x + 12} ${height}`
          : char === '/' ? `M ${x + 12} 0 Q ${x} ${height / 2} ${x - 12} ${height}`
            : char === '_' || char === '-' ? `M ${x - 12} ${height / 2} H ${x + 12}` : ''
      if (!path) return null
      return <g key={index} className={`git-lane-${lane % 6}`}>
        <path className="git-rail" d={path} />
        {char === '*' ? <><circle className="git-node-outline" cx={x} cy={height / 2} r={selected ? 9 : 7.5} /><circle className="git-node" cx={x} cy={height / 2} r={selected ? 5.5 : 4.8} /></> : null}
      </g>
    })}
  </svg>
}

export default function GitHistory({ data }: { data: GitHistoryData }) {
  const commits = useMemo(() => data.rows.filter((row): row is CommitRow & { sha: string } => Boolean(row.sha)), [data])
  const graphColumns = useMemo(() => Math.max(2, ...data.rows.map((row) => row.graph.length)), [data])
  const [selectedSha, setSelectedSha] = useState(data.remoteMain ?? commits[0]?.sha ?? '')
  const [pushRuns, setPushRuns] = useState<PushRun[] | null>(null)
  const [pushError, setPushError] = useState(false)
  const selected = commits.find((row) => row.sha === selectedSha) ?? commits[0]
  const rowRefs = useRef(new Map<string, HTMLButtonElement>())
  useEffect(() => {
    const controller = new AbortController()
    fetch('https://api.github.com/repos/tangyixiao/Code/actions/workflows/pages.yml/runs?event=push&branch=main&per_page=8', { signal: controller.signal, headers: { Accept: 'application/vnd.github+json' } })
      .then((response) => response.ok ? response.json() : Promise.reject(new Error(`GitHub API ${response.status}`)))
      .then((result: { workflow_runs?: PushRun[] }) => {
        if (!Array.isArray(result.workflow_runs)) throw new Error('GitHub API response is missing workflow runs')
        setPushRuns(result.workflow_runs)
      })
      .catch(() => { if (!controller.signal.aborted) setPushError(true) })
    return () => controller.abort()
  }, [])
  const pushesBySha = useMemo(() => new Map(pushRuns?.map((run) => [run.head_sha, run]) ?? []), [pushRuns])
  const refsBySha = useMemo(() => {
    const result = new Map<string, Branch[]>()
    for (const branch of data.branches) result.set(branch.sha, [...(result.get(branch.sha) ?? []), branch])
    return result
  }, [data])
  const select = (sha: string) => {
    setSelectedSha(sha)
    rowRefs.current.get(sha)?.scrollIntoView({ block: 'center', behavior: 'auto' })
  }

  return <section className="history-page" aria-labelledby="history-title">
    <header className="history-intro">
      <div>
        <p className="utility-label">REPOSITORY / GIT</p>
        <h2 id="history-title">Git 历程</h2>
        <p>沿着分叉与合并，回看代码怎样走到现在。</p>
      </div>
      <div className="history-count"><strong>{commits.length.toLocaleString()}</strong><span>条提交</span></div>
    </header>
    <div className="history-layout">
      <aside className="history-branches" aria-label="分支">
        <div className="history-section-head"><h3>分支</h3><span>{data.branches.length}</span></div>
        <div className="branch-list">
          {data.branches.map((branch) => <button key={branch.name} className={selected?.sha === branch.sha ? 'selected' : ''} onClick={() => select(branch.sha)}>
            <span className="branch-icon" aria-hidden="true">⑂</span>
            <span className="branch-name">{branch.name}</span>
            <span className="branch-sha">{shortSha(branch.sha)}</span>
          </button>)}
        </div>
        <div className="history-push">
          <span className="push-dot" aria-hidden="true" />
          <div><strong>{data.pushEvent ? '本次由 main 推送触发' : '远端 main 当前指向'}</strong>
            <p>{data.remoteMain ? shortSha(data.remoteMain) : '当前构建没有远端指针'}</p>
          </div>
        </div>
        <div className="push-runs">
          <div className="history-section-head"><h3>推送与部署</h3><span>GITHUB ACTIONS</span></div>
          {pushRuns?.length ? <div className="push-run-list">{pushRuns.map((run) => <button key={run.id} onClick={() => select(run.head_sha)}>
            <span className={`run-status ${run.conclusion === 'success' ? 'success' : run.conclusion === 'failure' ? 'failure' : ''}`} aria-hidden="true" />
            <span className="run-main"><strong>{shortSha(run.head_sha)}</strong><small>{dateText(run.created_at)}</small></span>
            <span className="run-result">{runStatus(run)}</span>
          </button>)}</div> : <p className="push-run-state">{pushError ? '暂时无法读取部署记录。' : pushRuns ? '暂无推送记录。' : '正在读取推送记录…'} <a href="https://github.com/tangyixiao/Code/actions/workflows/pages.yml" target="_blank" rel="noreferrer">GitHub Actions ↗</a></p>}
        </div>
      </aside>
      <div className="history-commits" aria-label="提交关系图">
        <div className="history-section-head"><h3>提交图</h3><span>新 → 旧</span></div>
        <div className="commit-list">
          {data.rows.map((row, index) => row.sha
            ? <button key={row.sha} ref={(element) => { if (element) rowRefs.current.set(row.sha!, element); else rowRefs.current.delete(row.sha!) }} className={`commit-row${selected?.sha === row.sha ? ' selected' : ''}`} onClick={() => select(row.sha!)} aria-label={`${shortSha(row.sha)} ${row.subject}`}>
                <Graph value={row.graph} columns={graphColumns} selected={selected?.sha === row.sha} root={row.parents?.length === 0} />
                <span className="commit-content"><span className="commit-subject">{row.subject}</span><span className="commit-ref-list">{(refsBySha.get(row.sha) ?? []).map((branch) => <span key={branch.name} className={branch.remote ? 'remote' : ''}>{branch.name}</span>)}{pushesBySha.has(row.sha) ? <span className="push-ref">推送</span> : null}{row.sha === data.buildCommit ? <span className="build-ref">本站构建</span> : null}</span></span>
                <span className="commit-sha">{shortSha(row.sha)}</span>
              </button>
            : <div className="commit-connector" key={`connector-${index}`}><Graph value={row.graph} columns={graphColumns} connector /></div>)}
        </div>
      </div>
      <aside className="history-detail" aria-label="提交详情">
        <div className="history-section-head"><h3>提交详情</h3><span>COMMIT</span></div>
        {selected ? <div className="detail-content">
          <span className="detail-eyebrow">{selected.sha === data.remoteMain ? '远端 main' : '仓库提交'}</span>
          <h3>{selected.subject}</h3>
          <dl>
            <div><dt>提交</dt><dd className="mono">{selected.sha}</dd></div>
            <div><dt>作者</dt><dd>{selected.author}</dd></div>
            <div><dt>时间</dt><dd>{dateText(selected.committedAt)}</dd></div>
            <div><dt>父提交</dt><dd>{selected.parents?.length ? selected.parents.map((sha) => <button className="parent-link" key={sha} onClick={() => select(sha)}>{shortSha(sha)}</button>) : '初始提交'}</dd></div>
            {(refsBySha.get(selected.sha) ?? []).length ? <div><dt>分支指针</dt><dd>{refsBySha.get(selected.sha)?.map((branch) => branch.name).join('、')}</dd></div> : null}
            {pushesBySha.has(selected.sha) ? <div><dt>推送与部署</dt><dd><a className="run-link" href={pushesBySha.get(selected.sha)?.html_url} target="_blank" rel="noreferrer">{runStatus(pushesBySha.get(selected.sha)!)} · 查看运行 ↗</a></dd></div> : null}
          </dl>
          <a className="commit-link" href={`https://github.com/tangyixiao/Code/commit/${selected.sha}`} target="_blank" rel="noreferrer">在 GitHub 查看提交 ↗</a>
        </div> : <p className="history-empty">暂无提交</p>}
        <div className="history-note">Git 保存提交关系与当前分支指针。完整推送、构建与部署记录可在 <a href="https://github.com/tangyixiao/Code/actions/workflows/pages.yml" target="_blank" rel="noreferrer">GitHub Actions ↗</a> 查看。</div>
      </aside>
    </div>
  </section>
}
