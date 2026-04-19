# P2341 [USACO03FALL / HAOI2006] 受欢迎的牛 G

## 题目背景

本题测试数据已修复。

## 题目描述

每头奶牛都梦想成为牛棚里的明星。被所有奶牛喜欢的奶牛就是一头明星奶牛。所有奶牛都是自恋狂，每头奶牛总是喜欢自己的。奶牛之间的“喜欢”是可以传递的——如果 $A$ 喜欢 $B$，$B$ 喜欢 $C$，那么 $A$ 也喜欢 $C$。牛栏里共有 $N$ 头奶牛，给定一些奶牛之间的爱慕关系，请你算出有多少头奶牛可以当明星。

## 输入格式

第一行：两个用空格分开的整数：$N$ 和 $M$。

接下来 $M$ 行：每行两个用空格分开的整数：$A$ 和 $B$，表示 $A$ 喜欢 $B$。

## 输出格式

一行单独一个整数，表示明星奶牛的数量。

## 输入输出样例 #1

### 输入 #1

```
3 3
1 2
2 1
2 3
```

### 输出 #1

```
1
```

## 说明/提示

只有 $3$ 号奶牛可以做明星。

**【数据范围】**

对于 $10\%$ 的数据，$N\le20$，$M\le50$。

对于 $30\%$ 的数据，$N\le10^3$，$M\le2\times 10^4$。

对于 $70\%$ 的数据，$N\le5\times 10^3$，$M\le5\times 10^4$。

对于 $100\%$ 的数据，$1\le N\le10^4$，$1\le M\le5\times 10^4$。

---


# P2341 [USACO03FALL / HAOI2006] Popular Cows G

## 题目背景

The testdata for this problem has been fixed.

## 题目描述

Every cow dreams of becoming the star of the barn. A cow that is liked by all cows is a star cow. All cows are self-obsessed; each cow always likes itself. The “likes” relation is transitive—if $A$ likes $B$, and $B$ likes $C$, then $A$ also likes $C$. There are $N$ cows in the barn. Given some admiration relationships between cows, please compute how many cows can be stars.

## 输入格式

The first line contains two space-separated integers: $N$ and $M$.
The next $M$ lines: each line contains two space-separated integers: $A$ and $B$, meaning $A$ likes $B$.

## 输出格式

Output a single integer on one line, the number of star cows.

## 输入输出样例 #1

### 输入 #1

```
3 3
1 2
2 1
2 3
```

### 输出 #1

```
1
```

## 说明/提示

Only cow number $3$ can be a star.

Constraints
- For $10\%$ of the testdata, $N \le 20$, $M \le 50$.
- For $30\%$ of the testdata, $N \le 10^3$, $M \le 2 \times 10^4$.
- For $70\%$ of the testdata, $N \le 5 \times 10^3$, $M \le 5 \times 10^4$.
- For $100\%$ of the testdata, $1 \le N \le 10^4$, $1 \le M \le 5 \times 10^4$.

Translated by ChatGPT 5