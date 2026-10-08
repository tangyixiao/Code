# P6086 【模板】Prüfer（Prufer）序列

## 题目背景

Prüfer 序列又写作 Prufer 序列。

## 题目描述

请实现 Prüfer 序列和无根树的相互转化。

为方便你实现代码，尽管是无根树，我们在读入时仍将 $n$ 设为其根。

对于一棵无根树，设 $f_{1\dots n-1}$ 为其**父亲序列**（$f_i$ 表示 $i$ 在 $n$ 为根时的父亲），设 $p_{1 \dots n-2}$ 为其 **Prüfer 序列**。

另外，对于一个长度为 $m$ 的序列 $a_{1 \dots m}$，我们设其**权值**为 $\operatorname{xor}_{i = 1}^m i \times a_i$。

## 输入格式

第一行两个整数 $n,m$，表示树的点数和转化类型。

若 $m = 1$，第二行一行 $n-1$ 个整数，表示父亲序列。  
若 $m = 2$，第二行一行 $n-2$ 个整数，表示 Prüfer 序列。

## 输出格式

若 $m = 1$，一行一个整数，表示给出的父亲序列对应的 Prüfer 序列的权值。  
若 $m = 2$，一行一个整数，表示给出的 Prüfer 序列对应的父亲序列的权值。

## 输入输出样例 #1

### 输入 #1

```
6 1
3 6 4 6 1
```

### 输出 #1

```
29
```

## 输入输出样例 #2

### 输入 #2

```
6 2
4 6 5 2
```

### 输出 #2

```
4
```

## 说明/提示

**【样例 1 解释】**

$p = \{6\ 1\ 3\ 4\}$。

**【样例 2 解释】**

$f = \{4\ 6\ 6\ 5\ 2\}$。

---

**【数据范围】**

| 测试点编号 | $2 \le n \le $  | $m = $ |
| :--------: | :-------------: | :----: |
|    $1$     |     $10^3$      |  $1$   |
|    $2$     |     $10^5$      |  $1$   |
|    $3$     |     $10^5$      |  $1$   |
|    $4$     | $5 \times 10^6$ |  $1$   |
|    $5$     | $5 \times 10^6$ |  $1$   |
|    $6$     |     $10^3$      |  $2$   |
|    $7$     |     $10^5$      |  $2$   |
|    $8$     |     $10^5$      |  $2$   |
|    $9$     | $5 \times 10^6$ |  $2$   |
|    $10$    | $5 \times 10^6$ |  $2$   |

---

# P6086 [Template] Prüfer (Prufer) Sequence

## 题目背景

The Prüfer sequence is also written as the Prufer sequence.

## 题目描述

Please implement the conversion between a Prüfer sequence and an unrooted tree.

To make implementation easier, although the tree is unrooted, when reading the input we still treat $n$ as its root.

For an unrooted tree, let $f_{1 \dots n-1}$ be its **parent sequence** ($f_i$ denotes the parent of node $i$ when rooting the tree at $n$), and let $p_{1 \dots n-2}$ be its **Prüfer sequence**.

In addition, for a sequence $a_{1 \dots m}$ of length $m$, define its **value** as $\operatorname{xor}_{i = 1}^m i \times a_i$.

## 输入格式

The first line contains two integers $n, m$, representing the number of nodes in the tree and the conversion type.

If $m = 1$, the second line contains $n - 1$ integers, representing the parent sequence.  
If $m = 2$, the second line contains $n - 2$ integers, representing the Prüfer sequence.

## 输出格式

If $m = 1$, output one integer on a single line, representing the value of the Prüfer sequence corresponding to the given parent sequence.  
If $m = 2$, output one integer on a single line, representing the value of the parent sequence corresponding to the given Prüfer sequence.

## 输入输出样例 #1

### 输入 #1

```
6 1
3 6 4 6 1
```

### 输出 #1

```
29
```

## 输入输出样例 #2

### 输入 #2

```
6 2
4 6 5 2
```

### 输出 #2

```
4
```

## 说明/提示

**[Sample 1 Explanation]**

$p = \{6\ 1\ 3\ 4\}$.

**[Sample 2 Explanation]**

$f = \{4\ 6\ 6\ 5\ 2\}$.

---

**[Constraints]**

| Test Point ID | $2 \le n \le $  | $m = $ |
| :-----------: | :-------------: | :----: |
|     $1$       |     $10^3$      |  $1$   |
|     $2$       |     $10^5$      |  $1$   |
|     $3$       |     $10^5$      |  $1$   |
|     $4$       | $5 \times 10^6$ |  $1$   |
|     $5$       | $5 \times 10^6$ |  $1$   |
|     $6$       |     $10^3$      |  $2$   |
|     $7$       |     $10^5$      |  $2$   |
|     $8$       |     $10^5$      |  $2$   |
|     $9$       | $5 \times 10^6$ |  $2$   |
|     $10$      | $5 \times 10^6$ |  $2$   |

Translated by ChatGPT 5