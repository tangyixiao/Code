# CF1537E1 Erase and Extend (Easy Version)

## 题目描述

这是该问题的简单版本。唯一的区别在于 $n$ 和 $k$ 的约束条件。只有在所有版本的问题都被解决后，你才能进行 hack。

你有一个字符串 $s$，你可以对它进行两种操作：

- 删除字符串的最后一个字符。
- 复制字符串：$s := s + s$，其中 $+$ 表示连接操作。

每种操作你都可以执行任意次（也可以不执行）。

你的任务是通过对字符串 $s$ 进行这些操作，得到长度恰好为 $k$ 的字典序最小的字符串。

如果满足以下任一条件，则字符串 $a$ 的字典序小于字符串 $b$：

- $a$ 是 $b$ 的前缀，且 $a \ne b$；
- 在 $a$ 和 $b$ 第一个不同的位置，$a$ 的字母在字母表中比 $b$ 的对应字母更靠前。

## 输入格式

第一行包含两个整数 $n$ 和 $k$（$1 \leq n, k \leq 5000$）——原始字符串 $s$ 的长度和所需字符串的长度。

第二行包含字符串 $s$，由 $n$ 个小写英文字母组成。

## 输出格式

输出通过对字符串 $s$ 进行操作后得到的长度恰好为 $k$ 的字典序最小的字符串。

## 输入输出样例 #1

### 输入 #1

```
8 16
dbcadabc
```

### 输出 #1

```
dbcadabcdbcadabc
```

## 输入输出样例 #2

### 输入 #2

```
4 5
abcd
```

### 输出 #2

```
aaaaa
```

## 说明/提示

在第一个测试中，最优方案是进行一次复制操作："dbcadabc" $\to$ "dbcadabcdbcadabc"。

在第二个测试中，最优方案是先删除最后 $3$ 个字符，然后将字符串复制 $3$ 次，再删除最后 $3$ 个字符，使字符串长度为 $k$。

"abcd" $\to$ "abc" $\to$ "ab" $\to$ "a" $\to$ "aa" $\to$ "aaaa" $\to$ "aaaaaaaa" $\to$ "aaaaaaa" $\to$ "aaaaaa" $\to$ "aaaaa"。

由 ChatGPT 4.1 翻译

---

# CF1537E1 Erase and Extend (Easy Version)

## 题目描述

This is the easy version of the problem. The only difference is the constraints on $ n $ and $ k $ . You can make hacks only if all versions of the problem are solved.

You have a string $ s $ , and you can do two types of operations on it:

- Delete the last character of the string.
- Duplicate the string: $ s:=s+s $ , where $ + $ denotes concatenation.

You can use each operation any number of times (possibly none).

Your task is to find the lexicographically smallest string of length exactly $ k $ that can be obtained by doing these operations on string $ s $ .

A string $ a $ is lexicographically smaller than a string $ b $ if and only if one of the following holds:

- $ a $ is a prefix of $ b $ , but $ a\ne b $ ;
- In the first position where $ a $ and $ b $ differ, the string $ a $ has a letter that appears earlier in the alphabet than the corresponding letter in $ b $ .

## 输入格式

The first line contains two integers $ n $ , $ k $ ( $ 1 \leq n, k \leq 5000 $ ) — the length of the original string $ s $ and the length of the desired string.

The second line contains the string $ s $ , consisting of $ n $ lowercase English letters.

## 输出格式

Print the lexicographically smallest string of length $ k $ that can be obtained by doing the operations on string $ s $ .

## 输入输出样例 #1

### 输入 #1

```
8 16
dbcadabc
```

### 输出 #1

```
dbcadabcdbcadabc
```

## 输入输出样例 #2

### 输入 #2

```
4 5
abcd
```

### 输出 #2

```
aaaaa
```

## 说明/提示

In the first test, it is optimal to make one duplication: "dbcadabc" $ \to $ "dbcadabcdbcadabc".

In the second test it is optimal to delete the last $ 3 $ characters, then duplicate the string $ 3 $ times, then delete the last $ 3 $ characters to make the string have length $ k $ .

"abcd" $ \to $ "abc" $ \to $ "ab" $ \to $ "a" $ \to $ "aa" $ \to $ "aaaa" $ \to $ "aaaaaaaa" $ \to $ "aaaaaaa" $ \to $ "aaaaaa" $ \to $ "aaaaa".

## 题解

### 算法思路

如果先删除字符串末尾的一些字符，留下长度为 $p$ 的前缀，那么后续的复制操作只会重复这个前缀。最终得到的字符串一定是

$$
(s_1s_2\ldots s_p)^{\infty}
$$

的前 $k$ 个字符，其中 $1\le p\le n$。反过来，任意长度为 $p$ 的前缀都可以通过删除后复制得到，所以只需枚举 $p$。

维护当前字典序最小的前缀长度 `best`。对新的长度 $p$，逐字符比较两个周期串：新候选字符是 $s_{i\bmod p}$，当前最优字符是 $s_{i\bmod best}$。比较到第一个不同字符即可判断谁更小。

两个候选的周期分别为 $p$ 和 `best`。若它们要生成的长度不足 $p+best$，比较到长度 $k$ 即可；否则比较前 $p+best$ 个字符就足够。两个周期串若在这么长的公共前缀中完全相同，之后也会完全相同。因此每个候选最多比较 $p+best\le 2n$ 个字符。

找到最优前缀长度后，按下标 `i % best` 输出恰好 $k$ 个字符。

### 正确性证明

**引理 1：** 任意合法操作得到的长度为 $k$ 的字符串，都是原串某个前缀的重复串的前 $k$ 个字符。

操作只会删除末尾字符或将整个字符串复制一遍。删除操作最终留下原串的某个前缀；复制不会改变这个前缀作为周期的结构，最后删除多余字符即可得到所需长度。反过来，任意前缀都能先通过删除得到，再重复复制并截取到长度 $k$。因此枚举所有前缀长度覆盖了全部可行结果。

**引理 2：** 比较周期为 $p$ 和 `best` 的两个候选时，比较前 $\min(k,p+best)$ 个字符足以确定长度 $k$ 的字典序关系。

若比较过程中出现不同字符，该位置就是字典序的第一个差异。若 $k\le p+best$ 且始终相同，则两个长度为 $k$ 的结果相同。若前 $p+best$ 个字符都相同，两个周期串分别具有周期 $p$ 和 `best`；如此长的公共部分已经足以确定它们相同的周期延续，因此之后也不会首次出现差异。

**定理：** 算法输出字典序最小的可行字符串。

由引理 1，所有可行结果都对应某个前缀长度。算法逐个枚举这些长度，并由引理 2 正确比较新候选与当前最优候选；每次保留两者中较小者。因此遍历结束时保留的是所有可行结果中的最小值，按该前缀重复输出 $k$ 个字符即为答案。

### 复杂度分析

共有 $n$ 个候选长度，每个最多比较 $2n$ 个字符，输出还需要 $k$ 个字符。时间复杂度为 $O(n^2+k)$，额外空间复杂度为 $O(1)$（不计存储输入字符串）。
