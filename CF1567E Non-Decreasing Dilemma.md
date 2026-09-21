# CF1567E Non-Decreasing Dilemma

## 题目描述

Alice 最近收到了一个数组 $a_1, a_2, \dots, a_n$ 作为生日礼物！她对自己的数组非常自豪，当她把数组展示给朋友 Bob 时，Bob 也为她的礼物感到高兴！

然而，很快 Bob 变得好奇起来，像任何理智的朋友一样，他让 Alice 对她的数组执行 $q$ 次两种类型的操作：

- $1\ x\ y$：将第 $x$ 个元素更新为 $y$（即设置 $a_x = y$）。
- $2\ l\ r$：计算子数组 $[a_l, a_{l+1}, \dots, a_r]$ 中存在多少个非递减子数组。更正式地说，统计有多少对整数 $(p, q)$ 满足 $l \le p \le q \le r$ 且 $a_p \le a_{p+1} \le \dots \le a_{q-1} \le a_q$。

请帮助 Alice 回答 Bob 的所有询问！

## 输入格式

第一行包含两个整数 $n$ 和 $q$（$1 \le n, q \le 2 \cdot 10^5$），分别表示数组的大小和操作的数量。

第二行包含 $n$ 个整数 $a_1, a_2, \dots, a_n$（$1 \le a_i \le 10^9$），表示 Alice 的数组元素。

接下来的 $q$ 行，每行包含三个整数。第 $i$ 行的第一个整数为 $t_i$，表示第 $i$ 次操作的类型（$t_i = 1$ 或 $t_i = 2$）。

如果 $t_i = 1$，接下来的两个整数为 $x_i$ 和 $y_i$（$1 \le x_i \le n$；$1 \le y_i \le 10^9$），表示将第 $x_i$ 个元素更新为 $y_i$（即 $a_{x_i} = y_i$）。

如果 $t_i = 2$，接下来的两个整数为 $l_i$ 和 $r_i$（$1 \le l_i \le r_i \le n$），表示 Bob 在第 $i$ 次询问中询问的两个下标。

保证至少有一次第二种类型的操作。

## 输出格式

对于每个类型为 $2$ 的询问，输出一个整数，表示该询问的答案。

## 输入输出样例 #1

### 输入 #1

```
5 6
3 1 4 1 5
2 2 5
2 1 3
1 4 4
2 2 5
1 2 6
2 2 5
```

### 输出 #1

```
6
4
10
7
```

## 说明/提示

对于第一个询问，$l = 2$ 且 $r = 5$，非递减子数组 $[p, q]$ 有 $[2,2]$、$[3,3]$、$[4,4]$、$[5,5]$、$[2,3]$ 和 $[4,5]$。

由 ChatGPT 4.1 翻译

---

# CF1567E Non-Decreasing Dilemma

## 题目描述

Alice has recently received an array $ a_1, a_2, \dots, a_n $ for her birthday! She is very proud of her array, and when she showed her friend Bob the array, he was very happy with her present too!

However, soon Bob became curious, and as any sane friend would do, asked Alice to perform $ q $ operations of two types on her array:

- $ 1 $ $ x $ $ y $ : update the element $ a_x $ to $ y $ (set $ a_x = y $ ).
- $ 2 $ $ l $ $ r $ : calculate how many non-decreasing subarrays exist within the subarray $ [a_l, a_{l+1}, \dots, a_r] $ . More formally, count the number of pairs of integers $ (p,q) $ such that $ l \le p \le q \le r $ and $ a_p \le a_{p+1} \le \dots \le a_{q-1} \le a_q $ .

Help Alice answer Bob's queries!

## 输入格式

The first line contains two integers $ n $ and $ q $ ( $ 1 \le n, q \le 2 \cdot 10^5 $ ) — the size of the array, and the number of queries, respectively.

The second line contains $ n $ integers $ a_1, a_2, \dots, a_n $ ( $ 1 \le a_i \le 10^9 $ ) — the elements of Alice's array.

The next $ q $ lines consist of three integers each. The first integer of the $ i $ -th line is $ t_i $ , the operation being performed on the $ i $ -th step ( $ t_i = 1 $ or $ t_i = 2 $ ).

If $ t_i = 1 $ , the next two integers are $ x_i $ and $ y_i $ ( $ 1 \le x_i \le n $ ; $ 1 \le y_i \le 10^9 $ ), updating the element at position $ x_i $ to $ y_i $ (setting $ a_{x_i} = y_i $ ).

If $ t_i = 2 $ , the next two integers are $ l_i $ and $ r_i $ ( $ 1 \le l_i \le r_i \le n $ ), the two indices Bob asks Alice about for the $ i $ -th query.

It's guaranteed that there is at least one operation of the second type.

## 输出格式

For each query of type $ 2 $ , print a single integer, the answer to the query.

## 输入输出样例 #1

### 输入 #1

```
5 6
3 1 4 1 5
2 2 5
2 1 3
1 4 4
2 2 5
1 2 6
2 2 5
```

### 输出 #1

```
6
4
10
7
```

## 说明/提示

For the first query, $ l = 2 $ and $ r = 5 $ , and the non-decreasing subarrays $ [p,q] $ are $ [2,2] $ , $ [3,3] $ , $ [4,4] $ , $ [5,5] $ , $ [2,3] $ and $ [4,5] $ .