# P1948 [USACO08JAN] Telephone Lines S

## 题目描述

多年以后，笨笨长大了，成为了电话线布置师。由于地震使得某市的电话线全部损坏，笨笨是负责接到震中市的负责人。该市周围分布着 $n$（$1\le n\le10^3$）根按 $1\sim n$ 顺序编号的废弃的电话线杆，任意两根线杆之间没有电话线连接，一共有 $p$（$1\le p\le10^4$）对电话杆可以拉电话线。其他的由于地震使得无法连接。

第 $i$ 对电线杆的两个端点分别是 $a_i,b_i$，它们的距离为 $l_i$（$1\le l_i\le10^6$）。数据中每对 $(a_i,b_i)$ 只出现一次。编号为 $1$ 的电话杆已经接入了全国的电话网络，整个市的电话线全都连到了编号 $n$ 的电话线杆上。也就是说，笨笨的任务仅仅是找一条将 $1$ 号和 $n$ 号电线杆连起来的路径，其余的电话杆并不一定要连入电话网络。

电信公司决定支援灾区免费为此市连接 $k$ （$1\le k\le p$）对由笨笨指定的电话线杆，对于额外的那些电话线，需要为它们付费，总费用决定于其中最长的电话线的长度（每根电话线仅连接一对电话线杆）。如果需要连接的电话线杆不超过 $k$ 对，那么支出为 $0$。

请你计算一下，将电话线引导震中市最少需要在电话线上花多少钱？

## 输入格式

输入文件的第一行包含三个数字 $n,p,k$。

第二行到第 $p+1$ 行，每行分别都为三个整数 $a_i,b_i,l_i$。

## 输出格式

一个整数，表示该项工程的最小支出，如果不可能完成则输出 $-1$。

## 输入输出样例 #1

### 输入 #1

```
5 7 1
1 2 5
3 1 4
2 4 8
3 2 3
5 2 9
3 4 7
4 5 6

```

### 输出 #1

```
4

```

---

# P1948 [USACO08JAN] Telephone Lines S

## 题目描述

Years later, Benben (pinyin) grew up to become a telephone line installer. An earthquake destroyed all the city's telephone lines, and Benben is responsible for connecting the city at the epicenter. Around the city there are $n$ ($1 \le n \le 10^3$) abandoned telephone poles labeled $1$ through $n$. There are no existing lines between any pair of poles. In total, there are $p$ ($1 \le p \le 10^4$) pairs of poles that can be connected; all other pairs cannot be connected due to the earthquake.

For the $i$-th connectable pair, the endpoints are $a_i, b_i$, and the distance (line length) is $l_i$ ($1 \le l_i \le 10^6$). Each pair $(a_i, b_i)$ appears at most once in the data. Pole $1$ is already connected to the national telephone network, and the entire city's network is concentrated at pole $n$. In other words, Benben only needs to find a path that connects pole $1$ to pole $n$; the other poles do not need to be connected to the network.

The telecom company will support the disaster area by connecting up to $k$ ($1 \le k \le p$) pairs of poles designated by Benben for free. For any additional lines used on the chosen path, payment is required, and the total cost is determined by the longest length among those paid lines (each line connects exactly one pair of poles). If the chosen path uses at most $k$ lines, then the total cost is $0$.

Please compute the minimum amount of money needed to connect the city at the epicenter.

## 输入格式

The first line contains three integers $n, p, k$.

Each of the next $p$ lines contains three integers $a_i, b_i, l_i$.

## 输出格式

Output a single integer: the minimum total cost of the project. If it is impossible to complete, output $-1$.

## 输入输出样例 #1

### 输入 #1

```
5 7 1
1 2 5
3 1 4
2 4 8
3 2 3
5 2 9
3 4 7
4 5 6

```

### 输出 #1

```
4

```

## 说明/提示

Translated by ChatGPT 5