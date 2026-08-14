# P4197 [ONTAK2010] Peaks

## 题目描述

在 Bytemountains 有 $n$ 座山峰，每座山峰有他的高度 $h_i$。有些山峰之间有双向道路相连，共 $m$ 条路径，每条路径有一个困难值，这个值越大表示越难走。

现在有 $q$ 组询问，每组询问询问从点 $v$ 开始只经过困难值小于等于 $x$ 的路径所能到达的山峰中第 $k$ 高的山峰，如果无解输出 $-1$。

## 输入格式

第一行三个数 $n,m,q$。第二行 $n$ 个数，第 $i$ 个数为 $h_i$。

接下来 $m$ 行，每行三个整数 $a,b,c$，表示从 $a \to b$ 有一条困难值为 $c$ 的双向路径。

接下来 $q$ 行，每行三个数 $v,x,k$，表示一组询问。

## 输出格式

对于每组询问，输出一个整数表示能到达的山峰中第 $k$ 高的山峰的高度。

## 输入输出样例 #1

### 输入 #1

```
10 11 4
1 2 3 4 5 6 7 8 9 10
1 4 4
2 5 3
9 8 2
7 8 10
7 1 4
6 7 1
6 4 8
2 1 5
10 8 10
3 4 7
3 4 6
1 5 2
1 5 6
1 5 8
8 9 2
```

### 输出 #1

```
6
1
-1
8

```

## 说明/提示

### 数据规模与约定
对于 $100\%$ 的数据，$1 \le v,k \le n \le 10^5$，$1 \le m,q \le 5\times 10^5$，$1 \le h_i,c,x \le 10^9$。

---

# P4197 [ONTAK2010] Peaks

## 题目描述

In Bytemountains, there are $n$ peaks, and each peak has its height $h_i$. Some pairs of peaks are connected by bidirectional roads; there are $m$ roads in total. Each road has a difficulty value, and a larger value means it is harder to traverse.

There are $q$ queries. For each query, starting from vertex $v$, you may only traverse roads whose difficulty is less than or equal to $x$. Among all peaks reachable this way, find the $k$-th highest peak. If there is no such peak, output $-1$.

## 输入格式

The first line contains three integers $n, m, q$. The second line contains $n$ integers, where the $i$-th is $h_i$.

The next $m$ lines each contain three integers $a, b, c$, indicating there is a bidirectional road between $a$ and $b$ with difficulty $c$.

The next $q$ lines each contain three integers $v, x, k$, describing a query.

## 输出格式

For each query, output a single integer: the height of the $k$-th highest reachable peak.

## 输入输出样例 #1

### 输入 #1

```
10 11 4
1 2 3 4 5 6 7 8 9 10
1 4 4
2 5 3
9 8 2
7 8 10
7 1 4
6 7 1
6 4 8
2 1 5
10 8 10
3 4 7
3 4 6
1 5 2
1 5 6
1 5 8
8 9 2
```

### 输出 #1

```
6
1
-1
8

```

## 说明/提示

Constraints  
For $100\%$ of the testdata, $1 \le v, k \le n \le 10^5$, $1 \le m, q \le 5 \times 10^5$, $1 \le h_i, c, x \le 10^9$.

Translated by ChatGPT 5