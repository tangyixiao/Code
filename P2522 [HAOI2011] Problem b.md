# P2522 [HAOI2011] Problem b

## 题目描述

对于给出的 $n$ 个询问，每次求有多少个数对 $(x,y)$，满足 $a \le x \le b$，$c \le y \le d$，且 $\gcd(x,y) = k$，$\gcd(x,y)$ 函数为 $x$ 和 $y$ 的最大公约数。

## 输入格式

第一行一个整数 $n$，接下来 $n$ 行每行五个整数，分别表示 $a,b,c,d,k$。

## 输出格式

共 $n$ 行，每行一个整数表示满足要求的数对 $(x,y)$ 的个数。

## 输入输出样例 #1

### 输入 #1

```
2
2 5 1 5 1
1 5 1 5 2
```

### 输出 #1

```
14
3
```

## 说明/提示

对于 $100\%$ 的数据满足：$1 \le n,k \le 5 \times 10^4$，$1 \le a \le b \le 5 \times 10^4$，$1 \le c \le d \le 5 \times 10^4$。

---

# P2522 [HAOI2011] Problem b

## 题目描述

For each of the given $n$ queries, count the number of pairs $(x,y)$ such that $a \le x \le b$, $c \le y \le d$, and $\gcd(x,y) = k$. The function $\gcd(x,y)$ denotes the greatest common divisor of $x$ and $y$.

## 输入格式

The first line contains an integer $n$. Each of the next $n$ lines contains five integers, denoting $a, b, c, d, k$.

## 输出格式

Output $n$ lines, each containing one integer representing the number of pairs $(x,y)$ that satisfy the conditions.

## 输入输出样例 #1

### 输入 #1

```
2
2 5 1 5 1
1 5 1 5 2
```

### 输出 #1

```
14
3
```

## 说明/提示

Constraints: For $100\%$ of the testdata, the following holds: $1 \le n,k \le 5 \times 10^4$, $1 \le a \le b \le 5 \times 10^4$, $1 \le c \le d \le 5 \times 10^4$.

Translated by ChatGPT 5