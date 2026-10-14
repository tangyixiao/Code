# P1529 [USACO2.4] 回家 Bessie Come Home

## 题目描述

现在是晚餐时间，而母牛们在外面分散的牧场中。 

Farmer John 按响了电铃，所以她们开始向谷仓走去。 你的工作是要指出哪只母牛会最先到达谷仓（在给出的测试数据中，总会**有且只有**一只最快的母牛）。在挤奶的时候（晚餐前），每只母牛都在她自己的牧场上，一些牧场上可能没有母牛。

每个牧场由一条条道路和一个或多个牧场连接（可能包括自己）。有时，两个牧场（可能是字母相同的）之间会有超过一条道路相连。至少有一个牧场和谷仓之间有道路连接。因此，所有的母牛最后都能到达谷仓，并且母牛总是走最短的路径。当然，母牛能向着任意一方向前进，并且她们以相同的速度前进。牧场被标记为 $\texttt{a} \ldots \texttt{z}$ 和 $\texttt{A} \ldots \texttt{Y}$，在用大写字母表示的牧场中有一只母牛，小写字母中则没有。 谷仓的标记是 $\texttt{Z}$，注意没有母牛在谷仓中。

**注意 $\texttt{m}$ 和 $\texttt{M}$ 不是同一个牧场**。

## 输入格式

第一行一个整数 $P$（$1\leq P \leq 10^4$），表示连接牧场（谷仓）的道路的数目。

接下来 $P$ 行，每行用空格分开的两个字母和一个正整数：被道路连接牧场的标号和道路的长度（道路长度均不超过 $10^3$）。

## 输出格式

单独的一行包含 $2$ 个结果：最先到达谷仓的母牛所在的牧场的标号，和这只母牛走过的路径的长度。

## 输入输出样例 #1

### 输入 #1

```
5
A d 6
B d 3
C e 9
d Z 8
e Z 3
```

### 输出 #1

```
B 11

```

## 说明/提示

翻译来自 NOCOW

USACO 2.4

---

# P1529 [USACO2.4] Bessie Come Home

## 题目描述

It is dinnertime, and the cows are out in scattered pastures. Farmer John rings the electric bell, so they start heading to the barn. Your job is to determine which cow will reach the barn first (in the given testdata, there is always exactly one fastest cow). At milking time (before dinner), each cow is in her own pasture; some pastures may have no cows.

Each road connects a pair of pastures (possibly the same pasture). Sometimes, more than one road connects the same pair of pastures. At least one pasture is connected to the barn by a road. Therefore, all cows can eventually reach the barn, and cows always take the shortest paths. Of course, cows can travel in either direction, and they all travel at the same speed. Pastures are labeled $\texttt{a} \ldots \texttt{z}$ and $\texttt{A} \ldots \texttt{Y}$. Each uppercase-labeled pasture contains one cow, while lowercase-labeled pastures contain no cows. The barn is labeled $\texttt{Z}$; note that there is no cow in the barn.

**Note that $\texttt{m}$ and $\texttt{M}$ are not the same pasture.**

## 输入格式

The first line contains an integer $P$ ($1 \leq P \leq 10^4$), the number of roads connecting pastures and the barn.

Each of the next $P$ lines contains two letters and a positive integer, separated by spaces: the labels of the two pastures connected by the road, and the length of that road (each road length is at most $10^3$).

## 输出格式

A single line containing two items: the label of the pasture where the cow that reaches the barn first starts, and the length of that cow’s path.

## 输入输出样例 #1

### 输入 #1

```
5
A d 6
B d 3
C e 9
d Z 8
e Z 3
```

### 输出 #1

```
B 11

```

## 说明/提示

Translated from NOCOW.

USACO 2.4.

Translated by ChatGPT 5