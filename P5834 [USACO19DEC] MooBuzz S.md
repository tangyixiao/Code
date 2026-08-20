# P5834 [USACO19DEC] MooBuzz S

## 中文题面

奶牛从 1 开始依次报数，但 3 或 5 的倍数只会被说成 `Moo`。给定正整数 $N$，求第 $N$ 个真正被说出的数字。

### 输入

一个整数 $N$。

### 输出

第 $N$ 个既不是 3 的倍数、也不是 5 的倍数的正整数。

### 样例

```text
4
```

```text
7
```

### 数据范围

$1\le N\le 10^9$。测试点 2 至 5 满足 $N\le 10^6$。

## English Statement

Starting from 1, every multiple of 3 or 5 is replaced by `Moo`. Given $N$, output the $N$-th positive integer that is actually spoken.

Input contains one integer $N$. Output the $N$-th positive integer divisible by neither 3 nor 5. The constraints are $1\le N\le 10^9$.
