# CF1326D1 Prefix-Suffix Palindrome (Easy version)

## 题目描述

这是本题的简单版。 区别在于对字符串长度总和和多测数量的限制。

给你一个由小写英文字母组成的字符串 $s$。找出满足以下条件的最长字符串 $t$：

- $t$ 的长度不超过 $s$ 的长度。
- $t$ 是一个回文字符串。
- 存在两个字符串 $a$ 和 $b$（可能为空，且 $a$ 和 $b$ 不相交），使得 $t=a+b$ （加号表示连接），并且 $a$ 是 $s$ 的前缀，$b$ 是 $s$ 的后缀。

## 输入格式

输入由多个测试样例组成。第一行包含一个整数 $t$（ $1\le t\le 10^3$），即测试样例的数量。接下来的 $t$ 行分别描述一个测试样例。

每组数据的第一行都是一个非空字符串 $s$，且仅由小写英文字母组成。

保证所有测试样例的字符串长度之和不超过 $5\times 10^3$。

## 输出格式

对于每个测试样例，打印满足上述条件的最长字符串。 如果存在多个可能的解决方案，则打印其中任何一个。

## 输入输出样例 #1

### 输入 #1

```
5
a
abcdfdcecba
abbaxyzyx
codeforces
acbba
```

### 输出 #1

```
a
abcdfdcba
xyzyx
c
abba
```

## 说明/提示

在第一个样例中，字符串 `a` 满足所有条件。

在第二个样例中，字符串 `abcdfdcba` 满足所有条件。
- 因为它的长度是 $9$，没有超过字符串 $s$ 的长度 $11$。
- 它是一个回文串。
- `abcdfdcba=abcdfdc+ba`，`abcdfdc` 是 $s$ 的前缀，而 `ba` 是 $s$ 的后缀。

可以证明，不存在满足条件的更长字符串。

在第四次样例中，字符串 `c` 是正确的，因为 `c=c +""(即空串)`，又因为 $a$ 或 $b$ 可以为空。 这个样例的另一个可能解法是 `s`。

---

# CF1326D1 Prefix-Suffix Palindrome (Easy version)

## 题目描述

This is the easy version of the problem. The difference is the constraint on the sum of lengths of strings and the number of test cases. You can make hacks only if you solve all versions of this task.

You are given a string $ s $ , consisting of lowercase English letters. Find the longest string, $ t $ , which satisfies the following conditions:

- The length of $ t $ does not exceed the length of $ s $ .
- $ t $ is a palindrome.
- There exists two strings $ a $ and $ b $ (possibly empty), such that $ t = a + b $ ( " $ + $ " represents concatenation), and $ a $ is prefix of $ s $ while $ b $ is suffix of $ s $ .

## 输入格式

The input consists of multiple test cases. The first line contains a single integer $ t $ ( $ 1 \leq t \leq 1000 $ ), the number of test cases. The next $ t $ lines each describe a test case.

Each test case is a non-empty string $ s $ , consisting of lowercase English letters.

It is guaranteed that the sum of lengths of strings over all test cases does not exceed $ 5000 $ .

## 输出格式

For each test case, print the longest string which satisfies the conditions described above. If there exists multiple possible solutions, print any of them.

## 输入输出样例 #1

### 输入 #1

```
5
a
abcdfdcecba
abbaxyzyx
codeforces
acbba
```

### 输出 #1

```
a
abcdfdcba
xyzyx
c
abba
```

## 说明/提示

In the first test, the string $ s =  $ "a" satisfies all conditions.

In the second test, the string "abcdfdcba" satisfies all conditions, because:

- Its length is $ 9 $ , which does not exceed the length of the string $ s $ , which equals $ 11 $ .
- It is a palindrome.
- "abcdfdcba" $ = $ "abcdfdc" $ + $ "ba", and "abcdfdc" is a prefix of $ s $ while "ba" is a suffix of $ s $ .

It can be proven that there does not exist a longer string which satisfies the conditions.

In the fourth test, the string "c" is correct, because "c" $ = $ "c" $ + $ "" and $ a $ or $ b $ can be empty. The other possible solution for this test is "s".