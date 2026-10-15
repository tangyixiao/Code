# P4761 [CERC2014] Vocabulary

## 题目描述

根据一种流行的说法，计算机程序员喝很多咖啡，并且只知道几个单词。一个典型程序员的词汇量只有三个单词。此外，他很少知道如何拼写它们。为了帮助程序员纠正拼写错误，我们出版了一本名为《每个典型程序员应该知道的三个单词词典》的书。

你得到了一本书的副本，但不久之后，你把咖啡洒在了上面。

现在，你无法阅读其中的一些字符。幸运的是，这三个单词在字典中是不同的，并按字典顺序排列。在你尝试利用这一事实来恢复缺失的字符之前，你想知道有多少种不同的方法可以做到这一点。由于你预计这个数字可能很大，你想知道它对 $10^9 + 9$ 取模的结果。

## 输入格式

输入的第一行包含测试用例的数量 $T$。接下来的描述是测试用例：

每个测试用例由三行组成，每行包含一个非空单词——按它们在字典中出现的顺序。单词由小写英文字母和问号组成，问号表示缺失的字符。每个单词最多有 $1,000,000$ 个字符。

## 输出格式

对于每个测试用例，输出一行，包含将每个问号替换为从 “a” 到 “z” 的 $26$ 个字母之一的不同方法数，使得三个单词不同且按字典顺序排列。结果应对 $10^9 + 9$ 取模。

## 输入输出样例 #1

### 输入 #1

```
3
?heoret?cal
c?mputer
?cience
jagiellonian
?niversity
kra?ow
?
b
c
```

### 输出 #1

```
42562
52
1
```

## 说明/提示

题面翻译由 ChatGPT-4o 提供。

---

# P4761 [CERC2014] Vocabulary

## 题目描述

According to a popular belief, computer programmers drink a lot of coffee and know only a few words. The vocabulary of a typical programmer consists of just three words. Besides, he rarely knows how to spell them. To help programmers with their spelling mistakes, we published a book titled $The \ Dictionary \ of \ the \ Three \ Words \ Every \ Typical \ Programmer \ Should \ Know$.

You got a copy of the book but, soon after that, you spilled your coffee over it.

Now, youcannot read some of the characters. Fortunately, the three words were, as usually in dictionaries,distinct and printed in lexicographical order.
Before you attempt to use that fact to recover the missing characters, you want to know in how many different ways you can do it. Since you expect this number might be large, you want to know it modulo $10^9 + 9$.

## 输入格式

The first line of input contains the number of test cases $T$. The descriptions of the test cases follow:

Each test case consists of three lines, each containing a single nonempty word – in the order they appear in the dictionary. Words consist of small letters of the English alphabet and question marks, the latter denoting missing characters. Each word is at most $1 000 000$ characters long.

## 输出格式

For each test case, output one line containing the number of different ways you can substitute each question mark with one of the $26$ letters from ``a`` to ``z`` in such a way that the three words are distinct and in lexicographical order. The number should be printed modulo $10^9 + 9$.

## 输入输出样例 #1

### 输入 #1

```
3
?heoret?cal
c?mputer
?cience
jagiellonian
?niversity
kra?ow
?
b
c
```

### 输出 #1

```
42562
52
1
```