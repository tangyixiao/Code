# P5963 [BalticOI 2005] Card 卡牌游戏 (Day0)

## 题目描述

Adam 喜欢数。有一次他在他的抽屉里找到了一沓空白纸卡牌，在每张卡牌的两面写上随机的数，然后思考下面的谜题：把所有卡牌按任意顺序（必要时翻转）填入下面格式的表达式，最小的可能得到的表达式的值是多少？

>`□-□+□-□+□-□+...-□`（第一个符号和最后一个符号均为 `-`）

过了一会 Adam 想出了一个解法。你也能想出来吗？编写一个程序解决上面描述的谜题。

## 输入格式

标准输入的第一行包含卡牌的数量 $N$。

接下来 $N$ 行，第 $i+1$ 行两个整数 $a_i$ 和 $b_i$，分别表示写在第 $i$ 张卡牌两面的数。

## 输出格式

标准输出仅一行，应当包含最小的可能得到的表达式的值。

## 输入输出样例 #1

### 输入 #1

```
6
-8 12
0 5
7 -3
10 -7
-2 7
1 4
```

### 输出 #1

```
-34
```

## 输入输出样例 #2

### 输入 #2

```
10
70 70
62 73
81 65
59 77
99 40
35 88
80 57
76 67
85 57
53 96
```

### 输出 #2

```
-155

```

## 说明/提示

#### 样例 1 解释

卡牌填入表达式的顺序：$1,2,3,5,4,6$。

此时最小值为 $(-8) - 5 + (-3) - 7 + (-7) - 4 = -34$。

#### 样例 2 解释

卡牌填入表达式的顺序：$2,1,4,3,5,8,6,9,7,10$。

此时最小值为 $62 - 70 + 59 - 81 + 40 - 76 + 35 - 85 + 57 - 96 = -155$。

#### 数据规模与约定

对于 $100\%$ 的数据，$2\le N\le 10^5$，$N$ 为偶数（原因显然），$|a_i|,|b_i|\le 2000$。

#### 说明

翻译自 BalticOI 2005 Day0 Card。

原官网已经丢失此题，原数据可以在[这里](https://www.acmicpc.net/problem/3373)评测。

---

# P5963 [BalticOI 2005] Card Card Game (Day0)

## 题目描述

Adam likes numbers. Once, he found a stack of blank paper cards in his drawer. He wrote random numbers on both sides of each card, and then thought about the following puzzle: put all cards into the expression of the following form in any order (flipping them if necessary). What is the minimum possible value of the resulting expression?

> `□-□+□-□+□-□+...-□` (both the first operator and the last operator are `-`)

After a while, Adam came up with a solution. Can you do it too? Write a program to solve the puzzle described above.

## 输入格式

The first line of standard input contains the number of cards $N$.

In the next $N$ lines, the $(i+1)$-th line contains two integers $a_i$ and $b_i$, which are the numbers written on the two sides of the $i$-th card.

## 输出格式

Standard output contains only one line, which should contain the minimum possible value of the expression.

## 输入输出样例 #1

### 输入 #1

```
6
-8 12
0 5
7 -3
10 -7
-2 7
1 4
```

### 输出 #1

```
-34
```

## 输入输出样例 #2

### 输入 #2

```
10
70 70
62 73
81 65
59 77
99 40
35 88
80 57
76 67
85 57
53 96
```

### 输出 #2

```
-155

```

## 说明/提示

#### Explanation for Sample 1

The order of cards placed into the expression is: $1,2,3,5,4,6$.

Then the minimum value is $(-8) - 5 + (-3) - 7 + (-7) - 4 = -34$.

#### Explanation for Sample 2

The order of cards placed into the expression is: $2,1,4,3,5,8,6,9,7,10$.

Then the minimum value is $62 - 70 + 59 - 81 + 40 - 76 + 35 - 85 + 57 - 96 = -155$.

#### Constraints

For $100\%$ of the testdata, $2 \le N \le 10^5$, $N$ is even (for obvious reasons), and $|a_i|, |b_i| \le 2000$.

#### Notes

Translated from BalticOI 2005 Day0 Card.

The original official website for this problem has been lost. The original testdata can be judged [here](https://www.acmicpc.net/problem/3373).

Translated by ChatGPT 5