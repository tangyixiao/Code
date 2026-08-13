# P2880 [USACO07JAN] Balanced Lineup G

## 题目描述

每天，农夫 John 的 $n\ (1\le n\le 5\times 10^4)$ 头牛总是按同一序列排队。

有一天，John 决定让一些牛们玩一场飞盘比赛。他准备找一群在队列中位置连续的牛来进行比赛。但是为了避免水平悬殊，牛的身高不应该相差太大。John 准备了 $q\ (1\le q\le 1.8\times10^5)$ 个可能的牛的选择和所有牛的身高 $h_i\ (1\le h_i\le 10^6,1\le i\le n)$。他想知道每一组里面最高和最低的牛的身高差。

## 输入格式

第一行两个数 $n,q$。

接下来 $n$ 行，每行一个数 $h_i$。

再接下来 $q$ 行，每行两个整数 $a$ 和 $b$，表示询问第 $a$ 头牛到第 $b$ 头牛里的最高和最低的牛的身高差。

## 输出格式

输出共 $q$ 行，对于每一组询问，输出每一组中最高和最低的牛的身高差。

## 输入输出样例 #1

### 输入 #1

```
6 3
1
7
3
4
2
5
1 5
4 6
2 2
```

### 输出 #1

```
6
3
0
```

---

# P2880 [USACO07JAN] Balanced Lineup G

## 题目描述

For the daily milking, Farmer John's $N$ cows ($1 \le N \le 5 \times 10^4$) always line up in the same order. One day Farmer John decides to organize a game of Ultimate Frisbee with some of the cows. To keep things simple, he will take a contiguous range of cows from the milking lineup to play the game. However, for all the cows to have fun they should not differ too much in height.

Farmer John has made a list of $Q$ ($1 \le Q \le 1.8 \times 10^5$) potential groups of cows and their heights ($1 \le \text{height} \le 10^6$). For each group, he wants your help to determine the difference in height between the shortest and the tallest cow in the group.

## 输入格式

Line $1$: Two space-separated integers, $N$ and $Q$.

Lines $2 \dots N+1$: Line $i+1$ contains a single integer that is the height of cow $i$.

Lines $N+2 \dots N+Q+1$: Two integers $A$ and $B$ ($1 \le A \le B \le N$), representing the range of cows from $A$ to $B$ inclusive.

## 输出格式

Lines $1 \dots Q$: Each line contains a single integer that is a response to a reply and indicates the difference in height between the tallest and shortest cow in the range.

## 输入输出样例 #1

### 输入 #1

```
6 3
1
7
3
4
2
5
1 5
4 6
2 2
```

### 输出 #1

```
6
3
0
```