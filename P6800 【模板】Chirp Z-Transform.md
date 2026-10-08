# P6800 【模板】Chirp Z-Transform

## 题目描述

给定一个 $n$ 项多项式 $P(x)$ 以及 $c, m$，请计算 $P(c^0),P(c^1),\dots,P(c^{m-1})$。所有答案都对 $998244353$ 取模。

## 输入格式

第一行三个正整数 $n,c,m$。  
第二行 $n$ 个非负整数 $a_0,a_1,\dots,a_{n-1}$，由低到高表示 $P(x)$ 的系数。

## 输出格式

一行 $m$ 个正整数，第 $i$ 个数表示 $P(c^{i-1})$。

## 输入输出样例 #1

### 输入 #1

```
3 3 3
3 3 3
```

### 输出 #1

```
9 39 273
```

## 说明/提示

对于 $100\%$ 的数据，$1\le n,m\le 10^6,0\le c,a_i<998244353$.

---

# P6800 [Template] Chirp Z-Transform

## 题目描述

Given an $n$-term polynomial $P(x)$ and $c, m$, compute $P(c^0), P(c^1), \dots, P(c^{m-1})$. All answers are taken modulo $998244353$.

## 输入格式

The first line contains three positive integers $n, c, m$.  
The second line contains $n$ non-negative integers $a_0, a_1, \dots, a_{n-1}$, representing the coefficients of $P(x)$ from low degree to high degree.

## 输出格式

Output one line with $m$ positive integers. The $i$-th number represents $P(c^{i-1})$.

## 输入输出样例 #1

### 输入 #1

```
3 3 3
3 3 3
```

### 输出 #1

```
9 39 273
```

## 说明/提示

For $100\%$ of the testdata, $1 \le n, m \le 10^6$, $0 \le c, a_i < 998244353$.

Translated by ChatGPT 5