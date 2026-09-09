# CF1631D Range and Partition

## 题目描述

给定一个长度为 $n$ 的整数数组 $a$，请你找到一个取值范围 $[x, y]$（$x \le y$），并将 $a$ 恰好划分为 $k$ 个子数组（$1 \le k \le n$），使得：

- 每个子数组由 $a$ 的若干连续元素组成，即对于某些 $l$ 和 $r$（$1 \leq l \leq r \leq n$），子数组为 $a_l, a_{l+1}, \ldots, a_r$。
- 每个元素恰好属于一个子数组。
- 在每个子数组中，属于区间 $[x, y]$（包含端点）的元素个数严格大于不属于该区间的元素个数。下标为 $i$ 的元素属于区间 $[x, y]$ 当且仅当 $x \le a_i \le y$。

请输出任意一个使 $y - x$ 最小的方案。

## 输入格式

输入包含多组测试数据。第一行为一个整数 $t$（$1 \leq t \leq 3 \cdot 10^4$），表示测试数据的组数。接下来是每组测试数据的描述。

每组测试数据的第一行包含两个整数 $n$ 和 $k$（$1 \le k \le n \le 2 \cdot 10^5$），表示数组 $a$ 的长度和需要划分的子数组个数。

第二行包含 $n$ 个整数 $a_1, a_2, \ldots, a_n$（$1 \le a_i \le n$），表示数组 $a$ 的元素。

保证所有测试数据中 $n$ 的总和不超过 $2\cdot10^5$。

## 输出格式

对于每组测试数据，输出 $k+1$ 行。

第一行输出 $x$ 和 $y$，表示找到的区间范围。

接下来的 $k$ 行，每行输出 $l_i$ 和 $r_i$（$1\leq l_i \leq r_i \leq n$），表示第 $i$ 个子数组的区间。

子数组的输出顺序可以任意。

## 输入输出样例 #1

### 输入 #1

```
3
2 1
1 2
4 2
1 2 2 2
11 3
5 5 5 1 5 5 1 5 5 5 1
```

### 输出 #1

```
1 2
1 2
2 2
1 3
4 4
5 5
1 1
2 2
3 11
```

## 说明/提示

在第一个测试样例中，只能有一个子数组，必须等于整个数组。如果选择区间 $[1, 2]$，则区间内有 $2$ 个元素，区间外有 $0$ 个元素；如果选择区间 $[1, 1]$，则区间内有 $1$ 个元素（$a_1$），区间外有 $1$ 个元素（$a_2$），此时答案不合法。

在第二个测试样例中，可以选择区间 $[2, 2]$，并将数组划分为子数组 $(1, 3)$ 和 $(4, 4)$。在子数组 $(1, 3)$ 中，区间内有 $2$ 个元素（$a_2$ 和 $a_3$），区间外有 $1$ 个元素（$a_1$）；在子数组 $(4, 4)$ 中，只有 $1$ 个元素，且属于区间内。

在第三个测试样例中，可以选择区间 $[5, 5]$，并将数组划分为子数组 $(1, 4)$、$(5, 7)$ 和 $(8, 11)$。在子数组 $(1, 4)$ 中，区间内有 $3$ 个元素，区间外有 $1$ 个元素；在子数组 $(5, 7)$ 中，区间内有 $2$ 个元素，区间外有 $1$ 个元素；在子数组 $(8, 11)$ 中，区间内有 $3$ 个元素，区间外有 $1$ 个元素。

由 ChatGPT 4.1 翻译

---

# CF1630B Range and Partition

## 题目描述

Given an array $ a $ of $ n $ integers, find a range of values $ [x, y] $ ( $ x \le y $ ), and split $ a $ into exactly $ k $ ( $ 1 \le k \le n $ ) subarrays in such a way that:

- Each subarray is formed by several continuous elements of $ a $ , that is, it is equal to $ a_l, a_{l+1}, \ldots, a_r $ for some $ l $ and $ r $ ( $ 1 \leq l \leq r \leq n $ ).
- Each element from $ a $ belongs to exactly one subarray.
- In each subarray the number of elements inside the range $ [x, y] $ (inclusive) is strictly greater than the number of elements outside the range. An element with index $ i $ is inside the range $ [x, y] $ if and only if $ x \le a_i \le y $ .

Print any solution that minimizes $ y - x $ .

## 输入格式

The input consists of multiple test cases. The first line contains a single integer $ t $ ( $ 1 \leq t \leq 3 \cdot 10^4 $ ) — the number of test cases. Description of the test cases follows.

The first line of each test case contains two integers $ n $ and $ k $ ( $ 1 \le k \le n \le 2 \cdot 10^5 $ ) — the length of the array $ a $ and the number of subarrays required in the partition.

The second line of each test case contains $ n $ integers $ a_1, a_2, \ldots, a_n $ ( $ 1 \le a_i \le n $ ) where $ a_i $ is the $ i $ -th element of the array.

It is guaranteed that the sum of $ n $ over all test cases does not exceed $ 2\cdot10^5 $ .

## 输出格式

For each test case, print $ k+1 $ lines.

In the first line, print $ x $ and $ y $ — the limits of the found range.

Then print $ k $ lines, the $ i $ -th should contain $ l_i $ and $ r_i $ ( $ 1\leq l_i \leq r_i \leq n $ ) — the limits of the $ i $ -th subarray.

You can print the subarrays in any order.

## 输入输出样例 #1

### 输入 #1

```
3
2 1
1 2
4 2
1 2 2 2
11 3
5 5 5 1 5 5 1 5 5 5 1
```

### 输出 #1

```
1 2
1 2
2 2
1 3
4 4
5 5
1 1
2 2
3 11
```

## 说明/提示

In the first test, there should be only one subarray, which must be equal to the whole array. There are $ 2 $ elements inside the range $ [1, 2] $ and $ 0 $ elements outside, if the chosen range is $ [1, 1] $ , there will be $ 1 $ element inside ( $ a_1 $ ) and $ 1 $ element outside ( $ a_2 $ ), and the answer will be invalid.

In the second test, it is possible to choose the range $ [2, 2] $ , and split the array in subarrays $ (1, 3) $ and $ (4, 4) $ , in subarray $ (1, 3) $ there are $ 2 $ elements inside the range ( $ a_2 $ and $ a_3 $ ) and $ 1 $ element outside ( $ a_1 $ ), in subarray $ (4, 4) $ there is only $ 1 $ element ( $ a_4 $ ), and it is inside the range.

In the third test, it is possible to choose the range $ [5, 5] $ , and split the array in subarrays $ (1, 4) $ , $ (5, 7) $ and $ (8, 11) $ , in the subarray $ (1, 4) $ there are $ 3 $ elements inside the range and $ 1 $ element outside, in the subarray $ (5, 7) $ there are $ 2 $ elements inside and $ 1 $ element outside and in the subarray $ (8, 11) $ there are $ 3 $ elements inside and $ 1 $ element outside.