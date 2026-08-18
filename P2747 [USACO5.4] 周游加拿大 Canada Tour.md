# P2747 [USACO5.4] 周游加拿大 Canada Tour

## 题目描述

你赢得了一场航空公司举办的比赛，奖品是一张加拿大环游机票。旅行在这家航空公司开放的最西边的城市开始，然后一直自西向东旅行，直到你到达最东边的城市，再由东向西返回，直到你回到开始的城市。除了旅行开始的城市之外，每个城市只能访问一次，因为开始的城市必定要被访问两次（在旅行的开始和结束）。

当然不允许使用其他公司的航线或者用其他的交通工具。

给出这个航空公司开放的城市的列表，和两两城市之间的直达航线列表。找出能够访问尽可能多的城市的路线，这条路线必须满足上述条件，也就是从列表中的第一个城市开始旅行，访问到列表中最后一个城市之后再返回第一个城市。

## 输入格式

第 $1$ 行：航空公司开放的城市数 $N$ 和将要列出的直达航线的数量 $V$。$N$ 是一个不大于 $100$ 的正整数。$V$ 是任意的正整数。

第 $2\sim N+1$ 行：每行包括一个航空公司开放的城市名称。城市名称按照自西向东排列。不会出现两个城市在同一条经线上的情况。每个城市的名称都是一个字符串，最多 $15$ 字节，由拉丁字母表上的字母组成；城市名称中没有空格。

第 $N+2\sim N+2+V-1$ 行：每行包括两个城市名称（由上面列表中的城市名称组成），用一个空格分开。这样就表示两个城市之间的直达双程航线。

## 输出格式

第 $1$ 行：按照最佳路线访问的不同城市的数量 $M$。如果无法找到路线，输出 `1`。

## 输入输出样例 #1

### 输入 #1

```
8 9
Vancouver
Yellowknife
Edmonton
Calgary
Winnipeg
Toronto
Montreal
Halifax
Vancouver Edmonton
Vancouver Calgary
Calgary Winnipeg
Winnipeg Toronto
Toronto Halifax
Montreal Halifax
Edmonton Montreal
Edmonton Yellowknife
Edmonton Calgary
```

### 输出 #1

```
7
```

## 说明/提示

题目翻译来自 NOCOW。

USACO Training Section 5.4

---

# P2747 [USACO5.4] Canada Tour

## 题目描述

You have won a contest held by an airline, and the prize is a ticket for a tour of Canada. The trip starts at the westernmost city served by this airline, then you keep traveling from west to east until you reach the easternmost city, and then travel from east to west back to the starting city. Except for the starting city, each city may be visited at most once, because the starting city must be visited twice (at the beginning and at the end).

You are not allowed to use flights of other airlines or any other means of transportation.

Given the list of cities served by this airline and the list of direct flights between pairs of cities, find a route that visits as many cities as possible while satisfying the above conditions. In other words, you must start from the first city in the list, reach the last city in the list, and then return to the first city.

## 输入格式

Line $1$: The number of cities served by the airline $N$ and the number of direct flights to be listed $V$. $N$ is a positive integer not greater than $100$. $V$ is any positive integer.

Lines $2 \sim N+1$: Each line contains the name of a city served by the airline. The cities are listed from west to east. No two cities lie on the same meridian. Each city name is a string of at most $15$ bytes, consisting of letters of the Latin alphabet; city names contain no spaces.

Lines $N+2 \sim N+2+V-1$: Each line contains two city names (chosen from the list above), separated by a space, indicating a bidirectional direct flight between the two cities.

## 输出格式

Line $1$: $M$, the number of distinct cities visited by the optimal route. If no route can be found, output `1`.

## 输入输出样例 #1

### 输入 #1

```
8 9
Vancouver
Yellowknife
Edmonton
Calgary
Winnipeg
Toronto
Montreal
Halifax
Vancouver Edmonton
Vancouver Calgary
Calgary Winnipeg
Winnipeg Toronto
Toronto Halifax
Montreal Halifax
Edmonton Montreal
Edmonton Yellowknife
Edmonton Calgary
```

### 输出 #1

```
7
```

## 说明/提示

The problem statement is translated from NOCOW.
USACO Training Section 5.4.

Translated by ChatGPT 5