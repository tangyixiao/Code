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