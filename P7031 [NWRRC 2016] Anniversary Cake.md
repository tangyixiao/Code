# P7031 [NWRRC 2016] Anniversary Cake

## 题目描述

两个学生，Adam 和 Anton，正在庆祝他们未通过数学逻辑考试两周年。在当地超市经过仔细挑选后，他们买了一个长方形的蛋糕，蛋糕的尺寸是整数，并且有两根蜡烛。

后来在校园里，Adam 把蜡烛插在蛋糕的不同整数点上，并把刀交给 Anton 来切蛋糕。切口应该从蛋糕边缘的整数点开始和结束，并且不能碰到蜡烛。每一块蛋糕上应该正好有一根蜡烛。请帮助 Anton 找到切口的起点和终点。

一个 $7 \times 3$ 的蛋糕和两个蜡烛放在 $(2, 2)$ 和 $(3, 2)$。

Anton 可以从 $(0, 0)$ 到 $(4, 3)$ 切开这个蛋糕。

## 输入格式

输入的单行包含六个整数：$w, h$ —— 蛋糕的尺寸；$a_{x}, a_{y}$ —— 第一根蜡烛的 $x$ 和 $y$ 坐标；$b_{x}, b_{y}$ —— 第二根蜡烛的坐标（$3 \le w, h \le 10^{9}; 0 < a_{x}, b_{x} < w; 0 < a_{y}, b_{y} < h; a_{x} 
eq b_{x}$ 或 $a_{y} 
eq b_{y}$）。

## 输出格式

输出四个整数 $s_{x}, s_{y}, e_{x}, e_{y}$ —— 切口的起点和终点坐标。切口的起点和终点都应该在蛋糕的边缘上。

如果有多个解决方案，输出其中任意一个。

## 输入输出样例 #1

### 输入 #1

```
7 3 2 2 3 2 

```

### 输出 #1

```
0 0 4 3

```

## 说明/提示

时间限制：2 秒，内存限制：256 MB。

spj 提供者：@[shenyouran](\/user\/137367)

题面翻译由 ChatGPT-4o 提供。  


---

# P7031 [NWRRC 2016] Anniversary Cake

## 题目描述

Two students, Adam and Anton, are celebrating two-year anniversary of not passing their Math $Logic exa_m.$ After very careful search in a local supermarket, they bought a rectangular cake with $integer dimensions$ and two candles.

Later in the campus Adam put the candles into different integer points of the cake and gave a knife $to Anto_n$ to cut the cake. The cut should start and end at integer points at the edges of the cake, and $it should$ not touch the candles. Also each piece should have exactly one candle at it. Please, help $Anto_n to$ find the starting and ending points of the cut.

![](https://onlinejudgeimages.s3.amazonaws.com/problem/13473/%EC%8A%A4%ED%81%AC%EB%A6%B0%EC%83%B7%202016-11-01%20%EC%98%A4%ED%9B%84%202.30.49.png)

A $7 \times 3$ cake and two candles at $(2 , 2)$ and $(3 , 2)$ .

Anton can cut this cake through $(0 , 0)$ and $(4 , 3)$ .

## 输入格式

The single line of the input contains six integers: $w , h$ -- cake dimensions; $a_{x}, a_{y}$ -- $x$ and $y coordinates$ of the first candle; $b_{x}, b_{y}$ -- the coordinates of the second candle $(3 \le w , h \le 10^{9}; 0 < a_{x}, b_{x} < w$ ; $0 < a_{y}, b_{y} < h$ ; $a_{x} ≠ b_{x}$ or $a_{y }≠ b_{y}).$

## 输出格式

Output four integers $s_{x}, s_{y}, e_{x},$ and $e_{y}$ -- the starting and ending coordinates of the cut. Both $starting and$ ending point of the cut should belong to the sides of the cake.

If there are several solutions, output any of them.

## 输入输出样例 #1

### 输入 #1

```
7 3 2 2 3 2 

```

### 输出 #1

```
0 0 4 3

```

## 说明/提示

Time limit: 2 s, Memory limit: 256 MB. 

spj provider:@[shenyouran](/user/137367)