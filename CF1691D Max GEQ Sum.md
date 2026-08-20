# CF1691D Max GEQ Sum

## 题目描述

现在你有一个由 $n$ 个整数组成的数组 $a$，$(i,j)$ 满足条件当且仅当 $\max (a_i,a_{i+1},\cdots,a_j)\ge a_i+a_{i+1}+\cdots+a_j$，其中 $1\le i\le j\le n$。问是否所有 $(i,j)$ 都满足要求。

## 输入格式

第一行包括一个整数 $t$，表示数据的组数。

每组数据的第一行包括一个整数 $n(1 \le n \le 2 \times 10^5)$，表示数组的长度。

每组数据的第二行为 $n$ 个整数，即为 $a_1,a_2,\dots , a_n(-10^9 \le a_i \le 10^9)$。

保证所有数据的 $n$ 之和不超过 $2\times 10^5$。

## 输出格式

对于每组数据，所有 $(i,j)$ 都符合条件则输出 `YES`，否则输出 `NO`。

## 输入输出样例 #1

### 输入 #1

```
3
4
-1 1 -1 2
5
-1 2 -3 2 -1
3
2 3 -1
```

### 输出 #1

```
YES
YES
NO
```

## 说明/提示

In test cases $ 1 $ and $ 2 $ , the given condition is satisfied for all $ (i, j) $ pairs.

In test case $ 3 $ , the condition isn't satisfied for the pair $ (1, 2) $ as $ \max(2, 3) < 2 + 3 $ .

---

# CF1691D Max GEQ Sum

## 题目描述

You are given an array $ a $ of $ n $ integers. You are asked to find out if the inequality $\max(a_i, a_{i + 1}, \ldots, a_{j - 1}, a_{j}) \geq a_i + a_{i + 1} + \dots + a_{j - 1} + a_{j} $  holds for all pairs of indices  $ (i, j) $ , where  $ 1 \leq i \leq j \leq n$.

## 输入格式

Each test contains multiple test cases. The first line contains the number of test cases $ t $ ( $ 1 \le t \le 10^5 $ ). Description of the test cases follows.

The first line of each test case contains a single integer $ n $ ( $ 1 \leq n \leq 2 \cdot 10^5 $ ) — the size of the array.

The next line of each test case contains $ n $ integers $ a_1, a_2, \ldots, a_n $ ( $ -10^9 \le a_i \le 10^9 $ ).

It is guaranteed that the sum of $ n $ over all test cases does not exceed $ 2 \cdot 10^5 $ .

## 输出格式

For each test case, on a new line output "YES" if the condition is satisfied for the given array, and "NO" otherwise. You can print each letter in any case (upper or lower).

## 输入输出样例 #1

### 输入 #1

```
3
4
-1 1 -1 2
5
-1 2 -3 2 -1
3
2 3 -1
```

### 输出 #1

```
YES
YES
NO
```

## 说明/提示

In test cases $ 1 $ and $ 2 $ , the given condition is satisfied for all $ (i, j) $ pairs.

In test case $ 3 $ , the condition isn't satisfied for the pair $ (1, 2) $ as $ \max(2, 3) < 2 + 3 $ .