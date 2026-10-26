from pathlib import Path
import re
import subprocess
from bs4 import BeautifulSoup

BASE = Path(__file__).resolve().parent
ROOT = BASE.parents[1]
TEMP = ROOT / "tmp/pdfs/20261026"
OUTPUT = ROOT / "output/pdf/20261026题解与思路分析汇总.pdf"
TASKS = [("trim", "修整"), ("garden", "花园"), ("epigraphy", "印谱"), ("isogeny", "同铸"), ("ends", "首尾")]


def samples(name):
    soup = BeautifulSoup((BASE / name / "题面.html").read_text(), "html.parser")
    for element in soup.select('[role="button"]'):
        element.decompose()
    values = [element.get_text().strip() for element in soup.find_all("pre")]
    assert len(values) == 2, (name, len(values))
    return values


def sample_block(name):
    a, b = samples(name)
    return (
        "样例输入、输出分别如下（左为输入，右为输出）。\n\n"
        "\\noindent\n\\begin{minipage}[t]{0.47\\textwidth}\n"
        "\\begin{lstlisting}\n" + a + "\n\\end{lstlisting}\n"
        "\\end{minipage}\\hfill\n\\begin{minipage}[t]{0.47\\textwidth}\n"
        "\\begin{lstlisting}\n" + b + "\n\\end{lstlisting}\n"
        "\\end{minipage}\n"
    )


def main():
    TEMP.mkdir(parents=True, exist_ok=True)
    OUTPUT.parent.mkdir(parents=True, exist_ok=True)
    metadata = r'''---
    title-meta: 2026-10-26 题解与思路分析汇总
    author-meta: Tangyixiao
    documentclass: ctexart
    classoption:
      - UTF8
      - a4paper
      - fontset=none
    fontsize: 11pt
    geometry: margin=2.1cm
    mainfont: Liberation Serif
    sansfont: Liberation Sans
    mathfont: DejaVu Math TeX Gyre
    monofont: JetBrains Mono
    CJKmainfont: Noto Serif CJK SC
    toc: false
    header-includes:
      - \usepackage{listings}
      - \usepackage{needspace}
      - \setCJKsansfont{Noto Sans CJK SC}
      - \lstset{frame=none,breaklines=true,breakatwhitespace=false,columns=fullflexible,basicstyle=\ttfamily\small,keepspaces=true,showstringspaces=false,aboveskip=4pt,belowskip=4pt}
      - \setlength{\emergencystretch}{3em}
      - \setlength{\parskip}{4pt}
      - \clubpenalty=10000
      - \widowpenalty=10000
      - \displaywidowpenalty=10000
      - \setcounter{secnumdepth}{0}
    ---

    '''
    metadata = "\n".join(line[4:] if line.startswith("    ") else line for line in metadata.splitlines())
    parts = [metadata]
    for name, title in TASKS:
        statement = (BASE / name / "题面.md").read_text().strip()
        editorial = (BASE / name / "题解.md").read_text().strip()
        for text in [statement, editorial]:
            assert not re.search(r"^#{1,6}\s", text, re.M), name
            assert not re.search(r"https?://|\\boxed|\\fbox|正确性|复杂度证明|实现细节|附件", text), name
        paragraphs = editorial.split("\n\n")
        for i in range(len(paragraphs) - 1):
            if paragraphs[i + 1].lstrip().startswith("$$"):
                paragraphs[i] = "\\Needspace{6\\baselineskip}\n\n" + paragraphs[i]
        editorial = "\n\n".join(paragraphs)
        section = (
            f"# {title}\n\n\\label{{start-{name}}}\n\n{statement}\n\n"
            + sample_block(name)
            + f"\n\\bigskip\n\n{editorial}\n\n\\label{{end-{name}}}\n"
        )
        (BASE / name / "完整题解.md").write_text(section)
        parts.append(section)
    markdown = ROOT / "20261026题解与思路分析汇总.md"
    markdown.write_text(metadata + "\n\n\\clearpage\n\n".join(parts[1:]))
    tex = TEMP / "汇总.tex"
    subprocess.run(["pandoc", str(markdown), "--standalone", "--pdf-engine=xelatex", "-o", str(tex)], check=True)
    for _ in range(2):
        result = subprocess.run(["xelatex", "-interaction=nonstopmode", "-halt-on-error", "-output-directory", str(TEMP), str(tex)], cwd=ROOT, text=True, stdout=subprocess.PIPE)
        if result.returncode:
            print(result.stdout[-5000:])
            raise RuntimeError("PDF 编译失败")
    aux = (TEMP / "汇总.aux").read_text()
    pages = {f"{kind}-{name}": int(page) for kind, name, page in re.findall(r"\\newlabel\{(start|end)-(\w+)\}\{\{[^}]*\}\{(\d+)\}", aux)}
    for name, title in TASKS:
        first, last = pages["start-" + name], pages["end-" + name]
        assert 1 <= last - first + 1 <= 2, (title, first, last)
        print(f"{title}：第 {first}–{last} 页，共 {last-first+1} 页")
    OUTPUT.write_bytes((TEMP / "汇总.pdf").read_bytes())
    print(OUTPUT)


if __name__ == "__main__":
    main()
