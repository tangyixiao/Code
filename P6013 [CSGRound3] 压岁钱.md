# P6013 [CSGRound3] 压岁钱

## 题目背景

祝大家庚子鼠年快乐！Best wishes! 

也愿肺炎早日得到控制吧，中国加油！

新年到了，小 Z 总是能收到很多的压岁钱。

小 Z 是个非常喜欢氪金的玩家，所以时不时都会把压岁钱花掉一部分用来买皮肤和石头。

但是小 Z 又十分担心压岁钱没过几天就都被自己花完了。为此，小 Z 有封印大法，能够暂时的把自己的一部分钱封印起来（即无法花费），直到某一天解除封印后才能使用。

## 题目描述

一共存在有 $m$ 个事件，且事件分为以下的 $3$ 种类型。

1. 小 Z 得到了 $a$ 元压岁钱。
2. 小 Z 花掉了 $a$ 元压岁钱用于买皮肤。
3. 小 Z 把自己的 $a$ 元钱封印了起来，只有当第 $b$ 个事件发生前 $1$ 秒才会解除封印，并保证每次小 Z 现有的钱大于等于封印的钱。

当小 Z 的钱在某个事件不够花时，小 Z 会感到不开心，同时钱不够花时小 Z 便不会花钱。

请告诉小 Z ，他的钱在几个事件中会不够花。

## 输入格式

第一行一个整数 $m$，用于表示事件发生的总数。

接下来的 $m$ 行，首先一个整数 $t$，表示事件的类型。

如果 $t=1$ 或 $t=2$，则接下来一个整数 $a$。

如果 $t=3$，则接下来两个整数 $a,b$。

## 输出格式

一行一个整数，表示**钱不够花**的事件数。

## 输入输出样例 #1

### 输入 #1

```
3
1 10
2 20
2 10
```

### 输出 #1

```
1
```

## 输入输出样例 #2

### 输入 #2

```
5
1 10
3 5 5
2 10
1 10
2 20
```

### 输出 #2

```
1
```

## 说明/提示

**【样例 1 解释】**

第一天：收入 $10$ 元，余额 $10$ 元。

第二天：不够支出 $20$ 元，余额 $10$ 元。

第三天：支出 $10$ 元，余额 $0$ 元。

总计：$1$ 天。

**【样例 2 解释】**

第一天：收入 $10$ 元，余额 $10$ 元。

第二天：封印 $5$ 元，余额 $5$ 元。

第三天：不够支出 $10$ 元，余额 $5$ 元。

第四天：收入 $10$ 元，余额 $15$ 元。

第五天：封印解开，支出 $20$ 元，余额 $0$ 元。

总计：$1$ 天。

---

**【数据范围】**

对于 $50\%$ 的数据，满足 $m,a \leq 5\times 10^3$。

对于 $70\%$ 的数据，$t \ne 3$。

对于 $100\%$ 的数据，满足 $ 1 \leq b \le m \leq 10^6$，$1 \le t \le 3$，$1 \leq a \leq 10^7$。

---

# P6013 [CSGRound3] Lucky Money

## 题目背景

Wishing everyone a happy Year of the Rat in the Gengzi year! Best wishes!

May the pneumonia outbreak be brought under control as soon as possible. Stay strong, China!

When the New Year comes, Xiao Z can always receive a lot of lucky money.

Xiao Z is a player who really likes spending money in games, so from time to time he will spend part of his lucky money to buy skins and gems.

But Xiao Z is also very worried that he will spend all his lucky money in just a few days. To deal with this, Xiao Z has a sealing technique that can temporarily seal away part of his money (meaning it cannot be spent). It can only be used after the seal is lifted on some day.

## 题目描述

There are $m$ events in total, and the events are divided into the following $3$ types.

1. Xiao Z receives $a$ yuan of lucky money.
2. Xiao Z spends $a$ yuan of lucky money to buy skins.
3. Xiao Z seals $a$ yuan of his money. The seal will be lifted $1$ second before event $b$ happens. It is guaranteed that each time, the money Xiao Z currently has is greater than or equal to the amount being sealed.

If Xiao Z does not have enough money to spend on some event, Xiao Z will feel unhappy. At the same time, when he does not have enough money, Xiao Z will not spend the money.

Please tell Xiao Z in how many events he will not have enough money to spend.

## 输入格式

The first line contains an integer $m$, which indicates the total number of events.

The next $m$ lines each start with an integer $t$, indicating the type of the event.

If $t=1$ or $t=2$, then it is followed by an integer $a$.

If $t=3$, then it is followed by two integers $a,b$.

## 输出格式

Output one line with one integer, indicating the number of events in which **there is not enough money to spend**.

## 输入输出样例 #1

### 输入 #1

```
3
1 10
2 20
2 10
```

### 输出 #1

```
1
```

## 输入输出样例 #2

### 输入 #2

```
5
1 10
3 5 5
2 10
1 10
2 20
```

### 输出 #2

```
1
```

## 说明/提示

**[Sample 1 Explanation]**

Day 1: Income $10$ yuan, balance $10$ yuan.

Day 2: Not enough to spend $20$ yuan, balance $10$ yuan.

Day 3: Spend $10$ yuan, balance $0$ yuan.

Total: $1$ day.

**[Sample 2 Explanation]**

Day 1: Income $10$ yuan, balance $10$ yuan.

Day 2: Seal $5$ yuan, balance $5$ yuan.

Day 3: Not enough to spend $10$ yuan, balance $5$ yuan.

Day 4: Income $10$ yuan, balance $15$ yuan.

Day 5: The seal is lifted, spend $20$ yuan, balance $0$ yuan.

Total: $1$ day.

---

**[Constraints]**

For $50\%$ of the testdata, $m,a \leq 5\times 10^3$.

For $70\%$ of the testdata, $t \ne 3$.

For $100\%$ of the testdata, $ 1 \leq b \le m \leq 10^6$, $1 \le t \le 3$, $1 \leq a \leq 10^7$.

Translated by ChatGPT 5