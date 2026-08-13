# P3509 [POI 2010] ZAB-Frog

## 题目描述

在一个特别长且笔直的 Byteotian 小溪的河床上，有 $n$ 块石头露出水面。它们距离小溪源头的距离分别为 $p_1 < p_2 < \cdots < p_n$。一只小青蛙正坐在其中一块石头上，准备开始它的跳跃训练。每次青蛙跳跃到距离它所在石头第 $k$ 近的石头上。具体来说，如果青蛙坐在位置 $p_i$ 的石头上，那么它将跳到这样的 $p_j$ 上，使得：

$$
|\{ p_a : |p _ a - p _ i| < |p_j - p_i| \}| \le k \text{ and } |\{ p_a : |p _ a - p _ i| \le |p_j - p_i| \}| > k
$$

如果 $p_j$ 不是唯一的，那么青蛙在其中选择距离源头最近的石头。对于每一块石头分别计算，若青蛙从这块石头开始跳跃，经过 $m$ 次跳跃后最终会停留在哪一块石头上？

## 输入格式

标准输入的第一行包含三个整数 $n$、$k$ 和 $m$（$1 \le k < n \le 10^6, 1 \le m \le 10^{18}$），用空格分隔，分别表示石头的数量、参数 $k$ 和计划跳跃的次数。第二行包含 $n$ 个整数 $p_j$（$1 \le p_1 < p_2 < \cdots < p_n \le 10^{18}$），用空格分隔，表示小溪河床上连续石头的位置。

## 输出格式

你的程序应在标准输出上打印一行，包含 $n$ 个整数 $r_1, r_2, \cdots, r_n$，用空格分隔。数字 $r_i$ 表示从输入顺序中的第 $i$ 块石头开始跳跃 $m$ 次后，青蛙最终停留的石头编号。

## 输入输出样例 #1

### 输入 #1

```
5 2 4
1 2 4 7 10
```

### 输出 #1

```
1 1 3 1 1
```

## 说明/提示

### 样例 #1 解释：

![](https://cdn.luogu.com.cn/upload/image_hosting/yyilx2mp.png)

图中展示了青蛙从每块石头跳跃（单次跳跃）到的位置。

题面翻译由 ChatGPT-4o 提供。

---

# P3509 [POI 2010] ZAB-Frog

## 题目描述

On the bed of one particularly long and straight Byteotian brook there lie $n$ rocks jutting above the water level. Their distances from the brook's spring are $p_1 < p_2 < \cdots < p_n$ respectively. A small frog sitting on one of these is about to begin its leaping training. Each time the frog leaps to the rock that is the -th closest to the one it is sitting on. Specifically, if the frog is sitting on the rock at position $p_i$, then it will leap onto such $p_j$ that:
$$
|\{ p_a : |p _ a - p _ i| < |p_j - p_i| \}| \le k \text{ and } |\{ p_a : |p _ a - p _ i| \le |p_j - p_i| \}| > k
$$
If $p_j$ is not unique, then the frog chooses among them the rock that is closest to the spring. On which rock the frog will be sitting after $m$ leaps depending on the rock is started from?

## 输入格式

The first line of the standard input holds three integers, $n$, $k$ and $m$ ($1 \le k < n \le 1 \, 000 \, 000, 1 \le m \le 10^{18}$), separated by single spaces, that denote respectively: the number of rocks, the parameter $k$, and the number of intended leaps. The second line holds $n$ integers $p_j$ ($1 \le p_1 < p_2 < \cdots < p_n \le 10^{18}$), separated by single spaces, that denote the positions of successive rocks on the bed of the brook.

## 输出格式

Your program should print a single line on the standard output, with $n$ integers $r_1, r_2, \cdots, r_n$ from the interval $[1, n]$ in it, separated by single spaces. The number $r_i$ denotes the number of the rock that the frog ends on after making $m$ leaps starting from the rock no. $i$ (in the input order).

## 输入输出样例 #1

### 输入 #1

```
5 2 4
1 2 4 7 10
```

### 输出 #1

```
1 1 3 1 1
```

## 说明/提示

### 样例 #1 解释：

![](https://cdn.luogu.com.cn/upload/image_hosting/yyilx2mp.png)

The figure presents where the frog leaps to (in a single leap) from each and every rock.