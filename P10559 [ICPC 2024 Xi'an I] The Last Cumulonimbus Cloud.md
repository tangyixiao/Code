# P10559 [ICPC 2024 Xi'an I] The Last Cumulonimbus Cloud

## 题目描述

每年四月，这座城市总是被积雨云笼罩。

这座城市由 $n$ 座建筑和 $m$ 条双向街道连接。为了方便人们出行，任何两座建筑都可以通过街道直接或间接到达。同时，没有街道连接同一座建筑，并且每对建筑之间最多有一条街道连接。

由于城市布局不太庞大，这座城市的生活节奏非常缓慢。

具体来说，如果我们将这座城市视为无向图 $G$，则保证在该图的任何非空子图中，至少有一座建筑在子图内连接了最多 10 条街道。

雨不停地下，积雨云的数量不断增加。起初，第 $i$ 座建筑上方有 $a_i$ 个积雨云，但在接下来的 $q$ 天中，每天会发生以下两种事件之一：

- $\text{1 x v}$ 表示在第 $x$ 座建筑上方增加了 $v$ 个积雨云。
- $\text{2 x}$ 表示需要报告直接连接到建筑 $x$ 的所有建筑上方的积雨云总数。

## 输入格式

第一行包含三个整数 $n,m,q(1\le n\le 3\times 10^5,1\leq m\leq 3\times 10^6, 1\leq q\leq 2\times 10^6)$。

接下来的 $m$ 行中的每一行包含两个整数 $x,y(1\leq x,y\leq n,x \neq y)$，表示连接第 $x$ 座和第 $y$ 座建筑的街道。

接下来的 $n$ 行中的每一行包含一个整数 $a_i(0\leq a_i\leq 100)$。

接下来的 $q$ 行中的每一行包含两个或三个整数，如果第一个整数是 $1$，则表示第一种类型的事件，接下来的两个整数表示 $x,v(0\leq v\leq 100)$。如果第一个整数是 $2$，则表示第二种类型的事件，接下来的整数表示 $x$。

## 输出格式

多行，每行表示第二种类型事件的查询结果。

## 输入输出样例 #1

### 输入 #1

```
4 6 10
2 4
2 3
4 3
3 1
4 1
2 1
0
7
1
6
2 4
2 2
1 3 3
2 1
1 1 9
2 4
2 2
1 3 6
2 4
2 2
```

### 输出 #1

```
8
7
17
20
19
26
25
```

## 说明/提示

（由 ChatGPT 4o 翻译）

---

# P10559 [ICPC 2024 Xi'an I] The Last Cumulonimbus Cloud

## 题目描述

Every April, the city is always shrouded under cumulonimbus clouds.

This city is connected by $n$ buildings and $m$ two-way streets. In order to facilitate people's travel, any two buildings can directly or indirectly reach each other through the streets. At the same time, no street connects the same building, and there is at most one street that connects each pair of buildings.

The pace of life in this city is very slow because the city layout is not very bulky.

Specifically,if we consider this city as an undirected graph $G$ ,it is guaranteed that for any non empty subgraph in this graph,there is at least one building inside it that connects up to 10 streets within the subgraph.

The rain is not stopping, and the number of cumulonimbus clouds is constantly increasing. At the beginning, there are $a_i$ cumulonimbus clouds above the $i$ -th building, but in the following $q$ days, one of the following two events will occur every day:

- $\text{1 x v}$ $v$ cumulonimbus clouds have been added over the $x$ -th building.
- $\text{2 x}$ you need to report how many cumulonimbus clouds are in total over all buildings directly connected to building $x$.

## 输入格式

The first line contains three integers $n,m,q(1\le n\le 3\times 10^5,1\leq m\leq 3\times 10^6, 1\leq q\leq 2\times 10^6)$.

Each of the next $m$ lines contains two integers $x,y(1\leq x,y\leq n,x\neq y)$, which represents a street connecting the $x$ -th and $y$ -th buildings.

Each of the next $n$ lines contains an integer $a_i(0\leq a_i\leq 100)$.

Each of the next $q$ lines contains two or three integers, if the first integer is $1$, it represents a first type of event, and the next two integers represent $x,v(0\leq v\leq 100)$. If the first integer is $2$, it represents a second type of event, the next integer represents $x$.

## 输出格式

Several rows, each representing a query result for a second type of event.

## 输入输出样例 #1

### 输入 #1

```
4 6 10
2 4
2 3
4 3
3 1
4 1
2 1
0
7
1
6
2 4
2 2
1 3 3
2 1
1 1 9
2 4
2 2
1 3 6
2 4
2 2
```

### 输出 #1

```
8
7
17
20
19
26
25
```