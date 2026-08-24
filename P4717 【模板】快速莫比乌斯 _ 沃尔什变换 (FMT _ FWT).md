# P4717 【模板】快速莫比乌斯 / 沃尔什变换 (FMT / FWT)

## 中文题面

### 题目描述

给定长度为 $2^n$ 两个序列 $A,B$，设

$$C_i=\sum_{j\oplus k = i}A_j \times B_k$$

分别当 $\oplus$ 是 or, and, xor 时求出 $C$。

### 输入格式

第一行，一个整数 $n$。
第二行，$2^n$ 个数 $A_0, A_1, \ldots, A_{2^n-1}$。
第三行，$2^n$ 个数 $B_0, B_1, \ldots, B_{2^n-1}$。

### 输出格式

三行，每行 $2^n$ 个数，分别代表 $\oplus$ 是 or, and, xor 时 $C_0, C_1, \ldots, C_{2^n-1}$ 的值 $\bmod\ 998244353$。

### 样例 1

```text
2
2 4 6 8
1 3 5 7
```

```text
2 22 46 250
88 64 112 56
100 92 68 60
```

### 说明与限制

### 数据范围

* $1 \le n \le 17$
* $0\le a_i,b_i<998244353$

## English Statement

### Description

Given two sequences $A$ and $B$ of length $2^n$, define $C_i=\sum_{j\mathbin{\circ}k=i}A_jB_k$. Compute $C$ when $\circ$ is bitwise OR, bitwise AND, and bitwise XOR.

### Input

The first line contains $n$. The second line contains $2^n$ integers $A_0,\ldots,A_{2^n-1}$, and the third line contains $2^n$ integers $B_0,\ldots,B_{2^n-1}$.

### Output

Print three lines of $2^n$ integers. They are the OR, AND, and XOR convolutions, respectively, modulo $998244353$.

### Constraints

$1\le n\le17$ and $0\le A_i,B_i<998244353$.
