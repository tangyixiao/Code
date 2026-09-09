# CF1631C And Matching

## 题目描述

给定一个包含 $n$ 个元素的集合（$n$ 总是 $2$ 的幂），该集合恰好包含所有整数 $0, 1, 2, \ldots, n-1$。

请将这些元素分成 $\frac{n}{2}$ 对，使得：

- 集合中的每个元素恰好属于一对。
- 所有对中元素按位与的和恰好等于 $k$。形式化地说，若第 $i$ 对为 $a_i$ 和 $b_i$，则需满足：$$\sum_{i=1}^{n/2}{a_i \& b_i} = k$$，其中 $\,\&\,$ 表示按位与运算。

如果有多种方案，输出任意一种。如果无解，则输出 $-1$。

## 输入格式

输入包含多组测试数据。第一行包含一个整数 $t$（$1 \leq t \leq 400$），表示测试数据组数。接下来每组测试数据一行，包含两个整数 $n$ 和 $k$（$4 \leq n \leq 2^{16}$，$n$ 是 $2$ 的幂，$0 \leq k \leq n-1$）。

所有测试数据中 $n$ 的总和不超过 $2^{16}$。每组测试数据均不相同。

## 输出格式

对于每组测试数据，如果无解，输出一行 $-1$。

否则，输出 $\frac{n}{2}$ 行，每行两个整数 $a_i$ 和 $b_i$，表示一对元素。

如果有多种方案，输出任意一种。对的顺序和对内元素顺序均不限。

## 输入输出样例 #1

### 输入 #1

```
4
4 0
4 1
4 2
4 3
```

### 输出 #1

```
0 3
1 2
0 2
1 3
0 1
2 3
-1
```

## 说明/提示

在第一个测试样例中，$(0\&3)+(1\&2)=0$。

在第二个测试样例中，$(0\&2)+(1\&3)=1$。

在第三个测试样例中，$(0\&1)+(2\&3)=2$。

在第四个测试样例中，无解。

由 ChatGPT 4.1 翻译

---

# CF1630A And Matching

## 题目描述

You are given a set of $ n $ ( $ n $ is always a power of $ 2 $ ) elements containing all integers $ 0, 1, 2, \ldots, n-1 $ exactly once.

Find $ \frac{n}{2} $ pairs of elements such that:

- Each element in the set is in exactly one pair.
- The sum over all pairs of the [bitwise AND](https://en.wikipedia.org/wiki/Bitwise_operation#AND) of its elements must be exactly equal to $ k $ . Formally, if $ a_i $ and $ b_i $ are the elements of the $ i $ -th pair, then the following must hold: $ $$$\sum_{i=1}^{n/2}{a_i \& b_i} = k, $ $  where  $ \\&amp; $  denotes the bitwise AND operation. </li></ul><p>If there are many solutions, print any of them, if there is no solution, print  $ -1$$$ instead.

## 输入格式

The input consists of multiple test cases. The first line contains a single integer $ t $ ( $ 1 \leq t \leq 400 $ ) — the number of test cases. Description of the test cases follows.

Each test case consists of a single line with two integers $ n $ and $ k $ ( $ 4 \leq n \leq 2^{16} $ , $ n $ is a power of $ 2 $ , $ 0 \leq k \leq n-1 $ ).

The sum of $ n $ over all test cases does not exceed $ 2^{16} $ . All test cases in each individual input will be pairwise different.

## 输出格式

For each test case, if there is no solution, print a single line with the integer $ -1 $ .

Otherwise, print $ \frac{n}{2} $ lines, the $ i $ -th of them must contain $ a_i $ and $ b_i $ , the elements in the $ i $ -th pair.

If there are many solutions, print any of them. Print the pairs and the elements in the pairs in any order.

## 输入输出样例 #1

### 输入 #1

```
4
4 0
4 1
4 2
4 3
```

### 输出 #1

```
0 3
1 2
0 2
1 3
0 1
2 3
-1
```

## 说明/提示

In the first test, $ (0\&3)+(1\&2) = 0 $ .

In the second test, $ (0\&2)+(1\&3) = 1 $ .

In the third test, $ (0\&1)+(2\&3) = 2 $ .

In the fourth test, there is no solution.