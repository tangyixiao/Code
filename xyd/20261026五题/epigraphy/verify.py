import argparse
import random
import subprocess
import tempfile
import time
from pathlib import Path

ROOT = Path(__file__).resolve().parent
OLD = ROOT.parents[1] / "2026提高国庆模拟卷2" / ROOT.name
SEED = 20261026
MOD = 998244353


def run(exe, tmp, text):
    (tmp / (ROOT.name + ".in")).write_text(text, encoding="ascii")
    start = time.perf_counter()
    subprocess.run([str(exe)], cwd=tmp, check=True, timeout=20)
    return (tmp / (ROOT.name + ".out")).read_text().split(), time.perf_counter() - start


def brute(n, m, days, stamps):
    dp = {0: 1}
    for day, available in enumerate(days, 1):
        ndp = {}
        for s, creation in stamps.items():
            if creation <= day and s & available == s:
                ways = 0
                for t, count in dp.items():
                    if t & s == t:
                        ways += count
                ndp[s] = ways % MOD
        dp = ndp
    return sum(dp.values()) % MOD


def make_case(rng):
    m = rng.randint(1, 6)
    n = rng.randint(1, 12)
    lim = 1 << m
    days = [rng.randrange(lim) for _ in range(n)]
    masks = list(range(1, lim))
    rng.shuffle(masks)
    chosen = set(masks[:rng.randint(0, min(len(masks), 14))])
    raw = [0] * lim
    for s in range(1, lim):
        raw[s] = rng.randint(1, n)
    creation = {}
    for s in range(1, lim):
        sub = (s - 1) & s
        best = raw[s]
        while sub:
            if sub in chosen:
                best = max(best, creation[sub])
            sub = (sub - 1) & s
        creation[s] = best
    stamps = {0: 1}
    for s in sorted(chosen, key=lambda x: (bin(x).count("1"), x)):
        stamps[s] = creation[s]
    return n, m, days, stamps


def encode(n, m, days, stamps):
    rows = [f"{n} {m} {len(stamps) - 1}", " ".join(map(str, days))]
    rows.extend(f"{s} {d}" for s, d in stamps.items() if s)
    return "\n".join(rows) + "\n"


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--rounds", type=int, default=500)
    args = parser.parse_args()
    with tempfile.TemporaryDirectory(prefix="epigraphy-verify-") as directory:
        tmp = Path(directory)
        exe = tmp / "main"
        subprocess.run(["g++", "-std=c++11", "-O2", str(ROOT / "epigraphy.cpp"), "-o", str(exe)], check=True)
        for i in (1, 2):
            actual, _ = run(exe, tmp, (OLD / f"sample{i}.in").read_text())
            assert actual == (OLD / f"sample{i}.out").read_text().split(), f"sample {i}"
        assert run(exe, tmp, "3 2 3\n3 1 3\n1 1\n2 1\n3 1\n")[0] == ["8"]
        print("samples: 2 attachment samples and statement example passed")
        rng = random.Random(SEED)
        cases = [(8, m, [(1 << m) - 1] * 8, {s: 1 for s in range(1 << m)}) for m in range(1, 7)]
        cases.extend([(1, 6, [63], {s: 1 for s in range(64)}), (9, 5, [31] * 8 + [0], {s: 1 for s in range(32)})])
        cases.extend(make_case(rng) for _ in range(args.rounds))
        for index, (n, m, days, stamps) in enumerate(cases):
            expected = brute(n, m, days, stamps)
            actual, _ = run(exe, tmp, encode(n, m, days, stamps))
            assert actual == [str(expected)], (index, n, m, days, stamps, expected, actual)
        print(f"brute: {len(cases)} cases passed, seed={SEED}")
        n, m = 200000, 16
        days = [65535] * n
        for name, stamps, last in [
            ("all available day 1", {s: 1 for s in range(65536)}, 65535),
            ("popcount creation day", {0: 1, **{s: 1 + s.bit_count() for s in range(1, 65536)}}, 65535),
            ("last day empty", {s: 1 for s in range(65536)}, 0),
            ("creation on final day", {0: 1, **{s: n for s in range(1, 65536)}}, 65535),
        ]:
            days[-1] = last
            actual, elapsed = run(exe, tmp, encode(n, m, days, stamps))
            if name == "all available day 1":
                assert actual == [str(pow(n + 1, m, MOD))]
            elif name == "last day empty":
                assert actual == ["1"]
            elif name == "creation on final day":
                assert actual == ["65536"]
            print(f"pressure {name}: {elapsed:.3f}s, answer={actual[0]}")


if __name__ == "__main__":
    main()
