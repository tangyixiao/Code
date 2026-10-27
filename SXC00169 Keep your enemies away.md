# SXC00169 Keep your enemies away

## 题目描述

Problem Statement
玛丽亚·冯·埃特尔正在和一颗苹果搏斗。
玛丽亚的生命值是H。
苹果可以提供N种口味，第i种口味能削减玛丽亚A_i的生命值。当玛丽亚的生命值变为0或以下时，玛丽亚就会睡去。
同一种口味，玛丽亚不会尝第二口；但若是不同的口味，玛丽亚必须要尝一口，请问玛丽亚会沉睡吗？会的话输出Yes；不会的话输出No。
Constraints
1 \leq H \leq 10^9
1 \leq N \leq 10^5
1 < A_i \leq 10^4
所有的输入值都是整数
Input
输入一行两个整数：H \quad N
第二行输入N个整数：A_1 \quad A_2 \quad ... \quad A_N
Output
如果Snow White死去，输出Yes，否则输出No。
Sample Input 1
Sample Output 1
尝了苹果的第2、3种口味，就足以让我们亲爱的玛丽亚公主永眠了。
Sample Input 2
Sample Output 2
Sample Input 3
Sample Output 3
Sample Input 4
Sample Output 4

## 输入输出样例 #1

### 输入 #1

```
10 3
4 5 6
```

### 输出 #1

```
Yes
```

## 输入输出样例 #2

### 输入 #2

```
20 3
4 5 6
```

### 输出 #2

```
No
```

## 输入输出样例 #3

### 输入 #3

```
210 5
31 41 59 26 53
```

### 输出 #3

```
Yes
```

## 输入输出样例 #4

### 输入 #4

```
211 5
31 41 59 26 53
```

### 输出 #4

```
No
```
