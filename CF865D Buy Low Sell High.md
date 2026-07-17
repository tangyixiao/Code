# CF865D Buy Low Sell High

## 题目描述

你可以完美地预测某只股票接下来 $N$ 天的价格，你想利用这一知识盈利，但你每天只想买卖一股，这表明你每天要么什么都不干，要么买入一股，要么卖出一股。起初你没有股票，你也不能在没有股票时卖出股票。你希望在第 $N$ 天结束时不持有股票，并最大化盈利。

## 输入格式

第一行一个整数 $N$（$2 \le N \le 3 \times 10^5$），表示天数。

接下来一行 $N$ 个整数 $p_1,p_2,\dots p_N$（$1 \le p_i \le 10^6$），表示第 $i$ 天的股价。

## 输出格式

输出你第 $N$ 天结束时的最大盈利。

### 样例解释

在股价为 $5,4$ 时各买入一股，在股价为 $9,12$ 时各卖出一股，接着在股价为 $2$ 时买入一股，股价为 $10$ 时卖出一股，总收益为 $20$。

Translated by uid $408071$。

## 输入输出样例 #1

### 输入 #1

```
9
10 5 4 7 9 12 6 2 10

```

### 输出 #1

```
20

```

## 输入输出样例 #2

### 输入 #2

```
20
3 1 4 1 5 9 2 6 5 3 5 8 9 7 9 3 2 3 8 4

```

### 输出 #2

```
41

```

---

# CF865D Buy Low Sell High

## 题目描述

You can perfectly predict the price of a certain stock for the next $ N $ days. You would like to profit on this knowledge, but only want to transact one share of stock per day. That is, each day you will either buy one share, sell one share, or do nothing. Initially you own zero shares, and you cannot sell shares when you don't own any. At the end of the $ N $ days you would like to again own zero shares, but want to have as much money as possible.

## 输入格式

Input begins with an integer $ N $ $ (2<=N<=3·10^{5}) $ , the number of days.

Following this is a line with exactly $ N $ integers $ p_{1},p_{2},...,p_{N} $ $ (1<=p_{i}<=10^{6}) $ . The price of one share of stock on the $ i $ -th day is given by $ p_{i} $ .

## 输出格式

Print the maximum amount of money you can end up with at the end of $ N $ days.

## 输入输出样例 #1

### 输入 #1

```
9
10 5 4 7 9 12 6 2 10

```

### 输出 #1

```
20

```

## 输入输出样例 #2

### 输入 #2

```
20
3 1 4 1 5 9 2 6 5 3 5 8 9 7 9 3 2 3 8 4

```

### 输出 #2

```
41

```

## 说明/提示

In the first example, buy a share at $ 5 $ , buy another at $ 4 $ , sell one at $ 9 $ and another at $ 12 $ . Then buy at $ 2 $ and sell at $ 10 $ . The total profit is $ -5-4+9+12-2+10=20 $ .