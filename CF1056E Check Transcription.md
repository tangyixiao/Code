# CF1056E Check Transcription

## 题目描述

Arkady 的一位朋友在一个巨大的射电望远镜工作。几十年前，这个望远镜向遥远的星系发送了一个信号 $s$。最近他们收到了一个回应 $t$，他们认为这可能是外星人的回复！科学家们现在想要检查信号 $t$ 是否与 $s$ 相似。

原始信号 $s$ 是由 $0$ 和 $1$ 组成的序列（众所周知，二进制代码是宇宙通用的语言）。然而，返回的信号 $t$ 看起来并不像 $s$ 那么简单，但科学家们并没有放弃！他们将 $t$ 表示为一串英文小写字母，并且认为如果你可以将 $s$ 中所有的 $0$ 替换为某个字符串 $r_0$，所有的 $1$ 替换为另一个字符串 $r_1$，从而得到 $t$，那么 $t$ 就与 $s$ 相似。字符串 $r_0$ 和 $r_1$ 必须是不同且非空的。

请帮助 Arkady 的朋友，计算有多少种可能的 $r_0$ 和 $r_1$ 的取值对（即字符串对 $(r_0, r_1)$），可以将 $s$ 变换为 $t$。

## 输入格式

第一行包含一个字符串 $s$（$2 \le |s| \le 10^5$），由 $0$ 和 $1$ 组成，表示原始信号。

第二行包含一个字符串 $t$（$1 \le |t| \le 10^6$），由小写英文字母组成，表示收到的信号。

保证字符串 $s$ 至少包含一个 $0$ 和至少一个 $1$。

## 输出格式

输出一个整数，表示可以将 $s$ 变换为 $t$ 的 $(r_0, r_1)$ 对的数量。

如果不存在这样的对，输出 $0$。

## 输入输出样例 #1

### 输入 #1

```
01
aaaaaa

```

### 输出 #1

```
4

```

## 输入输出样例 #2

### 输入 #2

```
001
kokokokotlin

```

### 输出 #2

```
2

```

## 说明/提示

在第一个样例中，可能的 $(r_0, r_1)$ 对如下：

- "a", "aaaaa"
- "aa", "aaaa"
- "aaaa", "aa"
- "aaaaa", "a"

对 "aaa", "aaa" 不允许，因为 $r_0$ 和 $r_1$ 必须不同。

在第二个样例中，可能的对有：

- "ko", "kokotlin"
- "koko", "tlin"

由 ChatGPT 4.1 翻译

---

# CF1056E Check Transcription

## 题目描述

One of Arkady's friends works at a huge radio telescope. A few decades ago the telescope has sent a signal $ s $ towards a faraway galaxy. Recently they've received a response $ t $ which they believe to be a response from aliens! The scientists now want to check if the signal $ t $ is similar to $ s $ .

The original signal $ s $ was a sequence of zeros and ones (everyone knows that binary code is the universe-wide language). The returned signal $ t $ , however, does not look as easy as $ s $ , but the scientists don't give up! They represented $ t $ as a sequence of English letters and say that $ t $ is similar to $ s $ if you can replace all zeros in $ s $ with some string $ r_0 $ and all ones in $ s $ with some other string $ r_1 $ and obtain $ t $ . The strings $ r_0 $ and $ r_1 $ must be different and non-empty.

Please help Arkady's friend and find the number of possible replacements for zeros and ones (the number of pairs of strings $ r_0 $ and $ r_1 $ ) that transform $ s $ to $ t $ .

## 输入格式

The first line contains a string $ s $ ( $ 2 \le |s| \le 10^5 $ ) consisting of zeros and ones — the original signal.

The second line contains a string $ t $ ( $ 1 \le |t| \le 10^6 $ ) consisting of lowercase English letters only — the received signal.

It is guaranteed, that the string $ s $ contains at least one '0' and at least one '1'.

## 输出格式

Print a single integer — the number of pairs of strings $ r_0 $ and $ r_1 $ that transform $ s $ to $ t $ .

In case there are no such pairs, print $ 0 $ .

## 输入输出样例 #1

### 输入 #1

```
01
aaaaaa

```

### 输出 #1

```
4

```

## 输入输出样例 #2

### 输入 #2

```
001
kokokokotlin

```

### 输出 #2

```
2

```

## 说明/提示

In the first example, the possible pairs $ (r_0, r_1) $ are as follows:

- "a", "aaaaa"
- "aa", "aaaa"
- "aaaa", "aa"
- "aaaaa", "a"

The pair "aaa", "aaa" is not allowed, since $ r_0 $ and $ r_1 $ must be different.

In the second example, the following pairs are possible:

- "ko", "kokotlin"
- "koko", "tlin"