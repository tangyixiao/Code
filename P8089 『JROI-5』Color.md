# P8089 『JROI-5』Color

## 题目背景

【被三月删除的图片】

泷泽三月 Orz

---
被删除图片会偷偷展示给报名讲评的同学（

## 题目描述

**请注意到并不正常的时间限制。**

小 C 有一棵 $dep$ 层 $n$ 个节点的**完全二叉树**，她希望选择其中一个**包含根节点**的**连通块**染色，她想知道有几种不同的染色方案，答案对 $998,244,353$ 取模。

## 输入格式

多测，第一行一个整数 $T$，表示测试组数。

**对于每组数据**

第一行一个整数 $dep$，同题意。

第二行一个整数 $s$，表示最底层叶子结点数目，特别的，他们将用二进制表示，你将读入一个 $dep$ 位 $\texttt{01}$ 串，用以表示 $s$，若转换为二进制后不足 $dep$ 位则用前缀 $0$ 补充。


**保证数据合法。**

## 输出格式

对于每组数据，一行一个整数，表示合法的染色方案的个数，需要**换行**。

## 输入输出样例 #1

### 输入 #1

```
1
2
10
```

### 输出 #1

```
4
```

## 输入输出样例 #2

### 输入 #2

```
1
3
100
```

### 输出 #2

```
25
```

## 输入输出样例 #3

### 输入 #3

```
1
3
010
```

### 输出 #3

```
10
```

## 输入输出样例 #4

### 输入 #4

```
见附件
```

### 输出 #4

```
见附件
```

## 说明/提示

你可以通过学习 [OI-Wiki 树基础](https://oi-wiki.org/graph/tree-basic/) 来了解题面中的名词。

【样例解释】

对于样例 #1，可以画出如下所示二叉树。

![7sc6Yj.png](https://s4.ax1x.com/2022/01/19/7sc6Yj.png)

我们对该二叉树按照**前序遍历标号**（如图），得到点集 $\left(1,2,3\right)$。

则仅有 $\left(1,2,3\right),\left(1,2\right),\left(1,3\right),\left(1\right)$ 是合法的染色方案。
****
对于样例 #3，可以画出如下所示二叉树。

![7sc1eO.png](https://s4.ax1x.com/2022/01/19/7sc1eO.png)

我们对该二叉树按照**前序遍历标号**（如图），得到点集 $\left(1,2,3,4,5\right)$。

则仅有 $\left(1,2,3,4,5\right),\left(1,2,3,4\right),\left(1,2,3\right),\left(1,2,4\right),\left(1,2\right),\left(1,2,3,5\right),\left(1,2,4,5\right),\left(1,2,5\right),\left(1,5\right),\left(1\right)$ 是合法的染色方案。

显然 $\left(2,3,4\right),\left(1,3,4\right)$ 不是合法的染色方案，前者没有包含根节点，后者染色的点集不是联通的。
***
对于 $30\%$ 的数据，$1\leq T\leq 10, 1\leq dep \leq 20$。

对于另外 $20\%$ 的数据，树是满二叉树（即完美二叉树，perfect binary tree）。

对于 $100\%$ 的数据，$1\leq T\leq 10, 1\leq dep \leq 10^6$。

---

# P8089 "JROI-5" Color

## 题目背景

[Image deleted by March.]

Takizawa March Orz.

---

The deleted image will be secretly shown to the students who sign up for the editorial session (

## 题目描述

**Please note the unusual time limit.**

Little C has a **complete binary tree** with $dep$ levels and $n$ nodes. She wants to choose one **connected subgraph** that **contains the root node** and color it. She wants to know how many different coloring schemes there are. Output the answer modulo $998,244,353$.

## 输入格式

Multiple test cases. The first line contains an integer $T$, the number of test cases.

**For each test case:**

The first line contains an integer $dep$, as described above.

The second line contains an integer $s$, the number of leaf nodes on the bottom level. In particular, it will be given in binary: you will read a $dep$-bit $\texttt{01}$ string to represent $s$. If the binary representation has fewer than $dep$ bits, it is padded with leading $0$.

**It is guaranteed that the input is valid.**

## 输出格式

For each test case, output one integer per line, the number of valid coloring schemes. A **newline** is required.

## 输入输出样例 #1

### 输入 #1

```
1
2
10
```

### 输出 #1

```
4
```

## 输入输出样例 #2

### 输入 #2

```
1
3
100
```

### 输出 #2

```
25
```

## 输入输出样例 #3

### 输入 #3

```
1
3
010
```

### 输出 #3

```
10
```

## 输入输出样例 #4

### 输入 #4

```
见附件
```

### 输出 #4

```
见附件
```

## 说明/提示

You can learn the terms used in this statement by reading [OI-Wiki Tree Basics](https://oi-wiki.org/graph/tree-basic/).

[Sample Explanation]

For sample #1, you can draw the following binary tree.

![7sc6Yj.png](https://s4.ax1x.com/2022/01/19/7sc6Yj.png)

We label this binary tree in **preorder traversal** (as shown in the figure), obtaining the vertex set $\left(1,2,3\right)$.

Then only $\left(1,2,3\right),\left(1,2\right),\left(1,3\right),\left(1\right)$ are valid coloring schemes.
****
For sample #3, you can draw the following binary tree.

![7sc1eO.png](https://s4.ax1x.com/2022/01/19/7sc1eO.png)

We label this binary tree in **preorder traversal** (as shown in the figure), obtaining the vertex set $\left(1,2,3,4,5\right)$.

Then only $\left(1,2,3,4,5\right),\left(1,2,3,4\right),\left(1,2,3\right),\left(1,2,4\right),\left(1,2\right),\left(1,2,3,5\right),\left(1,2,4,5\right),\left(1,2,5\right),\left(1,5\right),\left(1\right)$ are valid coloring schemes.

Obviously, $\left(2,3,4\right)$ and $\left(1,3,4\right)$ are not valid coloring schemes: the former does not include the root node, and the latter is not connected.
***
For $30\%$ of the testdata, $1\leq T\leq 10, 1\leq dep \leq 20$.

For another $20\%$ of the testdata, the tree is a full binary tree (i.e. a perfect binary tree).

For $100\%$ of the testdata, $1\leq T\leq 10, 1\leq dep \leq 10^6$.

# Input Format



# Output Format



# Hint

Translated by ChatGPT 5