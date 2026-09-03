# CF1635C Differential Sorting

## 题目描述

给定一个长度为 $n$ 的数组 $a$。

你最多可以进行 $n$ 次如下操作：选择三个下标 $x, y, z$，满足 $1 \leq x < y < z \leq n$，并将 $a_x$ 替换为 $a_y - a_z$。操作后，要求 $|a_x| < 10^{18}$。

你的目标是使最终得到的数组非递减。如果有多种方案，可以输出任意一种。如果无法实现，也需要输出。

## 输入格式

每组测试数据包含多组测试用例。第一行包含一个整数 $t$ $(1 \leq t \leq 10000)$，表示测试用例的数量。

每个测试用例的第一行包含一个整数 $n$ $(3 \leq n \leq 2 \cdot 10^5)$，表示数组 $a$ 的长度。

第二行包含 $n$ 个整数 $a_1, a_2, \ldots, a_n$ $(-10^9 \leq a_i \leq 10^9)$，表示数组 $a$ 的元素。

保证所有测试用例中 $n$ 的总和不超过 $2 \cdot 10^5$。

## 输出格式

对于每个测试用例，如果无解，输出一行 $-1$。否则，第一行输出一个整数 $m$ $(0 \leq m \leq n)$，表示你进行了多少次操作。

接下来的 $m$ 行，每行输出三个整数 $x, y, z$ $(1 \leq x < y < z \leq n)$，表示每次操作的下标。

如果有多种方案，可以输出任意一种。注意本题不要求操作次数最少。

## 输入输出样例 #1

### 输入 #1

```
3
5
5 -4 2 -1 2
3
4 3 2
3
-3 -2 -1
```

### 输出 #1

```
2
1 2 3
3 4 5
-1
0
```

## 说明/提示

在第一个样例中，第一次操作后数组变为

$[-6, -4, 2, -1, 2]$，

第二次操作后数组变为

$[-6, -4, -3, -1, 2]$。

在第二个样例中，无论进行怎样的操作，都无法使数组有序。

在第三个样例中，数组本身已经有序，因此无需进行任何操作。

由 ChatGPT 4.1 翻译

---

# CF1635C Differential Sorting

## 题目描述

You are given an array $ a $ of $ n $ elements.

Your can perform the following operation no more than $ n $ times: Select three indices $ x,y,z $ $ (1 \leq x < y < z \leq n) $ and replace $ a_x $ with $ a_y - a_z $ . After the operation, $ |a_x| $ need to be less than $ 10^{18} $ .

Your goal is to make the resulting array non-decreasing. If there are multiple solutions, you can output any. If it is impossible to achieve, you should report it as well.

## 输入格式

Each test contains multiple test cases. The first line will contain a single integer $ t $ $ (1 \leq t \leq 10000) $ — the number of test cases. Then $ t $ test cases follow.

The first line of each test case contains a single integer $ n $ $ (3 \leq n \leq 2 \cdot 10^5) $ — the size of the array $ a $ .

The second line of each test case contains $ n $ integers $ a_1, a_2, \ldots ,a_n $ $ (-10^9 \leq a_i \leq 10^9) $ , the elements of $ a $ .

It is guaranteed that the sum of $ n $ over all test cases does not exceed $ 2 \cdot 10^5 $ .

## 输出格式

For each test case, print $ -1 $ in a single line if there is no solution. Otherwise in the first line you should print a single integer $ m $ $ (0 \leq m \leq n) $ — number of operations you performed.

Then the $ i $ -th of the following $ m $ lines should contain three integers $ x,y,z $ $ (1 \leq x < y < z \leq n) $ — description of the $ i $ -th operation.

If there are multiple solutions, you can output any. Note that you don't have to minimize the number of operations in this task.

## 输入输出样例 #1

### 输入 #1

```
3
5
5 -4 2 -1 2
3
4 3 2
3
-3 -2 -1
```

### 输出 #1

```
2
1 2 3
3 4 5
-1
0
```

## 说明/提示

In the first example, the array becomes

 $ [-6,-4,2,-1,2] $ after the first operation,

 $ [-6,-4,-3,-1,2] $ after the second operation.

In the second example, it is impossible to make the array sorted after any sequence of operations.

In the third example, the array is already sorted, so we don't need to perform any operations.