# CF1691A Beat The Odds

## 题目描述

### 题目翻译
给定一个序列$a_{1}$,$a_{2}$,...,$a_{n}$,要使序列中每两个连续的数的和为偶数，找出最少要删除序列的元素的个数

## 输入格式

**有多组数据**  
第一行包括一个整数$t$($1 \le t \le 100$),表示有$t$组数据  
每组数据的第一行包括一个整数$n$（$3 \le n \le 10^5$)  
每组数据的第二行包括$n$个整数$a_{1}$,$a_{2}$,...,$a_{n}$($1 \le a_{1} \le 10^9$)  
保证$n$在所有数据里不超过$10^5$

## 输出格式

输出$n$行，表示最少删除序列中的元素使得序列中每两个连续数的和为偶数  
### 输入输出样例解释
在第一组数据中，删除3后序列变成[2、4、6、8],满足题目要求，因此只需删除一个元素即可，输出1  
在第二组数据中，每两个连续数的和都是偶数，因此不需要删除任何元素，输出0

## 输入输出样例 #1

### 输入 #1

```
2
5
2 4 3 6 8
6
3 5 9 7 1 3
```

### 输出 #1

```
1
0
```

---

# CF1691A Beat The Odds

## 题目描述

Given a sequence $ a_1, a_2, \ldots, a_n $ , find the minimum number of elements to remove from the sequence such that after the removal, the sum of every $ 2 $ consecutive elements is even.

## 输入格式

Each test contains multiple test cases. The first line contains a single integer $ t $ ( $ 1 \le t \le 100 $ ) — the number of test cases. Description of the test cases follows.

The first line of each test case contains a single integer $ n $ ( $ 3 \le n \le 10^5 $ ).

The second line of each test case contains $ n $ integers $ a_1, a_2,\dots,a_n $ ( $ 1\leq a_i\leq10^9 $ ) — elements of the sequence.

It is guaranteed that the sum of $ n $ over all test cases does not exceed $ 10^5 $ .

## 输出格式

For each test case, print a single integer — the minimum number of elements to remove from the sequence such that the sum of every $ 2 $ consecutive elements is even.

## 输入输出样例 #1

### 输入 #1

```
2
5
2 4 3 6 8
6
3 5 9 7 1 3
```

### 输出 #1

```
1
0
```

## 说明/提示

In the first test case, after removing $ 3 $ , the sequence becomes $ [2,4,6,8] $ . The pairs of consecutive elements are $ \{[2, 4], [4, 6], [6, 8]\} $ . Each consecutive pair has an even sum now. Hence, we only need to remove $ 1 $ element to satisfy the condition asked.

In the second test case, each consecutive pair already has an even sum so we need not remove any element.