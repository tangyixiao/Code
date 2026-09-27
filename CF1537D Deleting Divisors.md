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

## 题解

把当前局面分成必胜态和必败态：轮到某人时，若存在一步能把数字变成必败态，则当前局面是必胜态；如果所有合法操作都会到达必胜态，当前局面就是必败态。

### 结论

- **奇数是必败态。** 奇数的合法约数 $d$ 必然是奇数。减去 $d$ 后得到偶数。若这个偶数不是 $2$ 的幂，对手可以减去它的奇数部分，再回到一个更小的奇数。双方这样交替后，最终会到达没有合法操作的奇数，对手输。
- **偶数且不是 $2$ 的幂是必胜态。** 设 $n=2^a q$，其中 $q>1$ 是奇数。选择减去 $q$，剩下 $q(2^a-1)$，这是奇数必败态。
- **$2$ 的幂按指数奇偶交替。** 当 $n=2^a$ 时，减去 $2^{a-1}$ 可以到达 $2^{a-1}$。其他合法选择都会得到一个偶数且非 $2$ 的幂，也就是必胜态。因此 $2^a$ 的胜负与 $2^{a-1}$ 相反。$2=2^1$ 没有合法操作，是必败态；所以指数为奇数时必败，指数为偶数时必胜。

因此，奇数输出 `Bob`；偶数若为 $2^a$，指数 $a$ 为奇数时输出 `Bob`，否则输出 `Alice`；偶数但不是 $2$ 的幂时输出 `Alice`。

### 正确性证明

设奇数局面中当前玩家进行一次操作，减去奇约数 $d>1$。得到的偶数为 $m=n-d$。因为 $d$ 同时整除 $n$ 和 $m$，所以 $d$ 整除 $m$；由于 $d$ 是大于 $1$ 的奇数，$m$ 不可能是 $2$ 的幂。对手可以从 $m=2^a q$ 中减去奇数部分 $q$，回到更小的奇数。由此，奇数局面的先手无法避免对手在后续奇数局面中继续回应，最终先手面对无合法操作的局面，所以奇数是必败态。

对于偶数非 $2$ 的幂，取其奇数部分 $q>1$ 并减去它，会得到奇数必败态，因此该局面必胜。对于 $2^a$，减去 $2^{a-1}$ 会转移到指数少 $1$ 的幂；其余选择会转移到偶数非 $2$ 的幂，即必胜态。因此幂的胜负随指数奇偶交替，并且 $2^1$ 为必败态。以上分类与算法输出一致。

### 复杂度分析

每组数据最多除去 $\log_2 n$ 个因子 $2$，时间复杂度为 $O(\log n)$，额外空间复杂度为 $O(1)$。
