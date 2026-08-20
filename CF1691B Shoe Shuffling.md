# CF1691B Shoe Shuffling

## 题目描述

一个班的学生想要互相换鞋子，假设这个班有 $n$ 名学生，给定一个**非递减**的序列记录每个学生鞋子的码数。你需要给出一个下标排列，使得每个学生拿到的都不是自己的鞋子，并且码数与原来的相同。如果找不到这样的下标排列，输出 $-1$ 。

定义一个下标排列由整数 $1$ 到 $n$ 组成，顺序任意。比如， $ [2,3,1,5,4] $ 是一个下标序列；$ [1,2,2] $ 不是一个下标数列，因为 $2$ 出现了两次；$ [1,3,4] $ 不是一个下标序列，因为排列的长度为 $3$ 却出现了元素 $4$。

## 输入格式

每个测试点有多组数据。

第一行一个整数 $t$ ( $ 1 \le t \le 1000 $ )，表示共有 $t$  组数据。

接下来 $2t$ 行。每组数据 $2$ 行。

每组数据的第一行一个整数 $n$ ( $ 1\leq n\leq10^5 $ ) 表示学生个数。

每组数据第二行 $n$ 个整数  $ s_1, s_2,\ldots,s_n $ ( $ 1\leq s_i\leq10^9 $ ，对于所有 $ 1\le i<n $ , $ s_i\le s_{i+1} $ ) ，表示学生鞋子的码数。

保证所有数据 $n$ 的和不超过 $ 10^5 $ 。

## 输出格式

无

## 输入输出样例 #1

### 输入 #1

```
2
5
1 1 1 1 1
6
3 6 8 13 15 21
```

### 输出 #1

```
5 1 2 3 4 
-1
```

## 说明/提示

对于第一组数据，除了 $[1, 2, 3, 4, 5]$ 外的长度为 $5$ 的下标序列都是合法的，因为每个同学之间都能穿对方的鞋子。

对于第二组数据，可以证明没有合法的下标序列。

---

# CF1691B Shoe Shuffling

## 题目描述

A class of students got bored wearing the same pair of shoes every day, so they decided to shuffle their shoes among themselves. In this problem, a pair of shoes is inseparable and is considered as a single object.

There are $ n $ students in the class, and you are given an array $ s $ in non-decreasing order, where $ s_i $ is the shoe size of the $ i $ -th student. A shuffling of shoes is valid only if no student gets their own shoes and if every student gets shoes of size greater than or equal to their size.

You have to output a permutation $ p $ of $ \{1,2,\ldots,n\} $ denoting a valid shuffling of shoes, where the $ i $ -th student gets the shoes of the $ p_i $ -th student ( $ p_i \ne i $ ). And output $ -1 $ if a valid shuffling does not exist.

A permutation is an array consisting of $ n $ distinct integers from $ 1 $ to $ n $ in arbitrary order. For example, $ [2,3,1,5,4] $ is a permutation, but $ [1,2,2] $ is not a permutation ( $ 2 $ appears twice in the array) and $ [1,3,4] $ is also not a permutation ( $ n=3 $ but there is $ 4 $ in the array).

## 输入格式

Each test contains multiple test cases. The first line contains a single integer $ t $ ( $ 1 \le t \le 1000 $ ) — the number of test cases. Description of the test cases follows.

The first line of each test case contains a single integer $ n $ ( $ 1\leq n\leq10^5 $ ) — the number of students.

The second line of each test case contains $ n $ integers $ s_1, s_2,\ldots,s_n $ ( $ 1\leq s_i\leq10^9 $ , and for all $ 1\le i<n $ , $ s_i\le s_{i+1} $ ) — the shoe sizes of the students.

It is guaranteed that the sum of $ n $ over all test cases does not exceed $ 10^5 $ .

## 输出格式

For each test case, print the answer in a single line using the following format.

If a valid shuffling does not exist, print the number $ -1 $ as the answer.

If a valid shuffling exists, print $ n $ space-separated integers — a permutation $ p $ of $ 1,2,\ldots,n $ denoting a valid shuffling of shoes where the $ i $ -th student gets the shoes of the $ p_i $ -th student. If there are multiple answers, then print any of them.

## 输入输出样例 #1

### 输入 #1

```
2
5
1 1 1 1 1
6
3 6 8 13 15 21
```

### 输出 #1

```
5 1 2 3 4 
-1
```

## 说明/提示

In the first test case, any permutation $ p $ of $ 1,\ldots,n $ where $ p_i\ne i $ would represent a valid shuffling since all students have equal shoe sizes, and thus anyone can wear anyone's shoes.

In the second test case, it can be shown that no valid shuffling is possible.