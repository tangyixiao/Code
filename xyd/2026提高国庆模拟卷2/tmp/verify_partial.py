"""重编译印谱部分分版，独立核验已有暴力用例和q=10上限构造。"""
import math
from pathlib import Path
import subprocess

BASE = Path(__file__).resolve().parents[1]
FIXTURES = BASE / 'tmp' / 'acceptance' / 'epigraphy'
WORK = BASE / 'tmp' / 'partial_acceptance'
WORK.mkdir(parents=True, exist_ok=True)
EXE = WORK / 'partial.exe'
subprocess.run(['g++', '-std=c++11', '-O2', str(BASE / 'epigraphy' / 'partial.cpp'), '-o', str(EXE)], check=True)
cases = 0
for path in sorted(FIXTURES.glob('*.in')):
    if not (path.stem.startswith('random') or path.stem.startswith('sample')):
        continue
    data = path.read_text(encoding='ascii')
    expected = path.with_suffix('.out').read_text(encoding='ascii').split()
    (WORK / 'epigraphy.in').write_text(data, encoding='ascii')
    subprocess.run([str(EXE)], cwd=WORK, check=True, timeout=30)
    actual = (WORK / 'epigraphy.out').read_text(encoding='ascii')
    (WORK / (path.stem + '.out')).write_text(actual, encoding='ascii')
    assert actual.split() == expected, path.stem
    cases += 1
n, m, q = 2000, 10, 10
data = f'{n} {m} {q}\n' + ' '.join(['1023'] * n) + '\n' + '\n'.join(f'{(1 << j) - 1} 1' for j in range(1, 11)) + '\n'
(WORK / 'chain.in').write_text(data, encoding='ascii')
(WORK / 'epigraphy.in').write_text(data, encoding='ascii')
subprocess.run([str(EXE)], cwd=WORK, check=True, timeout=30)
actual = int((WORK / 'epigraphy.out').read_text(encoding='ascii'))
assert actual == math.comb(n + q, q) % 998244353
print('PASS partial:', cases, 'sample/random fixtures plus n=2000,m=10,q=10 chain, independent combination formula')
