# P3602 Koishi Loves Segments

## 题目描述

Koishi 喜欢线段。

她的 $n$ 条线段都能表示成数轴上的某个闭区间 $[l,r]$。Koishi 喜欢在把所有线段都放在数轴上，然后数出某些点被多少线段覆盖了。

Flandre 看她和线段玩得很开心，就抛给她一个问题：

数轴上有 $m$ 个点突然兴奋，如果自己被身上覆盖了超过 $x$ 条线段，这个点就会浑身难受然后把 Koishi 批判一番。

Koishi 十分善良，为了不让数轴上的点浑身难受，也为了让自己开心，她想在数轴上放入尽量多的线段。

按照套路，Koishi 假装自己并不会做这道题，所以她就来求你帮忙。并承诺如果你解决了问题就给你打一通电话。

## 输入格式

第一行两个整数 $n,m$，分别表示插入的线段数和关键点数。

接下来 $n$ 行，每行两个整数 $l,r(l\leq r)$，表示线段 $[l,r]$ 的端点。

接下来 $m$ 行，每行两个整数 $p,x$，表示有个位于 $p$ 的点突然兴奋，并认为自己身上不得覆盖超过 $x$ 条线段。

## 输出格式

一个整数，表示最多能放入的线段数。

## 输入输出样例 #1

### 输入 #1

```
4 3
1 3
2 4
5 7
6 8
2 5
3 1
6 2
```

### 输出 #1

```
3
```

## 说明/提示

对于 $20\%$ 的数据，满足 $1\leq n,m\leq 20$。

对于 $60\%$ 的数据，满足 $1\leq n,m\leq 100$。

对于 $80\%$的数据，满足 $1\leq n,m\leq 5000$。

对于 $100\%$ 的数据，满足 $1\leq x\leq n\leq 2\times 10^5,1\leq m\leq 4\times 10^5,|l|,|r|,|p|\leq 10^7$

如果一个点兴奋了两次，那么 Koishi 应当满足它的**较严苛的要求**（也就是 $p$ 相同时 $x$ 取最小值啦）

请适当使用读入优化。

---

# P3602 Koishi Loves Segments

## 题目描述

Koishi likes segments.

Each of her $n$ segments can be represented as a closed interval $[l, r]$ on the number line. Koishi likes to put all the segments on the number line and then count how many segments cover certain points.

Seeing how happily she plays with segments, Flandre throws her a problem:

There are $m$ points on the number line that suddenly get excited. If a point is covered by more than $x$ segments, it will feel terrible and criticize Koishi.

Koishi is very kind. To avoid making the points feel bad and to make herself happy, she wants to place as many segments on the number line as possible.

As usual, Koishi pretends she cannot solve this problem, so she asks you for help, and promises to give you a phone call if you solve it.

## 输入格式

The first line contains two integers $n, m$, denoting the number of segments to insert and the number of excited points.

Each of the next $n$ lines contains two integers $l, r$ ($l \le r$), denoting the endpoints of a segment $[l, r]$.

Each of the next $m$ lines contains two integers $p, x$, meaning that the point at position $p$ gets excited and requires that it should not be covered by more than $x$ segments.

## 输出格式

Output a single integer, denoting the maximum number of segments that can be placed.

## 输入输出样例 #1

### 输入 #1

```
4 3
1 3
2 4
5 7
6 8
2 5
3 1
6 2
```

### 输出 #1

```
3
```

## 说明/提示

- For 20% of the testdata, $1 \le n, m \le 20$.
- For 60% of the testdata, $1 \le n, m \le 100$.
- For 80% of the testdata, $1 \le n, m \le 5000$.
- Constraints: $1 \le x \le n \le 2\times 10^5$, $1 \le m \le 4\times 10^5$, $|l|, |r|, |p| \le 10^7$.
- If a point gets excited multiple times, Koishi should satisfy its stricter requirement (i.e., when $p$ is the same, take the minimum $x$).
- Please use fast I/O appropriately.

Translated by ChatGPT 5