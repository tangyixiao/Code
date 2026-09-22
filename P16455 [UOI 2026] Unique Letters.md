# P16455 [UOI 2026] Unique Letters

## 题目描述

给定两个由小写拉丁字母组成的字符串 $s$ 和 $t$。

你可以任意排列字符串 $s$ 中的字符，也可以任意排列字符串 $t$ 中的字符。

我们定义字符串 $x$ 的 **唯一化** 过程如下：首先，令辅助字符串 $a$ 为空。然后从左到右依次处理字符串 $x$ 中的字符。设当前字符为 $c$。

- 若字符 $c$ 未在当前字符串 $a$ 中出现，则将该字符 $c$ 追加到 $a$ 的末尾。
- 若字符 $c$ 已经在当前字符串 $a$ 中出现过，则将 $a$ 中从开头到**第一次**出现 $c$ 为止（包含该 $c$）的后缀从 $a$ 中删除。此时，当前正在处理的字符 $c$ 不会被加入。

将处理完所有字符后得到的字符串 $a$ 称为该字符串的 **唯一化** 结果。

请你判断是否能够通过排列得到字符串 $s'$ 与 $t'$，使得：

- $s'$ 是字符串 $s$ 中字符的一个排列；
- $t'$ 是字符串 $t$ 中字符的一个排列；
- 字符串 $s'$ 的 **唯一化** 结果等于 $t'$。

## 输入格式

第一行包含字符串 $s$ $(1 \le |s| \le 2 \cdot 10^5)$。

第二行包含字符串 $t$ $(1 \le |t| \le 2 \cdot 10^5)$。

两个字符串均仅由小写拉丁字母组成。

## 输出格式

若无法得到满足要求的字符串 $s'$ 与 $t'$，输出 `NO`。

否则，输出 `YES`。接下来输出两行，分别为字符串 $s'$ 与 $t'$，满足：

- $s'$ 是字符串 $s$ 中字符的一个排列；
- $t'$ 是字符串 $t$ 中字符的一个排列；
- 字符串 $s'$ 的 **唯一化** 结果等于 $t'$。

## 输入输出样例 #1

### 输入 #1

```
bbcdfe
fe
```

### 输出 #1

```
YES
bcdbef
ef
```

## 输入输出样例 #2

### 输入 #2

```
bbfcbbd
f
```

### 输出 #2

```
YES
bcdbfbb
f
```

## 输入输出样例 #3

### 输入 #3

```
cgbfedc
gfbc
```

### 输出 #3

```
NO
```

## 说明/提示

对于第一个样例：

我们将字符串 $s$ 排列为 `bcdbef`，将字符串 $t$ 排列为 `ef`。

构造字符串 $a$ 的过程如下：

- 处理字符 `b` 后，$a = \texttt{b}$；
- 处理字符 `c` 后，$a = \texttt{bc}$；
- 处理字符 `d` 后，$a = \texttt{bcd}$；
- 处理字符 `b` 时，字母 `b` 已在 $a$ 中存在，因此我们将 $a$ 中到第一次出现 `b` 为止的后缀删除。随后，$a$ 变为空字符串；
- 处理字符 `e` 后，$a = \texttt{e}$；
- 处理字符 `f` 后，$a = \texttt{ef}$。

在第四步中，字母 `c` 和 `d` 也一同从 $a$ 中被移除，而不仅仅是字母 `b`。

最终得到的字符串 $a$ 等于排列后的字符串 $t$，因此存在答案。

对于第二个样例：

我们将字符串 $s$ 排列为 `bcdbfbb`，并保持字符串 $t$ 为 `f`。

构造字符串 $a$ 的过程如下：

- 处理字符 `b` 后，$a = \texttt{b}$；
- 处理字符 `c` 后，$a = \texttt{bc}$；
- 处理字符 `d` 后，$a = \texttt{bcd}$；
- 处理字符 `b` 时，字母 `b` 已在 $a$ 中存在，因此我们将 $a$ 中到第一次出现 `b` 为止的后缀删除。随后，$a$ 变为空字符串；
- 处理字符 `f` 后，$a = \texttt{f}$；
- 处理字符 `b` 后，$a = \texttt{fb}$；
- 处理字符 `b` 时，字母 `b` 已在 $a$ 中存在，因此我们将 $a$ 中到第一次出现 `b` 为止的后缀删除。随后，$a = \texttt{f}$。

在第四步中，字母 `c` 和 `d` 也一同从 $a$ 中被移除，而不仅仅是字母 `b`。

最终得到的字符串 $a$ 等于排列后的字符串 $t$，因此存在答案。

在第三个样例中，可以证明：对于字符串 `cgbfedc` 的任何排列，其 **唯一化** 结果都不可能是字符串 `gfbc` 的排列。

### 计分

- （$4$ 分）：$|s|=|t|=1$；
- （$8$ 分）：$s$ 可以通过排列字母得到 $t$；
- （$8$ 分）：$s$ 中所有字母互不相同；
- （$12$ 分）：字符串 $s$ 中仅有一个字母出现次数超过 $1$；
- （$24$ 分）：$s=\texttt{aaaaabbbbbcccccddddd}$；
- （$16$ 分）：$|s| \le 8$；
- （$28$ 分）：无额外限制。

翻译由 DeepSeek V4 Pro 完成

---


# P16455 [UOI 2026] Unique Letters

## 题目描述

You are given two strings $s$ and $t$, consisting of lowercase Latin letters.

You may arbitrarily permute the characters in string $s$ and arbitrarily permute the characters in string $t$.

We define the $\textit{uniquization}$ of a string $x$ as the following process. First, an auxiliary string $a$ is empty. Then the characters of string $x$ are processed from left to right. Suppose the current character is $c$.

- If character $c$ is not present in the current string $a$, then character $c$ is appended to the end of string $a$.
- If character $c$ is already present in the current string $a$, then the suffix of string $a$ up to and including the first occurrence of character $c$ is removed from $a$. In this case, the currently processed character $c$ is not added.

The string $a$ obtained after processing all characters will be called the result of uniquization of this string.

Determine whether it is possible to obtain strings $s'$ and $t'$ such that:

- $s'$ is a permutation of the characters of string $s$;
- $t'$ is a permutation of the characters of string $t$;
- the result of uniquization of string $s'$ is equal to $t'$.

## 输入格式

The first line contains string $s$ $(1 \le |s| \le 2 \cdot 10^5)$.

The second line contains string $t$ $(1 \le |t| \le 2 \cdot 10^5)$.

Both strings consist only of lowercase Latin letters.

## 输出格式

If it is impossible to obtain the required strings $s'$ and $t'$, output $\tt{NO}$.

Otherwise, output $\tt{YES}$. Then output two strings $s'$ and $t'$ such that:

- $s'$ is a permutation of the characters of string $s$;
- $t'$ is a permutation of the characters of string $t$;
- the result of uniquization of string $s'$ is equal to $t'$.

## 输入输出样例 #1

### 输入 #1

```
bbcdfe
fe
```

### 输出 #1

```
YES
bcdbef
ef
```

## 输入输出样例 #2

### 输入 #2

```
bbfcbbd
f
```

### 输出 #2

```
YES
bcdbfbb
f
```

## 输入输出样例 #3

### 输入 #3

```
cgbfedc
gfbc
```

### 输出 #3

```
NO
```

## 说明/提示

For the first sample:

We permute string $s$ as $\texttt{bcdbef}$, and string $t$ as $\texttt{ef}$.

Construct string $a$:

- after character $\texttt{b}$, we have $a = \texttt{b}$;
- after character $\texttt{c}$, we have $a = \texttt{bc}$;
- after character $\texttt{d}$, we have $a = \texttt{bcd}$;
- after character $\texttt{b}$, the letter $\texttt{b}$ is already present in string $a$, so we remove the suffix up to and including the first occurrence of $\texttt{b}$. After that, $a$ becomes an empty string;
- after character $\texttt{e}$, we have $a = \texttt{e}$;
- after character $\texttt{f}$, we have $a = \texttt{ef}$.


At the fourth step, letters $\texttt{c}$ and $\texttt{d}$ are also removed from string $a$, not only letter $\texttt{b}$.

The resulting string $a$ is equal to the permuted string $t$, so an answer exists.

For the second sample:

We permute string $s$ as $\texttt{bcdbfbb}$, and leave string $t$ as $\texttt{f}$.

Construct string $a$:

- after character $\texttt{b}$, we have $a = \texttt{b}$;
- after character $\texttt{c}$, we have $a = \texttt{bc}$;
- after character $\texttt{d}$, we have $a = \texttt{bcd}$;
- after character $\texttt{b}$, the letter $\texttt{b}$ is already present in string $a$, so we remove the suffix up to and including the first occurrence of $\texttt{b}$. After that, $a$ becomes an empty string;
- after character $\texttt{f}$, we have $a = \texttt{f}$;
- after character $\texttt{b}$, we have $a = \texttt{fb}$;
- after character $\texttt{b}$, the letter $\texttt{b}$ is already present in string $a$, so we remove the suffix up to and including the first occurrence of $\texttt{b}$. After that, $a = \texttt{f}$.


At the fourth step, letters $\texttt{c}$ and $\texttt{d}$ are also removed from string $a$, not only letter $\texttt{b}$.

The resulting string $a$ is equal to the permuted string $t$, so an answer exists.

In the third sample, it can be proved that for no permutation of string $\texttt{cgbfedc}$ will the result of uniquization be a permutation of string $\texttt{gfbc}$.

### Scoring

- ($4$ points): $|s|=|t|=1$;
- ($8$ points): $s$ can be obtained from $t$ by permuting letters;
- ($8$ points): all letters in $s$ are distinct;
- ($12$ points): only one letter in string $s$ appears more than once;
- ($24$ points): $s=\texttt{aaaaabbbbbcccccddddd}$;
- ($16$ points): $|s| \le 8$;
- ($28$ points): no additional constraints.