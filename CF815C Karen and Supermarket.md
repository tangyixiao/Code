# CF815C Karen and Supermarket

## 题目描述

在回家的路上，Karen 决定去超市买些杂货。

她需要购买很多商品，但作为学生的她预算非常有限。实际上，她最多只能花 $b$ 美元。

超市有 $n$ 种商品。第 $i$ 种商品的售价为 $c_{i}$ 美元。当然，每种商品只能买一次。

最近超市正在努力提升生意。作为忠实顾客，Karen 得到了 $n$ 张优惠券。如果 Karen 购买第 $i$ 种商品，她可以使用第 $i$ 张优惠券，使该商品的价格减少 $d_{i}$ 美元。当然，没有购买对应商品时，不能使用该商品的优惠券。

不过，优惠券有一个使用限制。对于所有 $i \geq 2$，如果要使用第 $i$ 张优惠券，Karen 还必须同时使用第 $x_{i}$ 张优惠券（这可能意味着还需要满足更多优惠券的使用要求）。

Karen 想知道，在不超过她的预算 $b$ 的情况下，她最多能买多少种商品。

## 输入格式

输入的第一行包含两个整数 $n$ 和 $b$（$1 \leq n \leq 5000$，$1 \leq b \leq 10^{9}$），分别表示商店中的商品数量和 Karen 拥有的金额。

接下来的 $n$ 行描述每种商品。具体来说：

- 其中第 $i$ 行以两个整数 $c_{i}$ 和 $d_{i}$ 开头（$1 \leq d_{i} < c_{i} \leq 10^{9}$），表示第 $i$ 种商品的价格和使用其优惠券时可减免的金额。
- 如果 $i \geq 2$，这两个数后还会有一个整数 $x_{i}$（$1 \leq x_{i} < i$），表示要使用第 $i$ 张优惠券，必须先使用第 $x_{i}$ 张优惠券。

## 输出格式

输出一个整数，表示在不超过预算的情况下，Karen 最多能购买的不同商品数量。

## 输入输出样例 #1

### 输入 #1

```
6 16
10 9
10 5 1
12 2 1
20 18 3
10 2 3
2 1 5

```

### 输出 #1

```
4

```

## 输入输出样例 #2

### 输入 #2

```
5 10
3 1
3 1 1
3 1 2
3 1 3
3 1 4

```

### 输出 #2

```
5

```

## 说明/提示

在第一个测试样例中，Karen 可以购买如下 $4$ 件商品：

- 使用第 $1$ 张优惠券，以 $10-9=1$ 美元买下第 $1$ 件商品。
- 使用第 $3$ 张优惠券，以 $12-2=10$ 美元买下第 $3$ 件商品。
- 使用第 $4$ 张优惠券，以 $20-18=2$ 美元买下第 $4$ 件商品。
- 直接用 $2$ 美元买下第 $6$ 件商品。

这些商品总花费是 $15$ 美元，未超出她的预算。需要注意的是，例如她不能对第 $6$ 件商品使用优惠券，因为那样就要求她同时购买并使用第 $5$ 张优惠券，而实际上她没有这么做。

在第二个测试样例中，Karen 有足够的钱购买全部商品并使用所有优惠券。

由 ChatGPT 5 翻译

---

# CF815C Karen and Supermarket

## 题目描述

On the way home, Karen decided to stop by the supermarket to buy some groceries.

 ![](https://cdn.luogu.com.cn/upload/vjudge_pic/CF815C/155b4f0d440b0d3ff60763603980cf23ed9ae97d.png)She needs to buy a lot of goods, but since she is a student her budget is still quite limited. In fact, she can only spend up to $ b $ dollars.

The supermarket sells $ n $ goods. The $ i $ -th good can be bought for $ c_{i} $ dollars. Of course, each good can only be bought once.

Lately, the supermarket has been trying to increase its business. Karen, being a loyal customer, was given $ n $ coupons. If Karen purchases the $ i $ -th good, she can use the $ i $ -th coupon to decrease its price by $ d_{i} $ . Of course, a coupon cannot be used without buying the corresponding good.

There is, however, a constraint with the coupons. For all $ i>=2 $ , in order to use the $ i $ -th coupon, Karen must also use the $ x_{i} $ -th coupon (which may mean using even more coupons to satisfy the requirement for that coupon).

Karen wants to know the following. What is the maximum number of goods she can buy, without exceeding her budget $ b $ ?

## 输入格式

The first line of input contains two integers $ n $ and $ b $ ( $ 1<=n<=5000 $ , $ 1<=b<=10^{9} $ ), the number of goods in the store and the amount of money Karen has, respectively.

The next $ n $ lines describe the items. Specifically:

- The $ i $ -th line among these starts with two integers, $ c_{i} $ and $ d_{i} $ ( $ 1<=d_{i}<c_{i}<=10^{9} $ ), the price of the $ i $ -th good and the discount when using the coupon for the $ i $ -th good, respectively.
- If $ i>=2 $ , this is followed by another integer, $ x_{i} $ ( $ 1<=x_{i}<i $ ), denoting that the $ x_{i} $ -th coupon must also be used before this coupon can be used.

## 输出格式

Output a single integer on a line by itself, the number of different goods Karen can buy, without exceeding her budget.

## 输入输出样例 #1

### 输入 #1

```
6 16
10 9
10 5 1
12 2 1
20 18 3
10 2 3
2 1 5

```

### 输出 #1

```
4

```

## 输入输出样例 #2

### 输入 #2

```
5 10
3 1
3 1 1
3 1 2
3 1 3
3 1 4

```

### 输出 #2

```
5

```

## 说明/提示

In the first test case, Karen can purchase the following $ 4 $ items:

- Use the first coupon to buy the first item for $ 10-9=1 $ dollar.
- Use the third coupon to buy the third item for $ 12-2=10 $ dollars.
- Use the fourth coupon to buy the fourth item for $ 20-18=2 $ dollars.
- Buy the sixth item for $ 2 $ dollars.

The total cost of these goods is $ 15 $ , which falls within her budget. Note, for example, that she cannot use the coupon on the sixth item, because then she should have also used the fifth coupon to buy the fifth item, which she did not do here.

In the second test case, Karen has enough money to use all the coupons and purchase everything.