# P5858 「SWTR-3」Golden Sword

## 题目背景

小 E 不幸在一场战斗中失去了他的金宝剑。

## 题目描述

制造一把金宝剑需要 $n$ 种原料，编号为 $1$ 到 $n$，编号为 $i$ 的原料的坚固值为 $a_i$。

炼金是很讲究放入原料的顺序的，因此小 E 必须**按照 $1$ 到 $n$ 的顺序**依次将这些原料放入炼金锅。

但是，炼金锅的容量非常有限，它**最多只能容纳 $w$ 个原料**。

所幸的是，**每放入一个原料之前**，小 E 可以从中取出一些原料，数量不能超过 $s$ 个。

- 我们定义第 $i$ 种原料的耐久度为：放入第 $i$ 种原料时锅内的原料总数（包括正在放入的原料） $\times\ a_i$，则宝剑的耐久度为**所有原料**的耐久度之和。

小 E 当然想让他的宝剑的耐久度尽可能得大，这样他就可以带着它进行更多的战斗，请求出耐久度的最大值。

注：这里的“放入第 $i$ 种原料时锅内的原料总数**包括正在放入锅中的原料**，详细信息请见样例。

## 输入格式

第一行，三个整数 $n,w,s$。

第二行，$n$ 个整数 $a_1,a_2,\dots,a_n$。

## 输出格式

一行一个整数，表示耐久度的最大值。

## 输入输出样例 #1

### 输入 #1

```
5 3 3
1 3 2 4 5

```

### 输出 #1

```
40
```

## 输入输出样例 #2

### 输入 #2

```
5 3 3
1 -3 -2 4 5

```

### 输出 #2

```
21
```

## 输入输出样例 #3

### 输入 #3

```
7 4 2
-5 3 -1 -4 7 -6 5

```

### 输出 #3

```
17
```

## 输入输出样例 #4

### 输入 #4

```
5 3 1
-1 -3 -2 -4 -5

```

### 输出 #4

```
-15
```

## 说明/提示

#### 「样例说明」

- **对于样例 1**，一种可行的**最优**方案为：
首先放进原料 1，此时锅内有 $1$ 种原料，耐久度为 $1\times a_1=1\times 1=1$。  
再放进原料 2，此时锅内有 $2$ 种原料，耐久度为 $2\times a_2=2\times 3=6$。  
再放进原料 3，此时锅内有 $3$ 种原料，耐久度为 $3\times a_3=3\times 2=6$。  
取出原料 1，再放进原料 4，此时锅内有 $3$ 种原料，耐久度为 $3\times a_4=3\times 4=12$。  
取出原料 4，再放进原料 5，此时锅内有 $3$ 种原料，耐久度为 $3\times a_5=3\times 5=15$。  
最终答案为 $1+6+6+12+15=40$。  
- **对于样例 2**，一种可行的**最优**方案为：  
放进原料 1，耐久度为 $1\times 1=1$。  
取出原料 1，放进原料 2，耐久度为 $1\times (-3)=-3$。  
放进原料 3，耐久度为 $2\times (-2)=-4$。  
放进原料 4，耐久度为 $3\times 4=12$。  
取出原料 2，放进原料 5，耐久度为 $3\times 5=15$。  
最终答案为 $1+(-3)+(-4)+12+15=21$。  
- **对于样例 3**，一种可行的**最优**方案为：  
  $a_1+2a_2+2a_3+3a_4+4a_5+3a_6+4a_7=17$。 
- **对于样例 4**，一种可行的**最优**方案为：  
$a_1+a_2+a_3+a_4+a_5=-15$。

#### 「数据范围与约定」

**本题使用捆绑测试。**

- Subtask #1（15 points）：$n\leq 10$。
- Subtask #2（5 points）：$n\leq 100$，$a_i\geq0$。
- Subtask #3（15 points）：$n\leq 300$。
- Subtask #4（15 points）：$s=w=n$。
- Subtask #5（5 points）：$a_i\geq 0$。
- Subtask #6（10 points）：$n\leq 2\times 10^3$。
- Subtask #7（10 points）：$s=1$。
- Subtask #8（25 points）：无特殊限制。

对于 $100\%$ 的数据，$1 \leq s \leq w \leq n \leq 5\times 10^3$，$|a_i| \leq 10^9$。对于 Subtask $i$ 有 $|a_i|\leq 10^{i+1}$。

#### 「帮助/说明」

本题下发大样例，具体输入输出见 [**Big Sample**](https://pan.baidu.com/s/1erVDllDlvNlEShxh3U42gA) 中的 gold01-08.in/gold01-08.out。提取码：757d。  
**文件名与 Subtask 编号一一对应。**

#### 「来源」

[Sweet Round 03 D](https://www.luogu.com.cn/contest/24755)。  
idea & solution：ET2006。

---

# P5858 "SWTR-3" Golden Sword

## 题目背景

Little E unfortunately lost his golden sword in a battle.

## 题目描述

To make a golden sword, $n$ kinds of materials are needed, numbered from $1$ to $n$. The sturdiness value of material $i$ is $a_i$.

Alchemy pays great attention to the order of adding materials, so Little E must add these materials into the alchemy pot **in the order from $1$ to $n$**, one by one.

However, the pot has a very limited capacity: it can hold **at most $w$ materials**.

Fortunately, **before adding each material**, Little E may take out some materials from the pot, but the number taken out cannot exceed $s$.

- We define the durability of material $i$ as: (the total number of materials in the pot when adding material $i$, **including the material being added**) $\times\ a_i$. Then, the sword's durability is the sum of the durabilities of **all materials**.

Little E of course wants his sword's durability to be as large as possible, so that he can take it into more battles. Please output the maximum possible durability.

Note: Here, “the total number of materials in the pot when adding material $i$” **includes the material currently being put into the pot**. For details, see the samples.

## 输入格式

The first line contains three integers $n,w,s$.

The second line contains $n$ integers $a_1,a_2,\dots,a_n$.

## 输出格式

Output one integer in one line, representing the maximum durability.

## 输入输出样例 #1

### 输入 #1

```
5 3 3
1 3 2 4 5

```

### 输出 #1

```
40
```

## 输入输出样例 #2

### 输入 #2

```
5 3 3
1 -3 -2 4 5

```

### 输出 #2

```
21
```

## 输入输出样例 #3

### 输入 #3

```
7 4 2
-5 3 -1 -4 7 -6 5

```

### 输出 #3

```
17
```

## 输入输出样例 #4

### 输入 #4

```
5 3 1
-1 -3 -2 -4 -5

```

### 输出 #4

```
-15
```

## 说明/提示

#### "Sample Explanation"

- **For Sample 1**, one feasible **optimal** plan is:
First put in material 1. Now there is $1$ material in the pot, and the durability is $1\times a_1=1\times 1=1$.  
Then put in material 2. Now there are $2$ materials in the pot, and the durability is $2\times a_2=2\times 3=6$.  
Then put in material 3. Now there are $3$ materials in the pot, and the durability is $3\times a_3=3\times 2=6$.  
Take out material 1, then put in material 4. Now there are $3$ materials in the pot, and the durability is $3\times a_4=3\times 4=12$.  
Take out material 4, then put in material 5. Now there are $3$ materials in the pot, and the durability is $3\times a_5=3\times 5=15$.  
The final answer is $1+6+6+12+15=40$.  
- **For Sample 2**, one feasible **optimal** plan is:  
Put in material 1, and the durability is $1\times 1=1$.  
Take out material 1, put in material 2, and the durability is $1\times (-3)=-3$.  
Put in material 3, and the durability is $2\times (-2)=-4$.  
Put in material 4, and the durability is $3\times 4=12$.  
Take out material 2, put in material 5, and the durability is $3\times 5=15$.  
The final answer is $1+(-3)+(-4)+12+15=21$.  
- **For Sample 3**, one feasible **optimal** plan is:  
  $a_1+2a_2+2a_3+3a_4+4a_5+3a_6+4a_7=17$. 
- **For Sample 4**, one feasible **optimal** plan is:  
$a_1+a_2+a_3+a_4+a_5=-15$.

#### "Constraints and Notes"

**This problem uses bundled testdata.**

- Subtask #1 (15 points): $n\leq 10$.
- Subtask #2 (5 points): $n\leq 100$, $a_i\geq0$.
- Subtask #3 (15 points): $n\leq 300$.
- Subtask #4 (15 points): $s=w=n$.
- Subtask #5 (5 points): $a_i\geq 0$.
- Subtask #6 (10 points): $n\leq 2\times 10^3$.
- Subtask #7 (10 points): $s=1$.
- Subtask #8 (25 points): no special restrictions.

For $100\%$ of the data, $1 \leq s \leq w \leq n \leq 5\times 10^3$, $|a_i| \leq 10^9$. For Subtask $i$, $|a_i|\leq 10^{i+1}$.

#### "Help / Notes"

This problem provides large samples. For the exact input and output, see gold01-08.in / gold01-08.out in [**Big Sample**](https://pan.baidu.com/s/1erVDllDlvNlEShxh3U42gA). Extraction code: 757d.  
**The filenames correspond one-to-one with the Subtask numbers.**

#### "Source"

[Sweet Round 03 D](https://www.luogu.com.cn/contest/24755).  
Idea & solution: ET2006.

Translated by ChatGPT 5