import random, subprocess, time, os

FOLDER = r'D:\Code\xyd\csps2026moni'

def write_and_run(name, n, edges):
    with open(os.path.join(FOLDER, 'cov.in'), 'w') as f:
        f.write(f'{n} {len(edges)}\n')
        f.write('\n'.join(f'{u} {v}' for u, v in edges) + ('\n' if edges else ''))
    t0 = time.perf_counter()
    r = subprocess.run([os.path.join(FOLDER, 'b.exe')], cwd=FOLDER, capture_output=True, timeout=10)
    dt = (time.perf_counter() - t0) * 1000
    c = subprocess.run([os.path.join(FOLDER, 'bchecker.exe'), 'cov.in', 'cov.out', 'cov.in'],
                       cwd=FOLDER, capture_output=True, timeout=30)
    out = (c.stderr + c.stdout).decode(errors='replace').strip()
    status = 'PASS' if c.returncode == 0 and out.startswith('ok') else 'FAIL'
    print(f'{status}  {name:28s} n={n:5d} m={len(edges):7d}  solve={dt:7.1f}ms  [{out}]')
    return status == 'PASS'

random.seed(20260926)
ok = True

ok &= write_and_run('single vertex', 1, [])
ok &= write_and_run('two vertices', 2, [(1, 2)])
ok &= write_and_run('official sample', 3, [(1, 2), (2, 3)])
ok &= write_and_run('path n=1000', 1000, [(i, i + 1) for i in range(1, 1000)])
ok &= write_and_run('star n=1000', 1000, [(1, i) for i in range(2, 1001)])
ok &= write_and_run('broom', 999, [(i, i + 1) for i in range(1, 500)] + [(500, i) for i in range(501, 1000)])
ok &= write_and_run('caterpillar n=999', 999,
                    [(i, i + 1) for i in range(1, 500)] + [(i, 500 + i) for i in range(1, 500)])
for t, n in enumerate([15, 100, 999, 1000]):
    edges = [(random.randint(1, i - 1), i) for i in range(2, n + 1)]
    ok &= write_and_run(f'random tree #{t}', n, edges)
for t, (n, extra) in enumerate([(1000, 5), (1000, 500), (1000, 5000), (999, 50000)]):
    edges = {(random.randint(1, i - 1), i) for i in range(2, n + 1)}
    while len(edges) < n - 1 + extra:
        u, v = random.randint(1, n), random.randint(1, n)
        if u != v:
            edges.add((min(u, v), max(u, v)))
    ok &= write_and_run(f'random sparse+{extra} #{t}', n, sorted(edges))
n = 100
ok &= write_and_run('complete n=100', n, [(u, v) for u in range(1, n) for v in range(u + 1, n + 1)])

print('ALL PASS' if ok else 'SOME FAILED')
