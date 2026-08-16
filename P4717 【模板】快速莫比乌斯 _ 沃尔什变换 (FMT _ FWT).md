# P4717 【模板】快速莫比乌斯 / 沃尔什变换 (FMT / FWT)

## 题目描述

给定长度为 $2^n$ 两个序列 $A,B$，设 

$$C_i=\sum_{j\oplus k = i}A_j \times B_k$$

分别当 $\oplus$ 是 or, and, xor 时求出 $C$。

## 输入格式

第一行，一个整数 $n$。  
第二行，$2^n$ 个数 $A_0, A_1, \ldots, A_{2^n-1}$。  
第三行，$2^n$ 个数 $B_0, B_1, \ldots, B_{2^n-1}$。

## 输出格式

三行，每行 $2^n$ 个数，分别代表 $\oplus$ 是 or, and, xor 时 $C_0, C_1, \ldots, C_{2^n-1}$ 的值 $\bmod\ 998244353$。

## 输入输出样例 #1

### 输入 #1

```
2
2 4 6 8
1 3 5 7

```

### 输出 #1

```
2 22 46 250
88 64 112 56
100 92 68 60

```

## 说明/提示

### 数据范围

* $1 \le n \le 17$
* $0\le a_i,b_i<998244353$

---

# P4717 [Template] Fast Möbius / Walsh Transform (FMT / FWT)

## 题目描述

Given two sequences $A$ and $B$ of length $2^n$, define

$$C_i=\sum_{j\oplus k = i}A_j \times B_k$$

Compute $C$ respectively when $\oplus$ is OR, AND, and XOR.

## 输入格式

The first line contains an integer $n$.  
The second line contains $2^n$ numbers $A_0, A_1, \ldots, A_{2^n-1}$.  
The third line contains $2^n$ numbers $B_0, B_1, \ldots, A_{2^n-1}$.

## 输出格式

Output three lines. Each line contains $2^n$ numbers, representing the values of $C_0, C_1, \ldots, C_{2^n-1}$ when $\oplus$ is OR, AND, and XOR, respectively, taken $\bmod\ 998244353$.

## 输入输出样例 #1

### 输入 #1

```
2
2 4 6 8
1 3 5 7

```

### 输出 #1

```
2 22 46 250
88 64 112 56
100 92 68 60

```

## 说明/提示

### Data Constraints

* $1 \le n \le 17$
* $0\le a_i,b_i<998244353$

Translated by ChatGPT 5