# P6031 CF1278F Cards 加强版

## 题目背景

[原题链接](https://www.luogu.com.cn/problem/CF1278F)

## 题目描述

有 $m$ 张牌，其中有一张是王牌。将这些牌均匀随机打乱 $n$ 次，设有 $x$ 次第一张为王牌，求 $x^k$ 的期望值。

答案对 $998244353$ 取模。

## 输入格式

一行三个正整数 $n,m,k$。

## 输出格式

输出一行一个整数表示答案。

## 输入输出样例 #1

### 输入 #1

```
1234 2345 3456
```

### 输出 #1

```
398700213
```

## 输入输出样例 #2

### 输入 #2

```
998244352 1337 5000
```

### 输出 #2

```
326459680
```

## 输入输出样例 #3

### 输入 #3

```
233333333 114514 9982443
```

### 输出 #3

```
825888958
```

## 说明/提示

【数据范围】  
对于 $20\%$ 的数据，$1\le k \le 5000$；  
对于 $40\%$ 的数据，$1\le k \le 10^5$；  
对于 $100\%$ 的数据，$1\le k \le 10^7$，$1\le n,m \le 998244352$。

Solution：iostream  
Data：NaCly\_Fish


---

# P6031 CF1278F Cards Enhanced Version

## 题目背景

[Original problem link](https://www.luogu.com.cn/problem/CF1278F)

## 题目描述

There are $m$ cards, and one of them is a joker. Shuffle these cards uniformly at random $n$ times. Let $x$ be the number of times the first card is the joker. Find the expected value of $x^k$.

Take the answer modulo $998244353$.

## 输入格式

One line with three positive integers $n, m, k$.

## 输出格式

Output one integer in one line, which is the answer.

## 输入输出样例 #1

### 输入 #1

```
1234 2345 3456
```

### 输出 #1

```
398700213
```

## 输入输出样例 #2

### 输入 #2

```
998244352 1337 5000
```

### 输出 #2

```
326459680
```

## 输入输出样例 #3

### 输入 #3

```
233333333 114514 9982443
```

### 输出 #3

```
825888958
```

## 说明/提示

Constraints  
For $20\%$ of the testdata, $1 \le k \le 5000$;  
For $40\%$ of the testdata, $1 \le k \le 10^5$;  
For $100\%$ of the testdata, $1 \le k \le 10^7$, $1 \le n, m \le 998244352$.

Solution: iostream  
Data: NaCly\_Fish

Translated by ChatGPT 5