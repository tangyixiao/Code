# CF1537A Arithmetic Array

## 题目描述

一个长度为 $k$ 的数组 $b$ 被称为“好”的，如果它的算术平均值等于 $1$。更正式地说，如果
$$
\frac{b_1 + \cdots + b_k}{k}=1。
$$
注意，这里的 $ \frac{b_1+\cdots+b_k}{k} $ 不进行向上或向下取整。例如，数组 $[1,1,1,2]$ 的算术平均值为 $1.25$，不等于 $1$。

给定一个长度为 $n$ 的整数数组 $a$。每次操作，你可以在数组末尾添加一个非负整数。你需要的最少操作次数是多少，才能使数组变为“好”的？

我们已经证明，总是可以通过有限次操作实现目标。

## 输入格式

第一行包含一个整数 $t$（$1 \leq t \leq 1000$）——表示测试用例的数量。接下来是 $t$ 组测试数据。

每组测试数据的第一行包含一个整数 $n$（$1 \leq n \leq 50$）——初始数组 $a$ 的长度。

第二行包含 $n$ 个整数 $a_1,\ldots,a_n$（$-10^4\leq a_i \leq 10^4$），表示数组的元素。

## 输出格式

对于每个测试用例，输出一个整数——你需要在数组末尾添加的非负整数的最小数量，使得数组的算术平均值恰好等于 $1$。

## 输入输出样例 #1

### 输入 #1

```
4
3
1 1 1
2
1 2
4
8 4 6 2
1
-2
```

### 输出 #1

```
0
1
16
1
```

## 说明/提示

在第一个测试用例中，不需要添加任何元素，因为数组的算术平均值已经是 $1$，所以答案是 $0$。

在第二个测试用例中，初始的算术平均值不是 $1$，所以至少需要再添加一个数。如果我们添加 $0$，整个数组的算术平均值就变成了 $1$，所以答案是 $1$。

在第三个测试用例中，最少需要添加 $16$ 个元素，因为只能添加非负整数。

在第四个测试用例中，我们可以添加一个整数 $4$。此时算术平均值变为 $\frac{-2+4}{2}$，等于 $1$。

由 ChatGPT 4.1 翻译

---

# CF1537A Arithmetic Array

## 题目描述

An array $ b $ of length $ k $ is called good if its arithmetic mean is equal to $ 1 $ . More formally, if $ $$$\frac{b_1 + \cdots + b_k}{k}=1. $ $ </p><p>Note that the value  $ \\frac{b\_1+\\cdots+b\_k}{k} $  is not rounded up or down. For example, the array  $ \[1,1,1,2\] $  has an arithmetic mean of  $ 1.25 $ , which is not equal to  $ 1 $ .</p><p>You are given an integer array  $ a $  of length  $ n$$$. In an operation, you can append a non-negative integer to the end of the array. What's the minimum number of operations required to make the array good?

We have a proof that it is always possible with finitely many operations.

## 输入格式

The first line contains a single integer $ t $ ( $ 1 \leq t \leq 1000 $ ) — the number of test cases. Then $ t $ test cases follow.

The first line of each test case contains a single integer $ n $ ( $ 1 \leq n \leq 50 $ ) — the length of the initial array $ a $ .

The second line of each test case contains $ n $ integers $ a_1,\ldots,a_n $ ( $ -10^4\leq a_i \leq 10^4 $ ), the elements of the array.

## 输出格式

For each test case, output a single integer — the minimum number of non-negative integers you have to append to the array so that the arithmetic mean of the array will be exactly $ 1 $ .

## 输入输出样例 #1

### 输入 #1

```
4
3
1 1 1
2
1 2
4
8 4 6 2
1
-2
```

### 输出 #1

```
0
1
16
1
```

## 说明/提示

In the first test case, we don't need to add any element because the arithmetic mean of the array is already $ 1 $ , so the answer is $ 0 $ .

In the second test case, the arithmetic mean is not $ 1 $ initially so we need to add at least one more number. If we add $ 0 $ then the arithmetic mean of the whole array becomes $ 1 $ , so the answer is $ 1 $ .

In the third test case, the minimum number of elements that need to be added is $ 16 $ since only non-negative integers can be added.

In the fourth test case, we can add a single integer $ 4 $ . The arithmetic mean becomes $ \frac{-2+4}{2} $ which is equal to $ 1 $ .