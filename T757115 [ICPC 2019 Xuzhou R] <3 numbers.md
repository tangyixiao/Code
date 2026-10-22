# T757115 [ICPC 2019 Xuzhou R] <3 numbers

## 题目描述

Rosie 喜欢玩正整数，尤其是正整数中的 **<3 数**。

**<3 数**是一类特殊的正整数，它们能被少于三个不同的正整数整除。

例如，$7$ 是一个 <3 数。整除 $7$ 的正整数有两个，分别是 $1$ 和 $7$。$25$ 不是一个 <3 数，能整除 $25$ 的正整数有 $1$、$5$ 和 $25$ 共三个。

现在，Rosie 对介于正整数 $L$ 和 $R$ 之间究竟有多少个 <3 数感到好奇。然而要精确算出 <3 数的个数实在太难了。Rosie 只想知道 $L$ 到 $R$ 之间 <3 数的比例是否小于三分之一。确切地说，如果在 $L$ 到 $R$ 之间有 $x$ 个 <3 数，Rosie 想知道是否有 $\frac{x}{R-L+1} < \frac{1}{3}$。

请帮帮好奇的 Rosie 回答他的问题。

## 输入格式

第一行有一个正整数 $T$，表示测试数据的总组数。

每组测试数据占一行，包含两个整数 $L, R$。

- $1 \le T \le 100$
- $1 \le L \le R \le 10^9$

## 输出格式

对于每组测试数据输出一行，如果 $L$ 到 $R$ 之间 <3 数的比例小于三分之一，输出 `Yes`，否则输出 `No`。

## 输入输出样例 #1

### 输入 #1

```
3
7 7
25 25
5 14
```

### 输出 #1

```
No
Yes
No
```

## 说明/提示

翻译由 DeepSeek V4 Pro 完成

---

# T757115 [ICPC 2019 Xuzhou R] <3 numbers

## 题目描述

Rosie likes to play with positive integers, especially the <3 numbers in positive integers.

<3 number is a special group of positive integers, all of which can be divided by less than three positive integers.

For example, $7$ is a < 3 number. There are two positive integers that divide $7$ by $1$ and $7$. $25$ is not a number less than $3$. There are $1$, $5$ and $25$ that can divide $25$.

Now, Rosie is curious about how many <3 numbers are included between positive integers $L$ and $R$. But it's too difficult to figure out exactly how many <3 numbers there are. Rosie wants to know whether the proportion of <3 numbers between $L$ and $R$ is less than one third. To be exact, if there are $x$ <3 numbers between $L$ and $R$, Rosie wants to know if $\frac{x}{R-L+1} < \frac{1}{3}$.

Please help the curious Rosie to answer his questions.

## 输入格式

The first line has a positive integer of $T$, which represents the total number of test data.

Each test data is a line of two integers $L, R$.

- $1 \le T \le 100$
- $1 \le L \le R \le 10^9$

## 输出格式

Please output one line for each test data. If the proportion of <3 numbers between $L$ and $R$ is less than one third, output `Yes`, otherwise output `No`.

## 输入输出样例 #1

### 输入 #1

```
3
7 7
25 25
5 14
```

### 输出 #1

```
No
Yes
No
```