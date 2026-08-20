# P5834 [USACO19DEC] MooBuzz S

## 题目描述

Farmer John 的奶牛们最近成为了一个简单的数字游戏“FizzBuzz”的狂热玩家。这个游戏的规则很简单：奶牛们站成一圈，依次从一开始报数，每头奶牛在轮到她的时候报一个数。如果一头奶牛将要报的数字是 $3$ 的倍数，她应当报 `Fizz` 来代替这个数。如果一头奶牛将要报的数字是 $5$ 的倍数，她应当报 `Buzz` 来代替这个数。如果一头奶牛将要报的数字是 $15$ 的倍数，她应当报 `FizzBuzz` 来代替这个数。于是这个游戏的开始部分的记录为：

`1, 2, Fizz, 4, Buzz, Fizz, 7, 8, Fizz, Buzz, 11, Fizz, 13, 14, FizzBuzz, 16`

由于词汇的匮乏，奶牛们玩的 FizzBuzz 中用`Moo` 代替了 `Fizz`、`Buzz`、`FizzBuzz`。于是奶牛版的游戏的开始部分的记录为：

`1, 2, Moo, 4, Moo, Moo, 7, 8, Moo, Moo, 11, Moo, 13, 14, Moo, 16`

给定 $N$，请求出这个游戏中第 $N$ 个被报的数。

## 输入格式

输入包含一个整数 $N$。

## 输出格式

输出游戏中被报出的第 $N$ 个数。

## 输入输出样例 #1

### 输入 #1

```
4
```

### 输出 #1

```
7
```

## 说明/提示

关于部分分：

测试点 $1$ 为样例。

测试点 $2\sim 5$ 满足 $N\le 10^6$。

对于 $100\%$ 的数据，$1 \leq N \leq 10^9$

供题：Brian Dean+

---

# P5834 [USACO19DEC] MooBuzz S

## 题目描述

Farmer John’s cows have recently become enthusiastic players of a simple number game called “FizzBuzz.” The rules of this game are simple: the cows stand in a circle and count in order starting from $1$, and each cow says one item when it is her turn. If the number a cow is about to say is a multiple of $3$, she should say `Fizz` instead of the number. If it is a multiple of $5$, she should say `Buzz` instead of the number. If it is a multiple of $15$, she should say `FizzBuzz` instead of the number. Therefore, the beginning of the record of the game is:

`1, 2, Fizz, 4, Buzz, Fizz, 7, 8, Fizz, Buzz, 11, Fizz, 13, 14, FizzBuzz, 16`

Due to a limited vocabulary, in the cows’ version of FizzBuzz they use `Moo` to replace `Fizz`, `Buzz`, and `FizzBuzz`. Therefore, the beginning of the record of the cows’ game is:

`1, 2, Moo, 4, Moo, Moo, 7, 8, Moo, Moo, 11, Moo, 13, 14, Moo, 16`

Given $N$, find the $N$-th number that is spoken in this game.

## 输入格式

The input contains one integer $N$.

## 输出格式

Output the $N$-th number spoken in the game.

## 输入输出样例 #1

### 输入 #1

```
4
```

### 输出 #1

```
7
```

## 说明/提示

About partial scoring:

Test point $1$ is the sample.

Test points $2 \sim 5$ satisfy $N \le 10^6$.

For $100\%$ of the testdata, $1 \leq N \leq 10^9$.

Problem by: Brian Dean.

Translated by ChatGPT 5