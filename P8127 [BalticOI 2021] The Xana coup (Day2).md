# P8127 [BalticOI 2021] The Xana coup (Day2)

## 题目描述

给定一棵点数为 $N$ 个树，第 $i$ 个点有点权 $a_i$，$a_i \in \{0,1\}$。

你可以进行切换操作：

- 对点 $i$ 进行切换操作会使得点 $i$ 及与其 **直接相连** 的点的点权取反。

其中直接相连指两点之间恰好只有一条边。

求至少需要多少次切换操作才能使得所有点的点权变为 $0$。

## 输入格式

第一行一个整数 $N$ 代表树的点数。

接下来 $N-1$ 行每行两个整数代表树的一条边。

第 $N+1$ 行 $N$ 个整数 $a_i$ 代表第 $i$ 个点的点权。

## 输出格式

如果有解，一行一个整数代表答案。

如果无解，输出 `impossible`。

## 输入输出样例 #1

### 输入 #1

```
5
1 2
1 3
2 4
2 5
0 1 0 1 1
```

### 输出 #1

```
4
```

## 输入输出样例 #2

### 输入 #2

```
5
1 2
2 3
3 4
4 5
0 1 1 1 1
```

### 输出 #2

```
impossible
```

## 说明/提示

#### 样例 1 解释

![](https://cdn.luogu.com.cn/upload/image_hosting/qyej3711.png)

$a_i=0$ 为黑色，$a_i=1$ 为白色。

可以对点 $4,5,3,1$ 进行切换操作使得所有点的点权为 $0$。

#### 数据规模与约定

**本题采用捆绑测试。**

- Subtask 1（5 pts）：$N \le 20$。
- Subtask 2（15 pts）：$N \le 40$。
- Subtask 3（10 pts）：如果点 $u$ 和点 $v$ 满足 $|u-v|=1$，那么他们有边相连。
- Subtask 4（40 pts）：一个点最多与 $3$ 个点相连。
- Subtask 5（30 pts）：无特殊限制。

对于 $100\%$ 的数据，$3 \le N \le 10^5$。

#### 说明

翻译自 [BalticOI 2021 Day2 C The Xana coup](https://boi.cses.fi/files/boi2021_day2.pdf)。

---

# P8127 [BalticOI 2021] The Xana coup (Day2)

## 题目描述

You are given a tree with $N$ vertices. Vertex $i$ has a value $a_i$, where $a_i \in \{0,1\}$.

You may perform toggle operations:

- Toggling vertex $i$ will flip the values of vertex $i$ and all vertices **directly connected** to it.

Here, “directly connected” means that there is exactly one edge between the two vertices.

Find the minimum number of toggle operations needed to make the values of all vertices equal to $0$.

## 输入格式

The first line contains an integer $N$, the number of vertices in the tree.

The next $N-1$ lines each contain two integers, describing an edge of the tree.

The $(N+1)$-th line contains $N$ integers $a_i$, representing the value of vertex $i$.

## 输出格式

If a solution exists, output one line with one integer, the answer.

If there is no solution, output `impossible`.

## 输入输出样例 #1

### 输入 #1

```
5
1 2
1 3
2 4
2 5
0 1 0 1 1
```

### 输出 #1

```
4
```

## 输入输出样例 #2

### 输入 #2

```
5
1 2
2 3
3 4
4 5
0 1 1 1 1
```

### 输出 #2

```
impossible
```

## 说明/提示

#### Explanation for Sample 1

![](https://cdn.luogu.com.cn/upload/image_hosting/qyej3711.png)

$a_i=0$ is colored black, and $a_i=1$ is colored white.

By toggling vertices $4,5,3,1$, you can make the values of all vertices equal to $0$.

#### Constraints

**This problem uses bundled testdata.**

- Subtask 1 (5 pts): $N \le 20$.
- Subtask 2 (15 pts): $N \le 40$.
- Subtask 3 (10 pts): If vertices $u$ and $v$ satisfy $|u-v|=1$, then there is an edge between them.
- Subtask 4 (40 pts): Each vertex is connected to at most $3$ vertices.
- Subtask 5 (30 pts): No special restrictions.

For $100\%$ of the testdata, $3 \le N \le 10^5$.

#### Note

Translated from [BalticOI 2021 Day2 C The Xana coup](https://boi.cses.fi/files/boi2021_day2.pdf).

Translated by ChatGPT 5