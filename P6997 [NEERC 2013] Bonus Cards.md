# P6997 [NEERC 2013] Bonus Cards

## 题目描述

德米特里非常喜欢编程比赛。著名的冠军联赛决赛正在德米特里的家乡城市举行，所以他想去观看比赛。比赛非常受欢迎，但大多数门票都保留给 VIP 和赞助商。  

对于普通公众，冠军联赛决赛的门票以以下方式分发。希望观看比赛的观众提交他们的请求，说明他们希望用哪种支付方式来支付门票。假设有 $n$ 个可用座位。进行若干轮抽签。在每一轮中，每个尚未满足的请求根据支付方式获得一定数量的抽签机会。然后从这些机会中随机选择一个。该机会所属的请求被视为已满足，并不再参与后续的抽签轮次。抽签在 $n$ 轮后或没有未满足请求时结束，以先发生者为准。国际卡处理公司（ICPC）是冠军联赛的赞助商。选择 ICPC 卡作为支付方式的人在每轮抽签中获得两个机会，而使用其他支付方式的用户仅获得一个。  

德米特里有一张 ICPC 的卡，但他也有一张高级信用商品（ACM）的卡，该卡为他的所有消费提供奖金。他的兄弟 Petr 在负责分发门票的公司工作，所以他提前告诉德米特里已经有多少人决定使用 ICPC 卡以及多少人决定使用其他方法。现在德米特里想知道如果他使用 ICPC 卡或 ACM 卡，获得门票的概率是多少，以便做出明智的选择。他的请求将是 Petr 告诉他的请求数量的附加。  

你能帮忙吗？

## 输入格式

输入的第一行也是唯一一行包含 3 个整数——可用于抽签的座位数 $n (1 \le n \le 3000)$，使用 ICPC 卡作为支付方式的请求数 $a$，以及使用其他支付方式的请求数 $b (0 \le a, b \le 10^{9})$。

## 输出格式

第一行输出使用 ICPC 卡获得门票的概率。第二行输出使用 ACM 卡获得门票的概率。答案的绝对误差不超过 $10^{-9}$。

## 输入输出样例 #1

### 输入 #1

```
1 1 2

```

### 输出 #1

```
0.3333333333333333
0.2

```

## 输入输出样例 #2

### 输入 #2

```
10 10 10

```

### 输出 #2

```
0.5870875690480144
0.3640355515319861

```

## 说明/提示

时间限制：1 秒，内存限制：128 MB。

题面翻译由 ChatGPT-4o 提供。

---

# P6997 [NEERC 2013] Bonus Cards

## 题目描述

Dmitry loves programming competitions very much. The Finals of the famed Champions League are taking place in Dmitry's home city, so he wants to visit the competition. The competition is very popular, but most tickets to the competition are reserved for VIPs and for sponsors.

For the general public tickets to the Champions League Finals are distributed in the following way. Spectators, that want to see the competition, submit their request that states the payment method they want to use to pay for their ticket. Suppose there are $n$ seats available. Several draw round are conducted. In each round every request that is not yet fulfilled receives some number of slots depending on the payment method. Then one of those slots is selected uniformly at random. The request to which this slot belongs is considered fulfilled and does not take part in subsequent drawing rounds. Draw ends after $n$ rounds or when there are no more unfulfilled requests, whichever occurs first. An International Card Processing Corporation (ICPC) is a sponsor of the Champions League. Those who chose ICPC card as a payment method receive two slots in each draw round, while users of other payment methods receive only one.

Dmitry has a card from ICPC, but he also has a card from Advanced Credit Merchandise $(ACM),$ which offers him a bonus on all his spendings. His brother Petr works in a company that conducts draw to distribute tickets, so he told Dmitry in advance how many people had already decided to use ICPC card and how many had decided to use other methods. Now Dmitry want to know the probabilities he would get a ticket if he would use his ICPC card or if he would use his ACM card, so that he can make an informed choice. His request is going to be in addition to the number of requests Petr had told him about.

Can you help?

## 输入格式

The first and the only line of the input contains $3$ integer numbers -- the number of seats available for a draw $n (1 \le n \le 3000)$ , the number of requests with ICPC card as a payment method a , and the number of requests with other payment methods $b (0 \le $ a , $b \le 10^{9}).$

## 输出格式

On the first line output the probability of getting a ticket using ICPC card. On the second line output the probability of getting a ticket using ACM card. Answers should have an absolute error of no more than $10^{-9}.$

## 输入输出样例 #1

### 输入 #1

```
1 1 2

```

### 输出 #1

```
0.3333333333333333
0.2

```

## 输入输出样例 #2

### 输入 #2

```
10 10 10

```

### 输出 #2

```
0.5870875690480144
0.3640355515319861

```

## 说明/提示

Time limit: 1 s, Memory limit: 128 MB.