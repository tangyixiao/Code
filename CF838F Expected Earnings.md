# CF838F Expected Earnings

## 题目描述

你正在玩一个有红球和黑球的游戏。一开始，你被告知袋子中共有 $n$ 个球。此外，你还知道袋子中恰好有 $i$ 个红球的概率为 $p_{i}/10^{6}$。

你现在想从这个袋子中买球。你非常喜欢红色，因此红球的价值为 $1$ 单位，而黑球没有价值。每次买球时，如果袋子中还有球，你需要支付 $c$ 的费用（$0 \leq c \leq 1$），然后随机从袋子中抽取一个球。你可以在任何时刻选择停止购买（你甚至可以选择什么都不买）。

如果你总是以最大化期望利润（即红球数量减去获得红球所需的花费）的方式购买，请输出最大的期望利润。

## 输入格式

输入的第一行包含两个整数 $n, X$（$1 \leq n \leq 10000$，$0 \leq X \leq 10^6$）。

第二行包含 $n+1$ 个整数 $p_{0}, p_{1}, \ldots, p_{n}$（$0 \leq p_{i} \leq 10^{6}$，并且 $p_0 + p_1 + \cdots + p_n = 10^6$）。

$c$ 的值可以按如下公式计算：

$$
c = \frac{X}{10^6}
$$

## 输出格式

输出一个浮点数，表示最大期望值。

如果你的答案和标准答案的绝对误差或相对误差不超过 $10^{-9}$ 即视为正确。更具体地说，设你的答案为 $a$，标准答案为 $b$，只要满足

$$
\frac{|a-b|}{\max(1, |b|)} \leq 10^{-9}
$$

你的答案即为正确。

## 输入输出样例 #1

### 输入 #1

```
3 200000
250000 250000 250000 250000

```

### 输出 #1

```
0.9000000000

```

## 说明/提示

在本样例中，袋子中恰好有 0、1、2、3 个红球的概率相等。同时，每次抽球的花费为 $0.2$。

由 ChatGPT 5 翻译


---

# CF838F Expected Earnings

## 题目描述

You are playing a game with a bag of red and black balls. Initially, you are told that the bag has $ n $ balls total. In addition, you are also told that the bag has probability $ p_{i}/10^{6} $ of containing exactly $ i $ red balls.

You now would like to buy balls from this bag. You really like the color red, so red balls are worth a unit of $ 1 $ , while black balls are worth nothing. To buy a ball, if there are still balls in the bag, you pay a cost $ c $ with $ 0<=c<=1 $ , and draw a ball randomly from the bag. You can choose to stop buying at any point (and you can even choose to not buy anything at all).

Given that you buy optimally to maximize the expected profit (i.e. # red balls - cost needed to obtain them), print the maximum expected profit.

## 输入格式

The first line of input will contain two integers $ n,X $ ( $ 1<=n<=10000 $ , $ 0<=X<=10^{6} $ ).

The next line of input will contain $ n+1 $ integers $ p_{0},p_{1},...\ p_{n} $ ( $ 0<=p_{i}<=10^{6} $ , ![](https://cdn.luogu.com.cn/upload/vjudge_pic/CF838F/7db6b8342276851a78020e225114985f8bcff7e6.png))

The value of $ c $ can be computed as ![](https://cdn.luogu.com.cn/upload/vjudge_pic/CF838F/6efe404963af6b3d99ee39cb1c0a64c063c32bf4.png).

## 输出格式

Print a single floating point number representing the optimal expected value.

Your answer will be accepted if it has absolute or relative error at most $ 10^{-9} $ . More specifically, if your answer is $ a $ and the jury answer is $ b $ , your answer will be accepted if ![](https://cdn.luogu.com.cn/upload/vjudge_pic/CF838F/d8d110e69d298146d951837cc2710d1c4cc74a7d.png).

## 输入输出样例 #1

### 输入 #1

```
3 200000
250000 250000 250000 250000

```

### 输出 #1

```
0.9000000000

```

## 说明/提示

Here, there is equal probability for the bag to contain 0,1,2,3 red balls. Also, it costs 0.2 to draw a ball from the bag.