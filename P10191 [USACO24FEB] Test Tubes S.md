# P10191 [USACO24FEB] Test Tubes S

## 题目描述

Bessie 最近开始对化学感兴趣。目前，她有两种不同颜色 $1$ 和 $2$ 的液体，彼此之间无法混合。她有两个无限容量的试管，各装有 $N$（$1\le N\le 10^5$）单位的这两种颜色的液体混合物。由于液体无法混合，一旦沉淀，它们就会分成不同颜色的层。因此，两个试管可以被视为两个字符串 $f_1f_2\ldots f_N$ 和 $s_1s_2\ldots s_N$，其中 $f_i$ 表示距离第一个试管底部 $i$ 单位处的液体的颜色，$s_i$ 表示距离第二个试管底部 $i$ 单位处的液体的颜色。输入保证两种颜色的液体至少各有一个单位。

Bessie 想要分离这些液体，以使得每个试管包含一种颜色的液体的所有单位。她有第三个无限容量的空烧杯来帮助她完成这一任务。当 Bessie 进行一次「倾倒」时，她将一个试管或烧杯顶部的所有颜色为 $i$ 的液体移至另一个的顶部。

求出将所有液体分离到两个试管中所需的最小的倾倒次数，以及所需的移动操作。两个试管最终包含的液体颜色不影响正确性，但烧杯必须是空的。

有 $T$（$1\le T\le 10$）个测试用例，每个测试用例有一个参数 $P$。

设将液体分离至试管中的最小倾倒次数为 $M$。

- 若 $P=1$，当你仅输出 $M$ 时可以得到分数。
- 若 $P=2$，当你输出 $A$，其中 $M\le A\le M+5$，并在以下 $A$ 行输出以该操作次数构造的一个方案时，可以得到分数。每一行包含来源试管和目标试管（$1$，$2$，或用 $3$ 表示烧杯）。操作之前，来源试管必须是非空的，并且不得将一个试管向其自身倾倒。
- 若 $P=3$，当你输出 $M$，并输出以该操作次数构造的一个方案时，可以得到分数。

## 输入格式

输入的第一行包含 $T$，为测试用例的数量。对于每一个测试用例，第一行包含 $N$ 和 $P$，为每个试管最初装有液体的数量以及询问类型。下一行包含 $f_1f_2f_3\ldots f_N$，表示第一个试管。$f_i\in \{1,2\}$，$f_1$ 表示试管的底部。下一行包含 $s_1s_2s_3\ldots s_N$，表示第二个试管。$s_i\in \{1,2\}$，$s_1$ 表示试管的底部。

输入保证 $1$ 和 $2$ 都至少在一个字符串中出现。

## 输出格式

对于每一个测试用例，输出一个整数，表示分离试管中液体的最少倾倒次数。根据询问类型，你可能还需要提供合法的构造方案。

## 输入输出样例 #1

### 输入 #1

```
6
4 1
1221
2211
4 2
1221
2211
4 3
1221
2211
6 3
222222
111112
4 3
1121
1222
4 2
1121
1222
```

### 输出 #1

```
4
4
1 2
1 3
2 1
3 2
4
1 2
1 3
2 1
3 2
1
2 1
5
2 3
1 2
1 3
1 2
3 1
6
2 3
1 2
1 3
1 2
2 1
3 2
```

## 说明/提示

### 样例解释

在前三个测试用例中，分离试管的最小倾倒次数为 $4$。我们可以看到以下操作是如何分离试管的：

初始状态：

```plain
1: 1221
2: 2211
3: 
```

在操作 `1 2` 后：

```plain
1: 122
2: 22111
3: 
```

在操作 `1 3` 后：

```plain
1: 1
2: 22111
3: 22
```

在操作 `2 1` 后：

```plain
1: 1111
2: 22
3: 22
```

在操作 `3 2` 后：

```plain
1: 1111
2: 2222
3:
```

在最后一个测试用例中，最小倾倒次数为 $5$。然而，由于 $P=2$，给出的 $6$ 次操作的构造也是合法的，因为它与最优解的差在 $5$ 次倾倒之内。

### 测试点性质

- 测试点 $2-6$：$P=1$。
- 测试点 $7-11$：$P=2$。
- 测试点 $12-21$：没有额外限制。

除此之外，输入保证除样例外的所有测试点均有 $T=10$。

---

# P10191 [USACO24FEB] Test Tubes S

## 题目描述

Bessie has recently gotten into chemistry. At the moment, she has two different colors $1$ and $2$ of various liquids that don't mix well with one another. She has two test tubes of infinite capacity filled with $N$ $(1 \leq N \leq 10^5)$ units each of some mixture of liquids of these two colors. Because the liquids don't mix,  once they settled, they divided into layers of separate colors. Because of this, the two tubes can be viewed as strings $f_1f_2\ldots f_N$ and $s_1s_2\ldots s_N$  where $f_i$ represents the color of the liquid that is $i$ units from the bottom of the first tube, and $s_i$ represents the color of the liquid that is $i$ units from the bottom of the second tube. It is guaranteed that there is at least one unit of each color of liquid.  

Bessie wants to separate these liquids so that each test tube contains all units of one color of liquid. She has a third empty beaker of infinite capacity to help her in this task. When Bessie makes a "pour", she moves all liquid of color $i$ at the top of one test tube or beaker into another.  

Determine the minimum number of pours to separate all the liquid into the two test tubes, and the series of moves needed to do so. It does not matter which test tube ends up with which color, but the beaker must be empty..  

There will be $T$ ($1 \leq T \leq 10$) test cases, with a parameter $P$ for each test case.  

Suppose the minimum number of pours to separate the liquids into the original tubes is $M$.  


- If $P=1$, you will receive credit if you print only $M$.
- If $P=2$, you will receive credit if you print an integer $A$ such that $M \leq A \leq M+5$, followed by $A$ lines that construct a solution with that number of moves. Each line should contain the source and the destination tube ($1$, $2$, or $3$ for the beaker). The source tube must be nonempty before the move and a tube may not be poured into itself.
- If $P=3$, you will receive credit if you print $M$, followed by a valid construction using that number of moves.

## 输入格式

The first line contains $T$, the. number of test cases. For each test case, the next line contains $N$ and $P$ representing the amount each test tube is initially filled to, and the query type. The following line contains $f_1f_2f_3\ldots f_N$ representing  the first test tube. $f_i \in \{ 1,2 \}$ and $f_1$ represents the bottom of the test tube. The subsequent line contains $s_1s_2s_3\ldots s_N$ representing the second test tube. $s_i \in \{ 1,2 \}$ and $s_1$ represents the bottom of the test tube.  

It is guaranteed that there will be at least one $1$ and one $2$ across both input strings.

## 输出格式

For each test case, you will print a single number representing the minimum pours to separate the liquid in the test tubes. Depending on the query type, you may also need to provide a valid construction.

## 输入输出样例 #1

### 输入 #1

```
6
4 1
1221
2211
4 2
1221
2211
4 3
1221
2211
6 3
222222
111112
4 3
1121
1222
4 2
1121
1222
```

### 输出 #1

```
4
4
1 2
1 3
2 1
3 2
4
1 2
1 3
2 1
3 2
1
2 1
5
2 3
1 2
1 3
1 2
3 1
6
2 3
1 2
1 3
1 2
2 1
3 2
```

## 说明/提示

In the first three test cases, the minimum number of pours to separate the tubes is $4$. We can see how the following moves separate the test tubes:  

Initial state: 
```
1: 1221
2: 2211
3: 
```
After the move "1 2": 
```
1: 122
2: 22111
3: 
```
After the move "1 3": 
```
1: 1
2: 22111
3: 22
```
After the move "2 1": 
```
1: 1111
2: 22
3: 22
```
After the move "3 2": 
```
1: 1111
2: 2222
3:
```


In the last test case, the minimum amount of pours is $5$. However, since $P=2$, the given construction with $6$ moves is valid since it is within $5$ pours from the optimal answer. 
#### SCORING:
- Inputs 2-6: $P = 1$
- Inputs 7-11: $P=2$
- Inputs 12-21: No additional constraints.

Additionally, it is guaranteed that $T=10$ for all inputs besides the sample.