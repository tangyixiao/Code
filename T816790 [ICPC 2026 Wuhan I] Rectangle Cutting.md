# T816790 [ICPC 2026 Wuhan I] Rectangle Cutting

## 题目描述

八千代在平面直角坐标系的第一象限内有一个矩形。该矩形的左下角位于坐标原点 $(0,0)$，右上角位于 $(n,m)$。换言之，矩形的两边分别与 $x$ 轴、$y$ 轴重合，其在 $x$ 轴方向的长度为 $n$，在 $y$ 轴方向的长度为 $m$。

八千代决定把这个矩形切 $q$ 刀。具体地，她有以下两种切割方式：

- 横向切割：给定一个正整数 $k$，沿着直线 $y=k$ 进行切割。
- 纵向切割：给定一个正整数 $k$，沿着直线 $x=k$ 进行切割。

每次切割都会贯穿整个区域，将现有的矩形进一步切割成更多的小矩形。

八千代想要知道，在每一次切割完成之后，当前所有被切分出来的小矩形中，面积的最大值是多少？

## 输入格式

第一行包含三个整数 $n,m,q$（$1 \le n,m \le 10^9$，$1 \le q \le 5\times10^5$），分别表示初始矩形的水平长度、垂直长度以及切割的次数。

接下来 $q$ 行，每行包含两个整数 $op,k$，描述一次切割操作：

- 若 $op=1$，表示进行一次纵向切割，给定整数 $k$（$1 \le k<n$），沿着直线 $x=k$ 切割。
- 若 $op=2$，表示进行一次横向切割，给定整数 $k$（$1 \le k<m$），沿着直线 $y=k$ 切割。

保证八千代绝对不会在同一个位置切割两次（即所有的切割直线均互不相同）。

## 输出格式

输出共 $q$ 行，每行包含一个整数，第 $i$ 行的整数表示在第 $i$ 次切割之后，所有小矩形中面积的最大值。

## 输入输出样例 #1

### 输入 #1

```
5 3 3
1 1
1 4
2 2
```

### 输出 #1

```
12
9
6
```

## 说明/提示

:::align{center}

![](https://cdn.luogu.com.cn/upload/image_hosting/3elsx29w.png)

图 1：样例解释
:::

---

# T816790 [ICPC 2026 Wuhan I] Rectangle Cutting

## 题目描述

Yachiyo has a rectangle in the first quadrant of the Cartesian coordinate plane. The lower-left corner of the rectangle is at the origin $(0,0)$, and the upper-right corner is at $(n,m)$. In other words, the two sides of the rectangle are aligned with the $x$-axis and the $y$-axis, with lengths $n$ and $m$ along the $x$- and $y$-directions, respectively.

Yachiyo decides to make $q$ cuts on this rectangle. Specifically, there are two kinds of cuts:

- Horizontal cut: given a positive integer $k$, cut along the line $y=k$.
- Vertical cut: given a positive integer $k$, cut along the line $x=k$.

Each cut goes through the entire region, further dividing the existing rectangles into more smaller rectangles.

Yachiyo wants to know, after each cut is completed, what the maximum area among all the currently divided small rectangles is.

## 输入格式

The first line contains three integers $n,m,q$ ($1 \le n,m \le 10^9$, $1 \le q \le 5\times10^5$), representing the horizontal length, vertical length, and the number of cuts of the initial rectangle, respectively.

The next $q$ lines each contain two integers $op,k$, describing one cut operation:

- If $op=1$, it means a vertical cut is performed, and the given integer $k$ ($1 \le k<n$) indicates cutting along the line $x=k$.
- If $op=2$, it means a horizontal cut is performed, and the given integer $k$ ($1 \le k<m$) indicates cutting along the line $y=k$.

It is guaranteed that Yachiyo will never cut at the same position twice (that is, all cutting lines are distinct).

## 输出格式

Output $q$ lines. The $i$-th line should contain one integer, representing the maximum area among all small rectangles after the $i$-th cut.

## 输入输出样例 #1

### 输入 #1

```
5 3 3
1 1
1 4
2 2
```

### 输出 #1

```
12
9
6
```

## 说明/提示

:::align{center}
![](https://cdn.luogu.com.cn/upload/image_hosting/3elsx29w.png)

Pic. 1: Sample explanation
:::