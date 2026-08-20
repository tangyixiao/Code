# VS Code CodeHub Rebuild Implementation Plan

> **For agentic workers:** REQUIRED SUB-SKILL: Use superpowers:subagent-driven-development (recommended) or superpowers:executing-plans to implement this plan task-by-task. Steps use checkbox (`- [ ]`) syntax for tracking.

**Goal:** Ship a Vite-built React CodeHub that retains every archive-reading feature and adopts a VS Code-inspired, accessible interface.

**Architecture:** The Python generator remains the authority for the tracked-root manifest and passes the exact build SHA to the static client. Vite produces `dist/`; React validates `files.json`, synchronizes selected files with `#file=`, and divides list, reader, Markdown, and code concerns into focused components.

**Tech Stack:** React 19, TypeScript, Vite, Tailwind CSS v4, `@tailwindcss/vite`, `motion/react`, DOMPurify, marked, highlight.js, KaTeX, Python unittest, Playwright.

**Spec:** `docs/superpowers/specs/2026-08-20-vscode-codehub-rebuild-design.md`

## Global Constraints

- Keep schema version 1 and include only tracked root `.cpp` and `.md` files.
- Bind the manifest and raw GitHub URLs to the exact 40-character build SHA.
- Use the VS Code tokens `#1E1E1E`, `#252526`, `#2D2D30`, `#007ACC`, `#3794FF`, and `#D4D4D4`.
- Do not publish supplied external portrait, GIF, project-image, or video assets.
- Preserve search, type filters, natural ordering, paired-file navigation, safe Markdown, KaTeX, copy, raw links, retries, and mobile list/reader behavior.

---

### Task 1: Establish the Vite build handoff

**Files:**
- Create: `package.json`, `vite.config.ts`, `tsconfig.json`, `src/main.tsx`, `src/index.css`, `src/App.tsx`
- Modify: `scripts/build_pages.py`, `.github/workflows/pages.yml`, `.gitignore`
- Test: `tests/test_build_pages.py`

**Interfaces:** `build_pages.py --root ROOT --output OUTPUT --commit SHA` produces Vite assets, `.nojekyll`, and `files.json`.

- [ ] **Step 1: Write a failing Vite-artifact test**

```python
def test_copies_vite_dist_and_manifest(self):
    result = build_site(self.repo, commit=SHA)
    self.assertTrue((result / "index.html").is_file())
    self.assertTrue((result / "assets").is_dir())
    self.assertEqual(json.loads((result / "files.json").read_text())["commit"], SHA)
```

- [ ] **Step 2: Run the focused test**

Run: `python -m unittest tests.test_build_pages.BuildPagesTests.test_copies_vite_dist_and_manifest -v`
Expected: FAIL because the static `index.html` is not a Vite artifact.

- [ ] **Step 3: Implement Vite, Tailwind, and the build handoff**

```ts
export default defineConfig({ base: '/Code/', plugins: [react(), tailwindcss()] })
```

```python
subprocess.run(["npm", "ci"], cwd=root, check=True)
subprocess.run(["npm", "run", "build"], cwd=root, check=True)
shutil.copytree(root / "dist", output, dirs_exist_ok=True)
write_manifest(output / "files.json", files, commit)
```

- [ ] **Step 4: Verify and commit**

Run: `python -m unittest discover -s tests -v; npm ci; npm run build; python scripts/build_pages.py --output _site --commit <SHA>`

```bash
git add package.json package-lock.json vite.config.ts tsconfig.json src scripts/build_pages.py .github/workflows/pages.yml .gitignore tests/test_build_pages.py
git commit -m "feat: build CodeHub with Vite"
```

### Task 2: Reimplement archive state and reader behavior in React

**Files:**
- Create: `src/lib/manifest.ts`, `src/lib/paths.ts`, `src/components/ArchiveHeader.tsx`, `src/components/FileList.tsx`, `src/components/CodeReader.tsx`, `src/components/MarkdownReader.tsx`
- Modify: `src/App.tsx`, `src/index.css`
- Test: `tests/site.test.cjs`

**Interfaces:** `loadManifest(): Promise<ArchiveManifest>` rejects bad/empty manifests; `encodeRawPath(path: string): string` encodes each segment; `App` owns the selected `#file=` path.

- [ ] **Step 1: Write a failing reader contract check**

```js
await page.getByRole('button', { name: /Markdown P9709/ }).click();
await expect(page.locator('#viewer .katex').first()).toBeVisible();
await expect(page.getByRole('link', { name: /个人主页/ })).toHaveAttribute('href', 'https://tangyixiao.github.io/');
```

- [ ] **Step 2: Run the browser test**

Run: `node tests/site.test.cjs`
Expected: FAIL because the React reader and header do not exist.

- [ ] **Step 3: Implement manifest loading, selection, list, code, and Markdown components**

```tsx
const [selectedPath, setSelectedPath] = useHashSelection(files)
const selected = files.find((file) => file.path === selectedPath) ?? null
return <ArchiveLayout files={files} selected={selected} onSelect={setSelectedPath} />
```

```ts
const safeHtml = DOMPurify.sanitize(marked.parse(source));
renderMathInElement(container, { delimiters, macros, throwOnError: false });
```

- [ ] **Step 4: Verify and commit**

Run: `npm run build; node tests/site.test.cjs`

```bash
git add src tests/site.test.cjs
git commit -m "feat: rebuild CodeHub reader in React"
```

### Task 3: Apply visual system, motion, and mobile accessibility

**Files:**
- Create: `src/components/ManifestoBand.tsx`, `src/components/MobileBackButton.tsx`
- Modify: `src/index.css`, `src/App.tsx`, `src/components/ArchiveHeader.tsx`, `src/components/FileList.tsx`
- Test: `tests/site.test.cjs`, `tests/site_smoke.cjs`

**Interfaces:** `ManifestoBand` has no remote media dependencies; the mobile back button has `aria-label="返回文件列表"` and restores `data-mobile-view="list"`.

- [ ] **Step 1: Add failing mobile and reduced-motion checks**

```js
await page.emulateMedia({ reducedMotion: 'reduce' });
await expect(page.locator('body')).toHaveAttribute('data-motion', 'reduced');
await mobile.getByRole('button', { name: '返回文件列表' }).click();
await expect(mobile.locator('body')).toHaveAttribute('data-mobile-view', 'list');
```

- [ ] **Step 2: Run the checks**

Run: `node tests/site.test.cjs`
Expected: FAIL until the responsive state and motion policy are implemented.

- [ ] **Step 3: Implement VS Code tokens and Motion transitions**

```tsx
const shouldReduceMotion = useReducedMotion()
<motion.section initial={shouldReduceMotion ? false : { opacity: 0, y: 12 }} animate={{ opacity: 1, y: 0 }} />
```

- [ ] **Step 4: Verify, release, and commit**

Run: `python -m unittest discover -s tests -v; npm run build; git diff --check; node tests/site.test.cjs`

```bash
git add src tests/site.test.cjs tests/site_smoke.cjs
git commit -m "feat: style CodeHub as a VS Code archive"
git fetch origin main
git merge-base --is-ancestor origin/main HEAD
git push origin HEAD:main
```

- [ ] **Step 5: Verify production**

Run `tests/site_smoke.cjs` with `SITE_URL=https://tangyixiao.github.io/Code/`; assert HTTP 200, schema 1, current commit, special-character deep link, KaTeX, pairing, and mobile back navigation.
