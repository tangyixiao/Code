import argparse
import itertools
import random
import subprocess
from pathlib import Path

ROOT = Path(__file__).resolve().parent
TMP = ROOT / "tmp"
EXE = TMP / "notch.exe"


def brute(a):
    n = len(a)
    ans = [0] * (n + 1)
    for l in range(n):
        mn = n
        seen = [False] * (n + 1)
        for r in range(l, n):
            mn = min(mn, a[r])
            seen[a[r]] = True
            mex = 0
            while seen[mex]:
                mex += 1
            if mn + mex <= n:
                ans[mn + mex] += 1
    return ans[1:]


def run(a):
    (TMP / "notch.in").write_text(str(len(a)) + "\n" + " ".join(map(str, a)) + "\n")
    subprocess.run([str(EXE)], cwd=TMP, check=True)
    return list(map(int, (TMP / "notch.out").read_text().split()))


def check(a, tag):
    expected = brute(a)
    actual = run(a)
    if actual != expected:
        (TMP / (tag + ".in")).write_text(str(len(a)) + "\n" + " ".join(map(str, a)) + "\n")
        (TMP / (tag + ".expected")).write_text(" ".join(map(str, expected)) + "\n")
        (TMP / (tag + ".actual")).write_text(" ".join(map(str, actual)) + "\n")
        raise SystemExit("Mismatch: " + tag)


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--rounds", type=int, default=200)
    args = parser.parse_args()
    rng = random.Random(20261002)
    for n in range(1, 8):
        for a in itertools.permutations(range(n)):
            check(list(a), "exhaustive-" + str(n) + "-" + "-".join(map(str, a)))
    for a in ([0], [0, 1], [1, 0], [0, 1, 2, 3, 4], [4, 3, 2, 1, 0]):
        check(list(a), "boundary")
    for turn in range(args.rounds):
        n = rng.randint(1, 10)
        a = list(range(n))
        rng.shuffle(a)
        check(a, "random-" + str(turn))
    for i in (1, 2):
        input_text = (ROOT / ("sample%d.in" % i)).read_text()
        expected = (ROOT / ("sample%d.out" % i)).read_text().split()
        (TMP / "notch.in").write_text(input_text)
        subprocess.run([str(EXE)], cwd=TMP, check=True)
        actual = (TMP / "notch.out").read_text().split()
        if actual != expected:
            raise SystemExit("Sample %d mismatch" % i)
    print("PASS: exhaustive permutations n<=7, boundaries, %d random rounds, samples 1-2" % args.rounds)


if __name__ == "__main__":
    main()
