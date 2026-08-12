# P6178 【模板】Matrix-Tree 定理

## 题目描述

给定一张 $n$ 个结点 $m$ 条边的带权图（可能为无向图，可能为有向图）。

定义其一个生成树 $T$ 的权值为 $T$ 中所有边权的乘积。

求其所有不同生成树的权值之和，对 $10^9+7$ 取模。

---

注意：

1. 本题中，有向图的生成树指的是 **以 $1$ 为根的外向树**；

2. 两棵生成树 $T_1,T_2$ 不同，当且仅当存在存在一条边 $e$，满足 $e\in T_1,\ \ e\notin T_2$。

## 输入格式

第一行：三个整数 $n,m,t$，分别表示图的结点数量，边的数量和图的类型（$t=0$ 时为无向图，$t=1$ 时为有向图）。

接下来 $m$ 行：每行三个整数 $u,v,w$。

如果 $t=0$，表示 $u,v$ 之间有一条权值为 $w$ 的无向边；

如果 $t=1$，表示从 $u$ 到 $v$ 有一条权值为 $w$ 的有向边。

## 输出格式

第一行：一个整数 $ans$，表示给定的图的生成树权值和对 $10^9+7$ 取模的结果。

## 输入输出样例 #1

### 输入 #1

```
5 8 0
2 3 1
1 2 3
4 5 1
4 2 2
3 5 2
3 4 3
3 4 1
3 3 5

```

### 输出 #1

```
144

```

## 输入输出样例 #2

### 输入 #2

```
5 9 1
1 2 3
3 2 1
1 3 1
2 4 2
3 5 1
4 3 4
3 5 1
5 4 1
4 4 6

```

### 输出 #2

```
72

```

## 说明/提示

【样例 $1$ 解释】

样例 $1$ 中的无向图如左图所示：

![](https://cdn.luogu.com.cn/upload/image_hosting/pxtx9z5a.png)

右图为其一个权值为 $3\times 1\times 2\times 3=18$ 的生成树的例子。

---

【样例 $2$ 解释】

样例 $2$ 中的有向图如左图所示：

![](https://cdn.luogu.com.cn/upload/image_hosting/4276yln3.png)

右图为其一个权值为 $1\times 1\times 1\times 2=2$ 的生成树（以 $1$ 为根的外向树）的例子。

---

【数据范围】

对于 $100\%$ 的数据：$1\leq n\leq 300,\ \ 1\leq m\leq 10^5,\ \ t\in \{0,1\},\ \ 1\leq u,v\leq n,\ \ 1\leq w\leq 10^9$。

对于测试点 $1,2,3,4,5,6$，$t=0$；对于测试点 $7,8,9,10,11$，$t=1$。

图中 **可能** 存在重边和自环，重边算作多条边。

---

# P6178 [Template] Matrix-Tree Theorem

## 题目描述

Given a weighted graph with $n$ vertices and $m$ edges (it may be undirected or directed).

Define the weight of a spanning tree $T$ as the product of the weights of all edges in $T$.

Find the sum of the weights of all distinct spanning trees, modulo $10^9+7$.

---

Notes:

1. In this problem, a spanning tree of a directed graph means an **out-arborescence rooted at $1$**.

2. Two spanning trees $T_1, T_2$ are different if and only if there exists an edge $e$ such that $e\in T_1$ and $e\notin T_2$.

## 输入格式

The first line contains three integers $n, m, t$, representing the number of vertices, the number of edges, and the type of the graph ($t=0$ for an undirected graph, $t=1$ for a directed graph).

The next $m$ lines each contain three integers $u, v, w$.

If $t=0$, it means there is an undirected edge between $u$ and $v$ with weight $w$.

If $t=1$, it means there is a directed edge from $u$ to $v$ with weight $w$.

## 输出格式

The first line contains one integer $ans$, which is the sum of spanning tree weights of the given graph modulo $10^9+7$.

## 输入输出样例 #1

### 输入 #1

```
5 8 0
2 3 1
1 2 3
4 5 1
4 2 2
3 5 2
3 4 3
3 4 1
3 3 5

```

### 输出 #1

```
144

```

## 输入输出样例 #2

### 输入 #2

```
5 9 1
1 2 3
3 2 1
1 3 1
2 4 2
3 5 1
4 3 4
3 5 1
5 4 1
4 4 6

```

### 输出 #2

```
72

```

## 说明/提示

[Sample $1$ Explanation]

The undirected graph in sample $1$ is shown in the left figure:

![](https://cdn.luogu.com.cn/upload/image_hosting/pxtx9z5a.png)

The right figure shows an example spanning tree with weight $3\times 1\times 2\times 3=18$.

---

[Sample $2$ Explanation]

The directed graph in sample $2$ is shown in the left figure:

![](https://cdn.luogu.com.cn/upload/image_hosting/4276yln3.png)

The right figure shows an example spanning tree (an out-arborescence rooted at $1$) with weight $1\times 1\times 1\times 2=2$.

---

[Constraints]

For $100\%$ of the testdata: $1\leq n\leq 300,\ \ 1\leq m\leq 10^5,\ \ t\in \{0,1\},\ \ 1\leq u,v\leq n,\ \ 1\leq w\leq 10^9$.

For test points $1,2,3,4,5,6$, $t=0$; for test points $7,8,9,10,11$, $t=1$.

The graph **may** contain multiple edges and self-loops. Multiple edges are counted as different edges.

Translated by ChatGPT 5