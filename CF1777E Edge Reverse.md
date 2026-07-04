# CF1777E Edge Reverse

## 题目描述

给定一个有 $n$ 个点、$m$ 条有向边的带权有向图，第 $i$ 条边的权值为 $w_i$（$1 \le i \le m$）。

你需要反转图中的一些边，使得图中至少存在一个节点，从该节点出发可以到达所有其他节点。反转这些边的代价等于所有被反转边中权值的最大值。如果不需要反转任何边，则代价为 $0$。

保证不存在自环或重边。

请你求出完成该任务所需的最小代价。如果无解，输出一个整数 $-1$。

## 输入格式

每个测试点包含多组测试用例。第一行包含一个整数 $t$（$1 \le t \le 10^5$），表示测试用例的数量。接下来是每组测试用例的描述。

每组测试用例的第一行包含两个整数 $n$ 和 $m$（$2 \le n \le 2 \cdot 10^5$，$1 \le m \le 2 \cdot 10^5$），分别表示图中的点数和边数。

接下来的 $m$ 行，每行包含三个整数 $u$、$v$、$w$（$1 \le u, v \le n$，$1 \le w \le 10^9$），表示一条从 $u$ 指向 $v$、权值为 $w$ 的有向边。保证不存在自环，也不存在起点和终点都相同的重边。

保证所有测试用例中 $n$ 的总和与 $m$ 的总和不超过 $2 \cdot 10^5$。

## 输出格式

对于每组测试用例，输出最小代价。如果无解，输出 $-1$。

## 输入输出样例 #1

### 输入 #1

```
4
2 1
1 2 3
5 4
1 2 10
2 3 10
3 1 10
4 5 10
4 5
1 2 10000
2 3 20000
1 3 30000
4 2 500
4 3 20
4 5
1 2 10000
2 3 20000
1 3 30000
4 2 5
4 3 20
```

### 输出 #1

```
0
-1
20
5
```

## 说明/提示

在第一个测试用例中，存在一条从 $1$ 到 $2$ 的边，因此所有节点都可以从 $1$ 到达。

在第二个测试用例中，无论如何反转边，都无法使任意节点可以到达所有节点，因此答案为 $-1$。

在第三个测试用例中，反转第 $4$ 条或第 $5$ 条边都可以使所有节点从 $1$ 出发可达。此处选择反转第 $5$ 条边，因为其权值更小。

由 ChatGPT 4.1 翻译

---

# CF1777E Edge Reverse

## 题目描述

You will be given a weighted directed graph of $ n $ nodes and $ m $ directed edges, where the $ i $ -th edge has a weight of $ w_i $ ( $ 1 \le i \le m $ ).

You need to reverse some edges of this graph so that there is at least one node in the graph from which every other node is reachable. The cost of these reversals is equal to the maximum weight of all reversed edges. If no edge reversal is required, assume the cost to be $ 0 $ .

It is guaranteed that no self-loop or duplicate edge exists.

Find the minimum cost required for completing the task. If there is no solution, print a single integer $ -1 $ .

## 输入格式

Each test contains multiple test cases. The first line contains the number of test cases $ t $ ( $ 1 \le t \le 10^5 $ ). The description of the test cases follows.

Each test case begins with a line containing two integers $ n $ and $ m $ ( $ 2 \le n \le 2 \cdot 10^5 $ , $ 1 \le m \le 2 \cdot 10^5 $ ) — the number of nodes in the graph and the number of edges in the graph.

The next $ m $ lines of each test case contain $ 3 $ integers each — $ u $ , $ v $ , $ w $ ( $ 1 \le u, v \le n $ , $ 1 \le w \le 10^9 $ ), indicating an edge from $ u $ to $ v $ with a weight of $ w $ . It is guaranteed that no edge connects a vertex to itself, and no pair of edges share the same origin and destination simultaneously.

It is guaranteed that the sum of $ n $ and the sum of $ m $ over all test cases do not exceed $ 2 \cdot 10^5 $ .

## 输出格式

For each test case, output the minimum cost. If there is no solution, print $ -1 $ .

## 输入输出样例 #1

### 输入 #1

```
4
2 1
1 2 3
5 4
1 2 10
2 3 10
3 1 10
4 5 10
4 5
1 2 10000
2 3 20000
1 3 30000
4 2 500
4 3 20
4 5
1 2 10000
2 3 20000
1 3 30000
4 2 5
4 3 20
```

### 输出 #1

```
0
-1
20
5
```

## 说明/提示

In the first test case, an edge exists from $ 1 $ to $ 2 $ , so all nodes are reachable (from $ 1 $ ).

In the second test case, no nodes are reachable from any node no matter what edges we reverse, so the answer is $ -1 $ .

In the third test case, reversing the $ 4 $ -th or $ 5 $ -th edge allows all nodes to be reachable from $ 1 $ . We choose the $ 5 $ -th edge here because its weight is smaller.