# P7051 [NWRRC 2015] Distribution in Metagonia

## 题目描述

在梅塔戈尼亚国有一百个贵族家庭，每年这些家庭中的一些会从“唯一者”的先知那里收到几个仪式立方体。“唯一者”对立方体的分配有几个规则：如果一个家庭收到至少一个立方体，那么收到的立方体数量的所有质因数应该是 $2$ 或 $3$。此外，如果一个家庭收到 $a > 0$ 个立方体，而同一年另一个家庭收到 $b > 0$ 个立方体，那么 $a$ 不应该能被 $b$ 整除，反之亦然。

你是“唯一者”的先知。你提前知道未来 $t$ 年将有多少立方体可供分配。你想为这些年中的每一年找到任何有效的立方体分配方案。每年你必须分配掉该年所有可用的立方体。

## 输入格式

输入文件的第一行包含一个整数 $t$ —— 即将到来的年份数 $(1 \le t \le 1000)$。接下来的 $t$ 行中的每一行包含一个整数 $n_{i}$ —— 在第 $i$ 年要分配的立方体数量 $(1 \le n_{i} \le 10^{18})$。

## 输出格式

对于每一年 $i$ 输出两行。第一行应包含 $m_{i}$ —— 在第 $i$ 年至少收到一个立方体的家庭数量 $(1 \le m_{i} \le 100)$。第二行应包含 $m_{i}$ 个整数 —— 每个家庭收到的立方体数量。这些数字的总和应等于 $n_{i}$。

## 输入输出样例 #1

### 输入 #1

```
4
1
2
3
10

```

### 输出 #1

```
1
1
1
2
1
3
2
4 6

```

## 说明/提示

时间限制：2 秒，内存限制：256 MB。

题面翻译由 ChatGPT-4o 提供。

---

# P7051 [NWRRC 2015] Distribution in Metagonia

## 题目描述

There are one hundred noble families in the country of Metagonia, and each year some of these families receive several ritual cubes from the Seer of the One. The One has several rules about cube distribution: if a family receives at least one cube, every prime divisor of the number of cubes received should be either $2$ or $3$ , moreover if one family receives a $> 0$ cubes and another family in the same year receives $b > 0$ cubes then a should not be divisible by $b$ and vice versa.

You are the Seer of the One. You know in advance how many cubes would be available for distribution for the next $t$ years. You want to find any valid distribution of cubes for each of these years. Each year you have to distribute all cubes available for that year.

## 输入格式

The first line of input file contains a single integer $t$ -- the number of years to come $(1 \le t \le 1000)$ . Each of the following $t$ lines contains a single integer $n_{i}$ -- the number of cubes to distribute in i-th year $(1 \le n_{i} \le 10^{18}).$

## 输出格式

For each year $i$ output two lines. The first line should contain $m_{i}$ -- the number of families that would receive at least one cube in i-th year $(1 \le m_{i} \le 100)$ . The second line should contain $m_{i}$ integers -- the number of cubes received by each family. The sum of these numbers should be equal to $n_{i}.$

## 输入输出样例 #1

### 输入 #1

```
4
1
2
3
10

```

### 输出 #1

```
1
1
1
2
1
3
2
4 6

```

## 说明/提示

Time limit: 2 s, Memory limit: 256 MB.