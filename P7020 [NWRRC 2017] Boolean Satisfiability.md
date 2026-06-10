# P7020 [NWRRC 2017] Boolean Satisfiability

## 题目描述

布尔可满足性问题（SAT）在计算机科学中被认为是一个非常困难的问题。在这个问题中，给定一个布尔公式，你需要判断该公式的变量是否可以被一致地替换为真或假，使得公式的结果为真。SAT 是已知的 NP 完全问题。此外，即使在 $3-CNF$ 公式（$3-SAT$）的情况下，它也是 NP 完全的。然而，例如，对于 $2-CNF$ 公式（$2-SAT$）的 SAT 问题是在 $P$ 中的。

$#SAT$ 是 SAT 问题的扩展。在这个问题中，你需要检查是否可能，并计算赋值给变量的方式的数量。这个问题即使对于 $2-CNF$ 公式也是已知的 $#P$ 完全问题。我们要求你解决 $#1-DNF-SAT$，这是 $1-DNF$ 公式的 $#SAT$ 问题。

你被给定一个 $1-DNF$ 形式的布尔公式。这意味着它是一个或多个子句的析取（逻辑或），每个子句正好是一个文字，每个文字要么是变量，要么是它的否定（逻辑非）。

形式化地：

$\langle \text{formula} \rangle ::= \langle \text{clause} \rangle \ | \ \langle \text{formula} \rangle \lor \langle \text{clause} \rangle$

$\langle \text{clause} \rangle ::= \langle \text{literal} \rangle$

$\langle \text{literal} \rangle ::= \langle \text{variable} \rangle \ | \ 
eg \langle \text{variable} \rangle$

$\langle \text{variable} \rangle ::= A \ldots Z \ | \ a \ldots z$

你的任务是找到将所有变量替换为真和假（同一变量的所有出现应替换为相同的值）的方法的数量，使得公式的结果为真。

## 输入格式

输入文件的唯一一行包含一个 $1-DNF$ 形式的逻辑公式（不超过 $1000$ 个符号）。逻辑操作由 ‘|’（析取）和 ‘~’（否定）表示。变量是 ‘A’ 到 ‘Z’ 和 ‘a’ 到 ‘z’（大写和小写字母是不同的变量）。公式不包含空格或语法中未提到的其他字符。

## 输出格式

输出一个整数——给定公式的 $#SAT$ 问题的答案。

## 输入输出样例 #1

### 输入 #1

```
a

```

### 输出 #1

```
1

```

## 输入输出样例 #2

### 输入 #2

```
B|~B

```

### 输出 #2

```
2

```

## 输入输出样例 #3

### 输入 #3

```
c|~C

```

### 输出 #3

```
3

```

## 输入输出样例 #4

### 输入 #4

```
i|c|p|c

```

### 输出 #4

```
7

```

## 说明/提示

时间限制：3 秒，内存限制：512 MB。

题面翻译由 ChatGPT-4o 提供。


---

# P7020 [NWRRC 2017] Boolean Satisfiability

## 题目描述

Boolean satisfiability problem (SAT) is known to be a very hard problem in computer science. In this problem you are given a Boolean formula, and you need to find out if the variables of a given formula can be consistently replaced by the values true or false in such a way that the formula evaluates to true. SAT is known to be NP-complete problem. Moreover, it is NP-complete even in case of $3-CNF$ formula $(3-SAT).$ However, for example, SAT problem for $2-CNF$ formulae $(2-SAT)$ is in $P$ .

$#SAT$ is the extension of SAT problem. In this problem you need to check if it is possible, and count the number of ways to assign values to variables. This problem is known to be $#P-complete$ even for $2-CNF$ formulae. We ask you to solve $#1-DNF-SAT,$ which is $#SAT$ problem for $1-DNF$ formulae.

You are given a Boolean formula in $1-DNF$ form. It means that it is a disjunction (logical or) of one or more clauses, each clause is exactly one literal, each literal is either variable or its negation (logical not).

Formally:

$〈formula〉 ::= 〈clause〉 | 〈formula〉 ∨ 〈clause〉$

$〈clause〉 ::= 〈literal〉$

$〈literal〉 ::= 〈variable〉 | ¬ 〈variable〉$

$〈variable〉 ::=$ A . . . $Z |$ a . . . $z$

Your task is to find the number of ways to replace all variables with values true and false (all occurrences of the same variable should be replaced with same value), such that the formula evaluates to true.

## 输入格式

The only line of the input file contains a logical formula in $1-DNF$ form (not longer than $1000$ symbols). Logical operations are represented by $‘|'$ (disjunction) and $‘ \sim ' (negatio_n).$ The variables are $‘A'$ . . . $‘Z'$ and $‘a'$ . . . $‘z'$ (uppercase and lowercase letters are different variables). The formula contains neither spaces nor other characters not mentioned in the grammar.

## 输出格式

Output a single integer -- the answer for $#SAT$ problem for the given formula.

## 输入输出样例 #1

### 输入 #1

```
a

```

### 输出 #1

```
1

```

## 输入输出样例 #2

### 输入 #2

```
B|~B

```

### 输出 #2

```
2

```

## 输入输出样例 #3

### 输入 #3

```
c|~C

```

### 输出 #3

```
3

```

## 输入输出样例 #4

### 输入 #4

```
i|c|p|c

```

### 输出 #4

```
7

```

## 说明/提示

Time limit: 3 s, Memory limit: 512 MB.