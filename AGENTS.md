# Repository Guidelines

## Project Structure

This monorepo contains independent competitive-programming solutions and supporting projects. Root-level `*.cpp` files are organized by OJ/problem ID and often have adjacent Markdown notes. The Vite/React site lives in `src/`, with supporting scripts in `scripts/` and tests in `tests/`. `Luogu2VjudgeExtension/` contains the Tampermonkey userscript; `Server/` and `LakeLopNur/` hold small experiments. Beamer sources and assets are in `SXYZ-Beamer-Template/` and `ZJU-Beamer-Template/`; `ConsoleApplication1/` is a Visual Studio C++ project.

## Build, Test, and Development

- Compile one contest solution with `g++ -std=c++11 -O2 "file.cpp" -o file.exe`.
- From the repository root, run `npm run build` to build the Vite site and verify lazy chunks.
- Run `npm run test:unit` for focused JavaScript unit tests; run `npm run test:browser` for site and generated-page smoke tests.
- From either Beamer directory, run `make` to build the PDF; use `make clean` to remove generated LaTeX files.
- Open `ConsoleApplication1/ConsoleApplication1.slnx` in Visual Studio for that project.

## Coding Style and Naming

C++ uses 4-space indentation, K&R braces, `#include <bits/stdc++.h>`, fast iostream setup, and `signed main()`. Prefer concise lowercase function names and problem-oriented filenames such as `P1234 ...cpp`, `CF...cpp`, or `ABC...cpp`. Use `.clang-format` for formatting; it is LLVM-based with a 4-space indent and no column limit. Preserve existing historical boilerplate, but do not copy it into new solutions. Keep frontend TypeScript/React changes localized to `src/` and follow the surrounding module style.

## Testing Guidelines

Add or update tests under `tests/` when changing the site, build scripts, or generated-page behavior. Run the narrowest relevant command first, then `npm run build` and the applicable broader test command. For contest solutions, compile locally and check samples and boundary cases; final correctness is normally established by the target OJ.

## Commits and Pull Requests

Recent history uses timestamp-style subjects such as `2026-09-21-20-03-46-623`, sometimes followed by a short descriptive suffix. Keep commits focused and describe the affected problem or component. Pull requests should explain the scope, list validation commands and results, link related issues when applicable, and include screenshots or rendered PDFs for visual/template changes. Do not commit secrets or unnecessary generated build output.
