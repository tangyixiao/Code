# P3421 [POI 2005] SKO-Knights

## 题目描述

一个骑士在一个无限的棋盘上移动。它可以执行的每一个动作都由一对整数 $(a,b)$ 来描述——表示这个骑士可以从 $(x,y)$ 移动到 $(x+a,y+b)$ 或者 $(x-a,y-b)$ 。这个骑士有 $n$ 组这样的移动描述，表示了它可以做出的移动。我们保证骑士从 $(0,0)$ 出发移动到的所有位置并非都共线。

如果两个骑士从 $(0,0)$ 出发到达的位置集合全等，我们就说它们是等价的。(请注意，两个骑士可以分别移动不同的步数)。可以证明，对于每一个骑士，都存在另一个仅由两组 $(a,b)$ 描述的骑士与其全等。

你的任务是写一个程序，读入对骑士移动的表示，然后确定两对表示等价的骑士移动的整数，并输出这两对整数。

## 输入格式

第一行读入一个整数 $n$，表示骑士的移动方式数（$3\le n\le 100$）。接下来 $n$ 行为表示骑士移动的整数对，每一行是一对整数 $a_i$ 和 $b_i$，并由一个空格分隔开，$-100\le a_i,b_i\le 100,(a_i,b_i)\neq (0,0)$。

## 输出格式

第一行输出两个整数 $a$ 和 $b$，并由一个空格分隔。

第二行输出两个整数 $c$ 和 $d$，并由一个空格分隔。

上述整数应满足以下条件：$-10000\le a,b,c,d\le 10000$，且输出的两对整数描述的骑士和输入数据中描述的骑士是等价的。

## 输入输出样例 #1

### 输入 #1

```
3
24 28
15 50
12 21
```

### 输出 #1

```
3 0
0 1
```

---

# P3421 [POI 2005] SKO-Knights

## 题目描述

A knight moves on an infinite chessboard. Each move it can perform is described by a pair of integers $(a,b)$, meaning the knight can move from $(x,y)$ to $(x+a,y+b)$ or to $(x-a,y-b)$. Each knight has a set of such move descriptions, representing the moves it can perform. We assume that all positions reachable by a knight starting from $(0,0)$ are not collinear.

We say two knights are equivalent if they can reach exactly the same set of coordinates from $(0,0)$. (Note that the same knight may reach those squares using different sequences of moves.) It can be shown that for every knight there exists an equivalent knight whose moves can be described by only two pairs of integers.

Your task is to read a set of move descriptions for a knight, determine two pairs of integers that describe an equivalent knight, and output these two pairs.

## 输入格式

The first line contains an integer $n$ ($3\le n\le 100$), the number of move pairs.  
Each of the next $n$ lines contains a pair of integers $a_i$ and $b_i$ separated by a space, where $-100\le a_i,b_i\le 100$ and $(a_i,b_i)\neq(0,0)$.

## 输出格式

Output two lines.  
The first line contains two integers $a$ and $b$ separated by a space.  
The second line contains two integers $c$ and $d$ separated by a space.

These integers must satisfy $-10000\le a,b,c,d\le 10000$, and the two output pairs must describe a knight equivalent to the knight described in the input.

## 输入输出样例 #1

### 输入 #1

```
3
24 28
15 50
12 21
```

### 输出 #1

```
3 0
0 1
```

## 说明/提示

Translated by ChatGPT 5