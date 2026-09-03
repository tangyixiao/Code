# CF1635E Cars

## 题目描述

坐标轴 $O\!X$ 上有 $n$ 辆汽车。每辆车最初位于一个整数点，并且没有两辆车位于同一点。此外，每辆车都可以向左或向右定向地、可以随时以任何恒定的正速度地沿该方向移动。

更正式地说，我们可以用一个字母和一个整数来描述第 $ i $ 辆汽车：它的方向 $ ori_i $ 和它的位置 $ x_i $ 。如果 $ ori_i = L \ \left(Left\right) $ ，则 $ x_i $ 以相对于时间的恒定速率递减。类似地，如果 $ ori_i = R \ \left(Right\right)$ ，则 $ x_i $ 以相对于时间的恒定速率增加。

如果两辆汽车无论速度如何都永远不会到达同一点，我们称它们为 **无关紧要的**。换句话说，它们在任何时候都不会处于相同的坐标。

如果两辆汽车无论速度如何，它们一定会到达同一点，我们就称它们为 **命中注定的** 。换句话说，它们一定会在某个时刻处于相同的坐标。

不幸的是，我们丢失了有关我们汽车的所有信息，但我们依然记得这些车之间的 $ m $ 个关系。有两种类型的关系：

 - $ 1$ $ i $ $ j $ — 第 $ i $ 辆车和第$ j $ 辆车是 **无关紧要的**。

- $ 2 $ $ i $ $ j $— 第 $ i $ 辆车和第 $ j $ 辆车是 **命中注定的**。

要求求出满足关系的汽车的方向和位置，或着回答满足关系的车不可能存在的。如果有多个解决方案，则输出任何一个。

**请注意，如果两辆车处于相同的坐标，它们将相交，但同时它们将继续沿各自的方向移动。**

## 输入格式

第一行包含两个整数，$ n $ 和 $ m $ $ (2 \leq n \leq 2 \cdot 10^5; 1 \leq m \leq min(2 \cdot 10^5, \frac{n(n -1)}{2}) $ — 分别是汽车数量和关系数量。

接下来的 $ m $ 行中的每一行都包含三个整数， $ type $ 、 $ i $ 和 $ j $ $ (1 \leq type \leq 2; 1 \leq i,j \leq n; i≠j) $ 。

如果 $ type = 1 $ ， 第 $ i $ 辆车和第 $ j $ 辆车是 **无关紧要的**。否则，第 $ i $ 辆车和第 $ j $ 辆车是 **命中注定的**。

保证每对汽车之间最多有 $ 1 $ 种关系。

## 输出格式

在第一行中，一定要输出 **YES** 或 **NO** ，表示是否存在满足关系的汽车的方向和位置。

如果输出 **YES** ，则在接下来 $ n $ 行中，每行包含一个符号和一个整数来代表第 $ i $ 辆车的信息： $ ori_i $ 和 $ x_i $ $ (ori_i \in \{L, R\};\, -10^9 \leq x_i \leq 10^9) $ 

如果该车方向为左，则 $ ori_i = L $ 。否则 $ ori_i = R $ 。

 $ x_i $ 是第 $ i $ 辆车所在的位置。**请注意，不存在任意两个相同的 $ x_i $ 。**

我们可以证明，如果存在解，那么一定存在可以约束 $ x_i $ 的解。

## 输入输出样例 #1

### 输入 #1

```
4 4
1 1 2
1 2 3
2 3 4
2 4 1
```

### 输出 #1

```
YES
R 0
L -3
R 5
L 6
```

## 输入输出样例 #2

### 输入 #2

```
3 3
1 1 2
1 2 3
1 1 3
```

### 输出 #2

```
NO
```


---

# CF1635E Cars

## 题目描述

There are $ n $ cars on a coordinate axis $ OX $ . Each car is located at an integer point initially and no two cars are located at the same point. Also, each car is oriented either left or right, and they can move at any constant positive speed in that direction at any moment.

More formally, we can describe the $ i $ -th car with a letter and an integer: its orientation $ ori_i $ and its location $ x_i $ . If $ ori_i = L $ , then $ x_i $ is decreasing at a constant rate with respect to time. Similarly, if $ ori_i = R $ , then $ x_i $ is increasing at a constant rate with respect to time.

We call two cars irrelevant if they never end up in the same point regardless of their speed. In other words, they won't share the same coordinate at any moment.

We call two cars destined if they always end up in the same point regardless of their speed. In other words, they must share the same coordinate at some moment.

Unfortunately, we lost all information about our cars, but we do remember $ m $ relationships. There are two types of relationships:

 $ 1 $ $ i $ $ j $ — $ i $ -th car and $ j $ -th car are irrelevant.

 $ 2 $ $ i $ $ j $ — $ i $ -th car and $ j $ -th car are destined.

Restore the orientations and the locations of the cars satisfying the relationships, or report that it is impossible. If there are multiple solutions, you can output any.

Note that if two cars share the same coordinate, they will intersect, but at the same moment they will continue their movement in their directions.

## 输入格式

The first line contains two integers, $ n $ and $ m $ $ (2 \leq n \leq 2 \cdot 10^5; 1 \leq m \leq min(2 \cdot 10^5, \frac{n(n-1)}{2}) $ — the number of cars and the number of restrictions respectively.

Each of the next $ m $ lines contains three integers, $ type $ , $ i $ , and $ j $ $ (1 \leq type \leq 2; 1 \leq i,j \leq n; i≠j) $ .

If $ type $ = $ 1 $ , $ i $ -th car and $ j $ -th car are irrelevant. Otherwise, $ i $ -th car and $ j $ -th car are destined.

It is guaranteed that for each pair of cars, there are at most $ 1 $ relationship between.

## 输出格式

In the first line, print either "YES" or "NO" (in any case), whether it is possible to restore the orientations and the locations of the cars satisfying the relationships.

If the answer is "YES", print $ n $ lines each containing a symbol and an integer: $ ori_i $ and $ x_i $ $ (ori_i \in \{L, R\}; -10^9 \leq x_i \leq 10^9) $ — representing the information of the $ i $ -th car.

If the orientation is left, then $ ori_i $ = $ L $ . Otherwise $ ori_i $ = $ R $ .

 $ x_i $ is the where the $ i $ -th car is located. Note that all $ x_i $ should be distinct.

We can prove that if there exists a solution, then there must be a solution satisfying the constraints on $ x_i $ .

## 输入输出样例 #1

### 输入 #1

```
4 4
1 1 2
1 2 3
2 3 4
2 4 1
```

### 输出 #1

```
YES
R 0
L -3
R 5
L 6
```

## 输入输出样例 #2

### 输入 #2

```
3 3
1 1 2
1 2 3
1 1 3
```

### 输出 #2

```
NO
```