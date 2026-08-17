# P9446 [ICPC 2021 WF] Prehistoric Programs

## 题目描述

考古学家在 Alutila 洞穴的深层发现了令人兴奋的粘土板。除了两个似乎描述嵌套结构的符号（类似于 LISP 中的开括号和闭括号）外，没有人能够破译粘土板上的文字。难道几千年前人类就已经在编写程序了吗？

综合来看，这些粘土板似乎描述了一项伟大的作品——可能是一个程序，或者是一部史诗，甚至是税务记录！不出所料，经过这么长时间，粘土板已经处于无序状态。你的任务是将它们排列成一个序列，使得结果作品具有正确嵌套的括号结构。仅考虑开括号和闭括号，一个正确嵌套的结构要么是

- $()$，或者
- $(A)$，其中 $A$ 是一个正确嵌套的结构，或者
- $AB$，其中 $A$ 和 $B$ 是正确嵌套的结构。

## 输入格式

输入的第一行包含一个整数 $n$ ($1 \leq n \leq 10^6$)，表示粘土板的数量。接下来的 $n$ 行中的每一行描述一个粘土板，并包含一个非空的开括号和闭括号字符串；与嵌套结构无关的符号被省略。字符串按照它们在输入中出现的顺序从 $1$ 到 $n$ 编号。输入中最多包含 $10^7$ 个括号。

## 输出格式

输出一个从 $1$ 到 $n$ 的数字排列，使得按此顺序连接字符串后形成一个正确嵌套的结构。如果存在多个排列满足条件，任何一个都可以接受。如果没有这样的排列，输出 $\texttt{impossible}$。

## 输入输出样例 #1

### 输入 #1

```
2
())())()
((()

```

### 输出 #1

```
2
1
```

## 输入输出样例 #2

### 输入 #2

```
5
(
))
((
))
(

```

### 输出 #2

```
1
5
3
4
2

```

## 输入输出样例 #3

### 输入 #3

```
2
((
)

```

### 输出 #3

```
impossible

```

## 说明/提示

题面翻译由 ChatGPT-4o 提供。

---

# P9446 [ICPC 2021 WF] Prehistoric Programs

## 题目描述

Archaeologists have discovered exciting clay tablets in deep layers of Alutila Cave. Nobody was able to decipher the script on the tablets, except for two symbols that seem to describe nested structures not unlike opening and closing parentheses in LISP. Could it be that humans wrote programs thousands of years ago?

Taken together, the tablets appear to describe a great piece of work $-$ perhaps a program, or an epic, or even tax records! Unsurprisingly, after such a long time, the tablets are in a state of disorder. Your job is to arrange them into a sequence so that the resulting work has a properly nested parenthesis structure. Considering only opening and closing parentheses, a properly nested structure is either

- $()$, or
- $(A)$, where $A$ is a properly nested structure, or
- $AB$, where $A$ and $B$ are properly nested structures.

## 输入格式

The first line of input contains one integer $n$ ($1 \leq n \leq 10^6$), the number of tablets. Each of the remaining $n$ lines describes a tablet, and contains a non-empty string of opening and closing parentheses; symbols unrelated to the nesting structure are omitted. The strings are numbered from $1$ to $n$ in the order that they appear in the input. The input contains at most $10^7$ parentheses.

## 输出格式

Output a permutation of the numbers from $1$ to $n$ such that concatenating the strings in this order results in a properly nested structure. If this happens for multiple permutations, any one of them will be accepted. If there is no such permutation, output $\texttt{impossible}$ instead.

## 输入输出样例 #1

### 输入 #1

```
2
())())()
((()

```

### 输出 #1

```
2
1
```

## 输入输出样例 #2

### 输入 #2

```
5
(
))
((
))
(

```

### 输出 #2

```
1
5
3
4
2

```

## 输入输出样例 #3

### 输入 #3

```
2
((
)

```

### 输出 #3

```
impossible

```