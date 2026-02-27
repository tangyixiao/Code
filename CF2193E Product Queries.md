# CF2193E Product Queries

## 题目描述

今天，Sabyrzhan 被叫到黑板前，面对一个长度为 $ n $ 的数组 $ a $，并被布置了一项任务——回答 $ n $ 个问题。

在第 $ i $ 个问题中，需要确定从黑板上最少选择多少个数组元素（允许重复使用同一个元素），使得它们的乘积恰好等于 $ i $，或者报告无法达到这样的乘积。

注意：至少必须选择一个元素。

## 输入格式

每个测试包含多个测试用例。第一行包含一个整数 $ t $（$ 1 \le t \le 10^4 $）——测试用例的数量。接下来是测试用例的描述。

每个测试用例的第一行包含一个整数 $ n $（$ 1 \le n \le 3 \cdot 10 ^ 5 $）。

每个测试用例的第二行包含 $ n $ 个整数 $ a_1, a_2, \ldots, a_n $（$ 1 \le a_i \le n $）。

保证所有测试用例中 $ n $ 的总和不超过 $ 3 \cdot 10 ^ 5 $。

## 输出格式

对于第 $ i $ 个问题，输出一个整数——为获得乘积等于 $ i $ 所需的最少数组元素数量，如果无法达到这样的乘积，则输出 $ −1 $。

## 输入输出样例 #1

### 输入 #1

```
6
8
3 2 2 3 7 3 6 7
5
1 2 3 4 5
3
1 1 1
10
2 1 2 1 3 5 5 7 7 7
4
1 1 2 2
1
1
```

### 输出 #1

```
-1 1 1 2 -1 1 1 3
1 1 1 1 1
1 -1 -1
1 1 1 2 1 2 1 3 2 2
1 1 -1 2
1
```

## 说明/提示

考虑第一个测试用例。乘积可以按如下方式获得：

- $ 1 $ 无法获得。
- $ 2 $ 可以通过选择 $ a_2 $ 获得。
- $ 3 $ 可以通过选择 $ a_1 $ 获得。
- $ 4 $ 可以通过选择 $ a_2 $ 两次获得。
- $ 5 $ 无法获得。
- $ 6 $ 可以通过选择 $ a_7 $ 获得。
- $ 7 $ 可以通过选择 $ a_5 $ 获得。
- $ 8 $ 可以通过选择 $ a_2 $ 三次获得。

由 deepseek v3 翻译完成

---

# CF2193E Product Queries

## 题目描述

Today, Sabyrzhan was called to the board with an array  $ a $  of length  $ n $  and was assigned an officer's task — to answer  $ n $  questions.

In the  $ i $ -th question, it is required to determine the minimum number of elements from the array that need to be selected from the board (it is allowed to use the same element multiple times) so that their product is exactly equal to  $ i $ , or to report that it is impossible to achieve such a product.

Note that at least one element must be selected.

## 输入格式

Each test consists of several test cases. The first line contains one integer  $ t $  ( $ 1 \le t \le 10^4 $ ) — the number of test cases. The description of the test cases follows.

The first line of each test case contains one integer  $ n $  ( $ 1 \le n \le 3 \cdot 10 ^ 5 $ ).

The second line of each test case contains  $ n $  integers  $ a_1, a_2, \ldots, a_n $  ( $ 1 \le a_i \le n $ ).

It is guaranteed that the sum of the values of  $ n $  across all test cases does not exceed  $ 3 \cdot 10 ^ 5 $ .

## 输出格式

For the  $ i $ -th question, output one integer — the minimum number of elements from the array required to obtain a product equal to  $ i $ , or  $ −1 $  if it is impossible to achieve such a product.

## 输入输出样例 #1

### 输入 #1

```
6
8
3 2 2 3 7 3 6 7
5
1 2 3 4 5
3
1 1 1
10
2 1 2 1 3 5 5 7 7 7
4
1 1 2 2
1
1
```

### 输出 #1

```
-1 1 1 2 -1 1 1 3
1 1 1 1 1
1 -1 -1
1 1 1 2 1 2 1 3 2 2
1 1 -1 2
1
```

## 说明/提示

Consider the first test case. The products can be obtained as follows:

- $ 1 $  cannot be obtained.
- $ 2 $  can be obtained by selecting  $ a_2 $ .
- $ 3 $  can be obtained by selecting  $ a_1 $ .
- $ 4 $  can be obtained by selecting  $ a_2 $  twice.
- $ 5 $  cannot be obtained.
- $ 6 $  can be obtained by selecting  $ a_7 $ .
- $ 7 $  can be obtained by selecting  $ a_5 $ .
- $ 8 $  can be obtained by selecting  $ a_2 $  three times.