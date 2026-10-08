# P4980 【模板】Pólya 定理

## 题目描述

给定一个 $n$ 个点，$n$ 条边的环，有 $n$ 种颜色，给每个顶点染色，问有多少种**本质不同**的染色方案，答案对 $10^9+7$ 取模。

注意本题的本质不同，定义为：**只需要不能通过旋转与别的染色方案相同**。

## 输入格式

第一行输入一个 $t$，表示有 $t$ 组数据

第二行开始，一共 $t$ 行，每行一个整数 $n$，意思如题所示。

## 输出格式

共 $t$ 行，每行一个数字，表示染色方案数对 $10^9+7$ 取模后的结果

## 输入输出样例 #1

### 输入 #1

```
5
1 
2 
3 
4 
5 
```

### 输出 #1

```
1
3
11
70
629
```

## 说明/提示

- $n \leq 10^9$
- $t \leq 10^3$

---

# P4980 [Template] Pólya Theorem

## 题目描述

Given a cycle with $n$ vertices and $n$ edges, there are $n$ colors. Color each vertex, and ask how many **essentially different** coloring schemes there are. Output the answer modulo $10^9+7$.

Note that in this problem, “essentially different” is defined as: it **only needs to be different up to rotation**, i.e., two colorings are considered the same if one can be obtained from the other by rotation.

## 输入格式

The first line contains an integer $t$, meaning there are $t$ test cases.

Starting from the second line, there are $t$ lines in total. Each line contains an integer $n$, with the meaning as described above.

## 输出格式

There are $t$ lines in total. Each line contains one number, representing the number of coloring schemes modulo $10^9+7$.

## 输入输出样例 #1

### 输入 #1

```
5
1 
2 
3 
4 
5 
```

### 输出 #1

```
1
3
11
70
629
```

## 说明/提示

$$n \leq 10^9$$
$$t \leq 10^3$$

Translated by ChatGPT 5