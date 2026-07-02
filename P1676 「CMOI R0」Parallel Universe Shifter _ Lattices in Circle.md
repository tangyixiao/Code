# P1676 「CMOI R0」Parallel Universe Shifter / Lattices in Circle

## 题目背景

原《[USACO05FEB] Aggressive Cows G》参见 [P1824](https://www.luogu.com.cn/problem/P1824)。

$$\text{Answer}=\pi n^2+\mathrm O(n^{\frac{517}{824}}).$$

![](bilibili:BV1RM4m1U7oU)

$\small\color{white}/35^{\text{th}}\text{Problem by AtC}.$

## 题目描述

求与原点距离不超过 $n(1\leq n\leq 10^{12})$ 的整点个数。

## 输入格式

一行一个正整数 $n$。

## 输出格式

一行一个正整数，即答案。注意它可能大于 $2^{64}$。

## 输入输出样例 #1

### 输入 #1

```
1
```

### 输出 #1

```
5
```

## 输入输出样例 #2

### 输入 #2

```
2
```

### 输出 #2

```
13
```

## 输入输出样例 #3

### 输入 #3

```
5
```

### 输出 #3

```
81
```

## 输入输出样例 #4

### 输入 #4

```
19
```

### 输出 #4

```
1129
```

## 输入输出样例 #5

### 输入 #5

```
100
```

### 输出 #5

```
31417
```

## 输入输出样例 #6

### 输入 #6

```
30000
```

### 输出 #6

```
2827432965
```

## 输入输出样例 #7

### 输入 #7

```
10000000
```

### 输出 #7

```
314159265350589
```

## 输入输出样例 #8

### 输入 #8

```
500000000
```

### 输出 #8

```
785398163397389961
```

## 输入输出样例 #9

### 输入 #9

```
16000000000
```

### 输出 #9

```
804247719318986163169
```

## 输入输出样例 #10

### 输入 #10

```
700000000000
```

### 输出 #10

```
1539380400258998682200449
```

## 说明/提示

### 样例 $1$ 解释

符合条件的 $5$ 个点是 $(0,0),(1,0),(0,1),(0,-1),(-1,0)$。

### 数据范围

|$\text{Subtask}$|$\text{Special Constraints}$|$\text{Time Limit}$|$\text{Points}$|
| :----------: | :----------: | :----------: | :----------: |
|$1$|$1\leq n\leq 2\times 10^3$|$0.25\text s$|$1$|
|$2$|$10^4\leq n\leq 10^7$|$1\text s$|$4$|
|$3$|$10^8\leq n\leq 10^9$|$1\text s$|$10$|
|$4$|$10^9\leq n\leq 10^{10}$|$3\text s$|$15$|
|$5$|$10^{10}\leq n\leq 10^{11}$|$4\text s$|$30$|
|$6$|$10^{11}\leq n\leq 10^{12}$|$4\text s$|$40$|


---

# P1676 "CMOI R0" Parallel Universe Shifter / Lattices in Circle

## 题目背景

The original "[USACO05FEB] Aggressive Cows G" can be found at [P1824](https://www.luogu.com.cn/problem/P1824).

$$\text{Answer}=\pi n^2+\mathrm O(n^{\frac{517}{824}}).$$

![](bilibili:BV1RM4m1U7oU)

$\small\color{white}/35^{\text{th}}\text{Problem by AtC}.$

## 题目描述

Find the number of integer lattice points whose distance to the origin is at most $n$ $(1\leq n\leq 10^{12})$.

## 输入格式

One line with one positive integer $n$.

## 输出格式

One line with one positive integer, the answer. Note that it may be greater than $2^{64}$.

## 输入输出样例 #1

### 输入 #1

```
1
```

### 输出 #1

```
5
```

## 输入输出样例 #2

### 输入 #2

```
2
```

### 输出 #2

```
13
```

## 输入输出样例 #3

### 输入 #3

```
5
```

### 输出 #3

```
81
```

## 输入输出样例 #4

### 输入 #4

```
19
```

### 输出 #4

```
1129
```

## 输入输出样例 #5

### 输入 #5

```
100
```

### 输出 #5

```
31417
```

## 输入输出样例 #6

### 输入 #6

```
30000
```

### 输出 #6

```
2827432965
```

## 输入输出样例 #7

### 输入 #7

```
10000000
```

### 输出 #7

```
314159265350589
```

## 输入输出样例 #8

### 输入 #8

```
500000000
```

### 输出 #8

```
785398163397389961
```

## 输入输出样例 #9

### 输入 #9

```
16000000000
```

### 输出 #9

```
804247719318986163169
```

## 输入输出样例 #10

### 输入 #10

```
700000000000
```

### 输出 #10

```
1539380400258998682200449
```

## 说明/提示

### Explanation for Sample $1$

The $5$ points that satisfy the condition are $(0,0),(1,0),(0,1),(0,-1),(-1,0)$.

### Constraints

|$\text{Subtask}$|$\text{Special Constraints}$|$\text{Time Limit}$|$\text{Points}$|
| :----------: | :----------: | :----------: | :----------: |
|$1$|$1\leq n\leq 2\times 10^3$|$0.25\text s$|$1$|
|$2$|$10^4\leq n\leq 10^7$|$1\text s$|$4$|
|$3$|$10^8\leq n\leq 10^9$|$1\text s$|$10$|
|$4$|$10^9\leq n\leq 10^{10}$|$3\text s$|$15$|
|$5$|$10^{10}\leq n\leq 10^{11}$|$4\text s$|$30$|
|$6$|$10^{11}\leq n\leq 10^{12}$|$4\text s$|$40$|

Translated by ChatGPT 5