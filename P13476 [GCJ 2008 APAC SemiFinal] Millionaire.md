# P13476 [GCJ 2008 APAC SemiFinal] Millionaire

## 题目描述

你受邀参加了著名电视节目“你想成为百万富翁吗？”。当然你想！

游戏规则很简单：

- 在游戏开始前，主持人会转动幸运轮，决定每次下注获胜的概率 $P$。
- 你起始拥有 $X$ 美元。
- 游戏共进行 $M$ 轮下注。在每一轮中，你可以下注当前所拥有金额的任意部分，包括全部或不下注。下注金额可以不是整数。
- 如果你赢得本轮下注，你的总金额会增加你下注的金额；如果你输掉本轮下注，你的总金额会减少你下注的金额。
- 所有下注结束后，如果你累计金额达到 $1000000$ 或以上，你可以保留你的奖金（这时金额向下取整为整数美元）；否则你将一无所获。

给定 $M$、$P$ 和 $X$，请你计算在最优策略下（即最大化成为百万富翁概率的策略），你成为百万富翁的概率。

## 输入格式

输入的第一行是测试用例数 $N$。

接下来的 $N$ 行，每行格式为 “$M$ $P$ $X$”，其中：

- $M$ 为整数，表示下注轮数。
- $P$ 为实数，表示每轮下注获胜的概率。
- $X$ 为整数，表示初始金额（美元）。

## 输出格式

对于每个测试用例，输出一行，格式为 “Case #$X$: $Y$”，其中：

- $X$ 为测试用例编号，从 $1$ 开始。
- $Y$ 为成为百万富翁的概率，范围在 $0$ 到 $1$ 之间。

当你的答案的绝对误差或相对误差不超过 $10^{-6}$ 时，将被视为正确。

## 输入输出样例 #1

### 输入 #1

```
2
1 0.5 500000
3 0.75 600000
```

### 输出 #1

```
Case #1: 0.500000
Case #2: 0.843750
```

## 说明/提示

**样例解释**

在第一个样例中，唯一能达到 $1000000$ 的方式是在唯一一轮中押上全部金额。

在第二个样例中，你可以通过合理下注，即使输掉一轮也有机会成为百万富翁。以下是一种下注方式：

- 第一轮你有 \$600000，下注 \$150000。
- 如果第一轮输了，你剩下 \$450000，下注 \$100000。
- 如果第一轮输了、第二轮赢了，你有 \$550000，下注 \$450000。
- 如果第一轮赢了，你有 \$750000，下注 \$250000。
- 如果第一轮赢了、第二轮输了，你有 \$500000，下注 \$500000。

**数据范围**

- $1 \leq N \leq 100$
- $0 \leq P \leq 1.0$，小数点后最多 6 位
- $1 \leq X \leq 1000000$

**小数据集（13 分，测试点 1 - 可见）**

- $1 \leq M \leq 5$

**大数据集（16 分，测试点 2 - 隐藏）**

- $1 \leq M \leq 15$

由 ChatGPT 4.1 翻译

---


# P13476 [GCJ 2008 APAC SemiFinal] Millionaire

## 题目描述

You have been invited to the popular TV show "Would you like to be a millionaire?". Of course you would!

The rules of the show are simple:

- Before the game starts, the host spins a wheel of fortune to determine $P$, the probability of winning each bet.
- You start out with some money: $X$ dollars.
- There are $M$ rounds of betting. In each round, you can bet any part of your current money, including none of it or all of it. The amount is not limited to whole dollars or whole cents. If you win the bet, your total amount of money increases by the amount you bet. Otherwise, your amount of money decreases by the amount you bet.
- After all the rounds of betting are done, you get to keep your winnings (this time the amount is rounded down to whole dollars) only if you have accumulated $1000000 or more. Otherwise you get nothing.

Given $M$, $P$ and $X$, determine your probability of winning at least $1000000 if you play optimally (i.e. you play so that you maximize your chances of becoming a millionaire).

## 输入格式

The first line of input gives the number of cases, $N$.

Each of the following $N$ lines has the format "$M$ $P$ $X$", where:

- $M$ is an integer, the number of rounds of betting.
- $P$ is a real number, the probability of winning each round.
- $X$ is an integer, the starting number of dollars.

## 输出格式

For each test case, output one line containing "Case #$X$: $Y$", where:

- $X$ is the test case number, beginning at $1$.
- $Y$ is the probability of becoming a millionaire, between $0$ and $1$.

Answers with a relative or absolute error of at most $10^{-6}$ will be considered correct.

## 输入输出样例 #1

### 输入 #1

```
2
1 0.5 500000
3 0.75 600000
```

### 输出 #1

```
Case #1: 0.500000
Case #2: 0.843750
```

## 说明/提示

**Sample Explanation**

In the first case, the only way to reach $1000000 is to bet everything in the single round.

In the second case, you can play so that you can still reach $1000000 even if you lose a bet. Here's one way to do it:

- You have \$600000 on the first round. Bet \$150000.
- If you lose the first round, you have \$450000 left. Bet \$100000.
- If you lose the first round and win the second round, you have \$550000 left. Bet \$450000.
- If you win the first round, you have \$750000 left. Bet \$250000.
- If you win the first round and lose the second round, you have \$500000 left. Bet \$500000.

**Limits**

- $1 \leq N \leq 100$
- $0 \leq P \leq 1.0$, there will be at most 6 digits after the decimal point.
- $1 \leq X \leq 1000000$

**Small dataset (13 Pts, Test set 1 - Visible)**

- $1 \leq M \leq 5$

**Large dataset (16 Pts, Test set 2 - Hidden)**

- $1 \leq M \leq 15$