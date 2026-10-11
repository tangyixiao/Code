# P8412 「SvR-1」Hack Function!

## 题目背景

**Problem Number:** $\textit{63}$

小 C 坐在 J-PSC2077 的赛场（题目可于下方「**题目附件**」处下载）上，他早已年逾七旬，但作为 Z 队选手还是成功参赛。

## 题目描述

此时的 J-PSC 终于改成了 CF 赛制，小 C 迅速地 AK 了 Day 1，他发现 T2 function 比较好 Hack，题目的人话翻译如下：

> 对于一个数 $A$，定义函数 $f(A)$ 如下：
> 
> 1. 先把 $A$ 变成 $k$ 进制数 $B$。
> 2. 将 $A$ 替换为 $B$ 各位之和。
> 3. 返回执行第 1 步，直到 $B$ 是一位数为止。
> 4. 记 $x$ 表示 $A$ 此时的值（十进制）。
> 此时 $f(A) = x$，$f(A)$ 称作 $A$ 关于 $k$ 的**位和函数**。
>
> 给定 $k, l, r, p$，求出 $\sum_{i = l}^r f(i^i) \bmod p$ 的值。
>
> **特别地，当 $\sum_{i = l}^r f(i^i) = p$ 时，输出 $\texttt{perfect}$。**

小 C 迅速秒了该题，当他翻看别人的代码时，发现他们用的全是暴力枚举。（因为机子跑得飞快）

好不容易看到一个人，他的代码里竟然没有一个  $\texttt{perfect}$！但由于数据过弱，竟然让他 pp 了。

小 C 突然脑子一热，忘记了怎么构造 Hack 数据，所以他通过 Luogu 6.0 求助于你。

小 C 会告诉你 $k, p$ 的值，你需要构造一组 $l, r$，**使答案输出为 $\texttt{perfect}$**。

**若无法构造，输出两个 $\texttt{-1}$。**

## 输入格式

**本题有多组数据。**

第一行一个整数 $T$，表示数据组数。

接下来 $T$ 行，每行两个整数 $k,p$，含义如题所述。

## 输出格式

共 $T$ 行，对于每组数据，输出你构造的 $l,r$ 的值。

若有多组解，输出任意一组。

## 输入输出样例 #1

### 输入 #1

```
3
10 13
10 3
2 1
```

### 输出 #1

```
2 3
-1 -1
1 1
```

## 说明/提示

#### 样例 1 说明

- 对于数据 $1$，在 $k = 10$ 下，有 $f(2^2) = f(4) = 4$，$f(3^3) = f(27) = 9$，显然 $l = 2, r = 3$ 时原题应该输出 $\texttt{perfect}$。
- 对于数据 $2$，在 $k = 10$ 下，发现不可能满足要求。
- 对于数据 $3$，在 $k = 2$ 下，显然有 $f(1^1) = 1$，但该样例仅用于理解，根据数据规模与约定，我们保证 $k \geq 10$。

#### 数据规模与约定

$$
\newcommand{\arraystretch}{1.5}
\begin{array}{c|c|c|c}\hline\hline
\textbf{Subtask} & \textbf{说明} & \textbf{时限} & \textbf{分值} \\\hline
\textsf{1} & \text{无解} & 1\text{ s} & 3 \\\hline
\textsf{2} & \text{有解且\textbf{\textsf{存在}}一组解使 }1\le l\le r\le 10^5 & 1\text{ s} & 16 \\\hline
\textsf{3} & 1\le p\le 10^7 & 1\text{ s} & 34 \\\hline
\textsf{4} & \text{无特殊限制} & 1.5\text{ s} & 47 \\\hline\hline
\end{array}
$$

对于 $100\%$ 的数据，$10 \leq k \leq 10^3$，$1 \leq p \leq 10^8$，$1 \leq T \leq 10$。

保证时限在 std 用时的 $4$ 倍以上。

#### 评测说明

**本题开启 Special Judge 和捆绑测试。**

你需要保证 $l = r = -1$ 或 $1 \leq l \leq r \leq 10^{18}$ 且 $r - l \leq 10^{15}$，否则 SPJ 会将你的答案判为 $0$ 分。

---

# P8412 "SvR-1" Hack Function!

## 题目背景

**Problem Number:** $\textit{63}$

Little C is sitting at the contest site of J-PSC2077 (the problem can be downloaded from the "**Attachments**" section below). He is already over seventy years old, but as a player on Team Z, he still managed to participate successfully.

## 题目描述

Now J-PSC has finally changed to the CF contest format. Little C quickly got an AK on Day 1. He found that T2 function is quite easy to hack, and the “human-language” translation of the problem is as follows:

> For a number $A$, define the function $f(A)$ as follows:
>
> 1. First convert $A$ into a base-$k$ number $B$.
> 2. Replace $A$ with the sum of digits of $B$.
> 3. Repeat Step 1 until $B$ becomes a single-digit number.
> 4. Let $x$ denote the value of $A$ at this time (in decimal).
>    Then $f(A) = x$. $f(A)$ is called the **digit-sum function** of $A$ with respect to $k$.
>
> Given $k, l, r, p$, compute $\sum_{i = l}^r f(i^i) \bmod p$.
>
> **In particular, when $\sum_{i = l}^r f(i^i) = p$, output $\texttt{perfect}$.**

Little C solved this problem instantly. When he looked through other people’s code, he found they all used brute-force enumeration (because their machines run extremely fast).

After much effort, he finally saw one person whose code did not contain a single $\texttt{perfect}$! But because the testdata was too weak, he still passed.

Little C suddenly got excited and forgot how to construct hack testdata, so he asked you for help through Luogu 6.0.

Little C will tell you the values of $k$ and $p$. You need to construct a pair $(l, r)$ **so that the answer outputs $\texttt{perfect}$**.

**If it is impossible to construct, output two $\texttt{-1}$.**

## 输入格式

**This problem contains multiple test cases.**

The first line contains an integer $T$, indicating the number of test cases.

The next $T$ lines each contain two integers $k, p$, with meanings as described above.

## 输出格式

Output $T$ lines. For each test case, output the $l, r$ you constructed.

If there are multiple solutions, output any one of them.

## 输入输出样例 #1

### 输入 #1

```
3
10 13
10 3
2 1
```

### 输出 #1

```
2 3
-1 -1
1 1
```

## 说明/提示

#### Explanation of Sample 1

- For test case $1$, under $k = 10$, we have $f(2^2) = f(4) = 4$ and $f(3^3) = f(27) = 9$. Obviously, when $l = 2, r = 3$, the original problem should output $\texttt{perfect}$.
- For test case $2$, under $k = 10$, it turns out that it is impossible to meet the requirement.
- For test case $3$, under $k = 2$, it is clear that $f(1^1) = 1$. This sample is only for understanding. According to the constraints and conventions, we guarantee $k \geq 10$.

#### Constraints and Conventions

$$
\newcommand{\arraystretch}{1.5}
\begin{array}{c|c|c|c}\hline\hline
\textbf{Subtask} & \textbf{Description} & \textbf{Time Limit} & \textbf{Score} \\\hline
\textsf{1} & \text{No solution} & 1\text{ s} & 3 \\\hline
\textsf{2} & \text{A solution exists and \textbf{\textsf{there exists}} a solution with }1\le l\le r\le 10^5 & 1\text{ s} & 16 \\\hline
\textsf{3} & 1\le p\le 10^7 & 1\text{ s} & 34 \\\hline
\textsf{4} & \text{No special restrictions} & 1.5\text{ s} & 47 \\\hline\hline
\end{array}
$$

For $100\%$ of the testdata: $10 \leq k \leq 10^3$, $1 \leq p \leq 10^8$, $1 \leq T \leq 10$.

The time limit is guaranteed to be more than $4$ times the runtime of the standard solution (std).

#### Judging Notes

**This problem uses Special Judge and bundled tests.**

You must ensure that $l = r = -1$ or $1 \leq l \leq r \leq 10^{18}$ and $r - l \leq 10^{15}$; otherwise, the SPJ will judge your answer as $0$ points.

Translated by ChatGPT 5