# P8161 [JOI 2022 Final] 自学 / Self Study

## 题目描述

在 JOI 高中高一的第三个学期的 $M$ 个星期的时间内，有 $N$ 门课，编号为 $1 \sim N$。每个星期有 $N$ 个课时，第 $i$ 个课时上课程 $i$ 的一节课。

比太郎是一位高一学生。对于 $N \times M$ 个课时中的每一个，他会选择如下行动中的一个：

- 行动 1：比太郎去上课。如果他去上了课程 $i$ 的一节课，那么他对课程 $i$ 的理解程度会增加 $A_i$。
- 行动 2：比太郎不去上课。他转而选择任意一门课，并且自学选中的那门课。如果他选中了课程 $i$ 进行了时长为一课时的自学，那么他对课程 $i$ 的理解程度会增加 $B_i$。

一开始，对每门课的理解程度都为 $0$。由于比太郎想要在课后练习算法竞赛，他在非上课时间内不会学习。当第三个学期的所有课时结束后，期末考就会举行。

比太郎不想挂科。所以他想要最大化在期末考时对每门课的理解程度的最小值。

给定学期的长度，课程的数量，以及对理解程度的提升数值，请写一个程序计算在期末考时对每门课的理解程度的最小值的最大可能值。

## 输入格式

第一行，两个正整数 $N, M$。

第二行，$N$ 个正整数 $A_1, A_2, \ldots, A_N$。

第三行，$N$ 个正整数 $B_1, B_2, \ldots, B_N$。

## 输出格式

输出一行，一个数，表示在期末考时对每门课的理解程度的最小值的最大可能值。

## 输入输出样例 #1

### 输入 #1

```
3 3
19 4 5
2 6 2

```

### 输出 #1

```
18

```

## 输入输出样例 #2

### 输入 #2

```
2 1
9 7
2 6

```

### 输出 #2

```
7

```

## 输入输出样例 #3

### 输入 #3

```
5 60000
630510219 369411957 874325200 990002527 567203997
438920902 634940661 593780254 315929832 420627496

```

### 输出 #3

```
41397427274960

```

## 输入输出样例 #4

### 输入 #4

```
4 25
1 2 3 4
1 2 3 4

```

### 输出 #4

```
48

```

## 说明/提示

**【样例解释 \#1】**

举个例子，如果比太郎按如下方式学习，则他对课程 $1, 2, 3$ 的理解程度将分别为 $19, 18, 19$。

- 第一周课程 $1$ 的课：自学课程 $2$；
- 第一周课程 $2$ 的课：自学课程 $2$；
- 第一周课程 $3$ 的课：去上课程 $3$ 的课；
- 第二周课程 $1$ 的课：去上课程 $1$ 的课；
- 第二周课程 $2$ 的课：自学课程 $3$；
- 第二周课程 $3$ 的课：去上课程 $3$ 的课；
- 第三周课程 $1$ 的课：自学课程 $3$；
- 第三周课程 $2$ 的课：自学课程 $2$；
- 第三周课程 $3$ 的课：去上课程 $3$ 的课。

由于对每门课的最小的理解程度不能大于等于 $19$，输出 $18$。

这个样例满足子任务 $3, 5$ 的限制。

**【样例解释 \#2】**

这个样例满足子任务 $1, 3, 5$ 的限制。

**【样例解释 \#3】**

这个样例满足子任务 $3, 5$ 的限制。

**【样例解释 \#4】**

这个样例满足子任务 $2, 3, 4, 5$ 的限制。

----

**【数据范围】**

**本题采用捆绑测试。**

对于 $100 \%$ 的数据，$1 \le N \le 3 \times {10}^5$，$1 \le M \le {10}^9$，$1 \le A_i, B_i \le {10}^9$。

- 子任务 $1$（$10$ 分）：$M = 1$。
- 子任务 $2$（$25$ 分）：$N \cdot M \le 3 \times {10}^5$，$A_i = B_i$。
- 子任务 $3$（$27$ 分）：$N \cdot M \le 3 \times {10}^5$。
- 子任务 $4$（$29$ 分）：$A_i = B_i$。
- 子任务 $5$（$9$ 分）：无特殊限制。

----

**译自 [JOI 2022 Final](https://www.ioi-jp.org/joi/2021/2022-ho/index.html) T2「[自習](https://www.ioi-jp.org/joi/2021/2022-ho/2022-ho-t2.pdf) / [Self Study](https://www.ioi-jp.org/joi/2021/2022-ho/2022-ho-t2-en.pdf)」**

---

# P8161 [JOI 2022 Final] Self Study / Self Study

## 题目描述

During the third term of the first year at JOI High School, which lasts for $M$ weeks, there are $N$ subjects numbered $1 \sim N$. Each week has $N$ class periods. In period $i$, there is a class of subject $i$.

Bitaro is a first-year high school student. For each of the $N \times M$ class periods, he will choose one of the following actions:

- Action 1: Bitaro attends the class. If he attends one class of subject $i$, then his level of understanding of subject $i$ increases by $A_i$.
- Action 2: Bitaro does not attend the class. Instead, he chooses any subject and does self-study for that subject. If he chooses subject $i$ and self-studies for one class period, then his level of understanding of subject $i$ increases by $B_i$.

At the beginning, his level of understanding for every subject is $0$. Since Bitaro wants to practice programming contests after school, he will not study outside of class periods. After all class periods in the third term end, the final exams will be held.

Bitaro does not want to fail. Therefore, he wants to maximize the minimum value of his level of understanding among all subjects at the time of the final exams.

Given the term length, the number of subjects, and the increase values of understanding, write a program to compute the maximum possible value of the minimum level of understanding among all subjects at the time of the final exams.

## 输入格式

The first line contains two positive integers $N, M$.

The second line contains $N$ positive integers $A_1, A_2, \ldots, A_N$.

The third line contains $N$ positive integers $B_1, B_2, \ldots, B_N$.

## 输出格式

Output one line containing one number, which is the maximum possible value of the minimum level of understanding among all subjects at the time of the final exams.

## 输入输出样例 #1

### 输入 #1

```
3 3
19 4 5
2 6 2

```

### 输出 #1

```
18

```

## 输入输出样例 #2

### 输入 #2

```
2 1
9 7
2 6

```

### 输出 #2

```
7

```

## 输入输出样例 #3

### 输入 #3

```
5 60000
630510219 369411957 874325200 990002527 567203997
438920902 634940661 593780254 315929832 420627496

```

### 输出 #3

```
41397427274960

```

## 输入输出样例 #4

### 输入 #4

```
4 25
1 2 3 4
1 2 3 4

```

### 输出 #4

```
48

```

## 说明/提示

**[Sample Explanation #1]**

For example, if Bitaro studies in the following way, then his levels of understanding of subjects $1, 2, 3$ will be $19, 18, 19$, respectively.

- Week 1, subject $1$ period: self-study subject $2$.
- Week 1, subject $2$ period: self-study subject $2$.
- Week 1, subject $3$ period: attend the class of subject $3$.
- Week 2, subject $1$ period: attend the class of subject $1$.
- Week 2, subject $2$ period: self-study subject $3$.
- Week 2, subject $3$ period: attend the class of subject $3$.
- Week 3, subject $1$ period: self-study subject $3$.
- Week 3, subject $2$ period: self-study subject $2$.
- Week 3, subject $3$ period: attend the class of subject $3$.

Since the minimum level of understanding among all subjects cannot be greater than or equal to $19$, output $18$.

This sample satisfies the constraints of subtasks $3, 5$.

**[Sample Explanation #2]**

This sample satisfies the constraints of subtasks $1, 3, 5$.

**[Sample Explanation #3]**

This sample satisfies the constraints of subtasks $3, 5$.

**[Sample Explanation #4]**

This sample satisfies the constraints of subtasks $2, 3, 4, 5$.

----

**[Constraints]**

**This problem uses bundled testdata.**

For all testdata ($100\%$), $1 \le N \le 3 \times {10}^5$, $1 \le M \le {10}^9$, $1 \le A_i, B_i \le {10}^9$.

- Subtask $1$ ($10$ points): $M = 1$.
- Subtask $2$ ($25$ points): $N \cdot M \le 3 \times {10}^5$, $A_i = B_i$.
- Subtask $3$ ($27$ points): $N \cdot M \le 3 \times {10}^5$.
- Subtask $4$ ($29$ points): $A_i = B_i$.
- Subtask $5$ ($9$ points): no additional constraints.

----

Translated from [JOI 2022 Final](https://www.ioi-jp.org/joi/2021/2022-ho/index.html) T2 “[自習](https://www.ioi-jp.org/joi/2021/2022-ho/2022-ho-t2.pdf) / [Self Study](https://www.ioi-jp.org/joi/2021/2022-ho/2022-ho-t2-en.pdf)”.

Translated by ChatGPT 5