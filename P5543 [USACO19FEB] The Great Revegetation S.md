# P5543 [USACO19FEB] The Great Revegetation S

## 中文题面

有 $N$ 块牧场，每块选择两种草之一。$M$ 条关系要求两块牧场种相同草（S）或不同草（D）。求满足所有关系的方案数，并用二进制输出。

### 输入

第一行 $N,M$。随后每行包含字符 S/D 和两个牧场编号。

$2\le N\le10^5$，$1\le M\le10^5$。

### 输出

方案数的二进制表示；若矛盾则输出 0。

### 样例

```text
3 2
S 1 2
D 3 2
```

```text
10
```

## English Statement

Assign one of two grass types to every pasture. Each constraint requires two pastures to use the same or different types. Print the number of valid assignments in binary, or 0 when the constraints are inconsistent.
