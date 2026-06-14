# P2627 [USACO11OPEN] Mowing the Lawn G

## 题目描述

在一年前赢得了小镇的最佳草坪比赛后，Farmer John 变得很懒，再也没有修剪过草坪。现在，新一轮的最佳草坪比赛又开始了，Farmer John 希望能够再次夺冠。

然而，Farmer John 的草坪非常脏乱，因此，Farmer John 只能够让他的奶牛来完成这项工作。Farmer John 有 $N$（$1\le N\le 10^5$）只排成一排的奶牛，编号为 $1\ldots N$。每只奶牛的效率是不同的，奶牛 $i$ 的效率为 $E_i$（$0\le E_i\le 10^9$）。

靠近的奶牛们很熟悉，因此，如果 Farmer John安排超过 $K$（$1\le K\le N$）只连续的奶牛，那么，这些奶牛就会罢工去开派对 :)。因此，现在 Farmer John 需要你的帮助，计算 FJ 可以得到的最大效率，并且该方案中没有连续的超过 $K$ 只奶牛。

## 输入格式

第一行：空格隔开的两个整数 $N$ 和 $K$。

第二到 $N+1$ 行：第 $i+1$ 行有一个整数 $E_i$。

## 输出格式

第一行：一个值，表示 Farmer John 可以得到的最大的效率值。

## 输入输出样例 #1

### 输入 #1

```
5 2
1
2
3
4
5

```

### 输出 #1

```
12

```

---

# P2627 [USACO11OPEN] Mowing the Lawn G

## 题目描述

After winning the town’s Best Lawn contest a year ago, Farmer John became lazy and hasn’t mowed the lawn since. Now, a new Best Lawn contest is starting, and Farmer John hopes to win again.

However, Farmer John’s lawn is a mess, so he can only rely on his cows to do the job. Farmer John has $N$ ($1\le N\le 10^5$) cows in a row, numbered $1\ldots N$. Each cow has a different efficiency; cow $i$ has efficiency $E_i$ ($0\le E_i\le 10^9$).

Neighboring cows are very familiar with each other, so if Farmer John schedules more than $K$ ($1\le K\le N$) consecutive cows, they will go on strike to throw a party :). Therefore, Farmer John needs your help to compute the maximum total efficiency he can obtain, with no stretch of more than $K$ consecutive cows.

## 输入格式

The first line contains two integers $N$ and $K$ separated by a space.

The second to $(N+1)$-th lines: the $(i+1)$-th line contains an integer $E_i$.

## 输出格式

Output a single value: the maximum total efficiency that Farmer John can obtain.

## 输入输出样例 #1

### 输入 #1

```
5 2
1
2
3
4
5

```

### 输出 #1

```
12

```

## 说明/提示

Translated by ChatGPT 5