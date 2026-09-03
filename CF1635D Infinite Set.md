# CF1635D Infinite Set

## 题目描述

给定一个由 $n$ 个互不相同的正整数组成的数组 $a$。

我们定义一个无限整数集合 $S$，其中包含所有满足以下至少一个条件的整数 $x$：

1. 存在 $1 \leq i \leq n$，使得 $x = a_i$。
2. 存在 $y \in S$，使得 $x = 2y + 1$。
3. 存在 $y \in S$，使得 $x = 4y$。

例如，如果 $a = [1,2]$，那么 $S$ 中最小的 $10$ 个元素为 $\{1,2,3,4,5,7,8,9,11,12\}$。

请你计算 $S$ 中严格小于 $2^p$ 的元素个数。由于答案可能很大，请输出对 $10^9 + 7$ 取模后的结果。

## 输入格式

第一行包含两个整数 $n$ 和 $p$，$1 \leq n, p \leq 2 \cdot 10^5$。

第二行包含 $n$ 个整数 $a_1,a_2,\ldots,a_n$，$1 \leq a_i \leq 10^9$。

保证 $a$ 中所有数字互不相同。

## 输出格式

输出一个整数，表示 $S$ 中严格小于 $2^p$ 的元素个数。请记得对 $10^9 + 7$ 取模。

## 输入输出样例 #1

### 输入 #1

```
2 4
6 1
```

### 输出 #1

```
9
```

## 输入输出样例 #2

### 输入 #2

```
4 7
20 39 5 200
```

### 输出 #2

```
14
```

## 输入输出样例 #3

### 输入 #3

```
2 200000
48763 1000000000
```

### 输出 #3

```
448201910
```

## 说明/提示

在第一个样例中，严格小于 $2^4$ 的元素为 $\{1, 3, 4, 6, 7, 9, 12, 13, 15\}$。

在第二个样例中，严格小于 $2^7$ 的元素为 $\{5,11,20,23,39,41,44,47,79,80,83,89,92,95\}$。

由 ChatGPT 4.1 翻译

---


# CF1635D Infinite Set

## 题目描述

You are given an array $ a $ consisting of $ n $ distinct positive integers.

Let's consider an infinite integer set $ S $ which contains all integers $ x $ that satisfy at least one of the following conditions:

1. $ x = a_i $ for some $ 1 \leq i \leq n $ .
2. $ x = 2y + 1 $ and $ y $ is in $ S $ .
3. $ x = 4y $ and $ y $ is in $ S $ .

For example, if $ a = [1,2] $ then the $ 10 $ smallest elements in $ S $ will be $ \{1,2,3,4,5,7,8,9,11,12\} $ .

Find the number of elements in $ S $ that are strictly smaller than $ 2^p $ . Since this number may be too large, print it modulo $ 10^9 + 7 $ .

## 输入格式

The first line contains two integers $ n $ and $ p $ $ (1 \leq n, p \leq 2 \cdot 10^5) $ .

The second line contains $ n $ integers $ a_1,a_2,\ldots,a_n $ $ (1 \leq a_i \leq 10^9) $ .

It is guaranteed that all the numbers in $ a $ are distinct.

## 输出格式

Print a single integer, the number of elements in $ S $ that are strictly smaller than $ 2^p $ . Remember to print it modulo $ 10^9 + 7 $ .

## 输入输出样例 #1

### 输入 #1

```
2 4
6 1
```

### 输出 #1

```
9
```

## 输入输出样例 #2

### 输入 #2

```
4 7
20 39 5 200
```

### 输出 #2

```
14
```

## 输入输出样例 #3

### 输入 #3

```
2 200000
48763 1000000000
```

### 输出 #3

```
448201910
```

## 说明/提示

In the first example, the elements smaller than $ 2^4 $ are $ \{1, 3, 4, 6, 7, 9, 12, 13, 15\} $ .

In the second example, the elements smaller than $ 2^7 $ are $ \{5,11,20,23,39,41,44,47,79,80,83,89,92,95\} $ .