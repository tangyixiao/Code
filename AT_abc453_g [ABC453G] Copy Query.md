# AT_abc453_g [ABC453G] Copy Query

## 题目描述

$ N $  個の長さ  $ M $  の数列  $ A_1,A_2,\dots,A_N $  があります。最初は全ての数列の全ての要素が  $ 0 $  です。  
 以降、数列  $ A_i $  の  $ j $  項目を  $ A_{i,j} $  と表します。

以下の  $ 3 $  種類のクエリを、与えられた順に合計  $ Q $  個処理してください。

- タイプ  $ 1 $  : 数列  $ A_{X_i} $  を数列  $ A_{Y_i} $  で上書きする。つまり、全ての整数  $ j $  ( $ 1 \le j \le M $ ) について、  $ A_{X_i,j} $  を  $ A_{Y_i,j} $  に変更する。
- タイプ  $ 2 $  : 数列  $ A_{X_i} $  の  $ Y_i $  項目、すなわち  $ A_{X_i,Y_i} $  を  $ Z_i $  に変更する。
- タイプ  $ 3 $  : 数列  $ A_{X_i} $  について、  $ L_i $  項目から  $ R_i $  項目までの和、すなわち  $ A_{X_i,L_i}+A_{X_i,L_i+1}+\dots+A_{X_i,R_i} $  を出力する。

## 输入格式

入力は以下の形式で標準入力から与えられる。

> $ N $   $ M $   $ Q $   $ {\rm Query}_1 $   $ {\rm Query}_2 $   $ \vdots $   $ {\rm Query}_Q $

ただし、  $ {\rm Query}_i $  は  $ i $  個目のクエリを表す。

タイプ  $ 1 $  のクエリは以下の形式で与えられる。

> 1  $ X_i $   $ Y_i $

タイプ  $ 2 $  のクエリは以下の形式で与えられる。

> 2  $ X_i $   $ Y_i $   $ Z_i $

タイプ  $ 3 $  のクエリは以下の形式で与えられる。

> 3  $ X_i $   $ L_i $   $ R_i $

## 输出格式

タイプ  $ 3 $  のクエリが与えられるごとに、そのクエリに対する答えを出力せよ。  
 タイプ  $ 3 $  のクエリが存在しない場合、出力は空とせよ。

## 输入输出样例 #1

### 输入 #1

```
4 5 10
2 2 1 2
2 2 2 7
2 2 4 8
1 1 2
2 2 3 1
1 3 2
2 3 2 10
3 1 2 4
3 2 1 4
3 3 2 2
```

### 输出 #1

```
15
18
10
```

## 说明/提示

### Sample Explanation 1

この入力では、  $ 4 $  個の長さ  $ 5 $  の数列を用意します。

- $ 1 $  個目のクエリで、  $ A_{2,1}=2 $  とする。この時点で数列  $ A_2=(2,0,0,0,0) $  である。
- $ 2 $  個目のクエリで、  $ A_{2,2}=7 $  とする。この時点で数列  $ A_2=(2,7,0,0,0) $  である。
- $ 3 $  個目のクエリで、  $ A_{2,4}=8 $  とする。この時点で数列  $ A_2=(2,7,0,8,0) $  である。
- $ 4 $  個目のクエリで、数列  $ A_1 $  を数列  $ A_2 $  で上書きする。この時点で数列  $ A_1=(2,7,0,8,0) $  である。
- $ 5 $  個目のクエリで、  $ A_{2,3}=1 $  とする。この時点で数列  $ A_2=(2,7,1,8,0) $  である。
- $ 6 $  個目のクエリで、数列  $ A_3 $  を数列  $ A_2 $  で上書きする。この時点で数列  $ A_3=(2,7,1,8,0) $  である。
- $ 7 $  個目のクエリで、  $ A_{3,2}=10 $  とする。この時点で数列  $ A_3=(2,10,1,8,0) $  である。
- $ 8 $  個目のクエリで、  $ A_{1,2}+A_{1,3}+A_{1,4}=7+0+8=15 $  を答える。
- $ 9 $  個目のクエリで、  $ A_{2,1}+A_{2,2}+A_{2,3}+A_{2,4}=2+7+1+8=18 $  を答える。
- $ 10 $  個目のクエリで、  $ A_{3,2}=10 $  を答える。

### Constraints

- $ 1 \le N,M \le 2 \times 10^5 $
- $ 1 \le Q \le 2 \times 10^5 $
- タイプ  $ 1 $  のクエリは以下の制約を満たす
    - $ 1 \le X_i,Y_i \le N $
- タイプ  $ 2 $  のクエリは以下の制約を満たす
    - $ 1 \le X_i \le N $
    - $ 1 \le Y_i \le M $
    - $ 0 \le Z_i \le 10^9 $
- タイプ  $ 3 $  のクエリは以下の制約を満たす
    - $ 1 \le X_i \le N $
    - $ 1 \le L_i \le R_i \le M $
- 入力はすべて整数

---

# AT_abc453_g [ABC453G] Copy Query

## 题目描述

There are  $ N $  sequences of length  $ M $ :  $ A_1,A_2,\dots,A_N $ . Initially, all elements of all sequences are  $ 0 $ .  
 Hereafter, the  $ j $ -th element of sequence  $ A_i $  is denoted by  $ A_{i,j} $ .

Process the following three types of queries in the given order,  $ Q $  queries in total.

- Type  $ 1 $ : Overwrite sequence  $ A_{X_i} $  with sequence  $ A_{Y_i} $ . That is, for every integer  $ j $  ( $ 1 \le j \le M $ ), change  $ A_{X_i,j} $  to  $ A_{Y_i,j} $ .
- Type  $ 2 $ : Change the  $ Y_i $ -th element of sequence  $ A_{X_i} $ , that is,  $ A_{X_i,Y_i} $ , to  $ Z_i $ .
- Type  $ 3 $ : For sequence  $ A_{X_i} $ , output the sum of elements from the  $ L_i $ -th through the  $ R_i $ -th, that is,  $ A_{X_i,L_i}+A_{X_i,L_i+1}+\dots+A_{X_i,R_i} $ .

## 输入格式

The input is given from Standard Input in the following format:

> $ N $   $ M $   $ Q $   $ {\rm Query}_1 $   $ {\rm Query}_2 $   $ \vdots $   $ {\rm Query}_Q $

Here,  $ {\rm Query}_i $  represents the  $ i $ -th query.

A type  $ 1 $  query is given in the following format:

> 1  $ X_i $   $ Y_i $

A type  $ 2 $  query is given in the following format:

> 2  $ X_i $   $ Y_i $   $ Z_i $

A type  $ 3 $  query is given in the following format:

> 3  $ X_i $   $ L_i $   $ R_i $

## 输出格式

For each type  $ 3 $  query, output the answer to that query. If there are no type  $ 3 $  queries, the output should be empty.

## 输入输出样例 #1

### 输入 #1

```
4 5 10
2 2 1 2
2 2 2 7
2 2 4 8
1 1 2
2 2 3 1
1 3 2
2 3 2 10
3 1 2 4
3 2 1 4
3 3 2 2
```

### 输出 #1

```
15
18
10
```

## 说明/提示

### Sample Explanation 1

In this input, prepare four sequences of length  $ 5 $ .

- In the  $ 1 $ st query, set  $ A_{2,1}=2 $ . At this point,  $ A_2=(2,0,0,0,0) $ .
- In the  $ 2 $ nd query, set  $ A_{2,2}=7 $ . At this point,  $ A_2=(2,7,0,0,0) $ .
- In the  $ 3 $ rd query, set  $ A_{2,4}=8 $ . At this point,  $ A_2=(2,7,0,8,0) $ .
- In the  $ 4 $ th query, overwrite sequence  $ A_1 $  with sequence  $ A_2 $ . At this point,  $ A_1=(2,7,0,8,0) $ .
- In the  $ 5 $ th query, set  $ A_{2,3}=1 $ . At this point,  $ A_2=(2,7,1,8,0) $ .
- In the  $ 6 $ th query, overwrite sequence  $ A_3 $  with sequence  $ A_2 $ . At this point,  $ A_3=(2,7,1,8,0) $ .
- In the  $ 7 $ th query, set  $ A_{3,2}=10 $ . At this point,  $ A_3=(2,10,1,8,0) $ .
- In the  $ 8 $ th query, output  $ A_{1,2}+A_{1,3}+A_{1,4}=7+0+8=15 $ .
- In the  $ 9 $ th query, output  $ A_{2,1}+A_{2,2}+A_{2,3}+A_{2,4}=2+7+1+8=18 $ .
- In the  $ 10 $ th query, output  $ A_{3,2}=10 $ .

### Constraints

- $ 1 \le N,M \le 2 \times 10^5 $
- $ 1 \le Q \le 2 \times 10^5 $
- Type  $ 1 $  queries satisfy the following constraints:
    - $ 1 \le X_i,Y_i \le N $
- Type  $ 2 $  queries satisfy the following constraints:
    - $ 1 \le X_i \le N $
    - $ 1 \le Y_i \le M $
    - $ 0 \le Z_i \le 10^9 $
- Type  $ 3 $  queries satisfy the following constraints:
    - $ 1 \le X_i \le N $
    - $ 1 \le L_i \le R_i \le M $
- All input values are integers.