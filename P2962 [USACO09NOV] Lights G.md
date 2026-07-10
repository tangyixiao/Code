# P2962 [USACO09NOV] Lights G

## 题目描述

奶牛 Bessie 和其他奶牛在谷仓里玩游戏，但电源重置后所有灯都熄灭了。请帮助它们将所有的灯重新打开，以便继续游戏。

有 $N$（$1 \le N \le 35$）盏灯，编号为 $1$ 到 $N$，它们的开关通过 $M$（$1 \le M \le 595$）条连接构成一个复杂的网络。

每盏灯都有一个开关，当你切换它时，该灯及所有与之直接相连的灯都会改变状态（开变关，关变开）。

请找出最少需要切换多少次开关，才能把所有灯都打开。

题目保证至少存在一种切换方案可以将所有灯点亮。

## 输入格式

第 $1$ 行是两个用空格分隔的整数 $N$ 和 $M$。

第 $2$ 行到第 $M + 1$ 行，每行两个空格分隔的整数，表示一条连接的两个灯的编号（无重复）。

## 输出格式

仅一行一个整数，表示将所有灯点亮所需的最少开关切换次数。

## 输入输出样例 #1

### 输入 #1

```
5 6 
1 2 
1 3 
4 2 
3 4 
2 5 
5 3 

```

### 输出 #1

```
3 

```

## 说明/提示

### 样例解释

$5$ 盏灯中，灯 $1, 4, 5$ 各自都与灯 $2$ 和灯 $3$ 相连。

只需切换灯 $1, 4, 5$ 的开关，即可使所有灯都打开。

---

# P2962 [USACO09NOV] Lights G

## 题目描述

Bessie and the cows were playing games in the barn, but the power was reset and the lights were all turned off. Help the cows get all the lights back on so they can resume their games.

The $N(1 \le N \le 35)$ lights conveniently numbered $1 \cdots N$ and their switches are arranged in a complex network with $M(1 \le M \le 595)$ clever connection between pairs of lights (see below).

Each light has a switch that, when toggled, causes that light -- and all of the lights that are connected to it -- to change their states (from on to off, or off to on).

Find the minimum number of switches that need to be toggled in order to turn all the lights back on.

It's guaranteed that there is at least one way to toggle the switches so all lights are back on.

## 输入格式

- Line $1$: Two space-separated integers: $N$ and $M$.
- Lines $2 \cdots M+1$: Each line contains two space-separated integers representing two lights that are connected. No pair will be repeated.

## 输出格式

- Line $1$: A single integer representing the minimum number of switches that need to be flipped in order to turn on all the lights.

## 输入输出样例 #1

### 输入 #1

```
5 6 
1 2 
1 3 
4 2 
3 4 
2 5 
5 3 

```

### 输出 #1

```
3 

```

## 说明/提示

### Explanation

There are $5$ lights. Lights $1,4$ and $5$ are each connected to both lights $2$ and $3$.

Toggle the switches on lights $1, 4$ and $5$.