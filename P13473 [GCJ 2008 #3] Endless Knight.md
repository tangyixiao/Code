# P13473 [GCJ 2008 #3] Endless Knight

## 中文题面

骑士从 $(1,1)$ 出发，只能向右下方走到 $(H,W)$。每步只能增加 $(1,2)$ 或 $(2,1)$。棋盘上有 $R$ 个不能落脚的石头格，允许跳过石头。求路径数模 10007。

### 输入

第一行测试组数 $T$。每组先输入 $H,W,R$，随后 $R$ 个石头坐标。

$T\le100$，$R\le10$。小数据 $H,W\le100$；大数据 $H,W\le10^8$。

### 输出

每组输出 `Case #X: answer`。

### 样例

```text
5
1 1 0
4 4 1
2 1
3 3 0
7 10 2
1 2
7 1
4 4 1
3 2
```

```text
Case #1: 1
Case #2: 2
Case #3: 0
Case #4: 5
Case #5: 1
```

## English Statement

Count paths from $(1,1)$ to $(H,W)$ using only moves $(1,2)$ and $(2,1)$ while avoiding at most ten blocked landing cells. Print each answer modulo the prime 10007 in Google Code Jam case format.
