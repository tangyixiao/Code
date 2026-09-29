# P9352 [JOI 2023 Final] 训猫 / Cat Exercise

## 题目描述

有 $N$ 个猫塔，编号从 $1$ 到 $N$。塔 $i$ 的高度为 $P_i$（$1 \le i \le N$）。这些塔的高度是 $1$ 到 $N$ 之间的不同整数。共有 $N - 1$ 对相邻的塔。对于每个 $j$（$1 \le j \le N - 1$），塔 $A_j$ 和塔 $B_j$ 是相邻的。最开始，可以通过从一个塔移动到相邻的塔，来从一个塔到达任何其他塔。

最开始，一只猫待在高度为 $N$ 的塔上。

然后我们进行**猫运动**。在猫运动中，我们反复选择一个塔并在其上放置一个障碍。然而，我们不能在已经放置障碍的塔上再放置障碍。在这个过程中，将发生以下情况：

- 如果猫不在所选的塔上，什么也不会发生。
- 如果猫在所选的塔上，并且所选塔的每个相邻塔上都有障碍，猫运动将结束。
- 否则，在猫可以通过从塔移动到相邻塔而不受障碍影响到达的塔中，猫将移动到除当前塔外最高的塔。过程中，猫会选择从塔移动到相邻塔的步数最少的路线。

给定塔的高度信息和相邻塔的对，编写程序计算在适当放置障碍的情况下，猫从塔移动到相邻塔的最大可能移动次数之和。

## 输入格式

从标准输入读取以下数据。

> $N$  
> $P_1$ $P_2$ $\cdots$ $P_N$  
> $A_1$ $B_1$  
> $A_2$ $B_2$  
> $\vdots$  
> $A_{N-1}$ $B_{N-1}$

## 输出格式

向标准输出写入一行。输出应包含猫从塔移动到相邻塔的最大可能移动次数之和。

## 输入输出样例 #1

### 输入 #1

```
4
3 4 1 2
1 2
2 3
3 4

```

### 输出 #1

```
3

```

## 输入输出样例 #2

### 输入 #2

```
7
3 2 7 1 5 4 6
1 2
1 3
2 4
2 5
3 6
3 7

```

### 输出 #2

```
7

```

## 说明/提示

## 样例

### 样例 1

如果我们按以下方式进行猫运动，猫总共移动 3 次。

- 我们在塔 1 上放置一个障碍。猫不移动。
- 我们在塔 2 上放置一个障碍。猫从塔 2 移动到塔 3。然后，猫从塔 3 移动到塔 4。
- 我们在塔 4 上放置一个障碍。猫从塔 4 移动到塔 3。
- 我们在塔 3 上放置一个障碍。然后猫运动结束。

由于没有办法进行猫运动，使得猫从塔移动到相邻塔的次数大于或等于 4，因此输出 3。

此样例输入满足子任务 1、2、3、4、5、7 的约束。

### 样例 2

此样例输入满足子任务 4、6、7 的约束。

## 约束

- $2 \le N \le 2\times 10^5$。
- $1 \le P_i \le N$ ($1 \le i \le N$)。
- $P_i \neq P_j$ ($1 \le i < j \le N$)。
- $1 \le A_j < B_j \le N$ ($1 \le j \le N - 1$)。
- 最开始，可以通过从一个塔移动到相邻塔，来从一个塔到达任何其他塔。
- 给定的值都是整数。

## 子任务

1. (7 分) $A_i = i, B_i = i + 1$ ($1 \le i \le N - 1$)，$N \le 16$。
2. (7 分) $A_i = i, B_i = i + 1$ ($1 \le i \le N - 1$)，$N \le 300$。
3. (7 分) $A_i = i, B_i = i + 1$ ($1 \le i \le N - 1$)，$N \le 5 000$。
4. (10 分) $N \le 5 000$。
5. (20 分) $A_i = i, B_i = i + 1$ ($1 \le i \le N - 1$)。
6. (23 分) $A_i =\left\lfloor\frac{i+1}2\right\rfloor, B_i = i + 1$ ($1 \le i \le N - 1$)。这里 $\lfloor x \rfloor$ 是小于或等于 $x$ 的最大整数。
7. (26 分) 无额外约束。

题面翻译由 ChatGPT-4o 提供。

---

# P9352 [JOI 2023 Final] 训猫 / Cat Exercise

## 题目描述

There are $N$ cat towers, numbered from $1$ to $N$. The height of Tower $i$ ($1 \le i \le N$) is $P_i$. The heights of the towers are distinct integers between $1$ and $N$, inclusive. There are $N - 1$ adjacent pairs of towers. For each $j$ ($1 \le j \le N - 1$), Tower $A_j$ and Tower $B_j$ are adjacent to each other. In the beginning, it is possible to travel from a tower to any other tower by repeating moves from towers to adjacent towers.

In the beginning, a cat stays in a tower of height $N$.

Then we perform **cat exercises**. In cat exercises, we repeatedly choose a tower and put an obstacle on it. However, we cannot put an obstacle on a tower where we already put an obstacle on it. During the process, the following will happen.

- If the cat does not stay in the chosen tower, nothing will happen.
- If the cat stays in the chosen tower and there is an obstacle on every tower which is adjacent to the chosen tower, the cat exercises will finish.
- Otherwise, among the towers where the cat can arrive by repeating moves from towers to adjacent towers without obstacles, the cat will move to the highest tower except for the current tower by repeating moves from towers to adjacent towers. In this process, the cat takes the route where the number of moves from towers to adjacent towers becomes minimum.

Given information of the heights of the towers and pairs of adjacent towers, write a program which calculates the maximum possible sum of the number of moves of the cat from towers to adjacent towers if we put obstacles suitably.

## 输入格式

Read the following data from the standard input.

> $N$  
> $P_1$ $P_2$ $\cdots$ $P_N$  
> $A_1$ $B_1$  
> $A_2$ $B_2$  
> $\vdots$    
> $A_{N-1}$ $B_{N-1}$

## 输出格式

Write one line to the standard output. The output should contain the maximum possible sum of the number of moves of the cat from towers to adjacent towers.

## 输入输出样例 #1

### 输入 #1

```
4
3 4 1 2
1 2
2 3
3 4

```

### 输出 #1

```
3

```

## 输入输出样例 #2

### 输入 #2

```
7
3 2 7 1 5 4 6
1 2
1 3
2 4
2 5
3 6
3 7

```

### 输出 #2

```
7

```

## 说明/提示

## Samples

### Sample 1

If we perform the cat exercises in the following way, the cat moves 3 times in total.

- We put an obstacle on Tower 1. The cat does not move.
- We put an obstacle on Tower 2. The cat moves from Tower 2 to Tower 3. Then, the cat moves from Tower 3 to Tower 4.
- We put an obstacle on Tower 4. The cat moves from Tower 4 to Tower 3.
- We put an obstacle on Tower 3. Then the cat exercises finish.

Since there is no way to perform cat exercises where the cat moves more than or equal to 4 times from towers to adjacent towers, output 3.

This sample input satisfies the constraints of Subtasks 1, 2, 3, 4, 5, 7.

### Sample 2

This sample input satisfies the constraints of Subtasks 4, 6, 7.

## Constraints

- $2 \le N \le 2\times 10^5$.
- $1 \le P_i \le N$ ($1 \le i \le N$).
- $P_i \neq P_j$ ($1 \le i < j \le N$).
- $1 \le A_j < B_j \le N$ ($1 \le j \le N - 1$).
- In the beginning, it is possible to travel from a tower to any other tower by repeating moves from towers to adjacent towers.
- Given values are all integers.

## Subtasks

1. (7 points) $A_i = i, B_i = i + 1$ ($1 \le i \le N - 1$), $N \le 16$．
2. (7 points) $A_i = i, B_i = i + 1$ ($1 \le i \le N - 1$), $N \le 300$．
3. (7 points) $A_i = i, B_i = i + 1$ ($1 \le i \le N - 1$), $N \le 5 000$．
4. (10 points) $N \le 5 000$．
5. (20 points) $A_i = i, B_i = i + 1$ ($1 \le i \le N - 1$)．
6. (23 points) $A_i =\left\lfloor\frac{i+1}2\right\rfloor, B_i = i + 1$ ($1 \le i \le N - 1$). Here $\lfloor x \rfloor$ is the largest integer which is smaller than or equal to $x$.
7. (26 points) No additional constraints.