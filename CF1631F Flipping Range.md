# CF1631F Flipping Range

## 题目描述

给定一个长度为 $n$ 的整数数组 $a$ 和一个包含 $m$ 个正整数的集合 $B$，其中 $1 \leq b_i \leq \lfloor \frac{n}{2} \rfloor$，$1\le i\le m$，$b_i$ 是 $B$ 的第 $i$ 个元素。

你可以对 $a$ 进行如下操作：

1. 选择某个 $x$，其中 $x$ 必须出现在 $B$ 中。
2. 从数组 $a$ 中选择一个长度为 $x$ 的区间，将该区间内的每个元素都乘以 $-1$。形式化地说，选择 $l$ 和 $r$，满足 $1\leq l\leq r \leq n$ 且 $r-l+1=x$，然后对每个 $l\leq i\leq r$，令 $a_i:=-a_i$。

举例如下，设 $a=[0,6,-2,1,-4,5]$，$B=\{1,2\}$：

1. 选择长度为 $2$ 的区间，$l=4$，$r=5$，操作后得到 $[0,6,-2,-1,4,5]$。
2. 选择长度为 $1$ 的区间，$l=3$，$r=3$，操作后得到 $[0,6,2,-1,4,5]$。

请你求出，经过任意次（可以为零次）上述操作后，数组 $a$ 所有元素之和 $\sum\limits_{i=1}^n {a_i}$ 的最大值。

## 输入格式

输入包含多组测试数据。第一行包含一个整数 $t$（$1 \le t \le 10^5$），表示测试用例的数量。接下来是每组测试数据的描述。

每组测试数据的第一行包含两个整数 $n$ 和 $m$（$2\leq n \leq 10^6$，$1 \leq m \leq \lfloor \frac{n}{2} \rfloor$），分别表示数组 $a$ 和集合 $B$ 的元素个数。

第二行包含 $n$ 个整数 $a_1,a_2,\ldots,a_n$（$-10^9\leq a_i \leq 10^9$）。

第三行包含 $m$ 个互不相同的正整数 $b_1,b_2,\ldots,b_m$（$1 \leq b_i \leq \lfloor \frac{n}{2} \rfloor$），表示集合 $B$ 的元素。

保证所有测试用例中 $n$ 的总和不超过 $10^6$。

## 输出格式

对于每组测试数据，输出一个整数，表示经过任意次操作后，数组 $a$ 所有元素之和的最大值。

## 输入输出样例 #1

### 输入 #1

```
3
6 2
0 6 -2 1 -4 5
1 2
7 1
1 -1 1 -1 1 -1 1
2
5 1
-1000000000 -1000000000 -1000000000 -1000000000 -1000000000
1
```

### 输出 #1

```
18
5
5000000000
```

## 说明/提示

在第一个测试用例中，你可以依次对 $x=1$，$l=3$，$r=3$ 和 $x=1$，$l=5$，$r=5$ 进行操作，数组变为 $[0, 6, 2, 1, 4, 5]$。

在第二个测试用例中，你可以先对 $x=2$，$l=2$，$r=3$ 进行操作，数组变为 $[1, 1, -1, -1, 1, -1, 1]$，再对 $x=2$，$l=3$，$r=4$ 进行操作，数组变为 $[1, 1, 1, 1, 1, -1, 1]$。无法得到比 $5$ 更大的和。

由 ChatGPT 4.1 翻译

---

# CF1630D Flipping Range

## 题目描述

You are given an array $ a $ of $ n $ integers and a set $ B $ of $ m $ positive integers such that $ 1 \leq b_i \leq \lfloor \frac{n}{2} \rfloor $ for $ 1\le i\le m $ , where $ b_i $ is the $ i $ -th element of $ B $ .

You can make the following operation on $ a $ :

1. Select some $ x $ such that $ x $ appears in $ B $ .
2. Select an interval from array $ a $ of size $ x $ and multiply by $ -1 $ every element in the interval. Formally, select $ l $ and $ r $ such that $ 1\leq l\leq r \leq n $ and $ r-l+1=x $ , then assign $ a_i:=-a_i $ for every $ i $ such that $ l\leq i\leq r $ .

Consider the following example, let $ a=[0,6,-2,1,-4,5] $ and $ B=\{1,2\} $ :

1. $ [0,6,-2,-1,4,5] $ is obtained after choosing size $ 2 $ and $ l=4 $ , $ r=5 $ .
2. $ [0,6,2,-1,4,5] $ is obtained after choosing size $ 1 $ and $ l=3 $ , $ r=3 $ .

Find the maximum $ \sum\limits_{i=1}^n {a_i} $ you can get after applying such operation any number of times (possibly zero).

## 输入格式

The input consists of multiple test cases. The first line contains a single integer $ t $ ( $ 1 \le t \le 10^5 $ ) — the number of test cases. Description of the test cases follows.

The first line of each test case contains two integers $ n $ and $ m $ ( $ 2\leq n \leq 10^6 $ , $ 1 \leq m \leq \lfloor \frac{n}{2} \rfloor $ ) — the number of elements of $ a $ and $ B $ respectively.

The second line of each test case contains $ n $ integers $ a_1,a_2,\ldots,a_n $ ( $ -10^9\leq a_i \leq 10^9 $ ).

The third line of each test case contains $ m $ distinct positive integers $ b_1,b_2,\ldots,b_m $ ( $ 1 \leq b_i \leq \lfloor \frac{n}{2} \rfloor $ ) — the elements in the set $ B $ .

It's guaranteed that the sum of $ n $ over all test cases does not exceed $ 10^6 $ .

## 输出格式

For each test case print a single integer — the maximum possible sum of all $ a_i $ after applying such operation any number of times.

## 输入输出样例 #1

### 输入 #1

```
3
6 2
0 6 -2 1 -4 5
1 2
7 1
1 -1 1 -1 1 -1 1
2
5 1
-1000000000 -1000000000 -1000000000 -1000000000 -1000000000
1
```

### 输出 #1

```
18
5
5000000000
```

## 说明/提示

In the first test, you can apply the operation $ x=1 $ , $ l=3 $ , $ r=3 $ , and the operation $ x=1 $ , $ l=5 $ , $ r=5 $ , then the array becomes $ [0, 6, 2, 1, 4, 5] $ .

In the second test, you can apply the operation $ x=2 $ , $ l=2 $ , $ r=3 $ , and the array becomes $ [1, 1, -1, -1, 1, -1, 1] $ , then apply the operation $ x=2 $ , $ l=3 $ , $ r=4 $ , and the array becomes $ [1, 1, 1, 1, 1, -1, 1] $ . There is no way to achieve a sum bigger than $ 5 $ .