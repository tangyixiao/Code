# P12200 Hash Killer Extra

## 题目背景

本题为给定 base 和 mod 的情况下卡单哈希，参考了 [北航 2024 国庆思维训练特别赛](https://accoding.buaa.edu.cn/contest-ng/index.html#/1109)，向出题人表示感谢。

## 题目描述

请你找到任意两个字符串，使它们满足以下条件：
- 仅由小写字母 $\tt{a}\sim \tt{z}$ 组成；
- 两者长度相同，且长度 $n$ 满足：$1\leq n\leq 10^4$；
- 两者不完全相同，却在给定的 $b,p$ 下有着一致的哈希值；

本题中参考的 hash 代码为：

```cpp
int strhash(const string &s, int b, int p) {
    int val = 0;
    for (int i = 0; i < s.length(); i++)
        val = (1ll * val * b + s[i] - 'a' + 1) % p;
    return val;
}
```

## 输入格式

输入两个正整数 $b,p$。

## 输出格式

输出两行，表示满足题目条件的两个字符串。对于同一组测试数据输出可能有很多种，任意一组符合条件的字符串均为可接受的答案。

## 输入输出样例 #1

### 输入 #1

```
37 131
```

### 输出 #1

```
bbbbbbbbbbbbbbbb
caabbbbbbcbbbbbb
```

## 说明/提示

### 数据范围

- 对于 $40\%$ 的测试数据，$31\leq b<p\leq 10007$；
- 对于所有测试数据，$31\leq b<p\leq 10^9+7$；

测试数据保证 $p$ 一定是质数。