import argparse
import itertools
import math
import random
import subprocess
from pathlib import Path
from functools import reduce

ROOT = Path(__file__).resolve().parent
EXE = ROOT / "isogeny.exe"
INP = ROOT / "isogeny.in"
OUT = ROOT / "isogeny.out"
MOD = 998244353
SEED = 20261002


def brute(a, m):
    best = -1
    count = 0
    for u, v, w in itertools.permutations(range(len(a)), 3):
        for x in range(1, m + 1):
            if m % x:
                continue
            rem = m // x
            for y in range(1, rem + 1):
                if rem % y:
                    continue
                z = rem // y
                b = a[:]
                b[u] *= x
                b[v] *= y
                b[w] *= z
                value = reduce(math.gcd, b)
                if value > best:
                    best, count = value, 1
                elif value == best:
                    count += 1
    return best, count % MOD


def one_case(rng):
    n = rng.choice([3, 4, 5, 6, 7])
    common = rng.randint(1, 5)
    a = [common * rng.randint(1, 24) for _ in range(n)]
    ms = sorted(set([rng.randint(1, 60) for _ in range(rng.randint(4, 12))] + [1, 2, 6, 12, 36, 60]))
    expected = [brute(a, m) for m in ms]
    data = f"{n} {len(ms)}\n" + " ".join(map(str, a)) + "\n" + "\n".join(map(str, ms)) + "\n"
    INP.write_text(data, encoding="ascii")
    with OUT.open("w", encoding="ascii") as f:
        with INP.open("r", encoding="ascii") as fi:
            subprocess.run([str(EXE)], cwd=ROOT, stdin=fi, stdout=f, stderr=subprocess.PIPE, check=True)
    got = [tuple(map(int, line.split())) for line in OUT.read_text(encoding="ascii").splitlines()]
    if got != expected:
        (ROOT / "failure.txt").write_text(
            f"seed={SEED}\narray={a}\nqueries={ms}\nexpected={expected}\ngot={got}\n", encoding="utf-8")
        raise AssertionError(f"mismatch; retained isogeny.in, isogeny.out, failure.txt: a={a}, ms={ms}")


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--rounds", type=int, default=100)
    args = parser.parse_args()
    rng = random.Random(SEED)
    for _ in range(args.rounds):
        one_case(rng)
    print(f"PASS rounds={args.rounds} seed={SEED}")

if __name__ == "__main__":
    main()
