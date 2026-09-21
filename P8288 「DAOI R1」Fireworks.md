# P8288 「DAOI R1」Fireworks

## 题目背景

> 俯首，满城灯火交辉。
> 
> 回眸，漫天流星逆飞。

## 题目描述

人们以前通常会放烟花，而每个烟花都有它本身的美观度。

$ \texttt{Iratis} $ 想要在户外放烟花，但是有烟花之间有一些关系：

- 关系一：对于烟花 $ x $ ，有一个对应烟花 $ a_x $ ，若烟花 $ x $ 与烟花 $ a_x $ 一起燃放，就会使烟花 $ x $ 的美观度减少 $ b_x $ 。

- 关系二：有一些烟花是一个系列，必须同时燃放，其中有一个是主烟花，**每个烟花只会属于一个系列**。

特别地，若有一系列 $ S_1 $ （主烟花为 $ p_1 $ ） 。 $ p_1 $ 关系一所对应的烟花为系列 $ S_2 $ 中的烟花。而 $ S_1 $ 系列中的其他烟花与非 $ S_1,S_2 $ 系列中的烟花形成关系一。**那么对于这条关系一，它不会降低美观度。**

$ \texttt{Iratis} $ 家里有 $ n $ 个烟花，他希望选择其中的一些烟花燃放，使得这些**烟花的美观度总和**最大。

## 输入格式

第一行包含两个整数 $ n,m $，分别描述烟花的个数和和关系二的个数。

接下来 $ n $ 行，每行三个整数 $ v_i,a_i,b_i $ ，分别是这个烟花的美观度、关系一对应的烟花、关系一降低的美观度。

最后 $ m $ 行，每行先读入两个数 $ p_i,k_i $，然后是 $ k_i $ 个数，表示这 $ k_i $ 个烟花是一个系列，编号为 $ p_i $ 的烟花为主烟花。

## 输出格式

输出一行一个整数，表示烟花的美观度总和。

## 输入输出样例 #1

### 输入 #1

```
3 0
2 2 1
2 3 1
2 1 1

```

### 输出 #1

```
3
```

## 输入输出样例 #2

### 输入 #2

```
4 1
3 2 1
3 1 3
3 4 2
3 3 2
1 2 1 3

```

### 输出 #2

```
7
```

## 说明/提示

### 样例解释
#### 样例1解释

烟花 $ 1,2,3 $ 一起燃放，最大美观度为 $ 2+2+2-1-1-1=3 $ 。

#### 样例2解释

烟花 $ 1,3,4 $ 一起燃放。

由于 $ 1,3 $ 为同一系列且 $ 1 $ 为主烟花，所以 $ 3 $ 烟花的关系一不会生效。

故总的美观度为 $ 3 \times 3-2=7 $ 。

### 数据规模

**本题采用捆绑测试**

| Subtask | $ m $  | 分值 |
| :----------: | :----------: | :----------: |
| $ 0 $ | $ =0 $ | $ 30 $ |
| $ 1 $ | 无特殊限制 | $ 70 $ |

对于 $ 100\% $ 的数据，满足 $ 0 \leq m \leq n \leq 5 \times 10^5,0 \leq b_i \leq v_i \leq 10^{12},1 \leq a_i \leq n,a_i \neq i $ 。

---

# P8288 「DAOI R1」Fireworks

## 题目背景

> Bow your head, and the whole city shines with lights.
>
> Look back, and meteors fly backward across the sky.

## 题目描述

People used to set off fireworks, and each firework has its own beauty value.

$\texttt{Iratis}$ wants to set off fireworks outdoors, but there are some relationships between fireworks:

- Relationship 1: For a firework $x$, there is a corresponding firework $a_x$. If firework $x$ and firework $a_x$ are set off together, the beauty value of firework $x$ will decrease by $b_x$.

- Relationship 2: Some fireworks belong to a series and must be set off at the same time. One of them is the main firework. **Each firework belongs to at most one series.**

In particular, suppose there is a series $S_1$ (with main firework $p_1$). The firework corresponding to $p_1$ in Relationship 1 is a firework in series $S_2$. Meanwhile, the other fireworks in series $S_1$ form Relationship 1 with fireworks not in series $S_1$ or $S_2$. **Then for such a Relationship 1, it will not reduce the beauty value.**

$\texttt{Iratis}$ has $n$ fireworks at home. He wants to choose some of them to set off, so that the **sum of the beauty values** of these fireworks is maximized.

## 输入格式

The first line contains two integers $n,m$, which denote the number of fireworks and the number of Relationship 2 groups.

The next $n$ lines each contain three integers $v_i,a_i,b_i$, which are the beauty value of this firework, the corresponding firework in Relationship 1, and the amount of beauty value reduced by Relationship 1.

The last $m$ lines: each line first reads two numbers $p_i,k_i$, followed by $k_i$ numbers, meaning these $k_i$ fireworks form a series, and the firework with index $p_i$ is the main firework.

## 输出格式

Output one line with one integer, representing the total sum of beauty values.

## 输入输出样例 #1

### 输入 #1

```
3 0
2 2 1
2 3 1
2 1 1

```

### 输出 #1

```
3
```

## 输入输出样例 #2

### 输入 #2

```
4 1
3 2 1
3 1 3
3 4 2
3 3 2
1 2 1 3

```

### 输出 #2

```
7
```

## 说明/提示

### Sample Explanation

#### Sample 1 Explanation

Set off fireworks $1,2,3$ together. The maximum beauty value is $2+2+2-1-1-1=3$.

#### Sample 2 Explanation

Set off fireworks $1,3,4$ together.

Since $1,3$ are in the same series and $1$ is the main firework, Relationship 1 of firework $3$ does not take effect.

So the total beauty value is $3 \times 3-2=7$.

### Constraints

**This problem uses bundled testdata.**

| Subtask | $m$ | Score |
| :----------: | :----------: | :----------: |
| $0$ | $=0$ | $30$ |
| $1$ | No special restrictions | $70$ |

For $100\%$ of the data, it holds that $0 \leq m \leq n \leq 5 \times 10^5$, $0 \leq b_i \leq v_i \leq 10^{12}$, $1 \leq a_i \leq n$, $a_i \neq i$.

Translated by ChatGPT 5