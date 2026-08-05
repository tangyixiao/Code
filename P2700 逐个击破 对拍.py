import random, subprocess, sys

def brute(n, special, edges):
    m = len(edges)
    best = 10**9
    sp = set(special)
    for mask in range(1 << m):
        fa = list(range(n))
        def find(x):
            while fa[x] != x:
                fa[x] = fa[fa[x]]
                x = fa[x]
            return x
        cost = 0
        for i, (a, b, c) in enumerate(edges):
            if mask >> i & 1:
                cost += c
            else:
                ra, rb = find(a), find(b)
                if ra != rb:
                    fa[ra] = rb
        roots = {find(s) for s in sp}
        if len(roots) == len(sp) and cost < best:
            best = cost
    return best

random.seed(20260618)
for t in range(400):
    n = random.randint(2, 8)
    edges = []
    for v in range(1, n):
        p = random.randint(0, v - 1)
        c = random.randint(1, 10)
        edges.append((p, v, c))
    k = random.randint(2, n)
    special = random.sample(range(n), k)
    inp = f"{n} {k}\n" + " ".join(map(str, special)) + "\n"
    for a, b, c in edges:
        inp += f"{a} {b} {c}\n"
    exp = brute(n, special, edges)
    r = subprocess.run(["D:/Code/p2700_t.exe"], input=inp, capture_output=True, text=True)
    got = int(r.stdout.strip())
    if got != exp:
        print("MISMATCH at test", t)
        print(inp)
        print("expected", exp, "got", got)
        sys.exit(1)
print("ALL_OK 400 random tests passed")