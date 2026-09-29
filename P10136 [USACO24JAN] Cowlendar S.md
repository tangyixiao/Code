# P10136 [USACO24JAN] Cowlendar S

## 题目描述

Bessie 在一个陌生的星球上醒来。这个星球上有 $N$（$1\le N\le 10^4$）个月，分别有 $a_1,\ldots,a_N$ 天（$1\le a_i\le 4\cdot 10^9$，所有 $a_i$ 均为整数）。此外，这个星球上还存在周，一周为 $L$ 天，其中 $L$ 是一个正整数。有趣的是，Bessie 知道以下事情：

- 对于正确的 $L$，每个月至少有 $4$ 周。
- 对于正确的 $L$，$a_i\bmod L$ 至多有 $3$ 个不同值。

不幸的是，Bessie 忘记了 $L$ 是多少！请通过输出 $L$ 的所有可能值之和来帮助她。

**注意这个问题涉及到的整数可能需要使用 64 位整数型（例如，C/C++ 中的 "long long"）。**

## 输入格式

输入的第一行包含一个整数 $N$。第二行包含 $N$ 个空格分隔的整数 $a_1,\ldots,a_N$。

## 输出格式

输出一个整数，为 $L$ 的所有可能值之和。

## 输入输出样例 #1

### 输入 #1

```
12
31 28 31 30 31 30 31 31 30 31 30 31
```

### 输出 #1

```
28
```

## 输入输出样例 #2

### 输入 #2

```
4
31 35 28 29
```

### 输出 #2

```
23
```

## 说明/提示

### 样例解释 1

$L$ 的可能值为 $1$，$2$，$3$，$4$，$5$，$6$ 和 $7$。例如，$L=7$ 是合法的，因为每个月的至少有 $4\cdot 7=28$ 天，且每个月的天数模 $7$ 的余数均为 $0$，$2$ 或 $3$。

### 样例解释 2

$L$ 的可能值为 $1$，$2$，$3$，$4$，$6$ 和 $7$。例如，$L=6$ 是合法的，因为每个月的至少有 $4\cdot 6=24$ 天，且每个月的天数模 $6$ 的余数均为 $1$，$4$ 或 $5$。

### 测试点性质

- 测试点 $3-4$：$1\le a_i\le 10^6$。
- 测试点 $5-14$：没有额外限制。

---

# P10136 [USACO24JAN] Cowlendar S

## 题目描述

Bessie has woken up on a strange planet.  In this planet, there are $N$ ($1\le N\le 10^4$) months, with $a_1, \ldots, a_N$ days, respectively ($1\leq a_i \leq 4 \cdot 10^9$, all $a_i$ are integers). In addition, on the planet, there are also weeks, where each week is $L$ days, with $L$ being a positive integer. Interestingly, Bessie knows the following: 
-  For the correct $L$, each month is at least $4$ weeks long. 
-  For the correct $L$,  there are at most $3$ distinct values of $a_i\bmod L$.  

Unfortunately, Bessie has forgotten what $L$ is! Help her by printing the sum of all possible values of $L$.  

**Note that the large size of integers involved in this problem may require the use of 64-bit integer data types (e.g. a "long long" in C/C++).**

## 输入格式

The first line contains a single integer $N$. The second line contains $N$ space-separated integers, $a_1, \ldots, a_N$.

## 输出格式

A single integer, the sum of all possible values of $L$.

## 输入输出样例 #1

### 输入 #1

```
12
31 28 31 30 31 30 31 31 30 31 30 31
```

### 输出 #1

```
28
```

## 输入输出样例 #2

### 输入 #2

```
4
31 35 28 29
```

### 输出 #2

```
23
```

## 说明/提示

##### For Sample 1:
The possible values of $L$ are 1, 2, 3, 4, 5, 6, and 7.  For example, $L=7$ is valid because each month is at least length $4 \cdot 7 = 28$ days long, and each month is either 0, 2, or 3 mod 7.   

##### For Sample 2:
The possible values of $L$ are 1, 2, 3, 4, 6, and 7. For example, $L=6$ is valid because each month is at least length $4 \cdot 6 = 24$ days long, and each month is either 1, 4, or 5 mod 6.   

#### SCORING:
- Inputs 3-4: $1 \leq a_i \leq 10^6$
- Inputs 5-14: No additional constraints