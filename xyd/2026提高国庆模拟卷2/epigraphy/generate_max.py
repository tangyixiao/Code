from pathlib import Path


ROOT = Path(__file__).resolve().parent
TMP = ROOT / "tmp"
N = 200000
M = 16


def main():
    TMP.mkdir(exist_ok=True)
    path = TMP / "max.in"
    with path.open("w", encoding="ascii", newline="\n") as f:
        f.write(f"{N} {M} {(1 << M) - 1}\n")
        f.write((f"{(1 << M) - 1} " * (N - 1)) + f"{(1 << M) - 1}\n")
        for s in range(1, 1 << M):
            f.write(f"{s} {1 + bin(s).count('1')}\n")
    print(path)


if __name__ == "__main__":
    main()
