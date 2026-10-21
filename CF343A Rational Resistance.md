# CF343A Rational Resistance

## 题目描述

疯狂科学家 Mike 正在业余时间制造一台时光机。要完成这项工作，他需要一个具有特定电阻值的电阻器。

然而，Mike 手头上只有很多相同的单位电阻器，电阻值为 $R_0 = 1$。可以通过这些电阻器组合得到其他电阻值的元件。在本题中，下述情况都被视为“元件”：

1. 一个电阻器；
2. 一个元件和一个电阻器串联；
3. 一个元件和一个电阻器并联。

串联时，新元件的电阻为 $R = R_e + R_0$。并联时，新元件的电阻为 $R = \frac{R_e \cdot R_0}{R_e + R_0}$，其中 $R_e$ 为被连接元件的电阻。

Mike 需要组装出一个电阻恰好等于 $\frac{a}{b}$ 的元件。请判断，至少需要多少个电阻器才能实现。

## 输入格式

输入包含一行，两个以空格分隔的整数 $a$ 和 $b$（$1 \leq a, b \leq 10^{18}$）。保证分数 $\frac{a}{b}$ 是最简分数，且保证一定有解。

## 输出格式

输出一个整数，表示最少需要多少个电阻器。

## 输入输出样例 #1

### 输入 #1

```
1 1

```

### 输出 #1

```
1

```

## 输入输出样例 #2

### 输入 #2

```
3 2

```

### 输出 #2

```
3

```

## 输入输出样例 #3

### 输入 #3

```
199 200

```

### 输出 #3

```
200

```

## 说明/提示

在第一个样例中，只需一个电阻器即可。

在第二个样例中，可以先将两个电阻器并联，再把所得元件与第三个电阻器串联。这样可获得电阻 $\frac{3}{2}$。用两个电阻器无法得到该电阻值。

由 ChatGPT 5 翻译

---

# CF343A Rational Resistance

## 题目描述

Mad scientist Mike is building a time machine in his spare time. To finish the work, he needs a resistor with a certain resistance value.

However, all Mike has is lots of identical resistors with unit resistance $ R_{0}=1 $ . Elements with other resistance can be constructed from these resistors. In this problem, we will consider the following as elements:

1. one resistor;
2. an element and one resistor plugged in sequence;
3. an element and one resistor plugged in parallel.

 ![](https://cdn.luogu.com.cn/upload/vjudge_pic/CF343A/f117fcf32ddafc80e319e28fce885c21483edc5b.png)With the consecutive connection the resistance of the new element equals $ R=R_{e}+R_{0} $ . With the parallel connection the resistance of the new element equals ![](https://cdn.luogu.com.cn/upload/vjudge_pic/CF343A/a708eb8090c66cbbd34afced0c36506bcb612681.png). In this case $ R_{e} $ equals the resistance of the element being connected.

Mike needs to assemble an element with a resistance equal to the fraction ![](https://cdn.luogu.com.cn/upload/vjudge_pic/CF343A/eecd60ed91fbeebe74e2406ea1a11d26df905945.png). Determine the smallest possible number of resistors he needs to make such an element.

## 输入格式

The single input line contains two space-separated integers $ a $ and $ b $ ( $ 1<=a,b<=10^{18} $ ). It is guaranteed that the fraction ![](https://cdn.luogu.com.cn/upload/vjudge_pic/CF343A/eecd60ed91fbeebe74e2406ea1a11d26df905945.png) is irreducible. It is guaranteed that a solution always exists.

## 输出格式

Print a single number — the answer to the problem.

Please do not use the %lld specifier to read or write 64-bit integers in С++. It is recommended to use the cin, cout streams or the %I64d specifier.

## 输入输出样例 #1

### 输入 #1

```
1 1

```

### 输出 #1

```
1

```

## 输入输出样例 #2

### 输入 #2

```
3 2

```

### 输出 #2

```
3

```

## 输入输出样例 #3

### 输入 #3

```
199 200

```

### 输出 #3

```
200

```

## 说明/提示

In the first sample, one resistor is enough.

In the second sample one can connect the resistors in parallel, take the resulting element and connect it to a third resistor consecutively. Then, we get an element with resistance ![](https://cdn.luogu.com.cn/upload/vjudge_pic/CF343A/234023ef6c61445a95e9903d46cd7846f3823141.png). We cannot make this element using two resistors.