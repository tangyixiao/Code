# P5541 [USACO19FEB] Sleepy Cow Herding S

## 中文题面

$N$ 头奶牛位于数轴上不同的整数位置。每次只能移动最左或最右的奶牛，移动后它不能仍是端点。目标是让奶牛占据 $N$ 个连续位置。求最少和最多移动次数。

### 输入

第一行 $N$，随后输入 $N$ 个不同位置，$N\le10^5$。

### 输出

第一行最少次数，第二行最多次数。

### 样例

```text
3
4
7
9
```

```text
1
2
```

## English Statement

Move only an endpoint cow to an unoccupied integer position where it is no longer an endpoint. Determine the minimum and maximum moves needed to place all $N$ cows at consecutive positions.
