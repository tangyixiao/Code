# P7846 「dWoi R2」Arcade hall / 街机厅

## 题目背景

众所周知，才囚学院地下有一个街机厅，~~百田被星龙马打败了 114514 次~~。

百田不服气，于是他打开了一个单人游戏 —— 先辈的城市。

---

114514 年，火星，幺舅幺舅巴以灵国。

因为有小可爱提出题面过于冗长，所以下方有 **简要题面**。

## 题目描述

幺舅幺舅巴以灵国一共有 $n$ 个城市，他们之间用一种神奇的通讯工具 —— 先辈符，第 $i$ 个城市的先辈符上刻有一个正整数 $w_i$。这 $n$ 个城市之前有 $n-1$ 条道路，第 $j$ 条道路连接第 $u_j$ 个城市和第 $v_j$ 个城市，有一个属性 $t_j$，这一条道路就表示为 $(u_j,v_j,t_j)$，其中 $t_j \in \{0,1,2\}$，意为：

- $t_j=0$ 时，第 $u_j$ 个城市与第 $v_j$ 个城市是敌对关系；
- $t_j=1$ 时，第 $u_j$ 个城市与第 $v_j$ 个城市是平等关系；
- $t_j=2$ 时，第 $u_j$ 个城市与第 $v_j$ 个城市是友好关系。

每一条道路都是双向的，并且保证任意两个城市 $u,v$ 之间都是可以互相到达的。

最近火星发生了 MARS-514 病毒疫情，先辈符系统的修建要加快脚步。我们规定：

- $w_i \in [1,R]$，且是一个正整数；
- 对于一条道路 $(p,q,r)$，有如下要求：
	- 当 $r=0$ 时，即第 $p$ 个城市与第 $q$ 个城市处于敌对关系时，需要保证 $w_p \ne w_q$；
    - 当 $r=2$ 时，即第 $p$ 个城市与第 $q$ 个城市处于友好关系时，需要保证 $w_p=w_q$；
    - 当 $r=1$ 时，即第 $p$ 个城市与第 $q$ 个城市处于平等关系时，不需要保证 $w_p$ 与 $w_q$ 的大小关系。
    
求这样分配 $w_i$ 后，将 $w_i$ 作为一个序列，会形成多少个本质不同的序列 $w_i$。

额外地，幺舅幺舅巴以灵国的统治者浩二结节在建造先辈符发现 $w_i$ 越大，用墨就会越多，建造起来也会越困难，所以浩二结节想知道 $w_i$ 的和的最小值是多少。

注意，本题的序列 $A_i$ 与 $B_i$ 本质相同当且仅当对于所有 $i$ 都有 $A_i=B_i$。

本质不同即为不满足本质相同的两个序列。

---

**简要题面**：

- 有一棵 $n$ 个点的树，第 $i$ 个点有点权 $w_i$，第 $j$ 条边有边权 $t_j$；
- 每一条边 $(u_j,v_j,t_j)$ 两边点的点权有如下要求：
	- $t_j=0$，$w_{u_j} \ne w_{v_j}$；
    - $t_j=1$，没有要求；
    - $t_j=2$，$w_{u_j}=w_{v_j}$；
    - 对任意点权都要有 $w_i \in [1,R]$；
- 求当 $w_i$ 作为序列时，一共有多少种本质不同的序列 $w_i$ 以及 $w_i$ 的和的最小值。

## 输入格式

第一行两个整数 $n,R$ 代表城市数与值域。

接下来 $n-1$ 行每行三个整数 $u_j,v_j,t_j$ 描述一条道路。

## 输出格式

一行两个整数分别代表满足要求的本质不同的序列 $w_i$ 的个数和 $w_i$ 的和的最小值。

如果不存在本质不同的序列（即第一问答案为 $0$），第二问也请输出一个 $0$。

**只有第一问答案对 $10^9+7$ 取模。**

## 输入输出样例 #1

### 输入 #1

```
3 3
1 2 0
1 3 0
```

### 输出 #1

```
12 4
```

## 输入输出样例 #2

### 输入 #2

```
9 3
1 2 0
1 3 1
1 4 1
2 5 2
2 6 1
6 7 0
4 8 2
4 9 0
```

### 输出 #2

```
648 12
```

## 说明/提示

#### 样例 1 解释

样例中的道路分布如下：

![](https://cdn.luogu.com.cn/upload/image_hosting/vq4dukx8.png)

一共有 $12$ 种赋值方式：

1. $w_i=\{1,2,2\}$；
2. $w_i=\{1,2,3\}$；
3. $w_i=\{1,3,2\}$；
4. $w_i=\{1,3,3\}$；
5. $w_i= \bf \{2,1,1\}$，这是最优情况；
6. $w_i=\{2,1,3\}$；
7. $w_i=\{2,3,1\}$；
8. $w_i=\{2,3,3\}$；
9. $w_i=\{3,1,1\}$；
10. $w_i=\{3,1,2\}$；
11. $w_i=\{3,2,1\}$；
12. $w_i=\{3,2,2\}$。

#### 样例 2 解释

样例中的道路分布如下：

![](https://cdn.luogu.com.cn/upload/image_hosting/9f1qjpm4.png)

对于第二问，其中一种最优的赋值方式是：$w_i=\{2,1,1,1,1,1,2,1,2\}$。

#### 数据规模与约定

**本题采用捆绑测试。**

- Subtask 1（5 pts）：$t_j=1$ 或 $t_j=2$；
- Subtask 2（5 pts）：$R=1$；
- Subtask 3（10 pts）：$u_j=j$，$v_j=j+1$；
- Subtask 4（20 pts）：$t_j=0$；
- Subtask 5（10 pts）：$n \le 10$，$R \le 5$；
- Subtask 6（50 pts）：无特殊限制。

对于 $100\%$ 的数据，$1 \le n \le 10^5$，$1 \le R \le 100$。

对于 Subtask 1 ~ 5，$R \le 40$。

上面描述 Subtask 时 $t_j=P$ 即为对于所有 $j \in [1,n)$ 都有 $t_j=P$。

其中对于 Subtask 1，“或” 意为 Subtask
1 的一部分测试点满足 $t_j=1$，另一部分测试点满足 $t_j=2$。

---

# P7846 “dWoi R2” Arcade hall / Arcade Hall.

## 题目背景

As everyone knows, there is an arcade hall under Caiqiu Academy, ~~and Baitian was defeated by Xinglongma 114514 times~~.

Baitian was not convinced, so he opened a single-player game — City of the Senpai.

---

In the year 114514, on Mars, in the country of Yaoyao-Yaoyao-Ba-Yiling.

Since someone said the statement is too long, a **brief statement** is provided below.

## 题目描述

The country of Yaoyao-Yaoyao-Ba-Yiling has $n$ cities. They are connected by a magical communication tool — the “Senpai Talisman”. The Senpai Talisman of the $i$-th city is engraved with a positive integer $w_i$. There are $n-1$ roads among these $n$ cities. The $j$-th road connects city $u_j$ and city $v_j$, and has an attribute $t_j$. This road is denoted as $(u_j,v_j,t_j)$, where $t_j \in \{0,1,2\}$, meaning:

- When $t_j=0$, city $u_j$ and city $v_j$ are in an antagonistic relationship.
- When $t_j=1$, city $u_j$ and city $v_j$ are in an equal relationship.
- When $t_j=2$, city $u_j$ and city $v_j$ are in a friendly relationship.

Each road is bidirectional, and it is guaranteed that any two cities $u,v$ are mutually reachable.

Recently, Mars has suffered from the MARS-514 virus outbreak, so the construction of the Senpai Talisman system must be accelerated. We define:

- $w_i \in [1,R]$, and $w_i$ is a positive integer.
- For a road $(p,q,r)$, the following requirements must be satisfied:
	- When $r=0$, i.e., city $p$ and city $q$ are antagonistic, it must hold that $w_p \ne w_q$.
	- When $r=2$, i.e., city $p$ and city $q$ are friendly, it must hold that $w_p=w_q$.
	- When $r=1$, i.e., city $p$ and city $q$ are equal, there is no requirement on the relationship between $w_p$ and $w_q$.

After assigning values to $w_i$, treat $w_i$ as a sequence. Determine how many essentially different sequences $w_i$ can be formed.

In addition, the ruler of Yaoyao-Yaoyao-Ba-Yiling, Haoer Jiejie, found that the larger $w_i$ is, the more ink is needed, and the harder it is to build. Therefore, Haoer Jiejie wants to know the minimum possible value of the sum of $w_i$.

Note that, in this problem, sequences $A_i$ and $B_i$ are essentially the same if and only if for all $i$, $A_i=B_i$.

“Essentially different” means two sequences that are not essentially the same.

---

**Brief statement**:

- There is a tree with $n$ nodes. Node $i$ has a node weight $w_i$, and edge $j$ has an edge weight $t_j$.
- For each edge $(u_j,v_j,t_j)$, the endpoint node weights must satisfy:
	- $t_j=0$, $w_{u_j} \ne w_{v_j}$.
	- $t_j=1$, no requirement.
	- $t_j=2$, $w_{u_j}=w_{v_j}$.
	- For any node weight, $w_i \in [1,R]$.
- When $w_i$ is treated as a sequence, find (1) the number of essentially different sequences $w_i$, and (2) the minimum possible sum of $w_i$.

## 输入格式

The first line contains two integers $n,R$, representing the number of cities and the value range.

The next $n-1$ lines each contain three integers $u_j,v_j,t_j$, describing a road.

## 输出格式

Output one line with two integers: the number of essentially different sequences $w_i$ that satisfy the requirements, and the minimum possible sum of $w_i$.

If there is no essentially different sequence (i.e., the answer to the first question is $0$), then output $0$ for the second question as well.

**Only the first answer is taken modulo $10^9+7$.**

## 输入输出样例 #1

### 输入 #1

```
3 3
1 2 0
1 3 0
```

### 输出 #1

```
12 4
```

## 输入输出样例 #2

### 输入 #2

```
9 3
1 2 0
1 3 1
1 4 1
2 5 2
2 6 1
6 7 0
4 8 2
4 9 0
```

### 输出 #2

```
648 12
```

## 说明/提示

#### Explanation for Sample 1

The roads in the sample are distributed as follows:

![](https://cdn.luogu.com.cn/upload/image_hosting/vq4dukx8.png)

There are $12$ assignment methods in total:

1. $w_i=\{1,2,2\}$.
2. $w_i=\{1,2,3\}$.
3. $w_i=\{1,3,2\}$.
4. $w_i=\{1,3,3\}$.
5. $w_i= \bf \{2,1,1\}$, this is the optimal case.
6. $w_i=\{2,1,3\}$.
7. $w_i=\{2,3,1\}$.
8. $w_i=\{2,3,3\}$.
9. $w_i=\{3,1,1\}$.
10. $w_i=\{3,1,2\}$.
11. $w_i=\{3,2,1\}$.
12. $w_i=\{3,2,2\}$.

#### Explanation for Sample 2

The roads in the sample are distributed as follows:

![](https://cdn.luogu.com.cn/upload/image_hosting/9f1qjpm4.png)

For the second question, one optimal assignment is: $w_i=\{2,1,1,1,1,1,2,1,2\}$.

#### Constraints and Notes

**This problem uses bundled testdata.**

- Subtask 1 (5 pts): $t_j=1$ or $t_j=2$.
- Subtask 2 (5 pts): $R=1$.
- Subtask 3 (10 pts): $u_j=j$, $v_j=j+1$.
- Subtask 4 (20 pts): $t_j=0$.
- Subtask 5 (10 pts): $n \le 10$, $R \le 5$.
- Subtask 6 (50 pts): no special constraints.

For $100\%$ of the testdata, $1 \le n \le 10^5$, $1 \le R \le 100$.

For Subtask 1 ~ 5, $R \le 40$.

In the subtask descriptions above, $t_j=P$ means that for all $j \in [1,n)$, $t_j=P$.

For Subtask 1, “or” means that part of the test points in Subtask 1 satisfy $t_j=1$, and the other part satisfy $t_j=2$.

Translated by ChatGPT 5