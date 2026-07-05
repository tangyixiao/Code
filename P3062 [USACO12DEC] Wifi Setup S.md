# P3062 [USACO12DEC] Wifi Setup S

## 题目描述

Farmer John 的 $N$ 头奶牛（$1 \le N \le 2000$）都站在从谷仓到牧场的直线路径上的不同位置，我们可以将其视为一条一维数轴。由于他的奶牛喜欢通过电子邮件保持联系，FJ 希望在不同位置安装无线基站，以便所有奶牛都能获得无线覆盖。

经过一番比较，FJ 了解到无线基站的成本取决于其传输距离：一个功率为 $r$ 的基站成本为 $A + B \times r$，其中 $A$ 是安装基站的固定成本，$B$ 是每单位传输距离的成本。如果 FJ 在位置 $x$ 安装这样的设备，那么它可以向位于 $x - r$ 到 $x + r$ 范围内的任何奶牛传输数据。允许安装传输功率 $r = 0$ 的基站，但这只能覆盖位于基站同一位置的奶牛。

给定 $A$ 和 $B$ 的值，以及 FJ 奶牛的位置，请确定 FJ 为所有奶牛提供无线覆盖的最小成本。

## 输入格式

- 第一行：三个空格分隔的整数 $N, A, B$（$0 \le A, B \le 1000$）。
- 第 $2$ 到第 $1+N$ 行：每行一个在 $0$ 到 $1\,000\,000$ 范围内的整数，表示一头奶牛的位置。

## 输出格式

- 一行：为所有奶牛提供无线覆盖的最小成本。

## 输入输出样例 #1

### 输入 #1

```
3 20 5 
7 
0 
100 

```

### 输出 #1

```
57.5 

```

## 说明/提示

有三头奶牛，位置分别为 $7, 0$ 和 $100$。安装一个功率为 $r$ 的基站成本为 $20 + 5r$。

最优方案是在位置 $3.5$ 处建造一个功率为 $3.5$ 的基站，在位置 $100$ 处建造一个功率为 $0$ 的基站。第一个基站覆盖奶牛 $1$ 和 $2$，第二个基站覆盖奶牛 $3$。


---

# P3062 [USACO12DEC] Wifi Setup S

## 题目描述

Farmer John’s $N$ cows ($1 \le N \le 2000$) stand at various positions along a straight path, which we can regard as a one-dimensional number line. Since his cows want to stay in email contact with each other, FJ plans to install Wifi base stations at positions of his choosing so that all cows have wireless coverage.

The cost of a Wifi base station depends on its transmission distance: a base station with power $r$ costs $A + B \times r$, where $A$ is the fixed installation cost and $B$ is the cost per unit distance. If a base station is installed at position $x$, it provides coverage to any cow located in the interval $[x - r, x + r]$. A base station with $r = 0$ is allowed, but it only covers a cow located exactly at $x$.

Given $A$, $B$, and the locations of FJ’s cows, determine the minimum total cost to provide wireless coverage for all cows. Base stations may be placed at any real position on the line.

## 输入格式

- Line 1: Three space-separated integers $N$, $A$, $B$, where $1 \le N \le 2000$ and $0 \le A, B \le 1000$.
- Lines $2$ to $N + 1$: Each line contains an integer in $[0, 1{,}000{,}000]$ describing the location of one cow.

## 输出格式

- Line 1: The minimum total cost to provide wireless coverage to all cows.

## 输入输出样例 #1

### 输入 #1

```
3 20 5 
7 
0 
100 

```

### 输出 #1

```
57.5 

```

## 说明/提示

There are $3$ cows at positions $7$, $0$, and $100$. Installing a base station of power $r$ costs $20 + 5 \times r$.

An optimal solution is to build one base station at position $3.5$ (power $r = 3.5$) and another at position $100$ (power $r = 0$). The first base station covers cows $1$ and $2$, and the second covers cow $3$.

Translated by ChatGPT 5