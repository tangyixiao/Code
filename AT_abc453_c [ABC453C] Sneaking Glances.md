# AT_abc453_c [ABC453C] Sneaking Glances

## 题目描述

数直線上の座標  $ 0.5 $  に高橋君がいます。

高橋君はこれから  $ N $  回の移動を行います。  
  $ i $  回目の移動では、「正の方向」「負の方向」のいずれかを選び、その方向に  $ L_i $  進みます。

高橋君は座標  $ 0 $  を最大で何回通り過ぎることが出来るでしょうか？  
 なお、この問題の制約上、座標  $ 0 $  で完了する移動が生じることはありません。

## 输入格式

入力は以下の形式で標準入力から与えられる。

> $ N $   $ L_1 $   $ L_2 $   $ \dots $   $ L_N $

## 输出格式

答えを出力せよ。

## 输入输出样例 #1

### 输入 #1

```
5
2 5 2 2 1
```

### 输出 #1

```
4
```

## 输入输出样例 #2

### 输入 #2

```
5
100 1 2 3 4
```

### 输出 #2

```
1
```

## 输入输出样例 #3

### 输入 #3

```
20
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
```

### 输出 #3

```
20
```

## 说明/提示

### Sample Explanation 1

例えば以下のように移動の方向を選択することで座標  $ 0 $  を  $ 4 $  回通り過ぎることができ、これが最大です。

- $ 1 $  回目の移動で負の方向を選び、  $ 2 $  進む。高橋君は座標  $ 0.5 $  から  $ -1.5 $  へと移動し、座標  $ 0 $  を通り過ぎる。
- $ 2 $  回目の移動で正の方向を選び、  $ 5 $  進む。高橋君は座標  $ -1.5 $  から  $ 3.5 $  へと移動し、座標  $ 0 $  を通り過ぎる。
- $ 3 $  回目の移動で負の方向を選び、  $ 2 $  進む。高橋君は座標  $ 3.5 $  から  $ 1.5 $  へと移動する。
- $ 4 $  回目の移動で負の方向を選び、  $ 2 $  進む。高橋君は座標  $ 1.5 $  から  $ -0.5 $  へと移動し、座標  $ 0 $  を通り過ぎる。
- $ 5 $  回目の移動で正の方向を選び、  $ 1 $  進む。高橋君は座標  $ -0.5 $  から  $ 0.5 $  へと移動し、座標  $ 0 $  を通り過ぎる。

### Constraints

- $ 1 \le N \le 20 $
- $ 1 \le L_i \le 10^9 $
- 入力はすべて整数


---

# AT_abc453_c [ABC453C] Sneaking Glances

## 题目描述

Takahashi is at coordinate  $ 0.5 $  on a number line.

He will make  $ N $  moves.  
 In the  $ i $ -th move, he chooses either the positive direction or the negative direction, and moves  $ L_i $  in that direction.

What is the maximum number of times he can pass through coordinate  $ 0 $ ?  
 Under the constraints of this problem, no move will end at coordinate  $ 0 $ .

## 输入格式

The input is given from Standard Input in the following format:

> $ N $   $ L_1 $   $ L_2 $   $ \dots $   $ L_N $

## 输出格式

Output the answer.

## 输入输出样例 #1

### 输入 #1

```
5
2 5 2 2 1
```

### 输出 #1

```
4
```

## 输入输出样例 #2

### 输入 #2

```
5
100 1 2 3 4
```

### 输出 #2

```
1
```

## 输入输出样例 #3

### 输入 #3

```
20
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
```

### 输出 #3

```
20
```

## 说明/提示

### Sample Explanation 1

For example, by choosing the directions of movement as follows, he can pass through coordinate  $ 0 $  four times, which is the maximum.

- In the first move, choose the negative direction and move  $ 2 $ . He moves from coordinate  $ 0.5 $  to  $ -1.5 $ , passing through coordinate  $ 0 $ .
- In the second move, choose the positive direction and move  $ 5 $ . He moves from coordinate  $ -1.5 $  to  $ 3.5 $ , passing through coordinate  $ 0 $ .
- In the third move, choose the negative direction and move  $ 2 $ . He moves from coordinate  $ 3.5 $  to  $ 1.5 $ .
- In the fourth move, choose the negative direction and move  $ 2 $ . He moves from coordinate  $ 1.5 $  to  $ -0.5 $ , passing through coordinate  $ 0 $ .
- In the fifth move, choose the positive direction and move  $ 1 $ . He moves from coordinate  $ -0.5 $  to  $ 0.5 $ , passing through coordinate  $ 0 $ .

### Constraints

- $ 1 \le N \le 20 $
- $ 1 \le L_i \le 10^9 $
- All input values are integers.