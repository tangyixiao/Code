# P1829 [集训队互测 2010] Crash的数字表格 / JZPTAB

## 题目描述

今天的数学课上，Crash 小朋友学习了最小公倍数（Least Common Multiple）。对于两个正整数 $a$ 和 $b$，$\text{lcm}(a,b)$ 表示能同时被 $a$ 和 $b$ 整除的最小正整数。例如，$\text{lcm}(6, 8) = 24$。

回到家后，Crash 还在想着课上学的东西，为了研究最小公倍数，他画了一张 $ n \times m$ 的表格。每个格子里写了一个数字，其中第 $i$ 行第 $j$ 列的那个格子里写着数为 $\text{lcm}(i, j)$。

看着这个表格，Crash 想到了很多可以思考的问题。不过他最想解决的问题却是一个十分简单的问题：这个表格中所有数的和是多少。当 $n$ 和 $m$ 很大时，Crash 就束手无策了，因此他找到了聪明的你用程序帮他解决这个问题。由于最终结果可能会很大，Crash 只想知道表格里所有数的和对 $20101009$ 取模后的值。

## 输入格式

输入包含一行两个整数，分别表示 $n$ 和 $m$。

## 输出格式

输出一个正整数，表示表格中所有数的和对 $20101009$ 取模后的值。

## 输入输出样例 #1

### 输入 #1

```
4 5
```

### 输出 #1

```
122
```

## 说明/提示

#### 样例输入输出 1 解释

该表格为：

|$1$|$2$|$3$|$4$|$5$|
|:-:|:-:|:-:|:-:|:-:|
|$2$|$2$|$6$|$4$|$10$|
|$3$|$6$|$3$|$12$|$15$|
|$4$|$4$|$12$|$4$|$20$|

#### 数据规模与约定

- 对于 $30\%$ 的数据，保证 $n, m \le 10^3$。
- 对于 $70\%$ 的数据，保证 $n, m \le 10^5$。
- 对于 $100\%$ 的数据，保证 $1\le n,m \le 10^7$。

---


# P1829 [CTT] Crash's Number Table / JZPTAB

## 题目描述

In today's math class, Crash learned about the Least Common Multiple. For two positive integers $a$ and $b$, $\text{lcm}(a, b)$ denotes the smallest positive integer divisible by both $a$ and $b$. For example, $\text{lcm}(6, 8) = 24$.

After returning home, Crash was still thinking about what he learned. To study the Least Common Multiple, he drew an $n \times m$ table. Each cell contains a number, where the cell in the $i$-th row and $j$-th column contains $\text{lcm}(i, j)$.

Looking at this table, Crash thought of many questions. The one he most wants to solve is very simple: what is the sum of all the numbers in this table? When $n$ and $m$ are large, Crash cannot handle it, so he asks you to write a program to compute the answer. Since the result can be very large, Crash only wants the sum modulo $20101009$.

## 输入格式

The input contains one line with two integers $n$ and $m$.

## 输出格式

Output one positive integer, the sum of all numbers in the table modulo $20101009$.

## 输入输出样例 #1

### 输入 #1

```
4 5
```

### 输出 #1

```
122
```

## 说明/提示

Sample 1 Explanation:

The table is:

| $1$ | $2$ | $3$ | $4$ | $5$ |
|:-:|:-:|:-:|:-:|:-:|
| $2$ | $2$ | $6$ | $4$ | $10$ |
| $3$ | $6$ | $3$ | $12$ | $15$ |
| $4$ | $4$ | $12$ | $4$ | $20$ |

Constraints:
- For $30\%$ of the testdata, $n, m \le 10^3$.
- For $70\%$ of the testdata, $n, m \le 10^5$.
- For $100\%$ of the testdata, $1 \le n, m \le 10^7$.

Translated by ChatGPT 5