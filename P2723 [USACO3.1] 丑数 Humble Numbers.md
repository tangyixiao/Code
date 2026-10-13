# P2723 [USACO3.1] 丑数 Humble Numbers

## 题目描述

对于一给定的素数集合 $S = \{ p_1, p_2, ..., p_k \}$, 考虑一个正整数集合，该集合中任一元素的质因数全部属于 $S$。这个正整数集合包括，$p_1$、$p_1 \times p_2$、$p_1 \times p_1$、$p_1 \times p_2 \times p_3$ ...(还有其它)。该集合被称为 $S$ 集合的“丑数集合”。注意：我们认为 $1$不是一个丑数。

你的工作是对于输入的集合 $S$ 去寻找“丑数集合”中的第 $n$ 个“丑数”。保证答案可以用 32 位有符号整数表示。

补充：丑数集合中每个数从小到大排列，每个丑数都是素数集合中的数的乘积，第 $n$ 个“丑数”就是在能由素数集合中的数相乘得来的（包括它本身）第 $n$ 小的数。

## 输入格式

输入的第一行是两个的整数，分别代表集合 $S$ 的大小 $k$ 和给定的参数 $n$。

输入的第二行有 $k$ 互不相同的整数，第 $i$ 个整数代表 $p_i$。

## 输出格式

输出一行一个整数，代表答案。

## 输入输出样例 #1

### 输入 #1

```
4 19
2 3 5 7
```

### 输出 #1

```
27
```

## 说明/提示

#### 数据规模与约定

对于 $100\%$ 的数据，保证：

- $1 \leq k \leq 100$。
- $1 \leq n \leq 10^5$。
- $2 \leq p_i < 2^{31}$，且 $p_i$ 一定为质数。

---
#### 说明

题目翻译来自 NOCOW。

USACO Training Section 3.1

---

# P2723 [USACO3.1] Humble Numbers

## 题目描述

Given a set of primes $S = \{ p_1, p_2, ..., p_k \}$, consider the set of positive integers whose prime factors all belong to $S$. This set includes $p_1$, $p_1 \times p_2$, $p_1 \times p_1$, $p_1 \times p_2 \times p_3$ ... (and others). This set is called the "humble numbers set" of $S$. Note: We consider $1$ not to be a humble number.

Your task is, given the set $S$, to find the $n$-th humble number in the humble numbers set. It is guaranteed that the answer fits in a 32-bit signed integer.

Supplement: The humble numbers are ordered from small to large. Each humble number is a product of numbers from the prime set. The $n$-th humble number is the $n$-th smallest positive integer that can be formed by multiplying numbers from the prime set (including a prime itself).

## 输入格式

- The first line contains two integers, which are the size $k$ of the set $S$ and the given parameter $n$.
- The second line contains $k$ distinct integers, where the $i$-th integer denotes $p_i$.

## 输出格式

Output a single integer, the answer.

## 输入输出样例 #1

### 输入 #1

```
4 19
2 3 5 7
```

### 输出 #1

```
27
```

## 说明/提示

- Constraints

For $100\%$ of the testdata, it is guaranteed that:
- $1 \leq k \leq 100$.
- $1 \leq n \leq 10^5$.
- $2 \leq p_i < 2^{31}$, and each $p_i$ is prime.

- Notes

Problem translation from NOCOW.

USACO Training Section 3.1.

Translated by ChatGPT 5