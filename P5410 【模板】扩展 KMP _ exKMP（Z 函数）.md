# P5410 【模板】扩展 KMP / exKMP（Z 函数）

## 题目描述

给定两个字符串 $a,b$，你要求出两个数组：

- $b$ 的 $z$ 函数数组 $z$，即 $b$ 与 $b$ 的每一个后缀的 LCP 长度。
- $b$ 与 $a$ 的每一个后缀的 LCP 长度数组 $p$。

对于一个长度为 $n$ 的数组 $a$，设其权值为 $\operatorname{xor}_{i=1}^n i \times (a_i + 1)$。

## 输入格式

两行两个字符串 $a,b$。

## 输出格式

第一行一个整数，表示 $z$ 的权值。

第二行一个整数，表示 $p$ 的权值。

## 输入输出样例 #1

### 输入 #1

```
aaaabaa
aaaaa
```

### 输出 #1

```
6
21
```

## 说明/提示

**样例解释：**

$z = \{5\ 4\ 3\ 2\ 1\}$，$p = \{4\ 3\ 2\ 1\ 0\ 2\ 1\}$。

---

**数据范围：**

对于第一个测试点，$|a|,|b| \le 2 \times 10^3$。

对于第二个测试点，$|a|,|b| \le 2 \times 10^5$。

对于 $100\%$ 的数据，$1 \le |a|,|b| \le 2 \times 10^7$，所有字符均为小写字母。

---

# P5410 [Template] Extended KMP / exKMP (Z Function).

## 题目描述

Given two strings $a, b$, you need to find two arrays:

- The $z$ function array $z$ of $b$, that is, the LCP length between $b$ and each suffix of $b$.
- The LCP length array $p$ between $b$ and each suffix of $a$.

For an array $a$ of length $n$, define its weight as $\operatorname{xor}_{i=1}^n i \times (a_i + 1)$.

## 输入格式

Two lines, containing two strings $a, b$.

## 输出格式

The first line contains one integer, the weight of $z$.

The second line contains one integer, the weight of $p$.

## 输入输出样例 #1

### 输入 #1

```
aaaabaa
aaaaa
```

### 输出 #1

```
6
21
```

## 说明/提示

**Sample explanation:**

$z = \{5\ 4\ 3\ 2\ 1\}$, $p = \{4\ 3\ 2\ 1\ 0\ 2\ 1\}$.

---

**Constraints:**

For the first test point, $|a|, |b| \le 2 \times 10^3$.

For the second test point, $|a|, |b| \le 2 \times 10^5$.

For $100\%$ of the data, $1 \le |a|, |b| \le 2 \times 10^7$, and all characters are lowercase letters.

Translated by ChatGPT 5