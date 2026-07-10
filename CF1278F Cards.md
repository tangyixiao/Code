# CF1278F Cards

## 题目描述

考虑如下实验。有一副共 $m$ 张牌的牌堆，且恰好有一张是小丑牌。你将进行 $n$ 次如下操作：将牌堆洗牌，从牌堆顶端抽出一张牌，查看后再放回牌堆。

设 $x$ 表示在本次实验中你抽到小丑牌的次数。假设每次洗牌后，所有 $m!$ 种牌的排列都是等概率的，求 $x^k$ 的期望值是多少？请将答案对 $998244353$ 取模后输出。

## 输入格式

一行包含三个整数 $n$、$m$ 和 $k$（$1 \le n, m < 998244353$，$1 \le k \le 5000$）。

## 输出格式

输出一个整数，表示 $x^k$ 的期望值对 $998244353$ 取模的结果（答案总可以表示为最简分数 $\frac{a}{b}$，其中 $b \bmod 998244353 \ne 0$；你需要输出 $a \cdot b^{-1} \bmod 998244353$）。

## 输入输出样例 #1

### 输入 #1

```
1 1 1

```

### 输出 #1

```
1

```

## 输入输出样例 #2

### 输入 #2

```
1 1 5000

```

### 输出 #2

```
1

```

## 输入输出样例 #3

### 输入 #3

```
2 2 2

```

### 输出 #3

```
499122178

```

## 输入输出样例 #4

### 输入 #4

```
998244352 1337 5000

```

### 输出 #4

```
326459680

```

## 说明/提示

由 ChatGPT 4.1 翻译


---


# CF1278F Cards

## 题目描述

Consider the following experiment. You have a deck of $ m $ cards, and exactly one card is a joker. $ n $ times, you do the following: shuffle the deck, take the top card of the deck, look at it and return it into the deck.

Let $ x $ be the number of times you have taken the joker out of the deck during this experiment. Assuming that every time you shuffle the deck, all $ m! $ possible permutations of cards are equiprobable, what is the expected value of $ x^k $ ? Print the answer modulo $ 998244353 $ .

## 输入格式

The only line contains three integers $ n $ , $ m $ and $ k $ ( $ 1 \le n, m < 998244353 $ , $ 1 \le k \le 5000 $ ).

## 输出格式

Print one integer — the expected value of $ x^k $ , taken modulo $ 998244353 $ (the answer can always be represented as an irreducible fraction $ \frac{a}{b} $ , where $ b \mod 998244353 \ne 0 $ ; you have to print $ a \cdot b^{-1} \mod 998244353 $ ).

## 输入输出样例 #1

### 输入 #1

```
1 1 1

```

### 输出 #1

```
1

```

## 输入输出样例 #2

### 输入 #2

```
1 1 5000

```

### 输出 #2

```
1

```

## 输入输出样例 #3

### 输入 #3

```
2 2 2

```

### 输出 #3

```
499122178

```

## 输入输出样例 #4

### 输入 #4

```
998244352 1337 5000

```

### 输出 #4

```
326459680

```