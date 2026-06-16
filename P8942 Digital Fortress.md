# P8942 Digital Fortress

## 题目背景

布林克霍夫大声喊道：“这当然是密码！这不是密码，还能是什么？还有什么原因能让友加送掉这枚戒指？到底是谁在戒指上刻一大串杂乱无章的字母？”

方丹愤怒地等了布林克霍夫一眼，使他安静了下来。

“啊……伙计们？”贝克插了一句话，似乎很不情愿卷进来一样，“你们一直说这些是杂乱无章的字母。我想我应该让你们知道……这枚戒指上刻的字母并不是杂乱无章。如果你近距离看一下，就会明白，实际上，这些字母……这个……这个是拉丁文。”

指挥台上的所有人都看向了那枚戒指。上面写道：

> Quis custodiet ipsos custiodies.  
谁来监视这些监视者……

## 题目描述

致命的变异串已经穿过了 X-11 过滤器，深入了国安局数据库。苏珊与贝克需要即时破解出密码，以关闭蠕虫病毒。

在蠕虫的文件中，他们找到了密码的一个特点：

- 共有 $n$ 位，每个数都在 $[1,m]$ 之间，并且单调不减。
- 如算出前缀异或和，那么前缀异或和也单调不减。
- 如算出后缀异或和，那么后缀异或和仍然单调不减。

除此之外，他们也找到了 $n,m$ 的值。现在，他们需要构造出一组密码，以满足所有特征。
***

#### 【形式化题意】

求是否存在长度为 $n$，所有元素都在 $[1,m]$ 范围内的单调不减正整数序列 $a$，满足：

- $\forall1<i\le n,a_1\ \text{xor}\ a_2\ \text{xor}\ \cdots\ \text{xor}\ a_{i-1}\le a_1\ \text{xor}\ a_2\ \text{xor}\ \cdots\ \text{xor}\ a_{i}$
- $\forall1\le i<n,a_n\ \text{xor}\ a_{n-1}\ \text{xor}\ \cdots\ \text{xor}\ a_{i+1}\le a_n\ \text{xor}\ a_{n-1}\ \text{xor}\ \cdots\ \text{xor}\ a_{i}$

如存在，输出一组合法解。多组数据。

## 输入格式

第一行一个正整数 $t$，表示数据组数。

对于每组数据，输入两个正整数 $n,m$。

## 输出格式

对于每组数据，如不存在满足要求的密码，输出 `No`。否则，输出 `Yes`，并在下一行输出一种合法方案。

## 输入输出样例 #1

### 输入 #1

```
2
4 20
1919 114514

```

### 输出 #1

```
Yes
1 6 8 16
No

```

## 说明/提示

#### 【样例解释】

对于第一组数据，密码的前缀异或和为 $\{1,7,15,31\}$，后缀异或和为 $\{16,24,30,31\}$，均为递增序列，满足题意。

对于第二组数据，不存在任何合法方案。

#### 【数据范围】

**本题开启捆绑测试。**

|$\text{Subtask}$|分值|$n\le$|$m\le$|
|:-:|:-:|:-:|:-:|
|$0$|$10$|$5$|$200$|
|$1$|$30$|$20$|$10^6$|
|$2$|$60$|$10^5$|$2^{63}-1$|

对于 $100\%$ 的数据，$1\le n\le10^5$，$1\le m\le2^{63}-1$，$1\le t\le50$。

---

# P8942 Digital Fortress

## 题目背景

Brinkhoff shouted loudly, “Of course it’s a password! If it’s not a password, what else could it be? Why else would Ugha give away this ring? Who would engrave a long string of messy letters on a ring?”

Fontaine glared at Brinkhoff angrily, making him quiet down.

“Uh… guys?” Beck cut in, as if he really did not want to get involved. “You keep saying these are messy letters. I think I should tell you… the letters engraved on this ring are not messy at all. If you look closely, you’ll see that actually, these letters… well… this is Latin.”

Everyone at the command console looked at the ring. It read:

> Quis custodiet ipsos custiodies.  
Who will watch the watchers…

## 题目描述

A deadly mutated string has passed through the X-11 filter and gone deep into the NSA database. Susan and Beck must crack the password immediately to shut down the worm virus.

In the worm’s files, they found some properties of the password:

- It has $n$ numbers, each in $[1,m]$, and the sequence is non-decreasing.
- If you compute the prefix XOR sums, the prefix XOR sums are also non-decreasing.
- If you compute the suffix XOR sums, the suffix XOR sums are still non-decreasing.

Besides this, they also found the values of $n,m$. Now they need to construct a password sequence that satisfies all properties.

***

#### [Formal statement]

Determine whether there exists a non-decreasing positive integer sequence $a$ of length $n$, with all elements in the range $[1,m]$, such that:

- $\forall1<i\le n,a_1\ \text{xor}\ a_2\ \text{xor}\ \cdots\ \text{xor}\ a_{i-1}\le a_1\ \text{xor}\ a_2\ \text{xor}\ \cdots\ \text{xor}\ a_{i}$
- $\forall1\le i<n,a_n\ \text{xor}\ a_{n-1}\ \text{xor}\ \cdots\ \text{xor}\ a_{i+1}\le a_n\ \text{xor}\ a_{n-1}\ \text{xor}\ \cdots\ \text{xor}\ a_{i}$

If it exists, output one valid solution. There are multiple test cases.

## 输入格式

The first line contains a positive integer $t$, the number of test cases.

For each test case, input two positive integers $n,m$.

## 输出格式

For each test case, if there is no password that meets the requirements, output `No`. Otherwise, output `Yes`, and on the next line output one valid construction.

## 输入输出样例 #1

### 输入 #1

```
2
4 20
1919 114514

```

### 输出 #1

```
Yes
1 6 8 16
No

```

## 说明/提示

#### [Sample explanation]

For the first test case, the prefix XOR sums are $\{1,7,15,31\}$, and the suffix XOR sums are $\{16,24,30,31\}$. Both are increasing sequences, so the requirements are satisfied.

For the second test case, there is no valid construction.

#### [Constraints]

**This problem uses bundled testdata.**

|$\text{Subtask}$|Score|$n\le$|$m\le$|
|:-:|:-:|:-:|:-:|
|$0$|$10$|$5$|$200$|
|$1$|$30$|$20$|$10^6$|
|$2$|$60$|$10^5$|$2^{63}-1$|

For $100\%$ of the testdata, $1\le n\le10^5$, $1\le m\le2^{63}-1$, $1\le t\le50$.

Translated by ChatGPT 5