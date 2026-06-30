# P5495 【模板】Dirichlet 前缀和

## 题目背景

模板题，无背景。

## 题目描述

给定一个长度为 $n$ 的数列 $a_1,a_2,a_3,\dots,a_n$。

现在你要求出一个长度为 $n$ 的数列 $b_1,b_2,b_3,\dots,b_n$，满足

$$b_k=\sum_{i|k}a_i$$

由于某些神秘原因，这里的 $b_k$ 要对 $2^{32}$ 取模。

## 输入格式

为了避免过大的输入，本题的输入使用随机数生成器。

输入中只有一行两个整数 $n,seed$。其中 $seed$ 为 $32$ 位无符号整数，用来生成数据。

接下来，你要调用 $n$ 次随机数生成器，分别生成 $a_1\sim a_n$。

对于```C/C++```选手，生成器模板如下：

```cpp
#define uint unsigned int
uint seed;
inline uint getnext(){
	seed^=seed<<13;
	seed^=seed>>17;
	seed^=seed<<5;
	return seed;
}
```

对于```Pascal```选手，生成器模板如下：

```pas
var seed:dword;
function getnext:dword;
begin
	seed:=seed xor(seed shl 13);
	seed:=seed xor(seed shr 17);
	seed:=seed xor(seed shl 5);
	getnext:=seed;
end;
```

注意：**所有 $n$ 个数均为 $32$ 位无符号整数**。

## 输出格式

为了避免过大的输出，你只需输出一个 $32$ 位无符号整数，表示所有 $b_i$ 的异或和。

## 输入输出样例 #1

### 输入 #1

```
5 1477

```

### 输出 #1

```
2608816472

```

## 说明/提示

样例中，数列 $a$ 为 $397153977, 974453892, 352446086, 334987182, 2086335567$。

数列 $b$ 为 $397153977, 1371607869, 749600063, 1706595051, 2483489544$。

### 限制与约定

对于 $100\%$ 的数据， $1\leq n\leq 2\times 10^7$，$0\leq seed< 2^{32}$。

---

# P5495 [Template] Dirichlet Prefix Sum

## 题目背景

This is a template problem, with no background.

## 题目描述

Given a sequence $a_1,a_2,a_3,\dots,a_n$ of length $n$.

Now you need to compute a sequence $b_1,b_2,b_3,\dots,b_n$ of length $n$, satisfying

$$b_k=\sum_{i|k}a_i$$

Due to some mysterious reasons, each $b_k$ should be taken modulo $2^{32}$.

## 输入格式

To avoid overly large input, this problem uses a random number generator.

The input contains only one line with two integers $n, seed$. Here, $seed$ is a $32$-bit unsigned integer used to generate the data.

Next, you need to call the random number generator $n$ times to generate $a_1 \sim a_n$.

For ```C/C++``` users, the generator template is as follows:

```cpp
#define uint unsigned int
uint seed;
inline uint getnext(){
	seed^=seed<<13;
	seed^=seed>>17;
	seed^=seed<<5;
	return seed;
}
```

For ```Pascal``` users, the generator template is as follows:

```pas
var seed:dword;
function getnext:dword;
begin
	seed:=seed xor(seed shl 13);
	seed:=seed xor(seed shr 17);
	seed:=seed xor(seed shl 5);
	getnext:=seed;
end;
```

Note: **All $n$ numbers are $32$-bit unsigned integers**.

## 输出格式

To avoid overly large output, you only need to output one $32$-bit unsigned integer, which is the XOR sum of all $b_i$.

## 输入输出样例 #1

### 输入 #1

```
5 1477

```

### 输出 #1

```
2608816472

```

## 说明/提示

In the sample, the sequence $a$ is $397153977, 974453892, 352446086, 334987182, 2086335567$.

The sequence $b$ is $397153977, 1371607869, 749600063, 1706595051, 2483489544$.

### Constraints and Conventions

For $100\%$ of the testdata, $1\leq n\leq 2\times 10^7$, $0\leq seed< 2^{32}$.

Translated by ChatGPT 5