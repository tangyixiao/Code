import { bundledLanguages, createHighlighter, type Highlighter } from 'shiki'

const aliases: Record<string, string> = {
  h: 'cpp', hpp: 'cpp', py: 'python', js: 'javascript', cjs: 'javascript', mjs: 'javascript',
  ts: 'typescript', sh: 'bash', ps1: 'powershell', tex: 'latex', yml: 'yaml', svg: 'xml', bib: 'bibtex',
}

const escapeHtml = (value: string) => value.replaceAll('&', '&amp;').replaceAll('<', '&lt;').replaceAll('>', '&gt;').replaceAll('"', '&quot;')
const languageFor = (value: string) => {
  const language = aliases[value.toLowerCase()] ?? value.toLowerCase()
  return language in bundledLanguages ? language : 'text'
}

let highlighterPromise: Promise<Highlighter> | undefined
export async function getSyntaxHighlighter(languages: string[]) {
  highlighterPromise ??= createHighlighter({ themes: ['dark-plus', 'light-plus'], langs: [] })
  const highlighter = await highlighterPromise
  for (const language of new Set(languages.map(languageFor).filter((item) => item !== 'text'))) {
    if (!highlighter.getLoadedLanguages().includes(language)) await highlighter.loadLanguage(language as keyof typeof bundledLanguages)
  }
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
  return [...source.matchAll(/^[ \t]*(`{3,}|~{3,})([^\n]*)$/gm)]
    .map((match) => match[2].trim().split(/\s+/)[0])
    .filter(Boolean)
}
