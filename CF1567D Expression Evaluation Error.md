# CF1567D Expression Evaluation Error

## 题目描述

在黑板上，Bob 写下了 $n$ 个十进制正整数，它们的和为 $s$。Alice 看到了黑板，但她不小心把黑板上的数字都当作 $11$ 进制的整数，并将它们相加（在 $11$ 进制下相加）。

Bob 应该在黑板上写下哪些数字，使得 Alice 得到的和尽可能大？

## 输入格式

输入包含多组测试用例。第一行包含一个整数 $t$（$1 \leq t \leq 100$），表示测试用例的数量。接下来是每个测试用例的描述。

每个测试用例仅一行，包含两个整数 $s$ 和 $n$（$1 \leq s \leq 10^9$；$1 \leq n \leq \min(100, s)$），分别表示黑板上数字的和以及数字的个数。$s$ 和 $n$ 都以十进制表示。

## 输出格式

对于每个测试用例，输出 $n$ 个正整数，表示 Bob 应该写在黑板上的数字，使得 Alice 得到的和尽可能大。如果有多组答案，输出任意一组均可。

## 输入输出样例 #1

### 输入 #1

```
6
97 2
17 1
111 4
100 2
10 9
999999 3
```

### 输出 #1

```
70 27 
17 
3 4 100 4
10 90
1 1 2 1 1 1 1 1 1 
999900 90 9
```

## 说明/提示

在第一个测试用例中，$70_{10} + 27_{10} = 97_{10}$，而 Alice 的和为 $70_{11} + 27_{11} = 97_{11} = 9 \times 11 + 7 = 106_{10}$。（这里 $x_b$ 表示 $b$ 进制下的数字 $x$。）可以证明 Alice 得到的和不可能比 $106_{10}$ 更大。

在第二个测试用例中，Bob 只能写一个数字，因此他必须写 $17$。

在第三个测试用例中，$3_{10} + 4_{10} + 100_{10} + 4_{10} = 111_{10}$，而 Alice 的和为 $3_{11} + 4_{11} + 100_{11} + 4_{11} = 110_{11} = 1 \times 11^2 + 1 \times 11 = 132_{10}$。可以证明 Alice 得到的和不可能比 $132_{10}$ 更大。

由 ChatGPT 4.1 翻译

---

# CF1567D Expression Evaluation Error

## 题目描述

On the board, Bob wrote $ n $ positive integers in [base](https://en.wikipedia.org/wiki/Positional_notation#Base_of_the_numeral_system) $ 10 $ with sum $ s $ (i. e. in decimal numeral system). Alice sees the board, but accidentally interprets the numbers on the board as base- $ 11 $ integers and adds them up (in base $ 11 $ ).

What numbers should Bob write on the board, so Alice's sum is as large as possible?

## 输入格式

The input consists of multiple test cases. The first line contains an integer $ t $ ( $ 1 \leq t \leq 100 $ ) — the number of test cases. The description of the test cases follows.

The only line of each test case contains two integers $ s $ and $ n $ ( $ 1 \leq s \leq 10^9 $ ; $ 1 \leq n \leq \min(100, s) $ ) — the sum and amount of numbers on the board, respectively. Numbers $ s $ and $ n $ are given in decimal notation (base $ 10 $ ).

## 输出格式

For each test case, output $ n $ positive integers — the numbers Bob should write on the board, so Alice's sum is as large as possible. If there are multiple answers, print any of them.

## 输入输出样例 #1

### 输入 #1

```
6
97 2
17 1
111 4
100 2
10 9
999999 3
```

### 输出 #1

```
70 27 
17 
3 4 100 4
10 90
1 1 2 1 1 1 1 1 1 
999900 90 9
```

## 说明/提示

In the first test case, $ 70_{10} + 27_{10} = 97_{10} $ , and Alice's sum is $ $$$70_{11} + 27_{11} = 97_{11} = 9 \cdot 11 + 7 = 106_{10}. $ $  (Here  $ x\_b $  represents the number  $ x $  in base  $ b $ .) It can be shown that it is impossible for Alice to get a larger sum than  $ 106\_{10} $ .</p><p>In the second test case, Bob can only write a single number on the board, so he must write  $ 17 $ .</p><p>In the third test case,  $ 3\_{10} + 4\_{10} + 100\_{10} + 4\_{10} = 111\_{10} $ , and Alice's sum is  $ $ 3_{11} + 4_{11} + 100_{11} + 4_{11} = 110_{11} = 1 \cdot 11^2 + 1 \cdot 11 = 132_{10}. $ $  It can be shown that it is impossible for Alice to get a larger sum than  $ 132\_{10}$$$.