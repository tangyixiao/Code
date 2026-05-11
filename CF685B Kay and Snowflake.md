# CF685B Kay and Snowflake

## 题目描述

当魔镜碎片击中凯的眼睛后，他对玫瑰的美再也不感兴趣了。现在他喜欢观察雪花。

有一天，他发现了一片巨大的雪花，这片雪花的结构是一棵有 $n$ 个结点的树（即连通无环图）。树的根节点编号为 $1$。凯对这棵树的结构非常感兴趣。

经过一些研究，他对这棵树产生了 $q$ 个问题。第 $i$ 个问题请求你找到以第 $v_i$ 号节点为根的子树的重心。

一个节点的子树是指由该节点及其所有后代（无论是直接的还是间接的）组成的部分。换句话说，节点 $v$ 的子树包含所有满足从节点 $u$ 到根节点的路径经过 $v$ 的结点。

一棵树（或子树）的重心是指这样一个节点：如果我们删除它，所得到的最大连通块的大小不超过原树（或子树）大小的一半。

## 输入格式

输入的第一行包含两个整数 $n$ 和 $q$（$2\leq n\leq 300000$，$1\leq q\leq 300000$），分别表示初始树的结点数和询问的数量。

第二行包含 $n-1$ 个整数 $p_2, p_3, \ldots, p_n$（$1\leq p_i\leq n$），表示编号为 $2$ 到 $n$ 的节点的父节点编号。节点 $1$ 是树的根节点。保证 $p_i$ 所描述的是一棵合法的树。

接下来的 $q$ 行，每行一个整数 $v_i$（$1\leq v_i\leq n$），表示一个问题 —— 以 $v_i$ 为根的子树，要求你找出它的重心。

## 输出格式

对于每个查询，输出对应子树重心的编号。如果存在多个满足条件的节点，输出其中任意一个即可。保证每个子树至少有一个重心。

## 输入输出样例 #1

### 输入 #1

```
7 4
1 1 3 3 5 3
1
2
3
5

```

### 输出 #1

```
3
2
3
6

```

## 说明/提示

如下图所示，第一组询问要求整棵树的重心——即节点 $3$。如果删除节点 $3$，树被分为四个连通块，其中两个大小为 $1$，两个大小为 $2$。

编号为 $2$ 的节点的子树只包含它自己，因此答案是 $2$。

编号为 $3$ 的节点自己的子树的重心是 $3$。

编号为 $5$ 的节点的子树的重心可以是 $5$ 或 $6$，两者都为正确答案。

![](https://cdn.luogu.com.cn/upload/vjudge_pic/CF685B/821209b858c843715556bbbb66f001612969fa03.png)

由 ChatGPT 5 翻译

---

# CF685B Kay and Snowflake

## 题目描述

After the piece of a devilish mirror hit the Kay's eye, he is no longer interested in the beauty of the roses. Now he likes to watch snowflakes.

Once upon a time, he found a huge snowflake that has a form of the tree (connected acyclic graph) consisting of $ n $ nodes. The root of tree has index $ 1 $ . Kay is very interested in the structure of this tree.

After doing some research he formed $ q $ queries he is interested in. The $ i $ -th query asks to find a centroid of the subtree of the node $ v_{i} $ . Your goal is to answer all queries.

Subtree of a node is a part of tree consisting of this node and all it's descendants (direct or not). In other words, subtree of node $ v $ is formed by nodes $ u $ , such that node $ v $ is present on the path from $ u $ to root.

Centroid of a tree (or a subtree) is a node, such that if we erase it from the tree, the maximum size of the connected component will be at least two times smaller than the size of the initial tree (or a subtree).

## 输入格式

The first line of the input contains two integers $ n $ and $ q $ ( $ 2<=n<=300000 $ , $ 1<=q<=300000 $ ) — the size of the initial tree and the number of queries respectively.

The second line contains $ n-1 $ integer $ p_{2},p_{3},...,p_{n} $ ( $ 1<=p_{i}<=n $ ) — the indices of the parents of the nodes from $ 2 $ to $ n $ . Node $ 1 $ is a root of the tree. It's guaranteed that $ p_{i} $ define a correct tree.

Each of the following $ q $ lines contain a single integer $ v_{i} $ ( $ 1<=v_{i}<=n $ ) — the index of the node, that define the subtree, for which we want to find a centroid.

## 输出格式

For each query print the index of a centroid of the corresponding subtree. If there are many suitable nodes, print any of them. It's guaranteed, that each subtree has at least one centroid.

## 输入输出样例 #1

### 输入 #1

```
7 4
1 1 3 3 5 3
1
2
3
5

```

### 输出 #1

```
3
2
3
6

```

## 说明/提示

![](https://cdn.luogu.com.cn/upload/vjudge_pic/CF685B/821209b858c843715556bbbb66f001612969fa03.png)The first query asks for a centroid of the whole tree — this is node $ 3 $ . If we delete node $ 3 $ the tree will split in four components, two of size $ 1 $ and two of size $ 2 $ .

The subtree of the second node consists of this node only, so the answer is $ 2 $ .

Node $ 3 $ is centroid of its own subtree.

The centroids of the subtree of the node $ 5 $ are nodes $ 5 $ and $ 6 $ — both answers are considered correct.