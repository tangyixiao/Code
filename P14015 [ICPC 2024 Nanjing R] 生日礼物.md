# P14015 [ICPC 2024 Nanjing R] 生日礼物

## 题目描述

Grammy 的生日快要来了，她从她的朋友那里获得了一个序列 $A$ 作为礼物。序列由 $0$，$1$ 和 $2$ 构成。Grammy 觉得这个序列太长了，所以她打算把 $A$ 修改得短一些。

更正式地，Grammy 可以执行任意次操作。每次她可以执行以下三种操作之一：

- 将任意一个 $2$ 改为 $0$ 或 $1$。
- 选择两个相邻的 $0$，删除它们，并将剩下的部分连接起来。
- 选择两个相邻的 $1$，删除它们，并将剩下的部分连接起来。

求 Grammy 能得到的最短序列的长度。

## 输入格式

有多组测试数据。第一行输入一个整数 $T$ 表示测试数据组数。对于每组测试数据：

第一行输入一个长度为 $n$ 的字符串（$1\leq n\leq 2 \times 10^5$）。字符串由数字 $0$，$1$ 和 $2$ 构成，表示初始序列 $A$。

保证所有数据 $n$ 之和不超过 $5 \times 10^5$。

## 输出格式

每组数据输出一行一个整数，表示 Grammy 能得到的最短序列的长度。

## 输入输出样例 #1

### 输入 #1

```
5
0110101
01020102
0000021111
1012121010
0100202010
```

### 输出 #1

```
3
4
0
6
0
```

---

# P14015 [ICPC 2024 Nanjing R] Birthday Gift

## 题目描述

Grammy's birthday is approaching, and she gets a sequence $A$ from her friends as a gift. The sequence consists of only $0$, $1$, and $2$. Grammy thinks that the sequence is too long, so she decides to modify $A$ to make it shorter.

Formally, Grammy can perform an arbitrary number of operations. Each time she can choose one of the following three operations to perform:
- Change any $2$ into $0$ or $1$.
- Choose two adjacent $0$s, erase them, and concatenate the rest of the parts.
- Choose two adjacent $1$s, erase them, and concatenate the rest of the parts.

Calculate the minimum sequence length Grammy can get.

## 输入格式

There are multiple test cases. The first line of the input contains an integer $T$ indicating the number of test cases. For each test case:

The first and only line contains a string of length $n$ ($1\leq n\leq 2 \times 10^5$) consisting of digits $0$, $1$, and $2$, indicating the initial sequence $A$.

It is guaranteed that the sum of $n$ of all test cases will not exceed $5 \times 10^5$.

## 输出格式

For each test case, output one line containing one integer indicating the minimum sequence length Grammy can get.

## 输入输出样例 #1

### 输入 #1

```
5
0110101
01020102
0000021111
1012121010
0100202010
```

### 输出 #1

```
3
4
0
6
0
```