# CF1790E Vlad and a Pair of Numbers

## 题目描述

Vlad 找到了两个正整数 $a$ 和 $b$（$a,b>0$）。他发现 $a \oplus b = \frac{a + b}{2}$，其中 $\oplus$ 表示[按位异或运算](http://tiny.cc/xor_wiki_eng)，除法为不进行四舍五入的普通除法。

由于记住一个数比记住两个数更容易，Vlad 只记住了 $a\oplus b$，我们用 $x$ 表示这个数。请你帮助他找到任意一组满足条件的 $a$ 和 $b$，或者告诉他不存在这样的数对。

## 输入格式

输入的第一行为一个整数 $t$（$1 \le t \le 10^4$），表示测试用例的数量。

每个测试用例包含一个整数 $x$（$1 \le x \le 2^{29}$），表示 Vlad 记住的那个数。

## 输出格式

输出 $t$ 行，每行对应一个测试用例的答案。每行输出两个整数 $a$ 和 $b$（$0 < a,b \le 2^{32}$），满足 $x = a \oplus b = \frac{a + b}{2}$。如果有多组答案，输出任意一组即可。如果不存在满足条件的数对，输出 -1。

## 输入输出样例 #1

### 输入 #1

```
6
2
5
10
6
18
36
```

### 输出 #1

```
3 1
-1
13 7
-1
25 11
50 22
```

## 说明/提示

由 ChatGPT 4.1 翻译

---

# CF1790E Vlad and a Pair of Numbers

## 题目描述

Vlad found two positive numbers $ a $ and $ b $ ( $ a,b>0 $ ). He discovered that $ a \oplus b = \frac{a + b}{2} $ , where $ \oplus $ means the [bitwise exclusive OR](http://tiny.cc/xor_wiki_eng) , and division is performed without rounding..

Since it is easier to remember one number than two, Vlad remembered only $ a\oplus b $ , let's denote this number as $ x $ . Help him find any suitable $ a $ and $ b $ or tell him that they do not exist.

## 输入格式

The first line of the input data contains the single integer $ t $ ( $ 1 \le t \le 10^4 $ ) — the number of test cases in the test.

Each test case is described by a single integer $ x $ ( $ 1 \le x \le 2^{29} $ ) — the number that Vlad remembered.

## 输出格式

Output $ t $ lines, each of which is the answer to the corresponding test case. As the answer, output $ a $ and $ b $ ( $ 0 < a,b \le 2^{32} $ ), such that $ x = a \oplus b = \frac{a + b}{2} $ . If there are several answers, output any of them. If there are no matching pairs, output -1.

## 输入输出样例 #1

### 输入 #1

```
6
2
5
10
6
18
36
```

### 输出 #1

```
3 1
-1
13 7
-1
25 11
50 22
```