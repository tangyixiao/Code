# P2864 [USACO06JAN] The Grove S

## 题目描述

牧场里有树林，林子里没有坑，贝茜很想知道，最少几步能绕树林走一圈，最后回到起点.她能上下左右走，也能走对角线格子.

牧场被分成 $R$ 行 $C$ 列 $(1\leq R\leq 50,1\leq C\leq 50)$。下面是一张样例的地图，其中 `.` 表示贝茜可以走的空地，`X` 表示树林，`*` 表示起点。而贝茜走的最近的路已经特别地用 `+` 表示出来：

```plain
...+...
..+X+..
.+XXX+.
..+XXX+
..+X..+
...+++*
```

题目**保证存在最短路径**，且森林形成一个联通块。

## 输入格式

第一行两个正整数 $R,C$。

下面 $R$ 行，一个 $R \times C$ 的字符矩阵。

## 输出格式

一行一个整数表示答案。

## 输入输出样例 #1

### 输入 #1

```
6 7
.......
...X...
..XXX..
...XXX.
...X...
...*...
```

### 输出 #1

```
11
```

---

# P2864 [USACO06JAN] The Grove S

## 题目描述

The pasture contains a small, contiguous grove of trees that has no 'holes' in the middle of the it.  Bessie wonders: how far is it to walk around that grove and get back to my starting position? She's just sure there is a way to do it by going from her start location to successive locations by walking horizontally, vertically, or diagonally and counting each move as a single step. Just looking at it, she doesn't think you could pass 'through' the grove on a tricky diagonal. Your job is to calculate the minimum number of steps she must take.


Happily, Bessie lives on a simple world where the pasture is represented by a grid with $R$ rows and $C$ columns $(1 \le R \le 50, 1 \le C \le 50)$. Here's a typical example where `.` is pasture (which Bessie may traverse), `X` is the grove of trees, `*` represents Bessie's start and end position, and `+` marks one shortest path she can walk to circumnavigate the grove (i.e., the answer):

```plain
...+...
..+X+..
.+XXX+.
..+XXX+
..+X..+
...+++*
```
The path shown is not the only possible shortest path; Bessie might have taken a diagonal step from her start position and achieved a similar length solution. Bessie is happy that she's starting 'outside' the grove instead of in a sort of 'harbor' that could complicate finding the best path.

## 输入格式

Line $1$: Two space-separated integers: $R$ and $C$.

Lines $2 \sim R+1$: Line $i+1$ describes row $i$ with $C$ characters (with no spaces between them).

## 输出格式

Line $1$: The single line contains a single integer which is the smallest number of steps required to circumnavigate the grove.

## 输入输出样例 #1

### 输入 #1

```
6 7
.......
...X...
..XXX..
...XXX.
...X...
...*...
```

### 输出 #1

```
11
```