# P6714 [CCO 2018] Wrong Answer

## 题目描述

在一场比赛中，您遇到了一道题：
> 有一个含 $N$ 个点的完全图，边有边权，您可以操作两个人从第一个点去遍历每个点，仅能从编号较小的点到达编号较大的点，求最小的边权和。

您一看，这不是宝宝题吗，于是您秒了它。

但是，此时一名选手的 Python 提交记录吸引了您的注意：
```python
def Solve(N, A):
    # A[i][j] is cost of moving from level i to level j
    # N is the number of levels
    x, y, sx, sy = 1, 1, 0, 0 # Initialize x and y to 1, sx and sy to 0
    for i in range(2, N + 1): # loop from 2 to N
        if sx + A[x][i] < sy + A[y][i]:
            sx += A[x][i]
            x = i
        else:
            sy += A[y][i]
            y = i
    return sx + sy
```
您一眼就看出了这是个错解，于是您决定 Hack 它。

## 输入格式

无需输入。

## 输出格式

第一行为一个整数 $N$。

接下来 $N-1$ 行，第 $i$ 行有 $N-i$ 个数，分别为 $A_{i,i+1},A_{i,i+2}\ldots A_{i,n}$，$A_{i,j}$ 表示 $i$ 到 $j$ 的边权。

## 输入输出样例 #1

### 输入 #1

```

```

### 输出 #1

```
5
1 2 3 4
10 9 8
7 6
5

```

## 说明/提示

#### SPJ 计分标准
您需要保证 $2\le N\le 100$，$1\le A_{i,j}\le 100$，否则，不得分。

您需要保证输出格式正确，否则，您不得分。

如果这份错误代码返回 $X$，而正解是 $Y$，则您将会得到 $\lceil\min(25,\frac{X}{4\times Y})\rceil$ 的分数。

译者提醒：为方便计分，SPJ 计分请使用 $100$ 分作为满分。

#### 样例解释
标解为一个人去第二个点，另一个人去剩下的点，边权和为 $1+2+7+5=15$，而错误代码所返回 $18$，所以可得 $\lceil \frac{18}{4\times 15}\rceil=1$ 分。

#### 说明
本题译自 [Canadian Computing Olympiad 2018](https://cemc.math.uwaterloo.ca/contests/computing/2018) [Day 1](https://cemc.math.uwaterloo.ca/contests/computing/2018/stage%202/day1.pdf) T2 Wrong Answer。

感谢 @[tiger2005](https://www.luogu.com.cn/user/60864) 提供的 SPJ。

---

# P6714 [CCO 2018] Wrong Answer

## 题目描述

In a contest, you encountered a problem:
> There is a complete graph with $N$ vertices and weighted edges. You can control two people starting from vertex $1$ to visit every vertex. You may only move from a smaller-numbered vertex to a larger-numbered vertex. Find the minimum total edge weight.

You took one look and thought it was easy, so you solved it instantly.

However, a contestant’s Python submission caught your attention:
```python
def Solve(N, A):
    # A[i][j] is cost of moving from level i to level j
    # N is the number of levels
    x, y, sx, sy = 1, 1, 0, 0 # Initialize x and y to 1, sx and sy to 0
    for i in range(2, N + 1): # loop from 2 to N
        if sx + A[x][i] < sy + A[y][i]:
            sx += A[x][i]
            x = i
        else:
            sy += A[y][i]
            y = i
    return sx + sy
```
You immediately realized this is a wrong solution, so you decided to hack it.

## 输入格式

No input.

## 输出格式

The first line contains an integer $N$.

In the next $N - 1$ lines, the $i$-th line contains $N - i$ numbers, which are $A_{i,i+1}, A_{i,i+2} \ldots A_{i,n}$. Here, $A_{i,j}$ denotes the edge weight from $i$ to $j$.

## 输入输出样例 #1

### 输入 #1

```

```

### 输出 #1

```
5
1 2 3 4
10 9 8
7 6
5

```

## 说明/提示

#### SPJ Scoring Rules

You must ensure that $2 \le N \le 100$ and $1 \le A_{i,j} \le 100$, otherwise you will receive no score.

You must ensure the output format is correct, otherwise you will receive no score.

If this wrong code returns $X$ and the correct answer is $Y$, then you will get a score of $\lceil \min(25, \frac{X}{4 \times Y}) \rceil$.

Translator’s note: For easier scoring, please use $100$ points as the full score in the SPJ.

#### Sample Explanation

In the official solution, one person goes to the second vertex, and the other person goes to the remaining vertices. The total edge weight is $1 + 2 + 7 + 5 = 15$, while the wrong code returns $18$, so you get $\lceil \frac{18}{4 \times 15} \rceil = 1$ point.

#### Notes

This problem is translated from [Canadian Computing Olympiad 2018](https://cemc.math.uwaterloo.ca/contests/computing/2018) [Day 1](https://cemc.math.uwaterloo.ca/contests/computing/2018/stage%202/day1.pdf) T2 Wrong Answer.

Thanks to @[tiger2005](https://www.luogu.com.cn/user/60864) for providing the SPJ.

Translated by ChatGPT 5