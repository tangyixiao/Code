# VS Code CodeHub Rebuild Design

## Goal

Rebuild `https://tangyixiao.github.io/Code/` as a React single-page code archive that keeps every existing reading feature while adopting a shared VS Code-inspired visual language with the personal homepage.

## Visual system

- Canvas: `#1E1E1E`; panels: `#252526` and `#2D2D30`; rules: `#3E3E42`.
- Accent: `#007ACC`; interactive highlight: `#3794FF`; cyan code glow: `#4FC1FF`.
- Text: `#D4D4D4`, secondary text: `#9DA5B4`, code font: a system monospace stack.
- Kanit is the utility/UI face, Italiana is reserved for the oversized archive title, Manrope is the prose face, and Marck Script is used once in the archive manifesto only.
- Motion is purposeful: list selection, panel reveal, and route transition; all animation is disabled or reduced under `prefers-reduced-motion`.

## Information architecture

1. A compact dark masthead identifies the archive, exposes a return link to `https://tangyixiao.github.io/`, and presents the generated file count.
2. The existing searchable file list remains the primary navigation surface. Type filters, natural ordering, paired `.cpp`/`.md` navigation, encoded `#file=` routes, copy, raw source, and error/retry behavior remain public contracts.
3. The reader remains a distraction-free pane: C++ keeps line numbering and syntax highlighting; Markdown stays sanitized and receives KaTeX rendering.
4. A short blue manifesto band connects the archive to the personal homepage without inserting third-party images, GIFs, portraits, video, or sample-project assets.

## React architecture

- Vite produces a static `dist/` site for GitHub Pages.
- `src/main.tsx` mounts the app; `src/App.tsx` owns selected-file state and URL synchronization.
- `src/lib/manifest.ts` validates `files.json`; `src/lib/paths.ts` encodes raw GitHub paths segment-by-segment.
- Focused components handle masthead, archive controls, file list, reader, Markdown renderer, code renderer, and the mobile list/reader switch.
- The Python generator remains the authority for the tracked-root manifest and passes the exact build commit to the static client via `files.json`.

## Accessibility and resilience

- Every action has a visible focus state and accessible label.
- Content loading failures name the failed action and offer retry.
- Unsafe Markdown HTML is cleaned before insertion; math rendering cannot execute arbitrary HTML.
- Mobile starts in list mode and exposes an explicit return-to-list action after a selection.

## Acceptance criteria

- The production manifest contains only tracked root `.cpp` and `.md` files, retains schema version 1, natural ordering, exact byte sizes, and the deployed 40-character commit SHA.
- A deep link with Chinese text, spaces, and `#` opens the correct file after refresh.
- LaTeX displays in Markdown; C++ and Markdown can switch to a paired counterpart.
- Desktop and mobile browser tests pass with normal and reduced-motion settings.
