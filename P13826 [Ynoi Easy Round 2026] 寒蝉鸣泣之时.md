# P13826 [Ynoi Easy Round 2026] 寒蝉鸣泣之时

## 题目背景

::::info[题目背景已折叠]
![](https://cdn.luogu.com.cn/upload/image_hosting/476ez1tm.png)
::::

## 题目描述

给定 $n$ 个边平行于坐标轴的平面矩形，以及正整数 $m$，对 $1\le m\cdot i\le n$ 的每个整数 $i$ ，你需要计算出恰好被 $m\cdot i$ 个矩形包含的区域的面积。

第 $i$ 个矩形用四个整数表示为 $x_{1,i},x_{2,i},y_{1,i},y_{2,i}$ ；

恰好被 $i$ 个矩形包含的区域的面积即为有多少个整点 $(x,y)$ 满足 $\sum\limits_{j=1}^n[x_{1,j}\le x<x_{2,j}][y_{1,j}\le y<y_{2,j}]=i$。

## 输入格式

第一行两个整数 $n,m$ ；

接下来 $n$ 行，每行四个整数表示 $x_{1,i},x_{2,i},y_{1,i},y_{2,i}$ 。

## 输出格式

共 $\left\lfloor \frac n m \right\rfloor$ 行，依次表示恰好被 $m,2m,3m,\dots,\left\lfloor \frac n m \right\rfloor\cdot m$ 个矩形包含的区域的面积。

## 输入输出样例 #1

### 输入 #1

```
10 4
1 2 1 6
3 9 8 9
2 3 1 9
2 8 8 10
3 7 2 10
1 7 2 7
5 6 2 6
5 8 3 7
6 7 4 7
1 4 7 10

```

### 输出 #1

```
7
0

```

## 说明/提示

Idea：nzhtl1477，Solution：ccz181078，Code：ccz181078，Data：ccz181078&nzhtl1477

对于 $15\%$ 的数据，满足 $m=n$。

对于另外 $15\%$ 的数据，满足 $n=1000$。

对于另外 $20\%$ 的数据，满足 $m=10000$。

对于 $100\%$ 的数据，满足 $n\le m^2\le n^2$，$1\le x_{1,i}<x_{2,i}\le n$，$1\le y_{1,i}<y_{2,i}\le n$，$1\le n\le 3\times 10^5$。