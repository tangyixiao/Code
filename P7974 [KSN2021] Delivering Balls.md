# P7974 [KSN2021] Delivering Balls

## 题目描述

给定一个长度为 $N$ 的序列 $H$ 和 $Q$ 次询问。

第 $i$ 次询问中，你初始在第 $S_i$ 列 $H_{S_i}$ 行，想要到第 $T_i$ 列第 $H_{T_i}$ 行。

你可以进行若干次移动。每次移动你可以选择以下两种参数：

* 列 $-1$，列不变，列 $+1$。
* 行 $-1$，行不变，行 $+1$。

如果你选择行 $-1$，消耗 $1$ 体力，如果你选择行不变，消耗 $2$ 体力，如果你选择行 $+1$，消耗 $4$ 体力。

你需要保证每次移动后，你的列数 $x$ 在 $[1,N]$ 之间，且你的行数 $y$ 不小于 $H_x$。

对于每个询问，你需要求出你消耗体力的最小值。

## 输入格式

第一行输入一个正整数 $N$。

第二行输入 $N$ 个正整数 $H_i$。

第三行输入一个正整数 $Q$。

接下来 $Q$ 行，每行输入两个正整数 $S_i,T_i$。

## 输出格式

对于每个询问，输出一行，包含一个整数，代表消耗体力的最小值。

## 输入输出样例 #1

### 输入 #1

```
4
9 1 8 2
2
1 3
4 2
```

### 输出 #1

```
3
31
```

## 输入输出样例 #2

### 输入 #2

```
9
1 2 3 2 1 2 3 2 1
4
1 9
4 6
2 6
5 2
```

### 输出 #2

```
18
4
9
9
```

## 说明/提示

**【样例解释】**

以下为第一个样例中两个询问的图示：


![](https://cdn.vjudge.net.cn/5b94c3b10f33f3cee49fc184a4504596)
![](https://cdn.vjudge.net.cn/acf17c861d64450f7566cdb59ea9f57b)

**【数据范围】**

- Subtask 1（7 points）：只存在一组数据，满足 $N=8$，$Q=4$，$H=[,9,3,3,5,4,8,2]$，$(S_i,T_i)$ 依次为 $(1,8)$，$(3,6)$，$(6,4)$ 和 $(7,2)$。
- Subtask 2（5 points）：$S_i+1=T_i$。
- Subtask 3（6 points）：$H_i=i$。
- Subtask 4（18 points）：$N,Q,H_i\leq 100$。
- Subtask 5（24 points）：$N,Q\leq 1000$。
- Subtask 6（13 points）：$S_i=1$。
- Subtask 7（27 points）：无特殊限制。

对于所有数据，$2\leq N\leq 2\times 10^5$，$H_i\leq 10^9$，$Q\leq 2\times 10^5$，$1\leq S_i,T_i\leq N$。


---

# P7974 [KSN2021] Delivering Balls

## 题目描述

You are given a sequence $H$ of length $N$ and $Q$ queries.

In the $i$-th query, you start at column $S_i$ and row $H_{S_i}$, and you want to reach column $T_i$ and row $H_{T_i}$.

You may make several moves. In each move, you can choose the following two parameters:

* Column $-1$, column unchanged, column $+1$.
* Row $-1$, row unchanged, row $+1$.

If you choose row $-1$, it costs $1$ stamina. If you choose row unchanged, it costs $2$ stamina. If you choose row $+1$, it costs $4$ stamina.

You must ensure that after each move, your column index $x$ is within $[1,N]$, and your row index $y$ is not less than $H_x$.

For each query, find the minimum stamina cost.

## 输入格式

The first line contains a positive integer $N$.

The second line contains $N$ positive integers $H_i$.

The third line contains a positive integer $Q$.

The next $Q$ lines each contain two positive integers $S_i, T_i$.

## 输出格式

For each query, output one line containing an integer, the minimum stamina cost.

## 输入输出样例 #1

### 输入 #1

```
4
9 1 8 2
2
1 3
4 2
```

### 输出 #1

```
3
31
```

## 输入输出样例 #2

### 输入 #2

```
9
1 2 3 2 1 2 3 2 1
4
1 9
4 6
2 6
5 2
```

### 输出 #2

```
18
4
9
9
```

## 说明/提示

**Sample Explanation**

The following figures illustrate the two queries in the first sample:

![](https://cdn.vjudge.net.cn/5b94c3b10f33f3cee49fc184a4504596)
![](https://cdn.vjudge.net.cn/acf17c861d64450f7566cdb59ea9f57b)

**Constraints**

- Subtask 1 (7 points): There is only one set of testdata, where $N=8$, $Q=4$, $H=[,9,3,3,5,4,8,2]$, and $(S_i,T_i)$ are $(1,8)$, $(3,6)$, $(6,4)$, and $(7,2)$ in order.
- Subtask 2 (5 points): $S_i+1=T_i$.
- Subtask 3 (6 points): $H_i=i$.
- Subtask 4 (18 points): $N,Q,H_i\leq 100$.
- Subtask 5 (24 points): $N,Q\leq 1000$.
- Subtask 6 (13 points): $S_i=1$.
- Subtask 7 (27 points): No special restrictions.

For all testdata, $2\leq N\leq 2\times 10^5$, $H_i\leq 10^9$, $Q\leq 2\times 10^5$, and $1\leq S_i,T_i\leq N$.

Translated by ChatGPT 5