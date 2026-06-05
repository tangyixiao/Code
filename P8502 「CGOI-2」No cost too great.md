# P8502 「CGOI-2」No cost too great

## 题目背景

光芒浸透圣巢，她正犯下弥天之错。

所剩寥寥无几的信仰，为什么始终执着。

我将作灯塔，照耀王国。

但在那之前有更重要的事去做，

无论什么代价都在所不惜，尽管我所剩无多……

## 题目描述

白王正在最后一次参观他建造的宏伟宫殿。现在假设宫殿由 $n$ 个房间构成，房间之间有若干个**单向**通道。出于白王奇怪的装修癖好（不是指到处安电锯），对于第 $i$ 个房间，它向编号在区间 $[l_i,r_i]$ 中的所有房间都连有一条单向通道。例如，$4$ 号房间向 $[2,5]$ 连有单向通道，就意味着从 $4$ 号房间到 $2,3,4,5$ 号房间各有一条单向通道（一个房间可以向自己连有通道）。当一个房间向 $[0,0]$ 连有通道时，表示没有从这个房间出发的通道。

白王提出了 $q$ 个问题，每次询问从 $a$ 号房间，通过恰好 $m$ 条单向通道且不经过 $c$ 号房间到达 $b$ 号房间的方案数（两方案不同，当且仅当存在 $i$ 使得两方案通过的第 $i$ 条通道不同）。因为这个数字可能会很大，所以白王让你将答案模 $998244353$ 后再回答。

## 输入格式

第一行，两个整数 $n, q$ 表示点数和询问数。

接下来 $n$ 行，每行两个整数 $l, r$，第 $i+1$ 行的整数 $l_i, r_i$ 表示 $i$ 号节点向区间 $[l_i, r_i]$ 中的每个点都连了一条单向边。当 $l_i=r_i=0$ 时，表示该节点没有向任何点连边。

接下来 $q$ 行，每行四个整数 $a, b, c, m$ 表示一个询问。

## 输出格式

$q$ 行，每行一个整数，第 $i$ 行的数字表示第 $i$ 个询问的方案数模 $998244353$ 的结果。

## 输入输出样例 #1

### 输入 #1

```
4 5
2 3
1 1
2 4
0 0
1 3 4 5
1 4 2 4
2 3 1 2
4 4 3 0
1 3 2 5
```

### 输出 #1

```
5
1
0
1
1
```

## 输入输出样例 #2

### 输入 #2

```
10 10
6 6
4 10
2 5
1 7
3 4
5 7
4 10
1 7
1 3
2 5
8 8 5 1
4 7 5 3
5 9 4 4
1 5 5 2
6 2 10 2
3 3 7 4
1 10 1 2
6 2 4 4
9 2 1 4
9 10 3 2
```

### 输出 #2

```
0
17
2
0
0
46
0
12
23
1
```

## 输入输出样例 #3

### 输入 #3

```
10 10
2 6
6 9
5 7
3 9
0 0
0 0
3 5
5 5
3 6
1 10
5 9 6 3
10 8 6 4
10 8 5 1
8 6 5 4
7 2 5 4
6 1 5 3
10 4 5 1
5 5 6 0
7 9 6 4
4 9 6 2
```

### 输出 #3

```
0
17
1
0
0
0
1
1
4
1
```

## 说明/提示

### 样例说明

在样例一中，$1$ 号房间能到达 $2,3$ 号房间，$2$ 号房间能到达 $1$ 号房间，$3$ 号房间能到达 $2,3,4$ 号房间，$4$ 号房间不能到达任何房间。

对于第一个询问，从 $1$ 号房间经过 $5$ 条通道且不经过 $4$ 号房间到达 $3$ 号房间的方案有 `121213`，`121333`，`133213`，`132133`，`133333` 共五种。

---

### 数据范围

**本题采用捆绑测试。**

| 编号| 特殊性质 | 空间限制 |分数 |
| :-: | :-: | :-: | :-: |
| 0 | $n\le10$，$q\le10$，$m\le4$ | 256MB | 10pts |
| 1 | $n\le100$，$q\le10^4$，$m\le40$ | 256MB | 15pts |
| 2 | 对于所有询问，$l_c=r_c=0$ | 256MB | 15pts |
| 3 | 无 | 256MB | 30pts |
| 4 | 无 | 128MB | 30pts |

对于 $100\%$ 的数据，$1\le n \le 500$，$1\le q \le 10^5$，$1\le m \le 100$，$0 \le l_i \le r_i \le n$，$1 \le a,b,c \le n$。当且仅当 $l_i=0$ 时 $r_i=0$。时间限制均为 1s。

---

### 提示

**注意空间常数。**

---

# P8502 "CGOI-2" No cost too great

## 题目背景

The Radiance seeps into Hallownest; she is making a huge mistake.

With only a little faith left, why does she still insist.

I will be a lighthouse, shining upon the kingdom.

But before that, there are more important things to do.

No matter what the cost is, I will not hesitate, even though I have little left...

## 题目描述

The Pale King is making his final visit to the magnificent palace he built. Now suppose the palace consists of $n$ rooms, with some **directed** corridors between rooms. Due to the Pale King's strange decorating habit (not referring to putting circular saws everywhere), for room $i$, it has a directed corridor to every room whose index lies in the interval $[l_i, r_i]$. For example, if room $4$ has directed corridors to $[2,5]$, it means there is a directed corridor from room $4$ to each of rooms $2, 3, 4, 5$ (a room may have a corridor to itself). If a room has corridors to $[0,0]$, it means there is no outgoing corridor from that room.

The Pale King asks $q$ questions. Each query asks for the number of ways to go from room $a$ to room $b$ using exactly $m$ directed corridors and without passing through room $c$ (two ways are different if and only if there exists an $i$ such that the $i$-th corridor used is different). Since this number can be very large, output the answer modulo $998244353$.

## 输入格式

The first line contains two integers $n, q$, representing the number of nodes and the number of queries.

The next $n$ lines each contain two integers $l, r$. The integers $l_i, r_i$ on the $(i+1)$-th line indicate that node $i$ has a directed edge to every node in the interval $[l_i, r_i]$. When $l_i=r_i=0$, it means this node has no outgoing edges.

The next $q$ lines each contain four integers $a, b, c, m$, representing one query.

## 输出格式

Output $q$ lines. Each line contains one integer. The $i$-th line is the number of ways for the $i$-th query modulo $998244353$.

## 输入输出样例 #1

### 输入 #1

```
4 5
2 3
1 1
2 4
0 0
1 3 4 5
1 4 2 4
2 3 1 2
4 4 3 0
1 3 2 5
```

### 输出 #1

```
5
1
0
1
1
```

## 输入输出样例 #2

### 输入 #2

```
10 10
6 6
4 10
2 5
1 7
3 4
5 7
4 10
1 7
1 3
2 5
8 8 5 1
4 7 5 3
5 9 4 4
1 5 5 2
6 2 10 2
3 3 7 4
1 10 1 2
6 2 4 4
9 2 1 4
9 10 3 2
```

### 输出 #2

```
0
17
2
0
0
46
0
12
23
1
```

## 输入输出样例 #3

### 输入 #3

```
10 10
2 6
6 9
5 7
3 9
0 0
0 0
3 5
5 5
3 6
1 10
5 9 6 3
10 8 6 4
10 8 5 1
8 6 5 4
7 2 5 4
6 1 5 3
10 4 5 1
5 5 6 0
7 9 6 4
4 9 6 2
```

### 输出 #3

```
0
17
1
0
0
0
1
1
4
1
```

## 说明/提示

### Sample Explanation

In sample 1, room $1$ can reach rooms $2, 3$. Room $2$ can reach room $1$. Room $3$ can reach rooms $2, 3, 4$. Room $4$ cannot reach any room.

For the first query, the ways to go from room $1$ to room $3$ using $5$ corridors and not passing through room $4$ are `121213`, `121333`, `133213`, `132133`, `133333`, totaling five ways.

---

### Constraints

**This problem uses bundled testdata.**

| ID | Special Property | Memory Limit | Score |
| :-: | :-: | :-: | :-: |
| 0 | $n\le10$，$q\le10$，$m\le4$ | 256MB | 10pts |
| 1 | $n\le100$，$q\le10^4$，$m\le40$ | 256MB | 15pts |
| 2 | For all queries, $l_c=r_c=0$ | 256MB | 15pts |
| 3 | None | 256MB | 30pts |
| 4 | None | 128MB | 30pts |

For $100\%$ of the data, $1\le n \le 500$, $1\le q \le 10^5$, $1\le m \le 100$, $0 \le l_i \le r_i \le n$, $1 \le a,b,c \le n$. $r_i=0$ if and only if $l_i=0$. The time limit is 1s for all subtasks.

---

### Hint

**Pay attention to the memory constant factors.**

Translated by ChatGPT 5