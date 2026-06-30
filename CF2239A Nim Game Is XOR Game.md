# CF2239A Nim Game Is XOR Game

## 题目描述

Alice and Bob are playing a game with an array  $ a $  consisting of  $ n $  non-negative integers. Alice goes first.

In each turn, the current player must choose an array of  $ n $  non-negative integers  $ b = [b_1, b_2, \ldots, b_n] $  that satisfies the following conditions:

1. $ 0 \le b_i \le a_i $  for all  $ 1 \le i \le n $ ;
2. $ \sum_{i=1}^n b_i  \gt  0 $  (i.e. the array  $ b $  does not consist entirely of zeros);
3. $ b_1 \oplus b_2 \oplus \ldots \oplus b_n = 0 $ , where  $ \oplus $  denotes the [bitwise XOR operation](https://en.wikipedia.org/wiki/Bitwise_operation#XOR).

After choosing the array  $ b $ , the player updates the array  $ a $  by performing  $ a_i \leftarrow a_i - b_i $  for all  $ 1 \le i \le n $ .

The player who cannot perform such an operation loses the game.

Determine the number of valid choices for the array  $ b $  that Alice can make on her first turn to guarantee a win, assuming both players play optimally. Since this number may be large, output the answer modulo  $ 998\,244\,353 $ .

## 输入格式

Each test contains multiple test cases. The first line contains the number of test cases  $ t $  ( $ 1 \le t \le 10^4 $ ). The description of the test cases follows.

The first line of each test case contains a single integer  $ n $  ( $ 1 \le n \le 10^6 $ ) — the length of the array  $ a $ .

The second line of each test case contains  $ n $  integers  $ a_1, a_2, \ldots, a_n $  ( $ 1 \le a_i  \lt  2^{30} $ ) — the contents of the array  $ a $

It is guaranteed that the sum of  $ n $  over all test cases does not exceed  $ 10^6 $ .

## 输出格式

For each test case, output the number of valid choices for the array  $ b $  that Alice can make on her first turn to guarantee a win modulo  $ 998\,244\,353 $ .

## 输入输出样例 #1

### 输入 #1

```
5
1
1
2
1 2
5
1 4 5 2 6
1
1073741823
3
1 2 3
```

### 输出 #1

```
0
1
3
0
1
```

## 说明/提示

In the first test case, Alice must choose an array  $ b $  of length  $ 1 $ . The conditions require  $ b_1 \le a_1 $ ,  $ b_1  \gt  0 $ , and  $ b_1 = 0 $ . It is impossible to satisfy  $ b_1  \gt  0 $  and  $ b_1 = 0 $  simultaneously. Thus, Alice has no valid moves and loses immediately. The answer is  $ 0 $ .

In the second test case,  $ a = [1, 2] $ . Alice must choose  $ b = [b_1, b_2] $ . The condition  $ b_1 \oplus b_2 = 0 $  implies that  $ b_1 = b_2 $ . Since  $ 0 \le b_1 \le 1 $  and  $ 0 \le b_2 \le 2 $ , and the array  $ b $  cannot consist entirely of zeros, the only valid choice is  $ b = [1, 1] $ . If Alice chooses  $ b = [1, 1] $ , the array updates to  $ a = [1-1, 2-1] = [0, 1] $ . Now it is Bob's turn. Similar to Alice's situation, Bob must choose  $ b' $  such that  $ b'_1 = b'_2 $ . Since  $ a_1 = 0 $ , he is forced to pick  $ b'_1 = 0 $ , which means  $ b'_2 = 0 $ . Since a valid move must have  $ \sum b'_i  \gt  0 $ , Bob has no valid moves and loses. Therefore,  $ b = [1, 1] $  is a winning move for Alice, and the answer is  $ 1 $ .
