# CF1528B Kavi on Pairing Duty

## 题目描述

Kavi 有 $2n$ 个点，这些点都位于 $OX$ 轴上，第 $i$ 个点的位置为 $x = i$。

Kavi 考虑将这 $2n$ 个点分成 $n$ 对的所有方式。在这些方式中，他对“好配对”感兴趣，定义如下：

考虑 $n$ 条线段，每条线段的两个端点分别是每一对中的两个点。如果对于任意两条不同的线段 $A$ 和 $B$，至少满足以下条件之一，则该配对被称为“好配对”：

- 其中一条线段完全包含在另一条线段内部。
- $A$ 和 $B$ 的长度相等。

请看以下示例：

![](https://cdn.luogu.com.cn/upload/vjudge_pic/CF1528B/41a58a6a051949b924acfc162dd6465703f68210.png) $A$ 是一个好配对，因为红色线段完全包含在蓝色线段内部。

$B$ 是一个好配对，因为红色和蓝色线段长度相等。

$C$ 不是好配对，因为红色和蓝色线段既不互相包含，也长度不相等。

Kavi 想知道好配对的数量。由于答案可能很大，请输出对 $998244353$ 取模后的结果。

如果某两个点在某种配对中被分到同一对，而在另一种配对中被分到不同的对，则这两种配对被认为是不同的。

## 输入格式

输入包含一行，一个整数 $n$，满足 $1 \le n \le 10^6$。

## 输出格式

输出一个整数，表示好配对的数量，对 $998244353$ 取模。

## 输入输出样例 #1

### 输入 #1

```
1
```

### 输出 #1

```
1
```

## 输入输出样例 #2

### 输入 #2

```
2
```

### 输出 #2

```
3
```

## 输入输出样例 #3

### 输入 #3

```
3
```

### 输出 #3

```
6
```

## 输入输出样例 #4

### 输入 #4

```
100
```

### 输出 #4

```
688750769
```

## 说明/提示

对于第二个样例，好配对如下：

![](https://cdn.luogu.com.cn/upload/vjudge_pic/CF1528B/26cefe71c208095e0e610c498701d052b950b5a2.png)

对于第三个样例，好配对如下：

![](https://cdn.luogu.com.cn/upload/vjudge_pic/CF1528B/4bfe3f3beac587d75fee5d30f6490c2823b90e1d.png)

由 ChatGPT 4.1 翻译

---

# CF1528B Kavi on Pairing Duty

## 题目描述

Kavi has $ 2n $ points lying on the $ OX $ axis, $ i $ -th of which is located at $ x = i $ .

Kavi considers all ways to split these $ 2n $ points into $ n $ pairs. Among those, he is interested in good pairings, which are defined as follows:

Consider $ n $ segments with ends at the points in correspondent pairs. The pairing is called good, if for every $ 2 $ different segments $ A $ and $ B $ among those, at least one of the following holds:

- One of the segments $ A $ and $ B $ lies completely inside the other.
- $ A $ and $ B $ have the same length.

Consider the following example:

 ![](https://cdn.luogu.com.cn/upload/vjudge_pic/CF1528B/41a58a6a051949b924acfc162dd6465703f68210.png) $ A $ is a good pairing since the red segment lies completely inside the blue segment.

 $ B $ is a good pairing since the red and the blue segment have the same length.

 $ C $ is not a good pairing since none of the red or blue segments lies inside the other, neither do they have the same size.

Kavi is interested in the number of good pairings, so he wants you to find it for him. As the result can be large, find this number modulo $ 998244353 $ .

Two pairings are called different, if some two points are in one pair in some pairing and in different pairs in another.

## 输入格式

The single line of the input contains a single integer $ n $ $ (1\le n \le 10^6) $ .

## 输出格式

Print the number of good pairings modulo $ 998244353 $ .

## 输入输出样例 #1

### 输入 #1

```
1
```

### 输出 #1

```
1
```

## 输入输出样例 #2

### 输入 #2

```
2
```

### 输出 #2

```
3
```

## 输入输出样例 #3

### 输入 #3

```
3
```

### 输出 #3

```
6
```

## 输入输出样例 #4

### 输入 #4

```
100
```

### 输出 #4

```
688750769
```

## 说明/提示

The good pairings for the second example are:

 ![](https://cdn.luogu.com.cn/upload/vjudge_pic/CF1528B/26cefe71c208095e0e610c498701d052b950b5a2.png)In the third example, the good pairings are:

 ![](https://cdn.luogu.com.cn/upload/vjudge_pic/CF1528B/4bfe3f3beac587d75fee5d30f6490c2823b90e1d.png)