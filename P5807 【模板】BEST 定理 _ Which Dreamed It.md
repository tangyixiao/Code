# P5807 【模板】BEST 定理 / Which Dreamed It

## 题目背景

请注意本题与真正的 BEST 定理略有出入：BEST 定理没有从 $1$ 出发的限制，且回路的边序列是循环同构的。

## 题目描述

有 $n$ 个房间，每个房间有若干把钥匙能够打开特定房间的门。

最初你在房间 $1$。每当你到达一个房间，你可以选择该房间的一把钥匙，前往该钥匙对应的房间，并将该钥匙丢到垃圾桶中。

你希望最终回到房间 $1$，且垃圾桶中有所有的钥匙。

你需要求出方案数，答案对 $10^6 + 3$ 取模。两组方案不同，当且仅当使用钥匙的顺序不同。

注意，每把钥匙都是不同的。

原 BZOJ3659。

## 输入格式

**本题有多组数据。**

第一行一个整数 $T$，表示数据组数。

对于每组数据：

第一行一个整数 $n$。

接下来 $n$ 行，第 $i$ 行描述房间 $i$：

首先一个数 $s$，表示这个房间的钥匙数目，接下来 $s$ 个数，分别描述每把钥匙能够打开的房间的门。

## 输出格式

对于每组数据，一行一个整数，表示答案对 $10^6+3$ 取模后的值。

## 输入输出样例 #1

### 输入 #1

```
2
1
0
2
1 1
1 2

```

### 输出 #1

```
1
0

```

## 输入输出样例 #2

### 输入 #2

```
5
3
1 2
1 3
1 2
3
1 2
1 1
0
3
1 2
1 1
1 3
3
1 2
1 3
1 1
3
0
0
0
```

### 输出 #2

```
0
1
0
1
1

```

## 输入输出样例 #3

### 输入 #3

```
4
6
1 4 
1 4 
1 2 
2 5 5 
2 3 1 
0 
7
2 6 5 
3 3 6 1 
4 4 2 4 5 
3 3 7 2 
4 6 3 1 6 
4 4 2 5 5 
1 3 
10
7 8 9 2 6 7 9 6 
5 6 10 5 1 3 
5 5 7 7 9 6 
4 5 7 9 7 
4 1 2 7 9 
6 4 10 8 1 10 3 
8 2 3 4 10 5 1 3 8 
7 7 10 6 1 2 3 7 
8 8 8 10 2 4 4 6 1 
6 9 8 1 8 9 9 
15
11 10 10 10 11 2 13 10 8 14 9 14 
9 5 3 10 1 15 11 8 13 11 
7 1 15 13 7 15 8 5 
7 8 14 7 1 2 3 8 
3 11 4 10 
7 7 12 7 4 12 11 12 
10 10 12 3 13 15 1 2 8 11 12 
12 9 4 13 10 2 6 13 10 7 6 7 11 
6 4 1 2 8 12 1 
15 1 11 9 9 7 7 6 6 2 8 12 2 8 12 2 
10 12 10 6 10 3 1 6 3 9 4 
12 15 14 10 14 14 9 8 7 7 11 13 4 
7 12 3 10 6 1 1 4 
6 12 5 8 3 8 12 
5 10 10 1 11 2 

```

### 输出 #3

```
2
190080
120594
887148

```

## 说明/提示

### 样例解释

* 样例 $1$ 说明

在第一组样例中，没有钥匙，则方案数为 $1$。

在第二组样例中，你不可能使用第二个房间的钥匙，所以方案数为 $0$。

* 样例 $2$ 说明

只要使用完所有的钥匙即可，不一定要经过所有的房间。

* 样例 $3$ 说明

前三组数据在取模前的答案分别是 $2,190080,49476320425715737559040000000$。

### 数据范围

对于 $50\%$ 的数据，$n \le 4$，$\sum s \le 30$。

对于 $100\%$ 的数据，$1 \le T \le 15$，$1 \le n \le 100$，$0 \le \sum s \le 3141592$。

2021/5/14 加强 by [SSerxhs](https://www.luogu.com.cn/user/29826)&[滑大稽](https://www.luogu.com.cn/user/203743)

---

# P5807 [Template] BEST Theorem / Which Dreamed It

## 题目背景

Please note that this problem is slightly different from the real BEST Theorem: the BEST Theorem does not require starting from $1$, and the edge sequence of the circuit is considered up to cyclic isomorphism.

## 题目描述

There are $n$ rooms, and each room has several keys that can open the door to a specific room.

At the beginning, you are in room $1$. Each time you arrive at a room, you may choose one key in that room, go to the room corresponding to that key, and throw that key into the trash bin.

You want to finally return to room $1$, and have all the keys in the trash bin.

You need to count the number of valid plans, modulo $10^6 + 3$. Two plans are different if and only if the order of using keys is different.

Note that every key is distinct.

Originally BZOJ3659.

## 输入格式

**This problem contains multiple test cases.**

The first line contains an integer $T$, the number of test cases.

For each test case:

The first line contains an integer $n$.

The next $n$ lines describe the rooms. Line $i$ describes room $i$:

First a number $s$, the number of keys in this room, followed by $s$ numbers, each describing which room’s door that key can open.

## 输出格式

For each test case, output one integer per line, the answer modulo $10^6 + 3$.

## 输入输出样例 #1

### 输入 #1

```
2
1
0
2
1 1
1 2

```

### 输出 #1

```
1
0

```

## 输入输出样例 #2

### 输入 #2

```
5
3
1 2
1 3
1 2
3
1 2
1 1
0
3
1 2
1 1
1 3
3
1 2
1 3
1 1
3
0
0
0
```

### 输出 #2

```
0
1
0
1
1

```

## 输入输出样例 #3

### 输入 #3

```
4
6
1 4 
1 4 
1 2 
2 5 5 
2 3 1 
0 
7
2 6 5 
3 3 6 1 
4 4 2 4 5 
3 3 7 2 
4 6 3 1 6 
4 4 2 5 5 
1 3 
10
7 8 9 2 6 7 9 6 
5 6 10 5 1 3 
5 5 7 7 9 6 
4 5 7 9 7 
4 1 2 7 9 
6 4 10 8 1 10 3 
8 2 3 4 10 5 1 3 8 
7 7 10 6 1 2 3 7 
8 8 8 10 2 4 4 6 1 
6 9 8 1 8 9 9 
15
11 10 10 10 11 2 13 10 8 14 9 14 
9 5 3 10 1 15 11 8 13 11 
7 1 15 13 7 15 8 5 
7 8 14 7 1 2 3 8 
3 11 4 10 
7 7 12 7 4 12 11 12 
10 10 12 3 13 15 1 2 8 11 12 
12 9 4 13 10 2 6 13 10 7 6 7 11 
6 4 1 2 8 12 1 
15 1 11 9 9 7 7 6 6 2 8 12 2 8 12 2 
10 12 10 6 10 3 1 6 3 9 4 
12 15 14 10 14 14 9 8 7 7 11 13 4 
7 12 3 10 6 1 1 4 
6 12 5 8 3 8 12 
5 10 10 1 11 2 

```

### 输出 #3

```
2
190080
120594
887148

```

## 说明/提示

### Sample Explanation

* Sample $1$

In the first test case, there are no keys, so the number of plans is $1$.

In the second test case, you cannot use the key in the second room, so the number of plans is $0$.

* Sample $2$

It is enough to use up all the keys; you do not necessarily need to visit all rooms.

* Sample $3$

Before taking modulo, the answers for the first three test cases are $2,190080,49476320425715737559040000000$, respectively.

### Constraints

For $50\%$ of the testdata, $n \le 4$, $\sum s \le 30$.

For $100\%$ of the testdata, $1 \le T \le 15$, $1 \le n \le 100$, $0 \le \sum s \le 3141592$.

Strengthened on 2021/5/14 by [SSerxhs](https://www.luogu.com.cn/user/29826) & [滑大稽](https://www.luogu.com.cn/user/203743).

Translated by ChatGPT 5