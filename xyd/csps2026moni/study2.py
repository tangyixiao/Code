import bisect, random

def detailed(a, k):
    a = list(a); n = len(a); cnt = 0; W = 0; J = 0
    ins_cnt = {x: 0 for x in a}
    passes = 0
    while True:
        if all(a[i] <= a[i+1] for i in range(n-1)): break
        passes += 1
        w1 = any(a[i] > a[i+1] for i in range(k-1))
        if w1: cnt += 1; W += 1; a[0:k] = sorted(a[0:k])
        buf = list(a[1:k]); moved = {x: 0 for x in a}
        out = [a[0]]
        for j in range(k, n):
            x = a[j]
            bisect.insort(buf, x)
            if x < buf[-2] if len(buf) > 1 else False:
                pass
            if buf[-1] != x:  # x not max -> insertion event
                cnt += 1; J += 1; ins_cnt[x] += 1
            out.append(buf[0]); buf = buf[1:]
        out.extend(buf)
        a = out
    return cnt, W, J, ins_cnt, passes

print('reversed: n, k: cnt, W, J, passes, per-element insertions (by value)')
for n in range(4, 11):
    for k in range(3, min(n, 6) + 1):
        cnt, W, J, ic, P = detailed(list(range(n, 0, -1)), k)
        seq = [ic[v] for v in range(1, n+1)]
        print(f'n={n} k={k}: cnt={cnt} W={W} J={J} P={P} ins={seq}')

random.seed(7)
print()
for t in range(8):
    p = list(range(1, 9)); random.shuffle(p)
    for k in (3, 4):
        cnt, W, J, ic, P = detailed(p, k)
        seq = [ic[v] for v in range(1, 9)]
        print(f'{p} k={k}: cnt={cnt} W={W} J={J} P={P} ins={seq}')
