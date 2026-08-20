# P1345 [USACO5.4] 奶牛的电信 Telecowmunication

## 题目描述

农夫约翰的奶牛们喜欢通过电邮保持联系，于是她们建立了一个奶牛电脑网络，以便互相交流。这些机器用如下的方式发送电邮：如果存在一个由 $c$ 台电脑组成的序列 $a_1,a_2,\cdots ,a_c$，且 $a_1$ 与 $a_2$ 相连，$a_2$ 与 $a_3$ 相连，等等。那么电脑 $a_1$ 和 $a_c$ 就可以互发电邮。

很不幸，有时候奶牛会不小心踩到电脑上，农夫约翰的车也可能碾过电脑，这台倒霉的电脑就会坏掉。这意味着这台电脑不能再发送电邮了，于是与这台电脑相关的连接也就不可用了。

有两头奶牛就想：如果我们两个不能互发电邮，至少需要坏掉多少台电脑呢？请注意，$c_1,c_2$ 不能被破坏。请编写一个程序为她们计算这个最小值。

以如下网络为例：

```plain
   1*
  /
 3 - 2*
```

这张图画的是有 $2$ 条连接的 $3$ 台电脑。我们想要在电脑 $1$ 和 $2$ 之间传送信息。电脑 $1$ 与 $3$，$2$ 与 $3$ 直接连通。如果电脑 $3$ 坏了，电脑 $1$ 与 $2$ 便不能互发信息了。

## 输入格式

第一行：四个由空格分隔的整数：$N,M,c_1,c_2$。$N$ 是电脑总数，电脑由 $1$ 到 $N$ 编号。$M$ 是电脑之间连接的总数。后面的两个整数 $c_1$ 和 $c_2$ 是上述两头奶牛使用的电脑编号。连接没有重复且均为双向的（即如果 $c_1$ 与 $c_2$ 相连，那么 $c_2$ 与 $c_1$ 也相连）。两台电脑之间至多有一条连接。电脑 $c_1$ 和 $c_2$ 不会直接相连。

第 $2$ 到 $M+1$ 行：接下来的 $M$ 行中，每行包含两台直接相连的电脑的编号。

## 输出格式

一行，一个整数，表示使电脑 $c_1$ 和 $c_2$ 不能互相通信需要坏掉的电脑数目的最小值。

## 输入输出样例 #1

### 输入 #1

```
3 2 1 2
1 3
2 3
```

### 输出 #1

```
1

```

## 说明/提示

对于 $100\%$ 的数据：$1\le N \le 100$，$1\le M \le 600$。

---

# P1345 [USACO5.4] Telecowmunication

## 题目描述

Farmer John's cows like to keep in touch by email, so they set up a cow computer network to communicate. The machines send email as follows: if there exists a sequence of $c$ computers $a_1,a_2,\cdots ,a_c$ such that $a_1$ is connected to $a_2$, $a_2$ is connected to $a_3$, and so on, then computers $a_1$ and $a_c$ can exchange email.

Unfortunately, sometimes a cow may accidentally step on a computer, and Farmer John's truck might run over a computer, and that unlucky computer will break. This means that computer can no longer send email, and all connections incident to it become unusable.

Two cows wonder: if the two of us are to be unable to email each other, what is the minimum number of computers that must fail? Note that $c_1$ and $c_2$ cannot be destroyed. Please write a program to compute this minimum.

Consider the following network:

```plain
   1*
  /
 3 - 2*
```

This figure shows $3$ computers with $2$ connections. We want to send messages between computers $1$ and $2$. Computer $1$ is directly connected to $3$, and $2$ is directly connected to $3$. If computer $3$ fails, then $1$ and $2$ can no longer communicate.

## 输入格式

The first line contains four space-separated integers: $N, M, c_1, c_2$. $N$ is the total number of computers, numbered from $1$ to $N$. $M$ is the total number of connections. The last two integers $c_1$ and $c_2$ are the computers used by the two cows mentioned above. Connections have no duplicates and are undirected (i.e., if $c_1$ is connected to $c_2$, then $c_2$ is connected to $c_1$ as well). There is at most one connection between any pair of computers. Computers $c_1$ and $c_2$ are not directly connected.

Lines $2$ to $M+1$: each of the next $M$ lines contains the indices of two directly connected computers.

## 输出格式

One line containing a single integer: the minimum number of computers that must fail to make computers $c_1$ and $c_2$ unable to communicate with each other.

## 输入输出样例 #1

### 输入 #1

```
3 2 1 2
1 3
2 3
```

### 输出 #1

```
1

```

## 说明/提示

For $100\%$ of the testdata: $1 \le N \le 100$, $1 \le M \le 600$.

Translated by ChatGPT 5