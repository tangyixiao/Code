# P3800 Power 收集

## 题目背景

据说在红雾异变时，博丽灵梦单身前往红魔馆，用十分强硬的手段将事件解决了。

然而当时灵梦在 Power 达到 MAX 之前，不具有“上线收点”的能力，所以她想要知道她能收集多少 P 点，然而这个问题她答不上来，于是她找到了学 OI 的你。

## 题目描述

可以把游戏界面理解成一个 $N$ 行 $M$ 列的棋盘，有 $K$ 个格子上有 P 点，其价值为 $\operatorname{val}(i,j)$。

初始灵梦可以选择在第一行的任意一个格子出发，每秒她必须下移一格。

灵梦具有一个左右移动的速度 $T$，可以使她每秒向左或右移动至多 $T$ 格，也可以不移动，并且在单次移动中不能折返。移动可视为瞬间完成，不经过路途上的点，只能获得目标格子的 P 点。

求最终她能获得的所有 P 点的价值总和最大是多少？

## 输入格式

第一行四个整数，$N,M,K,T$。

接下来 $K$ 行每行 $3$ 个整数 $x,y,v$，代表第 $x$ 行第 $y$ 列有一个 $\operatorname{val}$ 为 $v$ 的 P 点，数据保证一个格子上最多只有 $1$ 个 P 点。

## 输出格式

一个整数，表示灵梦能获得的 P 点的价值总和的最大值。

## 输入输出样例 #1

### 输入 #1

```
3 3 4 1
1 1 3
1 2 1
2 2 3
3 3 3

```

### 输出 #1

```
9
```

## 说明/提示

对于 $40\%$ 的测试点，$1 \le N,M,T,K \le 200$。

对于 $100\%$ 的测试点，$1 \le N,M,T,K \le 4000$，$0 \le v \le 100$，$N,M,K,T$ 均为整数。

by-szc

---

# P3800 Power Collection

## 题目背景

It is said that during the Scarlet Mist incident, Reimu Hakurei went alone to the Scarlet Devil Mansion and resolved the incident with very forceful means. However, before her Power reached MAX, Reimu did not have the ability to "collect at the top line" (上线收点), so she wanted to know how many P points she could collect. She could not answer this question, so she turned to you, who study OI.

## 题目描述

Treat the game screen as an $N$-row by $M$-column grid. There are P points on $K$ cells, and their values are $\operatorname{val}(i,j)$.

Initially, Reimu may choose any cell in the first row to start. Each second, she must move down by exactly one row.

Reimu has a horizontal speed $T$, allowing her each second to move left or right by at most $T$ columns, or not move horizontally at all, and she cannot reverse direction within a single move. Movement is considered instantaneous: she does not pass through intermediate cells en route and can only obtain the P point on the destination cell.

Compute the maximum possible total value of all P points she can obtain.

## 输入格式

The first line contains four integers, $N,M,K,T$.

Each of the next $K$ lines contains three integers $x,y,v$, indicating that there is a P point with $\operatorname{val}=v$ at row $x$, column $y$. It is guaranteed that there is at most $1$ P point on any cell.

## 输出格式

Output a single integer, the maximum total value of P points Reimu can obtain.

## 输入输出样例 #1

### 输入 #1

```
3 3 4 1
1 1 3
1 2 1
2 2 3
3 3 3

```

### 输出 #1

```
9
```

## 说明/提示

For $40\%$ of the testdata, $1 \le N,M,T,K \le 200$.

For $100\%$ of the testdata, $1 \le N,M,T,K \le 4000$, $0 \le v \le 100$, and $N,M,K,T$ are all integers.

by-szc

Translated by ChatGPT 5