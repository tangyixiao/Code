# P14444 [ICPC 2025 Xi'an Practice] Great Indices

## 题目描述

给定一个序列 $a_1, a_2, \cdots, a_n$。对于每一个满足 $1 \leq i \leq n$ 的下标 $i$，当且仅当以下条件成立时，我们称下标 $i$ 是 **好** 的：

- 至多存在一个下标 $1 \leq j \leq n$，使得 $a_j$ 不是 $a_i$ 的约数。

你的任务是找出序列中所有 **好** 的下标。

回忆一下，当且仅当存在一个整数 $k$ 使得 $n = d \times k$ 时，整数 $d$ 是整数 $n$ 的约数。

## 输入格式

输入包含多个测试用例。第一行包含一个整数 $t$（$1 \leq t \leq 10^5$），表示测试用例的数量。对于每个测试用例：

- 第一行包含一个整数 $n$（$1 \leq n \leq 3 \times 10^5$），表示序列 $a$ 的长度。
- 第二行包含 $n$ 个整数 $a_1, a_2, \cdots, a_n$（$1 \leq a_i \leq 10^9$），表示给定的序列。

保证所有测试用例中 $n$ 的总和不超过 $3 \times 10^5$。

## 输出格式

对于每个测试用例，输出两行：

- 第一行输出一个整数 $m$，表示 **好** 的下标的数量。
- 第二行输出 $m$ 个整数 $p_1, p_2, \cdots, p_m$（满足 $p_1 < p_2 < \cdots < p_m$），表示按 **升序** 排列的 **好** 的下标。

## 输入输出样例 #1

### 输入 #1

```
3
4
1 2 3 6
6
1 1 4 5 1 4
5
1 9 1 9 810
```

### 输出 #1

```
1
4 
2
3 6 
3
2 4 5 
```

## 说明/提示

在第一个测试用例中：

- 当 $i = 1$ 时，使得 $a_j$ 不是 $a_i$ 的约数的下标 $j$ 为 $2$、$3$ 和 $4$。由于此类下标数量为 $3 > 1$，因此下标 $1$ 不是 **好** 的下标。
- 当 $i = 2$ 时，存在两个下标 $j = 3$ 和 $j = 4$，使得 $a_j$ 不是 $a_i$ 的约数。
- 当 $i = 3$ 时，存在两个下标 $j = 2$ 和 $j = 4$，使得 $a_j$ 不是 $a_i$ 的约数。
- 当 $i = 4$ 时，所有的 $a_j$ 都是 $a_i$ 的约数，因此下标 $4$ 是 **好** 的。

因此，唯一的 **好** 的下标是 $i = 4$。

翻译由 ChatGPT-5 完成

---

# P14444 [ICPC 2025 Xi'an Practice] Great Indices

## 题目描述

You are given a sequence $a_1, a_2, \cdots, a_n$. For each $1 \leq i \leq n$, index $i$ is called $\textit{great}$ if and only if the following holds:

- There is at most one index $1 \leq j \leq n$ such that $a_j$ is not a divisor of $a_i$.

Your task is to find all $\textit{great}$ indices in the sequence.

Recall that an integer $d$ is a divisor of an integer $n$ if and only if there exists an integer $k$ such that $n = d \times k$.

## 输入格式

The input consists of multiple test cases. The first line contains an integer $t$ ($1 \leq t \leq 10^5$), the number of test cases. For each test case:

- The first line contains a single integer $n$ ($1 \leq n \leq 3 \times 10^5$), representing the length of sequence $a$.
- The second line contains $n$ integers $a_1, a_2, \cdots, a_n$ ($1 \leq a_i \leq 10^9$), representing the given sequence.

It is guaranteed that the sum of $n$ over all test cases does not exceed $3 \times 10^5$.

## 输出格式

For each test case, output two lines:

- The first line contains a single integer $m$, representing the number of $\textit{great}$ indices.
- The second line contains $m$ integers $p_1, p_2, \cdots, p_m$ ($p_1 < p_2 < \cdots < p_m$), representing the $\textit{great}$ indices $\textbf{in increasing order}$.

## 输入输出样例 #1

### 输入 #1

```
3
4
1 2 3 6
6
1 1 4 5 1 4
5
1 9 1 9 810
```

### 输出 #1

```
1
4 
2
3 6 
3
2 4 5 
```

## 说明/提示

In the first test case:

- When $i = 1$, the indices $j$ where $a_j$ is not a divisor of $a_i$ are $2$, $3$, and $4$. Since $3 > 1$, index $1$ is not a $\textit{great}$ index.
- When $i = 2$, there are two indices, $j = 3$ and $j = 4$, for which $a_j$ is not a divisor of $a_i$.
- When $i = 3$, there are two indices, $j = 2$ and $j = 4$, for which $a_j$ is not a divisor of $a_i$.
- When $i = 4$, each of $a_j$ is a divisor of $a_i$, so that index $4$ is a $\textit{great}$ index.

Therefore, the only $\textit{great}$ index is $i = 4$.