"""独立编译、样例、暴力和20万规模验收。所有输入/输出保留于tmp/acceptance。

用法：python tmp/acceptance.py；仅运行指定题：--only notch vine。
"""
import argparse
import functools
import itertools
import json
import math
from pathlib import Path
import random
import subprocess
import time

BASE = Path(__file__).resolve().parents[1]
OUT = BASE / 'tmp' / 'acceptance'
MOD = 998244353
RNG = random.Random(2026100202)
REPORT = []


def run(name, label, data, expected=None, sample=None):
    folder = OUT / name
    folder.mkdir(parents=True, exist_ok=True)
    source = folder / (label + '.in')
    source.write_text(data, encoding='ascii')
    (folder / (name + '.in')).write_text(data, encoding='ascii')
    start = time.perf_counter()
    subprocess.run([str(folder / (name + '.exe'))], cwd=folder, check=True, timeout=30)
    elapsed = time.perf_counter() - start
    actual = (folder / (name + '.out')).read_text(encoding='ascii')
    (folder / (label + '.out')).write_text(actual, encoding='ascii')
    if sample:
        expected = sample.read_text(encoding='ascii')
    if expected is not None:
        want = expected if isinstance(expected, str) else ' '.join(map(str, expected))
        if actual.split() != want.split():
            (folder / (label + '.expected')).write_text(want, encoding='ascii')
            raise AssertionError((name, label, actual[:200], want[:200]))
    REPORT.append({'problem': name, 'case': label, 'seconds': round(elapsed, 4), 'checked': expected is not None})
    if not label.startswith('random'):
        print(name, label, 'PASS', round(elapsed, 4), 's', flush=True)


def compile_problem(name):
    folder = OUT / name
    folder.mkdir(parents=True, exist_ok=True)
    subprocess.run(['g++', '-std=c++11', '-O2', str(BASE / name / (name + '.cpp')), '-o', str(folder / (name + '.exe'))], check=True)
    for sample in sorted((BASE / name).glob('sample*.in')):
        run(name, sample.stem, sample.read_text(encoding='ascii'), sample=sample.with_suffix('.out'))


def notch_oracle(a):
    ans = [0] * (len(a) + 1)
    for l in range(len(a)):
        seen, low, mex = set(), len(a), 0
        for x in a[l:]:
            seen.add(x)
            low = min(low, x)
            while mex in seen:
                mex += 1
            ans[low + mex] += 1
    return ans[1:]


def test_notch():
    for k in range(35):
        a = list(range(RNG.randint(1, 40)))
        RNG.shuffle(a)
        run('notch', f'random{k}', str(len(a)) + '\n' + ' '.join(map(str, a)), notch_oracle(a))
    n = 200000
    for label, a in [('ascending', range(n)), ('descending', range(n - 1, -1, -1))]:
        run('notch', label, str(n) + '\n' + ' '.join(map(str, a)), range(n, 0, -1))


def test_vine():
    for case in range(35):
        n = RNG.randint(2, 18)
        p = [-1] + [RNG.randrange(i) for i in range(1, n)]

        def moves(a, b):
            for coin, (u, v) in enumerate(((a, b), (b, a))):
                u = p[u]
                while u >= 0 and u != v:
                    yield (u, b) if coin == 0 else (a, u)
                    u = p[u]

        @functools.lru_cache(None)
        def win(a, b):
            return any(not win(x, y) for x, y in moves(a, b))

        pairs = list(itertools.combinations(range(n), 2))
        expected = []
        for a, b in pairs:
            count = sum(not win(x, y) for x, y in moves(a, b))
            expected.extend(('First' if count else 'Second', count))
        data = f'{n} {len(pairs)}\n' + ' '.join(str(x + 1) for x in p[1:]) + '\n' + '\n'.join(f'{a + 1} {b + 1}' for a, b in pairs)
        run('vine', f'random{case}', data, expected)
    n = q = 200000
    data = f'{n} {q}\n' + ' '.join(map(str, range(1, n))) + '\n' + '\n'.join('1 2' if i % 2 else f'1 {n}' for i in range(q))
    run('vine', 'chain', data, '\n'.join('Second 0' if i % 2 else 'First 1' for i in range(q)))
    data = f'{n} {q}\n' + ' '.join(['1'] * (n - 1)) + '\n' + '\n'.join('1 2' if i % 2 else '2 3' for i in range(q))
    run('vine', 'star', data, '\n'.join('Second 0' if i % 2 else 'First 2' for i in range(q)))


def factor_triples(m):
    for x in range(1, m + 1):
        if m % x == 0:
            for y in range(1, m // x + 1):
                if m // x % y == 0:
                    yield x, y, m // x // y


def isogeny_oracle(a, m):
    best = ways = 0
    for ids in itertools.permutations(range(len(a)), 3):
        for multipliers in factor_triples(m):
            b = a[:]
            for i, x in zip(ids, multipliers):
                b[i] *= x
            val = functools.reduce(math.gcd, b)
            if val > best:
                best, ways = val, 1
            elif val == best:
                ways += 1
    return best, ways % MOD


def tau3(m):
    val, p = 1, 2
    while p * p <= m:
        e = 0
        while m % p == 0:
            e += 1
            m //= p
        val *= (e + 1) * (e + 2) // 2
        p += 1
    return val * (3 if m > 1 else 1)


def test_isogeny():
    for case in range(35):
        a = [RNG.randint(1, 40) for _ in range(RNG.randint(3, 7))]
        ms = [1, 2, 3, 6, 8, 12, 25, 30, 36, 45]
        expected = [x for m in ms for x in isogeny_oracle(a, m)]
        data = f'{len(a)} {len(ms)}\n' + ' '.join(map(str, a)) + '\n' + '\n'.join(map(str, ms))
        run('isogeny', f'random{case}', data, expected)
    run('isogeny', 'n3_large_m', '3 5\n1 1 1\n1000000\n999983\n262144\n1\n216\n', [100, 6, 1, 18, 64, 6, 1, 6, 6, 6])
    n = q = 200000
    data = f'{n} {q}\n' + ' '.join(['1000000'] * n) + '\n' + '\n'.join(['1000000'] * q)
    count = n * (n - 1) * (n - 2) * tau3(1000000) % MOD
    run('isogeny', 'equal_upper', data, '\n'.join([f'1000000 {count}'] * q))
    data = f'{n} {q}\n1 ' + ' '.join(['720720'] * (n - 1)) + '\n' + '\n'.join(['1000000'] * q)
    d = math.gcd(720720, 1000000)
    count = 6 * math.comb(n - 1, 2) * tau3(1000000 // d) % MOD
    run('isogeny', 'many_divisors_upper', data, '\n'.join([f'{d} {count}'] * q))


def epigraphy_oracle(n, a, stamps):
    dp = {0: 1}
    for day, mask in enumerate(a, 1):
        dp = {s: sum(v for t, v in dp.items() if t & s == t) % MOD for s, d in stamps.items() if d <= day and s & mask == s}
    return sum(dp.values()) % MOD


def test_epigraphy():
    for case in range(35):
        n, m = RNG.randint(1, 20), RNG.randint(1, 7)
        full = (1 << m) - 1
        chosen = [0] + [s for s in range(1, full + 1) if RNG.randrange(2)]
        stamps = {0: 1}
        for s in chosen[1:]:
            stamps[s] = RNG.randint(max(d for t, d in stamps.items() if t & s == t), n)
        a = [RNG.randint(0, full) for _ in range(n)] if case % 2 else [full] * n
        data = f'{n} {m} {len(chosen) - 1}\n' + ' '.join(map(str, a)) + '\n' + '\n'.join(f'{s} {d}' for s, d in stamps.items() if s)
        run('epigraphy', f'random{case}', data, [epigraphy_oracle(n, a, stamps)])
    n, m, full = 200000, 16, 65535
    head = f'{n} {m} {full}\n' + ' '.join([str(full)] * n) + '\n'
    data = head + '\n'.join(f'{s} 1' for s in range(1, full + 1))
    run('epigraphy', 'full_upper', data, [pow(n + 1, m, MOD)])
    f = [1] + [0] * m
    for stage in range(1, m + 1):
        f = [sum(math.comb(r, k) * f[k] for k in range(r + 1)) % MOD if r <= stage else 0 for r in range(m + 1)]
    expected = sum(math.comb(m, r) * f[r] for r in range(m + 1)) % MOD
    data = head + '\n'.join(f'{s} {n - m + s.bit_count()}' for s in range(1, full + 1))
    run('epigraphy', 'late_upper', data, [expected])
    data = f'{n} {m} {full}\n' + ' '.join([str(full)] * (n - 1) + ['0']) + '\n' + '\n'.join(f'{s} 1' for s in range(1, full + 1))
    run('epigraphy', 'last_day_empty', data, [1])


if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('--only', nargs='+', choices=['notch', 'vine', 'isogeny', 'epigraphy'])
    args = parser.parse_args()
    names = args.only or ['notch', 'vine', 'isogeny', 'epigraphy']
    for name in names:
        compile_problem(name)
        globals()['test_' + name]()
        print(name, 'all checks passed', flush=True)
    OUT.mkdir(parents=True, exist_ok=True)
    (OUT / 'report.json').write_text(json.dumps(REPORT, indent=2), encoding='utf-8')
    print('PASS', len(REPORT), 'executable cases; report:', OUT / 'report.json', flush=True)
