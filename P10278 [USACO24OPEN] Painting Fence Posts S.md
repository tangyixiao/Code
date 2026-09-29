# P10278 [USACO24OPEN] Painting Fence Posts S

## 题目背景

**注意：本题的时间限制和内存限制为 3 秒 和 512MB，分别为通常限制的 1.5 倍和 2 倍。**

## 题目描述

Farmer John 的 $N$ 头奶牛（$1\le N\le 10^5$）每头都喜欢日常沿围着牧场的栅栏散步。不幸的是，每当一头奶牛走过栅栏柱子时，她就会碰到它，这要求 Farmer John 需要定期重新粉刷栅栏柱子。

栅栏由 $P$ 根柱子组成（$4\le P\le 2\cdot 10^5$，$P$ 为偶数），每根柱子的位置是 FJ 农场地图上的一个不同的二维坐标点 $(x,y)$（$0\le x,y\le 10^9$）。每根柱子通过垂直或水平线段的栅栏连接到两根相邻的柱子，因此整个栅栏可以被视为各边平行于 $x$ 轴或 $y$ 轴的一个多边形（最后一根柱子连回第一根柱子，确保围栏形成一个包围牧场的闭环）。栅栏多边形是「规则的」，体现在栅栏段仅可能在其端点处重合，每根柱子恰好属于两个栅栏段，同时每两个在端点处相交的栅栏段都是垂直的。

每头奶牛的日常散步都有一个偏好的起始和结束位置，均为沿栅栏的某个点（可能在柱子处，也可能不在）。每头奶牛日常散步时沿着栅栏行走，从起始位置开始，到结束位置结束。由于栅栏形成闭环，奶牛有两条路线可以选择。由于奶牛是一种有点懒的生物，每头奶牛都会选择距离较短的方向沿栅栏行走。值得注意的是，这个选择总是明确的——不存在并列的情况！

一头奶牛会触碰一根栅栏柱子，当她走过这根柱子，或者当这根栅栏柱子是她散步的起点或终点时。请帮助 FJ 计算每个栅栏柱子每天所经历的触碰次数，以便他知道接下来要重新粉刷哪根柱子。

可以证明，给定所有柱子的位置，组成的栅栏仅有唯一的可能性。

## 输入格式

输入的第一行包含 $N$ 和 $P$。以下 $P$ 行的每一行包含两个整数，表示栅栏柱子的位置，没有特定的顺序。以下 $N$ 行的每一行包含四个整数 $x_1\ y_1\ x_2\ y_2$，表示一头奶牛的起始位置 $(x_1,y_1)$ 和结束位置 $(x_2,y_2)$。

## 输出格式

输出 $P$ 个整数，包含每个栅栏柱子所经历的触碰次数。

## 输入输出样例 #1

### 输入 #1

```
5 4
3 1
1 5
3 5
1 1
2 1 1 5
1 5 3 4
3 1 3 5
2 1 2 1
3 2 3 3
```

### 输出 #1

```
1
2
2
1
```

## 输入输出样例 #2

### 输入 #2

```
2 8
1 1
1 2
0 2
0 3
0 0
0 1
2 3
2 0
1 1 2 1
1 0 1 3
```

### 输出 #2

```
1
0
0
0
1
1
1
2
```

## 输入输出样例 #3

### 输入 #3

```
1 12
0 0
2 0
2 1
1 1
1 2
3 2
3 3
1 3
1 4
2 4
2 5
0 5
2 2 0 2
```

### 输出 #3

```
1
1
1
1
1
0
0
0
0
0
0
0
```

## 说明/提示

### 样例解释 1

柱子以如下方式由栅栏段连接：

$$
(3,1)\leftrightarrow(3,5)\leftrightarrow(1,5)\leftrightarrow(1,1)\leftrightarrow(3,1)
$$

各奶牛接触的柱子如下：

1. 柱子 $2$ 和 $4$。
2. 柱子 $2$ 和 $3$。
3. 柱子 $1$ 和 $3$。
4. 无。
5. 无。

### 测试点性质

- 测试点 $4-6$：$N,P\le 1000$。
- 测试点 $7-9$：所有位置均有 $0\le x,y\le 1000$。
- 测试点 $10-15$：没有额外限制。

---

# P10278 [USACO24OPEN] Painting Fence Posts S

## 题目描述

****Note: The time limit and memory limit for this problem are 3s and 512MB, which are 1.5x and 2x the normal amount, respectively.****  

Farmer John's $N$ cows ($1 \leq N \leq 10^5$) each like to take a daily walk around the fence enclosing his pasture.  Unfortunately, whenever a cow walks past a fence post, she brushes up against it, requiring Farmer John to need to repaint the fence posts regularly.  

The fence consists of $P$ posts ($4 \leq P \leq 2\cdot 10^5$, $P$ even), the location of each being a different 2D point $(x,y)$ on a map of FJ's farm ($0 \leq x, y \leq 10^9$).  Each post is connected to the two adjacent posts by fences that are either vertical  or horizontal line segments, so the entire fence can be considered a polygon whose sides are parallel to the x or y axes (the last post connects back to the first post, ensuring the fence forms a closed loop that encloses the pasture).  The fence polygon is "well-behaved" in that fence segments only potentially overlap at their endpoints, each post aligns with exactly  two fence segment endpoints, and every two fence segments that meet at an endpoint are perpendicular.   

Each cow has a preferred starting and ending position for her daily walk, each being points somewhere along the fence (possibly at posts, possibly not).  Each cow walks along the fence for her daily walks, starting from her starting position and ending at her ending position.  There are two routes that the cow could take, given that the fence forms a closed loop.  Since cows are somewhat lazy creatures, each cow will walk in the direction around the fence that is shorter. Remarkably, this choice is always clear -- there are no ties!  

A cow touches a fence post if she walks past it, or if the fence post is the starting or ending point of her walk.  Please help FJ calculate the number of daily touches experienced by each fence post, so he knows which post to repaint next.  

It can be shown that there is exactly one possibility for the fences given the locations of all of the posts.

## 输入格式

The first line of input contains $N$ and $P$. Each of the next $P$ lines contains two integers representing the positions of the fence posts in no particular order. Each of the next $N$ lines contains four integers $x_1$ $y_1$ $x_2$ $y_2$ representing the starting position $(x_1, y_1)$ and ending position $(x_2, y_2)$ of a cow.

## 输出格式

Write $P$ integers as output, giving the number of touches experienced by each fence post.

## 输入输出样例 #1

### 输入 #1

```
5 4
3 1
1 5
3 5
1 1
2 1 1 5
1 5 3 4
3 1 3 5
2 1 2 1
3 2 3 3
```

### 输出 #1

```
1
2
2
1
```

## 输入输出样例 #2

### 输入 #2

```
2 8
1 1
1 2
0 2
0 3
0 0
0 1
2 3
2 0
1 1 2 1
1 0 1 3
```

### 输出 #2

```
1
0
0
0
1
1
1
2
```

## 输入输出样例 #3

### 输入 #3

```
1 12
0 0
2 0
2 1
1 1
1 2
3 2
3 3
1 3
1 4
2 4
2 5
0 5
2 2 0 2
```

### 输出 #3

```
1
1
1
1
1
0
0
0
0
0
0
0
```

## 说明/提示

##### For Sample 1:
The following posts are connected by fence segments:  

$$(3,1)\leftrightarrow (3, 5) \leftrightarrow  (1,5) \leftrightarrow (1,1) \leftrightarrow (3,1)$$  

The posts touched by each cow are as follows:  

1. Posts $2$ and $4$.
1. Posts $2$ and $3$.
1. Posts $1$ and $3$.
1. No posts.
1. No posts.  

#### SCORING:
- Inputs 4-6: $N,P\le 1000$
- Inputs 7-9: All locations satisfy $0\le x, y\le 1000$.
- Inputs 10-15: No additional constraints.