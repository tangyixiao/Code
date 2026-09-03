# CF1635B Avoid Local Maximums

## 题目描述

给定一个大小为 $n$ 的数组 $a$，数组中的每个元素都是 $1$ 到 $10^9$ 之间的整数。

你可以对该数组进行若干次操作。每次操作时，你可以将数组中的任意一个元素替换为 $1$ 到 $10^9$ 之间的任意整数。

请输出使得最终数组中不包含任何局部极大值所需的最少操作次数，以及操作后的数组。

如果某个元素 $a_i$ 严格大于它的两个相邻元素（即 $a_i > a_{i-1}$ 且 $a_i > a_{i+1}$），则称 $a_i$ 是一个局部极大值。由于 $a_1$ 和 $a_n$ 只有一个相邻元素，因此它们永远不会是局部极大值。

## 输入格式

每个测试包含多组测试用例。第一行包含一个整数 $t$ $(1 \leq t \leq 10000)$，表示测试用例的数量。接下来是 $t$ 组测试用例。

每组测试用例的第一行包含一个整数 $n$ $(2 \leq n \leq 2 \cdot 10^5)$，表示数组 $a$ 的大小。

第二行包含 $n$ 个整数 $a_1, a_2, \ldots, a_n$ $(1 \leq a_i \leq 10^9)$，表示数组的元素。

保证所有测试用例中 $n$ 的总和不超过 $2 \cdot 10^5$。

## 输出格式

对于每个测试用例，首先输出一行一个整数 $m$，表示所需的最少操作次数。然后输出一行 $n$ 个整数，表示操作后的数组。注意，该数组与初始数组恰好有 $m$ 个元素不同。

如果有多种答案，输出任意一种均可。

## 输入输出样例 #1

### 输入 #1

```
5
3
2 1 2
4
1 2 3 1
5
1 2 1 2 1
9
1 2 1 3 2 3 1 2 1
9
2 1 3 1 3 1 3 1 3
```

### 输出 #1

```
0
2 1 2
1
1 3 3 1
1
1 2 2 2 1
2
1 2 3 3 2 3 3 2 1
2
2 1 3 3 3 1 1 1 3
```

## 说明/提示

在第一个样例中，数组中没有局部极大值，因此不需要进行任何操作。

在第二个样例中，可以将 $a_2$ 改为 $3$，此时数组中没有局部极大值。

由 ChatGPT 4.1 翻译

---

# CF1635B Avoid Local Maximums

## 题目描述

You are given an array $ a $ of size $ n $ . Each element in this array is an integer between $ 1 $ and $ 10^9 $ .

You can perform several operations to this array. During an operation, you can replace an element in the array with any integer between $ 1 $ and $ 10^9 $ .

Output the minimum number of operations needed such that the resulting array doesn't contain any local maximums, and the resulting array after the operations.

An element $ a_i $ is a local maximum if it is strictly larger than both of its neighbors (that is, $ a_i > a_{i - 1} $ and $ a_i > a_{i + 1} $ ). Since $ a_1 $ and $ a_n $ have only one neighbor each, they will never be a local maximum.

## 输入格式

Each test contains multiple test cases. The first line will contain a single integer $ t $ $ (1 \leq t \leq 10000) $ — the number of test cases. Then $ t $ test cases follow.

The first line of each test case contains a single integer $ n $ $ (2 \leq n \leq 2 \cdot 10^5) $ — the size of the array $ a $ .

The second line of each test case contains $ n $ integers $ a_1, a_2, \ldots ,a_n $ $ (1 \leq a_i \leq 10^9) $ , the elements of array.

It is guaranteed that the sum of $ n $ over all test cases does not exceed $ 2 \cdot 10^5 $ .

## 输出格式

For each test case, first output a line containing a single integer $ m $ — minimum number of operations required. Then ouput a line consist of $ n $ integers — the resulting array after the operations. Note that this array should differ in exactly $ m $ elements from the initial array.

If there are multiple answers, print any.

## 输入输出样例 #1

### 输入 #1

```
5
3
2 1 2
4
1 2 3 1
5
1 2 1 2 1
9
1 2 1 3 2 3 1 2 1
9
2 1 3 1 3 1 3 1 3
```

### 输出 #1

```
0
2 1 2
1
1 3 3 1
1
1 2 2 2 1
2
1 2 3 3 2 3 3 2 1
2
2 1 3 3 3 1 1 1 3
```

## 说明/提示

In the first example, the array contains no local maximum, so we don't need to perform operations.

In the second example, we can change $ a_2 $ to $ 3 $ , then the array don't have local maximums.
