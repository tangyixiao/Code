# P13781 [eJOI 2022] Adjacent Pairs

## 题目描述

我们称一个数组 $b_1, b_2, \ldots, b_m$ 是**良好**的，如果对任意 $1 \leq i \leq m - 1$，都有 $b_i \neq b_{i+1}$。

现在给定一个长度为 $n$ 的**良好**数组 $a_1, a_2, a_3, \ldots, a_n$，其中所有元素均为正整数。

你可以对该数组执行如下操作：

- 选择任意一个下标 $i$（$1 \leq i \leq n$）以及一个数 $x$（$1 \leq x \leq 10^9$），然后将 $a_i$ 赋值为 $x$。执行该操作后，数组仍需保持**良好**。

你的目标是经过若干次操作后，使得最终的数组中恰好只包含两种不同的数值。请计算所需的最少操作次数。

## 输入格式

输入的第一行包含一个整数 $t$（$1 \leq t \leq 10^5$），表示测试用例的个数。接下来依次给出 $t$ 个测试用例。

每个测试用例的第一行包含一个整数 $n$（$2 \leq n \leq 2 \cdot 10^5$），表示数组的长度。

第二行包含 $n$ 个整数 $a_1, a_2, \ldots, a_n$（$1 \leq a_i \leq n$），即数组的元素。保证对所有 $1 \leq i \leq n - 1$，有 $a_i \neq a_{i+1}$，即该数组是**良好**的。

保证所有测试用例中 $n$ 的总和不超过 $2 \cdot 10^5$。

## 输出格式

对于每个测试用例，输出一个整数，表示将数组变为只包含恰好两种不同数值所需的最少操作次数。

## 输入输出样例 #1

### 输入 #1

```
2
5
4 5 2 4 5
2
1 2
```

### 输出 #1

```
3
0
```

## 说明/提示

### 样例说明

在第一个测试用例中，一种最优的操作序列为：

$(4, 5, 2, 4, 5) \rightarrow (2, 5, 2, 4, 5) \rightarrow (2, 5, 2, 4, 2) \rightarrow (2, 5, 2, 5, 2)$。

在第二个测试用例中，数组中已经只包含两种不同的数，因此答案是 $0$。

### 评分标准

1. （20 分）：所有测试用例中 $n$ 的总和不超过 $100$
2. （10 分）：所有测试用例中 $n$ 的总和不超过 $500$
3. （25 分）：所有测试用例中 $n$ 的总和不超过 $4000$
4. （45 分）：无额外限制

---

翻译由 ChatGPT-5 完成


---

# P13781 [eJOI 2022] Adjacent Pairs

## 题目描述

Let's call an array $b_1, b_2, \ldots, b_m$ **good**, if $b_i \neq b_{i+1}$ for any $i$ with $1 \leq i \leq m - 1$.

You are given a **good** array of $n$ positive integers $a_1, a_2, a_3, \ldots, a_n$.

You can perform the following operations on this array:

- Choose any index $i$ ($1 \leq i \leq n$) and a number $x$ ($1 \leq x \leq 10^9$). Then, set $a_i$ to $x$. After this operation, the array has to remain **good**.

You want to perform several operations so that the resulting array will contain exactly two distinct values. Determine the smallest number of operations needed to achieve this goal.

## 输入格式

The first line of input contains the integer $t$ ($1 \leq t \leq 10^5$), the number of test cases. The description of test cases follows.

The first line of each test case contains a single integer $n$ ($2 \leq n \leq 2 \cdot 10^5$) - the length of the array.

The second line of each test case contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \leq a_i \leq n$) - elements of the array. It's guaranteed that $a_i \neq a_{i+1}$ for $1 \leq i \leq n - 1$ (that is, the array is **good**).

It is guaranteed that the sum of $n$ over all test cases does not exceed $2 \cdot 10^5$.

## 输出格式

For each test case, output a single integer - the smallest number of operations needed to achieve an array in which there are exactly two distinct values.

## 输入输出样例 #1

### 输入 #1

```
2
5
4 5 2 4 5
2
1 2
```

### 输出 #1

```
3
0
```

## 说明/提示

### Note

In the first test case, one of the optimal sequences of operations is:

$(4, 5, 2, 4, 5) \rightarrow (2, 5, 2, 4, 5) \rightarrow (2, 5, 2, 4, 2) \rightarrow (2, 5, 2, 5, 2)$.

In the second test case, the array already contains only two distinct values, so the answer is $0$.

### Scoring

1. (20 points): The sum of $n$ over all test cases does not exceed $100$
2. (10 points): The sum of $n$ over all test cases does not exceed $500$
3. (25 points): The sum of $n$ over all test cases does not exceed $4000$
4. (45 points): No additional constraints