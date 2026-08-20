# P5833 [USACO19DEC] Livestock Lineup B

## 中文题面

Farmer John 有 8 头名字固定的奶牛：Bessie、Buttercup、Belinda、Beatrice、Bella、Blue、Betsy、Sue。每条限制要求两头指定奶牛在挤奶顺序中相邻。

输出满足所有限制的字典序最小排列。保证至少存在一个合法排列。

### 输入

第一行是 $N$，随后 $N$ 行形如 `X must be milked beside Y`。$1\le N\le7$。

### 输出

按顺序输出 8 个名字，每行一个。

### 样例

```text
3
Buttercup must be milked beside Bella
Blue must be milked beside Bella
Sue must be milked beside Beatrice
```

```text
Beatrice
Sue
Belinda
Bessie
Betsy
Blue
Bella
Buttercup
```

## English Statement

Arrange the eight fixed cow names so every given pair is adjacent. Among all valid arrangements, print the lexicographically smallest one. The input contains at most seven sentences of the form `X must be milked beside Y`.
