# CF1567F One-Four Overload

## 题目描述

Alice 有一个 $n$ 行 $m$ 列的矩阵，矩阵中有些单元格被标记了，而有的没有。在与矩阵边缘相邻的单元格总是没有被标记的。（当且仅当两个单元格共边时，我们称这两个单元格式相邻的）。

Alice 想往每个单元格里填入一个数字，使得该矩阵满足以下条件：
- 每个没标记的格子只能填入 $1$ 或者 $4$；
- 每个标记的格子的数字必须为**与它相邻的没有被标记的格子之和**；
- 每个标记的单元格的数字必须为 $5$ 的倍数。

Alice 是蒟蒻，做不出来，于是找你来帮忙 ~~（实际上是找的 Bob 然后让你来帮忙，但不如你直接帮 Alice）~~。

## 输入格式

第一行 $n$ 与 $m$（$1 \le n,m \le 500$）。

接下来 $n$ 行每行 $m$ 列，为一个字符 `X` 或 `.`，分别表示标记过的格子（`X`）与没标记过的格子（`.`）。

## 输出格式

第一行输出 `YES` 或 `NO`，表示是否存在一个合法的矩阵以满足 Alice 的要求。

如果输出的是 `YES`，则输出一个矩阵，表示合法的矩阵。

## 输入输出样例 #1

### 输入 #1

```
5 5
.....
.XXX.
.X.X.
.XXX.
.....
```

### 输出 #1

```
YES
4 1 4 4 1
4 5 5 5 1
4 5 1 5 4
1 5 5 5 4
1 4 4 1 4
```

## 输入输出样例 #2

### 输入 #2

```
5 5
.....
.XXX.
.XXX.
.XXX.
.....
```

### 输出 #2

```
NO
```

## 输入输出样例 #3

### 输入 #3

```
3 2
..
..
..
```

### 输出 #3

```
YES
4 1
4 1
1 4
```

## 输入输出样例 #4

### 输入 #4

```
9 9
.........
.XXXXX.X.
.X...X...
.X.XXXXX.
.X.X.X.X.
.X.XXX.X.
.X.....X.
.XXXXXXX.
.........
```

### 输出 #4

```
YES
4 4 4 1 4 1 4 1 4
1 5 5 5 5 5 4 10 1
4 5 1 4 1 5 4 4 4
4 5 1 5 5 0 5 5 1
4 5 1 5 4 5 1 5 4
4 5 1 5 5 5 4 5 1
1 5 4 4 1 1 4 5 1
4 5 5 5 5 5 5 5 4
1 1 1 1 4 4 1 1 4
```

## 说明/提示

翻译 @[XiaoQuQu](https://www.luogu.com.cn/user/427623)

---

# CF1567F One-Four Overload

## 题目描述

Alice has an empty grid with $ n $ rows and $ m $ columns. Some of the cells are marked, and no marked cells are adjacent to the edge of the grid. (Two squares are adjacent if they share a side.)

Alice wants to fill each cell with a number such that the following statements are true:

- every unmarked cell contains either the number $ 1 $ or $ 4 $ ;
- every marked cell contains the sum of the numbers in all unmarked cells adjacent to it (if a marked cell is not adjacent to any unmarked cell, this sum is $ 0 $ );
- every marked cell contains a multiple of $ 5 $ .

 Alice couldn't figure it out, so she asks Bob to help her. Help Bob find any such grid, or state that no such grid exists.

## 输入格式

The first line of input contains two integers $ n $ and $ m $ ( $ 1 \leq n, m \leq 500 $ ) — the number of rows and the number of columns in the grid, respectively.

Then $ n $ lines follow, each containing $ m $ characters. Each of these characters is either '.' or 'X' — an unmarked and a marked cell, respectively. No marked cells are adjacent to the edge of the grid.

## 输出格式

Output "'NO" if no suitable grid exists. Otherwise, output "'YES"'. Then output $ n $ lines of $ m $ space-separated integers — the integers in the grid.

## 输入输出样例 #1

### 输入 #1

```
5 5
.....
.XXX.
.X.X.
.XXX.
.....
```

### 输出 #1

```
YES
4 1 4 4 1
4 5 5 5 1
4 5 1 5 4
1 5 5 5 4
1 4 4 1 4
```

## 输入输出样例 #2

### 输入 #2

```
5 5
.....
.XXX.
.XXX.
.XXX.
.....
```

### 输出 #2

```
NO
```

## 输入输出样例 #3

### 输入 #3

```
3 2
..
..
..
```

### 输出 #3

```
YES
4 1
4 1
1 4
```

## 输入输出样例 #4

### 输入 #4

```
9 9
.........
.XXXXX.X.
.X...X...
.X.XXXXX.
.X.X.X.X.
.X.XXX.X.
.X.....X.
.XXXXXXX.
.........
```

### 输出 #4

```
YES
4 4 4 1 4 1 4 1 4
1 5 5 5 5 5 4 10 1
4 5 1 4 1 5 4 4 4
4 5 1 5 5 0 5 5 1
4 5 1 5 4 5 1 5 4
4 5 1 5 5 5 4 5 1
1 5 4 4 1 1 4 5 1
4 5 5 5 5 5 5 5 4
1 1 1 1 4 4 1 1 4
```

## 说明/提示

It can be shown that no such grid exists for the second test.