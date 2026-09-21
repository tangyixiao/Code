# CF1567C Carrying Conundrum

## 题目描述

Alice 刚学会加法。然而，她还没有完全理解“进位”的概念——她不是向左一位进位，而是向左两位进位。

例如，正常情况下计算 $2039 + 2976$ 的过程如下：

![](https://cdn.luogu.com.cn/upload/vjudge_pic/CF1567C/7f811803128f9de09a9d354d6ba38f6c979516bb.png)

然而，Alice 的计算方式如下：

![](https://cdn.luogu.com.cn/upload/vjudge_pic/CF1567C/83982f3a368c4bf27357d999f4274a4bb752e11c.png)

具体来说，她的做法如下：

- 将 $9$ 和 $6$ 相加得到 $15$，并把 $1$ 进位到左边第二列，也就是“$0$ $9$”那一列；
- 将 $3$ 和 $7$ 相加得到 $10$，并把 $1$ 进位到左边第二列，也就是“$2$ $2$”那一列；
- 将 $1$、$0$ 和 $9$ 相加得到 $10$，并把 $1$ 进位到左边第二列，也就是加号上方那一列；
- 将 $1$、$2$ 和 $2$ 相加得到 $5$；
- 将 $1$ 单独写下得到 $1$。

因此，她最终得到了错误的结果 $15005$。

现在，Alice 走到 Bob 面前，说她将两个数相加得到了 $n$。但 Bob 知道 Alice 是用她自己的方式加的。请你帮助 Bob 计算，有多少对有序正整数对 $(a, b)$，使得 Alice 用她的方式相加后结果为 $n$。注意，如果 $a \ne b$，则 $(a, b)$ 和 $(b, a)$ 被视为不同的有序对。

## 输入格式

输入包含多组测试用例。第一行包含一个整数 $t$（$1 \leq t \leq 1000$），表示测试用例的数量。

接下来每个测试用例一行，包含一个整数 $n$（$2 \leq n \leq 10^9$），表示 Alice 展示给 Bob 的结果。

## 输出格式

对于每个测试用例，输出一个整数，表示有多少对有序正整数对 $(a, b)$，使得 Alice 用她的方式相加后结果为 $n$。

## 输入输出样例 #1

### 输入 #1

```
5
100
12
8
2021
10000
```

### 输出 #1

```
9
4
7
44
99
```

## 说明/提示

在第一个测试用例中，无论 Alice 计算 $1 + 9$、$2 + 8$、$3 + 7$、$4 + 6$、$5 + 5$、$6 + 4$、$7 + 3$、$8 + 2$ 或 $9 + 1$，她都会得到 $100$。下图展示了 Alice 计算 $6 + 4$ 的过程：

![](https://cdn.luogu.com.cn/upload/vjudge_pic/CF1567C/b16910e4b25eab78326b49caad3574b10b90fef3.png)

由 ChatGPT 4.1 翻译

---


# CF1567C Carrying Conundrum

## 题目描述

Alice has just learned addition. However, she hasn't learned the concept of "carrying" fully — instead of carrying to the next column, she carries to the column two columns to the left.

For example, the regular way to evaluate the sum $ 2039 + 2976 $ would be as shown:

 ![](https://cdn.luogu.com.cn/upload/vjudge_pic/CF1567C/7f811803128f9de09a9d354d6ba38f6c979516bb.png)However, Alice evaluates it as shown:

 ![](https://cdn.luogu.com.cn/upload/vjudge_pic/CF1567C/83982f3a368c4bf27357d999f4274a4bb752e11c.png)In particular, this is what she does:

- add $ 9 $ and $ 6 $ to make $ 15 $ , and carry the $ 1 $ to the column two columns to the left, i. e. to the column " $ 0 $ $ 9 $ ";
- add $ 3 $ and $ 7 $ to make $ 10 $ and carry the $ 1 $ to the column two columns to the left, i. e. to the column " $ 2 $ $ 2 $ ";
- add $ 1 $ , $ 0 $ , and $ 9 $ to make $ 10 $ and carry the $ 1 $ to the column two columns to the left, i. e. to the column above the plus sign;
- add $ 1 $ , $ 2 $ and $ 2 $ to make $ 5 $ ;
- add $ 1 $ to make $ 1 $ .

 Thus, she ends up with the incorrect result of $ 15005 $ .Alice comes up to Bob and says that she has added two numbers to get a result of $ n $ . However, Bob knows that Alice adds in her own way. Help Bob find the number of ordered pairs of positive integers such that when Alice adds them, she will get a result of $ n $ . Note that pairs $ (a, b) $ and $ (b, a) $ are considered different if $ a \ne b $ .

## 输入格式

The input consists of multiple test cases. The first line contains an integer $ t $ ( $ 1 \leq t \leq 1000 $ ) — the number of test cases. The description of the test cases follows.

The only line of each test case contains an integer $ n $ ( $ 2 \leq n \leq 10^9 $ ) — the number Alice shows Bob.

## 输出格式

For each test case, output one integer — the number of ordered pairs of positive integers such that when Alice adds them, she will get a result of $ n $ .

## 输入输出样例 #1

### 输入 #1

```
5
100
12
8
2021
10000
```

### 输出 #1

```
9
4
7
44
99
```

## 说明/提示

In the first test case, when Alice evaluates any of the sums $ 1 + 9 $ , $ 2 + 8 $ , $ 3 + 7 $ , $ 4 + 6 $ , $ 5 + 5 $ , $ 6 + 4 $ , $ 7 + 3 $ , $ 8 + 2 $ , or $ 9 + 1 $ , she will get a result of $ 100 $ . The picture below shows how Alice evaluates $ 6 + 4 $ :

 ![](https://cdn.luogu.com.cn/upload/vjudge_pic/CF1567C/b16910e4b25eab78326b49caad3574b10b90fef3.png)