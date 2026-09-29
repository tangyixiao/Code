import { createBundledHighlighter } from 'shiki/core'
import { createOnigurumaEngine } from 'shiki/engine/oniguruma'

const languages = {
  cpp: () => import('@shikijs/langs/cpp'), c: () => import('@shikijs/langs/c'),
  python: () => import('@shikijs/langs/python'), php: () => import('@shikijs/langs/php'),
  javascript: () => import('@shikijs/langs/javascript'), typescript: () => import('@shikijs/langs/typescript'),
  tsx: () => import('@shikijs/langs/tsx'), html: () => import('@shikijs/langs/html'),
  xml: () => import('@shikijs/langs/xml'), css: () => import('@shikijs/langs/css'),
  bash: () => import('@shikijs/langs/bash'), powershell: () => import('@shikijs/langs/powershell'),
  bat: () => import('@shikijs/langs/bat'), latex: () => import('@shikijs/langs/latex'),
  java: () => import('@shikijs/langs/java'), go: () => import('@shikijs/langs/go'),
  rust: () => import('@shikijs/langs/rust'), csharp: () => import('@shikijs/langs/csharp'),
  sql: () => import('@shikijs/langs/sql'), lua: () => import('@shikijs/langs/lua'),
  ruby: () => import('@shikijs/langs/ruby'), swift: () => import('@shikijs/langs/swift'),
  kotlin: () => import('@shikijs/langs/kotlin'), json: () => import('@shikijs/langs/json'),
  yaml: () => import('@shikijs/langs/yaml'), toml: () => import('@shikijs/langs/toml'),
  ini: () => import('@shikijs/langs/ini'), bibtex: () => import('@shikijs/langs/bibtex'),
  markdown: () => import('@shikijs/langs/markdown'),
}

const createHighlighter = createBundledHighlighter({
  langs: languages,
  themes: {
    'dark-plus': () => import('@shikijs/themes/dark-plus'),
    'light-plus': () => import('@shikijs/themes/light-plus'),
  },
  engine: () => createOnigurumaEngine(import('shiki/wasm')),
})
type Highlighter = Awaited<ReturnType<typeof createHighlighter>>

const aliases: Record<string, string> = {
  'c++': 'cpp', h: 'cpp', hpp: 'cpp', py: 'python', js: 'javascript', cjs: 'javascript', mjs: 'javascript',
  ts: 'typescript', sh: 'bash', shell: 'bash', zsh: 'bash', ps1: 'powershell', tex: 'latex',
  yml: 'yaml', svg: 'xml', bib: 'bibtex', cs: 'csharp', rs: 'rust', rb: 'ruby', kt: 'kotlin',
}

const escapeHtml = (value: string) => value.replaceAll('&', '&amp;').replaceAll('<', '&lt;').replaceAll('>', '&gt;').replaceAll('"', '&quot;')
const languageFor = (value: string) => {
  const language = aliases[value.toLowerCase()] ?? value.toLowerCase()
  return language in languages ? language as keyof typeof languages : 'text'
}

let highlighterPromise: Promise<Highlighter> | undefined
let loadingPromise: Promise<void> = Promise.resolve()
export async function getSyntaxHighlighter(requestedLanguages: string[]) {
  highlighterPromise ??= createHighlighter({ themes: ['dark-plus', 'light-plus'], langs: [] })
  const highlighter = await highlighterPromise
  const next = loadingPromise.catch(() => {}).then(async () => {
    for (const language of new Set(requestedLanguages.map(languageFor).filter((item) => item !== 'text'))) {
      if (!highlighter.getLoadedLanguages().includes(language)) await highlighter.loadLanguage(language)
    }
  })
  loadingPromise = next
  await next
  return highlighter
}

export function highlightLines(highlighter: Highlighter, source: string, language: string) {
  const tokens = highlighter.codeToTokens(source, {
    lang: languageFor(language),
    themes: { dark: 'dark-plus', light: 'light-plus' },
    defaultColor: false,
  }).tokens
  return tokens.map((line) => line.map((token) => {
    const styles = Object.entries(token.htmlStyle ?? {}).map(([key, value]) => `${key}:${value}`).join(';')
    return styles ? `<span style="${escapeHtml(styles)}">${escapeHtml(token.content)}</span>` : escapeHtml(token.content)
  }).join(''))
}

export function markdownLanguages(source: string) {
  return ['cpp', ...[...source.matchAll(/^[ \t]*(`{3,}|~{3,})([^\n]*)$/gm)]
    .map((match) => match[2].trim().split(/\s+/)[0])
    .filter(Boolean)]
}
