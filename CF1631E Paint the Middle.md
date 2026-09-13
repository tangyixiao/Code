# CF1631E Paint the Middle

## 题目描述

给定 $n$ 个元素，编号从 $1$ 到 $n$，第 $i$ 个元素的值为 $a_i$，颜色为 $c_i$，初始时所有 $c_i = 0$。

可以进行如下操作：

- 选择三个元素 $i$、$j$ 和 $k$（$1 \leq i < j < k \leq n$），要求 $c_i$、$c_j$ 和 $c_k$ 都等于 $0$，且 $a_i = a_k$，然后将 $c_j$ 设为 $1$。

请你求出经过任意次操作后，$\sum\limits_{i=1}^n{c_i}$ 的最大值。

## 输入格式

第一行包含一个整数 $n$（$3 \leq n \leq 2 \cdot 10^5$）——元素的数量。

第二行包含 $n$ 个整数 $a_1, a_2, \dots, a_n$（$1 \leq a_i \leq n$），其中 $a_i$ 表示第 $i$ 个元素的值。

## 输出格式

输出一行，一个整数，表示经过任意次操作后，$\sum\limits_{i=1}^n{c_i}$ 的最大值。

## 输入输出样例 #1

### 输入 #1

```
7
1 2 1 2 7 4 7
```

### 输出 #1

```
2
```

## 输入输出样例 #2

### 输入 #2

```
13
1 2 3 2 1 3 3 4 5 5 5 4 7
```

### 输出 #2

```
7
```

## 说明/提示

在第一个测试样例中，可以按如下顺序进行操作：

![](https://cdn.luogu.com.cn/upload/vjudge_pic/CF1630C/7c496bb097d511fd66adf529c361a9334d75c9e9.png)

由 ChatGPT 4.1 翻译

---

# CF1630C Paint the Middle

## 题目描述

You are given $ n $ elements numbered from $ 1 $ to $ n $ , the element $ i $ has value $ a_i $ and color $ c_i $ , initially, $ c_i = 0 $ for all $ i $ .

The following operation can be applied:

- Select three elements $ i $ , $ j $ and $ k $ ( $ 1 \leq i < j < k \leq n $ ), such that $ c_i $ , $ c_j $ and $ c_k $ are all equal to $ 0 $ and $ a_i = a_k $ , then set $ c_j = 1 $ .

Find the maximum value of $ \sum\limits_{i=1}^n{c_i} $ that can be obtained after applying the given operation any number of times.

## 输入格式

The first line contains an integer $ n $ ( $ 3 \leq n \leq 2 \cdot 10^5 $ ) — the number of elements.

The second line consists of $ n $ integers $ a_1, a_2, \dots, a_n $ ( $ 1 \leq a_i \leq n $ ), where $ a_i $ is the value of the $ i $ -th element.

## 输出格式

Print a single integer in a line — the maximum value of $ \sum\limits_{i=1}^n{c_i} $ that can be obtained after applying the given operation any number of times.

## 输入输出样例 #1

### 输入 #1

```
7
1 2 1 2 7 4 7
```

### 输出 #1

```
2
```

## 输入输出样例 #2

### 输入 #2

```
13
1 2 3 2 1 3 3 4 5 5 5 4 7
```

### 输出 #2

```
7
```

## 说明/提示

In the first test, it is possible to apply the following operations in order:

 ![](https://cdn.luogu.com.cn/upload/vjudge_pic/CF1630C/7c496bb097d511fd66adf529c361a9334d75c9e9.png)