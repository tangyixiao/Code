# P16567 [ICPC 2026 APC] Growth Factor

## 题目描述

给定一个整数 $n$ 和一个整数序列 $a_1, a_2, \ldots, a_n$。你的任务是确定有多少个整数序列 $(b_1, b_2, \ldots, b_n)$ 满足如下条件：

- 对于每个 $i$（$1 \leq i \leq n$），有 $1 \leq b_i \leq a_i$。
- 对于每个 $i$（$1 \leq i \leq n-1$），有 $b_i$ 是 $b_{i+1}$ 的因数。

如果两个序列在至少一个位置的值不同，则认为它们是不同的序列。

由于满足条件的序列数可能很大，请输出它对 $998\,244\,353$ 取模后的结果。

## 输入格式

第一行输入一个整数 $n$，表示序列的长度（$1 \leq n \leq 200\,000$）。

第二行输入 $n$ 个整数 $a_1, a_2, \ldots, a_n$（$1 \leq a_i \leq 200\,000$）。

## 输出格式

输出满足条件的不同序列数，对 $998\,244\,353$ 取模。

## 输入输出样例 #1

### 输入 #1

```
2
2 4
```

### 输出 #1

```
6
```

## 输入输出样例 #2

### 输入 #2

```
6
265 9801 192168 200000 192018 199809
```

### 输出 #2

```
16555779

```

## 说明/提示

样例输入输出 $1$ 的解释：

所有满足条件的序列有：$(2,4)$、$(2,2)$、$(1,4)$、$(1,3)$、$(1,2)$ 和 $(1,1)$。

由 ChatGPT 5 翻译

---

# P16567 [ICPC 2026 APC] Growth Factor

## 题目描述

You are given an integer  $ n $  and a sequence of integers  $ a_1, a_2, \ldots, a_n $ . Your task is to determine the number of integer sequences  $ (b_1, b_2, \ldots, b_n) $  such that the following conditions are satisfied:

- $ 1 \leq b_i \leq a_i $  for each  $ i $  ( $ 1 \le i \le n $ ).
- $ b_i $  is a factor of  $ b_{i+1} $  for each  $ i $  ( $ 1 \le i \le n-1 $ ).

Two sequences are considered different if they differ in at least one position.

Since the number of such sequences may be large, compute the answer modulo  $ 998\,244\,353 $ .

## 输入格式

The first line of input contains a single integer  $ n $  ( $ 1 \le n \le 200\,000 $ ).

The second line contains  $ n $  integers  $ a_1, a_2, \ldots, a_n $  ( $ 1 \le a_i \le 200\,000 $ ).

## 输出格式

Output the number of distinct sequences satisfying the conditions, modulo  $ 998\,244\,353 $ .

## 输入输出样例 #1

### 输入 #1

```
2
2 4
```

### 输出 #1

```
6
```

## 输入输出样例 #2

### 输入 #2

```
6
265 9801 192168 200000 192018 199809
```

### 输出 #2

```
16555779

```

## 说明/提示

Explanation for the sample input/output #1

The following are all sequences satisfying the conditions:  $ (2,4) $ ,  $ (2,2) $ ,  $ (1,4) $ ,  $ (1,3) $ ,  $ (1,2) $ , and  $ (1,1) $ .