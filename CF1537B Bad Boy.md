# CF1537B Bad Boy

## 题目描述

Riley 是个很调皮的男孩，但同时他也是个溜溜球高手。所以，他决定用自己的溜溜球技巧来捉弄他的朋友 Anton。

Anton 的房间可以表示为一个有 $n$ 行 $m$ 列的网格。用 $(i, j)$ 表示第 $i$ 行第 $j$ 列的格子。Anton 目前站在房间的 $(i, j)$ 位置。为了捉弄 Anton，Riley 决定把两个溜溜球分别扔到房间的两个格子里（也可以扔在同一个格子里）。

由于 Anton 不喜欢地上有溜溜球，他必须把这两个溜溜球都捡起来，并回到最初的位置。Anton 需要行走的距离是经过两个溜溜球所在位置并返回 $(i, j)$ 的最短路径，只能走到相邻的格子（即每次可以从 $(x, y)$ 走到 $(x+1, y)$、$(x-1, y)$、$(x, y+1)$、$(x, y-1)$，前提是这些格子存在）。

Riley 想知道，他应该把这两个溜溜球扔到哪里，才能让 Anton 需要行走的距离最大。但因为他很忙，他让你帮他计算。

## 输入格式

第一行包含一个整数 $t$（$1 \leq t \leq 10^4$），表示测试用例的数量。接下来有 $t$ 组测试用例。

每组测试用例一行，包含四个整数 $n$、$m$、$i$、$j$（$1 \leq n, m \leq 10^9$，$1 \leq i \leq n$，$1 \leq j \leq m$），分别表示房间的行数、列数，以及 Anton 当前所在的格子。

## 输出格式

对于每组测试用例，输出四个整数 $x_1$、$y_1$、$x_2$、$y_2$（$1 \leq x_1, x_2 \leq n$，$1 \leq y_1, y_2 \leq m$），表示两个溜溜球应该被扔到的坐标。它们将分别被扔到 $(x_1, y_1)$ 和 $(x_2, y_2)$。

如果有多组答案，输出任意一组均可。

## 输入输出样例 #1

### 输入 #1

```
7
2 3 1 1
4 4 1 2
3 5 2 2
5 1 2 1
3 1 3 1
1 1 1 1
1000000000 1000000000 1000000000 50
```

### 输出 #1

```
1 2 2 3
4 1 4 4
3 1 1 5
5 1 1 1
1 1 2 1
1 1 1 1
50 1 1 1000000000
```

## 说明/提示

以下是第一个测试用例的可视化示意图。

![](https://cdn.luogu.com.cn/upload/vjudge_pic/CF1537B/55dd7a7a8828547b72bc3be325a8a8e51cf757fa.png)

由 ChatGPT 4.1 翻译

---

# CF1537B Bad Boy

## 题目描述

Riley is a very bad boy, but at the same time, he is a yo-yo master. So, he decided to use his yo-yo skills to annoy his friend Anton.

Anton's room can be represented as a grid with $ n $ rows and $ m $ columns. Let $ (i, j) $ denote the cell in row $ i $ and column $ j $ . Anton is currently standing at position $ (i, j) $ in his room. To annoy Anton, Riley decided to throw exactly two yo-yos in cells of the room (they can be in the same cell).

Because Anton doesn't like yo-yos thrown on the floor, he has to pick up both of them and return back to the initial position. The distance travelled by Anton is the shortest path that goes through the positions of both yo-yos and returns back to $ (i, j) $ by travelling only to adjacent by side cells. That is, if he is in cell $ (x, y) $ then he can travel to the cells $ (x + 1, y) $ , $ (x - 1, y) $ , $ (x, y + 1) $ and $ (x, y - 1) $ in one step (if a cell with those coordinates exists).

Riley is wondering where he should throw these two yo-yos so that the distance travelled by Anton is maximized. But because he is very busy, he asked you to tell him.

## 输入格式

The first line contains a single integer $ t $ ( $ 1 \leq t \leq 10^4 $ ) — the number of test cases. Then $ t $ test cases follow.

The only line of each test case contains four integers $ n $ , $ m $ , $ i $ , $ j $ ( $ 1 \leq n, m \leq 10^9 $ , $ 1\le i\le n $ , $ 1\le j\le m $ ) — the dimensions of the room, and the cell at which Anton is currently standing.

## 输出格式

For each test case, print four integers $ x_1 $ , $ y_1 $ , $ x_2 $ , $ y_2 $ ( $ 1 \leq x_1, x_2 \leq n $ , $ 1\le y_1, y_2\le m $ ) — the coordinates of where the two yo-yos should be thrown. They will be thrown at coordinates $ (x_1,y_1) $ and $ (x_2,y_2) $ .

If there are multiple answers, you may print any.

## 输入输出样例 #1

### 输入 #1

```
7
2 3 1 1
4 4 1 2
3 5 2 2
5 1 2 1
3 1 3 1
1 1 1 1
1000000000 1000000000 1000000000 50
```

### 输出 #1

```
1 2 2 3
4 1 4 4
3 1 1 5
5 1 1 1
1 1 2 1
1 1 1 1
50 1 1 1000000000
```

## 说明/提示

Here is a visualization of the first test case.

 ![](https://cdn.luogu.com.cn/upload/vjudge_pic/CF1537B/55dd7a7a8828547b72bc3be325a8a8e51cf757fa.png)