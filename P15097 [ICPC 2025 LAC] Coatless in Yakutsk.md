# P15097 [ICPC 2025 LAC] Coatless in Yakutsk

## 题目描述

这是你第一次到访萨尔瓦多，并且犯了一个新手错误：在海滩上睡着了。你醒来时皮肤通红、被晒伤了，坦率地说，感到非常丢脸。你发誓要向太阳及其所有可怕的后果复仇，于是决定你的下一个假期要去一个拥有真正冬天的地方——比如俄罗斯的雅库茨克，那里的平均气温是 $-42^\circ$ 摄氏度。

但你是有备而来的！你带了一件温暖舒适的厚外套。这件外套非常完美，能很好地为你保暖。可能好过头了，因为穿了 $C$ 天之后，你会出汗，外套也会变脏。由于你的旅行持续时间超过 $C$ 天，你必须想办法避免穿着有异味的外套到处走。

为此，当外套变脏时，你不能穿它直到它被洗净，但你也可以选择提前清洗它。在任何一天你不穿外套时——无论是因为它脏了还是在清洗中——你都必须忍受当天的气温而得不到它的保护。外套洗完后，就会变得干净并可以再次穿着。在你的旅行开始时，外套是干净的。

给定你旅行期间雅库茨克每日的气温，你需要确定在被迫没有外套穿的日子里，你所经历的最低气温，前提是你最优地安排清洗日期，以使这个温度尽可能高。

## 输入格式

第一行包含两个整数 $C$ 和 $N$（$1 \le C < N \le 10^5$），分别表示你在外套变脏前可以穿着它的天数，以及你假期的持续天数。

第二行包含 $N$ 个整数 $T_1, T_2, \dots, T_N$（对于 $i = 1, 2, \dots, N$，有 $-50 \le T_i \le 50$），其中 $T_i$ 是第 $i$ 天的气温。

## 输出格式

输出一行一个整数，表示你在没有外套穿的日子里必须忍受的最低气温。

## 输入输出样例 #1

### 输入 #1

```
2 6
-20 -10 -5 -10 -2 -40
```

### 输出 #1

```
-5
```

## 说明/提示

翻译由 DeepSeek V3 完成


---

# P15097 [ICPC 2025 LAC] Coatless in Yakutsk

## 题目描述

It was your first time visiting Salvador, and you made the rookie mistake of sleeping on the beach. You woke up red, sunburned, and frankly, humiliated. Swearing vengeance against the sun and all its terrible consequences, you decided that your next vacation would be somewhere with a real winter – like Yakutsk, Russia, where the average temperature is $-42^\circ$ Celsius.

But you came prepared! You brought a warm, cozy coat. The coat is perfect, it warms you very well. Maybe too well, as you get sweaty and the coat gets dirty after $C$ days of use. Since your trip lasts more than $C$ days, you must find a way to avoid walking around smelling bad.

To do so, when the coat gets dirty, you cannot wear it until it is washed, but you may also choose to wash it earlier. On any day you do not wear the coat – whether because it is dirty or being washed – you must endure the day’s temperature without its protection. After being washed, the coat is fresh and ready to be worn again. At the start of your trip, the coat is clean.

Given the daily temperatures in Yakutsk for the duration of your trip, you must determine the lowest temperature on a day when you are forced to be without your coat, assuming you schedule wash days optimally to make this temperature as high as possible.

## 输入格式

The first line contains two integers $C$ and $N$ ($1 \le C < N \le 10^5$), indicating respectively the number of days you can wear the coat before it gets dirty, and the duration in days of your holidays.

The second line contains $N$ integers $T_1, T_2, \dots, T_N$ ($-50 \le T_i \le 50$ for $i = 1, 2, \dots, N$), where $T_i$ is the temperature on the $i$-th day.

## 输出格式

Output a single line with an integer indicating the minimum temperature you must endure without your coat.

## 输入输出样例 #1

### 输入 #1

```
2 6
-20 -10 -5 -10 -2 -40
```

### 输出 #1

```
-5
```