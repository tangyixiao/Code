# P1709 [SEERC 2003 / USACO5.5] 隐藏口令 Hidden Password

## 题目描述

有时候程序员有很奇怪的方法来隐藏他们的口令。Binny 会选择一个字符串 $S$（由 $N$ 个小写字母组成，$5 \le N \le 5 \times {10}^6$），然后他把 $S$ 顺时针绕成一个圈，每次取一个做开头字母并顺时针依次取字母而组成一个字符串。这样将得到一些字符串，他把它们排序后取出第一个字符串。把这个字符串的第一个字母在原字符串中的位置减 $1$ 做为口令。

如字符串 `alabala`，按操作的到 $7$ 个字符串，排序后得：

`aalabal`
`abalaal`  
`alaalab`  
`alabala`  
`balaala`  
`laalaba`  
`labalaa`

第一个字符串为 `aalabal`，这个 `a` 在原字符串位置为 $7$，$7-1=6$，则 $6$ 为口令。

## 输入格式

第一行：一个数：$N$

第二行开始：字符串：$S$（每 $72$ 个字符一个换行符）

## 输出格式

一行，为得到的口令

## 输入输出样例 #1

### 输入 #1

```
7
anabana

```

### 输出 #1

```
6
```

## 说明/提示

测试数据题目满足：

$30 \%$ 的数据 $n \le {10}^4$。  
$70 \%$ 的数据 $n \le {10}^5$。  
$100 \%$ 的数据 $1 \le n \le 5 \times {10}^6$。

题目翻译来自 NOCOW。

USACO Training Section 5.5

// 20170523 新增数据四组

---

# P1709 [SEERC 2003 / USACO5.5] Hidden Password

## 题目描述

Sometimes the programmers have very strange ways of hiding their passwords. Billy "Hacker" Geits chooses a string S composed of L (5 <= L <= 100,000) lowercase letters ('a'..'z') with length L. Then he makes and sorts all L-1 one-letter left cyclic shifts of the string. He then takes as a password one prefix of the lexicographically first of the obtained strings (including S).

For example consider the string "alabala". The sorted cyclic one-letter left shifts (including the initial string) are:

```
aalabal 
abalaal 
alaalab 
alabala 
balaala 
laalaba 
labalaa
```

Lexicographically, first string is 'aalabal'. The first letter of this string ('a') is the 'a' that was in position 6 in the initial string (counting the first letter in the string as position 0).

Write a program that, for given string S, finds the start position of the first letter of the sorted list of cyclic shifts of the string. If the first element appears more than once in the sorted list, then the program should output the smallest possible initial position.

## 输入格式

Line 1: A single integer: L

Line 2..?: All L characters of the the string S, broken across lines such that each line has 72 characters except the last one, which might have fewer.

## 输出格式

Line 1: A single integer that is the start position of the first letter, as described above.

## 输入输出样例 #1

### 输入 #1

```
7
anabana

```

### 输出 #1

```
6
```