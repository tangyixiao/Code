# P2860 [USACO06JAN] Redundant Paths G

## 题目描述

贝西和其他牛需要在 $F(1\le F\le 5,000)$ 个牧场间移动（编号为 $1$ 到 $F$）。他们厌倦了走某些特定的路径，因而想要修建一些新路，使得在任意一对牧场之间总有至少两条路线可供选择。目前在每对牧场之间至少有一条路径。当然，他们只能在官方道路上移动。

当前有 $R(F-1\le R\le 10,000)$ 条道路，每条道路连接两个不同的牧场。请你确定必须修建的最小道路数量（每条新道路也要连接两个不同的牧场），使得在任意一对牧场之间至少有两条路线。两条路线只要没有使用同一条道路就被视为合法的（即使经过了相同的牧场）。

在同一对牧场之间可能已有多条路径。修建的新路可以与某条现有道路连接一对相同的牧场。

## 输入格式

第 $1$ 行：两个用空格分隔的整数：$F$ 和 $R$。

第 $2$ 行到第 $R+1$ 行：每行包含两个用空格分隔的整数，表示某条路径连接的两个牧场。

## 输出格式

一行一个整数，表示必须修建的新路径数量。

## 输入输出样例 #1

### 输入 #1

```
7 7
1 2
2 3
3 4
2 5
4 5
5 6
5 7
```

### 输出 #1

```
2
```

## 说明/提示

样例解释：

初始路径如下：

![](https://cdn.luogu.com.cn/upload/image_hosting/cubnel5k.png)

可以在 $1$ 和 $6$ ， $4$ 和 $7$ 间修建新路。

![](https://cdn.luogu.com.cn/upload/image_hosting/rgguiytp.png)

一些例子：

- $1 - 2$：$1 \to2$ 或 $1 \to6 \to5 \to2$
- $1 - 4$：$1 \to2 \to3 \to4$ 或 $1 \to6 \to5 \to4$
- $3 - 7$：$3 \to4 \to7$ 或 $3 \to2 \to5 \to7$

可以发现，每对牧场之间都有至少两条路径。

其他道路修建方式也可能解决问题（例如从 $6$ 到 $7$ 的道路），但是添加两条是最少的。

（由 ChatGPT 4o 翻译并人工整改）

---


# P2860 [USACO06JAN] Redundant Paths G

## 题目描述

In order to get from one of the $F$ ($1 \le F \le 5\times 10^3$) grazing fields (which are numbered $1$ to $F$) to another field, Bessie and the rest of the herd are forced to cross near the Tree of Rotten Apples.  The cows are now tired of often being forced to take a particular path and want to build some new paths so that they will always have a choice of at least two separate routes between any pair of fields. They currently have at least one route between each pair of fields and want to have at least two. Of course, they can only travel on Official Paths when they move from one field to another.


Given a description of the current set of $R$ ($F-1 \le R \le 1\times 10^4$) paths that each connect exactly two different fields, determine the minimum number of new paths (each of which connects exactly two fields) that must be built so that there are at least two separate routes between any pair of fields. Routes are considered separate if they use none of the same paths, even if they visit the same intermediate field along the way.


There might already be more than one paths between the same pair of fields, and you may also build a new path that connects the same fields as some other path.

## 输入格式

Line $1$: Two space-separated integers: $F$ and $R$.




Lines $2$ to $R+1$: Each line contains two space-separated integers which are the fields at the endpoints of some path.

## 输出格式

Line $1$: A single integer that is the number of new paths that must be built.

## 输入输出样例 #1

### 输入 #1

```
7 7
1 2
2 3
3 4
2 5
4 5
5 6
5 7
```

### 输出 #1

```
2
```

## 说明/提示

Explanation of the sample:




One visualization of the paths is:

![](https://cdn.luogu.com.cn/upload/image_hosting/cubnel5k.png)

Building new paths from $1$ to $6$ and from $4$ to $7$ satisfies the conditions.

![](https://cdn.luogu.com.cn/upload/image_hosting/rgguiytp.png)

Check some of the routes:

- $1$ – $2$:  $1 \to 2$ and $1 \to 6 \to 5 \to 2$.
- $1$ – $4$:  $1 \to 2 \to 3 \to 4$ and $1 \to 6 \to 5 \to 4$.
- $3$ – $7$:  $3 \to 4 \to 7$ and $3 \to 2 \to 5 \to 7$.

Every pair of fields is, in fact, connected by two routes.

It's possible that adding some other path will also solve the problem (like one from $6$ to $7$). Adding two paths, however, is the minimum.