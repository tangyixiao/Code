# CF1943D1 Counting Is Fun (Easy Version)

## 题目描述

这是该问题的简单版本。两个版本的唯一区别在于 $ n $ 的约束条件。只有当你同时解决了两个版本的问题时，才能进行 hack。

一个长度为 $ m $ 的非负整数数组 $ b $ 被称为“好数组”，如果可以通过以下操作若干次（可能为零次）将 $ b $ 的所有元素都变为 $ 0 $：

- 选择两个不同的下标 $ l $ 和 $ r $（$ 1 \leq l \color{red}< \color{normal}r \leq m $），并对所有满足 $ l \leq i \leq r $ 的 $ b_i $ 执行 $ b_i= b_i - 1 $。

现在给定两个正整数 $ n $、$ k $ 和一个质数 $ p $。

在所有长度为 $ n $ 的数组 $ a $ 中，满足 $ 0 \leq a_i \leq k $（$ 1 \leq i \leq n $），请统计有多少个“好数组”。

由于答案可能很大，你只需要输出答案对 $ p $ 取模的结果。

## 输入格式

每组测试数据包含多组测试用例。第一行包含一个整数 $ t $（$ 1 \leq t \leq 10^3 $），表示测试用例的数量。接下来是每个测试用例的描述。

每个测试用例的第一行包含三个正整数 $ n $、$ k $ 和 $ p $（$ 3 \leq n \leq 400 $，$ 1 \leq k \leq n $，$ 10^8 < p < 10^9 $），分别表示数组 $ a $ 的长度、元素的上界以及取模的质数。

保证所有测试用例中 $ n^2 $ 的和不超过 $ 2 \cdot 10^5 $，且 $ p $ 是质数。

## 输出格式

对于每个测试用例，输出一行，表示“好数组”的数量对 $ p $ 取模的结果。

## 输入输出样例 #1

### 输入 #1

```
4
3 1 998244853
4 1 998244353
3 2 998244353
343 343 998244353
```

### 输出 #1

```
4
7
10
456615865
```

## 说明/提示

在第一个测试用例中，$ 4 $ 个“好数组” $ a $ 分别为：

- $ [0,0,0] $；
- $ [0,1,1] $；
- $ [1,1,0] $；
- $ [1,1,1] $。

由 ChatGPT 4.1 翻译

---

# CF1943D1 Counting Is Fun (Easy Version)

## 题目描述

This is the easy version of the problem. The only difference between the two versions is the constraint on $ n $ . You can make hacks only if both versions of the problem are solved.

An array $ b $ of $ m $ non-negative integers is said to be good if all the elements of $ b $ can be made equal to $ 0 $ using the following operation some (possibly, zero) times:

- Select two distinct indices $ l $ and $ r $ ( $ 1 \leq l \color{red} < \color{normal}r \leq m $ ) and subtract $ 1 $ from all $ b_i $ such that $ l \leq i \leq r $ .

You are given two positive integers $ n $ , $ k $ and a prime number $ p $ .

Over all $ (k+1)^n $ arrays of length $ n $ such that $ 0 \leq a_i \leq k $ for all $ 1 \leq i \leq n $ , count the number of good arrays.

Since the number might be too large, you are only required to find it modulo $ p $ .

## 输入格式

Each test contains multiple test cases. The first line contains a single integer $ t $ ( $ 1 \leq t \leq 10^3 $ ) — the number of test cases. The description of the test cases follows.

The first line of each test case contains three positive integers $ n $ , $ k $ and $ p $ ( $ 3 \leq n \leq 400 $ , $ 1 \leq k \leq n $ , $ 10^8 < p < 10^9 $ ) — the length of the array $ a $ , the upper bound on the elements of $ a $ and modulus $ p $ .

It is guaranteed that the sum of $ n^2 $ over all test cases does not exceed $ 2 \cdot 10^5 $ , and $ p $ is prime.

## 输出格式

For each test case, on a new line, output the number of good arrays modulo $ p $ .

## 输入输出样例 #1

### 输入 #1

```
4
3 1 998244853
4 1 998244353
3 2 998244353
343 343 998244353
```

### 输出 #1

```
4
7
10
456615865
```

## 说明/提示

In the first test case, the $ 4 $ good arrays $ a $ are:

- $ [0,0,0] $ ;
- $ [0,1,1] $ ;
- $ [1,1,0] $ ;
- $ [1,1,1] $ .