# P1518 [USACO2.4] 两只塔姆沃斯牛 The Tamworth Two

## 题目描述

两只牛逃跑到了森林里。Farmer John 开始用他的专家技术追捕这两头牛。你的任务是模拟他们的行为（牛和 John）。

追击在 $10 \times 10$ 的平面网格内进行。一个格子可以是：空地，一个障碍物，两头牛（它们总在一起），或者 Farmer John。两头牛和 Farmer John 可以在同一个格子内（当他们相遇时），但是他们都不能进入有障碍的格子。

一个格子可以是：
- `.` 空地；
- `*` 障碍物；
- `C` 两头牛；
- `F` Farmer John。

这里有一个地图的例子：

```plain
*...*.....
......*...
...*...*..
..........
...*.F....
*.....*...
...*......
..C......*
...*.*....
.*.*......
```

牛在地图里以固定的方式游荡。每分钟，它们可以向前移动或是转弯。如果前方无障碍（地图边沿也是障碍），它们会按照原来的方向前进一步。否则它们会用这一分钟顺时针转 $90$ 度。 同时，它们不会离开地图。

Farmer John 深知牛的移动方法，他也这么移动。

每次（每分钟）Farmer John 和两头牛的移动是同时的。如果他们在移动的时候穿过对方，但是没有在同一格相遇，我们不认为他们相遇了。当他们在某分钟末在某格子相遇，那么追捕结束。

读入十行表示地图。每行都只包含 $10$ 个字符，表示的含义和上面所说的相同。保证地图中只有一个 `F` 和一个 `C`。`F` 和 `C` 一开始不会处于同一个格子中。

计算 Farmer John 需要多少分钟来抓住他的牛，假设牛和 Farmer John 一开始的行动方向都是正北（即上）。 如果 John 和牛永远不会相遇，输出 $0$。

## 输入格式

输入共十行，每行 $10$ 个字符，表示如上文描述的地图。

## 输出格式

输出一个数字，表示 John 需要多少时间才能抓住牛们。如果 John 无法抓住牛，则输出 $0$。

## 输入输出样例 #1

### 输入 #1

```
*...*.....
......*...
...*...*..
..........
...*.F....
*.....*...
...*......
..C......*
...*.*....
.*.*......
```

### 输出 #1

```
49
```

## 说明/提示

翻译来自NOCOW

USACO 2.4

---

# P1518 [USACO2.4] The Tamworth Two

## 题目描述

Two cows have escaped into the forest. Farmer John begins to pursue them using his expert technique. Your task is to simulate their behavior (the cows and John).

The chase takes place on a $10 \times 10$ grid. Each cell can be: an obstacle, the two cows (they always stay together), or Farmer John. The cows and Farmer John may occupy the same cell (when they meet), but neither can enter a cell with an obstacle.

A cell can be:
- `.` empty ground;
- `*` obstacle;
- `C` the two cows;
- `F` Farmer John.

Here is an example map:

```plain
*...*.....
......*...
...*...*..
..........
...*.F....
*.....*...
...*......
..C......*
...*.*....
.*.*......
```

The cows wander the map in a fixed way. Each minute, they either move forward or turn. If the cell directly ahead is not blocked (the map border also counts as a blockage), they advance one cell in their current direction. Otherwise, they spend that minute turning 90 degrees clockwise. They never move off the map.

Farmer John knows the cows' movement rule and moves in exactly the same way.

The cows and Farmer John move simultaneously each minute. If they pass through each other during a move but do not end up in the same cell at the end of that minute, that does not count as a meeting. When they occupy the same cell at the end of some minute, the chase ends.

Read ten lines describing the map. Each line contains exactly 10 characters, with meanings as defined above. There is exactly one `F` and one `C`. `F` and `C` do not start in the same cell.

Compute how many minutes Farmer John needs to catch the cows, assuming both the cows and Farmer John initially face north (up). If John and the cows will never meet, output 0.

## 输入格式

The input consists of ten lines, each with 10 characters, describing the map as above.

## 输出格式

Output a single integer: the number of minutes Farmer John needs to catch the cows. If he cannot catch them, output 0.

## 输入输出样例 #1

### 输入 #1

```
*...*.....
......*...
...*...*..
..........
...*.F....
*.....*...
...*......
..C......*
...*.*....
.*.*......
```

### 输出 #1

```
49
```

## 说明/提示

Translation from NOCOW.
USACO 2.4.

Translated by ChatGPT 5