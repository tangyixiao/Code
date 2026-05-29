# P13190 [GCJ 2016 #1A] Rank and File

## 题目描述

当 Argus 军士的部队集合训练时，士兵们会站成一个 $\mathbf{N} \times \mathbf{N}$ 的正方形网格，每个格子里恰好有一名士兵。每位士兵都有一个确定的身高。

Argus 认为时刻关注每一位士兵非常重要。由于他喜欢从左上角观察整个方阵，他要求：

- 在每一行内，士兵的身高必须从左到右严格递增。
- 在每一列内，士兵的身高必须从上到下严格递增。

虽然同一行或同一列内不能有身高相同的士兵，但整个网格中可以有多名士兵身高相同。

由于士兵们有时会分别与自己所在的行或列进行训练，Argus 让你记录一份报告，内容包括 $2 \times \mathbf{N}$ 份士兵身高的列表：每一行（从左到右）和每一列（从上到下）各一份。当你巡视士兵时，你只能用很小的纸条记下每一份列表，因此每份列表都写在一张不同的纸条上。然而，在回办公室的路上，你被一声响亮的军号吓了一跳，所有纸条都掉在了地上，风把其中一张吹走了！剩下的纸条顺序已乱，你也不记得哪些是行、哪些是列，因为你没有记录这一点。

你知道，如果你交给 Argus 的报告不完整，他一定会让你做上百个俯卧撑。你能否找出缺失的那一份列表？

## 输入格式

输入的第一行包含一个整数 $\mathbf{T}$，表示测试用例的数量。接下来有 $\mathbf{T}$ 组测试用例。每组测试用例的第一行为一个整数 $\mathbf{N}$，接下来有 $2 \times \mathbf{N} - 1$ 行，每行包含 $\mathbf{N}$ 个整数，表示你记录下的列表，如题面所述。保证这些列表恰好是某个合法网格中全部行和列中除一份之外的所有列表。

## 输出格式

对于每组测试用例，输出一行 `Case #x: y`，其中 $x$ 表示测试用例编号（从 1 开始），$y$ 为缺失的那一份列表，包含 $\mathbf{N}$ 个严格递增的整数。

## 输入输出样例 #1

### 输入 #1

```
1
3
1 2 3
2 3 5
3 5 6
2 3 4
1 2 3
```

### 输出 #1

```
Case #1: 3 4 6
```

## 说明/提示

**样例解释**

在样例中，可能的方阵为：
```
1 2 3
2 3 4
3 5 6
```

或
```
1 2 3
2 3 5
3 4 6
```

无论哪种情况，缺失的列表都是 `3 4 6`。

**限制条件**

- $1 \leqslant \mathbf{T} \leqslant 50$。
- $1 \leqslant$ 所有身高 $\leqslant 2500$。
- 每行的整数均严格递增。
- 保证存在唯一的合法解。

**小数据集（14 分，测试集 1 - 可见）**

- $2 \leqslant \mathbf{N} \leqslant 10$。

**大数据集（21 分，测试集 2 - 隐藏）**

- $2 \leqslant \mathbf{N} \leqslant 50$。

翻译由 GPT4.1 完成。

---

# P13190 [GCJ 2016 #1A] Rank and File

## 题目描述

When Sergeant Argus's army assembles for drilling, they stand in the shape of an $\mathbf{N}$ by $\mathbf{N}$ square grid, with exactly one soldier in each cell. Each soldier has a certain height.

Argus believes that it is important to keep an eye on all of his soldiers at all times. Since he likes to look at the grid from the upper left, he requires that:

- Within every row of the grid, the soldiers' heights must be in strictly increasing order, from left to right.
- Within every column of the grid, the soldiers' heights must be in strictly increasing order, from top to bottom.

Although no two soldiers in the same row or column may have the same height, it is possible for multiple soldiers in the grid to have the same height.

Since soldiers sometimes train separately with their row or their column, Argus has asked you to make a report consisting of $2 \times \mathbf{N}$ lists of the soldiers' heights: one representing each row (in left-to-right order) and column (in top-to-bottom order). As you surveyed the soldiers, you only had small pieces of paper to write on, so you wrote each list on a separate piece of paper. However, on your way back to your office, you were startled by a loud bugle blast and you dropped all of the pieces of paper, and the wind blew one away before you could recover it! The other pieces of paper are now in no particular order, and you can't even remember which lists represent rows and which represent columns, since you didn't write that down.

You know that Argus will make you do hundreds of push-ups if you give him an incomplete report. Can you figure out what the missing list is?

## 输入格式

The first line of the input gives the number of test cases, $\mathbf{T}$. $\mathbf{T}$ test cases follow. Each consists of one line with an integer $\mathbf{N}$, followed by $2 \times \mathbf{N} - 1$ lines of $\mathbf{N}$ integers each, representing the lists you have, as described in the statement. It is guaranteed that these lists represent all but one of the rows and columns from a valid grid, as described in the statement.

## 输出格式

For each test case, output one line containing `Case #x: y`, where $x$ is the test case number (starting from 1) and $y$ is a list of $\mathbf{N}$ integers in strictly increasing order, representing the missing list.

## 输入输出样例 #1

### 输入 #1

```
1
3
1 2 3
2 3 5
3 5 6
2 3 4
1 2 3
```

### 输出 #1

```
Case #1: 3 4 6
```

## 说明/提示

**Sample Explanation**

In the sample case, the arrangement must be either this:
```
1 2 3
2 3 4
3 5 6
```
or this:
```
1 2 3
2 3 5
3 4 6
```
In either case, the missing list is `3 4 6`.

**Limits**

- $1 \leqslant \mathbf{T} \leqslant 50$.
- $1 \leqslant \text{all heights} \leqslant 2500$.
- The integers on each line will be in strictly increasing order.
- It is guaranteed that a unique valid answer exists.

**Small dataset (14 Pts, Test Set 1 - Visible)**

- $2 \leqslant \mathbf{N} \leqslant 10$.

**Large dataset (21 Pts, Test Set 2 - Hidden)**

- $2 \leqslant \mathbf{N} \leqslant 50$.