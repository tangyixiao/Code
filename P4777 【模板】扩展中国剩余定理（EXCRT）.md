# P4777 【模板】扩展中国剩余定理（EXCRT）

## 题目描述

给定 $n$ 组非负整数 $a_i, b_i$ ，求解关于 $x$ 的方程组的最小非负整数解。
$$\begin{cases}x\equiv b_1\pmod{a_1}\\x\equiv b_2\pmod{a_2}\\\dots\\x\equiv b_n\pmod{a_n}\end{cases}$$

## 输入格式

输入第一行包含整数 $n$。

接下来 $n$ 行，每行两个非负整数 $a_i, b_i$。

## 输出格式

输出一行，为满足条件的最小非负整数 $x$。

## 输入输出样例 #1

### 输入 #1

```
3
11 6
25 9
33 17

```

### 输出 #1

```
809
```

## 说明/提示

对于 $100 \%$ 的数据，$1 \le n \le {10}^5$，$1 \le a_i \le {10}^{12}$，$0\leq b_i \leq 10^{12}$，保证所有 $a_i$ 的最小公倍数不超过 ${10}^{18}$。

**请注意程序运行过程中进行乘法运算时结果可能有溢出的风险。**

数据保证有解。

---


# P4777 [Template] Extended Chinese Remainder Theorem (EXCRT).

## 题目描述

Given $n$ pairs of non-negative integers $a_i, b_i$, find the smallest non-negative integer solution to the system of equations in $x$.
$$\begin{cases}x\equiv b_1\pmod{a_1}\\x\equiv b_2\pmod{a_2}\\\dots\\x\equiv b_n\pmod{a_n}\end{cases}$$

## 输入格式

The first line contains an integer $n$.

The next $n$ lines each contain two non-negative integers $a_i, b_i$.

## 输出格式

Output one line: the smallest non-negative integer $x$ that satisfies the conditions.

## 输入输出样例 #1

### 输入 #1

```
3
11 6
25 9
33 17

```

### 输出 #1

```
809
```

## 说明/提示

For $100\%$ of the testdata, $1 \le n \le {10}^5$, $1 \le a_i \le {10}^{12}$, $0\leq b_i \leq 10^{12}$. It is guaranteed that the least common multiple of all $a_i$ does not exceed ${10}^{18}$.

**Please note that during the execution of the program, multiplication operations may overflow.**

It is guaranteed that a solution exists.

Translated by ChatGPT 5