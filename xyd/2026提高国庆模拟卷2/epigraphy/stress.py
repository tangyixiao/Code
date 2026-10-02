import argparse
import random
import subprocess
from pathlib import Path


ROOT = Path(__file__).resolve().parent
TMP = ROOT / "tmp"
MOD = 998244353
SEED = 20261002
ROUNDS = 300


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
    parser.add_argument("--rounds", type=int, default=ROUNDS)
    rounds = parser.parse_args().rounds
    TMP.mkdir(exist_ok=True)
    exe = TMP / "epigraphy.exe"
    partial = TMP / "partial.exe"
    subprocess.run(["g++", "-std=c++11", "-O2", str(ROOT / "epigraphy.cpp"), "-o", str(exe)], check=True)
    subprocess.run(["g++", "-std=c++11", "-O2", str(ROOT / "partial.cpp"), "-o", str(partial)], check=True)
    rng = random.Random(SEED)
    input_path = TMP / "epigraphy.in"
    output_path = TMP / "epigraphy.out"
    cases = []
    for m in range(1, 7):
        n = 8
        cases.append((n, m, [(1 << m) - 1] * n, {s: 1 for s in range(1 << m)}))
    for n, m, days in [(1, 6, [63]), (9, 5, [31] * 8 + [0])]:
        cases.append((n, m, days, {s: 1 for s in range(1 << m)}))
    cases.extend(make_case(rng) for _ in range(rounds))
    for case_id, (n, m, days, stamps) in enumerate(cases, 1):
        data = encode(n, m, days, stamps)
        expected = brute(n, m, days, stamps)
        input_path.write_text(data, encoding="ascii")
        for name, program in (("optimized", exe), ("partial", partial)):
            subprocess.run([str(program)], cwd=TMP, check=True)
            actual = int(output_path.read_text(encoding="ascii").strip())
            if actual != expected:
                (TMP / "failed.in").write_text(data, encoding="ascii")
                (TMP / "failed.expected").write_text(f"{expected}\n", encoding="ascii")
                (TMP / "failed.actual").write_text(f"{actual}\n", encoding="ascii")
                raise SystemExit(f"{name} mismatch at case {case_id}: {expected} != {actual}")
    print(f"OK: {len(cases)} cases, seed={SEED}; optimized and partial")


if __name__ == "__main__":
    main()
