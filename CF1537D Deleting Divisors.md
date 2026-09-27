# CF1537D Deleting Divisors

## 题目描述

Alice 和 Bob 正在玩一个游戏。

他们从一个正整数 $n$ 开始，轮流对其进行操作。每一回合，玩家可以从 $n$ 中减去一个 $n$ 的约数，减去的数不能等于 $1$ 或 $n$。无法进行操作的玩家输掉游戏。Alice 总是先手。

注意，每一回合都要减去当前数字的一个约数。

现在请你判断，如果两人都采取最优策略，谁会赢得游戏。

## 输入格式

第一行包含一个整数 $t$（$1 \leq t \leq 10^4$），表示测试用例的数量。接下来有 $t$ 行，每行一个整数 $n$（$1 \leq n \leq 10^9$），表示初始数字。

## 输出格式

对于每个测试用例，如果 Alice 会赢，输出 "Alice"；如果 Bob 会赢，输出 "Bob"。两者都要求首字母大写。

## 输入输出样例 #1

### 输入 #1

```
4
1
4
12
69
```

### 输出 #1

```
Bob
Alice
Alice
Bob
```

## 说明/提示

在第一个测试用例中，游戏立即结束，因为 Alice 无法进行操作。

在第二个测试用例中，Alice 可以减去 $2$，使 $n=2$，此时 Bob 无法进行操作，因此 Alice 获胜。

在第三个测试用例中，Alice 可以减去 $3$，使 $n=9$。Bob 只能减去 $3$，使 $n=6$。现在，Alice 可以再次减去 $3$，使 $n=3$。此时 Bob 无法进行操作，因此 Alice 获胜。

由 ChatGPT 4.1 翻译，fixed by @tallnut

---

# CF1537D Deleting Divisors

## 题目描述

Alice and Bob are playing a game.

They start with a positive integer $ n $ and take alternating turns doing operations on it. Each turn a player can subtract from $ n $ one of its divisors that isn't $ 1 $ or $ n $ . The player who cannot make a move on his/her turn loses. Alice always moves first.

Note that they subtract a divisor of the current number in each turn.

You are asked to find out who will win the game if both players play optimally.

## 输入格式

The first line contains a single integer $ t $ ( $ 1 \leq t \leq 10^4 $ ) — the number of test cases. Then $ t $ test cases follow.

Each test case contains a single integer $ n $ ( $ 1 \leq n \leq 10^9 $ ) — the initial number.

## 输出格式

For each test case output "Alice" if Alice will win the game or "Bob" if Bob will win, if both players play optimally.

## 输入输出样例 #1

### 输入 #1

```
4
1
4
12
69
```

### 输出 #1

```
Bob
Alice
Alice
Bob
```

## 说明/提示

In the first test case, the game ends immediately because Alice cannot make a move.

In the second test case, Alice can subtract $ 2 $ making $ n = 2 $ , then Bob cannot make a move so Alice wins.

In the third test case, Alice can subtract $ 3 $ so that $ n = 9 $ . Bob's only move is to subtract $ 3 $ and make $ n = 6 $ . Now, Alice can subtract $ 3 $ again and $ n = 3 $ . Then Bob cannot make a move, so Alice wins.