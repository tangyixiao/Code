# CF1659A Red Versus Blue

## 题目描述

红队和蓝队进行了一场比赛，这场比赛分为了 $n$ 个阶段。

已知比赛中红队获胜的阶段数 $r$ 以及蓝队获胜的阶段数 $b$，由于蓝队实力不如红队，满足 $b<r$。你错过了这场比赛，想知道每个阶段的获胜队伍。

你用一个长 $n$ 的字符串来表示每个阶段的获胜队伍。具体地，将每一个阶段的获胜队伍连起来形成一个字符串，这个字符串的第 $i$ 位若为 $R$ 则表示红队赢了第 $i$ 个阶段，为 $B$ 则表示蓝队赢了这个阶段。你认为为了让比赛更有看头，某个队伍连续获胜的阶段数越少越好。

请输出一种可能的字符串，其中每一队连续获胜的阶段数的最大值最小，若有多解输出任意一种。

## 输入格式

第一行一个正整数 $t$ 表示数据组数（$1\le t\le 1000$），接下来依次输入每组数据：

## 输出格式

每组数据输出一个字符串满足题目条件。
### 样例解释
第一组样例的第一组数据中，为 $RBRBRBR$ 时，一个队伍连续赢的阶段数最大为 1，显然没有更小解。

第二组样例的第二组数据中，为 $\underline{RR}BRBRBRBR
$ 时，一个队伍连续赢的阶段数最大为 2，没有更小解。

## 输入输出样例 #1

### 输入 #1

```
3
7 4 3
6 5 1
19 13 6
```

### 输出 #1

```
RBRBRBR
RRRBRR
RRBRRBRRBRRBRRBRRBR
```

## 输入输出样例 #2

### 输入 #2

```
6
3 2 1
10 6 4
11 6 5
10 9 1
10 8 2
11 9 2
```

### 输出 #2

```
RBR
RRBRBRBRBR
RBRBRBRBRBR
RRRRRBRRRR
RRRBRRRBRR
RRRBRRRBRRR
```


---

# CF1659A Red Versus Blue

## 题目描述

Team Red and Team Blue competed in a competitive FPS. Their match was streamed around the world. They played a series of $ n $ matches.

In the end, it turned out Team Red won $ r $ times and Team Blue won $ b $ times. Team Blue was less skilled than Team Red, so $ b $ was strictly less than $ r $ .

You missed the stream since you overslept, but you think that the match must have been neck and neck since so many people watched it. So you imagine a string of length $ n $ where the $ i $ -th character denotes who won the $ i $ -th match — it is R if Team Red won or B if Team Blue won. You imagine the string was such that the maximum number of times a team won in a row was as small as possible. For example, in the series of matches RBBRRRB, Team Red won $ 3 $ times in a row, which is the maximum.

You must find a string satisfying the above conditions. If there are multiple answers, print any.

## 输入格式

The first line contains a single integer $ t $ ( $ 1 \le t \le 1000 $ ) — the number of test cases.

Each test case has a single line containing three integers $ n $ , $ r $ , and $ b $ ( $ 3 \leq n \leq 100 $ ; $ 1 \leq b < r \leq n $ , $ r+b=n $ ).

## 输出格式

For each test case, output a single line containing a string satisfying the given conditions. If there are multiple answers, print any.

## 输入输出样例 #1

### 输入 #1

```
3
7 4 3
6 5 1
19 13 6
```

### 输出 #1

```
RBRBRBR
RRRBRR
RRBRRBRRBRRBRRBRRBR
```

## 输入输出样例 #2

### 输入 #2

```
6
3 2 1
10 6 4
11 6 5
10 9 1
10 8 2
11 9 2
```

### 输出 #2

```
RBR
RRBRBRBRBR
RBRBRBRBRBR
RRRRRBRRRR
RRRBRRRBRR
RRRBRRRBRRR
```

## 说明/提示

The first test case of the first example gives the optimal answer for the example in the statement. The maximum number of times a team wins in a row in RBRBRBR is $ 1 $ . We cannot minimize it any further.

The answer for the second test case of the second example is RRBRBRBRBR. The maximum number of times a team wins in a row is $ 2 $ , given by RR at the beginning. We cannot minimize the answer any further.