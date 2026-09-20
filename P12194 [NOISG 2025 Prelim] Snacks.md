# P12194 [NOISG 2025 Prelim] Snacks

## 题目描述

Shor 小鸭已经准备了 $n$ 个小吃盘子，准备一边看电影一边享用！第 $i$ 个盘子最初装有一个美味值为 $a[i]$ 的小吃。

你需要处理 $q$ 个查询。在第 $j$ 个查询中，Shor 将按顺序执行以下两个操作：

1. 吃掉所有美味值在 $l[j]$ 到 $r[j]$（包含）之间的小吃。
2. 然后，将每一个被吃掉的小吃替换为一个美味值为 $x[j]$ 的新小吃。

在处理任何查询之前，以及每次处理完查询之后，Shor 都希望你确定所有盘子中小吃的美味值总和。

形式化地说，给定一个长度为 $n$ 的数组 $a$，你必须处理 $q$ 个查询。在处理所有查询之前，打印 $a$ 中所有元素的总和。在第 $j$ 个查询中，将所有满足 $l[j] \leq a[i] \leq r[j]$ 的元素 $a[i]$ 更新为 $x[j]$，然后打印更新后的 $a$ 中所有元素的总和。

## 输入格式

你的程序必须从标准输入读取数据。

输入的第一行包含两个用空格分隔的整数 $n$ 和 $q$。

第二行包含 $n$ 个用空格分隔的整数 $a[1], a[2], \ldots, a[n]$。

接下来的 $q$ 行输入中，每一行包含三个用空格分隔的整数。第 $j$ 行包含 $l[j], r[j]$ 和 $x[j]$，描述了第 $j$ 个查询。

## 输出格式

你的程序必须将结果打印到标准输出。

输出应包含 $q + 1$ 行。

输出的第一行应包含一个整数，表示在所有查询之前 $a$ 中所有元素的总和。

接下来的 $q$ 行中，第 $i$ 行应包含一个整数，表示第 $i$ 个查询后 $a$ 中所有元素的总和。

## 输入输出样例 #1

### 输入 #1

```
5 3
1 6 2 4 6
6 6 3
2 2 3
3 3 5
```

### 输出 #1

```
19
13
14
20
```

## 输入输出样例 #2

### 输入 #2

```
6 4
929 121 5 3 919 72
1 133 0
70 79 0
900 999 0
1 1000 0
```

### 输出 #2

```
2049
1848
1848
0
0
```

## 输入输出样例 #3

### 输入 #3

```
6 5
7 72 727 123 321 9
7 9 10
10 72 727
111 222 30
123 727 99
111 222 333
```

### 输出 #3

```
1259
1263
3352
3259
525
525
```

## 说明/提示

### 子任务

对于所有测试用例，输入将满足以下约束条件：

- $1 \leq n \leq 200\,000$
- $0 \leq q \leq 200\,000$
- $0 \leq a[i] \leq 10^9$ 对于所有 $1 \leq i \leq n$
- $0 \leq x[j] \leq 10^9$ 对于所有 $1 \leq j \leq q$
- $0 \leq l[j] \leq r[j] \leq 10^9$ 对于所有 $1 \leq j \leq q$

你的程序将在满足以下特殊性质的输入数据上进行测试：

| 子任务 | 分值 | 特殊性质 |
| :-: | :-: | :-: |
| $0$ | $0$ | 样例 |
| $1$ | $5$ | $q = 0$ |
| $2$ | $12$ | $n, q \leq 2000$ |
| $3$ | $21$ | $l[j] = r[j] \leq 200\,000$ 且 $a[i], x[j] \leq 200\,000$ |
| $4$ | $13$ | $l[j] = r[j]$ |
| $5$ | $16$ | $x[j] = 0$ |
| $6$ | $33$ | 无 |

### 样例 1 解释

此样例适用于子任务 $2, 3, 4, 6$。

### 样例 2 解释

此样例适用于子任务 $2, 5, 6$。

### 样例 3 解释

此样例适用于子任务 $2, 6$。

在所有查询之前，数组 $a$ 为 $[7, 72, 727, 123, 321, 9]$，总和为 $1259$。

第一次查询后，数组 $a$ 变为 $[10, 72, 727, 123, 321, 10]$，总和为 $1263$。

第二次查询后，数组 $a$ 变为 $[727, 727, 727, 123, 321, 727]$，总和为 $3352$。

第三次查询后，数组 $a$ 变为 $[727, 727, 727, 30, 321, 727]$，总和为 $3259$。

第四次查询后，数组 $a$ 变为 $[99, 99, 99, 30, 99, 99]$，总和为 $525$。

第五次查询后，数组 $a$ 变为 $[99, 99, 99, 30, 99, 99]$，总和为 $525$。

---

# P12194 [NOISG 2025 Prelim] Snacks

## 题目描述

Shor the Duck has prepared $n$ plates of snacks to enjoy while watching movies! The $i$-th plate initially contains a snack with a deliciousness value of $a[i]$.

You need to process $q$ queries. In the $j$-th query, Shor will do **both** of the following, in order:

1. Eat every snack whose deliciousness is between $l[j]$ and $r[j]$ (inclusive).
2. Then, replace each eaten snack with a new snack of deliciousness $x[j]$.

Before processing any queries, and after each query, Shor wants you to determine the sum of deliciousness of snacks across all plates.

Formally, you are given an array $a$ of length $n$ and must process $q$ queries. Before processing any queries, print the sum of all elements in $a$. In the $j$-th query, update every element $a[i]$ such that $l[j] \leq a[i] \leq r[j]$ by setting $a[i] = x[j]$, then print the updated sum of all elements in $a$.

## 输入格式

Your program must read from standard input.

The first line of input contains two space-separated integers $n$ and $q$.

The second line of input contains $n$ space-separated integers $a[1], a[2], \ldots, a[n]$.

The following $q$ lines of input each contain three space-separated integers. The $j$-th of these lines contains $l[j], r[j]$, and $x[j]$, describing the $j$-th query.

## 输出格式

Your program must print to standard output.

The output should contain $q + 1$ lines.

The first line of output should contain a single integer, the sum of all elements in a before all queries.

The following $q$ lines of input should each contain one integer. The $i$-th of these lines should contain the sum of elements in a after the $i$-th query.

## 输入输出样例 #1

### 输入 #1

```
5 3
1 6 2 4 6
6 6 3
2 2 3
3 3 5
```

### 输出 #1

```
19
13
14
20
```

## 输入输出样例 #2

### 输入 #2

```
6 4
929 121 5 3 919 72
1 133 0
70 79 0
900 999 0
1 1000 0
```

### 输出 #2

```
2049
1848
1848
0
0
```

## 输入输出样例 #3

### 输入 #3

```
6 5
7 72 727 123 321 9
7 9 10
10 72 727
111 222 30
123 727 99
111 222 333
```

### 输出 #3

```
1259
1263
3352
3259
525
525
```

## 说明/提示

### Subtasks

For all test cases, the input will satisfy the following bounds:

- $1 \leq n \leq 200\,000$
- $0 \leq q \leq 200\,000$
- $0 \leq a[i] \leq 10^9$ for all $1 \leq i \leq n$
- $0 \leq x[j] \leq 10^9$ for all $1 \leq j \leq q$
- $0 \leq l[j] \leq r[j] \leq 10^9$ for all $1 \leq j \leq q$

Your program will be tested on input instances that satisfy the following restrictions:

| Subtask | Marks | Additional Constraints |
| :-: | :-: | :-: |
| $0$ | $0$ | Sample test cases |
| $1$ | $5$ | $q = 0$ |
| $2$ | $12$ | $n, q \leq 2000$ |
| $3$ | $21$ | $l[j] = r[j] \leq 200\,000$ and $a[i], x[j] \leq 200\,000$ |
| $4$ | $13$ | $l[j] = r[j]$ |
| $5$ | $16$ | $x[j] = 0$ |
| $6$ | $33$ | No additional constraints |

### Sample Test Case 1 Explanation

This test case is valid for subtasks $2, 3, 4$, and $6$.

### Sample Test Case 2 Explanation

This test case is valid for subtasks $2, 5$, and $6$.

### Sample Test Case 3 Explanation

This test case is valid for subtasks $2$ and $6$.

Before all queries, the array a is $[7, 72, 727, 123, 321, 9]$, with a sum of $1259$.

After the first query, the array a becomes $[10, 72, 727, 123, 321, 10]$, with a sum of $1263$.

After the second query, the array a becomes $[727, 727, 727, 123, 321, 727]$, with a sum of $3352$.

After the third query, the array a becomes $[727, 727, 727, 30, 321, 727]$, with a sum of $3259$.

After the fourth query, the array a becomes $[99, 99, 99, 30, 99, 99]$, with a sum of $525$.

After the fifth query, the array a becomes $[99, 99, 99, 30, 99, 99]$, with a sum of $525$.