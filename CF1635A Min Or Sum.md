# CF1635A Min Or Sum

## 题目描述

给出一个含有 $n$ 个元素的序列 $a$。

对于每次操作，你可以选择两个不同的整数 $i, j(1 \le i \le j \le n)$，将 $a_i$ 替换为 $x$、将 $a_j$ 替换为 $y$。  

为了不破坏这个序列，你需要保证 $a_i|a_j = x|y$，且 $x,y$ 均为非负整数。（其中 `|` 表示[按位或运算](https://baike.baidu.com/item/%E6%8C%89%E4%BD%8D%E6%88%96/548283?fr=aladdin)。

你需要通过上述操作，最小化此序列的和 $(a_1+a_2+a_3+...+a_n)$。

请输出经过任意次操作后，序列的最小和。

## 输入格式

此题包含多个测试用例，第一行一个正整数 $t$ 表示测试用例的数量。

对于每个测试用例：

- 第一行一个整数 $n$，代表序列的元素数量。

- 第二行 $n$ 个整数 $a_1,a_2,...,a_n(0 \le a_i \le 2^{30})$。

## 输出格式

对于每个测试用例，输出一个整数表示序列中元素和的最小值。

## 输入输出样例 #1

### 输入 #1

```
4
3
1 3 2
5
1 2 4 8 16
2
6 6
3
3 5 6
```

### 输出 #1

```
3
31
6
7
```

## 说明/提示

在第一个测试用例中，你可以进行如下操作：

- 选择 $i=1,j=2$，修改 $a_1$ 为 $1$，修改 $a_2$ 为 $2$。因为 $1|3 = 1|2$，所以是有效的操作。此时序列变为 $[1, 2, 2]$。

- 选择 $i=2,j=3$，修改 $a_2$ 为 $0$，修改 $a_3$ 为 $2$。因为 $2|2 = 0|2$，所以是有效的操作。此时序列变为 $[1, 0, 2]$。

我们可以证明其最小和为 $1+0+2=3$。

对于第二个测试用例，我们不需要任何操作。

$\texttt{Translated by lym12321}$

---

# CF1635A Min Or Sum

## 题目描述

You are given an array $ a $ of size $ n $ .

You can perform the following operation on the array:

- Choose two different integers $ i, j $ $ (1 \leq i < j \leq n $ ), replace $ a_i $ with $ x $ and $ a_j $ with $ y $ . In order not to break the array, $ a_i | a_j = x | y $ must be held, where $ | $ denotes the [bitwise OR operation](https://en.wikipedia.org/wiki/Bitwise_operation#OR). Notice that $ x $ and $ y $ are non-negative integers.

Please output the minimum sum of the array you can get after using the operation above any number of times.

## 输入格式

Each test contains multiple test cases. The first line contains the number of test cases $ t $ $ (1 \leq t \leq 1000) $ . Description of the test cases follows.

The first line of each test case contains an integer $ n $ $ (2 \leq n \leq 100) $ — the size of array $ a $ .

The second line of each test case contains $ n $ integers $ a_1, a_2, \ldots ,a_n $ $ (0 \leq a_i < 2^{30}) $ .

## 输出格式

For each test case, print one number in a line — the minimum possible sum of the array.

## 输入输出样例 #1

### 输入 #1

```
4
3
1 3 2
5
1 2 4 8 16
2
6 6
3
3 5 6
```

### 输出 #1

```
3
31
6
7
```

## 说明/提示

In the first example, you can perform the following operations to obtain the array $ [1, 0, 2] $ :

1\. choose $ i = 1, j = 2 $ , change $ a_1 = 1 $ and $ a_2 = 2 $ , it's valid since $ 1 | 3 = 1 | 2 $ . The array becomes $ [1, 2, 2] $ .

2\. choose $ i = 2, j = 3 $ , change $ a_2 = 0 $ and $ a_3 = 2 $ , it's valid since $ 2 | 2 = 0 | 2 $ . The array becomes $ [1, 0, 2] $ .

We can prove that the minimum sum is $ 1 + 0 + 2 = 3 $

In the second example, We don't need any operations.
