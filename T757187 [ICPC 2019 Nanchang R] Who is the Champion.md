# T757187 [ICPC 2019 Nanchang R] Who is the Champion

## 题目描述

足球可能是这个国家最受欢迎的体育运动。然而，国家队在世界舞台上的战绩并不理想。为了激励年轻球员，每年都会举办全国足球锦标赛。

今年，共有 $n$ 支球队参加锦标赛。按照惯例，采用单循环赛制，每支球队与其他每支球队各比赛一场。一场标准的比赛双方各需要十名场上球员和一名守门员，总共有 $22$ 名球员参与。他们在长方形的草地球场上相互对抗，防守自家球门，攻击对方球门。

在 $90$ 分钟的比赛中，双方不断尝试射门。比赛结束时，进球数较多的一方获胜，并在积分榜上获得 $3$ 分，而失利方则不得分。一种非常特殊但常见的情况是双方进球数相同，即平局；此时双方各在积分榜上获得 $1$ 分。

赛季结束后，联赛将宣布总积分最高的球队为冠军。如果两支或更多球队的总积分相同，则总净胜球（用所有联赛比赛中的总进球数减去总失球数计算）最高的球队将成为冠军。最坏的情况是若干支球队的总积分和净胜球都相同，这将通过额外的附加赛来解决。

## 输入格式

第一行包含一个整数 $n$ $(1\le n \le 100)$ 表示参赛球队的数量。

接下来的 $n$ 行，每行包含 $n$ 个整数。第 $i$ 行中的第 $j$ 个整数为非负整数且不超过 $5$，表示第 $i$ 支球队对阵第 $j$ 支球队时的进球数。

我们保证对于所有 $1\le i \le n$，有 $a_{i,i}=0$。

## 输出格式

如果联赛能够决出冠军，输出将获得冠军的球队的编号；如果需要组织附加赛，则输出 `play-offs`（不带引号）。

## 输入输出样例 #1

### 输入 #1

```
2
0 1
2 0
```

### 输出 #1

```
2
```

## 输入输出样例 #2

### 输入 #2

```
2
0 1
1 0
```

### 输出 #2

```
play-offs
```

## 输入输出样例 #3

### 输入 #3

```
3
0 1 3
1 0 4
0 0 0
```

### 输出 #3

```
2
```

## 说明/提示

翻译由 DeepSeek V4 Pro 完成

---

# T757187 [ICPC 2019 Nanchang R] Who is the Champion

## 题目描述

Soccer is probably the sport with the greatest fans in this country. However, the national team has a poor record on the world stage. In order to energize youth players, the Soccer National Championship is organized every year.

In this year, there are $n$ teams taking part in the championship. As usual, the single round-robin system is adopted so that each team plays every other team once. A standard match asks ten players and a goalkeeper for both teams, which contains $22$ players in total. They confront each other, defend their nets and attack the opponent's goal in a rectangular grass court.

In a 90-minute game, they try to shoot again and again. When the game is over, the team with higher goals will win and obtain $3$ points in the scoreboard, while the loser will obtain nothing. A very special but common case is that both teams get the same goals, which is a draw; then both of them will obtain one point in the scoreboard.

At the end of the season, the league will declare the champion which is the team with the highest score in total. If two or more teams have the same highest score in total, the one with the highest goal differential (which is calculated as the number of goals scored in all league matches minus the number of goals conceded) will be the champion. The worst situation that several teams have the same highest score in total and the same goal differential will be solved by extra play-offs.

## 输入格式

The first line contains an integer $n~(1\le n \le 100)$ indicating the number of teams.

Each of the following $n$ lines contains $n$ integers. The $j$-th integer in the $i$-th line, which is non-negative and up to five, represents the number of goals scored by the $i$-th team against the $j$-th team.

We guarantee that $a_{i,i}=0$ for all $1\le i \le n$.

## 输出格式

If the league can declare the champion, output the index of the team who will be the champion or output `play-offs` (without quotes), if extra play-offs will be organized.

## 输入输出样例 #1

### 输入 #1

```
2
0 1
2 0
```

### 输出 #1

```
2
```

## 输入输出样例 #2

### 输入 #2

```
2
0 1
1 0
```

### 输出 #2

```
play-offs
```

## 输入输出样例 #3

### 输入 #3

```
3
0 1 3
1 0 4
0 0 0
```

### 输出 #3

```
2
```