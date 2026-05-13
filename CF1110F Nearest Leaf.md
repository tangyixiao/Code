# CF1110F Nearest Leaf

## 题目描述

我们将树（一个无环连通无向图）的欧拉遍历定义如下：考虑一种深度优先搜索算法，遍历树的顶点，并按访问顺序依次编号（每个顶点只在第一次访问时编号）。该函数从编号为 $1$ 的顶点开始，然后递归地从所有与当前顶点通过一条边相连且尚未访问过的顶点出发，按编号递增的顺序进行。形式化地，你可以用如下伪代码描述该函数：

```
next_id = 1
id = 长度为 n 的数组，初始值均为 -1
visited = 长度为 n 的数组，初始值均为 false

function dfs(v):
    visited[v] = true
    id[v] = next_id
    next_id += 1
    for to in 按编号递增顺序的 v 的邻居:
        if not visited[to]:
            dfs(to)
```

给定一棵带权树，其顶点已按照上述算法用 $1$ 到 $n$ 的整数编号。

叶子节点是指仅与一个其他顶点相连的顶点。在给定的树中，编号为 $1$ 的顶点不是叶子节点。树中两个顶点之间的距离定义为它们之间简单路径上所有边的权值之和。

你需要回答 $q$ 个如下形式的询问：给定整数 $v$、$l$ 和 $r$，求从顶点 $v$ 到编号在 $l$ 到 $r$（包含端点）之间的某个叶子节点的最短距离。

## 输入格式

第一行包含两个整数 $n$ 和 $q$（$3 \leq n \leq 500\,000, 1 \leq q \leq 500\,000$），分别表示树的顶点数和询问数。

接下来的 $n-1$ 行，第 $(i-1)$ 行包含两个整数 $p_i$ 和 $w_i$（$1 \leq p_i < i, 1 \leq w_i \leq 10^9$），表示在顶点 $p_i$ 和 $i$ 之间有一条权值为 $w_i$ 的边。

保证所给边构成一棵树，且顶点编号为欧拉遍历顺序，编号为 $1$ 的顶点不是叶子节点。

接下来的 $q$ 行，每行包含三个整数 $v_i$、$l_i$、$r_i$（$1 \leq v_i \leq n, 1 \leq l_i \leq r_i \leq n$），表示一次询问。保证对于每次询问，区间 $[l_i, r_i]$ 内至少有一个叶子节点。

## 输出格式

输出 $q$ 个整数，按输入顺序依次给出每个询问的答案。

## 输入输出样例 #1

### 输入 #1

```
5 3
1 10
1 1
3 2
3 3
1 1 5
5 4 5
4 1 2

```

### 输出 #1

```
3
0
13

```

## 输入输出样例 #2

### 输入 #2

```
5 3
1 1000000000
2 1000000000
1 1000000000
1 1000000000
3 4 5
2 1 5
2 4 5

```

### 输出 #2

```
3000000000
1000000000
2000000000

```

## 输入输出样例 #3

### 输入 #3

```
11 8
1 7
2 1
1 20
1 2
5 6
6 2
6 3
5 1
9 10
9 11
5 1 11
1 1 4
9 4 8
6 1 4
9 7 11
9 10 11
8 1 11
11 4 5

```

### 输出 #3

```
8
8
9
16
9
10
0
34

```

## 说明/提示

在第一个样例中，树的结构如下：

![](https://cdn.luogu.com.cn/upload/vjudge_pic/CF1110F/0f1b498aea8daedc270520f6cae94d5c4aa241fe.png)

对于第一个询问，顶点 $1$ 最近的叶子节点是顶点 $4$，距离为 $3$。对于第二个询问，顶点 $5$ 最近的叶子节点是顶点 $5$，距离为 $0$。对于第三个询问，顶点 $4$ 最近的叶子节点是顶点 $4$，但它不在询问区间 $[1, 2]$ 内。区间 $[1, 2]$ 内唯一的叶子节点是顶点 $2$，从顶点 $4$ 到顶点 $2$ 的距离为 $13$。

由 ChatGPT 4.1 翻译

---


# CF1110F Nearest Leaf

## 题目描述

Let's define the Eulerian traversal of a tree (a connected undirected graph without cycles) as follows: consider a depth-first search algorithm which traverses vertices of the tree and enumerates them in the order of visiting (only the first visit of each vertex counts). This function starts from the vertex number $ 1 $ and then recursively runs from all vertices which are connected with an edge with the current vertex and are not yet visited in increasing numbers order. Formally, you can describe this function using the following pseudocode:

```
<br></br>next_id = 1<br></br>id = array of length n filled with -1<br></br>visited = array of length n filled with false<br></br><br></br>function dfs(v):<br></br>    visited[v] = true<br></br>    id[v] = next_id<br></br>    next_id += 1<br></br>    for to in neighbors of v in increasing order:<br></br>        if not visited[to]:<br></br>            dfs(to)<br></br>
```

You are given a weighted tree, the vertices of which were enumerated with integers from $ 1 $ to $ n $ using the algorithm described above.

A leaf is a vertex of the tree which is connected with only one other vertex. In the tree given to you, the vertex $ 1 $ is not a leaf. The distance between two vertices in the tree is the sum of weights of the edges on the simple path between them.

You have to answer $ q $ queries of the following type: given integers $ v $ , $ l $ and $ r $ , find the shortest distance from vertex $ v $ to one of the leaves with indices from $ l $ to $ r $ inclusive.

## 输入格式

The first line contains two integers $ n $ and $ q $ ( $ 3 \leq n \leq 500\,000, 1 \leq q \leq 500\,000 $ ) — the number of vertices in the tree and the number of queries, respectively.

The $ (i - 1) $ -th of the following $ n - 1 $ lines contains two integers $ p_i $ and $ w_i $ ( $ 1 \leq p_i < i, 1 \leq w_i \leq 10^9 $ ), denoting an edge between vertices $ p_i $ and $ i $ with the weight $ w_i $ .

It's guaranteed that the given edges form a tree and the vertices are enumerated in the Eulerian traversal order and that the vertex with index $ 1 $ is not a leaf.

The next $ q $ lines describe the queries. Each of them contains three integers $ v_i $ , $ l_i $ , $ r_i $ ( $ 1 \leq v_i \leq n, 1 \leq l_i \leq r_i \leq n $ ), describing the parameters of the query. It is guaranteed that there is at least one leaf with index $ x $ such that $ l_i \leq x \leq r_i $ .

## 输出格式

Output $ q $ integers — the answers for the queries in the order they are given in the input.

## 输入输出样例 #1

### 输入 #1

```
5 3
1 10
1 1
3 2
3 3
1 1 5
5 4 5
4 1 2

```

### 输出 #1

```
3
0
13

```

## 输入输出样例 #2

### 输入 #2

```
5 3
1 1000000000
2 1000000000
1 1000000000
1 1000000000
3 4 5
2 1 5
2 4 5

```

### 输出 #2

```
3000000000
1000000000
2000000000

```

## 输入输出样例 #3

### 输入 #3

```
11 8
1 7
2 1
1 20
1 2
5 6
6 2
6 3
5 1
9 10
9 11
5 1 11
1 1 4
9 4 8
6 1 4
9 7 11
9 10 11
8 1 11
11 4 5

```

### 输出 #3

```
8
8
9
16
9
10
0
34

```

## 说明/提示

In the first example, the tree looks like this:

 ![](https://cdn.luogu.com.cn/upload/vjudge_pic/CF1110F/0f1b498aea8daedc270520f6cae94d5c4aa241fe.png)In the first query, the nearest leaf for the vertex $ 1 $ is vertex $ 4 $ with distance $ 3 $ . In the second query, the nearest leaf for vertex $ 5 $ is vertex $ 5 $ with distance $ 0 $ . In the third query the nearest leaf for vertex $ 4 $ is vertex $ 4 $ ; however, it is not inside interval $ [1, 2] $ of the query. The only leaf in interval $ [1, 2] $ is vertex $ 2 $ with distance $ 13 $ from vertex $ 4 $ .