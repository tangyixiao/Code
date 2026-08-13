# P6503 [COCI 2010/2011 #3] DIFERENCIJA

## 题目描述

给出一个长度为 $n$ 的序列 $a_i$，求出下列式子的值：

$$\sum_{i=1}^{n} \sum_{j=i}^{n} (\max_{i\le k\le j} a_k-\min_{i\le k\le j} a_k)$$



即定义一个子序列的权值为序列内最大值与最小值的差。求出所有连续子序列的权值和。

## 输入格式

输入第一行一个整数 $n$，表示序列的长度。

接下来的 $n$ 行，每行一个整数 $a_i$，描述这个序列。

## 输出格式

输出一行一个整数，表示式子的答案。

## 输入输出样例 #1

### 输入 #1

```
3
1
2
3
```

### 输出 #1

```
4
```

## 输入输出样例 #2

### 输入 #2

```
4
7
5
7
5
```

### 输出 #2

```
12
```

## 输入输出样例 #3

### 输入 #3

```
4
3
1
7
2
```

### 输出 #3

```
31
```

## 说明/提示

#### 数据规模与约定

对于 $100\%$ 的数据，保证 $2\le n\le 3\times 10^5$，$1\le a_i\le 10^8$。

#### 说明

**题目译自 [COCI2010-2011](https://hsin.hr/coci/archive/2010_2011/) [CONTEST #3](https://hsin.hr/coci/archive/2010_2011/contest3_tasks.pdf) *T5 DIFERENCIJA***。

---

# P6503 [COCI 2010/2011 #3] DIFERENCIJA

## 题目描述

Given a sequence $a_i$ of length $n$, find the value of the following expression:

$$\sum_{i=1}^{n} \sum_{j=i}^{n} (\max_{i\le k\le j} a_k-\min_{i\le k\le j} a_k)$$

That is, define the weight of a subarray as the difference between the maximum and the minimum value within it. Find the sum of the weights of all contiguous subarrays.

## 输入格式

The first line contains an integer $n$, the length of the sequence.

The next $n$ lines each contain an integer $a_i$, describing the sequence.

## 输出格式

Output one integer in one line, representing the answer to the expression.

## 输入输出样例 #1

### 输入 #1

```
3
1
2
3
```

### 输出 #1

```
4
```

## 输入输出样例 #2

### 输入 #2

```
4
7
5
7
5
```

### 输出 #2

```
12
```

## 输入输出样例 #3

### 输入 #3

```
4
3
1
7
2
```

### 输出 #3

```
31
```

## 说明/提示

#### Constraints

For $100\%$ of the testdata, it is guaranteed that $2\le n\le 3\times 10^5$ and $1\le a_i\le 10^8$.

#### Notes

**Translated from [COCI2010-2011](https://hsin.hr/coci/archive/2010_2011/) [CONTEST #3](https://hsin.hr/coci/archive/2010_2011/contest3_tasks.pdf) *T5 DIFERENCIJA***。

Translated by ChatGPT 5