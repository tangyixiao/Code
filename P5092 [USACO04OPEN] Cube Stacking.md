# P5092 [USACO04OPEN] Cube Stacking

## 题目描述

约翰和贝茜在玩一个方块游戏。编号为 $ 1\ldots n $ 的 $ n $（$ 1 \leq n \leq 30000 $）个方块正放在地上，每个构成一个立方柱。

游戏开始后，约翰会给贝茜发出 $ P $（$ 1 \leq P \leq 100000 $）个指令。指令有两种：

1. 移动（```M```）：将包含 ```X``` 的立方柱移动到包含 ```Y``` 的立方柱上。
2. 统计（```C```）：统计含 ```X``` 的立方柱中，在 ```X``` 下方的方块数目。

写个程序帮贝茜完成游戏。

## 输入格式

第 $1$ 行输入 $ P $ ，之后 $ P $ 行每行输入一条指令，形式为 `M X Y` 或者 `C X`。

输入保证不会有将立方柱放在自己头上的指令。

## 输出格式

对于每个统计指令，输出一行一个整数，代表其结果。

## 输入输出样例 #1

### 输入 #1

```
6
M 1 6
C 1
M 2 4
M 2 6
C 3
C 4
```

### 输出 #1

```
1
0
2
```

## 说明/提示

部分数据范围见输入格式。

$1 \le X, Y \le n$。

---

# P5092 [USACO04OPEN] Cube Stacking

## 题目描述

John and Bessie are playing a cube game. There are $n$ cubes numbered $1\ldots n$ ($1 \leq n \leq 30000$) placed on the ground at the start, each forming a single-cube pile.

After the game starts, John will give Bessie $P$ commands ($1 \leq P \leq 100000$). There are two types of commands:

1. Move (`M`): Move the pile containing `X` onto the top of the pile containing `Y`.
2. Count (`C`): Count how many cubes are below cube `X` in the pile containing `X`.

Write a program to help Bessie complete the game.

## 输入格式

The first line contains $P$. The next $P$ lines each contain one command, in the form `M X Y` or `C X`.

The input guarantees that there will be no command that moves a pile onto itself.

## 输出格式

For each count command, output one line with one integer, which is the result.

## 输入输出样例 #1

### 输入 #1

```
6
M 1 6
C 1
M 2 4
M 2 6
C 3
C 4
```

### 输出 #1

```
1
0
2
```

## 说明/提示

Some Constraints are shown in the Input Format.

$1 \le X, Y \le n$.

Translated by ChatGPT 5