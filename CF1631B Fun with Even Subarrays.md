# CF1631B Fun with Even Subarrays

## 题目描述

给定一个长度为 $n$ 的数组 $a$。你可以对其进行如下操作任意次：

- 选择一个长度为偶数 $2k$ 的子数组，该子数组起始于位置 $l$（$1\le l \le l+2k-1\le n$，$k\ge 1$），对于每个 $i$ 满足 $0\le i\le k-1$，将 $a_{l+i}$ 赋值为 $a_{l+k+i}$。

例如，若 $a = [2, 1, 3, 4, 5, 3]$，选择 $l=1$，$k=2$，执行该操作后，数组变为 $a = [3, 4, 3, 4, 5, 3]$。

请你求出最少需要多少次操作（可以为零），才能使数组所有元素都相等。

## 输入格式

输入包含多组测试用例。第一行包含一个整数 $t$（$1\leq t\leq 2\times 10^4$），表示测试用例的数量。接下来是每个测试用例的描述。

每个测试用例的第一行包含一个整数 $n$（$1\leq n\leq 2\times 10^5$），表示数组的长度。

每个测试用例的第二行包含 $n$ 个整数 $a_1, a_2, \dots, a_n$（$1\leq a_i\leq n$），表示数组 $a$ 的元素。

保证所有测试用例中 $n$ 的总和不超过 $2\times 10^5$。

## 输出格式

输出 $t$ 行，每行一个整数，表示使数组所有元素相等所需的最少操作次数。

## 输入输出样例 #1

### 输入 #1

```
5
3
1 1 1
2
2 1
5
4 4 4 2 4
4
4 2 1 3
1
1
```

### 输出 #1

```
0
1
1
2
0
```

## 说明/提示

在第一个测试用例中，所有元素已经相等，因此不需要任何操作。

在第二个测试用例中，你可以执行一次操作，取 $k=1$，$l=1$，将 $a_1 := a_2$，数组变为 $[1, 1]$，共需 $1$ 次操作。

在第三个测试用例中，你可以执行一次操作，取 $k=1$，$l=4$，将 $a_4 := a_5$，数组变为 $[4, 4, 4, 4, 4]$，共需 $1$ 次操作。

在第四个测试用例中，你可以先执行一次操作，取 $k=1$，$l=3$，将 $a_3 := a_4$，数组变为 $[4, 2, 3, 3]$，再执行一次操作，取 $k=2$，$l=1$，将 $a_1 := a_3$，$a_2 := a_4$，数组变为 $[3, 3, 3, 3]$，共需 $2$ 次操作。

在第五个测试用例中，数组只有一个元素，因此不需要任何操作。

由 ChatGPT 4.1 翻译

---

# CF1631B Fun with Even Subarrays

## 题目描述

You are given an array $ a $ of $ n $ elements. You can apply the following operation to it any number of times:

- Select some subarray from $ a $ of even size $ 2k $ that begins at position $ l $ ( $ 1\le l \le l+2\cdot{k}-1\le n $ , $ k \ge 1 $ ) and for each $ i $ between $ 0 $ and $ k-1 $ (inclusive), assign the value $ a_{l+k+i} $ to $ a_{l+i} $ .

For example, if $ a = [2, 1, 3, 4, 5, 3] $ , then choose $ l = 1 $ and $ k = 2 $ , applying this operation the array will become $ a = [3, 4, 3, 4, 5, 3] $ .

Find the minimum number of operations (possibly zero) needed to make all the elements of the array equal.

## 输入格式

The input consists of multiple test cases. The first line contains a single integer $ t $ ( $ 1 \leq t \leq 2 \cdot 10^4 $ ) — the number of test cases. Description of the test cases follows.

The first line of each test case contains an integer $ n $ ( $ 1 \leq n \leq 2 \cdot 10^5 $ ) — the length of the array.

The second line of each test case consists of $ n $ integers $ a_1, a_2, \dots, a_n $ ( $ 1 \leq a_i \leq n $ ) — the elements of the array $ a $ .

It is guaranteed that the sum of $ n $ over all test cases does not exceed $ 2 \cdot 10^5 $ .

## 输出格式

Print $ t $ lines, each line containing the answer to the corresponding test case — the minimum number of operations needed to make equal all the elements of the array with the given operation.

## 输入输出样例 #1

### 输入 #1

```
5
3
1 1 1
2
2 1
5
4 4 4 2 4
4
4 2 1 3
1
1
```

### 输出 #1

```
0
1
1
2
0
```

## 说明/提示

In the first test, all elements are equal, therefore no operations are needed.

In the second test, you can apply one operation with $ k=1 $ and $ l=1 $ , set $ a_1 := a_2 $ , and the array becomes $ [1, 1] $ with $ 1 $ operation.

In the third test, you can apply one operation with $ k=1 $ and $ l=4 $ , set $ a_4 := a_5 $ , and the array becomes $ [4, 4, 4, 4, 4] $ .

In the fourth test, you can apply one operation with $ k=1 $ and $ l=3 $ , set $ a_3 := a_4 $ , and the array becomes $ [4, 2, 3, 3] $ , then you can apply another operation with $ k=2 $ and $ l=1 $ , set $ a_1 := a_3 $ , $ a_2 := a_4 $ , and the array becomes $ [3, 3, 3, 3] $ .

In the fifth test, there is only one element, therefore no operations are needed.