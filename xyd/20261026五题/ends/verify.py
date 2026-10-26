from itertools import product
from pathlib import Path
import random
import subprocess
import tempfile
import time

BASE = Path(__file__).resolve().parent
RNG = random.Random(20261026)


def brute(a):
    def score(b):
        s = ans = 0
        for t, d in b:
            s += t
            ans = max(ans, s - d)
        return ans

    ans = score(a)
    for i in range(len(a)):
        b = a[:i] + a[i + 1:]
        ans = min(ans, score([a[i]] + b), score(b + [a[i]]))
    return ans


def main():
    count = 0
    report = []
    with tempfile.TemporaryDirectory(prefix="ends-verify-") as directory:
        work = Path(directory)
        exe = work / "ends"
        subprocess.run(["g++", "-std=c++11", "-O2", str(BASE / "ends.cpp"), "-o", str(exe)], check=True)

        def check(data, expected):
            nonlocal count
            (work / "ends.in").write_text(data)
            begin = time.perf_counter()
            subprocess.run([str(exe)], cwd=work, check=True, timeout=10)
            elapsed = time.perf_counter() - begin
            actual = (work / "ends.out").read_text().split()
            assert actual == str(expected).split(), (data[:1000], expected, actual)
            count += 1
            return elapsed

        check("6\n5 30\n4 24\n7 33\n6 4\n1 12\n8 3\n", 21)
        for path in sorted((BASE / "samples").glob("*.in")):
            elapsed = check(path.read_text(), path.with_suffix(".out").read_text())
            report.append(f"附件 {path.name}：通过，{elapsed:.3f} 秒")
        pairs = list(product(range(1, 4), range(7)))
        for n in range(1, 3):
            for a in product(pairs, repeat=n):
                a = list(a)
                check(str(n) + "\n" + "".join(f"{t} {d}\n" for t, d in a), brute(a))
        report.append("穷举 n=1、2，t∈[1,3]、d∈[0,6] 的 462 组：通过")
        for _ in range(3000):
            n = RNG.randint(1, 14)
            a = [(RNG.randint(1, 30), RNG.choice([0, RNG.randint(0, 300), 10**14])) for _ in range(n)]
            check(str(n) + "\n" + "".join(f"{t} {d}\n" for t, d in a), brute(a))
        report.append("固定种子随机 3000 组，与枚举所有首尾移动的暴力比对：通过")
        for t, d in [(1, 0), (10**9, 0), (10**9, 10**14)]:
            n = 200000
            elapsed = check(str(n) + "\n" + (f"{t} {d}\n" * n), max(0, n * t - d))
            report.append(f"上限 n={n}，统一 t={t}、d={d}：通过，{elapsed:.3f} 秒")
    report.insert(0, f"C++11 -O2 编译通过；共 {count} 组检查通过。")
    (BASE / "验证记录.md").write_text("# 首尾验证记录\n\n" + "\n\n".join(report) + "\n\n计时为当前机器单次运行时间，未在 OJ 提交。\n")
    print("\n".join(report))


if __name__ == "__main__":
    main()
