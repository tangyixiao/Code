# P8062 [BalkanOI 2012] handsome

## 题目背景

你是 OIer 中最帅的，所以你要做一道跟帅有关的题。

## 题目描述

一个 $N$ 位数是帅气的，当且仅当每一个数位上的数为 $1,2,3$ 中的一个。而且相邻的两个数位上的数字构成的有序数对不是“危险数对”。

- $N$ 位数 $X$ 在排列 $p$ 的意义下字典序小于 $N$ 位数 $Y$，当且仅当存在一个 $k$ 使得 $X_{p_1}=Y_{p_1},X_{p_2}=Y_{p_2},\dots,X_{p_{k}}<Y_{p_{k}}$。

- $N$ 位数 $X$ 在排列 $p$ 的意义下字典序等于 $N$ 位数 $Y$，当且仅当$X_{p_1}=Y_{p_1},X_{p_2}=Y_{p_2},\dots,X_{p_{N}}=Y_{p_{N}}$。


- $N$ 位数 $X$ 在排列 $p$ 的意义下字典序大于 $N$ 位数 $Y$，当且仅当存在一个 $k$ 使得 $X_{p_1}=Y_{p_1},X_{p_2}=Y_{p_2},\dots,X_{p_{k}}>Y_{p_{k}}$。

请你输出在排列 $p$ 意义下小于等于 $B$ 的帅气数的个数模 $10^9+7$ 的值。

## 输入格式

输入的第一行包含一个整数 $N$，表示数字位数。

第二行包含 $N$ 个空格分隔的整数，表示排列 $p$。该行的第 $i$ 个整数表示 $p_i$。

第三行包含一个整数 $M$，表示危险数对个数。

第四行 $M$ 个空格分隔的两位整数，第 $i$ 个两位整数 $\overline{a_ib_i}$ 表示 $(a_i,b_i)$ 为危险数对。

第五行一个正整数 $B$ 表示给定帅气数。

## 输出格式

输出一行，表示在排列 $p$ 意义下小于等于 $B$ 的帅气数个数模 $10^9+7$。

## 输入输出样例 #1

### 输入 #1

```
3
2 1 3
2
22 13
321
```

### 输出 #1

```
9
```

## 说明/提示

#### 数据范围：
Subtask#0 为样例。

$1\le N\le4\times10^5$，$M>0$，$a_i,b_i\in\{1,2,3\}$。

保证 $B$ 为帅气数。


#### 样例解释：

$113,122,131,132,133,213,221,222,223,313,322$ 不是帅气数，因为出现了危险数对 $(2,2)$ 或 $(1,3)$。


所以，所有 $3$ 位帅气数为：$
111,112,121,123,
211,212,231,232,233,
311,312,321,323,331,332,333$。

在排列 $2,1,3$ 意义下小于等于 $321$ 的帅气数有：$111,112,121,123,211,212,311,312,321$

如 $323$ 在排列 $2,1,3$ 意义下与 $321$ 比较（设 $323$ 为 $X$，$321$ 为 $Y$）：

- 先比较第 $2$ 位：$X_2=Y_2=2$；
- 再比较第 $1$ 位：$X_1=Y_1=3$；
- 最后比较第 $3$ 位：$X_3=3>Y_3=1$。

所以 $323$ 在排列 $2,1,3$ 意义下大于 $321$，不是满足条件的帅气数。

---

# P8062 [BalkanOI 2012] handsome

## 题目背景

You are the most handsome among OIers, so you have to solve a problem related to being handsome.

## 题目描述

An $N$-digit number is handsome if and only if every digit is one of $1,2,3$. Also, the ordered pair formed by any two adjacent digits is not a “dangerous pair”.

- An $N$-digit number $X$ is lexicographically smaller than an $N$-digit number $Y$ under the permutation $p$ if and only if there exists a $k$ such that $X_{p_1}=Y_{p_1},X_{p_2}=Y_{p_2},\dots,X_{p_{k}}<Y_{p_{k}}$.

- An $N$-digit number $X$ is lexicographically equal to an $N$-digit number $Y$ under the permutation $p$ if and only if $X_{p_1}=Y_{p_1},X_{p_2}=Y_{p_2},\dots,X_{p_{N}}=Y_{p_{N}}$.

- An $N$-digit number $X$ is lexicographically greater than an $N$-digit number $Y$ under the permutation $p$ if and only if there exists a $k$ such that $X_{p_1}=Y_{p_1},X_{p_2}=Y_{p_2},\dots,X_{p_{k}}>Y_{p_{k}}$.

Please output the number of handsome numbers that are $\le B$ under the permutation $p$, modulo $10^9+7$.

## 输入格式

The first line contains an integer $N$, the number of digits.

The second line contains $N$ space-separated integers, representing the permutation $p$. The $i$-th integer on this line is $p_i$.

The third line contains an integer $M$, the number of dangerous pairs.

The fourth line contains $M$ space-separated two-digit integers. The $i$-th two-digit integer $\overline{a_ib_i}$ indicates that $(a_i,b_i)$ is a dangerous pair.

The fifth line contains a positive integer $B$, the given handsome number.

## 输出格式

Output one line: the number of handsome numbers that are $\le B$ under the permutation $p$, modulo $10^9+7$.

## 输入输出样例 #1

### 输入 #1

```
3
2 1 3
2
22 13
321
```

### 输出 #1

```
9
```

## 说明/提示

#### Constraints

Subtask#0 is the sample.

$1\le N\le4\times10^5$, $M>0$, $a_i,b_i\in\{1,2,3\}$.

It is guaranteed that $B$ is a handsome number.

#### Sample Explanation

$113,122,131,132,133,213,221,222,223,313,322$ are not handsome numbers, because the dangerous pair $(2,2)$ or $(1,3)$ appears.

So, all handsome $3$-digit numbers are: $
111,112,121,123,
211,212,231,232,233,
311,312,321,323,331,332,333$.

Under the permutation $2,1,3$, the handsome numbers that are $\le 321$ are: $111,112,121,123,211,212,311,312,321$.

For example, compare $323$ and $321$ under the permutation $2,1,3$ (let $323$ be $X$ and $321$ be $Y$):

- First compare the $2$-nd digit: $X_2=Y_2=2$.
- Then compare the $1$-st digit: $X_1=Y_1=3$.
- Finally compare the $3$-rd digit: $X_3=3>Y_3=1$.

So $323$ is greater than $321$ under the permutation $2,1,3$, and it is not a valid handsome number.

Translated by ChatGPT 5