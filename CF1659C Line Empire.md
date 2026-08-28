# CF1659C Line Empire

## 题目描述

你是一位雄心勃勃的国王，想要成为“实数之皇”。但在此之前，你必须先成为“整数之皇”。

考虑一条数轴。你的帝国首都最初位于 $0$。有 $n$ 个未被征服的王国，分别位于 $0 < x_1 < x_2 < \ldots < x_n$ 的位置。你想要征服所有其他王国。

你有两种可用的行动：

- 你可以将首都的位置（假设当前位置为 $c_1$）迁移到任意一个已被征服的王国（其位置为 $c_2$），花费为 $a\cdot |c_1-c_2|$。
- 你可以从当前首都（位置为 $c_1$）出发，征服一个未被征服的王国（其位置为 $c_2$），花费为 $b\cdot |c_1-c_2|$。如果在目标和你的首都之间有未被征服的王国，则不能征服该王国。

注意，你不能将首都迁移到没有王国的位置。换句话说，任何时候你的首都只能位于 $0$ 或 $x_1,x_2,\ldots,x_n$ 之一。还要注意，征服一个王国不会改变首都的位置。

请你求出征服所有王国的最小总花费。最终首都可以位于任意位置。

## 输入格式

第一行包含一个整数 $t$（$1 \le t \le 1000$），表示测试用例的数量。每个测试用例的描述如下。

每个测试用例的第一行包含三个整数 $n$、$a$ 和 $b$（$1 \leq n \leq 2 \cdot 10^5$；$1 \leq a,b \leq 10^5$）。

每个测试用例的第二行包含 $n$ 个整数 $x_1, x_2, \ldots, x_n$（$1 \leq x_1 < x_2 < \ldots < x_n \leq 10^8$）。

所有测试用例中 $n$ 的总和不超过 $2 \cdot 10^5$。

## 输出格式

对于每个测试用例，输出一个整数，表示征服所有王国的最小花费。

## 输入输出样例 #1

### 输入 #1

```
4
5 2 7
3 5 12 13 21
5 6 3
1 5 6 21 30
2 9 3
10 15
11 27182 31415
16 18 33 98 874 989 4848 20458 34365 38117 72030
```

### 输出 #1

```
173
171
75
3298918744
```

## 说明/提示

以下是第二个测试用例的最优操作序列：

1. 以花费 $3\cdot(1-0)=3$ 征服位于 $1$ 的王国。
2. 以花费 $6\cdot(1-0)=6$ 将首都迁移到 $1$。
3. 以花费 $3\cdot(5-1)=12$ 征服位于 $5$ 的王国。
4. 以花费 $6\cdot(5-1)=24$ 将首都迁移到 $5$。
5. 以花费 $3\cdot(6-5)=3$ 征服位于 $6$ 的王国。
6. 以花费 $3\cdot(21-5)=48$ 征服位于 $21$ 的王国。
7. 以花费 $3\cdot(30-5)=75$ 征服位于 $30$ 的王国。

总花费为 $3+6+12+24+3+48+75=171$。你无法得到比这更低的花费。

由 ChatGPT 4.1 翻译

---

# CF1659C Line Empire

## 题目描述

You are an ambitious king who wants to be the Emperor of The Reals. But to do that, you must first become Emperor of The Integers.

Consider a number axis. The capital of your empire is initially at $ 0 $ . There are $ n $ unconquered kingdoms at positions $ 0<x_1<x_2<\ldots<x_n $ . You want to conquer all other kingdoms.

There are two actions available to you:

- You can change the location of your capital (let its current position be $ c_1 $ ) to any other conquered kingdom (let its position be $ c_2 $ ) at a cost of $ a\cdot |c_1-c_2| $ .
- From the current capital (let its current position be $ c_1 $ ) you can conquer an unconquered kingdom (let its position be $ c_2 $ ) at a cost of $ b\cdot |c_1-c_2| $ . You cannot conquer a kingdom if there is an unconquered kingdom between the target and your capital.

Note that you cannot place the capital at a point without a kingdom. In other words, at any point, your capital can only be at $ 0 $ or one of $ x_1,x_2,\ldots,x_n $ . Also note that conquering a kingdom does not change the position of your capital.

Find the minimum total cost to conquer all kingdoms. Your capital can be anywhere at the end.

## 输入格式

The first line contains a single integer $ t $ ( $ 1 \le t \le 1000 $ ) — the number of test cases. The description of each test case follows.

The first line of each test case contains $ 3 $ integers $ n $ , $ a $ , and $ b $ ( $ 1 \leq n \leq 2 \cdot 10^5 $ ; $ 1 \leq a,b \leq 10^5 $ ).

The second line of each test case contains $ n $ integers $ x_1, x_2, \ldots, x_n $ ( $ 1 \leq x_1 < x_2 < \ldots < x_n \leq 10^8 $ ).

The sum of $ n $ over all test cases does not exceed $ 2 \cdot 10^5 $ .

## 输出格式

For each test case, output a single integer — the minimum cost to conquer all kingdoms.

## 输入输出样例 #1

### 输入 #1

```
4
5 2 7
3 5 12 13 21
5 6 3
1 5 6 21 30
2 9 3
10 15
11 27182 31415
16 18 33 98 874 989 4848 20458 34365 38117 72030
```

### 输出 #1

```
173
171
75
3298918744
```

## 说明/提示

Here is an optimal sequence of moves for the second test case:

1. Conquer the kingdom at position $ 1 $ with cost $ 3\cdot(1-0)=3 $ .
2. Move the capital to the kingdom at position $ 1 $ with cost $ 6\cdot(1-0)=6 $ .
3. Conquer the kingdom at position $ 5 $ with cost $ 3\cdot(5-1)=12 $ .
4. Move the capital to the kingdom at position $ 5 $ with cost $ 6\cdot(5-1)=24 $ .
5. Conquer the kingdom at position $ 6 $ with cost $ 3\cdot(6-5)=3 $ .
6. Conquer the kingdom at position $ 21 $ with cost $ 3\cdot(21-5)=48 $ .
7. Conquer the kingdom at position $ 30 $ with cost $ 3\cdot(30-5)=75 $ .

The total cost is $ 3+6+12+24+3+48+75=171 $ . You cannot get a lower cost than this.