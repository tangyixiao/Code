# CF2178F Conquer or of Forest

## 题目描述

定义有根树的独特装饰性染色如下：

- 当以顶点 $v$ 为根的子树中的顶点个数是偶数时，将顶点 $v$ 染为白色；
- 否则，将 $v$ 染成黑色。

在征服圣诞树森林的征途上，Yuuki 遇到了一棵已被装饰性染色的树 $T$，该树有 $n$ 个顶点，编号从 $1$ 到 $n$，根为顶点 $1$。

Yuuki 认为一棵树被征服当且仅当下列任一条件成立：

- 树中不存在白色顶点，或
- 存在某个顶点 $v$，使得所有白色顶点都位于从根 $1$ 到 $v$ 的唯一路径上。

为了征服这棵树，Yuuki 可以任意次（也可以不做）进行如下操作：

- 首先，选择一个染成白色且不是 $T$ 根的顶点 $w$。设 $p_w$ 是 $w$ 的父节点。
- 然后，移除连接 $p_w$ 和 $w$ 的边，并在任意两顶点间添加一条边，前提是 $T$ 依然是一棵树。
- 最后，重染 $T$ 使其满足装饰染色规则。注意，$T$ 总是以顶点 $1$ 为根。

![](https://cdn.luogu.com.cn/upload/vjudge_pic/CF2178F/fdd4cbacb2b8669ea5bfe1022d5613d56384087ee5d70393fee42936b0d9648a.png)  
上图为第一组样例中操作的可能结果。生成的树被征服，因为所有白色顶点都在 $1$ 到 $3$ 的唯一路径上。
请计算通过任意次如上操作后，Yuuki 能够构造出的不同被征服树的数量。由于答案可能很大，请对 $998\,244\,353$ 取模输出。

注意，Yuuki 不能中途终止一次操作（特别是，他必须在判断前对树重新染色）。另外，即使树已经被征服，Yuuki 依然可以继续操作。

注解：
- $^*$ 树是一个无环连通图。
- $^\dagger$ 顶点 $v$ 的子树是由 $v$ 及其所有后代和这些点之间的所有边组成的子图。
- $^\ddagger$ 只有当一对顶点在其中一棵树中有一条边、在另一棵树中没有这条边时，两棵树才被认为是不同的。

## 输入格式

每组测试数据包含多组测试用例。第一行包含测试用例组数 $t$（$1 \le t \le 10^4$）。
每组测试数据第一行为一个整数 $n$（$2\le n\le 2\cdot 10^5$），表示 $T$ 的顶点数。
接下来 $n-1$ 行，每行包含两个整数 $u_i$ 和 $v_i$（$1\le u_i<v_i\le n$），表示第 $i$ 条边连接 $u_i$ 和 $v_i$。
保证所给的边构成一棵树。
保证所有测试用例的 $n$ 之和不超过 $2\cdot 10^5$。

## 输出格式

对于每个测试用例，输出一个整数，表示能够从 $T$ 构造出的不同被征服树的数量，对 $998\,244\,353$ 取模。

## 输入输出样例 #1

### 输入 #1

```
5
4
1 2
1 3
3 4
5
1 2
1 3
1 4
1 5
5
1 2
2 3
1 4
4 5
6
1 2
2 3
2 4
2 6
5 6
11
2 10
6 8
1 6
3 7
5 11
5 8
5 9
4 7
6 7
2 6
```

### 输出 #1

```
4
1
16
8
2048
```

## 说明/提示

在第一个测试用例中，下列给出了能构造的四棵被征服树及其操作序列：

说明  | 插图  
------|-----
- 零次操作。初始树已经被征服，因为所有白色顶点都在 $1$ 到 $4$ 的唯一路径上。 | ![](https://cdn.luogu.com.cn/upload/vjudge_pic/CF2178F/5cbb0e08f30e62e37cf88259261c7c650b2b4c7185ad359ed17c451c5e4e34e0.png)
- 第一次也是唯一一次操作选择 $w=3$（$p_w=1$），在 $2$ 与 $4$ 之间连边。新树已被征服，因为所有白色顶点都在 $1$ 到 $3$ 的唯一路径上。 | ![](https://cdn.luogu.com.cn/upload/vjudge_pic/CF2178F/f55f20c35d1fb8637c51d32e132d7a7d4075b21d6109b24721371d5648a0af03.png)
- 第一次也是唯一一次操作选择 $w=3$（$p_w=1$），在 $2$ 与 $3$ 之间连边。新树已被征服，因为所有白色顶点都在 $1$ 到 $3$ 的唯一路径上。 | ![](https://cdn.luogu.com.cn/upload/vjudge_pic/CF2178F/8e1f007e09806ff4dc5fdc6fbfcdebb541610f56bb541610f56bb16553134fdbc87d5b3a6a5.png)
- 第一次操作选择 $w=3$（$p_w=1$），在 $2$ 与 $4$ 之间连边。第二次操作选择 $w=4$（$p_w=2$），在 $1$ 与 $4$ 之间连边。最终新树已被征服，因为所有白色顶点都在 $1$ 到 $4$ 的唯一路径上。 | ![](https://cdn.luogu.com.cn/upload/vjudge_pic/CF2178F/2b6d9f3467195b3d97a56d97812bc76399cc80cae72ccab9e6d353ae14d6b44d.png)

在第二组样例中，$T$ 不存在白色顶点，因此无法进行操作。而 $T$ 已经被征服，所以答案为 $1$。

由 ChatGPT 5 翻译

---

# CF2178F Conquer or of Forest

## 题目描述

Define the unique ornamental coloring of a rooted tree $ ^{\text{∗}} $  as the following vertex coloring:

- A vertex  $ v $  is colored white if the number of vertices in the subtree $ ^{\text{†}} $  rooted at  $ v $  is even;
- Otherwise,  $ v $  is colored black.

On his quest to conquer a forest of Christmas trees, Yuuki encountered an ornamentally colored tree  $ T $  with  $ n $  vertices labeled from  $ 1 $  to  $ n $ , rooted at vertex  $ 1 $ .

Yuuki considers the tree conquered if and only if at least one of the following conditions holds:

- There are no white vertices in the tree, or
- There exists some vertex  $ v $  such that all white vertices lie on the simple path from the root  $ 1 $  to  $ v $ .

To conquer the tree, Yuuki can apply the following operation on  $ T $  an arbitrary number of times (possibly zero):

- First, choose a vertex  $ w $  that is colored white and is not the root of  $ T $ . Let  $ p_w $  be the parent of  $ w $ .
- Then, remove the edge connecting  $ p_w $  and  $ w $ , and add an edge between any two vertices such that  $ T $  remains a tree.
- Finally, recolor the vertices of  $ T $  such that it is ornamentally colored. Note that  $ T $  is always rooted at vertex  $ 1 $ .

 ![](https://cdn.luogu.com.cn/upload/vjudge_pic/CF2178F/fdd4cbacb2b8669ea5bfe1022d5613d56384087ee5d70393fee42936b0d9648a.png) A possible application of the operation in the first test case. The resulting tree is conquered since all white vertices lie on the path between vertices  $ 1 $  and  $ 3 $ .Compute the number of distinct $ ^{\text{‡}} $  conquered trees that Yuuki can construct by applying the above operation an arbitrary number of times on  $ T $ . Since the answer may be large, output it modulo  $ 998\,244\,353 $ .

Note that Yuuki cannot stop midway through an operation (in particular, he must recolor the tree before checking if it is conquered). Additionally, Yuuki is allowed to apply the operation even if the tree is already conquered.

 $ ^{\text{∗}} $ A tree is a connected graph without cycles.

 $ ^{\text{†}} $ A subtree of vertex  $ v $  is the subgraph of  $ v $ , all its descendants, and all the edges between them.

 $ ^{\text{‡}} $ Two trees are considered distinct if and only if there exists a pair of vertices such that there is an edge between them in one of the trees, and not in the other.

## 输入格式

Each test contains multiple test cases. The first line contains the number of test cases  $ t $  ( $ 1 \le t \le 10^4 $ ). The description of the test cases follows.

The first line of each test case contains a single integer  $ n $  ( $ 2\le n\le 2\cdot 10^5 $ ) — the number of vertices in  $ T $ .

Then  $ n-1 $  lines follow, the  $ i $ -th line containing two integers  $ u_i $  and  $ v_i $  ( $ 1\le u_i<v_i\le n $ ) — the two vertices that the  $ i $ -th edge connects.

It is guaranteed that the given edges form a tree.

It is guaranteed that the sum of  $ n $  over all test cases does not exceed  $ 2\cdot 10^5 $ .

## 输出格式

For each test case, output a single integer — the number of distinct conquered trees that can be constructed from  $ T $ , modulo  $ 998\,244\,353 $ .

## 输入输出样例 #1

### 输入 #1

```
5
4
1 2
1 3
3 4
5
1 2
1 3
1 4
1 5
5
1 2
2 3
1 4
4 5
6
1 2
2 3
2 4
2 6
5 6
11
2 10
6 8
1 6
3 7
5 11
5 8
5 9
4 7
6 7
2 6
```

### 输出 #1

```
4
1
16
8
2048
```

## 说明/提示

In the first test case, below are the four conquered trees that can be constructed and a sequence of operations that constructs each one.

 ExplanationIllustration- The operation is applied zero times.
- The given tree is already conquered since all white vertices lie on the simple path between vertices  $ 1 $  and  $ 4 $ .

![](https://cdn.luogu.com.cn/upload/vjudge_pic/CF2178F/5cbb0e08f30e62e37cf88259261c7c650b2b4c7185ad359ed17c451c5e4e34e0.png)- The first and only operation selects  $ w $  to be vertex  $ 3 $  ( $ p_w $  is vertex  $ 1 $ ) and draws an edge between vertices  $ 2 $  and  $ 4 $ .
- The resulting tree is conquered since all white vertices lie on the simple path between vertices  $ 1 $  and  $ 3 $ .

![](https://cdn.luogu.com.cn/upload/vjudge_pic/CF2178F/f55f20c35d1fb8637c51d32e132d7a7d4075b21d6109b24721371d5648a0af03.png)- The first and only operation selects  $ w $  to be vertex  $ 3 $  ( $ p_w $  is vertex  $ 1 $ ) and draws an edge between vertices  $ 2 $  and  $ 3 $ .
- The resulting tree is conquered since all white vertices lie on the simple path between vertices  $ 1 $  and  $ 3 $ .

![](https://cdn.luogu.com.cn/upload/vjudge_pic/CF2178F/8e1f007e09806ff4dc5fdc6fbfcdebb541610f56bb16553134fdbc87d5b3a6a5.png)- The first operation selects  $ w $  to be vertex  $ 3 $  ( $ p_w $  is vertex  $ 1 $ ) and draws an edge between vertices  $ 2 $  and  $ 4 $ .
- The second operation selects  $ w $  to be vertex  $ 4 $  ( $ p_w $  is vertex  $ 2 $ ) and draws an edge between vertices  $ 1 $  and  $ 4 $ .
- The resulting tree is conquered since all white vertices lie on the simple path between vertices  $ 1 $  and  $ 4 $ .

![](https://cdn.luogu.com.cn/upload/vjudge_pic/CF2178F/2b6d9f3467195b3d97a56d97812bc76399cc80cae72ccab9e6d353ae14d6b44d.png)In the second test case, Yuuki cannot apply the operation on  $ T $  since there are no white vertices. Additionally,  $ T $  is already conquered since there are no white vertices. Thus, the answer is  $ 1 $ .