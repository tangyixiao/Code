# P2310 loidc，看看海

## 题目背景

loidc 喜欢大海。在他放假的时候他经常一个人跑到海边独自玩耍。

在浪花的冲击下，他可以忘记打代码的烦躁，真是惬意极了。

虽然今天是周六，但今天可是 $2014$ 年 $11$ 月 $8$ 日，NOIP 2014 复赛 Day 1。在早晨放松之余他可不能忘掉 OI 知识。

## 题目描述

loidc 准备带着 LOI 的队员们考完试后到海边玩耍。所以他想写一个程序让队员们了解在一段时间内海浪的情况。

他的命令是这样输入的：

$$\texttt{x y k}$$

这是要询问在时间 $[x,y]$ 内海浪高度第 $k$ 小的单位时刻是那个时刻。

但是在他刚准备打开 Dev-pas++ 的时候，loidc 发现他的电脑坏掉了。于是一向喜欢偷懒的他就向你求助。他希望你能在 $1$ 秒内完成程序的运行。

当然 loidc 会提前告诉你所有时段海浪的高度，这点你放心。至于他是如何得到的，这就不得而知了。

## 输入格式

第一行一个整数 $n$，表示总时间段。

第二行 $n$ 个数 $\{a_n\}$，依次表示 $n$ 个单位时刻内海浪的高度。（数据保证各个时刻海浪高度均不相同）

第三行一个整数 $m$，表示有 $m$ 个询问。

接下来 $m$ 行，每行 $3$ 个整数 $x,y,k$，表示一个询问。

## 输出格式

一共 $m$ 行，是每个询问的回答。

## 输入输出样例 #1

### 输入 #1

```
5
1 2 3 4 5
3
2 4 2
1 5 1
3 3 1

```

### 输出 #1

```
3
1
3

```

## 说明/提示

对于 $30\%$ 的数据，$n,m \le 200$。

对于 $100\%$ 的数据，$1 \le n,m \le 4000$，$1 \le a_i \le 10^5$ 且 $a_i$ 两两不等，$1 \le x \le y \le n$，$1 \le k \le y-x+1$。

---

# P2310 loidc, Look at the Sea

## 题目背景

loidc likes the sea. When he is on vacation, he often goes to the seaside alone to play.

Under the impact of the surf, he can forget the irritation of coding. How pleasant it is.

Although today is Saturday, it is $2014$-$11$-$8$, NOIP 2014 Final Round Day 1. While relaxing in the morning, he must not forget OI knowledge.

## 题目描述

loidc plans to take the LOI team members to the seaside to have fun after the exam. So he wants to write a program to let them understand the wave conditions over a period of time.

His command is entered like this:

$$\texttt{x y k}$$

This asks, within time $[x, y]$, for the unit time index at which the $k$-th smallest wave height occurs.

But when he was just about to open Dev-pas++, loidc found that his computer was broken. Being lazy as always, he asks you for help. He hopes you can finish the program within $1$ second.

Of course, loidc will tell you the wave height for all time indices in advance, so rest assured. As for how he obtained them, that is unknown.

## 输入格式

- The first line contains an integer $n$, the total number of time indices.
- The second line contains $n$ numbers $a_i$, in order, representing the wave height at each of the $n$ unit time indices. It is guaranteed that all time indices have pairwise distinct wave heights.
- The third line contains an integer $m$, the number of queries.
- The next $m$ lines each contain $3$ integers $x, y, k$, representing one query.

## 输出格式

Output $m$ lines, each being the answer to one query.

## 输入输出样例 #1

### 输入 #1

```
5
1 2 3 4 5
3
2 4 2
1 5 1
3 3 1

```

### 输出 #1

```
3
1
3

```

## 说明/提示

- For $30\%$ of the testdata, $n, m \le 200$.
- Constraints: For $100\%$ of the testdata, $1 \le n, m \le 4000$, $1 \le a_i \le 10^5$ and $a_i$ are pairwise distinct, $1 \le x \le y \le n$, $1 \le k \le y - x + 1$.

Translated by ChatGPT 5