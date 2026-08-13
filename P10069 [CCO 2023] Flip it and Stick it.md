# P10069 [CCO 2023] Flip it and Stick it

## 题目描述

Finn 正在玩一款叫做「Flip it and Stick it」的游戏，简称为 FiSi。FiSi 是一款单人游戏，玩法是在两个由 0 和 1 组成的字符串 $S$ 和 $T$ 上进行操作。Finn 可以进行以下形式的操作：

选择 $S$ 的一个子串并将其翻转，然后将字符串的各部分按照原来的顺序粘贴在一起，形成新的字符串 $S$。
例如，Finn 可以取字符串 $S=101100$，取从第 2 位开始的子串 $011$（字符串的编号是从 $1$ 开始的），并在一次操作中创建字符串 $S=111000$。

如果 $S$ 不包含 $T$ 作为子串，Finn 就赢得了游戏。你的任务是帮助 Finn 确定赢得游戏所需的最短操作序列的长度，或者告诉他游戏无法获胜。

## 输入格式

第一行一个字符串 $S$。

第二行一个字符串 $T$。

## 输出格式

输出一行一个整数，表示如果能赢得游戏所需的最少操作次数，否则输出 $-1$。

## 输入输出样例 #1

### 输入 #1

```
100110
10
```

### 输出 #1

```
2
```

## 输入输出样例 #2

### 输入 #2

```
000
00
```

### 输出 #2

```
-1
```

## 说明/提示

**样例解释 1**

Finn 从字符串 $100110$ 开始。他无法通过一次操作后使得 $10$ 不为子串，但他可以在两次操作后做到。

例如，他的第一次操作可以是翻转从第 4 位到第 6 位的子串（$110$），得到 $100011$。然后，他的第二次操作可以是翻转从第 1 位到第 4 位的子串（$1000$），得到 $000111$，它不包含 $10$ 作为子串。

**样例解释 2**

无论 Finn 进行多少次操作，字符串 $T$ 总会是 $S$ 的子串。

对于所有的数据，有 $1 \leq|S| \leq 2\times 10^5$，$1 \leq|T| \leq 3$。

设 $|T|=l$。

| 子任务编号 |	分值	| $l$ 的限制 |
| :-:|:-:|:-:|
|1|	4|	$l=1$|
|2|	12|	$l=2, T_{1} \neq T_{2}$|
|3|	16|	$l=2$|
|4|	20|	$l=3, T_{1} \neq T_{3}$|
|5|	20|	$l=3,T_{1} \neq T_{2}$|
|6|	28|	$l=3$|

---

# P10069 [CCO 2023] Flip it and Stick it

## 题目描述

Finn is playing a game called “Flip it and Stick it”, abbreviated as FiSi. FiSi is a single-player game played on two strings $S$ and $T$ consisting of 0s and 1s. Finn can perform the following type of operation:

Choose a substring of $S$ and reverse it, then stick the parts of the string back together in the original order to form a new string $S$.
For example, Finn can take the string $S=101100$, choose the substring $011$ starting from position 2 (the string is indexed from $1$), and create the string $S=111000$ in one operation.

If $S$ does not contain $T$ as a substring, Finn wins the game. Your task is to help Finn determine the length of the shortest sequence of operations needed to win the game, or tell him that the game cannot be won.

## 输入格式

The first line contains a string $S$.

The second line contains a string $T$.

## 输出格式

Output one line containing an integer: the minimum number of operations needed to win if it is possible, otherwise output $-1$.

## 输入输出样例 #1

### 输入 #1

```
100110
10
```

### 输出 #1

```
2
```

## 输入输出样例 #2

### 输入 #2

```
000
00
```

### 输出 #2

```
-1
```

## 说明/提示

**Sample Explanation 1**

Finn starts from the string $100110$. He cannot make $10$ not be a substring with one operation, but he can do it in two operations.

For example, his first operation can be to reverse the substring from position 4 to position 6 ($110$), obtaining $100011$. Then, his second operation can be to reverse the substring from position 1 to position 4 ($1000$), obtaining $000111$, which does not contain $10$ as a substring.

**Sample Explanation 2**

No matter how many operations Finn performs, the string $T$ will always be a substring of $S$.

For all testdata, $1 \leq|S| \leq 2\times 10^5$, $1 \leq|T| \leq 3$.

Let $|T|=l$.

| Subtask ID | Score | Constraint on $l$ |
| :-: | :-: | :-: |
| 1 | 4 | $l=1$ |
| 2 | 12 | $l=2, T_{1} \neq T_{2}$ |
| 3 | 16 | $l=2$ |
| 4 | 20 | $l=3, T_{1} \neq T_{3}$ |
| 5 | 20 | $l=3, T_{1} \neq T_{2}$ |
| 6 | 28 | $l=3$ |

Translated by ChatGPT 5