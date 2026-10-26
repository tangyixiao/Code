import argparse
import itertools
import math
from functools import reduce
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


def encode(a, queries):
    return f"{len(a)} {len(queries)}\n" + " ".join(map(str, a)) + "\n" + "\n".join(map(str, queries)) + "\n"


def brute(a, m):
    best = count = 0
    for pos in itertools.permutations(range(len(a)), 3):
        for x in range(1, m + 1):
            if m % x:
                continue
            for y in range(1, m // x + 1):
                if m // x % y:
                    continue
                b = a[:]
                for i, mul in zip(pos, (x, y, m // x // y)):
                    b[i] *= mul
                value = reduce(math.gcd, b)
                if value > best:
                    best, count = value, 1
                elif value == best:
                    count += 1
    return best, count % MOD


def large_brute(a, m):
    def divisors(x):
        result = []
        for d in range(1, math.isqrt(x) + 1):
            if x % d == 0:
                result.append(d)
                if d * d != x:
                    result.append(x // d)
        return result
    triples = [(x, y, m // x // y) for x in divisors(m) for y in divisors(m // x)]
    best = count = 0
    for pos in itertools.permutations(range(len(a)), 3):
        for factors in triples:
            b = a[:]
            for i, mul in zip(pos, factors):
                b[i] *= mul
            value = reduce(math.gcd, b)
            if value > best:
                best, count = value, 1
            elif value == best:
                count += 1
    return best, count % MOD


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--rounds", type=int, default=300)
    args = parser.parse_args()
    with tempfile.TemporaryDirectory(prefix="isogeny-verify-") as directory:
        tmp = Path(directory)
        exe = tmp / "main"
        subprocess.run(["g++", "-std=c++11", "-O2", str(ROOT / "isogeny.cpp"), "-o", str(exe)], check=True)
        for i in range(1, 4):
            actual, _ = run(exe, tmp, (OLD / f"sample{i}.in").read_text())
            assert actual == (OLD / f"sample{i}.out").read_text().split(), f"sample {i}"
        print("samples: 3 passed")
        rng = random.Random(SEED)
        cases = [[1, 2, 3], [6, 6, 6], [1, 1, 1], [2, 3, 5, 7], [1, 6, 6, 6], [1, 1, 6, 6, 6], [1, 1, 1, 6, 6], [1, 1, 1, 1, 6]]
        for _ in range(args.rounds):
            common = rng.randint(1, 5)
            cases.append([common * rng.randint(1, 24) for _ in range(rng.randint(3, 7))])
        for index, a in enumerate(cases):
            queries = sorted({1, 2, 6, 12, 36, 60, *[rng.randint(1, 60) for _ in range(6)]})
            expected = [str(x) for m in queries for x in brute(a, m)]
            actual, _ = run(exe, tmp, encode(a, queries))
            if actual != expected:
                raise AssertionError((index, a, queries, expected, actual))
        print(f"brute: {len(cases)} arrays passed, seed={SEED}")
        for index in range(40):
            a = [rng.randint(1, 1000000) for _ in range(rng.randint(3, 6))]
            m = rng.choice([1000000, 720720, 999983, rng.randint(1, 1000000)])
            expected = [str(x) for x in large_brute(a, m)]
            actual, _ = run(exe, tmp, encode(a, [m]))
            assert actual == expected, (a, m, expected, actual)
        print("large-value brute: 40 arrays passed")
        cases = [
            ("all-equal", [1000000] * 200000, [1000000] * 200000),
            ("many-divisors", [1] + [720720] * 199999, [1000000] * 200000),
            ("distinct", list(range(800001, 1000001)), [1000000] * 200000),
            ("n=3, distinct queries", [720720, 999983, 1000000], list(range(1, 200001))),
        ]
        # The final case includes the largest query as well as 199999 distinct smaller queries.
        cases[-1][2][-1] = 1000000
        for name, a, queries in cases:
            actual, elapsed = run(exe, tmp, encode(a, queries))
            assert len(actual) == 2 * len(queries)
            if name == "all-equal":
                expected = 200000 * 199999 * 199998 * 784 % MOD
                assert actual == ["1000000", str(expected)] * len(queries)
            elif name == "n=3, distinct queries":
                assert actual[-2:] == [str(x) for x in large_brute(a, queries[-1])]
            print(f"pressure {name}: {elapsed:.3f}s, first={actual[:2]}, queries={len(queries)}")


if __name__ == "__main__":
    main()
