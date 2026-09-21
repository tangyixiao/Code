# CF1567B MEXor Mixup

## 题目描述

给你两个数字 $a$，$b$，问使得一个非负整数数组的 $\operatorname{MEX}$ 为 $a$ ，数组内所有数的 $\operatorname{XOR}$ 为 $b$ 的最短长度。

称不属于该数组的最小非负整数为该数组的 $\operatorname{MEX}$ ，数组的 $\operatorname{XOR}$ 为数组所有元素的按位异或。

## 输入格式

多组数据。

第一行一个 $t$ ，表示数据组数。

接下来每组数据包含两个整数 $a$ 和 $b$ 。

## 输出格式

对于每一组数据，输出一个数表示所能构成的最短长度。

## 输入输出样例 #1

### 输入 #1

```
5
1 1
2 1
2 0
1 10000
2 10000
```

### 输出 #1

```
3
2
3
2
3
```

## 说明/提示

$1\leq t \leq 5\cdot10^5,1\leq  a \leq 3\cdot10^5,0\leq b\leq 3\cdot10^5$

译者：@smyslenny

---

# CF1567B MEXor Mixup

## 题目描述

Alice gave Bob two integers $ a $ and $ b $ ( $ a > 0 $ and $ b \ge 0 $ ). Being a curious boy, Bob wrote down an array of non-negative integers with $ \operatorname{MEX} $ value of all elements equal to $ a $ and $ \operatorname{XOR} $ value of all elements equal to $ b $ .

What is the shortest possible length of the array Bob wrote?

Recall that the $ \operatorname{MEX} $ (<a>Minimum EXcluded</a>) of an array is the minimum non-negative integer that does not belong to the array and the $ \operatorname{XOR} $ of an array is the [bitwise XOR](https://en.wikipedia.org/wiki/Bitwise_operation#XOR) of all the elements of the array.

## 输入格式

The input consists of multiple test cases. The first line contains an integer $ t $ ( $ 1 \leq t \leq 5 \cdot 10^4 $ ) — the number of test cases. The description of the test cases follows.

The only line of each test case contains two integers $ a $ and $ b $ ( $ 1 \leq a \leq 3 \cdot 10^5 $ ; $ 0 \leq b \leq 3 \cdot 10^5 $ ) — the $ \operatorname{MEX} $ and $ \operatorname{XOR} $ of the array, respectively.

## 输出格式

For each test case, output one (positive) integer — the length of the shortest array with $ \operatorname{MEX} $ $ a $ and $ \operatorname{XOR} $ $ b $ . We can show that such an array always exists.

## 输入输出样例 #1

### 输入 #1

```
5
1 1
2 1
2 0
1 10000
2 10000
```

### 输出 #1

```
3
2
3
2
3
```

## 说明/提示

In the first test case, one of the shortest arrays with $ \operatorname{MEX} $ $ 1 $ and $ \operatorname{XOR} $ $ 1 $ is $ [0, 2020, 2021] $ .

In the second test case, one of the shortest arrays with $ \operatorname{MEX} $ $ 2 $ and $ \operatorname{XOR} $ $ 1 $ is $ [0, 1] $ .

It can be shown that these arrays are the shortest arrays possible.