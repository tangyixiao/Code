# P1535 [USACO08MAR] Cow Travelling S

## 题目描述

奶牛们在被划分成 $N$ 行 $M$ 列（$2 \leq N,M \leq 100$）的草地上游走， 试图找到整块草地中最美味的牧草。

Farmer John 在某个时刻看见贝茜在位置 $(R_1, C_1)$，恰好 $T$（$0 \lt T \leq 15$）秒后，FJ 又在位置 $(R_2, C_2)$ 与贝茜撞了正着。FJ 并不知道在这 $T$ 秒内贝茜是否曾经到过 $(R_2, C_2)$，他能确定的只是，现在贝茜在那里。

设 $S$ 为奶牛在 $T$ 秒内从 $(R_1, C_1)$ 走到 $(R_2, C_2)$ 所能选择的路径总数，FJ 希望有一个程序来帮他计算这个值。每一秒内，奶牛会水平或垂直地移动 $1$ 单位距离（奶牛总是在移动，不会在某秒内停在它上一秒所在的点）。草地上的某些地方有树，自然，奶牛不能走到树所在的位置，也不会走出草地。

现在你拿到了一张整块草地的地形图，其中 `.` 表示平坦的草地，`*` 表示挡路的树。你的任务是计算出，一头在正好 $T$ 秒从 $(R_1, C_1)$ 移动到 $(R_2, C_2)$ 的奶牛可能经过的路径有哪些。

## 输入格式

第一行包含 $3$ 个用空格隔开的整数：$N,M,T$。

接下来 $N$ 行：第 $i$ 行为 $M$ 个连续的字符，描述了草地第 $i$ 行各点的情况，保证字符是 `.` 和 `*` 中的一个。

最后一行 $4$ 个整数 $R_1,C_1,R_2,C_2$。

## 输出格式

输出从 $(R_1, C_1)$ 移动到 $(R_2, C_2)$ 的方案数。

## 输入输出样例 #1

### 输入 #1

```
4 5 6
...*.
...*.
.....
.....
1 3 1 5
```

### 输出 #1

```
1

```

## 说明/提示

奶牛在正好 $6$ 秒从 $(1,3)$ 走到 $(1,5)$ 的方法只有一种，绕过她面前的树。

---

# P1535 [USACO08MAR] Cow Travelling S

## 题目描述

Cows wander on a pasture divided into $N$ rows and $M$ columns ($2 \leq N, M \leq 100$), trying to find the tastiest grass.

At some moment, Farmer John sees Bessie at position $(R_1, C_1)$. Exactly $T$ ($0 < T \leq 15$) seconds later, FJ runs into Bessie at position $(R_2, C_2)$. FJ does not know whether Bessie visited $(R_2, C_2)$ at any time during those $T$ seconds; he only knows that she is there now.

Let $S$ be the number of paths the cow can take to go from $(R_1, C_1)$ to $(R_2, C_2)$ in $T$ seconds. FJ wants a program to compute this value. Each second, the cow moves horizontally or vertically by a distance of $1$ (the cow is always moving and will not stay at the same point in any second). Some places on the pasture have trees. Of course, the cow cannot step on a tree, and she will not leave the pasture.

You are given a map of the whole pasture, where `.` means open grass and `*` means a blocking tree. Your task is to compute how many different paths a cow can take to move from $(R_1, C_1)$ to $(R_2, C_2)$ in $T$ seconds.

## 输入格式

The first line contains $3$ space-separated integers: $N, M, T$.

Then $N$ lines follow: the $i$-th line has $M$ consecutive characters describing row $i$ of the pasture. Each character is guaranteed to be either `.` or `*`.

The last line contains $4$ integers $R_1, C_1, R_2, C_2$.

## 输出格式

Output the number of ways to move from $(R_1, C_1)$ to $(R_2, C_2)$.

## 输入输出样例 #1

### 输入 #1

```
4 5 6
...*.
...*.
.....
.....
1 3 1 5
```

### 输出 #1

```
1

```

## 说明/提示

There is only one way for the cow to go from $(1, 3)$ to $(1, 5)$ in $6$ seconds, by going around the tree in front of her.

Translated by ChatGPT 5