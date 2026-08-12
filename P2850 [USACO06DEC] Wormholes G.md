# P2850 [USACO06DEC] Wormholes G

## 题目背景

[英文题面见此链接](https://www.luogu.com.cn/paste/mxuf6zpl)

## 题目描述

Farmer John 在探索他的农场时发现了许多神奇的虫洞。虫洞的特性非常特殊——它是一个单向通道，能将你传送到它的目的地，而且时间还会回溯到过去！FJ 的每个农场包含 $N (1 \le N \le 500)$ 块编号为 $1 \sim N$ 的田地、$M (1 \le M \le 2500)$ 条双向路径和 $W (1 \le W \le 200)$ 个虫洞。

作为狂热的时间旅行爱好者，FJ 希望实现：从某块田地出发，经过若干路径和虫洞后，在初始离开时间之前回到起点。这样或许他能遇见自己 :)

为了判断可行性，FJ 将提供 $F (1 \le F \le 5)$ 个农场的完整地图。所有路径通行耗时不超过 $10,000$ 秒，虫洞最多能将 FJ 带回 $10,000$ 秒前。

## 输入格式

第 $1$ 行：一个整数 $F$，表示农场数。后续为 $F$ 个农场的数据。

每个农场：

- 第 $1$ 行：三个空格分隔的整数 $N$（田地数）, $M$（双向路径数）, $W$（虫洞数）。

- 第 $2 \sim M+1$ 行：每行三个空格分隔的整数 $(S, E, T)$，表示 $S$ 和 $E$ 间有一条耗时 $T$ 秒的双向路径。两块田地间可能存在多条路径。

- 第 $M+2 \sim M+W+1$ 行：每行三个空格分隔的整数 $(S, E, T)$，表示一条从 $S$ 到 $E$ 的单向虫洞，可将 FJ 带回 $T$ 秒前。

## 输出格式

输出 $F$ 行：对每个农场，若 FJ 能达成目标输出`YES`，否则输出`NO`。

## 输入输出样例 #1

### 输入 #1

```
2
3 3 1
1 2 2
1 3 4
2 3 1
3 1 3
3 2 1
1 2 3
2 3 4
3 1 8
```

### 输出 #1

```
NO
YES
```

## 说明/提示

- 农场 $1$：FJ 无法实现时间回溯。

- 农场 $2$：FJ 可通过环 $1 \to 2 \to 3 \to 1$ 回到起点 $1$ 秒前（可从环上任意点出发实现）。

翻译：DeepSeek-R1

---

# P2850 [USACO06DEC] Wormholes G

## 题目背景

[英文题面见此链接](https://www.luogu.com.cn/paste/mxuf6zpl)

## 题目描述

While exploring his many farms, Farmer John has discovered a number of amazing wormholes. A wormhole is very peculiar because it is a one-way path that delivers you to its destination at a time that is **BEFORE** you entered the wormhole! Each of FJ's farms comprises $N (1 \le N \le 500)$ fields conveniently numbered $1 \sim N, M (1 \le M \le 2500)$ paths, and $W (1 \le W \le 200)$ wormholes.

As FJ is an avid time-traveling fan, he wants to do the following: start at some field, travel through some paths and wormholes, and return to the starting field a time before his initial departure. Perhaps he will be able to meet himself :) .

To help FJ find out whether this is possible or not, he will supply you with complete maps to $F (1 \le F \le 5)$ of his farms. No paths will take longer than $10,000$ seconds to travel and no wormhole can bring FJ back in time by more than $10,000$ seconds.

## 输入格式

Line $1$: A single integer, $F$. $F$ farm descriptions follow.

Line $1$ of each farm: Three space-separated integers respectively: $N$, $M$, and $W$.

Lines $2 \sim M+1$ of each farm: Three space-separated numbers $(S, E, T)$ that describe, respectively: a bidirectional path between $S$ and $E$ that requires $T$ seconds to traverse. Two fields might be connected by more than one path.

Lines $M+2 \sim M+W+1$ of each farm: Three space-separated numbers $(S, E, T)$ that describe, respectively: A one way path from $S$ to $E$ that also moves the traveler back $T$ seconds.

## 输出格式

Lines $1 \sim F$: For each farm, output `YES` if FJ can achieve his goal, otherwise output `NO`.

## 输入输出样例 #1

### 输入 #1

```
2
3 3 1
1 2 2
1 3 4
2 3 1
3 1 3
3 2 1
1 2 3
2 3 4
3 1 8
```

### 输出 #1

```
NO
YES
```

## 说明/提示

For farm $1$, FJ cannot travel back in time.

For farm $2$, FJ could travel back in time by the cycle $1 \to 2 \to 3 \to 1$, arriving back at his starting location $1$ second before he leaves. He could start from anywhere on the cycle to accomplish this.