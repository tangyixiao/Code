# CF1537C Challenging Cliffs

## 题目描述

你是一名游戏设计师，想要制作一个障碍赛跑关卡。玩家将从左向右行进。你已经选定了 $n$ 座山的高度，并希望将它们排列，使得第一座和最后一座山的高度之差的绝对值尽可能小。

此外，你还希望让游戏更具挑战性。由于上坡或平地比下坡更难走，关卡的难度定义为满足 $h_i \leq h_{i+1}$ 的山峰数量 $i$（$1 \leq i < n$），其中 $h_i$ 表示第 $i$ 座山的高度。你不想浪费任何已经建模的山峰，因此必须全部使用。

在所有能最小化 $|h_1-h_n|$ 的排列中，找到一个难度最大的排列。如果有多种满足要求的排列，你可以输出任意一种。

## 输入格式

第一行包含一个整数 $t$（$1 \leq t \leq 100$），表示测试用例的数量。接下来有 $t$ 组测试数据。

每组测试数据的第一行包含一个整数 $n$（$2 \leq n \leq 2 \cdot 10^5$），表示山峰的数量。

第二行包含 $n$ 个整数 $h_1,\ldots,h_n$（$1 \leq h_i \leq 10^9$），表示每座山的高度。

保证所有测试用例中 $n$ 的总和不超过 $2 \cdot 10^5$。

## 输出格式

对于每个测试用例，输出 $n$ 个整数，表示一种排列后的山峰高度顺序，使得在所有最小化 $|h_1-h_n|$ 的排列中，难度分数最大。

如果有多种满足要求的排列，你可以输出任意一种。

## 输入输出样例 #1

### 输入 #1

```
2
4
4 2 1 2
2
3 1
```

### 输出 #1

```
2 4 1 2 
1 3
```

## 说明/提示

第一组测试数据：

玩家从高度 $2$ 开始，接着上升到高度 $4$，难度增加 $1$。之后下降到高度 $1$，难度不变，因为是下坡。最后上升到高度 $2$，难度再增加 $1$。起点和终点的高度差的绝对值为 $0$，且为最小值。难度也达到了最大。

第二组测试数据：

玩家从高度 $1$ 开始，接着上升到高度 $3$，难度增加 $1$。起点和终点的高度差的绝对值为 $2$，且为最小值，因为只有这两个高度。难度也达到了最大。

由 ChatGPT 4.1 翻译

---

# CF1537C Challenging Cliffs

## 题目描述

You are a game designer and want to make an obstacle course. The player will walk from left to right. You have $ n $ heights of mountains already selected and want to arrange them so that the absolute difference of the heights of the first and last mountains is as small as possible.

In addition, you want to make the game difficult, and since walking uphill or flat is harder than walking downhill, the difficulty of the level will be the number of mountains $ i $ ( $ 1 \leq i < n $ ) such that $ h_i \leq h_{i+1} $ where $ h_i $ is the height of the $ i $ -th mountain. You don't want to waste any of the mountains you modelled, so you have to use all of them.

From all the arrangements that minimize $ |h_1-h_n| $ , find one that is the most difficult. If there are multiple orders that satisfy these requirements, you may find any.

## 输入格式

The first line will contain a single integer $ t $ ( $ 1 \leq t \leq 100 $ ) — the number of test cases. Then $ t $ test cases follow.

The first line of each test case contains a single integer $ n $ ( $ 2 \leq n \leq 2 \cdot 10^5 $ ) — the number of mountains.

The second line of each test case contains $ n $ integers $ h_1,\ldots,h_n $ ( $ 1 \leq h_i \leq 10^9 $ ), where $ h_i $ is the height of the $ i $ -th mountain.

It is guaranteed that the sum of $ n $ over all test cases does not exceed $ 2 \cdot 10^5 $ .

## 输出格式

For each test case, output $ n $ integers — the given heights in an order that maximizes the difficulty score among all orders that minimize $ |h_1-h_n| $ .

If there are multiple orders that satisfy these requirements, you may output any.

## 输入输出样例 #1

### 输入 #1

```
2
4
4 2 1 2
2
3 1
```

### 输出 #1

```
2 4 1 2 
1 3
```

## 说明/提示

In the first test case:

The player begins at height $ 2 $ , next going up to height $ 4 $ increasing the difficulty by $ 1 $ . After that he will go down to height $ 1 $ and the difficulty doesn't change because he is going downhill. Finally the player will go up to height $ 2 $ and the difficulty will increase by $ 1 $ . The absolute difference between the starting height and the end height is equal to $ 0 $ and it's minimal. The difficulty is maximal.

In the second test case:

The player begins at height $ 1 $ , next going up to height $ 3 $ increasing the difficulty by $ 1 $ . The absolute difference between the starting height and the end height is equal to $ 2 $ and it's minimal as they are the only heights. The difficulty is maximal.