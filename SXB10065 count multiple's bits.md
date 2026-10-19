# SXB10065 count multiple's bits

## 题目描述

# Description

假设popcount(x)表示数x二进制上1的个数。请输出$\displaystyle\sum_{k|i}^{i<2^b}popcount(i)$

#### （其中k|i表示k是i的因子）

## Input

两个正整数k,b$（1\leq k\leq 1000,1\leq b\leq128）$

## Output

输出$\displaystyle\sum_{k|i}^{i<2^b}popcount(i)$

结果对1e9+9取模

# Samples

```input1
1 4
```

```output1
32
```

```input2
3 28
```

```output2
252698795
```

## 输入格式



## 输出格式



## 输入输出样例 #1

### 输入 #1

```
1 4
```

### 输出 #1

```
32
```

## 输入输出样例 #2

### 输入 #2

```
3 28
```

### 输出 #2

```
252698795
```
