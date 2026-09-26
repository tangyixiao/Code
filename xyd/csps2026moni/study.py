import itertools, random

def naive(a, k):
    a = list(a); n = len(a); cnt = 0
    while True:
        if all(a[i] <= a[i+1] for i in range(n-1)): break
        for i in range(n - k + 1):
            w = a[i:i+k]
            if any(w[t] > w[t+1] for t in range(k-1)):
                a[i:i+k] = sorted(w); cnt += 1
    return cnt

def stream(a, k):
    # pass model: window1 sort iff unsorted; then buffer of k-1, insert a[j] iff < max
    a = list(a); n = len(a); cnt = 0
    while True:
        if all(a[i] <= a[i+1] for i in range(n-1)): break
        if any(a[i] > a[i+1] for i in range(k-1)): cnt += 1; a[0:k] = sorted(a[0:k])
        buf = a[1:k]  # sorted
        for j in range(k, n):
            x = a[j]
            if x < buf[-1]:
                cnt += 1
                # insert x into buf, drop min -> becomes positions j-k+2..j
                import bisect
                bisect.insort(buf, x)
                buf = buf[1:]
            else:
                buf = buf[1:] + [x]
            a[j-k+1] = buf[0] if False else 0  # placeholder
        # rebuild array: finalized prefix + buffer at end
        # easier: redo properly below
        break
    return cnt

# the stream model above got fiddly; implement cleanly:
def stream2(a, k):
    import bisect
    a = list(a); n = len(a); cnt = 0
    while True:
        if all(a[i] <= a[i+1] for i in range(n-1)): return cnt
        if any(a[i] > a[i+1] for i in range(k-1)):
            cnt += 1; a[0:k] = sorted(a[0:k])
        buf = list(a[1:k])  # sorted multiset of positions 2..k
        out = [a[0]]
        for j in range(k, n):
            x = a[j]
            if x < buf[-1]:
                cnt += 1
                bisect.insort(buf, x)
            else:
                bisect.insort(buf, x)
            out.append(buf[0]); buf = buf[1:]
        out.extend(buf)
        a = out

# verify stream2 == naive
bad = 0
for n in range(1, 8):
    for perm in itertools.permutations(range(1, n+1)):
        for k in range(2, n+1):
            if naive(perm, k) != stream2(perm, k):
                print('MISMATCH', perm, k, naive(perm, k), stream2(perm, k)); bad += 1
                break
print('model verified' if not bad else f'{bad} mismatches')

print('reversed tables: rows n, cols k=2..n')
for n in range(2, 13):
    row = [naive(list(range(n, 0, -1)), k) for k in range(2, n+1)]
    print(n, row)

random.seed(1)
print('random perms n=8, k=2..8:')
for t in range(15):
    p = list(range(1, 9)); random.shuffle(p)
    print(p, [naive(p, k) for k in range(2, 9)])
