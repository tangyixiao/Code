# CF1062E Company

## 题目描述

公司 $X$ 有 $n$ 名员工，编号从 $1$ 到 $n$。每个员工 $u$ 都有一个直属上司 $p_u$（$1 \le p_u \le n$），但员工 $1$ 没有上司。保证所有 $p_i$ 构成一棵树。若员工 $u$ 是员工 $v$ 的直属上司，或存在某个员工 $w$，使得 $w$ 负责 $v$，且 $u$ 是 $w$ 的直属上司，则称 $u$ 负责 $v$。此外，任何员工都被认为负责自己。

对于每个员工 $u$，定义其级别 $lv(u)$ 如下：

- $lv(1)=0$
- $lv(u)=lv(p_u)+1$，其中 $u \neq 1$

未来公司有 $q$ 个可能的运营方案。第 $i$ 个方案包含两个整数 $l_i$ 和 $r_i$，表示编号在区间 $[l_i, r_i]$ 内的所有员工（且仅这些员工）参与该方案。为了顺利执行方案，必须有一名项目经理，且该项目经理需要负责所有参与的员工。即，若选择员工 $u$ 作为第 $i$ 个方案的项目经理，则对于每个 $v \in [l_i, r_i]$，$u$ 必须负责 $v$。注意，$u$ 不一定在 $[l_i, r_i]$ 区间内。此外，$u$ 总是选择级别 $lv(u)$ 尽可能大的员工（级别越高，工资越低）。

在任何方案执行前，公司让 JATC 检查了他们的方案。JATC 一眼就发现，对于每个方案，都可以恰好减少一名参与员工而不影响方案的执行。公司出于节省成本的目的，询问 JATC 应该将哪位员工从方案中剔除，才能使所需项目经理的级别最大。JATC 已经知道答案，现在挑战你来解决这个问题。

## 输入格式

第一行包含两个整数 $n$ 和 $q$（$2 \le n \le 100\,000$，$1 \le q \le 100\,000$），分别表示员工人数和方案数。

第二行包含 $n-1$ 个整数 $p_2, p_3, \dots, p_n$（$1 \le p_i \le n$），表示员工 $i$ 的直属上司为 $p_i$。

保证所有 $p_i$ 构成以 $1$ 为根的有向树。

接下来的 $q$ 行，每行包含两个整数 $l_i$ 和 $r_i$（$1 \le l_i < r_i \le n$），表示第 $i$ 个方案涉及的员工编号区间。

## 输出格式

输出 $q$ 行，每行包含两个整数，分别表示应从对应方案中剔除的员工编号，以及此时所需项目经理的最大可能级别。

如果有多种选择，输出任意一种均可。

## 输入输出样例 #1

### 输入 #1

```
11 5
1 1 3 3 3 4 2 7 7 6
4 6
4 8
1 11
9 11
8 11

```

### 输出 #1

```
4 1
8 1
1 0
11 3
8 1

```

## 说明/提示

例如：

![](https://cdn.luogu.com.cn/upload/vjudge_pic/CF1062E/4564b9c828c9be95a53a01799338a14403d69e77.png)

在第一个询问中，可以选择剔除 $4$、$5$ 或 $6$，此时项目经理为 $3$。

在第二个询问中，若剔除除 $8$ 以外的任意员工，项目经理为 $1$。若剔除 $8$，项目经理为 $3$。由于 $lv(3)=1 > lv(1)=0$，所以选择剔除 $8$ 最优。

在第三个询问中，无论剔除哪位员工，项目经理都只能是 $1$。

在第四个询问中，若剔除 $9$ 或 $10$，项目经理为 $3$；若剔除 $11$，项目经理为 $7$。由于 $lv(7)=3>lv(3)=1$，所以选择剔除 $11$。

由 ChatGPT 4.1 翻译

---



# CF1062E Company

## 题目描述

The company $ X $ has $ n $ employees numbered from $ 1 $ through $ n $ . Each employee $ u $ has a direct boss $ p_u $ ( $ 1 \le p_u \le n $ ), except for the employee $ 1 $ who has no boss. It is guaranteed, that values $ p_i $ form a tree. Employee $ u $ is said to be in charge of employee $ v $ if $ u $ is the direct boss of $ v $ or there is an employee $ w $ such that $ w $ is in charge of $ v $ and $ u $ is the direct boss of $ w $ . Also, any employee is considered to be in charge of himself.

In addition, for each employee $ u $ we define it's level $ lv(u) $ as follow:

- $ lv(1)=0 $
- $ lv(u)=lv(p_u)+1 $ for $ u \neq 1 $

In the near future, there are $ q $ possible plans for the company to operate. The $ i $ -th plan consists of two integers $ l_i $ and $ r_i $ , meaning that all the employees in the range $ [l_i, r_i] $ , and only they, are involved in this plan. To operate the plan smoothly, there must be a project manager who is an employee in charge of all the involved employees. To be precise, if an employee $ u $ is chosen as the project manager for the $ i $ -th plan then for every employee $ v \in [l_i, r_i] $ , $ u $ must be in charge of $ v $ . Note, that $ u $ is not necessary in the range $ [l_i, r_i] $ . Also, $ u $ is always chosen in such a way that $ lv(u) $ is as large as possible (the higher the level is, the lower the salary that the company has to pay the employee).

Before any plan is operated, the company has JATC take a look at their plans. After a glance, he tells the company that for every plan, it's possible to reduce the number of the involved employees exactly by one without affecting the plan. Being greedy, the company asks JATC which employee they should kick out of the plan so that the level of the project manager required is as large as possible. JATC has already figured out the answer and challenges you to do the same.

## 输入格式

The first line contains two integers $ n $ and $ q $ ( $ 2 \le n \le 100\,000 $ , $ 1 \le q \le 100\,000 $ ) — the number of employees and the number of plans, respectively.

The second line contains $ n-1 $ integers $ p_2, p_3, \dots, p_n $ ( $ 1 \le p_i \le n $ ) meaning $ p_i $ is the direct boss of employee $ i $ .

It is guaranteed, that values $ p_i $ form a directed tree with the root of $ 1 $ .

Each of the following $ q $ lines contains two integers $ l_i $ and $ r_i $ ( $ 1 \le l_i<r_i \le n $ ) — the range of the employees, involved in the corresponding plan.

## 输出格式

Print $ q $ lines, each containing two integers — the number of the employee which should be kicked from the corresponding plan and the maximum possible level of the project manager in that case.

If there are more than one way to choose that employee, print any of them.

## 输入输出样例 #1

### 输入 #1

```
11 5
1 1 3 3 3 4 2 7 7 6
4 6
4 8
1 11
9 11
8 11

```

### 输出 #1

```
4 1
8 1
1 0
11 3
8 1

```

## 说明/提示

In the example:

 ![](https://cdn.luogu.com.cn/upload/vjudge_pic/CF1062E/4564b9c828c9be95a53a01799338a14403d69e77.png) In the first query, we can choose whether $ 4 $ or $ 5 $ or $ 6 $ and the project manager will be $ 3 $ .In the second query, if we choose any employee other than the employee $ 8 $ , the project manager will be $ 1 $ . If we choose $ 8 $ , the project manager will be $ 3 $ . Since $ lv(3)=1 > lv(1)=0 $ , choosing $ 8 $ is the best strategy.

In the third query, no matter how we choose the employee, the project manager will always be $ 1 $ .

In the fourth query, if we choose $ 9 $ or $ 10 $ then the project manager will be $ 3 $ . If we choose $ 11 $ then the project manager will be $ 7 $ . Since $ lv(7)=3>lv(3)=1 $ , we choose $ 11 $ as the answer.
