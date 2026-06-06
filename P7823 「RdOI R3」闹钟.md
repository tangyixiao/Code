# P7823 「RdOI R3」闹钟

## 题目描述

你有一个闹钟，闹钟的定时可以用两个变量 $a_1,a_2$ 表示，变量的初始值皆为 $0$。把一个变量从 $x$ 调整至 $y$ 需要 $|x-y|$ 的代价。

接下来给出 $n$ 个数 $k_1,k_2,\cdots,k_n$。对于第 $i$ 天，你都需要通过调整变量的值，使得两个变量中**至少**有一个等于 $k_i$。求最小代价。

## 输入格式

第一行一个整数 $n$。  
第二行 $n$ 个整数 $k_1,k_2,\cdots,k_n$。

## 输出格式

一行一个整数，表示最小代价。

## 输入输出样例 #1

### 输入 #1

```
6
1 1 4 5 1 4
```

### 输出 #1

```
7
```

## 输入输出样例 #2

### 输入 #2

```
5
4 1 9 2 3
```

### 输出 #2

```
12
```

## 说明/提示

### 样例解释

样例解释一：  
第一天：$a=\{1,0\}$。  
第二天：$a=\{1,0\}$。  
第三天：$a=\{4,0\}$。  
第四天：$a=\{5,0\}$。  
第五天：$a=\{5,1\}$。  
第六天：$a=\{4,1\}$。  

样例解释二：  
第一天：$a=\{4,0\}$。  
第二天：$a=\{4,1\}$。  
第三天：$a=\{9,1\}$。  
第四天：$a=\{9,2\}$。  
第五天：$a=\{9,3\}$。 

---

### 数据范围

|数据编号|$n\le$|特殊性质|
|:-:|:-:|:-:|
|$1$|$10$|无|
|$2$|$10^3$|$k_i\le100$|
|$3\sim4$|$10^3$|无|
|$5\sim7$|$10^5$|$k_i\le100$|
|$8\sim10$|$10^5$|无|

另外，为了卡掉一些错误做法，本题添加了若干 hack 测试点。hack 测试点的数据满足 $n\le10$ 且 $k_i\le 100$。若你的程序没有通过至少一个 hack 测试点，则此题分数记为 $0$ 分。

对于 $100\%$ 的数据，$1\le n\le10^5,1\le k_i\le10^9$。

---

# P7823 "RdOI R3" Alarm Clock

## 题目描述

You have an alarm clock. The timer settings of the alarm clock can be represented by two variables $a_1, a_2$, both starting with an initial value of $0$. Adjusting a variable from $x$ to $y$ costs $|x-y|$.

Next, you are given $n$ numbers $k_1, k_2, \cdots, k_n$. On day $i$, you need to adjust the variables so that **at least** one of the two variables equals $k_i$. Find the minimum total cost.

## 输入格式

The first line contains an integer $n$.  
The second line contains $n$ integers $k_1, k_2, \cdots, k_n$.

## 输出格式

Output one integer in one line, representing the minimum cost.

## 输入输出样例 #1

### 输入 #1

```
6
1 1 4 5 1 4
```

### 输出 #1

```
7
```

## 输入输出样例 #2

### 输入 #2

```
5
4 1 9 2 3
```

### 输出 #2

```
12
```

## 说明/提示

### Sample Explanation

Sample explanation 1:  
Day 1: $a=\{1,0\}$.  
Day 2: $a=\{1,0\}$.  
Day 3: $a=\{4,0\}$.  
Day 4: $a=\{5,0\}$.  
Day 5: $a=\{5,1\}$.  
Day 6: $a=\{4,1\}$.  

Sample explanation 2:  
Day 1: $a=\{4,0\}$.  
Day 2: $a=\{4,1\}$.  
Day 3: $a=\{9,1\}$.  
Day 4: $a=\{9,2\}$.  
Day 5: $a=\{9,3\}$.  

---

### Constraints

|Test ID|$n\le$|Special property|
|:-:|:-:|:-:|
|$1$|$10$|None|
|$2$|$10^3$|$k_i\le 100$|
|$3\sim 4$|$10^3$|None|
|$5\sim 7$|$10^5$|$k_i\le 100$|
|$8\sim 10$|$10^5$|None|

In addition, to catch some incorrect solutions, this problem includes several hack test points. The testdata of the hack test points satisfy $n\le 10$ and $k_i\le 100$. If your program does not pass at least one hack test point, then the score for this problem will be $0$.

For $100\%$ of the testdata, $1\le n\le 10^5$ and $1\le k_i\le 10^9$.

Translated by ChatGPT 5