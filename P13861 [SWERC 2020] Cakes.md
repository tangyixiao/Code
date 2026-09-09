# P13861 [SWERC 2020] Cakes

## 题目描述

:::align{center}
![](https://espresso.codeforces.com/d802e25d143983ebaf159911df93c32ec3a1f5ba.png)
:::

这个夏天，你打算举办一个大型聚会并邀请许多朋友。他们都很喜欢甜食，所以你打算为他们烤一些美味的巧克力蛋糕。
你已经掌握了一份巧克力蛋糕的配方，现在你想尽可能多地烤蛋糕。

已知做一个蛋糕需要用到 $N$ 种食材，同时你也知道自己厨房里现有的食材数量。请问，你最多能烤出多少个蛋糕？

## 输入格式

- 输入的第一行包含一个整数 $N$。
- 接下来 $N$ 行，每行包含两个正整数：第一个整数表示制作一个蛋糕所需的该种食材数量；第二个整数表示你厨房里现有的该种食材数量。

### 数据范围

* $1 \leq N \leq 10$
* 所有食材数量均为 $1$ 到 $10\,000$ 之间的整数。

## 输出格式

输出一个整数，表示在现有食材下你最多能烤出的蛋糕数量。

## 输入输出样例 #1

### 输入 #1

```
3
100 500
2 5
70 1000
```

### 输出 #1

```
2
```

## 输入输出样例 #2

### 输入 #2

```
3
100 50
2 5
70 1000
```

### 输出 #2

```
0
```

## 说明/提示

本翻译由 ChatGPT-5 生成



---


# P13861 [SWERC 2020] Cakes

## 题目描述

:::align{center}

![](https://espresso.codeforces.com/d802e25d143983ebaf159911df93c32ec3a1f5ba.png)

:::


This summer, you plan to organize a large party and invite many
friends. They have a sweet tooth, so you plan to bake nice cakes for them.
You know the recipe for a nice chocolate cake, and you want to cook as
many of them as possible.

Given the $N$ ingredients needed to make a single cake and the
ingredients that you have in your kitchen, how many cakes can you
make?

## 输入格式

- The first line of the input contains a single integer $N$.
- Then, $N$ lines follow, one for each ingredient. Each of these lines
contains two positive integers: the first one is the required quantity
of this ingredient per cake, the second one is the quantity of this
ingredient you have in your kitchen.

**Limits**

- $1 \leq N \leq 10$
- All ingredient quantities will be integers between $1$ and $10\,000$.

## 输出格式

The output should contain a single integer: the maximum number of
cakes you can make using the available ingredients.

## 输入输出样例 #1

### 输入 #1

```
3
100 500
2 5
70 1000
```

### 输出 #1

```
2
```

## 输入输出样例 #2

### 输入 #2

```
3
100 50
2 5
70 1000
```

### 输出 #2

```
0
```