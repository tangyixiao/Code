#!/usr/bin/env python3
import argparse
import collections
import pathlib
import random
import subprocess
import time

ROOT = pathlib.Path(__file__).resolve().parent
TMP = ROOT / "tmp"
BIN = TMP / "trim.exe"


def execute(n, edges, ops, timeout=10):
    text = f"{n} {len(ops)}\n" + "".join(f"{u} {v}\n" for u, v in edges)
    text += "".join(" ".join(map(str, op)) + "\n" for op in ops)
    (TMP / "trim.in").write_text(text)
    start = time.perf_counter()
    subprocess.run([str(BIN)], cwd=TMP, check=True, timeout=timeout)
    elapsed = time.perf_counter() - start
    return list(map(int, (TMP / "trim.out").read_text().split())), elapsed


def brute(n, edges, ops):
    g = [[] for _ in range(n + 1)]
    for u, v in edges:
        g[u].append(v)
        g[v].append(u)
    fa = [0] * (n + 1)
    order = [1]
    for u in order:
        for v in g[u]:
            if v != fa[u]:
                fa[v] = u
                order.append(v)
    sub = [{i} for i in range(n + 1)]
    for u in reversed(order[1:]):
        sub[fa[u]].update(sub[u])
    a = [0] * (n + 1)
    ans = []
    for op in ops:
        t, u = op[:2]
        if t == 3:
            ans.append(sum(a[v] for v in sub[u]))
            continue
        _, u, v, w = op
        pre = [-1] * (n + 1)
        pre[u] = 0
        queue = collections.deque([u])
        while queue:
            x = queue.popleft()
            for y in g[x]:
                if pre[y] == -1:
                    pre[y] = x
                    queue.append(y)
        path = set()
        for_node = v
        while for_node:
            path.add(for_node)
            for_node = pre[for_node]
        closed = set(path)
        for x in path:
            closed.update(g[x])
        for x in closed:
            a[x] = a[x] + w if t == 1 else max(a[x], w)
    return ans


def tree(n, shape, rng):
    if shape == "chain":
        return [(i - 1, i) for i in range(2, n + 1)]
    if shape == "star":
        return [(1, i) for i in range(2, n + 1)]
    if shape == "binary":
        return [(i // 2, i) for i in range(2, n + 1)]
    if shape == "broom":
        return [(i - 1 if i <= n // 2 else max(1, n // 2), i) for i in range(2, n + 1)]
    return [(rng.randrange(1, i), i) for i in range(2, n + 1)]


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--rounds", type=int, default=1500)
    parser.add_argument("--large", action="store_true")
    args = parser.parse_args()
    TMP.mkdir(exist_ok=True)
    subprocess.run(["g++", "-std=c++11", "-O2", str(ROOT / "trim.cpp"), "-o", str(BIN)], check=True)
    rng = random.Random(20261026)
    edges = [(1, 2), (2, 3), (3, 4), (3, 5), (2, 6), (2, 7)]
    ops = [(1, 3, 4, 6), (3, 5), (3, 3), (3, 2), (2, 1, 7, 11), (3, 1), (3, 3)]
    got, _ = execute(7, edges, ops)
    assert got == [6, 18, 24, 67, 23], got
    print("sample: PASS")
    for inp in sorted((ROOT / "samples").glob("*.in")):
        (TMP / "trim.in").write_bytes(inp.read_bytes())
        subprocess.run([str(BIN)], cwd=TMP, check=True, timeout=30)
        got = list(map(int, (TMP / "trim.out").read_text().split()))
        expect = list(map(int, inp.with_suffix(".out").read_text().split()))
        assert got == expect, inp.name
        print(f"attachment {inp.name}: PASS")
    shapes = ["chain", "star", "binary", "broom", "random"]
    for case in range(args.rounds):
        n = rng.randrange(1, 46)
        edges = tree(n, shapes[case % 5], rng)
        ops = []
        for j in range(rng.randrange(1, 160)):
            t = rng.randrange(1, 4)
            u, v = rng.randrange(1, n + 1), rng.randrange(1, n + 1)
            if j % 7 == 0:
                v = u
            if t == 3:
                ops.append((3, u))
            else:
                w = rng.choice([0, 1, 2, 5, 10, 100000] if t == 1 else [0, 1, 2, 5, 10, 10**10])
                ops.append((t, u, v, w))
        ops.extend((3, i) for i in range(1, n + 1))
        expect = brute(n, edges, ops)
        got, _ = execute(n, edges, ops)
        if got != expect:
            raise AssertionError((case, n, edges, ops, expect, got))
    print(f"random brute: {args.rounds} PASS (seed=20261026)")
    # The largest legal values also check 64-bit sums and repeated lazy tags.
    n = 100000
    edges = tree(n, "star", rng)
    ops = [(2, 1, 1, 10**10)] + [(1, 1, 1, 100000)] * 99998 + [(3, 1)]
    got, elapsed = execute(n, edges, ops)
    assert got == [n * (10**10 + 99998 * 100000)], got
    print(f"64-bit star n=q=100000: PASS ({elapsed:.3f}s)")
    if args.large:
        for shape in shapes:
            edges = tree(n, shape, rng)
            ops = []
            for i in range(100000):
                u, v = rng.randrange(1, n + 1), rng.randrange(1, n + 1)
                if i % 5 == 4:
                    ops.append((3, u))
                elif i % 2:
                    ops.append((1, u, v, rng.randrange(1, 100001)))
                else:
                    ops.append((2, u, v, rng.randrange(1, 10**10 + 1)))
            got, elapsed = execute(n, edges, ops, 30)
            assert len(got) == 20000
            print(f"large {shape} n=q=100000: completed ({elapsed:.3f}s)")
        rng = random.Random(20261027)
        edges = tree(n, "binary", rng)
        for mode in ["all-add", "rising", "single-point", "equal-level"]:
            ops = []
            for i in range(n):
                u, v = rng.randrange(1, n + 1), rng.randrange(1, n + 1)
                if mode == "all-add":
                    ops.append((1, u, v, rng.randrange(1, 100001)))
                elif mode == "rising":
                    ops.append((1, u, v, rng.randrange(1, 100001)) if i % 2 else (2, u, v, i * 100000 + 1))
                elif mode == "single-point":
                    ops.append((1, u, u, rng.randrange(1, 100001)) if i % 2 else (2, u, v, i * 100000 + 1))
                else:
                    ops.append((1, u, v, rng.randrange(1, 100001)) if i % 2 else (2, u, v, i * 1000 + 1))
            got, elapsed = execute(n, edges, ops, 30)
            assert not got
            print(f"large binary {mode} n=q=100000: completed ({elapsed:.3f}s)")


if __name__ == "__main__":
    main()
