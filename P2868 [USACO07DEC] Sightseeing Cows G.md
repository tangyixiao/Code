# P2868 [USACO07DEC] Sightseeing Cows G

## 题目描述

农夫约翰决定奖励他的奶牛们的辛勤工作，带它们去大城市游览！奶牛们必须决定如何最好地度过它们的空闲时间。

幸运的是，它们有一张详细的城市地图，显示了 $L$ $(2 \leq L \leq 1000)$ 个主要地标（方便地编号为 $1$ 到 $L$）和 $P$ $(2 \leq P \leq 5000)$ 条连接这些地标的单向牛道。农夫约翰会把奶牛们送到它们选择的一个起始地标，从那里它们将沿着牛道走到一系列其他地标，最后回到它们的起始地标，农夫约翰会在那里接它们回农场。由于城市空间有限，牛道非常狭窄，因此每条牛道的旅行只能沿着一个固定方向进行。

虽然奶牛们可以在城市里待多久都行，但它们很容易感到无聊。参观每个新的地标很有趣，但在它们之间行走需要时间。奶牛们知道每个地标 $i$ 的确切乐趣值 $F_i$ $(1 \leq F_i \leq 1000)$。

奶牛们还了解牛道。牛道 $i$ 连接地标 $L1_i$ 到 $L2_i$（方向为 $L1_i \to L2_i$），需要时间 $T_i$ $(1 \leq T_i \leq 1000)$ 来穿越。

为了度过一个最好的假期，奶牛们希望最大化它们旅行的单位时间平均乐趣值。当然，地标只有在第一次访问时才有趣；奶牛们可以多次经过地标，但它们不会再次感受到它的乐趣值。此外，农夫约翰要求奶牛们至少访问两个地标，以便在假期中得到一些锻炼。

帮助奶牛们找到它们能够实现的最大单位时间乐趣值。

## 输入格式

第 $1$ 行：两个用空格分隔的整数：$L$ 和 $P$

第 $2$ 行到第 $L+1$ 行：第 $i+1$ 行包含一个整数：$F_i$

第 $L+2$ 行到第 $L+P+1$ 行：第 $L+i+1$ 行描述牛道 $i$，包含三个用空格分隔的整数：$L1_i$，$L2_i$ 和 $T_i$

## 输出格式

第 $1$ 行：一个保留两位小数的数字（不要进行显式四舍五入），表示最大可能的单位时间平均乐趣值，如果奶牛们无法按照上述规则计划任何旅行，则输出 $0$。

## 输入输出样例 #1

### 输入 #1

```
5 7
30
10
10
5
10
1 2 3
2 3 2
3 4 5
3 5 2
4 5 5
5 1 3
5 2 2
```

### 输出 #1

```
6.00
```

## 说明/提示

（由 ChatGPT 4o 翻译）

---

# P2868 [USACO07DEC] Sightseeing Cows G

## 题目描述

Farmer John has decided to reward his cows for their hard work by taking them on a tour of the big city! The cows must decide how best to spend their free time.

Fortunately, they have a detailed city map showing the L (2 ≤ L ≤ 1000) major landmarks (conveniently numbered 1.. L) and the P (2 ≤ P ≤ 5000) unidirectional cow paths that join them. Farmer John will drive the cows to a starting landmark of their choice, from which they will walk along the cow paths to a series of other landmarks, ending back at their starting landmark where Farmer John will pick them up and take them back to the farm. Because space in the city is at a premium, the cow paths are very narrow and so travel along each cow path is only allowed in one fixed direction.

While the cows may spend as much time as they like in the city, they do tend to get bored easily. Visiting each new landmark is fun, but walking between them takes time. The cows know the exact fun values Fi (1 ≤ Fi ≤ 1000) for each landmark i.

The cows also know about the cowpaths. Cowpath i connects landmark L1i to L2i (in the direction L1i -> L2i ) and requires time Ti (1 ≤ Ti ≤ 1000) to traverse.

In order to have the best possible day off, the cows want to maximize the average fun value per unit time of their trip. Of course, the landmarks are only fun the first time they are visited; the cows may pass through the landmark more than once, but they do not perceive its fun value again. Furthermore, Farmer John is making the cows visit at least two landmarks, so that they get some exercise during their day off.

Help the cows find the maximum fun value per unit time that they can achieve.

## 输入格式

\* Line 1: Two space-separated integers: L and P

\* Lines 2..L+1: Line i+1 contains a single one integer: Fi

\* Lines L+2..L+P+1: Line L+i+1 describes cow path i with three space-separated integers: L1i , L2i , and Ti

## 输出格式

\* Line 1: A single number given to two decimal places (do not perform explicit rounding), the maximum possible average fun per unit time, or 0 if the cows cannot plan any trip at all in accordance with the above rules.

## 输入输出样例 #1

### 输入 #1

```
5 7
30
10
10
5
10
1 2 3
2 3 2
3 4 5
3 5 2
4 5 5
5 1 3
5 2 2
```

### 输出 #1

```
6.00
```