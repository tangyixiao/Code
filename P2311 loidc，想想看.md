# P2311 loidc，想想看

## 题目背景

话说 loidc 现在正在家闲的无聊，这天 loidc 正在观看比赛，他突然很有兴趣想了解一段时间内中国队获得金牌的情况。

## 题目描述

还有一点，loidc 有特殊能力，可以预知未来，他可以准确的猜到中国队在某一个单位时间内获得的金牌数。但是，还有但是！由于工作量太大，再加上猜金牌要费很多的体力，所以他无法准确的计算出一段时间内获得的金牌数最大的单位时间是哪个，就因为这样 loidc 很郁闷。他思索来思索去就想到了你，因为他知道你是个 OIer，所以他对你呵呵一笑就把问题交给你了，loidc 希望你能在 1 s 内得出答案。

## 输入格式

第一行一个 $n$，表示有 $n$ 个时间段。

接下来一行有 $n$ 个数 $a_i$，$a_i$ 表示 loidc 猜到的中国队在第 $i$ 个时间段内获得的金牌数。

然后，第三行有一个数 $m$，表示 loidc 有 $m$ 个问题。

接下来有 $m$ 行，每行有 $2$ 个数分别为 $x_i$，$y_i$，表示要询问在时间段 $[x_i,y_i]$ 内中国队获得金牌数最大的是哪个单位时间。

loidc 有一个习惯，他问问题是有先后的，也就是说后一个问题总是在前一个问题之后提出的。

注意对于第 $i$ 个提问和第 $i+1$ 个提问严格的有 $x_i \le x_{i+1}$、$y_i \le y_{i+1}$。

## 输出格式

一共 $m$ 行，每行一个 $k_i$，表示第 $i$ 个询问的答案。

## 输入输出样例 #1

### 输入 #1

```
5
2 3 4 5 6
5
1 1
1 2
2 3
3 4
4 5

```

### 输出 #1

```
1
2
3
4
5

```

## 说明/提示

$30\%$：$n \le 1000$，$m \le 1000$。

$100\%$：$n \le {10}^5$，$m \le {10}^5$。

其他有关输入输出均小于 `maxlongint`。

数据保证 $a_i$ 没有相同的。


---

# P2311 loidc, Think About It

## 题目背景

It is said that loidc is currently bored at home. One day, while watching a competition, he suddenly became very interested in the number of gold medals the Chinese team wins over a period of time.

## 题目描述

Moreover, loidc has a special ability: he can foresee the future and accurately guess how many gold medals the Chinese team will win in any single unit of time. However, the workload is huge, and predicting gold medals consumes a lot of energy, so he cannot accurately determine which unit time within a given interval attains the maximum number of gold medals. This makes loidc quite upset. After thinking for a while, he thought of you, because he knows you are an OIer. He chuckled and handed the problem over to you. loidc hopes you can produce the answer within 1 s.

# Description

## 输入格式

The first line contains an $n$, indicating there are $n$ time intervals.

The next line contains $n$ numbers $a_i$, where $a_i$ denotes the number of gold medals loidc predicts the Chinese team will win in the $i$-th time interval.

Then, the third line contains a number $m$, indicating loidc has $m$ queries.

The next $m$ lines each contain two numbers $x_i$ and $y_i$, asking which unit time within the interval $[x_i, y_i]$ has the maximum number of gold medals.

loidc has a habit of asking questions in order; that is, each query is asked after the previous one.

Note that for the $i$-th and $(i+1)$-th queries, it strictly holds that $x_i \le x_{i+1}$ and $y_i \le y_{i+1}$.

## 输出格式

Output $m$ lines. Each line contains a single $k_i$, denoting the answer to the $i$-th query.

## 输入输出样例 #1

### 输入 #1

```
5
2 3 4 5 6
5
1 1
1 2
2 3
3 4
4 5

```

### 输出 #1

```
1
2
3
4
5

```

## 说明/提示

$30\%$: $n \le 1000$, $m \le 1000$.

$100\%$: $n \le {10}^5$, $m \le {10}^5$.

All other input and output values are less than `maxlongint`.

The testdata guarantees $a_i$ are all distinct.

Translated by ChatGPT 5