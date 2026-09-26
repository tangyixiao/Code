import itertools

def naive(a, k):
    a = list(a); n = len(a); cnt = 0
    while True:
        if all(a[i] <= a[i+1] for i in range(n-1)): break
        for i in range(n - k + 1):
            w = a[i:i+k]
            if any(w[t] > w[t+1] for t in range(k-1)):
                a[i:i+k] = sorted(w); cnt += 1
    return cnt

def blocks_formula(a, k, lo_mode):
    # for each value x at position p: scan left from p down to L (range depends on lo_mode),
    # blocks = maximal runs of elements > x (delimited by elements < x or range edge)
    # F(x) = sum over blocks of ceil(c/(k-1)); return sum of F(x)
    n = len(a); pos = {v: i+1 for i, v in enumerate(a)}; km = k - 1
    total = 0
    for x in range(1, n+1):
        p = pos[x]
        if lo_mode == 'final': L = x            # down to final position x
        elif lo_mode == 'final_incl': L = x - 1
        elif lo_mode == 'one': L = 1
        run = 0; fx = 0
        for i in range(p - 1, max(L - 1, 0), -1):   # positions p-1 .. L (1-based)
            if a[i-1] > x:
                run += 1
            else:
                fx += (run + km - 1) // km; run = 0
        fx += (run + km - 1) // km
        total += fx
    return total

ok = {m: 0 for m in ('final', 'final_incl', 'one')}
bad = {m: [] for m in ('final', 'final_incl', 'one')}
tot = 0
for n in range(2, 7):
    for perm in itertools.permutations(range(1, n+1)):
        if list(perm) == sorted(perm): continue
        for k in range(2, n+1):
            c = naive(perm, k); tot += 1
            for m in ok:
                f = blocks_formula(list(perm), k, m)
                if f == c: ok[m] += 1
                elif len(bad[m]) < 4: bad[m].append((perm, k, c, f))
print('tests:', tot)
for m in ok:
    print(m, 'match', ok[m], '/', tot)
    for b in bad[m]: print('   mismatch', b)
