# P1325 [ICPC 2002 Beijing R] 雷达安装

## 题目描述

假设海岸线是一条无限延伸的直线。它的一侧是陆地，另一侧是海洋。每一座小岛是在海面上的一个点。雷达必须安装在陆地上（包括海岸线），并且每个雷达都有相同的扫描范围 $d$。你的任务是建立尽量少的雷达站，使所有小岛都在扫描范围之内。

数据使用笛卡尔坐标系，定义海岸线为 $x$ 轴。在 $x$ 轴上方为海洋，下方为陆地。

## 输入格式

第一行包括 $2$ 个整数 $n$ 和 $d$，$n$ 是岛屿数目，$d$ 是雷达扫描范围。

接下来 $n$ 行，每行两个整数，为岛屿坐标。

## 输出格式

一个整数表示最少需要的雷达数目，若不可能覆盖所有岛屿，输出 `-1`。

## 输入输出样例 #1

### 输入 #1

```
3 2
1 2
-3 1
2 1

```

### 输出 #1

```
2
```

## 说明/提示

### 样例 1 解释

![](https://cdn.luogu.com.cn/upload/image_hosting/fnezefht.png)

### 数据范围

对于全部数据，$n\le1000$，$ d \le 2\times 10^4$，$ | x_i | \le 2 \times 10^6 $，$ 0 \le y_i \le 2\times 10^4$。

---

# P1325 [ICPC 2002 Beijing R] Radar Installation

## 题目描述

Assume the coastline is an infinitely long straight line. One side is land, and the other side is ocean. Each island is a point on the sea surface. Radars must be installed on land (including the coastline), and each radar has the same scan range $d$. Your task is to build as few radar stations as possible so that all islands are within the scan range.

The data use the Cartesian coordinate system, with the coastline defined as the $x$ axis. The ocean is above the $x$ axis, and the land is below it.

## 输入格式

The first line contains $2$ integers $n$ and $d$, where $n$ is the number of islands and $d$ is the radar scan range.

Then follow $n$ lines, each containing two integers, the coordinates of an island.

## 输出格式

Output a single integer: the minimum number of radars required. If it is impossible to cover all islands, output `-1`.

## 输入输出样例 #1

### 输入 #1

```
3 2
1 2
-3 1
2 1

```

### 输出 #1

```
2
```

## 说明/提示

### Sample 1 Explanation

![](https://cdn.luogu.com.cn/upload/image_hosting/fnezefht.png)

### Constraints

对于全部数据，$n\le1000$，$ d \le 2\times 10^4$，$ | x_i | \le 2 \times 10^6 $，$ 0 \le y_i \le 2\times 10^4$。

Translated by ChatGPT 5