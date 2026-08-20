import argparse
import csv
import re
from pathlib import Path


def base_name(pid, title):
    s = re.sub(r'[/\\:*?"<>|]+', '_', title)
    s = re.sub(r'_+', '_', s).strip()
    return f'{pid} {s}'


def unique_rows(rows):
    a = []
    s = set()
    for x in rows:
        if x[0] not in s:
            s.add(x[0])
            a.append(x)
    return a


def required_files(base):
    return [
        f'{base}.md', f'{base} 题解.md', f'{base}.cpp',
        f'{base} 数据生成.cpp', f'{base} 暴力.cpp', f'{base} 对拍.cpp'
    ]


def load_manifest(path):
    with path.open(encoding='utf-8') as f:
        return list(csv.DictReader(f, delimiter='\t'))


def check(root, manifest, phase=None):
    rows = load_manifest(manifest)
    if phase:
        rows = [x for x in rows if x['phase'] == phase]
    errors = []
    seen = set()
    for x in rows:
        pid = x['id']
        if pid in seen:
            errors.append(f'duplicate id: {pid}')
        seen.add(pid)
        base = x['base']
        for name in required_files(base):
            if not (root / name).is_file():
                errors.append(f'missing: {name}')
        d = root / 'cph' / base
        if not d.is_dir():
            errors.append(f'missing: cph/{base}')
        elif not list(d.glob('*.in')) or not list(d.glob('*.ans')):
            errors.append(f'missing cases: cph/{base}')
    return errors


def main():
    p = argparse.ArgumentParser()
    p.add_argument('--root', type=Path, default=Path(__file__).resolve().parent.parent)
    p.add_argument('--manifest', type=Path, default=Path(__file__).resolve().parent / 'manifest.tsv')
    p.add_argument('--phase')
    a = p.parse_args()
    e = check(a.root, a.manifest, a.phase)
    if e:
        print('\n'.join(e))
        raise SystemExit(1)
    print('OK')


if __name__ == '__main__':
    main()
