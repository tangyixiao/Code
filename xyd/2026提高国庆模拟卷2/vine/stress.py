import argparse
import functools
import random
import subprocess
from pathlib import Path

ROOT = Path(__file__).resolve().parent
TMP = ROOT / "tmp"
EXE = TMP / "vine.exe"


def oracle(parent):
    n = len(parent) - 1
    ancestors = [[] for _ in range(n + 1)]
    for v in range(1, n + 1):
        x = parent[v]
        while x:
            ancestors[v].append(x)
            x = parent[x]

    @functools.lru_cache(None)
    def winning(a, b):
        for x in ancestors[a]:
            if x == b:
                break
            if not winning(x, b):
                return True
        for x in ancestors[b]:
            if x == a:
                break
            if not winning(a, x):
                return True
        return False

    def moves(a, b):
        count = 0
        for x in ancestors[a]:
            if x == b:
                break
            count += not winning(x, b)
        for x in ancestors[b]:
            if x == a:
                break
            count += not winning(a, x)
        return count

    return winning, moves


def run(parent, queries):
    n = len(parent) - 1
    data = ["%d %d" % (n, len(queries))]
    data.append(" ".join(str(parent[i]) for i in range(2, n + 1)))
    data.extend("%d %d" % (a, b) for a, b in queries)
    (TMP / "vine.in").write_text("\n".join(data) + "\n")
    subprocess.run([str(EXE)], cwd=TMP, check=True)
    return (TMP / "vine.out").read_text().splitlines()


def check(parent, queries, tag):
    winning, moves = oracle(parent)
    expected = ["First %d" % moves(a, b) if winning(a, b) else "Second 0" for a, b in queries]
    actual = run(parent, queries)
    if actual != expected:
        n = len(parent) - 1
        data = ["%d %d" % (n, len(queries)), " ".join(str(parent[i]) for i in range(2, n + 1))]
        data.extend("%d %d" % (a, b) for a, b in queries)
        (TMP / (tag + ".in")).write_text("\n".join(data) + "\n")
        (TMP / (tag + ".expected")).write_text("\n".join(expected) + "\n")
        (TMP / (tag + ".actual")).write_text("\n".join(actual) + "\n")
        raise SystemExit("Mismatch: " + tag)


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--rounds", type=int, default=100)
    args = parser.parse_args()
    rng = random.Random(20261002)
    for round_id in range(args.rounds):
        n = rng.randint(2, 10)
        parent = [0] * (n + 1)
        for v in range(2, n + 1):
            parent[v] = rng.randrange(1, v)
        pairs = [(a, b) for a in range(1, n + 1) for b in range(a + 1, n + 1)]
        rng.shuffle(pairs)
        check(parent, pairs, "random-" + str(round_id))
    for i in (1, 2):
        expected = (ROOT / ("sample%d.out" % i)).read_text().splitlines()
        actual_input = (ROOT / ("sample%d.in" % i)).read_text()
        (TMP / "vine.in").write_text(actual_input)
        subprocess.run([str(EXE)], cwd=TMP, check=True)
        actual = (TMP / "vine.out").read_text().splitlines()
        if actual != expected:
            raise SystemExit("Sample %d mismatch" % i)
    print("PASS: %d fixed-seed random trees (all pairs), samples 1-2" % args.rounds)


if __name__ == "__main__":
    main()
