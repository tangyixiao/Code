# CF600E Lomsat gelral

## 题目描述

给你一棵以结点 $1$ 为根的有根树，每个节点最开始都被涂上了颜色。

如果颜色 $c$ 在以结点 $v$ 为根的子树中出现次数最多，则称其在以结点 $v$ 为根的子树中占**重要地位**。一棵树中可以有很多颜色同时占**重要地位**。

以 $v$ 为根的子树指结点 $v$ 及其他到根结点的路径包含 $v$ 的结点。

请输出对于每一个结点 $v$，在其子树中占**重要地位**的颜色编号之和。

## 输入格式

第一行包含一个整数 $n$，表示树的结点个数。

第二行包含 $n$ 个整数 $c _ i$，表示每个结点的颜色。

接下来 $n - 1$ 行，每行包含两个整数 $x _ j$ 和 $y _ j$，表示每条边。结点 $1$ 是树的根。

## 输出格式

输出一行 $n$ 个整数，表示对于每个节点，在以其为根的子树中占**重要地位**的颜色编号之和。

## 输入输出样例 #1

### 输入 #1

```
4
1 2 3 4
1 2
2 3
2 4

```

### 输出 #1

```
10 9 3 4

```

## 输入输出样例 #2

### 输入 #2

```
15
1 2 3 1 2 3 3 1 1 3 2 2 1 2 3
1 2
1 3
1 4
1 14
1 15
2 5
2 6
2 7
3 8
3 9
3 10
4 11
4 12
4 13

```

### 输出 #2

```
6 5 4 3 2 3 3 1 1 3 2 2 1 2 3

```

## 说明/提示

**数据范围**

对于所有数据，$1 \le n \le 10 ^ 5$，$1 \le c _ i \le n$。

---

# CF600E Lomsat gelral

## 题目描述

You are given a rooted tree with root in vertex $ 1 $ . Each vertex is coloured in some colour.

Let's call colour $ c $ dominating in the subtree of vertex $ v $ if there are no other colours that appear in the subtree of vertex $ v $ more times than colour $ c $ . So it's possible that two or more colours will be dominating in the subtree of some vertex.

The subtree of vertex $ v $ is the vertex $ v $ and all other vertices that contains vertex $ v $ in each path to the root.

For each vertex $ v $ find the sum of all dominating colours in the subtree of vertex $ v $ .

## 输入格式

The first line contains integer $ n $ ( $ 1<=n<=10^{5} $ ) — the number of vertices in the tree.

The second line contains $ n $ integers $ c_{i} $ ( $ 1<=c_{i}<=n $ ), $ c_{i} $ — the colour of the $ i $ -th vertex.

Each of the next $ n-1 $ lines contains two integers $ x_{j},y_{j} $ ( $ 1<=x_{j},y_{j}<=n $ ) — the edge of the tree. The first vertex is the root of the tree.

## 输出格式

Print $ n $ integers — the sums of dominating colours for each vertex.

## 输入输出样例 #1

### 输入 #1

```
4
1 2 3 4
1 2
2 3
2 4

```

### 输出 #1

```
10 9 3 4

```

## 输入输出样例 #2

### 输入 #2

```
15
1 2 3 1 2 3 3 1 1 3 2 2 1 2 3
1 2
1 3
1 4
1 14
1 15
2 5
2 6
2 7
3 8
3 9
3 10
4 11
4 12
4 13

```

### 输出 #2

```
6 5 4 3 2 3 3 1 1 3 2 2 1 2 3

```