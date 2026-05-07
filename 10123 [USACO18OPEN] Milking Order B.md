# P10123 [USACO18OPEN] Milking Order B

## 题目描述

Farmer John 的 $N$ 头奶牛（$2\le N\le 100$），方便起见仍然编号为 $1\ldots N$，正好闲得发慌。因此，她们发展了一个与 Farmer John 每天早上为她们挤牛奶的时候的排队顺序相关的复杂的社会结构。经过若干周的研究，Farmer John 发现这个结构基于两个关键特性。

首先，由于奶牛们的社会阶层，某些奶牛会坚持要在其他奶牛之前挤奶，基于她们的社会地位等级。比方说，如果奶牛 $3$ 有最高的地位，奶牛 $2$ 位于中等地位，奶牛 $5$ 是低地位，那么奶牛 $3$ 会最早挤奶，然后是奶牛 $2$，最后是奶牛 $5$。

然后，有些奶牛只允许她们在排队顺序中一个特定的位置挤奶。比方说，奶牛 $4$ 可能坚持要在所有奶牛中的第二位挤奶。

幸运的是，Farmer John 总是能够以一种满足所有这些情况的顺序给他的奶牛们挤奶。

不幸的是，奶牛 $1$ 最近生病了，所以 Farmer John 想要尽早给这头奶牛挤奶，使得她可以回到牛棚获得急需的休息。请帮助 Farmer John 求出奶牛 $1$ 可以在挤奶顺序中出现的最早位置。

## 输入格式

第一行包含 $N$，$M$（$1\le M<N$），和 $K$（$1\le K<N$），表示 Farmer John 有 $N$ 头奶牛，其中 $M$ 头形成了社会阶层，$K$ 头需要在挤奶顺序中处于一个特定的位置。下一行包含 $M$ 个不同的整数 $m_i$（$1\le m_i\le N$）。在这一行出现的奶牛必须以与她们在这行出现的顺序相同的顺序进行挤奶。下面 $K$ 行，每行包含两个整数 $c_i$（$1\le c_i\le N$）和 $p_i$（$1\le p_i\le N$），表示奶牛 $c_i$ 一定要在第 $p_i$ 位进行挤奶。

输入数据保证在这些限制之下，Farmer John 能够建立一个符合要求的挤奶顺序。

## 输出格式

输出奶牛 $1$ 可以在挤奶顺序中出现的最早位置。

## 输入输出样例 #1

### 输入 #1

```
6 3 2
4 5 6
5 3
3 1
```

### 输出 #1

```
4
```

## 说明/提示

在这个例子中，Farmer John 有六头奶牛，其中奶牛 $1$ 生病了。他的挤奶顺序应该为奶牛 $4$ 在奶牛 $5$ 之前，奶牛 $5$ 在奶牛 $6$ 之前。此外，Farmer John 必须要第一个给奶牛 $3$ 挤奶，第三个给奶牛 $5$ 挤奶。

FJ 必须第一个给奶牛 $3$ 挤奶，由于奶牛 $4$ 必须要在奶牛 $5$ 之前，奶牛 $4$ 一定是第二个挤奶的，然后奶牛 $5$ 第三个。于是，奶牛 $1$ 最早在挤奶顺序中出现的位置是第四个。

---

# P10123 [USACO18OPEN] Milking Order B

## 题目描述

Farmer John’s $N$ cows ($2\le N\le 100$), conveniently numbered $1\ldots N$, have been feeling bored. So, they have developed a complex social structure related to the order they line up in each morning when Farmer John milks them. After several weeks of study, Farmer John has found that this structure is based on two key properties.

First, because of the cows’ social ranks, some cows insist on being milked before other cows, based on their rank. For example, if cow $3$ has the highest rank, cow $2$ is in the middle, and cow $5$ is low-ranked, then cow $3$ must be milked first, then cow $2$, and finally cow $5$.

Second, some cows will only allow themselves to be milked at a specific position in the line. For example, cow $4$ might insist on being the second cow to be milked out of all the cows.

Fortunately, Farmer John can always milk his cows in an order that satisfies all of these conditions.

Unfortunately, cow $1$ has recently become sick, so Farmer John wants to milk her as early as possible, so she can return to the barn for some much-needed rest. Please help Farmer John determine the earliest possible position where cow $1$ can appear in the milking order.

## 输入格式

The first line contains $N$, $M$ ($1\le M<N$), and $K$ ($1\le K<N$), meaning Farmer John has $N$ cows, of which $M$ form a social hierarchy, and $K$ must be in specific positions in the milking order. The next line contains $M$ distinct integers $m_i$ ($1\le m_i\le N$). The cows listed on this line must be milked in the same relative order as they appear in this line. The following $K$ lines each contain two integers $c_i$ ($1\le c_i\le N$) and $p_i$ ($1\le p_i\le N$), meaning cow $c_i$ must be milked in position $p_i$.

The input guarantees that under these constraints, Farmer John can construct a milking order that satisfies all requirements.

## 输出格式

Output the earliest possible position where cow $1$ can appear in the milking order.

## 输入输出样例 #1

### 输入 #1

```
6 3 2
4 5 6
5 3
3 1
```

### 输出 #1

```
4
```

## 说明/提示

In this example, Farmer John has six cows, and cow $1$ is sick. His milking order must have cow $4$ before cow $5$, and cow $5$ before cow $6$. Also, Farmer John must milk cow $3$ first, and cow $5$ third.

Since FJ must milk cow $3$ first, and because cow $4$ must be before cow $5$, cow $4$ has to be milked second, and then cow $5$ third. Therefore, the earliest possible position for cow $1$ in the milking order is fourth.

Translated by ChatGPT 5