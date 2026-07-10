# P3545 [POI 2012] HUR-Warehouse Store

## 题目描述

现在有 $n$ 天。第 $i$ 天上午会进货 $A_i$ 件商品，中午的时候会有顾客需要购买 $B_i$ 件商品，可以选择满足顾客的要求，或是无视掉他。

如果要满足顾客的需求，就必须要有足够的库存。问最多能够满足多少个顾客的需求。

## 输入格式

第一行包含一个整数 $n$，表示有 $n$ 天。

第二行有 $n$ 个整数 $a_i$，表示第 $i$ 天上午进货 $a$ 件商品。

第三行包含 $n$ 个整数 $b_i$，表示在第 $i$ 天中午有顾客来买 $b$ 件商品。

## 输出格式

第一行一个整数，表示最多能满足几天中顾客的需求。


第二行输出最多能够满足哪些天顾客的需求。如果有多种方案，输出任意一种即可。

## 输入输出样例 #1

### 输入 #1

```
6
2 2 1 2 1 0
1 2 2 3 4 4
```

### 输出 #1

```
3
1 2 4
```

## 说明/提示

对于 $100\%$ 的数据，$1\leqslant n\leqslant 2.5\times 10^5$，$0\leqslant a_i,b_i \leqslant 10^9$。

---

# P3545 [POI 2012] HUR-Warehouse Store

## 题目描述

There are $n$ days. On the morning of day $i$, $A_i$ items arrive. At noon of day $i$, a customer wants to buy $B_i$ items; you may either fulfill the customer's request or ignore it.

To fulfill the customer's request, you must have enough inventory. What is the maximum number of days whose customer requests can be fulfilled?

## 输入格式

The first line contains an integer $n$, the number of days.

The second line contains $n$ integers $a_i$, where $a_i$ is the number of items arriving on the morning of day $i$.

The third line contains $n$ integers $b_i$, where $b_i$ is the number of items a customer wants to buy at noon of day $i$.

## 输出格式

The first line contains a single integer: the maximum number of days whose customer requests can be fulfilled.

The second line outputs one such set of days that achieves the maximum. If there are multiple solutions, output any one of them.

## 输入输出样例 #1

### 输入 #1

```
6
2 2 1 2 1 0
1 2 2 3 4 4
```

### 输出 #1

```
3
1 2 4
```

## 说明/提示

For $100\%$ of the testdata, $1 \leqslant n \leqslant 2.5 \times 10^5$, $0 \leqslant a_i, b_i \leqslant 10^9$.

Translated by ChatGPT 5