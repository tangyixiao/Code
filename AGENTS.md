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
- Static arrays defined at global scope (not inside `main`)
- Prefer static arrays over `std::vector` for graph/tree construction
- Short variable names
- Same-type declarations grouped on one line
- Use constants for repeated literal values
- No function parameters of `vector` or arrays (only global state + simple params)
- No comments in contest solutions

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
