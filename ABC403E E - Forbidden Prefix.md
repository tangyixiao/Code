# AT_abc403_e [ABC403E] Forbidden Prefix

## 题目描述

[problemUrl]: https://atcoder.jp/contests/abc403/tasks/abc403_e

现有两个字符串多重集合 $X$ 和 $Y$，初始时均为空集合。

需要依次处理 $Q$ 个查询。第 $i$ 个查询给出整数 $T_i$ 和字符串 $S_i$：
- 若 $T_i=1$，则将 $S_i$ 加入 $X$；
- 若 $T_i=2$，则将 $S_i$ 加入 $Y$。

在每个查询处理完成后，请输出以下值：
- $Y$ 中满足"不以 $X$ 中任何字符串作为前缀"的字符串数量。

## 输入格式

输入通过标准输入给出，格式如下：

> $Q$  
> $T_1$ $S_1$  
> $T_2$ $S_2$  
> $\vdots$  
> $T_Q$ $S_Q$

## 输出格式

输出 $Q$ 行。第 $i$ 行 $(1 \leq i \leq Q)$ 应输出第 $i$ 个查询处理后的答案。

## 输入输出样例 #1

### 输入 #1

```
4
1 at
2 watcoder
2 atcoder
1 wa
```

### 输出 #1

```
0
1
1
0
```

## 输入输出样例 #2

### 输入 #2

```
10
1 w
1 avko
2 atcoder
1 bzginn
2 beginner
1 atco
2 contest
1 ntxcdg
1 atc
1 contest
```

### 输出 #2

```
0
0
1
1
2
1
2
2
2
1
```

## 说明/提示

### 约束条件

- $Q$ 是 $1$ 到 $2 \times 10^5$ 之间的整数
- $T_i \in \{1,2\}$
- $S_i$ 是长度在 $1$ 到 $5 \times 10^5$ 之间的小写字母字符串
- $\displaystyle \sum_{i=1}^Q |S_i| \leq 5 \times 10^5$

### 样例解释 #1

各查询处理后的结果如下：
- $i=1$：$Y$ 为空集，答案为 $0$
- $i=2$：`watcoder` 不以 $X$ 中的 `at` 为前缀，答案为 $1$
- $i=3$：`watcoder` 仍满足条件，而 `atcoder` 以 `at` 为前缀，答案为 $1$
- $i=4$：`watcoder` 以新增的 `wa` 为前缀，`atcoder` 以 `at` 为前缀，答案为 $0$

翻译由 DeepSeek V3 完成