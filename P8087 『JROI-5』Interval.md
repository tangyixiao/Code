# P8087 『JROI-5』Interval

## 题目背景

小 C 喜欢带有区间操作的数据结构，因为这样的题总会有一档好写的 $\mathcal{O}\left(n^2\right)$ 部分分。

## 题目描述

**本题读入量较大，建议使用较快的读入方式，可以参考 [赛时公告板](https://www.luogu.com.cn/paste/lueudpd5)**

小 C 有一个长度为 $n$ 的序列 $a$，第 $i$ 项为 $a_i$。

$a$ 是一个 $1\sim n$ 的排列（即 $1\sim n$ 在 $a$ 中各出现一次）。

定义 $\operatorname{Mex}_{l,r}$ 为 $\{a_l,a_{l+1},
\cdots,a_{r-1},a_r\}$ 中**没有出现过的最小正整数**。

例如，$\operatorname{Mex}\{2,3\}=1,\operatorname{Mex}\{1,2,3\}=4$。

小 C 还有一个长度为 $n$ 的数列 $f$。

定义一个区间 $\left[l,r\right]$ 是合法的当且仅当 
$$f_{r-l+1}< \operatorname{Mex}_{l,r}$$

小 C 希望你告诉他，最短的合法区间的长度是多少，特别的，如果没有区间合法，则输出 `0`。

## 输入格式

第一行一个正整数 $n$。

第二行 $n$ 个正整数 $a_1,a_2,\cdots,a_n$。

第三行 $n$ 个正整数 $f_1,f_2,\cdots,f_n$。

## 输出格式

一行一个整数，表示最短的合法区间长度。

## 输入输出样例 #1

### 输入 #1

```
5
2 3 1 5 4
2 2 3 4 5
```

### 输出 #1

```
3
```

## 输入输出样例 #2

### 输入 #2

```
5
2 3 1 5 4
1 2 2 4 5
```

### 输出 #2

```
1
```

## 输入输出样例 #3

### 输入 #3

```
5
1 3 4 2 5
6 7 8 9 10
```

### 输出 #3

```
0
```

## 输入输出样例 #4

### 输入 #4

```
见附件
```

### 输出 #4

```
见附件
```

## 说明/提示

【样例解释】

对于 #1，容易发现 $\left[1,3\right]$ 是最短的合法区间。

对于 #2，容易发现 $\left[3,3\right]$ 是最短的合法区间。

对于 #3，容易发现没有合法的区间。

---

对于 $10\%$ 的数据，满足 $1\leq n\leq 100$。

对于 $20\%$ 的数据，满足 $1\leq n\leq 1000$。

对于另外 $10\%$ 的数据，满足 $f$ 不升，即满足 $f_1\geq f_2\geq\cdots\geq f_n$，且 $1\leq n\leq 10^6$。

对于 $100\%$ 的数据，满足 $1\leq n\leq 4\times 10^6,1\leq f_i\leq 10^9$。

---


# P8087 "JROI-5" Interval

## 题目背景

Little C likes data structures with interval operations, because such problems always have an easy-to-write $\mathcal{O}\left(n^2\right)$ partial score.

## 题目描述

**This problem has a large input size. It is recommended to use a fast input method. You may refer to the [contest bulletin board](https://www.luogu.com.cn/paste/lueudpd5).**

Little C has a sequence $a$ of length $n$, where the $i$-th term is $a_i$.

$a$ is a permutation of $1 \sim n$ (that is, each of $1 \sim n$ appears exactly once in $a$).

Define $\operatorname{Mex}_{l,r}$ as the **smallest positive integer that does not appear** in $\{a_l,a_{l+1},\cdots,a_{r-1},a_r\}$.

For example, $\operatorname{Mex}\{2,3\}=1$, and $\operatorname{Mex}\{1,2,3\}=4$.

Little C also has an array $f$ of length $n$.

An interval $\left[l,r\right]$ is defined to be valid if and only if
$$f_{r-l+1}< \operatorname{Mex}_{l,r}$$

Little C wants you to tell him the length of the shortest valid interval. In particular, if no interval is valid, output `0`.

## 输入格式

The first line contains a positive integer $n$.

The second line contains $n$ positive integers $a_1,a_2,\cdots,a_n$.

The third line contains $n$ positive integers $f_1,f_2,\cdots,f_n$.

## 输出格式

Output one integer in a single line, indicating the length of the shortest valid interval.

## 输入输出样例 #1

### 输入 #1

```
5
2 3 1 5 4
2 2 3 4 5
```

### 输出 #1

```
3
```

## 输入输出样例 #2

### 输入 #2

```
5
2 3 1 5 4
1 2 2 4 5
```

### 输出 #2

```
1
```

## 输入输出样例 #3

### 输入 #3

```
5
1 3 4 2 5
6 7 8 9 10
```

### 输出 #3

```
0
```

## 输入输出样例 #4

### 输入 #4

```
见附件
```

### 输出 #4

```
见附件
```

## 说明/提示

[Sample Explanation]

For #1, it is easy to see that $\left[1,3\right]$ is the shortest valid interval.

For #2, it is easy to see that $\left[3,3\right]$ is the shortest valid interval.

For #3, it is easy to see that there is no valid interval.

---

For $10\%$ of the testdata, $1\leq n\leq 100$.

For $20\%$ of the testdata, $1\leq n\leq 1000$.

For another $10\%$ of the testdata, $f$ is non-increasing, i.e. $f_1\geq f_2\geq\cdots\geq f_n$, and $1\leq n\leq 10^6$.

For $100\%$ of the testdata, $1\leq n\leq 4\times 10^6$ and $1\leq f_i\leq 10^9$.

Translated by ChatGPT 5