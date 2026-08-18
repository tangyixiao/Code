# P4137 Rmq Problem / mex

## 题目描述

有一个长度为 $n$ 的数组 $\{a_1,a_2,\ldots,a_n\}$。

$m$ 次询问，每次询问一个区间内最小没有出现过的自然数。

## 输入格式

第一行，两个正整数 $n,m$。  
第二行，$n$ 个非负整数 $a_1, a_2, \ldots , a_n$。  
接下来 $m$ 行，每行两个正整数 $l,r$，表示一次询问。

## 输出格式

输出 $m$ 行，每行一个数，依次表示每个询问的答案。

## 输入输出样例 #1

### 输入 #1

```
5 5
2 1 0 2 1
3 3
2 3
2 4
1 2
3 5
```

### 输出 #1

```
1
2
3
0
3
```

## 说明/提示

对于 $30\%$ 的数据：$1\leq n,m\leq 1000$。  
对于 $100\%$ 的数据：$1\leq n,m\leq 2\times {10}^5$，$1\leq l\leq r\leq n$，$0\leq a_i\leq 2\times 10^5$。

---

# P4137 Rmq Problem / mex

## 题目描述

There is an array $\{a_1,a_2,\ldots,a_n\}$ of length $n$.

There are $m$ queries; for each query, find the smallest non-negative integer that does not appear in the interval (mex).

## 输入格式

The first line contains two positive integers $n,m$.  
The second line contains $n$ non-negative integers $a_1, a_2, \ldots , a_n$.  
Then follow $m$ lines, each containing two positive integers $l,r$, representing a query.

## 输出格式

Output $m$ lines, one number per line, giving the answer to each query in order.

## 输入输出样例 #1

### 输入 #1

```
5 5
2 1 0 2 1
3 3
2 3
2 4
1 2
3 5
```

### 输出 #1

```
1
2
3
0
3
```

## 说明/提示

For $30\%$ of the testdata: $1\leq n,m\leq 1000$.  
For $100\%$ of the testdata: $1\leq n,m\leq 2\times {10}^5$, $1\leq l\leq r\leq n$, $0\leq a_i\leq 2\times 10^5$.

Translated by ChatGPT 5