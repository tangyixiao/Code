# CF1806D DSU Master

## 题目描述

给定一个整数 $n$ 和一个长度为 $n-1$ 的数组 $a$，其中每个元素都是 $0$ 或 $1$。

我们定义一个长度为 $m-1$（$m \leq n$）的排列 $p$ 的值如下：

令 $G$ 为一个有 $m$ 个顶点的图，顶点编号为 $1$ 到 $m$，初始时没有任何边。对于每个 $i$ 从 $1$ 到 $m-1$，执行以下操作：

- 设 $u$ 和 $v$ 分别为包含顶点 $p_i$ 和 $p_i+1$ 的弱连通分量中仅有入边的（唯一）顶点；
- 如果 $a_{p_i}=0$，则在图 $G$ 中添加一条从顶点 $v$ 指向 $u$ 的有向边；否则（即 $a_{p_i}=1$），添加一条从 $u$ 指向 $v$ 的有向边。

注意，每一步操作后，可以证明 $G$ 的每个弱连通分量都恰好有一个仅有入边的顶点。排列 $p$ 的值定义为 $G$ 中顶点 $1$ 的入边数。

对于每个 $k$ 从 $1$ 到 $n-1$，求所有长度为 $k$ 的排列的值之和（共 $k!$ 个排列）。由于答案可能很大，只需输出对 $998\,244\,353$ 取模的结果。

当 $n=3$，$a=[0,1]$ 且 $p=[1,2]$ 时的操作示意图。

![](https://pic1.imgdb.cn/item/69129de23203f7be00eec852.gif) 

$^\dagger$ 长度为 $n$ 的排列是一个包含 $1$ 到 $n$ 的所有整数且顺序任意的数组。例如，$[2,3,1,5,4]$ 是一个排列，但 $[1,2,2]$ 不是（$2$ 出现了两次），$[1,3,4]$ 也不是（$n=3$ 但数组中有 $4$）。

$^\ddagger$ 有向图的弱连通分量与其无向版本的连通分量相同。形式化地，对于有向图 $G$，定义图 $H$，对于 $G$ 中的每条边 $a \to b$，在 $H$ 中添加一条无向边 $a \leftrightarrow b$。则 $G$ 的弱连通分量即为 $H$ 的连通分量。

$^{\dagger\dagger}$ 注意，没有任何边的顶点也被认为是仅有入边的顶点。

## 输入格式

第一行包含一个整数 $t$（$1\le t\le 10^4$），表示测试用例的数量。接下来是每个测试用例的描述。

每个测试用例的第一行包含一个整数 $n$（$2\le n\le 5 \cdot 10^5$）。

第二行包含 $n-1$ 个整数 $a_1, a_2, \ldots, a_{n-1}$（$a_i$ 为 $0$ 或 $1$）。

保证所有测试用例中 $n$ 的总和不超过 $5 \cdot 10^5$。

## 输出格式

对于每个测试用例，输出一行 $n-1$ 个整数，第 $i$ 个整数表示 $k=i$ 时的答案，对 $998\,244\,353$ 取模。

## 输入输出样例 #1

### 输入 #1

```
2
3
0 0
9
0 1 0 0 0 1 0 0
```

### 输出 #1

```
1 3 
1 2 7 31 167 1002 7314 60612
```

## 说明/提示

考虑第一个测试用例。

当 $k=1$ 时，只有 $1$ 个排列 $p$。

- 当 $p=[1]$ 时，会添加一条从顶点 $2$ 指向 $1$ 的边。顶点 $1$ 有 $1$ 条入边，所以 $[1]$ 的值为 $1$。

因此当 $k=1$ 时，答案为 $1$。

当 $k=2$ 时，有 $2$ 个排列 $p$。

- 当 $p=[1,2]$ 时，会添加一条从顶点 $2$ 指向 $1$ 的边，再添加一条从 $3$ 指向 $1$ 的边。顶点 $1$ 有 $2$ 条入边，所以 $[1,2]$ 的值为 $2$。
- 当 $p=[2,1]$ 时，会添加一条从 $3$ 指向 $2$ 的边，再添加一条从 $2$ 指向 $1$ 的边。顶点 $1$ 有 $1$ 条入边，所以 $[2,1]$ 的值为 $1$。

因此当 $k=2$ 时，答案为 $2+1=3$。

由 ChatGPT 4.1 翻译

---

# CF1806D DSU Master

## 题目描述

You are given an integer $ n $ and an array $ a $ of length $ n-1 $ whose elements are either $ 0 $ or $ 1 $ .

Let us define the value of a permutation $ ^\dagger $ $ p $ of length $ m-1 $ ( $ m \leq n $ ) by the following process.

Let $ G $ be a graph of $ m $ vertices labeled from $ 1 $ to $ m $ that does not contain any edges. For each $ i $ from $ 1 $ to $ m-1 $ , perform the following operations:

- define $ u $ and $ v $ as the (unique) vertices in the weakly connected components $ ^\ddagger $ containing vertices $ p_i $ and $ p_i+1 $ respectively with only incoming edges $ ^{\dagger\dagger} $ ;
- in graph $ G $ , add a directed edge from vertex $ v $ to $ u $ if $ a_{p_i}=0 $ , otherwise add a directed edge from vertex $ u $ to $ v $ (if $ a_{p_i}=1 $ ).

 Note that after each step, it can be proven that each weakly connected component of $ G $ has a unique vertex with only incoming edges.Then, the value of $ p $ is the number of incoming edges of vertex $ 1 $ of $ G $ .

For each $ k $ from $ 1 $ to $ n-1 $ , find the sum of values of all $ k! $ permutations of length $ k $ . Since this value can be big, you are only required to compute this value under modulo $ 998\,244\,353 $ .

 ![](https://cdn.luogu.com.cn/upload/vjudge_pic/CF1806D/27fd1ea1a5a6a85d7d3f7a744475a00230fb82dd.png) Operations when $ n=3 $ , $ a=[0,1] $ and $ p=[1,2] $  $ ^\dagger $ A permutation of length $ n $ is an array consisting of $ n $ distinct integers from $ 1 $ to $ n $ in arbitrary order. For example, $ [2,3,1,5,4] $ is a permutation, but $ [1,2,2] $ is not a permutation ( $ 2 $ appears twice in the array), and $ [1,3,4] $ is also not a permutation ( $ n=3 $ but there is $ 4 $ in the array).

 $ ^\ddagger $ The weakly connected components of a directed graph is the same as the components of the undirected version of the graph. Formally, for directed graph $ G $ , define a graph $ H $ where for all edges $ a \to b $ in $ G $ , you add an undirected edge $ a \leftrightarrow b $ in $ H $ . Then the weakly connected components of $ G $ are the components of $ H $ .

 $ ^{\dagger\dagger} $ Note that a vertex that has no edges is considered to have only incoming edges.

## 输入格式

The first line contains a single integer $ t $ ( $ 1\le t\le 10^4 $ ) — the number of test cases. The description of test cases follows.

The first line of each test case contains a single integer $ n $ ( $ 2\le n\le 5 \cdot 10^5 $ ).

The second line of each test case contains $ n-1 $ integers $ a_1, a_2, \ldots, a_{n-1} $ ( $ a_i $ is $ 0 $ or $ 1 $ ).

It is guaranteed that the sum of $ n $ over all test cases does not exceed $ 5 \cdot 10^5 $ .

## 输出格式

For each test case, output $ n-1 $ integers in a line, the $ i $ -th integer should represent the answer when $ k=i $ , under modulo $ 998\,244\,353 $ .

## 输入输出样例 #1

### 输入 #1

```
2
3
0 0
9
0 1 0 0 0 1 0 0
```

### 输出 #1

```
1 3 
1 2 7 31 167 1002 7314 60612
```

## 说明/提示

Consider the first test case.

When $ k=1 $ , there is only $ 1 $ permutation $ p $ .

- When $ p=[1] $ , we will add a single edge from vertex $ 2 $ to $ 1 $ . Vertex $ 1 $ will have $ 1 $ incoming edge. So the value of $ [1] $ is $ 1 $ .

Therefore when $ k=1 $ , the answer is $ 1 $ .

When $ k=2 $ , there are $ 2 $ permutations $ p $ .

- When $ p=[1,2] $ , we will add an edge from vertex $ 2 $ to $ 1 $ and an edge from $ 3 $ to $ 1 $ . Vertex $ 1 $ will have $ 2 $ incoming edges. So the value of $ [1,2] $ is $ 2 $ .
- When $ p=[2,1] $ , we will add an edge from vertex $ 3 $ to $ 2 $ and an edge from $ 2 $ to $ 1 $ . Vertex $ 1 $ will have $ 1 $ incoming edge. So the value of $ [2,1] $ is $ 1 $ .

Therefore when $ k=2 $ , the answer is $ 2+1=3 $ .