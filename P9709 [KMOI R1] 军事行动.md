# P9709 [KMOI R1] 军事行动

## 题目背景

$$\blue{他们来了。}$$

$$\purple{集结军队，干掉他们，一个不留。}$$

$$\blue{是！}$$

## 题目描述

喵星边境局势愈发紧张，导致发生边境冲突。喵星军队总司令小袁立即对 $Y$ 星采取军事行动。

整个宇宙可以看作一个平面直角坐标系，城市 $1,2,\dots,n$ 的坐标分别为 $(x_1,y_1),(x_2,y_2),\dots(x_n,y_n)$。

现在小袁率领的**若干支**舰队（可以理解为小袁的军事力量是无限的）驻扎在边境要塞，城市 $1$ 处。他的舰队会进行以下移动：

- 如果舰队的坐标为 $(x,y)$，那么一天之后它可以移动到 $(x-1,y+2)$ 或 $(x+1,y+2)$ 或 $(x+2,y+1)$ 或 $(x-2,y+1)$ 或 $(x-1,y-2)$ 或 $(x+1,y-2)$ 或 $(x+2,y-1)$ 或 $(x-2,y-1)$ 处。

其中环绕在外的还有一条小行星带，当舰队的坐标  $(x,y)$ 且 $x\le 0$ 或 $y\le 0$ 或 $m < x$ 或 $m < y$ 时，舰队就会撞到小行星带。这是小袁所不想看到的。

现在小袁要攻打城市 $2,3,\dots,n$，每一次他都会从一个**已经占领**的城市（城市 $1$ 也算），派出舰队前往城市 $i$ 并攻打它，舰队**到达之后的第二天**城市 $i$ 就被攻占了。

特别的，小袁在一个舰队**前往攻打或攻打一个城市**的时候不会派出另外一支舰队，在**攻占一座城市后当天**可以立即派出另外一支舰队。

小袁想问，最少要花多少时间才能攻占所有的城市。

**攻打顺序可以不按照 $2,3\dots n$ 的顺序。**

## 输入格式

第一行一个整数 $n,m$，表示城市个数和小行星带的范围。

接下来 $n$ 行，每一行两个正整数 $(x_i,y_i)$，表示城市 $i$ 的坐标。**保证 $1\le x_i,y_i \le m$**。

## 输出格式

一个整数 $ans$，表示最少要花的时间。

## 输入输出样例 #1

### 输入 #1

```
2 20
1 1
1 3
```

### 输出 #1

```
3
```

## 输入输出样例 #2

### 输入 #2

```
3 150
1 2
2 4
4 3
```

### 输出 #2

```
4
```

## 输入输出样例 #3

### 输入 #3

```
10 10
1 4
2 3
2 6
3 6
10 3
1 5
4 2
5 3
2 8
9 2
```

### 输出 #3

```
23
```

## 输入输出样例 #4

### 输入 #4

```
查看附件的 example4.in
```

### 输出 #4

```
查看附件的 example4.out
```

## 说明/提示

## 样例一解释：

舰队在第一天来到了 $(3,2)$ 的位置，第二天到达了城市 $2$ 的位置，第三天占领了城市 $2$。总共花了 $3$ 天。

## 样例二解释：

舰队在第一天到达了城市 $2$ 的位置，第二天占领了城市 $2$。第三天到达了城市 $3$ 的位置，第四天占领了城市 $3$。总共花了 $4$ 天。

## 数据范围

**本题采用 Subtask 捆绑测试。**

|子任务编号|  测试点编号| $n$ | $m$ |特殊性质|分值|
|:-----:| :----------: | :----------: | :----------: | :----------: |:---:|
|$1$| $1\sim2$ | $1\le n\le 7$ |$4\le m\le 7$|无|$10$|
|$2$| $3\sim7$ | $1\le n\le 200$ |$4\le m\le 70$|无|$25$|
|$3$| $8\sim9$ | $1\le n\le 150$ |$4\le m\le 150$|有|$15$|
|$4$| $10\sim20$ | $1\le n\le 2000$ |$4\le m\le 150$|无|$50$|

特殊性质：对于每一个 $1\le i\le n-1$，都有 $x_i = x_{i+1}$。

**数据严格保证不会有不同的城市拥有相同的坐标。**

---

# P9709 [KMOI R1] Military Operation

## 题目背景

$$\blue{They are coming.}$$

$$\purple{Assemble the army, take them out, leave none alive.}$$

$$\blue{Yes!}$$

## 题目描述

The situation on the Meow Planet’s border is getting more and more tense, leading to border conflicts. The commander-in-chief of the Meow Planet’s army, Xiao Yuan, immediately launches a military operation against Planet $Y$.

The entire universe can be viewed as a 2D Cartesian coordinate system. Cities $1,2,\dots,n$ are located at $(x_1,y_1),(x_2,y_2),\dots,(x_n,y_n)$, respectively.

Now Xiao Yuan commands **several** fleets (you may understand this as Xiao Yuan having unlimited military power) stationed at the border fortress, City $1$. His fleets move as follows:

- If a fleet is at coordinate $(x,y)$, then after one day it can move to $(x-1,y+2)$, $(x+1,y+2)$, $(x+2,y+1)$, $(x-2,y+1)$, $(x-1,y-2)$, $(x+1,y-2)$, $(x+2,y-1)$, or $(x-2,y-1)$.

Surrounding the outside is an asteroid belt. When a fleet is at coordinate $(x,y)$ and $x \le 0$ or $y \le 0$ or $m < x$ or $m < y$, the fleet will crash into the asteroid belt, which is something Xiao Yuan does not want.

Now Xiao Yuan wants to attack Cities $2,3,\dots,n$. Each time, he will dispatch a fleet from a city that has **already been occupied** (City $1$ also counts), send it to City $i$, and attack it. City $i$ will be occupied **on the second day after the fleet arrives**.

In particular, while Xiao Yuan is sending a fleet to attack or is attacking a city, he will not dispatch another fleet. On the **same day** a city is occupied, he can immediately dispatch another fleet.

Xiao Yuan wants to know the minimum time needed to occupy all cities.

**The attack order does not need to follow $2,3,\dots,n$.**

## 输入格式

The first line contains two integers $n,m$, representing the number of cities and the range of the asteroid belt.

The next $n$ lines each contain two positive integers $(x_i,y_i)$, representing the coordinates of City $i$. **It is guaranteed that $1 \le x_i,y_i \le m$.**

## 输出格式

Output one integer $ans$, representing the minimum time required.

## 输入输出样例 #1

### 输入 #1

```
2 20
1 1
1 3
```

### 输出 #1

```
3
```

## 输入输出样例 #2

### 输入 #2

```
3 150
1 2
2 4
4 3
```

### 输出 #2

```
4
```

## 输入输出样例 #3

### 输入 #3

```
10 10
1 4
2 3
2 6
3 6
10 3
1 5
4 2
5 3
2 8
9 2
```

### 输出 #3

```
23
```

## 输入输出样例 #4

### 输入 #4

```
查看附件的 example4.in
```

### 输出 #4

```
查看附件的 example4.out
```

## 说明/提示

## Explanation for Sample 1.

On day 1, the fleet arrives at position $(3,2)$. On day 2, it reaches the position of City $2$. On day 3, it occupies City $2$. A total of $3$ days are used.

## Explanation for Sample 2.

On day 1, the fleet reaches the position of City $2$. On day 2, it occupies City $2$. On day 3, it reaches the position of City $3$. On day 4, it occupies City $3$. A total of $4$ days are used.

## Constraints

**This problem uses bundled Subtask testdata.**

| Subtask ID | Test Point ID | $n$ | $m$ | Special Property | Score |
|:-----:| :----------: | :----------: | :----------: | :----------: |:---:|
| $1$ | $1\sim2$ | $1\le n\le 7$ | $4\le m\le 7$ | None | $10$ |
| $2$ | $3\sim7$ | $1\le n\le 200$ | $4\le m\le 70$ | None | $25$ |
| $3$ | $8\sim9$ | $1\le n\le 150$ | $4\le m\le 150$ | Yes | $15$ |
| $4$ | $10\sim20$ | $1\le n\le 2000$ | $4\le m\le 150$ | None | $50$ |

Special property: For every $1 \le i \le n-1$, we have $x_i = x_{i+1}$.

**The testdata strictly guarantees that no two different cities share the same coordinates.**

Translated by ChatGPT 5