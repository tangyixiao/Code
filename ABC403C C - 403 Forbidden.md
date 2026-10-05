# AT_abc403_c [ABC403C] 403 Forbidden

## 题目描述

[problemUrl]: https://atcoder.jp/contests/abc403/tasks/abc403_c

WAtCoder 有 $N$ 个用户，编号从 $1$ 到 $N$。还有 $M$ 个比赛页面，编号从 $1$ 到 $M$。初始时，所有用户都没有任何比赛页面的访问权限。

现在需要依次处理 $Q$ 个查询。查询共有三种类型，格式如下：

- `1 X Y`：授予用户 $X$ 访问比赛页面 $Y$ 的权限。
- `2 X`：授予用户 $X$ 访问所有比赛页面的权限。
- `3 X Y`：查询用户 $X$ 是否可以访问比赛页面 $Y$。

注意：在查询过程中，可能会多次授予某个用户已经拥有的权限。

## 输入格式

输入通过标准输入给出，格式如下：

> $N$ $M$ $Q$  
> $\mathrm{query}_1$  
> $\mathrm{query}_2$  
> $\vdots$  
> $\mathrm{query}_Q$

每个查询 $\mathrm{query}_i$ 是以下三种形式之一：

> $1$ $X$ $Y$  
> $2$ $X$  
> $3$ $X$ $Y$

## 输出格式

对于每个类型为 `3` 的查询，如果用户 $X$ 可以访问比赛页面 $Y$，则输出 `Yes`，否则输出 `No`。每个查询的结果单独占一行。

## 输入输出样例 #1

### 输入 #1

```
2 3 5
1 1 2
3 1 1
3 1 2
2 2
3 2 3
```

### 输出 #1

```
No
Yes
Yes
```

## 输入输出样例 #2

### 输入 #2

```
5 5 10
2 2
3 4 4
1 1 1
1 4 1
1 4 2
1 4 4
1 2 4
3 3 2
3 5 4
3 2 1
```

### 输出 #2

```
No
No
No
Yes
```

## 说明/提示

### 约束条件

- $1 \leq N \leq 2 \times 10^5$
- $1 \leq M \leq 2 \times 10^5$
- $1 \leq Q \leq 2 \times 10^5$
- $1 \leq X \leq N$
- $1 \leq Y \leq M$
- 输入中的所有值均为整数

### 样例解释 #1

- 第一个查询授予用户 $1$ 访问比赛页面 $2$ 的权限。
- 第二个查询时，用户 $1$ 只能访问比赛页面 $2$，因此查询页面 $1$ 时输出 `No`。
- 第三个查询时，用户 $1$ 可以访问比赛页面 $2$，因此输出 `Yes`。
- 第四个查询授予用户 $2$ 访问所有比赛页面的权限。
- 第五个查询时，用户 $2$ 可以访问所有页面（$1,2,3$），因此查询页面 $3$ 时输出 `Yes`。

翻译由 DeepSeek V3 完成

---

# AT_abc403_c [ABC403C] 403 Forbidden

## 题目描述

There are  $ N $  users on WAtCoder, numbered from  $ 1 $  to  $ N $ , and  $ M $  contest pages, numbered from  $ 1 $  to  $ M $ . Initially, no user has view permission for any contest page.

You are given  $ Q $  queries to process in order. Each query is of one of the following three types:

- `1 X Y`: Grant user  $ X $  view permission for contest page  $ Y $ .
- `2 X`: Grant user  $ X $  view permission for all contest pages.
- `3 X Y`: Answer whether user  $ X $  can view contest page  $ Y $ .

It is possible for a user to be granted permission for the same contest page multiple times.

## 输入格式

The input is given from Standard Input in the following format:

> $ N $   $ M $   $ Q $  $ \mathrm{query}_1 $  $ \mathrm{query}_2 $  $ \vdots $  $ \mathrm{query}_Q $

Each  $ \mathrm{query}_i $  is in one of the following formats:

> $ 1 $   $ X $   $ Y $

> $ 2 $   $ X $

> $ 3 $   $ X $   $ Y $

## 输出格式

For each query of the third type, print `Yes` if user  $ X $  can view contest page  $ Y $ , otherwise print `No`, each on its own line.

## 输入输出样例 #1

### 输入 #1

```
2 3 5
1 1 2
3 1 1
3 1 2
2 2
3 2 3
```

### 输出 #1

```
No
Yes
Yes
```

## 输入输出样例 #2

### 输入 #2

```
5 5 10
2 2
3 4 4
1 1 1
1 4 1
1 4 2
1 4 4
1 2 4
3 3 2
3 5 4
3 2 1
```

### 输出 #2

```
No
No
No
Yes
```

## 说明/提示

### Sample Explanation 1

- In the first query, user  $ 1 $  is granted permission to view contest page  $ 2 $ .
- At the second query, user  $ 1 $  can view only page  $ 2 $ ; they cannot view page  $ 1 $ , so print `No`.
- At the third query, user  $ 1 $  can view page  $ 2 $ , so print `Yes`.
- In the fourth query, user  $ 2 $  is granted permission to view all pages.
- At the fifth query, user  $ 2 $  can view pages  $ 1,2,3 $ ; they can view page  $ 3 $ , so print `Yes`.

### Constraints

- $ 1 \le N \le 2\times 10^5 $
- $ 1 \le M \le 2\times 10^5 $
- $ 1 \le Q \le 2\times 10^5 $
- $ 1 \le X \le N $
- $ 1 \le Y \le M $
- All input values are integers.