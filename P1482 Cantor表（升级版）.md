# P1482 Cantor表（升级版）

## 题目描述

现代数学的著名证明之一是 Georg Cantor 证明了有理数是可枚举的。他是用下面这一张表来证明这一命题的：

$$\begin{matrix}
1/1 & 1/2 & 1/3 & 1/4 & 1/5 & \cdots \cr
2/1 & 2/2 & 2/3 & 2/4 &  \cdots \cr
3/1 & 3/2 & 3/3 &  \cdots \cr
4/1 & 4/2 &  \cdots \cr
5/1 &  \cdots \cr
\end{matrix}
$$

这次与 NOIp1999 第一题不同的是：这次需输入两个分数（不一定是最简分数），算出这两个分数的积（注意需要约分至最简分数），输出积在原表的第几列第几行（若积形如 $a$（即结果为整数）或者 $1/a$，则看作表内的 $a/1$ 或 $1/a$ 结算）。

## 输入格式

共两行。每行输入一个分数（不一定是最简分数）。

## 输出格式

两个整数，表示输入的两个分数的积在表中的第几列第几行。

## 输入输出样例 #1

### 输入 #1

```
4/5
5/4
```

### 输出 #1

```
1 1
```

## 说明/提示

### 数据范围

对于全部数据，两个分数的分母和分子均小于 $10^4$。

---

# P1482 Cantor Table (Upgraded Version)

## 题目描述

One of the famous results in modern mathematics is Georg Cantor’s proof that the rational numbers are countable. He used the following table to demonstrate this fact:

$$\begin{matrix}
1/1 & 1/2 & 1/3 & 1/4 & 1/5 & \cdots \cr
2/1 & 2/2 & 2/3 & 2/4 &  \cdots \cr
3/1 & 3/2 & 3/3 &  \cdots \cr
4/1 & 4/2 &  \cdots \cr
5/1 &  \cdots \cr
\end{matrix}
$$

This time, unlike NOIp 1999 Problem 1, you need to input two fractions (not necessarily in lowest terms), compute their product (make sure to reduce it to lowest terms), and output which column and which row the product falls into in the original table (if the product is of the form $a$ (i.e., an integer) or $1/a$, treat it as $a/1$ or $1/a$ in the table).

## 输入格式

Two lines. Each line contains a fraction (not necessarily in lowest terms).

## 输出格式

Two integers, indicating in which column and which row the product of the two input fractions appears in the table.

## 输入输出样例 #1

### 输入 #1

```
4/5
5/4
```

### 输出 #1

```
1 1
```

## 说明/提示

### Constraints

For all testdata, the numerators and denominators of the two fractions are less than $10^4$.

Translated by ChatGPT 5