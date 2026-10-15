# P6889 [CEOI 2006] CONNECT

## 题目描述

早些年，当著名的十六位三字母操作系统最常用于 25x80 终端并主导 PC 市场时，“Nibbles” 是每个人最喜欢的电脑游戏。然而，这个问题与 Nibbles 无关——它与一个名为“Connect”的游戏有关，这个游戏几乎完全不像 Nibbles。

Connect 在一个由方格组成的棋盘上进行，棋盘由 R 行和 C 列组成，其中 R 和 C 都是**奇数**。行和列分别编号为 1 到 R 和 1 到 C。棋盘上的每个位置要么是空闲的，要么被墙壁阻挡。此外，每个棋盘满足以下约束：

- **两个坐标都是偶数**的方格称为房间。它们**永远不会被阻挡**。
- **两个坐标都是奇数**的方格称为障碍物。它们**总是被阻挡**。
- 所有其他方格称为走廊。它们可能被阻挡，也可能不被阻挡。
- **沿着棋盘边缘**的走廊**总是被阻挡**。

障碍物用 '+'（加号）字符表示，阻挡的水平走廊用 '|'（竖线）字符表示，而阻挡的垂直走廊用 '–'（减号）字符表示。房间和空闲走廊用空白字符表示。

在游戏开始时，**偶数个**棋子（用大写字母 'X' 表示）被放置在棋盘上——每个棋子在一个单独的**房间**里。棋子 A 和 B 之间的路径是一系列**空闲**方格，从 A 开始，以 B 结束，每一步都在**四个可能的方向**之一移动（路径包括两个端点方格，A 和 B）。路径的长度是从 A 到 B 所需的总步数（等于路径中包含的方格数减一）。

玩家的目标是首先**将所有棋子分成对**，然后，对于每对棋子，**用路径连接**这两个棋子。对应该以这样的方式连接，即**没有两条路径共享一个公共方格**。

对于完成的游戏，得分定义为所有路径的长度之和。

编写一个程序，给定 Connect 游戏的起始位置，以实现**可能的最小得分**来进行游戏。测试数据将保证一个解，尽管不一定是唯一的，总是存在的。

## 输入格式

第一行输入为两个整数：$R$ 和 $C$，其中 $R$ 为行数，$C$ 为列数，$R$，$C$ 均为奇数。

接下来的 $R$ 行每行包括 $C$ 个字符，每个字符都是 `+`、`|`、`-`、空格或 `X` 中的一个，分别表示障碍及两种墙壁，空格表示房间或可通过的走廊，`X` 表示房间中的物品。

## 输出格式

输出的第一行是一个整数，即最小分值。

本题**不要求**输出合法方案。

## 输入输出样例 #1

### 输入 #1

```
17 15
+-+-+-+-+-+-+-+
|             |
+ + + + + + + +
|X  |   |     |
+ + + + + + + +
|   |   |  X  |
+-+ + + + + + +
|       |     |
+ + + +-+-+-+-+
|            X|
+ + +-+-+-+-+ +
|             |
+ + + + + + + +
|  X|         |
+ + + + + + + +
|  |          |
+-+-+-+-+-+-+-+
```

### 输出 #1

```
30

```

## 说明/提示

$5 \leqslant R \leqslant 25$，$5 \leqslant C \leqslant 80$。

题面翻译由 ChatGPT-4o 提供。

---

# P6889 [CEOI 2006] CONNECT

## 题目描述

Back in the day when the famous sixteen-bit three-letter operating system most often used on an 25x80 terminal dominated the PC market, "Nibbles" was everyone's favorite computer game. This problem, however, is not related to Nibbles – it is related to a game called "Connect" which is almost, but not quite, entirely unlike
Nibbles.

Connect is played on a board composed of squares organized into R rows and $C$ columns, where both $R$ and $C$ are **odd numbers**. Rows and columns are numbered $1$ to $R$ and $1$ to $C$, respectively. Each position on the board
is either free or blocked by a wall. Additionally, each board satisfies the following constraints:

- Squares with **both coordinates even** are called rooms. They are **never blocked**.
- Squares with **both coordinates odd** are called barriers. They are **always blocked**
- All other squares are called corridors. They may or may not be blocked.
- Corridors **along the edge** of the board are **always blocked**.

Barriers are represented by the '+' (plus) character, blocked horizontal corridors by the '|' (pipe) character, while blocked vertical corridors are represented by the '–' (minus) character. Rooms and free corridors are represented by the blank character.

  At the beginning of the game an **even number** of figures (represented by the uppercase letter 'X') are placed on the board – each in a separate **room**. $A$ path between figures $A$ and $B$ is a sequence of **free** squares starting from $A$, ending with $B$ and moving in one of the **four possible directions** in each step (the path includes both endpoint squares, $A$ and $B$). The length of the path is the total number of steps needed to get from $A$ to $B$  (which is equal to the number of squares contained in the path minus one).

  The goal of the player is to first **divide all the figures into pairs**, and then, for each pair, **connect** the two figures with a path. The pairs should be connected in such a way that **no two paths share a common square**.

  For a completed game, the score is defined as **the sum of the lengths** of all paths.

![](https://cdn.luogu.com.cn/upload/image_hosting/3ytczh4t.png)

Write a program that, given the starting position of the Connect game, plays the game in such a way that the **minimum possible score** is achieved.
The test data will guarantee that a solution, although not necessarily unique, will always exist.

## 输入格式

The first line of input is two integers: $R$ and $C$, where $R$ is the number of rows and $C$ is the number of columns. $R$ and $C$ are both odd numbers.

The next $R$ lines each contain $C$ characters, each of which is one of `+`, `|`, `-`, space or `X`, representing obstacles and two types of walls, respectively, a space represents a room or a passable corridor, and `X` represents an item in the room.

## 输出格式

The first line of output is an integer, which is the minimum score.

This task **does not** require outputting a legal solution

## 输入输出样例 #1

### 输入 #1

```
17 15
+-+-+-+-+-+-+-+
|             |
+ + + + + + + +
|X  |   |     |
+ + + + + + + +
|   |   |  X  |
+-+ + + + + + +
|       |     |
+ + + +-+-+-+-+
|            X|
+ + +-+-+-+-+ +
|             |
+ + + + + + + +
|  X|         |
+ + + + + + + +
|  |          |
+-+-+-+-+-+-+-+
```

### 输出 #1

```
30

```

## 说明/提示

$5 \leqslant R \leqslant 25$，$5 \leqslant C \leqslant 80$