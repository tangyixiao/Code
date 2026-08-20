# CF1691C Sum of Substrings

## 题目描述

给定由 $0$ 和 $1$ 组成的长度为 $n$ 的字符串 $ s $ 。

定义一个十进制数字 $ d_i $ 十位和个位分别为 $ s_i $ 和  $ s_{i+1} $ 。 定义 $ f(s) $ 为所有合法的 $ d_i $ 的和。也就是说 $ f(s) = \sum\limits_{i=1}^{n-1} d_i $ 。

比如， 对于字符串 $ s = 1011 $ ：

- $ d_1 = 10 $ ；
- $ d_2 = 01 $ ；
- $ d_3 = 11 $ ;
- $ f(s) = 10 + 01 + 11 = 22 $ 。

在一次操作中你可以交换两个相邻的元素。 找到经过不多于 $k$ 次操作后 $ f(s) $ 的最小值。


保证所有数据中 $ n $ 的和不超过 $ 10^5 $ 。

## 输入格式

每个测试点有多组数据。

第一行一个整数 $t$ 表示数据个数。

接下来 $2t$ 行，每组数据 $2$ 行。

每组数据的第一行两个整数 $ n $ 和 $ k $ ( $ 2 \le n \le 10^5 $ , $ 0 \le k \le 10^9 $ ) ，分别表示字符串长度和最大操作数。

## 输出格式

共 $t$ 行，每一行一个整数，表示经过不多于 $k$ 次操作后 $ f(s) $ 的最小值。

## 输入输出样例 #1

### 输入 #1

```
3
4 0
1010
7 1
0010100
5 2
00110
```

### 输出 #1

```
21
22
12
```

## 说明/提示

- 对于第一组数据，不能做任何操作。$ f(s) = f(1010) = 10 + 01 + 10 = 21 $ 。
- 对于第二组数据，可以将字符串变成 $0011000$。 此时 $ f $ 的值为 $ 22 $ 。
- 对于第三组数据，可以将字符串变成 $00011$。 此时 $ f $ 的值为 $ 12 $ 。

---

# CF1691C Sum of Substrings

## 题目描述

You are given a binary string $ s $ of length $ n $ .

Let's define $ d_i $ as the number whose decimal representation is $ s_i s_{i+1} $ (possibly, with a leading zero). We define $ f(s) $ to be the sum of all the valid $ d_i $ . In other words, $ f(s) = \sum\limits_{i=1}^{n-1} d_i $ .

For example, for the string $ s = 1011 $ :

- $ d_1 = 10 $ (ten);
- $ d_2 = 01 $ (one)
- $ d_3 = 11 $ (eleven);
- $ f(s) = 10 + 01 + 11 = 22 $ .

In one operation you can swap any two adjacent elements of the string. Find the minimum value of $ f(s) $ that can be achieved if at most $ k $ operations are allowed.

## 输入格式

Each test contains multiple test cases. The first line contains the number of test cases $ t $ ( $ 1 \le t \le 10^5 $ ). Description of the test cases follows.

First line of each test case contains two integers $ n $ and $ k $ ( $ 2 \le n \le 10^5 $ , $ 0 \le k \le 10^9 $ ) — the length of the string and the maximum number of operations allowed.

The second line of each test case contains the binary string $ s $ of length $ n $ , consisting of only zeros and ones.

It is also given that sum of $ n $ over all the test cases doesn't exceed $ 10^5 $ .

## 输出格式

For each test case, print the minimum value of $ f(s) $ you can obtain with at most $ k $ operations.

## 输入输出样例 #1

### 输入 #1

```
3
4 0
1010
7 1
0010100
5 2
00110
```

### 输出 #1

```
21
22
12
```

## 说明/提示

- For the first example, you can't do any operation so the optimal string is $ s $ itself. $ f(s) = f(1010) = 10 + 01 + 10 = 21 $ .
- For the second example, one of the optimal strings you can obtain is "0011000". The string has an $ f $ value of $ 22 $ .
- For the third example, one of the optimal strings you can obtain is "00011". The string has an $ f $ value of $ 12 $ .