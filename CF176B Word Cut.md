# CF176B Word Cut

## 题目描述

让我们来考虑一个有趣的单词游戏。在这个游戏中，你需要通过特殊操作将一个单词变换成另一个单词。

假如我们有一个单词 $w$，我们可以将这个单词分成两个非空部分 $x$ 和 $y$，使得 $w=xy$。一次“分割操作”指的是将单词 $w=xy$ 变换为新单词 $u=yx$。例如，一次分割操作可以将单词 "wordcut" 变换成 "cutword"。

现在给定两个单词 $start$ 和 $end$。请计算有多少种不同的方法，可以通过恰好 $k$ 次连续的分割操作，将单词 $start$ 变换成单词 $end$。

如果两个操作序列在某一步（$1 \leq i \leq k$）中，选取的分割位置不同，则认为这两种方式是不同的方法。具体来说，若第 $i$ 次操作时，两种方案分别将单词分割为 $x|y$ 和 $a|b$，并且 $x\neq a$，则认为两个序列不同。

## 输入格式

第一行包含一个非空单词 $start$，第二行包含一个非空单词 $end$。两个单词均由小写拉丁字母组成，且长度相等，长度不少于 $2$，不超过 $1000$。

第三行包含一个整数 $k$ ($0 \leq k \leq 10^{5}$)——需要执行的分割操作次数。

## 输出格式

输出一个整数，表示答案。由于答案可能很大，请输出对 $1000000007$ ($10^9+7$) 取模后的结果。

## 输入输出样例 #1

### 输入 #1

```
ab
ab
2

```

### 输出 #1

```
1

```

## 输入输出样例 #2

### 输入 #2

```
ababab
ababab
1

```

### 输出 #2

```
2

```

## 输入输出样例 #3

### 输入 #3

```
ab
ba
2

```

### 输出 #3

```
0

```

## 说明/提示

第一个样例中，唯一的方案是：

ab $→$ a|b $→$ ba $→$ b|a $→$ ab

第二个样例中，有两种方案：

- ababab $→$ abab|ab $→$ ababab
- ababab $→$ ab|abab $→$ ababab

由 ChatGPT 5 翻译

---

# CF176B Word Cut

## 题目描述

Let's consider one interesting word game. In this game you should transform one word into another through special operations.

Let's say we have word $ w $ , let's split this word into two non-empty parts $ x $ and $ y $ so, that $ w=xy $ . A split operation is transforming word $ w=xy $ into word $ u=yx $ . For example, a split operation can transform word "wordcut" into word "cutword".

You are given two words $ start $ and $ end $ . Count in how many ways we can transform word $ start $ into word $ end $ , if we apply exactly $ k $ split operations consecutively to word $ start $ .

Two ways are considered different if the sequences of applied operations differ. Two operation sequences are different if exists such number $ i $ ( $ 1<=i<=k $ ), that in the $ i $ -th operation of the first sequence the word splits into parts $ x $ and $ y $ , in the $ i $ -th operation of the second sequence the word splits into parts $ a $ and $ b $ , and additionally $ x≠a $ holds.

## 输入格式

The first line contains a non-empty word $ start $ , the second line contains a non-empty word $ end $ . The words consist of lowercase Latin letters. The number of letters in word $ start $ equals the number of letters in word $ end $ and is at least $ 2 $ and doesn't exceed $ 1000 $ letters.

The third line contains integer $ k $ ( $ 0<=k<=10^{5} $ ) — the required number of operations.

## 输出格式

Print a single number — the answer to the problem. As this number can be rather large, print it modulo $ 1000000007 $ $ (10^{9}+7) $ .

## 输入输出样例 #1

### 输入 #1

```
ab
ab
2

```

### 输出 #1

```
1

```

## 输入输出样例 #2

### 输入 #2

```
ababab
ababab
1

```

### 输出 #2

```
2

```

## 输入输出样例 #3

### 输入 #3

```
ab
ba
2

```

### 输出 #3

```
0

```

## 说明/提示

The sought way in the first sample is:

ab $ → $ a|b $ → $ ba $ → $ b|a $ → $ ab

In the second sample the two sought ways are:

- ababab $ → $ abab|ab $ → $ ababab
- ababab $ → $ ab|abab $ → $ ababab