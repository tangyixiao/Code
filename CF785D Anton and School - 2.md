# CF785D Anton and School - 2

## 题目描述

你可能知道，Anton 在上学。他学的科目之一是括号学。在括号学的课程中，学生们通常学习由圆括号组成的各种序列（即字符 "(" 与 ")"（不带引号））。

在上一节课上，Anton 学习了“正规简单括号序列”（RSBS）。长度为 $n$ 的括号序列 $s$ 是 RSBS，当且仅当满足以下条件：

- 序列非空（即 $n \neq 0$）。
- 序列长度是偶数。
- 序列的开头 $\frac{n}{2}$ 个字符都是 "("。
- 序列的结尾 $\frac{n}{2}$ 个字符都是 ")"。

例如，序列 "((()))" 是 RSBS，但序列 "((())" 和 "(()())" 不是 RSBS。

Anton 的老师 Elena Ivanovna 给了他如下家庭作业。给定一个括号序列 $s$，请找出它的本质不同的子序列中属于 RSBS 的有多少个。注意，$s$ 的一个子序列是指通过删除 $s$ 的某些元素后得到的字符串。如果删除元素的位置集合不同，那么子序列即认为不同。

由于答案可能很大，而 Anton 的老师不喜欢大数，她要求 Anton 将答案对 $10^9+7$ 取模。

Anton 想了很久，但仍然不知道怎么解这道题。请你帮助 Anton 完成这道题，并编写程序输出答案！

## 输入格式

输入仅一行，为括号序列 $s$，即 Anton 的作业。字符串只包含字符 "(" 和 ")"（不带引号）。保证字符串非空，长度不超过 $200000$。

## 输出格式

输出一个整数，表示满足条件的本质不同 RSBS 子序列的个数，对 $10^9+7$ 取模。

## 输入输出样例 #1

### 输入 #1

```
)(()()

```

### 输出 #1

```
6

```

## 输入输出样例 #2

### 输入 #2

```
()()()

```

### 输出 #2

```
7

```

## 输入输出样例 #3

### 输入 #3

```
)))

```

### 输出 #3

```
0

```

## 说明/提示

在第一个样例中，满足条件的子序列有：

- 删除第 $1$ 和第 $5$ 个字符（下标从 $1$ 开始），得到 "(())"。
- 删除第 $1,\,2,\,3,\,4$ 个字符，得到 "()"。
- 删除第 $1,\,2,\,4,\,5$ 个字符，得到 "()"。
- 删除第 $1,\,2,\,5,\,6$ 个字符，得到 "()"。
- 删除第 $1,\,3,\,4,\,5$ 个字符，得到 "()"。
- 删除第 $1,\,3,\,5,\,6$ 个字符，得到 "()"。

其余子序列都不是 RSBS。所以共有 $6$ 个本质不同且为 RSBS 的子序列，因此答案为 $6$。

由 ChatGPT 5 翻译

---

# CF785D Anton and School - 2

## 题目描述

As you probably know, Anton goes to school. One of the school subjects that Anton studies is Bracketology. On the Bracketology lessons students usually learn different sequences that consist of round brackets (characters "(" and ")" (without quotes)).

On the last lesson Anton learned about the regular simple bracket sequences (RSBS). A bracket sequence $ s $ of length $ n $ is an RSBS if the following conditions are met:

- It is not empty (that is $ n≠0 $ ).
- The length of the sequence is even.
- First ![](https://cdn.luogu.com.cn/upload/vjudge_pic/CF785D/666f6519688863e0a36337875170dd12050e1c31.png) charactes of the sequence are equal to "(".
- Last ![](https://cdn.luogu.com.cn/upload/vjudge_pic/CF785D/666f6519688863e0a36337875170dd12050e1c31.png) charactes of the sequence are equal to ")".

For example, the sequence "((()))" is an RSBS but the sequences "((())" and "(()())" are not RSBS.

Elena Ivanovna, Anton's teacher, gave him the following task as a homework. Given a bracket sequence $ s $ . Find the number of its distinct subsequences such that they are RSBS. Note that a subsequence of $ s $ is a string that can be obtained from $ s $ by deleting some of its elements. Two subsequences are considered distinct if distinct sets of positions are deleted.

Because the answer can be very big and Anton's teacher doesn't like big numbers, she asks Anton to find the answer modulo $ 10^{9}+7 $ .

Anton thought of this task for a very long time, but he still doesn't know how to solve it. Help Anton to solve this task and write a program that finds the answer for it!

## 输入格式

The only line of the input contains a string $ s $ — the bracket sequence given in Anton's homework. The string consists only of characters "(" and ")" (without quotes). It's guaranteed that the string is not empty and its length doesn't exceed $ 200000 $ .

## 输出格式

Output one number — the answer for the task modulo $ 10^{9}+7 $ .

## 输入输出样例 #1

### 输入 #1

```
)(()()

```

### 输出 #1

```
6

```

## 输入输出样例 #2

### 输入 #2

```
()()()

```

### 输出 #2

```
7

```

## 输入输出样例 #3

### 输入 #3

```
)))

```

### 输出 #3

```
0

```

## 说明/提示

In the first sample the following subsequences are possible:

- If we delete characters at the positions $ 1 $ and $ 5 $ (numbering starts with one), we will get the subsequence "(())".
- If we delete characters at the positions $ 1 $ , $ 2 $ , $ 3 $ and $ 4 $ , we will get the subsequence "()".
- If we delete characters at the positions $ 1 $ , $ 2 $ , $ 4 $ and $ 5 $ , we will get the subsequence "()".
- If we delete characters at the positions $ 1 $ , $ 2 $ , $ 5 $ and $ 6 $ , we will get the subsequence "()".
- If we delete characters at the positions $ 1 $ , $ 3 $ , $ 4 $ and $ 5 $ , we will get the subsequence "()".
- If we delete characters at the positions $ 1 $ , $ 3 $ , $ 5 $ and $ 6 $ , we will get the subsequence "()".

The rest of the subsequnces are not RSBS. So we got $ 6 $ distinct subsequences that are RSBS, so the answer is $ 6 $ .