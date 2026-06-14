# P1823 [COI 2007] Patrik 音乐会的等待

## 题目描述

$n$ 个人正在排队进入一个音乐会。人们等得很无聊，于是他们开始转来转去，想在队伍里寻找自己的熟人。

队列中任意两个人 $a$ 和 $b$，如果他们是相邻或他们之间没有人比 $a$ 或 $b$ 高，那么他们是可以互相看得见的。

写一个程序计算出有多少对人可以互相看见。

## 输入格式

输入的第一行包含一个整数 $n$，表示队伍中共有 $n$ 个人。

接下来的 $n$ 行中，每行包含一个整数，表示人的高度，以毫微米（等于 $10^{-9}$ 米）为单位，这些高度分别表示队伍中人的身高。

## 输出格式

输出仅有一行，包含一个数 $s$，表示队伍中共有 $s$ 对人可以互相看见。

## 输入输出样例 #1

### 输入 #1

```
7 
2 
4 
1 
2 
2 
5 
1
```

### 输出 #1

```
10
```

## 说明/提示

#### 数据规模与约定
对于全部的测试点，保证 $1\le$ 每个人的高度 $< 2^{31}$，$1 \le n \le 5\times 10^5$。

---

# P1823 [COI 2007] Patrik: Waiting at the Concert

## 题目描述

$n$ people are standing in a queue to enter a concert. People are bored, so they start turning around to look for their acquaintances in the line.

For any two people $a$ and $b$ in the queue, they can see each other if they are adjacent, or if there is no one between them who is taller than both $a$ and $b$.

Write a program to compute how many pairs of people can see each other.

## 输入格式

The first line contains an integer $n$, the number of people in the queue.

Each of the next $n$ lines contains an integer, the height of a person, in nanometers (equal to $10^{-9}$ meters). These heights correspond to the people in the queue.

## 输出格式

Output a single line containing a number $s$, the total number of pairs of people who can see each other.

## 输入输出样例 #1

### 输入 #1

```
7 
2 
4 
1 
2 
2 
5 
1
```

### 输出 #1

```
10
```

## 说明/提示

Constraints

For all test points, $1 \le$ each person’s height $< 2^{31}$, and $1 \le n \le 5 \times 10^5$.

Translated by ChatGPT 5