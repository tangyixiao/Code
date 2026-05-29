# P3455 [POI 2007] ZAP-Queries

## 题目描述

密码学家正在尝试破解一种叫 BSA 的密码。

他发现，在破解一条消息的同时，他还需要回答这样一种问题：

给出 $a,b,d$，求满足 $1 \leq x \leq a$，$1 \leq y \leq b$，且 $\gcd(x,y)=d$ 的二元组 $(x,y)$ 的数量。

因为要解决的问题实在太多了，他便过来寻求你的帮助。

## 输入格式

输入第一行一个整数 $n$，代表要回答的问题个数。

接下来 $n$ 行，每行三个整数 $a,b,d$。

## 输出格式

对于每组询问，输出一个整数代表答案。

## 输入输出样例 #1

### 输入 #1

```
2
4 5 2
6 4 3
```

### 输出 #1

```
3
2
```

## 说明/提示

#### 数据规模与约定

对于全部的测试点，保证 $1 \leq n \leq 5 \times 10^4$，$1 \leq d \leq a,b \leq 5 \times 10^4$。


---

# P3455 [POI 2007] ZAP-Queries

## 题目描述

A cryptographer is trying to break a cipher called BSA.

He found that while breaking a message, he also needs to answer the following question:

Given $a,b,d$, count the number of pairs $(x,y)$ such that $1 \leq x \leq a$, $1 \leq y \leq b$, and $\gcd(x,y)=d$.

Because there are so many problems to solve, he asks for your help.

## 输入格式

The first line contains an integer $n$, the number of queries.

Each of the next $n$ lines contains three integers $a,b,d$.

## 输出格式

For each query, output a single integer representing the answer.

## 输入输出样例 #1

### 输入 #1

```
2
4 5 2
6 4 3
```

### 输出 #1

```
3
2
```

## 说明/提示

Constraints

For all testdata, it is guaranteed that $1 \leq n \leq 5 \times 10^4$, $1 \leq d \leq a,b \leq 5 \times 10^4$.

Translated by ChatGPT 5