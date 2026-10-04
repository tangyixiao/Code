# CF768B Code For 1

## 题目描述

琼恩英勇奋战，营救了在硬家堡被异鬼袭击的野人。回到黑城堡后，山姆告诉他自己想去旧镇，在“学城”接受训练，成为一名学士，这样他就能回来接替已逝艾蒙的位置，成为黑城堡的学士。琼恩同意了山姆的请求，于是山姆踏上了前往学城的旅途。然而，想成为学城的学徒并非易事，因此学士们给了山姆一道难题，用来测试他的资格。

起初，山姆手上有一个只包含一个元素 $n$ 的列表。然后，他需要对该列表进行若干操作。在每次操作中，山姆必须从列表中移除任意满足 $x>1$ 的元素 $x$，并在原位置依次插入 $[\left\lfloor \frac{x}{2} \right\rfloor,\, x\bmod 2,\, \left\lfloor \frac{x}{2} \right\rfloor]$。他需要重复以上操作，直到列表中的所有元素都是 $0$ 或 $1$。

现在，学士们想知道最终列表中第 $l$ 到第 $r$ 位（$1$-索引）中 $1$ 的总数。山姆想成为学士，但不幸的是他解不出这道题。你能帮助山姆通过资格测试吗？

## 输入格式

第一行包含三个整数 $n$、$l$、$r$（$0 \leq n < 2^{50}$，$0 \leq r-l \leq 10^{5}$，$r \geq 1$，$l \geq 1$）——初始元素以及查询区间 $l$ 到 $r$。

保证 $r$ 不大于最终列表的长度。

## 输出格式

输出在最终序列的 $l$ 到 $r$ 区间中 $1$ 的总数。

## 输入输出样例 #1

### 输入 #1

```
7 2 5

```

### 输出 #1

```
4

```

## 输入输出样例 #2

### 输入 #2

```
10 3 10

```

### 输出 #2

```
5

```

## 说明/提示

考虑第一个样例：

最终序列为 $[1,1,1,1,1,1,1]$。

列表第 $2$ 到第 $5$ 位的元素为 $[1,1,1,1]$。$1$ 的个数为 $4$。

对于第二个样例：

最终序列为 $[1,0,1,1,1,0,1,0,1,0,1,1,1,0,1]$。

列表第 $3$ 到第 $10$ 位的元素为 $[1,1,1,0,1,0,1,0]$。$1$ 的个数为 $5$。

由 ChatGPT 5 翻译

---

# CF768B Code For 1

## 题目描述

Jon fought bravely to rescue the wildlings who were attacked by the white-walkers at Hardhome. On his arrival, Sam tells him that he wants to go to Oldtown to train at the Citadel to become a maester, so he can return and take the deceased Aemon's place as maester of Castle Black. Jon agrees to Sam's proposal and Sam sets off his journey to the Citadel. However becoming a trainee at the Citadel is not a cakewalk and hence the maesters at the Citadel gave Sam a problem to test his eligibility.

Initially Sam has a list with a single element $n$. Then he has to perform certain operations on this list. In each operation Sam must remove any element $x$, such that $x > 1$, from the list and insert at the same position $\lfloor \frac{x}{2} \rfloor$, $x \bmod 2$, $\lfloor \frac{x}{2} \rfloor$ sequentially. He must continue with these operations until all the elements in the list are either $0$ or $1$.

Now the masters want the total number of $1$s in the range $l$ to $r$ ($1$-indexed). Sam wants to become a maester but unfortunately he cannot solve this problem. Can you help Sam to pass the eligibility test?

## 输入格式

The first line contains three integers $n$, $l$, $r$ ($0 \le n < 2^{50}$, $0 \le r - l \le 10^{5}$, $r \ge 1$, $l \ge 1$) – initial element and the range $l$ to $r$.

It is guaranteed that $r$ is not greater than the length of the final list.

## 输出格式

Output the total number of $ 1 $ s in the range $ l $ to $ r $ in the final sequence.

## 输入输出样例 #1

### 输入 #1

```
7 2 5

```

### 输出 #1

```
4

```

## 输入输出样例 #2

### 输入 #2

```
10 3 10

```

### 输出 #2

```
5

```

## 说明/提示

Consider first example:
$[1,1,1,1,1,1,1]$


Elements on positions from $ 2 $ -nd to $ 5 $ -th in list is $ [1,1,1,1] $ . The number of ones is $ 4 $ .

For the second example:

$[1,0,1,1,1,0,1,0,1,0,1,1,1,0,1]$

Elements on positions from $ 3 $ -rd to $ 10 $ -th in list is $ [1,1,1,0,1,0,1,0] $ . The number of ones is $ 5 $ .