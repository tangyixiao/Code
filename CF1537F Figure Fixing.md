# CF1537F Figure Fixing

## 题目描述

你有一个由 $n$ 个节点和 $m$ 条边组成的连通无向图。第 $i$ 个节点有一个初始值 $v_i$ 和一个目标值 $t_i$。

每次操作，你可以选择一条边 $(i, j)$，并将某个整数 $k$ 加到 $v_i$ 和 $v_j$ 上，其中 $k$ 可以是任意整数，特别地，$k$ 可以为负数。

你的任务是判断，是否可以通过有限次（可以为零次）这样的操作，使得对于每个节点 $i$，都有 $v_i = t_i$。

## 输入格式

第一行包含一个整数 $t$（$1 \leq t \leq 1000$），表示测试用例的数量。接下来是 $t$ 组测试用例。

每组测试用例的第一行包含两个整数 $n$ 和 $m$（$2 \leq n \leq 2 \cdot 10^5$，$n-1 \leq m \leq \min(2 \cdot 10^5, \frac{n(n-1)}{2})$），分别表示节点数和边数。

第二行包含 $n$ 个整数 $v_1, \ldots, v_n$（$-10^9 \leq v_i \leq 10^9$），表示每个节点的初始值。

第三行包含 $n$ 个整数 $t_1, \ldots, t_n$（$-10^9 \leq t_i \leq 10^9$），表示每个节点的目标值。

接下来的 $m$ 行，每行包含两个整数 $i$ 和 $j$，表示节点 $i$ 和节点 $j$ 之间有一条边（$1 \leq i, j \leq n$，$i \ne j$）。

保证图是连通的，且任意一对节点之间最多只有一条边。

保证所有测试用例中 $n$ 的总和不超过 $2 \cdot 10^5$，$m$ 的总和不超过 $2 \cdot 10^5$。

## 输出格式

对于每个测试用例，如果可以通过若干次操作使每个节点都达到目标值，输出 "YES"；否则输出 "NO"。

## 输入输出样例 #1

### 输入 #1

```
2
4 4
5 1 2 -3
3 3 10 1
1 2
1 4
3 2
3 4
4 4
5 8 6 6
-3 1 15 4
1 2
1 4
3 2
3 4
```

### 输出 #1

```
YES
NO
```

## 说明/提示

以下是第一个测试用例的可视化（橙色为初始值，蓝色为目标值）：

![](https://cdn.luogu.com.cn/upload/vjudge_pic/CF1537F/1a3ad14db7374ce21cd4060fc1b1fbe532afbff1.png)

一种可能的操作顺序如下：

- 操作 $1$：对节点 $2$ 和 $3$ 加 $2$。
- 操作 $2$：对节点 $1$ 和 $4$ 加 $-2$。
- 操作 $3$：对节点 $3$ 和 $4$ 加 $6$。

最终我们可以看到，总共对节点 $1$ 加了 $-2$，对节点 $2$ 加了 $2$，对节点 $3$ 加了 $8$，对节点 $4$ 加了 $4$，刚好使每个节点达到目标值。

对于第二个测试用例的图，不可能达到目标值。

由 ChatGPT 4.1 翻译

---

# CF1537F Figure Fixing

## 题目描述

You have a connected undirected graph made of $ n $ nodes and $ m $ edges. The $ i $ -th node has a value $ v_i $ and a target value $ t_i $ .

In an operation, you can choose an edge $ (i, j) $ and add $ k $ to both $ v_i $ and $ v_j $ , where $ k $ can be any integer. In particular, $ k $ can be negative.

Your task to determine if it is possible that by doing some finite number of operations (possibly zero), you can achieve for every node $ i $ , $ v_i = t_i $ .

## 输入格式

The first line contains a single integer $ t $ ( $ 1 \leq t \leq 1000 $ ), the number of test cases. Then the test cases follow.

The first line of each test case contains two integers $ n $ , $ m $ ( $ 2 \leq n \leq 2\cdot 10^5 $ , $ n-1\leq m\leq \min(2\cdot 10^5, \frac{n(n-1)}{2}) $ ) — the number of nodes and edges respectively.

The second line contains $ n $ integers $ v_1\ldots, v_n $ ( $ -10^9 \leq v_i \leq 10^9 $ ) — initial values of nodes.

The third line contains $ n $ integers $ t_1\ldots, t_n $ ( $ -10^9 \leq t_i \leq 10^9 $ ) — target values of nodes.

Each of the next $ m $ lines contains two integers $ i $ and $ j $ representing an edge between node $ i $ and node $ j $ ( $ 1 \leq i, j \leq n $ , $ i\ne j $ ).

It is guaranteed that the graph is connected and there is at most one edge between the same pair of nodes.

It is guaranteed that the sum of $ n $ over all testcases does not exceed $ 2 \cdot 10^5 $ and the sum of $ m $ over all testcases does not exceed $ 2 \cdot 10^5 $ .

## 输出格式

For each test case, if it is possible for every node to reach its target after some number of operations, print "YES". Otherwise, print "NO".

## 输入输出样例 #1

### 输入 #1

```
2
4 4
5 1 2 -3
3 3 10 1
1 2
1 4
3 2
3 4
4 4
5 8 6 6
-3 1 15 4
1 2
1 4
3 2
3 4
```

### 输出 #1

```
YES
NO
```

## 说明/提示

Here is a visualization of the first test case (the orange values denote the initial values and the blue ones the desired values):

 ![](https://cdn.luogu.com.cn/upload/vjudge_pic/CF1537F/1a3ad14db7374ce21cd4060fc1b1fbe532afbff1.png)One possible order of operations to obtain the desired values for each node is the following:

- Operation $ 1 $ : Add $ 2 $ to nodes $ 2 $ and $ 3 $ .
- Operation $ 2 $ : Add $ -2 $ to nodes $ 1 $ and $ 4 $ .
- Operation $ 3 $ : Add $ 6 $ to nodes $ 3 $ and $ 4 $ .

Now we can see that in total we added $ -2 $ to node $ 1 $ , $ 2 $ to node $ 2 $ , $ 8 $ to node $ 3 $ and $ 4 $ to node $ 4 $ which brings each node exactly to it's desired value.

For the graph from the second test case it's impossible to get the target values.