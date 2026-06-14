# P1322 logo语言

## 题目描述

Logo 语言命令可以指挥海龟在屏幕中爬行。本问题只使用 Logo 语言的三个语句：前进 `FD`，倒退 `BK` 和重复 `REPEAT`，因此，海龟只在一条直线上来回爬行。输入一行 logo 的命令行，输出海龟在屏幕中离开原来位子的距离（假设屏幕很大，可以让海龟移开 $10^9$ 的距离）。

例如：

- 输入 `FD 100` ，输出：$100$。

- 输入 `FD 100 BK 150`， 输出：$50$。

- 输入 `REPEAT 5[FD 100 BK 50]`， 输出：$250$。

- 输入 `REPEAT 5[FD 50 REPEAT 10[FD 100]]`， 输出：$5250$。

## 输入格式

一行，一个字符串，符合上述规定的 logo 命令行。

## 输出格式

一个数据，海龟离开原来位子的距离。

## 输入输出样例 #1

### 输入 #1

```
FD 100

```

### 输出 #1

```
100

```

## 说明/提示

每个语句输入数据的绝对值不超过 $1000$。输出结果不会超过 $10^9$。

---

# P1322 Logo Language

## 题目描述

Logo language commands can direct a turtle to crawl on the screen. This problem uses only three Logo statements: forward `FD`, backward `BK`, and repeat `REPEAT`, so the turtle moves back and forth along a single straight line. Given one line of a Logo command line, output the distance between the turtle and its original position (assume the screen is large enough to let the turtle move up to a distance of $10^9$).

For example:
- Input `FD 100`, output: $100$.
- Input `FD 100 BK 150`, output: $50$.
- Input `REPEAT 5[FD 100 BK 50]`, output: $250$.
- Input `REPEAT 5[FD 50 REPEAT 10[FD 100]]`, output: $5250$.

## 输入格式

One line containing a string that is a valid Logo command line as specified above.

## 输出格式

A single number: the distance from the turtle’s original position.

## 输入输出样例 #1

### 输入 #1

```
FD 100

```

### 输出 #1

```
100

```

## 说明/提示

The absolute value of each statement’s argument does not exceed $1000$. The output will not exceed $10^9$.

Translated by ChatGPT 5