# P6207 [USACO06OCT] Cows on Skates G

## 题目描述

**本题使用 Special Judge。**

Farmer John 把农场划分为了一个 $r$ 行 $c$ 列的矩阵，并发现奶牛们无法通过其中一些区域。此刻，Bessie 位于坐标为 $(1,1)$ 的区域，并想到坐标为 $(r,c)$ 的牛棚享用晚餐。她知道，以她所在的区域为起点，每次移动至相邻的四个区域之一，总有一些路径可以到达牛棚。

这样的路径可能有无数种，请你输出任意一种，并保证所需移动次数不超过 $10^5$。

## 输入格式

第一行两个整数 $r,c$。
 
接下来 $r$ 行，每行 $c$ 个字符，表示 Bessie 能否通过相应位置的区域。字符只可能是 `.` 或 `*`。

- `.` 表示 Bessie 可以通过该区域。
- `*` 表示 Bessie 无法通过该区域。

## 输出格式

若干行，每行包含两个用空格隔开的整数，表示 Bessie 依次通过的区域的坐标。

显然，输出的第一行是 `1 1` ，最后一行是 `r c`。

相邻的两个坐标所表示的区域必须相邻。

## 输入输出样例 #1

### 输入 #1

```
5 8
..*...**
*.*.*.**
*...*...
*.*.*.*.
....*.*.
```

### 输出 #1

```
1 1
1 2
2 2
3 2
3 3
3 4
2 4
1 4
1 5
1 6
2 6
3 6
3 7
3 8
4 8
5 8
```

## 说明/提示

**【数据范围】**

对于 $100\%$ 的数据，$1\le r\le 113$，$1\le c\le 77$。

------------

**【样例说明】* *

![](https://cdn.luogu.com.cn/upload/image_hosting/3gsutffb.png)

图为样例输出的示意图。答案不唯一。

---

# P6207 [USACO06OCT] Cows on Skates G

## 题目描述

**This problem uses a Special Judge.**

Farmer John divided the farm into a matrix with $r$ rows and $c$ columns, and found that cows cannot pass through some areas. Now, Bessie is in the cell with coordinates $(1,1)$, and she wants to reach the barn at $(r,c)$ to enjoy dinner. She knows that starting from her current cell and moving each time to one of the four adjacent cells, there is always at least one path that can reach the barn.

There may be infinitely many such paths. Please output any one of them, and make sure the number of moves needed does not exceed $100000$.

## 输入格式

The first line contains two integers $r, c$.

The next $r$ lines each contain $c$ characters, indicating whether Bessie can pass through the corresponding cell. Each character is either `.` or `*`.

- `.` means Bessie can pass through this cell.
- `*` means Bessie cannot pass through this cell.

## 输出格式

Output several lines. Each line contains two integers separated by a space, representing the coordinates of the cells Bessie passes through in order.

Obviously, the first line of the output is `1 1`, and the last line is `r c`.

The cells represented by two adjacent coordinates must be adjacent.

## 输入输出样例 #1

### 输入 #1

```
5 8
..*...**
*.*.*.**
*...*...
*.*.*.*.
....*.*.
```

### 输出 #1

```
1 1
1 2
2 2
3 2
3 3
3 4
2 4
1 4
1 5
1 6
2 6
3 6
3 7
3 8
4 8
5 8
```

## 说明/提示

**Constraints**

For $100\%$ of the testdata, $1 \le r \le 113$, $1 \le c \le 77$.

------------

**Sample Explanation**

![](https://cdn.luogu.com.cn/upload/image_hosting/3gsutffb.png)

The figure shows an illustration of a sample output. The answer is not unique.

Translated by ChatGPT 5