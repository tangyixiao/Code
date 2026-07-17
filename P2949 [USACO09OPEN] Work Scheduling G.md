# P2949 [USACO09OPEN] Work Scheduling G

## 题目描述

农夫约翰有很多工作要做！为了高效地经营农场，他必须从他所做的每一项工作中赚取利润，每项工作只需要一个时间单位。

他的工作日从时间 $0$ 开始，总共有 $10^9$ 个时间单位。他目前可以从 $N$ ($1 \leq N \leq 10^5$) 项工作中选择要做的工作，这些工作被方便地编号为 $1$ 到 $N$。

虽然理论上他有可能完成所有 $N$ 项工作，但实际上这是极不可能的，因为他在任何一个时间单位内只能完成一项工作，而截止日期通常会导致他无法完成所有任务。

第 $i$ 项工作的截止时间为 $D_i$ ($1 \leq D_i \leq 10^9$)。如果他在截止时间前完成第 $i$ 项工作（如果当前时间为 $t$，那么仅当 $D_i > t$ 的时候他能做这个任务，完成后 $t \rightarrow t+1$），他将获得 $P_i$ ($1 \leq P_i \leq 10^9$) 的利润。

给定一系列工作和截止日期，FJ 能够获得的最大总利润是多少？答案可能无法容纳在 $32$ 位整数中。

## 输入格式

第一行输入一个整数 $N$，意义见题目描述。

第二行到第 $N+1$ 行：第 $i+1$ 行包含两个用空格分隔的整数：$D_i$ 和 $P_i$

## 输出格式

只有一个数字，表示 FJ 能够获得的最大利润。

## 输入输出样例 #1

### 输入 #1

```
3 
2 10 
1 5 
1 7 

```

### 输出 #1

```
17 

```

## 说明/提示

在时间 $1$ 完成工作 $3$ $\left(1,7\right)$，在时间 $2$ 完成工作 $1$ $\left(2,10\right)$ 以最大化收益，最后收益为 $7+10=17$。

（由 ChatGPT 4o 翻译）

---


# P2949 [USACO09OPEN] Work Scheduling G

## 题目描述

Farmer John has so very many jobs to do! In order to run the farm efficiently, he must make money on the jobs he does, each one of which takes just one time unit.

His work day starts at time 0 and has 1,000,000,000 time units (!).  He currently can choose from any of N (1 <= N <= 100,000) jobs

conveniently numbered 1..N for work to do. It is possible but

extremely unlikely that he has time for all N jobs since he can only work on one job during any time unit and the deadlines tend to fall so that he can not perform all the tasks.

Job i has deadline D\_i (1 <= D\_i <= 1,000,000,000). If he finishes job i by then, he makes a profit of P\_i (1 <= P\_i <= 1,000,000,000).

What is the maximum total profit that FJ can earn from a given list of jobs and deadlines?  The answer might not fit into a 32-bit integer.

## 输入格式

\* Line 1: A single integer: N

\* Lines 2..N+1: Line i+1 contains two space-separated integers: D\_i and P\_i

## 输出格式

\* Line 1: A single number on a line by itself that is the maximum possible profit FJ can earn.

## 输入输出样例 #1

### 输入 #1

```
3 
2 10 
1 5 
1 7 

```

### 输出 #1

```
17 

```

## 说明/提示

Complete job 3 (1,7) at time 1 and complete job 1 (2,10) at time 2 to maximize the earnings (7 + 10 -> 17).