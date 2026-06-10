import zstandard as zstd
import tarfile

src = r'C:\Users\tany\AppData\Local\Temp\zsh.pkg.tar.zst'
tar_out = r'C:\Users\tany\AppData\Local\Temp\zsh-extracted.tar'

# 1. 解压 zst → tar
with open(src, 'rb') as f:
    dctx = zstd.ZstdDecompressor()
    data = dctx.stream_reader(f).read()
with open(tar_out, 'wb') as out:
    out.write(data)

# 2. 解包 tar
with tarfile.open(tar_out, 'r') as tar:
    tar.extractall(r'C:\Users\tany\AppData\Local\Temp\zsh-extracted')