# P8050 [ZYOI Round1] Chessboard game/棋盘游戏

## 题目背景

子衿有一个游戏棋盘，此时准备拿出来玩玩。

## 题目描述

她的棋盘是 L 字形的，由上面一个 $n_1 \times m_1$ 的小长方形和下面一个 $n_2 \times m_2$ 的大长方形组成。棋盘初始状态所有格子上的数都为 $k$。

比如，当 $n_1 = 2$，$m_1 = 2$，$n_2 = 3$，$m_2 = 4$，$k = 0$ 时，棋盘初始是这样的：

```
0 0
0 0
0 0 0 0
0 0 0 0
0 0 0 0
```

现在她要进行若干次操作：将相邻的两个格子中的数同时加 $1$ 或减 $1$。操作完成后她会记住这些格子上的数。

可是她有一次不小心，经过若干次操作后忘掉了其中某一个数是多少了，于是在上面打了一个 $999999$。请你通过编程求出被打上 $999999$ 的数应该是多少。保证有且仅有一个格子被打上了 $999999$。

## 输入格式

第一行输入五个整数 $n_1,m_1,n_2,m_2,k$，分别表示组成 L 字形棋盘小长方形的行数和列数，大长方形的行数和列数，以及初始格子上的数。

接下来 $n_1$ 行，每行输入 $m_1$ 个整数，表示操作后的棋盘小长方形中每个格子中的数。

接下来 $n_2$ 行，每行输入 $m_2$ 个整数，表示操作后的棋盘大长方形中每个格子中的数。

未知的数以 $999999$ 代替。

## 输出格式

一行，一个整数，表示被打上 $999999$ 的数原本的值。

数据保证有解。

## 输入输出样例 #1

### 输入 #1

```
2 2 3 4 0
0 0
1 0
2 1 1 0
0 1 999999 0
0 0 0 0
```

### 输出 #1

```
2
```

## 说明/提示

对于 $40\%$ 的数据，$n_1 = m_1 = 0$。

对于 $100\%$ 的数据，$m_1 < m_2$，$0 \le n_1,m_1,k \le 100$，$1 \le n_2,m_2 \le 100$，每个格子中的数 $\ge -1000$ 且 $\le 1000$，除前 $40\%$ 的数据外剩下的 $60\%$ 的数据保证 $n_1,m_1 > 0$。

**【样例说明】**

一开始棋盘是这样的：

```
0 0
0 0
0 0 0 0
0 0 0 0
0 0 0 0
```

下面给出一种可行的操作方案：

先将第 $2$ 行第 $1$ 个数与第 $3$ 行第 $1$ 个数同时加 $1$：

```
0 0
1 0
1 0 0 0
0 0 0 0
0 0 0 0
```

再将第 $3$ 行第 $1$ 个数与第 $3$ 行第 $2$ 个数同时加 $1$：

```
0 0
1 0
2 1 0 0
0 0 0 0
0 0 0 0
```

再将第 $3$ 行第 $3$ 个数与第 $4$ 行第 $3$ 个数同时加 $1$：

```
0 0
1 0
2 1 1 0
0 0 1 0
0 0 0 0
```

最后将第 $4$ 行第 $2$ 个数与第 $4$ 行第 $3$ 个数同时加 $1$：

```
0 0
1 0
2 1 1 0
0 1 2 0
0 0 0 0
```

可以得出被打上 $999999$ 的数（第 $4$ 行第 $3$ 个数）为 $2$。

操作方案可能不唯一，但可以证明答案是唯一的。

---

# P8050 [ZYOI Round1] Chessboard game/Chessboard Game

## 题目背景

Zijin has a game board and is going to take it out to play.

## 题目描述

Her board is L-shaped. It consists of an upper small rectangle of size $n_1 \times m_1$ and a lower large rectangle of size $n_2 \times m_2$. Initially, the number in every cell on the board is $k$.

For example, when $n_1 = 2$, $m_1 = 2$, $n_2 = 3$, $m_2 = 4$, $k = 0$, the initial board looks like this:

```
0 0
0 0
0 0 0 0
0 0 0 0
0 0 0 0
```

Now she will perform several operations: add $1$ or subtract $1$ to the numbers in two adjacent cells at the same time. After finishing the operations, she will remember the numbers in these cells.

However, she made a mistake once. After several operations, she forgot what one of the numbers was, so she wrote $999999$ there. Please write a program to find what the number marked as $999999$ should be. It is guaranteed that exactly one cell is marked as $999999$.

## 输入格式

The first line contains five integers $n_1, m_1, n_2, m_2, k$, representing the number of rows and columns of the small rectangle forming the L-shaped board, the number of rows and columns of the large rectangle, and the initial number in each cell.

Next come $n_1$ lines, each containing $m_1$ integers, describing the numbers in each cell of the small rectangle after the operations.

Next come $n_2$ lines, each containing $m_2$ integers, describing the numbers in each cell of the large rectangle after the operations.

The unknown number is replaced by $999999$.

## 输出格式

Output one line with one integer, which is the original value of the number marked as $999999$.

The testdata guarantees that a solution exists.

## 输入输出样例 #1

### 输入 #1

```
2 2 3 4 0
0 0
1 0
2 1 1 0
0 1 999999 0
0 0 0 0
```

### 输出 #1

```
2
```

## 说明/提示

For $40\%$ of the testdata, $n_1 = m_1 = 0$.

For $100\%$ of the testdata, $m_1 < m_2$, $0 \le n_1, m_1, k \le 100$, $1 \le n_2, m_2 \le 100$, and the number in each cell satisfies $-1000 \le$ value $\le 1000$. Besides the first $40\%$ of the testdata, the remaining $60\%$ of the testdata guarantees $n_1, m_1 > 0$.

**Sample Explanation**

At the beginning, the board is like this:

```
0 0
0 0
0 0 0 0
0 0 0 0
0 0 0 0
```

One possible sequence of operations is given below:

First, add $1$ to the number in row $2$ column $1$ and the number in row $3$ column $1$ at the same time:

```
0 0
1 0
1 0 0 0
0 0 0 0
0 0 0 0
```

Then, add $1$ to the number in row $3$ column $1$ and the number in row $3$ column $2$ at the same time:

```
0 0
1 0
2 1 0 0
0 0 0 0
0 0 0 0
```

Then, add $1$ to the number in row $3$ column $3$ and the number in row $4$ column $3$ at the same time:

```
0 0
1 0
2 1 1 0
0 0 1 0
0 0 0 0
```

Finally, add $1$ to the number in row $4$ column $2$ and the number in row $4$ column $3$ at the same time:

```
0 0
1 0
2 1 1 0
0 1 2 0
0 0 0 0
```

It can be concluded that the number marked as $999999$ (the number in row $4$ column $3$) is $2$.

The sequence of operations may not be unique, but it can be proven that the answer is unique.

Translated by ChatGPT 5