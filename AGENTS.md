# AGENTS.md

This file provides guidance to Codex (Codex.ai/code) when working with code in this repository.

## Repository Overview

Multi-project monorepo centered on competitive programming (C++) with supplementary tools and LaTeX templates. Contains ~1000 C++ solutions and ~500 markdown problem notes.

## Projects

### 1. Competitive Programming (root directory)
C++ solutions for Luogu (P/B/CF/SP/AT/UVA prefixed), Codeforces, AtCoder, GESP, and other OJ problems. Each `.cpp` file is independently compiled.

### 2. Luogu2VjudgeExtension (`Luogu2VjudgeExtension/index.js`)
Tampermonkey userscript adding a "跳转VJudge" button on Luogu problem pages for one-click navigation to VJudge.

### 3. Beamer Templates (`SXYZ-Beamer-Template/`, `ZJU-Beamer-Template/`)
LaTeX Beamer presentation templates for Shaoxing No.1 High School and Zhejiang University.

### 4. ConsoleApplication1 (`ConsoleApplication1/`)
Visual Studio C++ project (`.slnx` + `.vcxproj`).

### 5. Misc (`LakeLopNur/`, `Server/`)
Random C++ test files and a simple HTML/CSS page.

## C++ Build

- No shared build system — each `.cpp` is compiled individually
- Compile: `g++ -std=c++11 -O2 file.cpp -o file.exe`
- No package manager or dependencies
- Solutions use `cin`/`cout` for I/O and `freopen` for file I/O in contest problems

## C++ Coding Conventions (Competitive Programming)

Full style guide with statistics: see `码风总结.md`. Formatting rules live in `.clang-format`. Key points:

- Fixed header: `#include <bits/stdc++.h>` + `using namespace std;`; entry is `signed main()` (pairs with `#define int long long` when overflow-safe ints are wanted)
- I/O: `ios::sync_with_stdio(false); cin.tie(nullptr);` first, `cin`/`cout` with `'\n'` (never `endl`); switch to `scanf`/`printf` for UVA or heavy-constant geometry; `freopen` for file-I/O contests
- Formatting: 4-space indent, K&R braces (`{` stays on the same line), no line-width limit
- Static arrays defined at global scope (not inside `main`) with `const int N = 2e5 + 5` style size constants; prefer static arrays over `std::vector` for dense graphs (chained forward star `h[]/to[]/ne[]/ec` + `add()`), `vector` adjacency lists are fine for trees/DP
- Short variable names (`n, m, a[], x, y, l, r, mid, ans`); same-type declarations grouped on one line
- Use constants for repeated literal values (`const int mod = 998244353`, `inf = 0x3f3f3f3f`)
- No function parameters of `vector` or arrays (only global state + simple params)
- 1-indexed loops: `for (int i = 1; i <= n; i++)`
- Comma operator chains multiple statements: `cin >> n, ans1 = ans2 = 0;`
- Bitwise idioms: `(l + r) >> 1`, `1LL << x`, `__builtin_popcount/ctz`
- Functions: lowercase bare names (`solve`, `dfs`, `add`, `build`, `check`, `query`), `inline`, void functions end with explicit `return;`
- Structs: single letters or lowercase words for small ADTs (`P`, `node`, `Edge`), PascalCase for encapsulated data structures (`BIT`, `SegTree`, `DSU`)
- No comments in contest solutions
- New solutions use the lean style (plain header, no boilerplate). Historic files carry a large `namespace TANGYIXIAO` boilerplate from `template.cpp` — do not replicate it in new code, and never reformat the region between `// clang-format off/on`

## LaTeX Build (Beamer Templates)
```bash
# Build PDF (run from template directory)
xelatex -interaction=nonstopmode <file>.tex
xelatex -interaction=nonstopmode <file>.tex
bibtex <file>
xelatex -interaction=nonstopmode <file>.tex

# Or use Makefile
make        # build PDF
make clean  # remove aux files
```

## Git Conventions
- Commit messages follow date-based format: `YYYY-MM-DD-HH-MM-SS` or with descriptive suffix
