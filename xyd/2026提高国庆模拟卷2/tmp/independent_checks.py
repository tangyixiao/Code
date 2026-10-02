"""主代理独立数学核验；保留枚举过程，运行 python tmp/independent_checks.py。"""
import functools
import itertools
import math
import random

MOD = 998244353
RNG = random.Random(20261002)


def check_notch():
    cases = 0
    for n in range(1, 9):
        for a in itertools.permutations(range(n)):
            want = [0] * (n + 1)
            for l in range(n):
                seen, low, mex = set(), n, 0
                for r in range(l, n):
                    seen.add(a[r])
                    low = min(low, a[r])
                    while mex in seen:
                        mex += 1
                    want[low + mex] += 1
            got = [0] * (n + 1)
            for i, x in enumerate(a):
                if x == 0:
                    continue
                l, r = i - 1, i + 1
                while l >= 0 and a[l] > x:
                    l -= 1
                while r < n and a[r] > x:
                    r += 1
                got[x] += (i - l) * (r - i)
            p = [a.index(i) for i in range(n)]
            l, r, prev = n, -1, 0
            for k in range(1, n + 1):
                l, r = min(l, p[k - 1]), max(r, p[k - 1])
                now = (l + 1) * (n - r)
                if k > 1:
                    got[k - 1] += prev - now
                prev = now
            got[n] += prev
            assert got == want, (a, got, want)
            cases += 1
    print('notch: all permutations through n=8:', cases, 'passed', flush=True)


def check_vine():
    trees = states = 0
    for n in range(2, 9):
        for ps in itertools.product(*(range(i) for i in range(1, n))):
            p, dep = (-1,) + ps, [0] * n
            for i in range(1, n):
                dep[i] = dep[p[i]] + 1

            def moves(a, b):
                for coin, (u, v) in enumerate(((a, b), (b, a))):
                    u = p[u]
                    while u >= 0 and u != v:
                        yield (u, b) if coin == 0 else (a, u)
                        u = p[u]

            @functools.lru_cache(None)
            def win(a, b):
                return any(not win(x, y) for x, y in moves(a, b))

            for a in range(n):
                for b in range(a + 1, n):
                    x, y = a, b
                    while dep[x] > dep[y]:
                        x = p[x]
                    while dep[y] > dep[x]:
                        y = p[y]
                    while x != y:
                        x, y = p[x], p[y]
                    u, v = dep[a] - dep[x], dep[b] - dep[x]
                    got = 0 if ((u == 0 or v == 0) and u + v == 1) or (u == v and u >= 2) else 2 if u == v == 1 else 1
                    want = sum(not win(x, y) for x, y in moves(a, b))
                    assert got == want, (n, p, a, b, got, want)
                    states += 1
            trees += 1
    print('vine:', trees, 'trees,', states, 'states passed', flush=True)


def factors(m):
    for x in range(1, m + 1):
        if m % x:
            continue
        for y in range(1, m // x + 1):
            if m // x % y == 0:
                yield x, y, m // x // y


def check_isogeny():
    for case in range(600):
        n, m = RNG.randint(3, 7), RNG.randint(1, 45)
        a = [RNG.randint(1, 30) for _ in range(n)]
        if case % 4 == 0:
            a = [x * 6 for x in a]
        best, ways = 0, 0
        for ids in itertools.permutations(range(n), 3):
            for xyz in factors(m):
                b = a[:]
                for i, x in zip(ids, xyz):
                    b[i] *= x
                val = functools.reduce(math.gcd, b)
                if val > best:
                    best, ways = val, 1
                elif val == best:
                    ways += 1
        g = functools.reduce(math.gcd, a)
        b = [x // g for x in a]
        for d in range(m, 0, -1):
            if m % d:
                continue
            h = [d // math.gcd(d, x) for x in b]
            t, need = sum(x != 1 for x in h), math.prod(h)
            assert need % d == 0
            if t <= 3 and m % need == 0:
                got = (g * d, 6 * math.comb(n - t, 3 - t) * sum(1 for _ in factors(m // need)))
                break
        assert got == (best, ways), (a, m, got, best, ways)
    print('isogeny: 600 independent ordered-triple enumerations passed', flush=True)


def check_epigraphy():
    for case in range(800):
        m, n = RNG.randint(1, 5), RNG.randint(1, 10)
        full = (1 << m) - 1
        stamps = [0] + [s for s in range(1, full + 1) if RNG.randrange(3)]
        days = {0: 1}
        for s in sorted(stamps[1:], key=int.bit_count):
            days[s] = RNG.randint(max(days[t] for t in days if t & s == t), n)
        a = [RNG.randint(0, full) for _ in range(n)]
        if case % 3 == 0:
            a = [full] * n
        f = {0: 1}
        for i, mask in enumerate(a, 1):
            f = {s: sum(v for t, v in f.items() if t & s == t) % MOD
                 for s in stamps if days[s] <= i and s & mask == s}
        want = sum(f.values()) % MOD
        last = [max([0] + [i for i, mask in enumerate(a, 1) if not mask >> b & 1]) for b in range(m)]
        release = {s: max([days[s]] + [last[b] + 1 for b in range(m) if s >> b & 1]) for s in stamps}
        coef = {0: [1]}
        for s in sorted(stamps[1:], key=int.bit_count):
            if release[s] > n:
                continue
            c = [0] * (s.bit_count() + 1)
            for t in coef:
                if t & s == t:
                    for k, v in enumerate(coef[t]):
                        c[k + 1] = (c[k + 1] + v) % MOD
            c[0] = -sum(c[k] * (math.comb(release[s] - 1, k) if k < release[s] else 0)
                        for k in range(1, len(c))) % MOD
            coef[s] = c
        got = sum(v * (math.comb(n, k) if k <= n else 0) for c in coef.values() for k, v in enumerate(c)) % MOD
        assert got == want, (m, n, stamps, days, a, got, want)
    print('epigraphy: 800 independent day-by-day DP comparisons passed', flush=True)


if __name__ == '__main__':
    check_notch()
    check_vine()
    check_isogeny()
    check_epigraphy()
