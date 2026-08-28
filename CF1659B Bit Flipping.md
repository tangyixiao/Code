# CF1659B Bit Flipping

## 题目描述

给定一个长度为 $n$ 的二进制字符串。你有恰好 $k$ 次操作机会。每次操作，你必须选择一个比特位。除了被选择的那个比特位外，其余所有比特位的状态都会翻转（$0$ 变为 $1$，$1$ 变为 $0$）。你需要输出在用完所有 $k$ 次操作后，能够得到的字典序最大的字符串。同时，输出每个位被选择的次数。如果有多种方案，可以输出任意一种。

对于长度相同的二进制字符串 $a$ 和 $b$，当且仅当在第一个不同的位置，$a$ 的该位为 $1$ 且 $b$ 的该位为 $0$ 时，$a$ 的字典序大于 $b$。

## 输入格式

第一行包含一个整数 $t$（$1 \le t \le 1000$），表示测试用例的数量。

每个测试用例包含两行。第一行包含两个整数 $n$ 和 $k$（$1 \leq n \leq 2 \cdot 10^5$；$0 \leq k \leq 10^9$）。

第二行包含一个长度为 $n$ 的二进制字符串，每个字符为 $0$ 或 $1$。

所有测试用例中 $n$ 的总和不超过 $2 \cdot 10^5$。

## 输出格式

对于每个测试用例，输出两行。

第一行输出你能得到的字典序最大的字符串。

第二行输出 $n$ 个整数 $f_1, f_2, \ldots, f_n$，其中 $f_i$ 表示第 $i$ 位被选择的次数。所有整数之和必须等于 $k$。

## 输入输出样例 #1

### 输入 #1

```
6
6 3
100001
6 4
100011
6 0
000000
6 1
111001
6 11
101100
6 12
001110
```

### 输出 #1

```
111110
1 0 0 2 0 0 
111110
0 1 1 1 0 1 
000000
0 0 0 0 0 0 
100110
1 0 0 0 0 0 
111111
1 2 1 3 0 4 
111110
1 1 4 2 0 4
```

## 说明/提示

以下是第一个测试用例的解释。每一步展示了在一次操作后字符串的变化。

- 选择第 $1$ 位：$\color{red}{\underline{1}00001} \rightarrow \color{red}{\underline{1}}\color{blue}{11110}$。
- 选择第 $4$ 位：$\color{red}{111\underline{1}10} \rightarrow \color{blue}{000}\color{red}{\underline{1}}\color{blue}{01}$。
- 选择第 $4$ 位：$\color{red}{000\underline{1}01} \rightarrow \color{blue}{111}\color{red}{\underline{1}}\color{blue}{10}$。

最终字符串为 $111110$，这是可以得到的字典序最大的字符串。

由 ChatGPT 4.1 翻译


---


# CF1659B Bit Flipping

## 题目描述

You are given a binary string of length $ n $ . You have exactly $ k $ moves. In one move, you must select a single bit. The state of all bits except that bit will get flipped ( $ 0 $ becomes $ 1 $ , $ 1 $ becomes $ 0 $ ). You need to output the lexicographically largest string that you can get after using all $ k $ moves. Also, output the number of times you will select each bit. If there are multiple ways to do this, you may output any of them.

A binary string $ a $ is lexicographically larger than a binary string $ b $ of the same length, if and only if the following holds:

- in the first position where $ a $ and $ b $ differ, the string $ a $ contains a $ 1 $ , and the string $ b $ contains a $ 0 $ .

## 输入格式

The first line contains a single integer $ t $ ( $ 1 \le t \le 1000 $ ) — the number of test cases.

Each test case has two lines. The first line has two integers $ n $ and $ k $ ( $ 1 \leq n \leq 2 \cdot 10^5 $ ; $ 0 \leq k \leq 10^9 $ ).

The second line has a binary string of length $ n $ , each character is either $ 0 $ or $ 1 $ .

The sum of $ n $ over all test cases does not exceed $ 2 \cdot 10^5 $ .

## 输出格式

For each test case, output two lines.

The first line should contain the lexicographically largest string you can obtain.

The second line should contain $ n $ integers $ f_1, f_2, \ldots, f_n $ , where $ f_i $ is the number of times the $ i $ -th bit is selected. The sum of all the integers must be equal to $ k $ .

## 输入输出样例 #1

### 输入 #1

```
6
6 3
100001
6 4
100011
6 0
000000
6 1
111001
6 11
101100
6 12
001110
```

### 输出 #1

```
111110
1 0 0 2 0 0 
111110
0 1 1 1 0 1 
000000
0 0 0 0 0 0 
100110
1 0 0 0 0 0 
111111
1 2 1 3 0 4 
111110
1 1 4 2 0 4
```

## 说明/提示

Here is the explanation for the first testcase. Each step shows how the binary string changes in a move.

- Choose bit $ 1 $ : $ \color{red}{\underline{1}00001} \rightarrow \color{red}{\underline{1}}\color{blue}{11110} $ .
- Choose bit $ 4 $ : $ \color{red}{111\underline{1}10} \rightarrow \color{blue}{000}\color{red}{\underline{1}}\color{blue}{01} $ .
- Choose bit $ 4 $ : $ \color{red}{000\underline{1}01} \rightarrow \color{blue}{111}\color{red}{\underline{1}}\color{blue}{10} $ .

 The final string is $ 111110 $ and this is the lexicographically largest string we can get.