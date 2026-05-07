# CF2225A A Number Between Two Others

## 题目描述

You are given two integers  $ x $  and  $ y $  such that  $ y  \gt  x $  and  $ y \bmod x = 0 $  (that is,  $ y $  is divisible by  $ x $ ).

Your task is to determine whether there exists an integer  $ z $  such that

- $ z $  lies between  $ x $  and  $ y $  (that is,  $ x  \lt  z  \lt  y $ );
- $ z $  is divisible by  $ x $  (that is,  $ z \bmod x = 0 $ );
- $ y $  is not divisible by  $ z $  (that is,  $ y \bmod z \ne 0 $ ).

## 输入格式

Each test contains multiple test cases. The first line contains the number of test cases  $ t $  ( $ 1 \le t \le 10^4 $ ). The description of the test cases follows.

Each test case consists of a single line containing two integers  $ x $  and  $ y $  ( $ 1 \le x  \lt  y \le 10^{18} $ ;  $ y \bmod x = 0 $ ).

## 输出格式

For each test case, print the answer as follows: if the required number  $ z $  exists, print YES; otherwise, print NO. You may print each letter in any case.

## 输入输出样例 #1

### 输入 #1

```
5
1 2
1 3
1234567890 12345678900
2 8
7 84
```

### 输出 #1

```
NO
YES
YES
YES
YES
```

## 说明/提示

In the second test case of the example, you can use  $ z = 2 $ .

In the third test case of the example, you can use  $ z = 7407407340 $ .