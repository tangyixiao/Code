# P3719 [AHOI2017初中组] rexp

## 题目背景

为了解决形形色色的字符串匹配问题，正则表达式是一个强有力的工具。正则表达式通过定义一套符号体系，能够表示出需要查找的字符串所具有的性质。如 `a|aa` 能匹配 `a` 或 `aa`，`(a|b)c` 能匹配 `ac` 或 `bc`。

## 题目描述

完整的正则表达式过于复杂，在这里我们只考虑由 `(`、`)`、`|` 和 `a` 组成的正则表达式。运算遵循下列法则：

1. 有括号时，我们总是先算括号内的部分；

2. 当两个字符串（或由括号定义的子串）间没有符号时，我们总把它们连起来作为一个整体；

3. `|` 是或连接符，表示两边的字符串任取其一，若同一层里有多个或连接符，可以看作在这些或连接符所分开的若干字符串里任取其一。

例如，`(aaa)aa|aa|(a(aa)a)`、`(aaaaa)|(aa)|aaaa` 和 `aaaaa|aaaa|aa` 是等价的，它们都能匹配长度为 $2,4$ 或 $5$ 的全 `a` 字符串。

下面给定一个简化正则表达式，试编程计算它最多能匹配多长的全 `a` 字符串。

## 输入格式

输入一行一个合法的简化正则表达式。

## 输出格式

一行一个整数，表示能匹配的最长全 `a` 字符串长度。

## 输入输出样例 #1

### 输入 #1

```
(aaa)aa|aa|(a(aa)a)
```

### 输出 #1

```
5

```

## 输入输出样例 #2

### 输入 #2

```
((a|aaa)|aa)|a
```

### 输出 #2

```
3
```

## 输入输出样例 #3

### 输入 #3

```
(a(aa|aaa)a|(a|aa))aa
```

### 输出 #3

```
7
```

## 说明/提示

**【数据范围】**

对于 $20\%$ 数据，表达式长度不超过 $100$，且不存在括号。

对于 $40\%$ 数据，表达式长度不超过 $100$。

对于 $70\%$ 数据，表达式长度不超过 $2 \times 10^3$。

对于 $100\%$ 的数据，表达式长度不超过 $10^5$。

保证表达式合法（即 `|` 两端和括号内运算结果均非空字符串）。

---

# P3719 [AHOI2017 Middle School Division] rexp

## 题目背景

To solve various string matching problems, regular expressions are a powerful tool. By defining a system of symbols, regular expressions can describe the properties of the strings to be found. For example, `a|aa` can match `a` or `aa`, and `(a|b)c` can match `ac` or `bc`.

## 题目描述

Full regular expressions are too complex. Here, we only consider regular expressions composed of `(`, `)`, `|`, and `a`. The operations follow the rules below:

1. When there are parentheses, we always evaluate the part inside the parentheses first.
2. When two strings (or substrings defined by parentheses) have no symbol between them, we concatenate them as a whole.
3. `|` is the OR operator, meaning you can choose either string on its two sides. If there are multiple OR operators at the same level, it can be viewed as choosing any one of the strings separated by these OR operators.

For example, `(aaa)aa|aa|(a(aa)a)`, `(aaaaa)|(aa)|aaaa`, and `aaaaa|aaaa|aa` are equivalent. They all match all-`a` strings of length $2,4$ or $5$.

Given a simplified regular expression, write a program to compute the maximum length of an all-`a` string it can match.

## 输入格式

One line containing a valid simplified regular expression.

## 输出格式

One line containing an integer, which is the maximum length of an all-`a` string that can be matched.

## 输入输出样例 #1

### 输入 #1

```
(aaa)aa|aa|(a(aa)a)
```

### 输出 #1

```
5

```

## 输入输出样例 #2

### 输入 #2

```
((a|aaa)|aa)|a
```

### 输出 #2

```
3
```

## 输入输出样例 #3

### 输入 #3

```
(a(aa|aaa)a|(a|aa))aa
```

### 输出 #3

```
7
```

## 说明/提示

[Constraints]

For $20\%$ of the testdata, the expression length does not exceed $100$, and there are no parentheses.

For $40\%$ of the testdata, the expression length does not exceed $100$.

For $70\%$ of the testdata, the expression length does not exceed $2 \times 10^3$.

For $100\%$ of the testdata, the expression length does not exceed $10^5$.

The expression is guaranteed to be valid (i.e., the results on both sides of `|` and inside parentheses are non-empty strings).

Translated by ChatGPT 5