# P4863 JerryC Loves Driving

## 题目背景

JerryC 最近迷上了狂野飙车！！！

## 题目描述

众所周知，JerryC 是一位疯狂的 Female。他最近买了一台跑车（~~但是却没有驾驶证~~），所以他就只能到一个偏僻的地方练习开车。

当然，JerryC 是不可能正常开车的。她首先决定要开 $(B-A+1)$ 段路程的车，第 $i$ 段路程的速度都是从 $1$ 开始加速的。每一秒会加上 $1$ 的单位速度。当速度加到 $(i+A-1)$ 的时候，JerryC 就会把速度降为 $1$，然后开始下一段路程。

对于第 $i$ 段路程的第 $j$ 秒，JerryC 获得的愉悦值为$\left\lfloor \frac{i+A-1}{j} \right\rfloor \times (-1)^j$。（反正 JerryC 就是不喜欢奇数。）

现在请你求出 JerryC 最后的总愉悦值。

P.s. ：

如果上面的东西没有看懂，那么简单版就是这个意思：

给出 $A, B$，求出下面式子的值。

$$\sum_{i=A}^B \sum_{j=1}^{i}\left\lfloor \frac{i}{j} \right\rfloor \times (-1)^j$$

## 输入格式

一行，两个正整数 $A, B$。

## 输出格式

一行，一个整数表示最终的愉悦值。

## 输入输出样例 #1

### 输入 #1

```
1 1
```

### 输出 #1

```
-1
```

## 输入输出样例 #2

### 输入 #2

```
2 2
```

### 输出 #2

```
-1
```

## 输入输出样例 #3

### 输入 #3

```
3 3
```

### 输出 #3

```
-3
```

## 说明/提示

对于 $50\%$ 的数据，$1 \leqslant A \leqslant B \leqslant 5\times10^3$；  
对于 $70\%$ 的数据，$1 \leqslant A \leqslant B \leqslant 5\times10^4$；  
对于 $100\%$ 的数据，$1 \leqslant A \leqslant B \leqslant 2\times10^7$。

---

# P4863 JerryC Loves Driving

## 题目背景

JerryC has recently become obsessed with Asphalt Racing.

## 题目描述

As everyone knows, JerryC is a crazy Female. He recently bought a sports car (~~but he does not have a driver’s license~~), so he can only practice driving in a remote place.

Of course, JerryC is not going to drive normally. She first decides to drive $(B-A+1)$ segments of road. In the $i$-th segment, the speed starts accelerating from $1$. Each second, it increases by $1$ unit of speed. When the speed reaches $(i+A-1)$, JerryC will reduce the speed back to $1$, and then start the next segment.

For the $j$-th second of the $i$-th segment, the pleasure value JerryC gets is $\left\lfloor \frac{i+A-1}{j} \right\rfloor \times (-1)^j$. (Anyway, JerryC just does not like odd numbers.)

Now please compute JerryC’s final total pleasure value.

P.s.:

If you did not understand the above, then the simplified version is:

Given $A, B$, compute the value of the following expression.

$$\sum_{i=A}^B \sum_{j=1}^{i}\left\lfloor \frac{i}{j} \right\rfloor \times (-1)^j$$

## 输入格式

One line with two positive integers $A, B$.

## 输出格式

One line with one integer, representing the final pleasure value.

## 输入输出样例 #1

### 输入 #1

```
1 1
```

### 输出 #1

```
-1
```

## 输入输出样例 #2

### 输入 #2

```
2 2
```

### 输出 #2

```
-1
```

## 输入输出样例 #3

### 输入 #3

```
3 3
```

### 输出 #3

```
-3
```

## 说明/提示

For $50\%$ of the testdata, $1 \leqslant A \leqslant B \leqslant 5\times10^3$.  
For $70\%$ of the testdata, $1 \leqslant A \leqslant B \leqslant 5\times10^4$.  
For $100\%$ of the testdata, $1 \leqslant A \leqslant B \leqslant 2\times10^7$.

Translated by ChatGPT 5