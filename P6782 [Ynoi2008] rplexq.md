# P6782 [Ynoi2008] rplexq

## 题目描述

给定一棵 $n$ 个节点的有根树，第 $i$ 个点的编号是 $i$。

有 $m$ 次询问，每次询问给出 $l,r,x$，求有多少点编号的二元组 $(i,j)$ 满足 $l \le i < j \le r$ 且 $i$ 和 $j$ 的最近公共祖先是节点 $x$。

## 输入格式

第一行三个数 $n$ $m$ $rt$，其中 $rt$ 表示根节点的编号。

之后 $n-1$ 行，每行两个数 $u$ $v$ 表示一条边。

之后 $m$ 行，每行三个数 $l$ $r$ $x$ 表示一次询问。

## 输出格式

共 $m$ 行，表示每个询问对应的答案

## 输入输出样例 #1

### 输入 #1

```
10 10 7
4 2
10 4
3 2
6 10
9 2
7 3
1 4
8 2
5 3
8 10 10
2 6 2
3 6 2
4 6 4
3 10 2
8 8 10
3 10 4
2 3 2
2 6 4
1 7 10
```

### 输出 #1

```
0
2
0
1
7
0
2
0
1
0
```

## 说明/提示

Idea：Ynoi，Solution：nzhtl1477，Code：nzhtl1477，Data：nzhtl1477

对于 $100\%$ 的数据，$1\le n,m\le 2\cdot 10^5$，$1 \le l,r,x \le n$。

#### 样例解释 ####

`2 6 2`：符合条件的有 $(2,4)$，$(2,6)$。

`4 6 4`：符合条件的有 $(4,6)$ 。

`3 10 2`：符合条件的有 $(4,8)$ ，$(4,9)$，$(6,8)$，$(6,9)$，$(8,9)$，$(8,10)$，$(9,10)$。

`3 10 4`：符合条件的有 $(4,6)$，$(4,10)$。

`2 6 4`：符合条件的有 $(4,6)$。


---

# P6782 [Ynoi2008] rplexq

## 题目描述

Given a rooted tree with $n$ nodes, the index of node $i$ is $i$.

There are $m$ queries. Each query gives $l, r, x$. You need to count how many pairs of node indices $(i, j)$ satisfy $l \le i < j \le r$, and the lowest common ancestor of $i$ and $j$ is node $x$.

## 输入格式

The first line contains three integers $n$ $m$ $rt$, where $rt$ is the index of the root node.

The next $n - 1$ lines each contain two integers $u$ $v$, representing an edge.

The next $m$ lines each contain three integers $l$ $r$ $x$, representing a query.

## 输出格式

Output $m$ lines. Each line is the answer to the corresponding query.

## 输入输出样例 #1

### 输入 #1

```
10 10 7
4 2
10 4
3 2
6 10
9 2
7 3
1 4
8 2
5 3
8 10 10
2 6 2
3 6 2
4 6 4
3 10 2
8 8 10
3 10 4
2 3 2
2 6 4
1 7 10
```

### 输出 #1

```
0
2
0
1
7
0
2
0
1
0
```

## 说明/提示

Idea: Ynoi, Solution: nzhtl1477, Code: nzhtl1477, Data: nzhtl1477.

Constraints: for $100\%$ of the testdata, $1 \le n, m \le 2 \cdot 10^5$, $1 \le l, r, x \le n$.

#### Sample Explanation ####

`2 6 2`: the valid pairs are $(2,4)$, $(2,6)$.

`4 6 4`: the valid pair is $(4,6)$.

`3 10 2`: the valid pairs are $(4,8)$, $(4,9)$, $(6,8)$, $(6,9)$, $(8,9)$, $(8,10)$, $(9,10)$.

`3 10 4`: the valid pairs are $(4,6)$, $(4,10)$.

`2 6 4`: the valid pair is $(4,6)$.

Translated by ChatGPT 5