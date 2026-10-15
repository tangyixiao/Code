# P5123 [USACO18DEC] Cowpatibility G

## 题目背景

2025/4/9 加入两组 hack 数据（@Starrykiller）。

## 题目描述

研究证明，有一个因素在两头奶牛能否作为朋友和谐共处这方面比其他任何因素都来得重要——她们是不是喜欢同一种口味的冰激凌！

Farmer John 的 $N$ 头奶牛（$2\le N\le 5\times 10^4$）各自列举了她们最喜欢的五种冰激凌口味的清单。为使这个清单更加精炼，每种可能的口味用一个不超过 $10^6$ 的正整数 $\texttt{ID}$ 表示。如果两头奶牛的清单上有至少一种共同的冰激凌口味，那么她们可以和谐共处。

请求出不能和谐共处的奶牛的对数。

## 输入格式

输入的第一行包含 $N$。以下 $N$ 行每行包含 $5$ 个整数（各不相同），表示一头奶牛最喜欢的冰激凌口味。

## 输出格式

输出不能和谐共处的奶牛的对数。

## 输入输出样例 #1

### 输入 #1

```
4
1 2 3 4 5
1 2 3 10 8
10 9 8 7 6
50 60 70 80 90
```

### 输出 #1

```
4
```

## 说明/提示

在这里，奶牛 $4$ 不能和奶牛 $1$、$2$、$3$ 中的任一头和谐共处，奶牛 $1$ 和奶牛 $3$ 也不能和谐共处。

---

# P5123 [USACO18DEC] Cowpatibility G

## 题目背景

On 2025/4/9, two groups of hack testdata were added (@Starrykiller).

## 题目描述

Research shows that one factor matters more than anything else in whether two cows can get along as friends—whether they like the same ice cream flavor.

Farmer John has $N$ cows ($2 \le N \le 5 \times 10^4$). Each cow lists her five favorite ice cream flavors. To make the list more concise, each possible flavor is represented by a positive integer $\texttt{ID}$ not exceeding $10^6$. If two cows' lists share at least one common ice cream flavor, then they can get along.

Please compute the number of pairs of cows that cannot get along.

## 输入格式

The first line contains $N$. The next $N$ lines each contain $5$ integers (all distinct), representing one cow’s favorite ice cream flavors.

## 输出格式

Output the number of pairs of cows that cannot get along.

## 输入输出样例 #1

### 输入 #1

```
4
1 2 3 4 5
1 2 3 10 8
10 9 8 7 6
50 60 70 80 90
```

### 输出 #1

```
4
```

## 说明/提示

Here, cow $4$ cannot get along with any of cows $1$, $2$, or $3$, and cow $1$ and cow $3$ also cannot get along.

Translated by ChatGPT 5