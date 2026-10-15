# CF1528C Trees of Tranquillity

## 题目描述

Soroush 和 Keshi 各自拥有一棵有 $n$ 个结点的有根有标号树。两棵树的根都是结点 $1$。

Soroush 和 Keshi 曾经是敌人。经过无数年的战斗，他们终于成为盟友，一起准备一场 Codeforces 比赛。为了纪念这次幸运的事件，他们决定构建一张有 $n$ 个结点的纪念图。

如果满足以下两个条件，他们就在纪念图中为结点 $u$ 和 $v$ 之间添加一条边：

- 在 Soroush 的树中，$u$ 和 $v$ 之一是另一个的祖先。
- 在 Keshi 的树中，$u$ 和 $v$ 互相都不是对方的祖先。

这里，如果 $u$ 在从 $1$（根）到 $v$ 的路径上，则称 $u$ 是 $v$ 的祖先。

突然出现的 Mashtali 想要在纪念图中找到最大团的大小，但由于图太大，他失败了。

请你帮助 Mashtali，找出纪念图中最大团的大小。

提示：团是图中一个顶点的子集，任意两点之间都有边相连。

## 输入格式

第一行包含一个整数 $t$（$1\le t\le 3 \cdot 10^5$），表示测试用例的数量。接下来是每个测试用例的描述。

每个测试用例的第一行包含一个整数 $n$（$2\le n\le 3 \cdot 10^5$）。

第二行包含 $n-1$ 个整数 $a_2, \ldots, a_n$（$1 \le a_i < i$），其中 $a_i$ 表示 Soroush 的树中结点 $i$ 的父节点。

第三行包含 $n-1$ 个整数 $b_2, \ldots, b_n$（$1 \le b_i < i$），其中 $b_i$ 表示 Keshi 的树中结点 $i$ 的父节点。

保证给定的图都是树。

保证所有测试用例中 $n$ 的总和不超过 $3 \cdot 10^5$。

## 输出格式

对于每个测试用例，输出一个整数，表示纪念图中最大团的大小。

## 输入输出样例 #1

### 输入 #1

```
4
4
1 2 3
1 2 3
5
1 2 3 4
1 1 1 1
6
1 1 1 1 2
1 2 1 2 2
7
1 1 3 4 4 5
1 2 1 4 2 5
```

### 输出 #1

```
1
4
1
3
```

## 说明/提示

在第一个和第三个测试用例中，你可以任选一个结点。

在第二个测试用例中，其中一个最大团是 $\{2, 3, 4, 5\}$。

在第四个测试用例中，其中一个最大团是 $\{3, 4, 6\}$。

由 ChatGPT 4.1 翻译

---

# CF1528C Trees of Tranquillity

## 题目描述

Soroush and Keshi each have a labeled and rooted tree on $ n $ vertices. Both of their trees are rooted from vertex $ 1 $ .

Soroush and Keshi used to be at war. After endless decades of fighting, they finally became allies to prepare a Codeforces round. To celebrate this fortunate event, they decided to make a memorial graph on $ n $ vertices.

They add an edge between vertices $ u $ and $ v $ in the memorial graph if both of the following conditions hold:

- One of $ u $ or $ v $ is the ancestor of the other in Soroush's tree.
- Neither of $ u $ or $ v $ is the ancestor of the other in Keshi's tree.

Here vertex $ u $ is considered ancestor of vertex $ v $ , if $ u $ lies on the path from $ 1 $ (the root) to the $ v $ .

Popping out of nowhere, Mashtali tried to find the maximum clique in the memorial graph for no reason. He failed because the graph was too big.

Help Mashtali by finding the size of the maximum clique in the memorial graph.

As a reminder, clique is a subset of vertices of the graph, each two of which are connected by an edge.

## 输入格式

The first line contains an integer $ t $ $ (1\le t\le 3 \cdot 10^5) $ — the number of test cases. The description of the test cases follows.

The first line of each test case contains an integer $ n $ $ (2\le n\le 3 \cdot 10^5) $ .

The second line of each test case contains $ n-1 $ integers $ a_2, \ldots, a_n $ $ (1 \le a_i < i) $ , $ a_i $ being the parent of the vertex $ i $ in Soroush's tree.

The third line of each test case contains $ n-1 $ integers $ b_2, \ldots, b_n $ $ (1 \le b_i < i) $ , $ b_i $ being the parent of the vertex $ i $ in Keshi's tree.

It is guaranteed that the given graphs are trees.

It is guaranteed that the sum of $ n $ over all test cases doesn't exceed $ 3 \cdot 10^5 $ .

## 输出格式

For each test case print a single integer — the size of the maximum clique in the memorial graph.

## 输入输出样例 #1

### 输入 #1

```
4
4
1 2 3
1 2 3
5
1 2 3 4
1 1 1 1
6
1 1 1 1 2
1 2 1 2 2
7
1 1 3 4 4 5
1 2 1 4 2 5
```

### 输出 #1

```
1
4
1
3
```

## 说明/提示

In the first and third test cases, you can pick any vertex.

In the second test case, one of the maximum cliques is $ \{2, 3, 4, 5\} $ .

In the fourth test case, one of the maximum cliques is $ \{3, 4, 6\} $ .