# AT_abc403_f [ABC403F] Shortest One Formula

## 题目描述

[problemUrl]: https://atcoder.jp/contests/abc403/tasks/abc403_f

给定一个正整数 $N$。

请找出由字符 `1`、`+`、`*`、`(`、`)` 组成的数学表达式中，满足以下所有条件的最短表达式 $S$：
1. $S$ 符合以下 [BNF 语法](https://ja.wikipedia.org/wiki/%E3%83%90%E3%83%83%E3%82%AB%E3%82%B9%E3%83%BB%E3%83%8A%E3%82%A6%E3%82%A2%E8%A8%98%E6%B3%95) 中 `<expr>` 符号的定义
2. $S$ 表示的数学表达式计算结果等于 $N$

BNF 语法定义如下：

```
<expr>   ::= <term> | <expr> "+" <term>
<term>   ::= <factor> | <term> "*" <factor>
<factor> ::= <number> | "(" <expr> ")"
<number> ::= "1" | "1" <number> 
```

符合 `<expr>` 定义的表达式示例：
- `1111+111`：表示 $1111+111$
- `(1+1)*(1+1)`：表示 $(1+1)\times (1+1)$
- `(11+(1+1)*(1+1))+1`：表示 $(11+(1+1)\times (1+1))+1$

不符合 `<expr>` 定义的表达式示例：
- `(1+1)(1+1)`
- `1+2`
- `1-1`
- `1/1`
- `)1(`
- `1++1`
- `+1`
- `(+1)`
- `1*+1`

## 输入格式

输入通过标准输入给出，格式如下：

> $N$

## 输出格式

输出满足条件的最短表达式。

## 输入输出样例 #1

### 输入 #1

```
9
```

### 输出 #1

```
(1+1+1)*(1+1+1)
```

## 输入输出样例 #2

### 输入 #2

```
11
```

### 输出 #2

```
11
```

## 输入输出样例 #3

### 输入 #3

```
403
```

### 输出 #3

```
1+(1+1+1)*(1+11+11+111)
```

## 说明/提示

### 约束条件

- $1 \leq N \leq 2000$
- 输入均为整数

### 样例解释 #1

值为 $9$ 的表达式可能有多种形式，例如：
- `(1+1+1)*(1+1+1)`
- `1+1+1+1+1+1+1+1+1`
- `(1+1)*(1+1)*(1+1)+1`

其中 `(1+1+1)*(1+1+1)` 是最短的表达式。

翻译由 DeepSeek V3 完成

---


# AT_abc403_f [ABC403F] Shortest One Formula

## 题目描述

You are given a positive integer  $ N $ .

Among all valid arithmetic expressions consisting of the characters `1`, `+`, `*`, `(`, and `)`, find one of the minimum length whose value is  $ N $ .

More formally, among the strings  $ S $  satisfying all of the following conditions, find one of the minimum length:

- $ S $  conforms to the symbol `<expr>` in the [BNF](https://en.wikipedia.org/wiki/Backus%E2%80%93Naur_form) below.
- The value of the expression represented by  $ S $  is  $ N $ .
 
 ```
<expr>   ::= <term> | <expr> "+" <term>
<term>   ::= <factor> | <term> "*" <factor>
<factor> ::= <number> | "(" <expr> ")"
<number> ::= "1" | "1" <number>
```

Strings that conform to `<expr>` include:

- `1111+111` representing  $ 1111+111 $ .
- `(1+1)*(1+1)` representing  $ (1+1)\times(1+1) $ .
- `(11+(1+1)*(1+1))+1` representing  $ (11+(1+1)\times(1+1))+1 $ .
 
Strings that do not conform to `<expr>` include:

- `(1+1)(1+1)`
- `1+2`
- `1-1`
- `1/1`
- `)1(`
- `1++1`
- `+1`
- `(+1)`
- `1*+1`

## 输入格式

The input is given from Standard Input in the following format:

> $ N $

## 输出格式

Print a solution.

## 输入输出样例 #1

### 输入 #1

```
9
```

### 输出 #1

```
(1+1+1)*(1+1+1)
```

## 输入输出样例 #2

### 输入 #2

```
11
```

### 输出 #2

```
11
```

## 输入输出样例 #3

### 输入 #3

```
403
```

### 输出 #3

```
1+(1+1+1)*(1+11+11+111)
```

## 说明/提示

### Sample Explanation 1

Expressions whose value is  $ 9 $  include:

- `(1+1+1)*(1+1+1)`
- `1+1+1+1+1+1+1+1+1`
- `(1+1)*(1+1)*(1+1)+1`
 
Among them, a shortest is `(1+1+1)*(1+1+1)`.

### Constraints

- $ 1 \le N \le 2000 $
- All input values are integers.