# P7504 「HMOI R1」可爱的德丽莎

## 题目背景

Polaris_Dane 非常菜，他不仅沉迷于数论，而且喜欢玩崩坏 3。

## 题目描述

可爱的德丽莎希望你能帮她求出

$$
\sum_{x = 1}^n\sum_{y = 1}^n\sum_{i = 1}^x[x \bot k_1][i \bot x]\cdot i\cdot \sum_{j = 1}^y[y \bot k_2][j \bot y]\cdot j
$$
的结果。

其中 $[x \bot y] = \begin{cases}1 & \operatorname{gcd}(x,y)=1 \\ 0 & \operatorname{gcd}(x,y)\neq 1\end{cases}$

德丽莎这么可爱，你怎么能不答应她呢？

由于答案可能很大，所以德丽莎只想知道它对 $998244353$ 取模后的结果。

## 输入格式

共一行三个整数 $n, k_1, k_2$。

## 输出格式

仅一行一个数，为所求的答案对 $998244353$ 取模后的结果。

## 输入输出样例 #1

### 输入 #1

```
2 2 2
```

### 输出 #1

```
1
```

## 输入输出样例 #2

### 输入 #2

```
4 2 2
```

### 输出 #2

```
16
```

## 说明/提示

**本题测试点编号倒序排列。**

对于所有数据：
- $1 \le n, k_1, k_2 \le 2 \times 10^9$。

---------

**本题采用捆绑测试。**

| No. | Constraints                   | Score |
| ----------- | ----------------------------- | ----- |
| $1$         | $1\le n,k_1,k_2\le 100$         | $10$  |
| $2$         | $1\le n,k_1,k_2\le 3000$ | $20$  |
| $3$         | $1\le n,k_1,k_2\le 5\times 10^5$ | $20$  |
| $4$         | No further constraints        | $50$  |

---------------

- Idea: Polaris_Dane
- Solution: Polaris_Dane
- Code: Polaris_Dane
- Data: Polaris_Dane

---

# P7504 "HMOI R1" Cute Theresa

## 题目背景

Polaris_Dane is very keen on math. He is not only obsessed with number theory, but also likes playing Honkai Impact 3.

## 题目描述

Cute Theresa hopes you can help her compute the value of

$$
\sum_{x = 1}^n\sum_{y = 1}^n\sum_{i = 1}^x[x \bot k_1][i \bot x]\cdot i\cdot \sum_{j = 1}^y[y \bot k_2][j \bot y]\cdot j
$$

where

$$
[x \bot y] = \begin{cases}1 & \operatorname{gcd}(x,y)=1 \\ 0 & \operatorname{gcd}(x,y)\neq 1\end{cases}
$$

Theresa is so cute, how could you say no to her?

Since the answer may be very large, Theresa only wants to know the result modulo $998244353$.

## 输入格式

A single line with three integers $n, k_1, k_2$.

## 输出格式

A single line with one number: the required answer modulo $998244353$.

## 输入输出样例 #1

### 输入 #1

```
2 2 2
```

### 输出 #1

```
1
```

## 输入输出样例 #2

### 输入 #2

```
4 2 2
```

### 输出 #2

```
16
```

## 说明/提示

**The test point numbering is in reverse order.**

Constraints for all data:
- $1 \le n, k_1, k_2 \le 2 \times 10^9$.

---------

**This problem uses bundled tests.**

| No. | Constraints                   | Score |
| ----------- | ----------------------------- | ----- |
| $1$         | $1\le n,k_1,k_2\le 100$         | $10$  |
| $2$         | $1\le n,k_1,k_2\le 3000$ | $20$  |
| $3$         | $1\le n,k_1,k_2\le 5\times 10^5$ | $20$  |
| $4$         | No further constraints        | $50$  |

---------------

- Idea: Polaris_Dane
- Solution: Polaris_Dane
- Code: Polaris_Dane
- Data: Polaris_Dane

Translated by ChatGPT 5