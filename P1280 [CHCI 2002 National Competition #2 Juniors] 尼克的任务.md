# P1280 [CHCI 2002 National Competition #2 Juniors] 尼克的任务

## 题目描述

尼克每天上班之前都连接上英特网，接收他的上司发来的邮件，这些邮件包含了尼克主管的部门当天要完成的全部任务，每个任务由一个开始时刻与一个持续时间构成。

尼克的一个工作日为 $n$ 分钟，从第 $1$ 分钟开始到第 $n$ 分钟结束。当尼克到达单位后他就开始干活，公司一共有 $k$ 个任务需要完成。如果在同一时刻有多个任务需要完成，尼克可以任选其中的一个来做，而其余的则由他的同事完成，反之如果只有一个任务，则该任务必需由尼克去完成，假如某些任务开始时刻尼克正在工作，则这些任务也由尼克的同事完成。如果某任务于第 $p$ 分钟开始，持续时间为 $t$ 分钟，则该任务将在第 $(p+t-1)$ 分钟结束。

写一个程序计算尼克应该如何选取任务，才能获得最大的空暇时间。

## 输入格式

输入数据第一行含两个用空格隔开的整数 $n$ 和 $k$。

接下来共有 $k$ 行，每一行有两个用空格隔开的整数 $p$ 和 $t$，表示该任务从第 $p$ 分钟开始，持续时间为 $t$ 分钟。

## 输出格式

输出文件仅一行，包含一个整数，表示尼克可能获得的最大空暇时间。

## 输入输出样例 #1

### 输入 #1

```
15 6
1 2
1 6
4 11
8 5
8 1
11 5

```

### 输出 #1

```
4

```

## 说明/提示

#### 数据规模与约定

- 对于 $100\%$ 的数据，保证 $1 \leq n \leq 10^4,1 \leq k \leq 10^4,1 \leq p \leq n,1 \leq p+t-1 \leq n$。

---

# P1280 [CHCI 2002 National Competition #2 Juniors] LIGNJA

## 题目描述

Before going to work each day, Nick connects to the Internet and receives emails from his supervisor. These emails list all tasks that Nick’s department must complete that day. Each task is defined by a start time and a duration.

Nick’s workday lasts $n$ minutes, from minute $1$ to minute $n$. As soon as Nick arrives at work, he starts working. There are $k$ tasks in total. If, at the same moment, multiple tasks need to be done, Nick may choose any one of them to do, and the others will be completed by his colleagues. Conversely, if there is only one task, then that task must be done by Nick. If some tasks start at a time when Nick is already working, those tasks will also be handled by his colleagues. If a task starts at minute $p$ and lasts $t$ minutes, then it ends at minute $(p+t-1)$.

Write a program to determine how Nick should choose tasks in order to maximize his free time.

## 输入格式

The first line contains two integers $n$ and $k$ separated by a space.

Each of the next $k$ lines contains two integers $p$ and $t$, indicating a task that starts at minute $p$ and lasts $t$ minutes.

## 输出格式

Output a single line containing one integer, the maximum free time Nick can obtain.

## 输入输出样例 #1

### 输入 #1

```
15 6
1 2
1 6
4 11
8 5
8 1
11 5

```

### 输出 #1

```
4

```

## 说明/提示

Constraints

- For 100% of the testdata, it is guaranteed that $1 \leq n \leq 10^4, 1 \leq k \leq 10^4, 1 \leq p \leq n, 1 \leq p+t-1 \leq n$.

Translated by ChatGPT 5