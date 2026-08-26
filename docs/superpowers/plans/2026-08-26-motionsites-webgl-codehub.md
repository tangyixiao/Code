# Abyssal Clinamen CodeHub Implementation Plan

> Execute in `/home/tangyixiao/.codex/worktrees/Code/motionsites-webgl-codehub` on `codex/motionsites-webgl-codehub`.

## Goal

Upgrade the existing CodeHub workbench in place with an original low-luminance deep-sea WebGL reactor and a cohesive glass-console UI while preserving every archive feature, data contract, and full-row rendering behavior.

## Task 1: Test-drive and implement the CodeHub scene system

### Required production changes

- Add `three` as a production dependency and keep it behind a dynamic import so the initial React workbench renders first and the production build emits a distinct lazy scene chunk.
- Add typed visual modules under `src/visual/` with these public contracts:

```ts
export type SceneVariant = 'portfolio' | 'workbench'
export type ScenePhase = 'hero' | 'orbit' | 'focus' | 'archive' | 'links' | 'workbench'

export interface DeepSeaCanvasProps {
  variant: SceneVariant
  phase: ScenePhase
  pulse: number
  reducedMotion: boolean
}

export interface DeepSeaController {
  setPhase(phase: ScenePhase): void
  pulse(seed: number): void
  destroy(): void
}
```

- Render exactly one full-screen, transparent, pointer-inert canvas behind the workbench. The raw Three.js scene must include deep-sea fog, a low-brightness nucleus/reactor, orbit paths, a particle flow field, subtle camera drift, smoothed pointer inertia, cyan signal light, and muted ion purple. Use original programmatic geometry only.
- Keep the complete scene and identical particle count/logic on mobile. Cap renderer DPR at `Math.min(devicePixelRatio, 2)`.
- Pause while the document is hidden. On teardown, remove listeners and dispose all geometries, materials, textures, and the renderer.
- For `prefers-reduced-motion`, render a static first frame only. If WebGL cannot initialize or the context is lost, show a CSS deep-sea gradient and static ASCII atom fallback without uncaught errors.
- Expose deterministic scene attributes for phase, motion mode, pulse, and fallback status.

### Required workbench integration

- Preserve manifest loading, all `.file-row` elements, search, type filters, hash deep links, source loading, syntax highlighting, Markdown, KaTeX, paired-file switching, desktop internal scrolling, and mobile list/reader/back flow.
- Keep existing `content-visibility` behavior and never virtualize or truncate the 2,000+ file list.
- Increment a scene pulse on a genuine file selection and shift the top orbital telemetry, without stealing focus, resetting reader scroll, or changing reader content beyond the selected file.
- Restyle search, filters, file rows, toolbar, and reading panel as a coherent glass console with translucent fill, thin outlines, inner highlights, backdrop blur, scanning accents, refraction highlights, strong selected/focus states, and accessible contrast.
- Concentrate motion in the background, toolbar, and file-switch boundary. Do not apply continuous translation/scale animation to reading content.
- Do not add or stage `U105028 偷心魔理沙.md`.

### Tests first

Before implementation, extend browser regressions so they fail for the missing behavior, then implement until green. Browser coverage must prove:

- search, filters, hash deep links, source rendering, Markdown, KaTeX, paired files, and mobile back flow remain functional;
- one and only one scene canvas exists at desktop and `390x844`, with the full 3D scene mode on both;
- choosing a file changes the pulse marker but does not steal focus or corrupt scroll/content;
- reduced-motion mode is static and context loss reveals the fallback without console errors;
- the workbench keeps a single viewport height with internal scrolling and no horizontal overflow;
- the complete live manifest remains indexed and every `.file-row` remains in the DOM;
- stale title expectations are aligned with the current canonical `Paradox Praxis Clinamen — 深海算法档案` title.

### Workflow

- Update `.github/workflows/pages.yml` to run installation/build checks for pull requests while limiting Pages configure/upload/deploy actions to pushes on `main`.

### Verification

- `python3 -m unittest discover -s tests -p 'test_*.py'`
- `npm run build`
- Existing deterministic browser integration plus a live built-site smoke run using bundled Playwright and `/usr/bin/chromium`
- Confirm a distinct lazy Three.js/scene chunk exists under `dist/assets` and the initial app chunk does not eagerly absorb Three.js.
- Capture desktop, mobile, and reduced-motion screenshots for review.

### Commit

Commit all task-owned changes with a descriptive Conventional Commit message. Do not push or open the PR; the parent agent will do that after independent review.
