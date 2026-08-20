declare module 'katex/contrib/auto-render' {
  import type { KatexOptions } from 'katex'
  export default function renderMathInElement(element: HTMLElement, options?: KatexOptions & { delimiters?: Array<{ left: string; right: string; display: boolean }> }): void
}
