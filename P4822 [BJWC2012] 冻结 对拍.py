import random, subprocess, sys

def solve(n, m, k, edges):
    INF = float('inf')
    d = [[INF]*(k+1) for _ in range(n+1)]
    d[1][0] = 0
    for _ in range(n*(k+1)):
        upd = False
        for a, b, c in edges:
            for j in range(k+1):
                if d[a][j] + c < d[b][j]:
                    d[b][j] = d[a][j] + c; upd = True
                if d[b][j] + c < d[a][j]:
                    d[a][j] = d[b][j] + c; upd = True
                if j < k:
                    if d[a][j] + c//2 < d[b][j+1]:
                        d[b][j+1] = d[a][j] + c//2; upd = True
                    if d[b][j] + c//2 < d[a][j+1]:
                        d[a][j+1] = d[b][j] + c//2; upd = True
        if not upd:
            break
    return min(d[n])

random.seed(4822)
for t in range(300):
    n = random.randint(2, 8)
    k = random.randint(1, n)
    edges = []
    for v in range(2, n+1):
        p = random.randint(1, v-1)
        edges.append((p, v, random.choice([2,4,6,8,10])))
    m = random.randint(n-1, min(n*(n-1)//2, 12))
    while len(edges) < m:
        a = random.randint(1, n); b = random.randint(1, n)
        if a == b: continue
        if any((x==a and y==b) or (x==b and y==a) for x,y,_ in edges): continue
        edges.append((a, b, random.choice([2,4,6,8,10])))
    inp = f"{n} {m} {k}\n"
    for a,b,c in edges:
        inp += f"{a} {b} {c}\n"
    exp = solve(n, m, k, edges)
    r = subprocess.run(["D:/Code/p4822_t.exe"], input=inp, capture_output=True, text=True)
    got = int(r.stdout.strip())
    if got != exp:
        print("MISMATCH at test", t)
        print(inp)
        print("expected", exp, "got", got)
        sys.exit(1)
print("ALL_OK 300 random tests passed")