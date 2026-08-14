# P3089 [USACO13NOV] Pogo-Cow S

## 题目描述

FJ 给奶牛贝西的脚安装上了弹簧，使它可以在农场里快速地跳跃，但是它还没有学会如何降低速度。

为了训练贝西更好地控制跳跃，FJ 在农场的一条笔直一维路径上设置了一个练习场。他在路径的不同位置放置了 $N$ 个目标点 $(1 \le N \le 1000)$，贝西需要尝试落在这些点上。目标点 $i$ 的位置坐标为 $x_i$，如果贝西落在上面，就能获得 $p_i$ 分。

贝西可以从任意一个目标点开始起跳，并且只能朝一个方向移动（向左或向右），从一个目标点跳到另一个目标点。每次跳跃的距离必须大于等于上一次跳跃的距离，而且必须落在目标点上。

每跳到一个目标点，贝西可以拿到该点的得分。请计算他的最大可能得分。

## 输入格式

- 第一行，一个整数 $N$。

- 第二行到第 $N+1$ 行，第 $i+1$ 行包含两个整数 $x_i$ 和 $p_i$，其中 $0 \le x_i, p_i \le 10^6$。

## 输出格式

- 一行一个整数，表示贝西的最大得分。

## 输入输出样例 #1

### 输入 #1

```
6 
5 6 
1 1 
10 5 
7 6 
4 8 
8 10 

```

### 输出 #1

```
25 

```

## 说明/提示

有 $6$ 个目标点。第一个目标点位于位置 $x=5$，价值 $6$ 分，依此类推。

贝西从位置 $x=4$（$8$ 分）跳到位置 $x=5$（$6$ 分），再跳到位置 $x=7$（$6$ 分），最后跳到位置 $x=10$（$5$ 分）。共计 $25$ 分。

### 数据规模与约定

- $1 \le N \le 1000$
- $0 \le x_i, p_i \le 10^6$

---

# P3089 [USACO13NOV] Pogo-Cow S

## 题目描述

In an ill-conceived attempt to enhance the mobility of his prize cow Bessie, Farmer John has attached a pogo stick to each of Bessie's legs. Bessie can now hop around quickly throughout the farm, but she has not yet learned how to slow down.

To help train Bessie to hop with greater control, Farmer John sets up a practice course for her along a straight one-dimensional path across his farm. At various distinct positions on the path, he places N targets (1 ≤ N ≤ 1000) on which Bessie should try to land. Target i is located at position x(i), and is worth p(i) points if Bessie lands on it. Bessie starts at the location of any target of her choosing and is allowed to move in only one direction, hopping from target to target. Each hop must cover at least as much distance as the previous hop, and must land on a target.

Bessie receives credit for every target she touches (including the initial target on which she starts). Please compute the maximum number of points she can obtain.

## 输入格式

* Line 1: The integer N.
* Lines 2..1+N: Line i+1 contains x(i) and p(i), each an integer in the range 0..1,000,000.

## 输出格式

* Line 1: The maximum number of points Bessie can receive.

## 输入输出样例 #1

### 输入 #1

```
6 
5 6 
1 1 
10 5 
7 6 
4 8 
8 10 

```

### 输出 #1

```
25 

```

## 说明/提示

There are 6 targets. The first is at position x = 5 and is worth 6 points, and so on.

Bessie hops from position x = 4 (8 points) to position x = 5 (6 points) to position x = 7 (6 points) to position x = 10 (5 points).

Translated by ChatGPT 5