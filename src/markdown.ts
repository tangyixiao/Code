import { marked, type Tokens } from 'marked'
import hljs from 'highlight.js/lib/common'

const escapeHtml = (value: string) => value
  .replaceAll('&', '&amp;')
  .replaceAll('<', '&lt;')
  .replaceAll('>', '&gt;')
  .replaceAll('"', '&quot;')
  .replaceAll("'", '&#39;')

const parseAttributes = (value = '') => new Set(value.split(/[\s,]+/).map((item) => item.trim()).filter(Boolean))

const directiveOpening = /^ {0,3}(:{3,})([A-Za-z][\w-]*)(?:\[([^\]\n]*)\])?(?:\{([^}\n]*)\})?[ \t]*(?:\n|$)/
const inlineDirective = /^ {0,3}(:{3,})([A-Za-z][\w-]*)(?:\[([^\]\n]*)\])?(?:\{([^}\n]*)\})?[ \t]+([^\n]*?)\s+\1[ \t]*(?:\n|$)/
const closeDirective = /^ {0,3}(:{3,})[ \t]*$/
const openNestedDirective = /^ {0,3}(:{3,})([A-Za-z][\w-]*)/

function directiveToken(src: string, lexer: { blockTokens: (source: string) => Tokens.Generic[]; inlineTokens: (source: string) => Tokens.Generic[] }) {
  const singleLine = inlineDirective.exec(src)
  if (singleLine) {
    const [, marks, name, label, attrs, content] = singleLine
    return {
      type: 'luogu-directive',
      raw: singleLine[0],
      name,
      label,
      attrs,
      content,
      tokens: lexer.blockTokens(content),
      labelTokens: lexer.inlineTokens(label ?? ''),
    }
  }

  const opening = directiveOpening.exec(src)
  if (!opening) return
  const [openingRaw, marks, name, label, attrs] = opening
  const rest = src.slice(openingRaw.length)
  const stack = [marks.length]
  const lines = rest.split('\n')
  let offset = 0
  let closeStart = -1
  let closeEnd = -1

  for (let index = 0; index < lines.length; index += 1) {
    const line = lines[index]
    const nestedOpening = openNestedDirective.exec(line)
    const closing = closeDirective.exec(line)
    if (nestedOpening && nestedOpening[1].length > stack[stack.length - 1]) {
      stack.push(nestedOpening[1].length)
    } else if (closing && closing[1].length === stack[stack.length - 1]) {
      stack.pop()
      if (!stack.length) {
        closeStart = offset
        closeEnd = offset + line.length
        break
      }
    }
    offset += line.length + (index < lines.length - 1 ? 1 : 0)
  }

  if (closeStart < 0) return
  const content = rest.slice(0, closeStart).replace(/\n$/, '')
  const rawEnd = openingRaw.length + closeEnd + (rest[closeEnd] === '\n' ? 1 : 0)
  return {
    type: 'luogu-directive',
    raw: src.slice(0, rawEnd),
    name,
    label,
    attrs,
    content,
    tokens: lexer.blockTokens(content),
    labelTokens: lexer.inlineTokens(label ?? ''),
  }
}

function cuteTableToken(src: string, lexer: { blockTokens: (source: string) => Tokens.Generic[] }) {
  const opening = /^ {0,3}::cute-table(?:\{([^}\n]*)\})?[ \t]*(?:\n|$)/.exec(src)
  if (!opening) return
  const rest = src.slice(opening[0].length)
  const lines = rest.split('\n')
  let rowCount = 0
  while (rowCount < lines.length && lines[rowCount].includes('|')) rowCount += 1
  if (rowCount < 2) return
  const tableSource = lines.slice(0, rowCount).join('\n')
  const rawEnd = opening[0].length + tableSource.length + (rest[tableSource.length] === '\n' ? 1 : 0)
  return {
    type: 'luogu-cute-table',
    raw: src.slice(0, rawEnd),
    attrs: opening[1] ?? '',
    tokens: lexer.blockTokens(tableSource),
  }
}

type TableCell = Tokens.TableCell
type TableToken = Tokens.Table
type TableAnchor = { cell: TableCell; colspan: number; rowspan: number }

function cellMarker(cell: TableCell | undefined) {
  return cell?.text.trim() ?? ''
}

function renderTable(parser: { parseInline: (tokens: Tokens.Generic[]) => string }, table: TableToken, className: string, tuack?: string) {
  const rows = [table.header, ...table.rows]
  const columns = Math.max(0, ...rows.map((row) => row.length))
  const anchors: Array<Array<TableAnchor | null>> = []
  const outputRows: TableAnchor[][] = []

  rows.forEach((row, rowIndex) => {
    anchors[rowIndex] = Array.from({ length: columns }, () => null)
    outputRows[rowIndex] = []
    const expandedRowspans = new Set<TableAnchor>()

    row.forEach((cell, columnIndex) => {
      const marker = cellMarker(cell)
      if (marker === '^' || marker === '<' || marker === '>') return
      const anchor = { cell, colspan: 1, rowspan: 1 }
      anchors[rowIndex][columnIndex] = anchor
      outputRows[rowIndex].push(anchor)
    })

    row.forEach((cell, columnIndex) => {
      const marker = cellMarker(cell)
      if (marker === '^') {
        const anchor = anchors[rowIndex - 1]?.[columnIndex]
        if (anchor) {
          if (!expandedRowspans.has(anchor)) {
            anchor.rowspan += 1
            expandedRowspans.add(anchor)
          }
          anchors[rowIndex][columnIndex] = anchor
          return
        }
      }
      if (marker === '<') {
        const anchor = anchors[rowIndex].slice(0, columnIndex).reverse().find(Boolean)
        if (anchor) {
          anchor.colspan += 1
          anchors[rowIndex][columnIndex] = anchor
          return
        }
      }
      if (marker === '>') {
        const anchor = anchors[rowIndex].slice(columnIndex + 1).find(Boolean)
        if (anchor) {
          anchor.colspan += 1
          anchors[rowIndex][columnIndex] = anchor
        }
      }
    })
  })

  const renderCell = (anchor: TableAnchor) => {
    const { cell, colspan, rowspan } = anchor
    const tag = cell.header ? 'th' : 'td'
    const align = cell.align ? ` align="${cell.align}"` : ''
    const span = `${rowspan > 1 ? ` rowspan="${rowspan}"` : ''}${colspan > 1 ? ` colspan="${colspan}"` : ''}`
    return `<${tag}${align}${span}>${parser.parseInline(cell.tokens as Tokens.Generic[])}</${tag}>`
  }

  const header = outputRows[0]?.map(renderCell).join('') ?? ''
  const body = outputRows.slice(1).map((row) => `<tr>${row.map(renderCell).join('')}</tr>`).join('')
  const tableAttrs = tuack ? ` data-tuack="${escapeHtml(tuack)}"` : ''
  return `<table class="cute-table ${className}"${tableAttrs}><thead><tr>${header}</tr></thead><tbody>${body}</tbody></table>`
}

function renderCode({ text, lang }: Tokens.Code) {
  const languageAndMeta = (lang ?? '').trim().match(/^(\S+)?(?:\s+(.+))?$/)
  const language = languageAndMeta?.[1] || 'cpp'
  const meta = languageAndMeta?.[2] ?? ''
  const highlighted = new Set<number>()
  const lineRange = /(?:^|\s)lines=([\d,-]+)/.exec(meta)?.[1]
  lineRange?.split(',').forEach((range) => {
    const [start, end = start] = range.split('-').map(Number)
    if (!Number.isFinite(start) || !Number.isFinite(end)) return
    for (let line = start; line <= end; line += 1) highlighted.add(line)
  })

  const lines = text.split('\n').map((line, index) => {
    const lineNumber = index + 1
    const source = line || ' '
    const code = hljs.getLanguage(language) ? hljs.highlight(source, { language }).value : escapeHtml(source)
    const active = highlighted.has(lineNumber) ? ' data-highlighted="true"' : ''
    return `<span class="code-line" data-line="${lineNumber}"${active}><span class="line-number" aria-hidden="true">${lineNumber}</span><span class="line-content">${code}</span></span>`
  }).join('')

  return `<pre class="markdown-code-block" data-language="${escapeHtml(language)}"><code>${lines}</code></pre>`
}

const directiveExtension = {
  name: 'luogu-directive',
  level: 'block' as const,
  start: (src: string) => {
    const match = /^ {0,3}:{2,}/.exec(src)
    return match?.index
  },
  tokenizer(this: { lexer: { blockTokens: (source: string) => Tokens.Generic[]; inlineTokens: (source: string) => Tokens.Generic[] } }, src: string) {
    return directiveToken(src, this.lexer)
  },
  renderer(this: { parser: { parse: (tokens: Tokens.Generic[]) => string; parseInline: (tokens: Tokens.Generic[]) => string } }, token: Tokens.Generic) {
    const name = String(token.name ?? '').toLowerCase()
    const label = this.parser.parseInline((token.labelTokens ?? []) as Tokens.Generic[])
    const content = this.parser.parse((token.tokens ?? []) as Tokens.Generic[])
    const attrs = parseAttributes(String(token.attrs ?? ''))

    if (name === 'align') {
      const align = ['left', 'center', 'right'].find((item) => attrs.has(item)) ?? 'left'
      return `<div class="markdown-align" data-align="${align}">${content}</div>`
    }
    if (name === 'epigraph') {
      const author = String(token.label ?? '')
      return `<figure class="markdown-epigraph" data-author="${escapeHtml(author)}"><blockquote>${content}</blockquote>${label ? `<figcaption>${label}</figcaption>` : ''}</figure>`
    }

    const type = ['info', 'success', 'warning', 'error'].includes(name) ? name : 'default'
    const title = label || name
    const open = attrs.has('open') ? ' open' : ''
    return `<details class="markdown-callout markdown-callout-${type}"${open}><summary>${title}</summary><div class="markdown-callout-content">${content}</div></details>`
  },
}

const cuteTableExtension = {
  name: 'luogu-cute-table',
  level: 'block' as const,
  start: (src: string) => /^ {0,3}::cute-table/.test(src) ? 0 : undefined,
  tokenizer(this: { lexer: { blockTokens: (source: string) => Tokens.Generic[] } }, src: string) {
    return cuteTableToken(src, this.lexer)
  },
  renderer(this: { parser: { parse: (tokens: Tokens.Generic[]) => string; parseInline: (tokens: Tokens.Generic[]) => string } }, token: Tokens.Generic) {
    const style = parseAttributes(String(token.attrs ?? ''))
    const table = (token.tokens as Tokens.Generic[] | undefined)?.find((item) => item.type === 'table') as TableToken | undefined
    if (!table) return this.parser.parse((token.tokens ?? []) as Tokens.Generic[])
    const tuack = [...style].find((item) => item.startsWith('tuack='))?.slice('tuack='.length)
    const className = style.has('three') ? 'cute-table-three' : tuack ? 'cute-table-tuack' : 'cute-table-default'
    return renderTable(this.parser, table, className, tuack)
  },
}

marked.use({
  extensions: [directiveExtension, cuteTableExtension],
  renderer: { code: renderCode },
})

export const renderMarkdown = (source: string) => marked.parse(source) as string
