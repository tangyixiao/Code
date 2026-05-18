# CF2028E Alice's Adventures in the Rabbit Hole

## 题目描述

爱丽丝在兔子洞的底部！兔子洞可以建模为一棵树 $^{\text{∗}}$  ，在顶点 $1$ 有一个出口，而爱丽丝从某个顶点 $v$ 开始。她想要逃出这个洞，但不幸的是，红心女王下令处决她。

每分钟都会抛一次公平的硬币。如果硬币正面朝上，爱丽丝可以移动到她当前位置的一个相邻顶点，否则，红心女王可以将爱丽丝拉到女王选择的一个相邻顶点。如果爱丽丝最终出现在树的任何非根叶子 $^{\text{†}}$ 上，爱丽丝就输了。

假设他们都以最佳方式移动，计算爱丽丝从每个起始顶点 $1\le v\le n$ 成功逃脱的概率。由于这些概率可能非常小，因此输出它们对 $998\,244\,353$ 的取模。

形式上，设 $M = 998\,244\,353$ 。可以证明，确切的答案可以表示为一个不可约分的分数 $\frac{p}{q}$ ，其中 $p$ 和 $q$ 是整数且 $q \not \equiv 0 \pmod{M}$。输出等于 $p \cdot q^{-1} \bmod M$ 的整数。换句话说，输出这样一个整数 $x$，使得 $0 \le x < M$ 和 $x \cdot q \equiv p \pmod{M}$ 

---
$^{\text{∗}}$
 一棵树是一个连通的简单图，具有 $n$ 个顶点和 $n-1$ 条边。

$^{\text{†}} $
 一个叶子是一个仅与一条边相连的顶点。

## 输入格式

每个测试包含多个测试用例。第一行包含测试用例的数量 $t$（$1 \le t \le 10^4$）。测试用例的描述如下。

每个测试用例的第一行包含一个整数 $n$（$2\le n\le 2\cdot 10^5$）——树中的顶点数量。

接下来的 $i$ 行中的第 $n - 1$ 行包含两个整数 $x_i$ 和 $y_i$ （$1 \le x_i, y_i \le n$ 和 $x_i \neq y_i$）——树的边。可以保证给定的边形成一棵树。

可以保证所有测试用例的 $n$ 之和不超过 $2\cdot 10^5$ 。

## 输出格式

对于每个测试用例，输出 $n$ 个整数在一行上——爱丽丝从顶点 $1, 2, \ldots, n$ 开始逃脱的概率。由于这些概率可能非常小，因此输出它们对$998\,244\,353$ 的取模。

## 输入输出样例 #1

### 输入 #1

```
2
5
1 2
1 3
2 4
3 5
9
1 2
2 3
4 5
5 6
7 8
8 9
2 4
5 7
```

### 输出 #1

```
1 499122177 499122177 0 0 
1 499122177 0 332748118 166374059 0 443664157 720954255 0
```

## 说明/提示

对于第一个测试用例：

1.根据定义，爱丽丝从根节点（顶点 $1$）逃脱的概率为 $1$。\
2.爱丽丝从顶点 $4$ 和 $5$ 立即输掉，因为它们是叶子。\
3.从另外两个顶点，爱丽丝以概率 $\frac 12$ 逃脱，因为女王会将她拉到叶子。

---

# CF2028E Alice's Adventures in the Rabbit Hole

## 题目描述

Alice is at the bottom of the rabbit hole! The rabbit hole can be modeled as a tree $ ^{\text{∗}} $ which has an exit at vertex $ 1 $ , and Alice starts at some vertex $ v $ . She wants to get out of the hole, but unfortunately, the Queen of Hearts has ordered her execution.

Each minute, a fair coin is flipped. If it lands heads, Alice gets to move to an adjacent vertex of her current location, and otherwise, the Queen of Hearts gets to pull Alice to an adjacent vertex of the Queen's choosing. If Alice ever ends up on any of the non-root leaves $ ^{\text{†}} $ of the tree, Alice loses.

Assuming both of them move optimally, compute the probability that Alice manages to escape for every single starting vertex $ 1\le v\le n $ . Since these probabilities can be very small, output them modulo $ 998\,244\,353 $ .

Formally, let $ M = 998\,244\,353 $ . It can be shown that the exact answer can be expressed as an irreducible fraction $ \frac{p}{q} $ , where $ p $ and $ q $ are integers and $ q \not \equiv 0 \pmod{M} $ . Output the integer equal to $ p \cdot q^{-1} \bmod M $ . In other words, output such an integer $ x $ that $ 0 \le x < M $ and $ x \cdot q \equiv p \pmod{M} $ .

 $ ^{\text{∗}} $ A tree is a connected simple graph which has $ n $ vertices and $ n-1 $ edges.

 $ ^{\text{†}} $ A leaf is a vertex that is connected to exactly one edge.

## 输入格式

Each test contains multiple test cases. The first line contains the number of test cases $ t $ ( $ 1 \le t \le 10^4 $ ). The description of the test cases follows.

The first line of each test case contains a single integer $ n $ ( $ 2\le n\le 2\cdot 10^5 $ ) — the number of vertices in the tree.

The $ i $ -th of the next $ n - 1 $ lines contains two integers $ x_i $ and $ y_i $ ( $ 1 \le x_i, y_i \le n $ and $ x_i \neq y_i $ ) — the edges of the tree. It is guaranteed that the given edges form a tree.

It is guaranteed that the sum of $ n $ over all test cases does not exceed $ 2\cdot 10^5 $ .

## 输出格式

For each test case, output $ n $ integers on one line — the probabilities of Alice escaping starting from vertex $ 1, 2, \ldots, n $ . Since these probabilities can be very small, output them modulo $ 998\,244\,353 $ .

## 输入输出样例 #1

### 输入 #1

```
2
5
1 2
1 3
2 4
3 5
9
1 2
2 3
4 5
5 6
7 8
8 9
2 4
5 7
```

### 输出 #1

```
1 499122177 499122177 0 0 
1 499122177 0 332748118 166374059 0 443664157 720954255 0
```

## 说明/提示

For the first test case:

1. Alice escapes from the root (vertex $ 1 $ ) by definition with probability $ 1 $ .
2. Alice immediately loses from vertices $ 4 $ and $ 5 $ since they are leaves.
3. From the other two vertices, Alice escapes with probability $ \frac 12 $ since the Queen will pull her to the leaves.