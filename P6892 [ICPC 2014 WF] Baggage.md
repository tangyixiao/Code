# P6892 [ICPC 2014 WF] Baggage

## 题目描述

一家航空公司有两趟航班几乎同时从 ICPCity 出发，一趟飞往城市 B，另一趟飞往城市 A。航空公司有 $n$ 个柜台供乘客托运行李。每个柜台都有一对相同的行李箱，一个用于城市 B，一个用于城市 A。

就在航班起飞前，每对行李箱会被一辆电动推车移动到一个分拣区。推车总是一次移动两个箱子，一个用于城市 B，一个用于城市 A。所有箱子移动完后，它们在分拣区排成如下的顺序：

B A B A B A ... B A

也就是说，有 $2n$ 个行李箱排成一行，从一个城市 B 的箱子开始，然后是一个城市 A 的箱子，如此交替。现在的任务是重新排列它们，使得所有城市 A 的行李箱都排在城市 B 的行李箱之前。然后这些箱子可以被装载到相应的飞机上。

重新排列是通过移动相邻的一对行李箱（不一定是 B 然后是 A），同样通过电动推车进行。为了保持平衡，推车必须总是携带两个箱子，不能只携带一个。每对箱子必须移动到至少有两个箱子宽度的空位上。在第一个箱子的左边有一些空位，在重新排列过程中可以根据需要使用。

当重新排列过程开始时，箱子的位置从 $1$ 开始编号（最初包含最左边的 B 行李箱）到 $2n$（最初包含最右边的 A 行李箱）。在箱子的左边有 $2n$ 个初始空位，编号从 $0$ 到 $-2n+1$，如图 1 所示，$n=4$ 的情况。

![图 1](https://cdn.luogu.com.cn/upload/image_hosting/fwkcv2gq.png)

图 1：$n = 4$ 时箱子和空位的初始配置

给定 $n$，找出一个最短的移动序列，以便重新排列箱子，使得所有 A 箱子都在所有 B 箱子的左边。在过程结束时，最左边的 A 箱子可能在位置 $1$ 之外的某个位置，但箱子必须在 $2n$ 个位置的序列中相邻。

## 输入格式

输入由一个单一的测试用例组成，包含一个整数 $n$ $(3 \leq n \leq 100)$。

## 输出格式

显示一个最短的移动序列，该序列可以正确地重新排列箱子。每个移动的形式为“$f$ to $t$”，其中 $f$ 和 $t$ 是整数，表示位置 $f$ 和 $f + 1$ 的箱子移动到位置 $t$ 和 $t + 1$。如果有多个解决方案，显示其中任意一个。

## 输入输出样例 #1

### 输入 #1

```
5

```

### 输出 #1

```
8 to -1
3 to 8
6 to 3
0 to 6
9 to 0

```

## 输入输出样例 #2

### 输入 #2

```
8

```

### 输出 #2

```
10 to -1
3 to 10
14 to 3
7 to 14
0 to 7
11 to 0
4 to 11
15 to 4

```

## 说明/提示

时间限制：1000 毫秒，内存限制：1048576 KB。

国际大学生程序设计竞赛（ACM-ICPC）世界总决赛 2014。

题面翻译由 ChatGPT-4o 提供。

---

# P6892 [ICPC 2014 WF] Baggage

## 题目描述

An airline has two flights leaving at about the same time from ICPCity, one to city B and one to city A. The airline also has $n$ counters where passengers check their baggage. At each counter there is a pair of identical baggage bins, one for city B and one for city A.

Just before the flights depart, each pair of baggage bins is moved by a motorized cart to a sorting area. The cart always moves two bins at a time, one for city B and one for city A. After all the bins have been moved, they line up in the sorting area like this:

  B A B A B A ... B A 

That is, there are $2n$ baggage bins in a row, starting with a bin for city B, then one for city A, and so forth. The task now is to reorder them so all the baggage bins for city A precede the baggage bins for city B. Then the bins can be loaded on the appropriate aircraft.

The reordering is done by moving pairs of adjacent baggage bins (not necessarily B then A), again via the motorized cart. For proper balance, the cart must always carry two bins, never just one. A pair of bins must always be moved to an empty space that is at least two bins wide. On the left of the first bin are some empty spaces that can be used as needed during the reordering.

When the reordering process begins, the bin locations are numbered from $1$ (initially containing the leftmost B baggage bin) to $2n$ (initially containing the rightmost A baggage bin). There are $2n$ initially empty spaces to the left of the bins, numbered from $0$ to $-2n+1$, as shown in Figure 1 for the case $n=4$.
![](https://cdn.luogu.com.cn/upload/image_hosting/fwkcv2gq.png)

   Figure 1: Initial configuration of bins and empty spaces for $n = 4$ 

Given $n$, find a shortest sequence of moves that will reorder the bins so that all the A bins are to the left of all the B bins. At the end of the process, it is possible that the leftmost A bin is at some location other than $1$, but the bins must be adjacent in a sequence of $2n$ locations.

## 输入格式

The input consists of a single test case, which consists of the integer $n$ $(3 \leq n \leq 100)$.

## 输出格式

Display a shortest sequence of moves that will correctly reorder the bins. Each move is of the form “$f$ to $t$”, where $f$ and $t$ are integers representing the movement of the bins in locations $f$ and $f + 1$ to locations $t$ and $t + 1$. If multiple solutions are possible, display any one of them.

## 输入输出样例 #1

### 输入 #1

```
5

```

### 输出 #1

```
8 to -1
3 to 8
6 to 3
0 to 6
9 to 0

```

## 输入输出样例 #2

### 输入 #2

```
8

```

### 输出 #2

```
10 to -1
3 to 10
14 to 3
7 to 14
0 to 7
11 to 0
4 to 11
15 to 4

```

## 说明/提示

Time limit: 1000 ms, Memory limit: 1048576 kB. 

 International Collegiate Programming Contest (ACM-ICPC) World Finals 2014