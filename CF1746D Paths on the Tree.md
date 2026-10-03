# CF1746D Paths on the Tree

## 题目描述

给定一棵有 $n$ 个结点的有根树，结点编号为 $1$ 到 $n$，根结点为 $1$。同时给定一个分数数组 $s_1, s_2, \ldots, s_n$。

一个包含 $k$ 条简单路径的多重集被称为“合法”，当且仅当满足以下两个条件：

- 每条路径都从 $1$ 号结点出发。
- 设 $c_i$ 表示有多少条路径经过结点 $i$。对于每一对有相同父亲的结点 $(u, v)$（$2 \le u, v \le n$），都有 $|c_u - c_v| \le 1$。

路径多重集的价值定义为 $\sum\limits_{i=1}^n c_i s_i$。可以证明总能找到至少一个合法的多重集。请你求出所有合法多重集中价值的最大值。

## 输入格式

每组测试数据包含多组测试用例。第一行包含一个整数 $t$（$1 \leq t \leq 10^4$），表示测试用例的组数。

每组测试用例的第一行包含两个整数 $n$（$2 \le n \le 2 \cdot 10^5$）和 $k$（$1 \le k \le 10^9$），分别表示树的结点数和所需路径数。

第二行包含 $n-1$ 个整数 $p_2, p_3, \ldots, p_n$（$1 \le p_i \le n$），其中 $p_i$ 表示第 $i$ 个结点的父亲。保证这些值描述了一棵以 $1$ 为根的合法树。

第三行包含 $n$ 个整数 $s_1, s_2, \ldots, s_n$（$0 \le s_i \le 10^4$），表示每个结点的分数。

保证所有测试用例中 $n$ 的总和不超过 $2 \cdot 10^5$。

## 输出格式

对于每组测试用例，输出一个整数，表示路径多重集的最大价值。

## 输入输出样例 #1

### 输入 #1

```
2
5 4
1 2 1 3
6 2 1 5 7
5 3
1 2 1 3
6 6 1 4 10
```

### 输出 #1

```
54
56
```

## 说明/提示

在第一个测试用例中，一种最优方案是四条路径 $1 \to 2 \to 3 \to 5$，$1 \to 2 \to 3 \to 5$，$1 \to 4$，$1 \to 4$，此时 $c=[4,2,2,2,2]$。价值为 $4\cdot 6+2\cdot 2+2\cdot 1+2\cdot 5+2\cdot 7=54$。

在第二个测试用例中，一种最优方案是三条路径 $1 \to 2 \to 3 \to 5$，$1 \to 2 \to 3 \to 5$，$1 \to 4$，此时 $c=[3,2,2,1,2]$。价值为 $3\cdot 6+2\cdot 6+2\cdot 1+1\cdot 4+2\cdot 10=56$。

由 ChatGPT 4.1 翻译

---

# CF1746D Paths on the Tree

## 题目描述

You are given a rooted tree consisting of $ n $ vertices. The vertices are numbered from $ 1 $ to $ n $ , and the root is the vertex $ 1 $ . You are also given a score array $ s_1, s_2, \ldots, s_n $ .

A multiset of $ k $ simple paths is called valid if the following two conditions are both true.

- Each path starts from $ 1 $ .
- Let $ c_i $ be the number of paths covering vertex $ i $ . For each pair of vertices $ (u,v) $ ( $ 2\le u,v\le n $ ) that have the same parent, $ |c_u-c_v|\le 1 $ holds.

 The value of the path multiset is defined as $ \sum\limits_{i=1}^n c_i s_i $ .It can be shown that it is always possible to find at least one valid multiset. Find the maximum value among all valid multisets.

## 输入格式

Each test contains multiple test cases. The first line contains a single integer $ t $ ( $ 1 \leq t \leq 10^4 $ ) — the number of test cases. The description of the test cases follows.

The first line of each test case contains two space-separated integers $ n $ ( $ 2 \le n \le 2 \cdot 10^5 $ ) and $ k $ ( $ 1 \le k \le 10^9 $ ) — the size of the tree and the required number of paths.

The second line contains $ n - 1 $ space-separated integers $ p_2,p_3,\ldots,p_n $ ( $ 1\le p_i\le n $ ), where $ p_i $ is the parent of the $ i $ -th vertex. It is guaranteed that this value describe a valid tree with root $ 1 $ .

The third line contains $ n $ space-separated integers $ s_1,s_2,\ldots,s_n $ ( $ 0 \le s_i \le 10^4 $ ) — the scores of the vertices.

It is guaranteed that the sum of $ n $ over all test cases does not exceed $ 2 \cdot 10 ^ 5 $ .

## 输出格式

For each test case, print a single integer — the maximum value of a path multiset.

## 输入输出样例 #1

### 输入 #1

```
2
5 4
1 2 1 3
6 2 1 5 7
5 3
1 2 1 3
6 6 1 4 10
```

### 输出 #1

```
54
56
```

## 说明/提示

In the first test case, one of optimal solutions is four paths $ 1 \to 2 \to 3 \to 5 $ , $ 1 \to 2 \to 3 \to 5 $ , $ 1 \to 4 $ , $ 1 \to 4 $ , here $ c=[4,2,2,2,2] $ . The value equals to $ 4\cdot 6+ 2\cdot 2+2\cdot 1+2\cdot 5+2\cdot 7=54 $ .

In the second test case, one of optimal solution is three paths $ 1 \to 2 \to 3 \to 5 $ , $ 1 \to 2 \to 3 \to 5 $ , $ 1 \to 4 $ , here $ c=[3,2,2,1,2] $ . The value equals to $ 3\cdot 6+ 2\cdot 6+2\cdot 1+1\cdot 4+2\cdot 10=56 $ .