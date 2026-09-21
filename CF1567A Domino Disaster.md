# CF1567A Domino Disaster

## 题目描述

一个 $2$ 行 $n$ 列的网格，用 $n$ 个 $1\times2$ 大小的多米诺骨牌完全覆盖在这个网格上，可以水平或竖直放置。

给出其中的一行的放置情况，问另一行的放置情况。

## 输入格式

多组数据。

第一行一个整数 $t$ 表示数据组数。

接下来 $t$ 组数据，每组数据第一行一个整数 $n$ ，表示网格的列数。

第二行一个由 $n$ 个字符组成的字符串 $s$ ,字符由 $L,R,U,D$ 组成，分别表示多米诺骨牌的左半部分，右半部分，上半部分和下半部分。

## 输出格式

对于每组数据，输出一个字符串表示另一行的放置情况，如果有多个答案，随机输出一个即可。

## 输入输出样例 #1

### 输入 #1

```
4
1
U
2
LR
5
LRDLR
6
UUUUUU
```

### 输出 #1

```
D
LR
LRULR
DDDDDD
```

## 说明/提示

$1\leq t \leq 5000,1\leq n\leq 100$ 。



译者：@smyslenny

---

# CF1567A Domino Disaster

## 题目描述

Alice has a grid with $ 2 $ rows and $ n $ columns. She fully covers the grid using $ n $ dominoes of size $ 1 \times 2 $ — Alice may place them vertically or horizontally, and each cell should be covered by exactly one domino.

Now, she decided to show one row of the grid to Bob. Help Bob and figure out what the other row of the grid looks like!

## 输入格式

The input consists of multiple test cases. The first line contains an integer $ t $ ( $ 1 \leq t \leq 5000 $ ) — the number of test cases. The description of the test cases follows.

The first line of each test case contains an integer $ n $ ( $ 1 \leq n \leq 100 $ ) — the width of the grid.

The second line of each test case contains a string $ s $ consisting of $ n $ characters, each of which is either L, R, U, or D, representing the left, right, top, or bottom half of a domino, respectively (see notes for better understanding). This string represents one of the rows of the grid.

Additional constraint on the input: each input corresponds to at least one valid tiling.

## 输出格式

For each test case, output one string — the other row of the grid, using the same format as the input string. If there are multiple answers, print any.

## 输入输出样例 #1

### 输入 #1

```
4
1
U
2
LR
5
LRDLR
6
UUUUUU
```

### 输出 #1

```
D
LR
LRULR
DDDDDD
```

## 说明/提示

In the first test case, Alice shows Bob the top row, the whole grid may look like:

 ![](https://cdn.luogu.com.cn/upload/vjudge_pic/CF1567A/f6313fac31aa4ee89163b1e6517c7b8cd79de94e.png)In the second test case, Alice shows Bob the bottom row, the whole grid may look like:

 ![](https://cdn.luogu.com.cn/upload/vjudge_pic/CF1567A/d483f512dfd4df0b26ddea7edaf86ee4f49029e9.png)In the third test case, Alice shows Bob the bottom row, the whole grid may look like:

 ![](https://cdn.luogu.com.cn/upload/vjudge_pic/CF1567A/914fa600373e22b40bd82a0efc2de6946f9f624d.png)In the fourth test case, Alice shows Bob the top row, the whole grid may look like:

 ![](https://cdn.luogu.com.cn/upload/vjudge_pic/CF1567A/3e5d0a895f5ae2d60b12cbf41a4412e12bc7f913.png)