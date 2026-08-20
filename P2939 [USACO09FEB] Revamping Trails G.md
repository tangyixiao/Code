# P2939 [USACO09FEB] Revamping Trails G

## 题目描述

农夫约翰每天都会认真检查他的奶牛。他会穿越一些编号为 $1$ 到 $M$ 的小径（$1 \leq M \leq 50,000$），从牧场 $1$ 一直走到牧场 $N$（对于测试数据给出的路径图，这段旅程总是可能的）。农夫约翰的农场上有 $N$ 个牧场（$1 \leq N \leq 10,000$），它们通过双向泥土小径连接在一起。每条小径 $i$ 连接牧场 $P1_i$ 和 $P2_i$（$1 \leq P1_i \leq N,1 \leq P2_i \leq N$），需要 $T_i$（$1 \leq T_i \leq 10^6$）单位时间来穿越。

他想要改造农场上的一些小径，以节省长途旅行的时间。具体来说，他将选择 $K$（$1 \leq K \leq 20$）条小径将其改造成高速公路，这将有效地将小径的穿越时间减少到 $0$。帮助 FJ 决定改造哪些小径以最小化从牧场 $1$ 到 $N$ 的最终时间。

## 输入格式

* 第 $1$ 行：三个用空格分隔的整数：$N,M$ 和 $K$。

* 第 $2$ 行到第 $M+1$ 行：第 $i+1$ 行描述小径 $i$，包含三个用空格分隔的整数：$P1_i$、$P2_i$ 和 $T_i$。

## 输出格式

共 $1$ 行：改造不超过 $K$ 条边后的最短路径长度。

## 输入输出样例 #1

### 输入 #1

```
4 4 1 
1 2 10 
2 4 10 
1 3 1 
3 4 100 

```

### 输出 #1

```
1 

```

## 说明/提示

$K$ 为 $1$；将小径 $3 \to 4$ 改造成高速公路，时间从 $100$ 变为 $0$。新的最短路径为 $1 \to 3 \to 4$，总穿越时间现在为 $1$。

---

# P2939 [USACO09FEB] Revamping Trails G

## 题目描述

Farmer John dutifully checks on the cows every day. He traverses some of the M (1 <= M <= 50,000) trails conveniently numbered 1..M from pasture 1 all the way out to pasture N (a journey which is always possible for trail maps given in the test data). The N (1 <= N <= 10,000) pastures conveniently numbered 1..N on Farmer John's farm are currently connected by bidirectional dirt trails.  Each trail i connects pastures P1\_i and P2\_i (1 <= P1\_i <= N; 1 <= P2\_i <= N) and requires T\_i (1 <= T\_i <= 1,000,000) units of time to traverse.

He wants to revamp some of the trails on his farm to save time on his long journey. Specifically, he will choose K (1 <= K <= 20) trails to turn into highways, which will effectively reduce the trail's traversal time to 0. Help FJ decide which trails to revamp to minimize the resulting time of getting from pasture 1 to N.

TIME LIMIT: 2 seconds

## 输入格式

\* Line 1: Three space-separated integers: N, M, and K

\* Lines 2..M+1: Line i+1 describes trail i with three space-separated integers: P1\_i, P2\_i, and T\_i

## 输出格式

\* Line 1: The length of the shortest path after revamping no more than K edges

## 输入输出样例 #1

### 输入 #1

```
4 4 1 
1 2 10 
2 4 10 
1 3 1 
3 4 100 

```

### 输出 #1

```
1 

```

## 说明/提示

K is 1; revamp trail 3->4 to take time 0 instead of 100. The new shortest path is 1->3->4, total traversal time now 1.