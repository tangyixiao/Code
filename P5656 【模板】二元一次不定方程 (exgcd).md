# P5656 【模板】二元一次不定方程 (exgcd)

## 题目描述

给定不定方程

$$ax+by=c$$

---


- 若该方程无整数解，输出 $-1$。

- 若该方程有整数解，且有正整数解，则输出其**正整数**解的数量、所有**正整数**解中 $x$ 的最小值、所有**正整数**解中 $y$ 的最小值、所有**正整数**解中 $x$ 的最大值、以及所有**正整数**解中 $y$ 的最大值。

- 若方程有整数解，但没有正整数解，你需要输出所有**整数解**中 $x$ 的最小正整数值， $y$ 的最小正整数值。

>注：
>
>1. 正整数解即为 $x, y$ 均为正整数的解，$\boldsymbol{0}$ **不是正整数**。
> 
> 2. 整数解即为 $x,y$ 均为整数的解。
>
>3. $x$ 的最小正整数值即所有 $x$ 为正整数的整数解中 $x$ 的最小值，$y$ 同理。

## 输入格式

第一行一个正整数 $T$，代表数据组数。

接下来 $T$ 行，每行三个由空格隔开的正整数 $a, b, c$。

## 输出格式

应输出 $T$ 行。

若该行对应的询问无整数解，一个数字 $-1$。  

若该行对应的询问有整数解但无正整数解，包含 $2$ 个由空格隔开的数字，依次代表整数解中，$x$ 的最小正整数值，$y$ 的最小正整数值。  

否则包含 $5$ 个由空格隔开的数字，依次代表正整数解的数量，正整数解中，$x$ 的最小值，$y$ 的最小值，$x$ 的最大值，$y$ 的最大值。

**读入输出量较大，注意使用较快的读入输出方式**

## 输入输出样例 #1

### 输入 #1

```
7
2 11 100
3 18 6
192 608 17
19 2 60817
11 45 14
19 19 810
98 76 5432
```

### 输出 #1

```
4 6 2 39 8
2 1
-1
1600 1 18 3199 30399
34 3
-1
2 12 7 50 56
```

## 说明/提示

**【数据范围】**

对于 $100\%$ 的数据，$1 \le T \le 2 \times {10}^5$，$1 \le a, b, c \le {10}^9$。

---

# P5656 [Template] Binary Linear Diophantine Equation (exgcd)

## 题目描述

Given the indeterminate equation

$$ax+by=c$$

If this equation has no integer solution, output $-1$.  
If this equation has integer solutions and also has positive integer solutions, output: the number of **positive integer** solutions, the minimum value of $x$ among all **positive integer** solutions, the minimum value of $y$ among all **positive integer** solutions, the maximum value of $x$ among all **positive integer** solutions, and the maximum value of $y$ among all **positive integer** solutions.  
If the equation has integer solutions but has no positive integer solution, you need to output: the minimum positive integer value of $x$ among all **integer solutions**, and the minimum positive integer value of $y$ among all **integer solutions**.

A positive integer solution means a solution where both $x$ and $y$ are positive integers, and $\boldsymbol{0}$ **is not a positive integer**.  
An integer solution means a solution where both $x$ and $y$ are integers.  
The minimum positive integer value of $x$ means the minimum value of $x$ among all integer solutions with $x$ being a positive integer, and similarly for $y$.

## 输入格式

The first line contains a positive integer $T$, representing the number of test cases.

The next $T$ lines each contain three positive integers $a, b, c$ separated by spaces.

## 输出格式

Output $T$ lines.

If the corresponding query has no integer solution, output a single number $-1$.  
If the corresponding query has integer solutions but no positive integer solution, output $2$ numbers separated by spaces, representing the minimum positive integer value of $x$ and the minimum positive integer value of $y$ among integer solutions, in order.  
Otherwise, output $5$ numbers separated by spaces, representing the number of positive integer solutions, the minimum $x$, the minimum $y$, the maximum $x$, and the maximum $y$ among positive integer solutions, in order.

The input and output sizes are large, so please use fast I/O methods.

## 输入输出样例 #1

### 输入 #1

```
7
2 11 100
3 18 6
192 608 17
19 2 60817
11 45 14
19 19 810
98 76 5432
```

### 输出 #1

```
4 6 2 39 8
2 1
-1
1600 1 18 3199 30399
34 3
-1
2 12 7 50 56
```

## 说明/提示

**Constraints**

For $100\%$ of the testdata, $1 \le T \le 2 \times {10}^5$, $1 \le a, b, c \le {10}^9$.

Translated by ChatGPT 5