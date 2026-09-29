import { Marked, type Tokens } from 'marked'

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

function renderCode({ text, lang }: Tokens.Code, highlight: (source: string, language: string) => string[]) {
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

  const renderedLines = highlight(text, language)
  const lines = text.split('\n').map((line, index) => {
    const lineNumber = index + 1
    const code = renderedLines[index] || (line ? escapeHtml(line) : ' ')
    const active = highlighted.has(lineNumber) ? ' data-highlighted="true"' : ''
    return `<span class="code-line" data-line="${lineNumber}"${active}><span class="line-number" aria-hidden="true">${lineNumber}</span><span class="line-content">${code}</span></span>`
  }).join('')

  return `<pre class="markdown-code-block" data-language="${escapeHtml(language)}"><code class="shiki">${lines}</code></pre>`
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

export const renderMarkdown = (source: string, highlight: (source: string, language: string) => string[]) => {
  const { text, math, stem } = protectMath(source)
  const html = new Marked({
    extensions: [directiveExtension, cuteTableExtension],
    renderer: { code: (token) => renderCode(token, highlight) },
  }).parse(text) as string
  return restoreMath(html, math, stem)
}

// KaTeX formulas must never be parsed by marked: emphasis markers (_x_), backslash escapes
// (\{, \\) and Setext underlines (= on its own line) all corrupt LaTeX. Math spans are
// replaced by plain-word placeholders before parsing and restored afterwards, so the
// auto-render pass in App.tsx always sees the original delimiters intact.
const mathPlaceholder = 'katexprotectedmathplaceholder'

const escapeMath = (value: string) => value
  .replaceAll('&', '&amp;')
  .replaceAll('<', '&lt;')
  .replaceAll('>', '&gt;')

function protectMath(source: string) {
  let stem = mathPlaceholder
  while (source.includes(stem)) stem += 'x'
  const math: string[] = []
  // strip trailing \r so CRLF sources still match the fence and delimiter rules
  const lines = source.split('\n').map((line) => line.replace(/\r$/, ''))
  let fence: { marker: string; length: number } | null = null
  let pending: { closer: string; content: string } | null = null
  let out = ''
  for (let lineIndex = 0; lineIndex < lines.length; lineIndex += 1) {
    const line = lines[lineIndex]
    const newline = lineIndex < lines.length - 1 ? '\n' : ''
    if (fence) {
      if (new RegExp(`^ {0,3}${fence.marker}{${fence.length},}[ \\t]*$`).test(line)) fence = null
      out += line + newline
      continue
    }
    const opening = /^ {0,3}(`{3,}|~{3,})/.exec(line)
    if (opening) {
      fence = { marker: opening[1][0], length: opening[1].length }
      out += line + newline
      continue
    }
    if (pending) {
      if (pending.closer === '$' && !line.trim()) {
        // inline math cannot cross a blank line: give up and keep the text verbatim
        out += pending.content
        pending = null
      } else {
        const end = findInlineCloser(line, pending.closer)
        if (end >= 0) {
          const closerLength = pending.closer.length
          math.push(pending.content + line.slice(0, end + closerLength))
          out += `${stem}${math.length - 1}${stem}`
          pending = null
          const rest = protectMathInline(line.slice(end + closerLength), stem, math)
          out += rest.output
          if (rest.open) pending = rest.open
          continue
        }
        pending.content += line + '\n'
        continue
      }
    }
    const inline = protectMathInline(line, stem, math)
    out += inline.output + newline
    if (inline.open) pending = inline.open
  }
  if (pending) out += pending.content
  return { text: out, math, stem }
}

// closers are the first unescaped occurrence, matching how KaTeX auto-render pairs delimiters
function findInlineCloser(line: string, closer: string) {
  let index = line.indexOf(closer)
  while (index >= 0) {
    if (line[index - 1] !== '\\') return index
    index = line.indexOf(closer, index + closer.length)
  }
  return -1
}

function protectMathInline(line: string, stem: string, math: string[]): { output: string; open?: { closer: string; content: string } } {
  let out = ''
  let index = 0
  while (index < line.length) {
    const char = line[index]
    if (char === '\\' && (line[index + 1] === '(' || line[index + 1] === '[')) {
      const closer = line[index + 1] === '[' ? '\\]' : '\\)'
      const end = findInlineCloser(line.slice(index + 2), closer)
      if (end >= 0) {
        math.push(line.slice(index, index + 2 + end + closer.length))
        out += `${stem}${math.length - 1}${stem}`
        index += 2 + end + closer.length
        continue
      }
      // \[ blocks may span lines, but only when the opener starts its own line
      if (line[index + 1] === '[' && line.slice(0, index).trim() === '') {
        return { output: out, open: { closer, content: line.slice(index) + '\n' } }
      }
    }
    if (char === '\\' && line[index + 1] === '$') {
      out += '\\$'
      index += 2
      continue
    }
    if (char === '`') {
      const run = /`+/.exec(line.slice(index))![0]
      const closing = line.indexOf(run, index + run.length)
      if (closing >= 0) {
        out += line.slice(index, closing + run.length)
        index = closing + run.length
        continue
      }
      out += run
      index += run.length
      continue
    }
    if (char === '$') {
      if (line[index + 1] === '$') {
        const end = findInlineCloser(line.slice(index + 2), '$$')
        if (end >= 0) {
          math.push(line.slice(index, index + 2 + end + 2))
          out += `${stem}${math.length - 1}${stem}`
          index += 2 + end + 2
          continue
        }
        // same rule for $$ blocks: only a line-start opener may continue onto the next line,
        // so sequences like "$$$" in prose never swallow the rest of the document
        if (line.slice(0, index).trim() === '') {
          return { output: out, open: { closer: '$$', content: line.slice(index) + '\n' } }
        }
        out += '$$'
        index += 2
        continue
      }
      const end = findInlineCloser(line.slice(index + 1), '$')
      if (end >= 0) {
        math.push(line.slice(index, index + 1 + end + 1))
        out += `${stem}${math.length - 1}${stem}`
        index += 1 + end + 1
        continue
      }
      // inline math may continue onto the next line of the same paragraph
      return { output: out, open: { closer: '$', content: line.slice(index) + '\n' } }
    }
    out += char
    index += 1
  }
  return { output: out }
}

function restoreMath(html: string, math: string[], stem: string) {
  return html.replace(new RegExp(`${stem}(\\d+)${stem}`, 'g'), (match, index) => {
    const value = math[Number(index)]
    return value === undefined ? match : escapeMath(value)
  })
}
