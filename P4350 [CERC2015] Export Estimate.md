# P4350 [CERC2015] Export Estimate

## 题目背景

Luka 经营一家地理数据公司，负责维护详细的城市地图，并将数据导出给有需求的客户。通常客户不需要完整地图，而是希望获得仅包含主要街道的简化地图。

## 题目描述

城市地图是一个无向图，包含编号 $1$ 到 $n$ 的 $n$ 个交叉路口和 $m$ 条双向街道。每条街道都有一个非负整数的优先级。当客户请求地图时，会指定一个优先级阈值 $p$。原始地图会经过以下处理流程生成导出地图：

1. 所有优先级小于 $p$ 的街道被删除；  
2. 按顺序处理每个交叉路口 $i$（从 $1$ 到 $n$ 依次处理）：

   (a) 如果这个路口没有连接到任何街道，它就会被删除。

   (b) 如果路口 $i$ 恰好连接两条不同街道 $x$ 和 $y$（分别通向不同于 $i$ 的路口 $a$ 和 $b$），则按以下步骤进行收缩：

   i.删除道路 $x$ 和道路 $y$；

   ii.删除路口 $i$；

   iii.加入一条连接路口 $a$ 和 $b$ 的新道路 $z$；

![](https://cdn.luogu.com.cn/upload/pic/16236.png)

最初，图中没有环（即一条连接到自身的边）或者平行的边（即在同一对交点之间有一条以上的边），但在收缩的过程中可能会形成环和平行边。

请注意，在步骤 2.(b) 之前，$x$ 和 $y$ 都不能是环（即 $a$ 和 $b$ 必须和 $i$ 不同），但是新增的 $z$ 可以是一个环（即 $a$ 和 $b$ 可能是相同的）。

给定地图和一系列导出请求，对每个请求计算导出地图中的路口数量和街道数量。

## 输入格式

第一行包含两个整数 $n(1 \le n\le3\times10^5)$ 和 $m(1\le m\le 3\times10^5)$ 分别是点和边的数量。

后面 $m$ 行包含三个整数分别是 $a,b$ 和 $p(1\le a,b \le n,0\le p\le 3\times10^5)$ 用来描述 $a,b$ 之间边的优先级 $p$，没有一条边只连接一个点，两个点之间最多有一条边。

第 $m+2$ 行包含一个整数 $q(1\le q\le 3\times10^5)$ 表示询问的个数，下一行有 $q$ 个整数，第 $k$ 个整数 $t_k(0\le t_k\le 3\times10^5)$ 是第 $k$ 次询问的优先级。

## 输出格式

输出包括 $q$ 行。第 $k$ 行包含两个整数，分别是第 $k$ 次询问的点和边的个数。

## 输入输出样例 #1

### 输入 #1

```
6 7 
1 2 20 
2 3 80 
2 5 100 
3 5 50 
3 4 100 
5 6 90 
4 6 100 
4 
25 75 85 95
```

### 输出 #1

```
2 3 
1 1 
2 1 
4 2

```

## 输入输出样例 #2

### 输入 #2

```
10 14 
2 7 150 
1 2 100 
2 3 150 
3 1 200 
1 4 60 
4 5 20 
2 5 100 
5 6 90 
6 7 120 
7 5 130 
6 8 50 
8 9 200 
9 10 200 
10 7 200 
5 
300 50 95 100 110
```

### 输出 #2

```
0 0 
6 9 
4 5 
4 5 
5 4
```

## 说明/提示

Central Europe Regional Contest 2015 Problem E


---

# P4350 [CERC2015] Export Estimate

## 题目背景

Luka owns a geographic data company that maintains a detailed city map and exports the data to interested parties. Often, clients do not want the complete map. Instead, they want a simpliﬁed map containing only major streets.

## 题目描述

City map is an undirected graph consisting of n intersections denoted with integers from 1 to n and m two-way streets. Each street is assigned a priority – a non-negative integer. When requesting a map, the client selects a threshold priority p. The original map is then copied and converted to the exported map using the following procedure:

1. All streets whose priority is lower than p are deleted. 

2. For each intersection i from 1,2,...,n (processed in that order): 

(a) If the intersection i is not connected to any streets it is deleted. 

(b) If the intersection i is connected to exactly two different streets x and y leading to intersections a and b both different from i then the intersection i is contracted using the following procedure: 

i. Streets x and y are deleted. 

ii. Intersection i is deleted. 

iii. New street z connecting intersections a and b is added.

![](https://cdn.luogu.com.cn/upload/pic/16236.png )

Initially, the map does not contain loops (loop is a street that connects an intersection to itself) or parallel edges (more than one street between the same pair of intersections), but the loops and parallel edges may form during the contraction procedure. Notice that, in the step 2. (b) above, neither x nor y can be a loop (both a and b have to be different from i), but the newly added street z could be a loop (it is possible that a and b are same). 

Given a map and a sequence of incoming export requests, for each request ﬁnd the number of intersections and the number of streets in the exported map.

## 输入格式

The ﬁrst line contains two integers n (1 ≤ n ≤ 300000) and m (1 ≤ m ≤ 300000) – the number of intersections and the number of streets, respectively. Each of the following m lines contains three integers a, b and p (1≤ a,b≤n,0≤ p≤300000) which describe a street with priority p connecting intersections a and b. No street connects an intersection to itself. There is at most one street between every two intersections. 

The following line contains an integer q (1 ≤ q ≤ 300000) – the number of export requests. The following line contains q integers. The k-th integer tk (0≤tk ≤300000) is the threshold priority of the k-th request.

## 输出格式

Output should consist of q lines. The k-th line should contain two integers–the number of intersections and the number of streets, respectively, in the exported map for the k-th request.

## 输入输出样例 #1

### 输入 #1

```
6 7 
1 2 20 
2 3 80 
2 5 100 
3 5 50 
3 4 100 
5 6 90 
4 6 100 
4 
25 75 85 95
```

### 输出 #1

```
2 3 
1 1 
2 1 
4 2

```

## 输入输出样例 #2

### 输入 #2

```
10 14 
2 7 150 
1 2 100 
2 3 150 
3 1 200 
1 4 60 
4 5 20 
2 5 100 
5 6 90 
6 7 120 
7 5 130 
6 8 50 
8 9 200 
9 10 200 
10 7 200 
5 
300 50 95 100 110
```

### 输出 #2

```
0 0 
6 9 
4 5 
4 5 
5 4
```

## 说明/提示

Central Europe Regional Contest 2015 Problem E