# P3612 [USACO17JAN] Secret Cow Code S

## 题目描述

奶牛们正在实验秘密代码，并设计了一种方法用于生成无限长度的字符串，作为他们代码的一部分。

给定一个字符串 $s$，令 $F(s)$ 为 $s$ 后接 $s$ 向右“旋转”一个字符的结果（在右旋转中，$s$ 的最后一个字符旋转并成为新的第一个字符）。给定初始字符串 $s$，奶牛们通过重复应用 $F$ 来构建他们的无限长度代码字符串；因此每一步都会使当前字符串的长度翻倍。

给定初始字符串和一个索引 $N$，请帮助奶牛计算无限代码字符串中第 $N$ 个位置的字符。

## 输入格式

输入由一行组成，包含一个字符串和 $N$。字符串最多由 30 个大写字母组成，且 $N \leq 10^{18}$。

请注意，$N$ 可能太大，无法放入标准的 32 位整数中，因此你可能需要使用 64 位整数类型（例如，C/C++ 中的 "long long"）。

## 输出格式

请输出从初始字符串构建的无限代码字符串的第 $N$ 个字符。第一个字符的位置为 $N=1$。

## 输入输出样例 #1

### 输入 #1

```
COW 8
```

### 输出 #1

```
C
```

## 说明/提示

在这个例子中，初始字符串 COW 按以下方式扩展：

COW -> COWWCO -> COWWCOOCOWWC

---

# P3612 [USACO17JAN] Secret Cow Code S

## 题目描述

The cows are experimenting with secret codes, and have devised a method for creating an infinite-length string to be used as part of one of their codes.

Given a string $s$, let $F(s)$ be $s$ followed by $s$ "rotated" one character to the right (in a right rotation, the last character of $s$ rotates around and becomes the new first character). Given an initial string $s$, the cows build their infinite-length code string by repeatedly applying $F$; each step therefore doubles the length of the current string.


Given the initial string and an index $N$, please help the cows compute the character at the $N$th position within the infinite code string.

## 输入格式

The input consists of a single line containing a string followed by $N$. The string consists of at most 30 uppercase characters, and $N \leq 10^{18}$.

Note that $N$ may be too large to fit into a standard 32-bit integer, so you may want to use a 64-bit integer type (e.g., a "long long" in C/C++).

## 输出格式

Please output the $N$th character of the infinite code built from the initial string. The first character is $N=1$.

## 输入输出样例 #1

### 输入 #1

```
COW 8
```

### 输出 #1

```
C
```

## 说明/提示

In this example, the initial string COW expands as follows:


COW -> COWWCO -> COWWCOOCOWWC

12345678