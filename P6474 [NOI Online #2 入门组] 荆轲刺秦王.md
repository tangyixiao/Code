# P6474 [NOI Online #2 入门组] 荆轲刺秦王

## 题目背景

本测试数据为脚造，欢迎提供 hack。

第 18 组数据卡了很多人，放于附件中供检查。

## 题目描述

时隔数年，刺客荆轲再次来到咸阳宫，试图刺杀嬴政。

咸阳宫的地图可以描述为一个 $n$ 行 $m$ 列的矩形。在这里，我们规定每一行中从左到右为 $x$ 轴正方向，每一列中从下到上为 $y$ 轴正方向，左下角的点坐标为 $(1,1)$。矩形中的点可以分为 $4$ 种：

1. 起点，也就是荆轲的所在点，在地图中用字符 `S` 代表。
2. 终点，也就是嬴政的所在点，在地图中用字符 `T` 代表。
3. 卫兵，在地图中用一个正整数 $a_{i,j}$ 代表。在这里，一个卫兵 $(i,j)$ 可以观察到与他曼哈顿距离小于 $a_{i,j}$ 的点。也就是卫兵 $(i,j)$ 可以观察到所有满足 $|x-i|+|y-j|<a_{i,j}$ 的点 $(x,y)$。
4. 空地，在地图中用字符 `.` 代表。

荆轲的正常移动方式为每秒向八连通的任意方向前进一格。如下图，中间的点为荆轲当前所在点，每一秒，他可以走向其余的八个点。

![](https://cdn.luogu.com.cn/upload/image_hosting/9rnnpj4z.png)

需要注意的是，正常移动时，荆轲不能踏进任何一个有卫兵或者卫兵能观察到的格子。当然，他也不能走出咸阳宫，也就是说，无论何时，荆轲的坐标 $(x,y)$ 都必须满足 $1\le x\le m$ 且 $1\le y\le n$。

荆轲还有两种技能：隐身和瞬移。

1. 隐身：下一秒荆轲进入隐身状态，卫兵观察不到荆轲，荆轲可以进入卫兵的观察范围内，但仍然不能进入卫兵所在的格子。注意这个状态只能维持一秒。
2. 瞬移：荆轲下一秒移动的距离改为 $d$，但这时只能向上下左右四个方向移动。即可以移动到 
$(x+d,y)$，$(x-d,y)$，$(x,y+d)$，$(x,y-d)$。
在本题中，两种技能可以同时使用，而且不考虑冷却时间，即一次用完可以立即用下一次，两种技能都分别有使用次数限制，你也可以不用完所有次数。

现在给出咸阳城的地图，请计算荆轲到达秦王所在点所需的最短时间。此外，在所用时间相同情况下，荆轲希望使用的两种技能总次数尽可能少；在所用时间与技能次数相同情况下，荆轲希望使用的隐身次数尽可能少。

## 输入格式

第一行五个整数 $n$, $m$, $c_1$, $c_2$, $d$，代表地图的大小为 $n\times m$，隐身的使用限制次数为 $c_1$，瞬移的使用限制次数为 $c_2$ 和一次瞬移的距离为 $d$。

接下来 $n$ 行，每行 $m$ 个元素。每个元素为字符 `S`、`T`、`.` 或者一个正整数 $a_{i,j}$，代表一个格点，具体含义详见题目描述。

## 输出格式

若荆轲无法到达秦王所在点，则输出一行一个 $-1$。

否则输出一行三个整数 $t$, $u_1$, $u_2$，依次代表所需的最短时间，隐身的使用次数与瞬移的使用次数。

## 输入输出样例 #1

### 输入 #1

```
5 4 0 0 5
. 1 T 1
. . . 2
. 1 . .
S . . .
1 . . .
```

### 输出 #1

```
3 0 0
```

## 输入输出样例 #2

### 输入 #2

```
8 6 2 3 3
. S . . . .
. . . . . .
. . . . . .
. . . . . .
. . . . . .
2 . 2 . 2 .
. . 1 . T .
3 . 1 . . 3

```

### 输出 #2

```
3 1 3
```

## 输入输出样例 #3

### 输入 #3

```
8 6 5 5 2
. S . . . .
. . . . . .
. . . . . .
1 1 3 2 . 1
2 3 2 2 1 3 
3 2 4 1 4 3 
2 6 1 5 T 2 
8 1 6 3 2 10
```

### 输出 #3

```
-1
```

## 说明/提示

#### 样例 1 解释

起点为 $(1,2)$，荆轲可以依次走到 $(1,3)$, $(2,4)$, $(3,5)$ 到达终点。

#### 样例 2 解释

起点为 $(2,8)$，荆轲可以依次走到 $(2,5)$, $(2,2)$, $(5,2)$，需要注意的是，即使最后一步到达终点，但因为终点在卫兵的观察范围之内，所以仍然需要隐身进入。

#### 数据范围与提示


对于测试点 $1\sim 6$：$n$, $m\le 10$，$c_1=c_2=0$，保证所需的最短时间不超过 $5$ 或者无解。

对于测试点 $7\sim 10$：$n$, $m\le 20$，$c_1=c_2=0$，保证 `T` 的位置不在任何一个卫兵的观察范围之中。

对于测试点 $11\sim 12$：$n$, $m\le 20$，$c_1=0$

对于测试点 $13\sim 14$：$n$, $m\le 20$，$c_1$, $c_2 \le 5$。

对于测试点 $15\sim 16$：卫兵个数不超过 $350$。

对于所有测试点：$2\le n$, $m\le 350$，$1\le a_{i,j}\le 350$，$0\le c_1$, $c_2\le 15$，$1\le d\le 350$。

保证 `S` 的位置不在任何卫兵的观察范围中。

---

# P6474 [NOI Online #2 Junior] Jing Ke Assassinating the King of Qin

## 题目背景

This testdata is handmade. Hacks are welcome.

The 18th group of testdata trapped many people, and it is provided in the attachment for checking.

## 题目描述

After several years, the assassin Jing Ke comes to the Xianyang Palace again, trying to assassinate Ying Zheng.

The map of the Xianyang Palace can be described as a rectangle with $n$ rows and $m$ columns. Here, we define that in each row, from left to right is the positive direction of the $x$ axis, and in each column, from bottom to top is the positive direction of the $y$ axis. The coordinate of the bottom-left corner is $(1,1)$. Points in the rectangle can be divided into $4$ types:

1. The start point, where Jing Ke is located, represented by the character `S` on the map.
2. The end point, where Ying Zheng is located, represented by the character `T` on the map.
3. Guards, represented by a positive integer $a_{i,j}$. A guard at $(i,j)$ can observe points whose Manhattan distance to him is less than $a_{i,j}$. That is, the guard at $(i,j)$ can observe all points $(x,y)$ satisfying $|x-i|+|y-j|<a_{i,j}$.
4. Empty ground, represented by the character `.` on the map.

Jing Ke’s normal movement is to move one grid per second to any of the eight 8-connected directions. As shown in the figure below, the middle point is Jing Ke’s current position, and every second, he can move to any of the other eight points.

![](https://cdn.luogu.com.cn/upload/image_hosting/9rnnpj4z.png)

Note that during normal movement, Jing Ke cannot step into any cell that has a guard or is observable by any guard. Of course, he also cannot leave the Xianyang Palace, meaning that at any time, Jing Ke’s coordinates $(x,y)$ must satisfy $1\le x\le m$ and $1\le y\le n$.

Jing Ke also has two skills: Invisibility and Teleportation.

1. Invisibility: In the next second, Jing Ke enters an invisible state. Guards cannot observe Jing Ke, and Jing Ke may enter cells within guards’ observable ranges, but he still cannot enter the cell where a guard stands. Note that this state lasts for only one second.
2. Teleportation: In the next second, Jing Ke’s moving distance becomes $d$, but he can only move in the four directions up, down, left, and right. That is, he can move to  
$(x+d,y)$, $(x-d,y)$, $(x,y+d)$, $(x,y-d)$.

In this problem, the two skills can be used at the same time, and there is no cooldown. That is, after using a skill once, you may use it again immediately. Both skills have usage limits, and you do not have to use all of them.

Now, given the map of Xianyang, compute the minimum time needed for Jing Ke to reach the King of Qin’s position. In addition, among solutions with the same time, Jing Ke wants the total number of times the two skills are used to be as small as possible. If both the time and the total skill usage are the same, Jing Ke wants the number of invisibility uses to be as small as possible.

## 输入格式

The first line contains five integers $n$, $m$, $c_1$, $c_2$, $d$, meaning the map size is $n\times m$, the usage limit of invisibility is $c_1$, the usage limit of teleportation is $c_2$, and the teleport distance is $d$.

Then follow $n$ lines, each with $m$ elements. Each element is the character `S`, `T`, `.`, or a positive integer $a_{i,j}$, representing a grid point. See the problem description for details.

## 输出格式

If Jing Ke cannot reach the King of Qin’s position, output one line with $-1$.

Otherwise, output one line with three integers $t$, $u_1$, $u_2$, representing the minimum required time, the number of invisibility uses, and the number of teleportation uses, in this order.

## 输入输出样例 #1

### 输入 #1

```
5 4 0 0 5
. 1 T 1
. . . 2
. 1 . .
S . . .
1 . . .
```

### 输出 #1

```
3 0 0
```

## 输入输出样例 #2

### 输入 #2

```
8 6 2 3 3
. S . . . .
. . . . . .
. . . . . .
. . . . . .
. . . . . .
2 . 2 . 2 .
. . 1 . T .
3 . 1 . . 3

```

### 输出 #2

```
3 1 3
```

## 输入输出样例 #3

### 输入 #3

```
8 6 5 5 2
. S . . . .
. . . . . .
. . . . . .
1 1 3 2 . 1
2 3 2 2 1 3 
3 2 4 1 4 3 
2 6 1 5 T 2 
8 1 6 3 2 10
```

### 输出 #3

```
-1
```

## 说明/提示

#### Sample 1 Explanation

The start point is $(1,2)$. Jing Ke can move to $(1,3)$, $(2,4)$, $(3,5)$ in order to reach the end point.

#### Sample 2 Explanation

The start point is $(2,8)$. Jing Ke can move to $(2,5)$, $(2,2)$, $(5,2)$ in order. Note that even though the last step reaches the end point, since the end point is within a guard’s observable range, Jing Ke still needs invisibility to enter.

#### Constraints and Hints

For test points $1\sim 6$: $n$, $m\le 10$, $c_1=c_2=0$. It is guaranteed that the minimum required time does not exceed $5$, or there is no solution.

For test points $7\sim 10$: $n$, $m\le 20$, $c_1=c_2=0$. It is guaranteed that the position of `T` is not within any guard’s observable range.

For test points $11\sim 12$: $n$, $m\le 20$, $c_1=0$.

For test points $13\sim 14$: $n$, $m\le 20$, $c_1$, $c_2 \le 5$.

For test points $15\sim 16$: the number of guards does not exceed $350$.

For all test points: $2\le n$, $m\le 350$, $1\le a_{i,j}\le 350$, $0\le c_1$, $c_2\le 15$, $1\le d\le 350$.

It is guaranteed that the position of `S` is not within any guard’s observable range.

Translated by ChatGPT 5