#!/usr/bin/env python3
"""Compile C++11; compare encrypted queries with BFS; optionally run full limits."""
import argparse
import itertools
import json
import random
import subprocess
import sys
import tempfile
import time
from collections import Counter
from pathlib import Path

MOD = 998244353
HERE = Path(__file__).resolve().parent


def brute(n, k, colors, edges, queries):
    adj = [[] for _ in range(n)]
    for u, v, w in edges:
        adj[u - 1].append((v - 1, w))
        adj[v - 1].append((u - 1, w))
    answers = []
    for s, w in queries:
        seen = {s - 1}
        todo = [s - 1]
        for u in todo:
            for v, weight in adj[u]:
                if weight <= w and v not in seen:
                    seen.add(v)
                    todo.append(v)
        counts = Counter(colors[u] for u in todo)
        answers.append((k + sum(pow(2, c, MOD) - 1 for c in counts.values())) % MOD)
    return answers


def offline(n, k, colors, edges, queries):
    """Independent large-case oracle: sort real queries and maintain DSU maps."""
    fa = list(range(n))
    bags = [{color: 1} for color in colors]
    scores = [k + 1] * n

    def find(x):
        while fa[x] != x:
            fa[x] = fa[fa[x]]
            x = fa[x]
        return x

    powers = [1] * (n + 1)
    for i in range(1, n + 1):
        powers[i] = powers[i - 1] * 2 % MOD
    ordered = sorted(edges, key=lambda e: e[2])
    pos = 0
    answers = [0] * len(queries)
    for i in sorted(range(len(queries)), key=lambda i: queries[i][1]):
        s, w = queries[i]
        while pos < len(edges) and ordered[pos][2] <= w:
            u, v, _ = ordered[pos]
            pos += 1
            u, v = find(u - 1), find(v - 1)
            if u == v:
                continue
            if len(bags[u]) < len(bags[v]):
                u, v = v, u
            for color, count in bags[v].items():
                old = bags[u].get(color, 0)
                scores[u] += powers[old + count] - powers[old]
                bags[u][color] = old + count
            scores[u] %= MOD
            bags[v].clear()
            fa[v] = u
        answers[i] = scores[find(s - 1)]
    return answers


def run(binary, directory, n, k, colors, edges, queries, answers, timed=False):
    last = 0
    data = [f"{n} {k} {len(edges)} {len(queries)}", " ".join(map(str, colors))]
    data.extend(f"{u} {v} {w}" for u, v, w in edges)
    for (s, w), answer in zip(queries, answers):
        data.append(f"{s ^ last} {w ^ last}")
        last = answer
    (directory / "garden.in").write_text("\n".join(data) + "\n")
    command = [str(binary)]
    if timed:
        helper = "import resource,subprocess,sys,time; t=time.perf_counter(); p=subprocess.run([sys.argv[1]]); print(time.perf_counter()-t, resource.getrusage(resource.RUSAGE_CHILDREN).ru_maxrss); sys.exit(p.returncode)"
        command = [sys.executable, "-c", helper, str(binary)]
    proc = subprocess.run(command, cwd=directory, capture_output=True, text=True, timeout=30)
    if proc.returncode:
        raise AssertionError(f"C++ failed: {proc.returncode}\n{proc.stderr}")
    actual = list(map(int, (directory / "garden.out").read_text().split()))
    if actual != answers:
        (HERE / "failed.in").write_text("\n".join(data) + "\n")
        raise AssertionError(f"Mismatch; saved failed.in\nexpected={answers}\nactual={actual}")
    if timed:
        seconds, memory = proc.stdout.split()
        return {"seconds": round(float(seconds), 3), "peak_rss_kib": int(memory)}


def stress_case(kind, rng):
    n, k = 100000, 100000
    colors = list(range(1, n + 1))
    if kind == "one_color":
        k, colors = 1, [1] * n
    elif kind == "few_colors":
        colors = [rng.randrange(1, 301) for _ in range(n)]
    if kind == "disconnected_equal_weights":
        edges = [(i, i + 1, 7) for i in range(1, n) if i % 1000]
    else:
        edges = [(i, i + 1, i + 1) for i in range(1, n)]
    present = {(u, v) for u, v, _ in edges}
    while len(edges) < 200000:
        u = rng.randrange(1, n)
        v = rng.randrange(u + 1, n + 1)
        if kind == "disconnected_equal_weights" and (u - 1) // 1000 != (v - 1) // 1000:
            continue
        if (u, v) in present:
            continue
        present.add((u, v))
        weight = 7 if kind == "disconnected_equal_weights" else rng.randrange(n + 1, MOD)
        edges.append((u, v, weight))
    queries = [(rng.randrange(1, n + 1), rng.choice([1, 6, 7, n // 2, n, MOD - 1, rng.randrange(1, MOD)])) for _ in range(100000)]
    queries[:4] = [(1, 1), (1, n), (n, n // 2), (n, MOD - 1)]
    return n, k, colors, edges, queries


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--cases", type=int, default=4000)
    parser.add_argument("--stress", action="store_true")
    parser.add_argument("--sanitize", action="store_true")
    args = parser.parse_args()
    rng = random.Random(20261026)
    report = {"seed": 20261026, "sanitizers": args.sanitize}
    start = time.perf_counter()
    with tempfile.TemporaryDirectory(prefix="garden-verify-") as temp:
        directory = Path(temp)
        binary = directory / "garden"
        flags = ["-O2"]
        if args.sanitize:
            flags = ["-O1", "-g", "-fsanitize=address,undefined", "-fno-omit-frame-pointer", "-no-pie"]
        subprocess.run(["g++", "-std=c++11", *flags, str(HERE / "garden.cpp"), "-o", str(binary)], check=True)
        report["official_samples"] = []
        for source in sorted((HERE / "samples").glob("*.in")):
            expected = source.with_suffix(".out")
            if not expected.exists():
                continue
            (directory / "garden.in").write_bytes(source.read_bytes())
            proc = subprocess.run([str(binary)], cwd=directory, capture_output=True, text=True, timeout=30)
            assert proc.returncode == 0, proc.stderr
            assert (directory / "garden.out").read_text().split() == expected.read_text().split(), source.name
            report["official_samples"].append(source.name)
        sample = (6, 3, [1, 2, 1, 3, 2, 3], [(1, 2, 2), (2, 3, 5), (3, 4, 3), (4, 5, 7), (5, 6, 1), (2, 5, 4)], [(1, 1), (6, 1), (3, 3), (1, 4), (4, 7)])
        run(binary, directory, *sample, [4, 5, 5, 8, 12])
        exhaustive = 0
        n, k = 3, 2
        pairs = list(itertools.combinations(range(1, n + 1), 2))
        for states in itertools.product(range(3), repeat=len(pairs)):
            edges = [(u, v, state) for (u, v), state in zip(pairs, states) if state]
            if not edges:
                continue
            for colors in itertools.product(range(1, k + 1), repeat=n):
                queries = list(itertools.product(range(1, n + 1), range(1, 4)))
                run(binary, directory, n, k, colors, edges, queries, brute(n, k, colors, edges, queries))
                exhaustive += 1
        report["exhaustive_cases"] = exhaustive
        for case in range(args.cases):
            n = rng.randrange(2, 46)
            k = rng.choice([1, n, rng.randrange(1, 65)])
            colors = [rng.randrange(1, k + 1) for _ in range(n)]
            pairs = list(itertools.combinations(range(1, n + 1), 2))
            rng.shuffle(pairs)
            edges = [(u, v, rng.randrange(1, 22)) for u, v in pairs[:rng.randrange(1, len(pairs) + 1)]]
            queries = [(rng.randrange(1, n + 1), rng.choice([1, 21, MOD - 1, rng.randrange(1, 23)])) for _ in range(rng.randrange(1, 70))]
            answers = brute(n, k, colors, edges, queries)
            assert offline(n, k, colors, edges, queries) == answers
            run(binary, directory, n, k, colors, edges, queries, answers)
        report["random_cases"] = args.cases
        if args.stress:
            report["stress"] = {}
            for kind in ["distinct_colors_deep_tree", "one_color", "few_colors", "disconnected_equal_weights"]:
                case = stress_case(kind, rng)
                answers = offline(*case)
                report["stress"][kind] = run(binary, directory, *case, answers, timed=True)
                print(kind, report["stress"][kind], flush=True)
    report["total_seconds"] = round(time.perf_counter() - start, 2)
    print(json.dumps(report, ensure_ascii=False, indent=2))


if __name__ == "__main__":
    main()
