# 2188 upper_bound

## 题目描述

<span>输入 $ n (n≤ 10^6)&nbsp;$ 个不超过 $ 10^9 $&nbsp;的单调不减的（就是后面的数字不小于前面的数字）非负整数&nbsp;a1&#44;a2&#44;…&#44;an，然后进行&nbsp; $ m(m≤10^5) $&nbsp;次询问。</span><br />
<span>对于每次询问，给出一个整数 $q(-10^9≤q≤10^9)$</span><br />
<span>要求找到第一个严格大于这个数字$q$在序列中的编号 &#44; 如果找不到输出n+1.</span>

## 输入格式

<span>第一行两个数n，m</span><br />
<span>第二行n个</span><span>单调不减的序列</span><span></span><br />
<span>接下来m行询问，每行一个整数q</span>

## 输出格式

<span><span>要求找到第一个大于这个数字在序列中的编号&#44;&nbsp;<span>如果找不到输出n+1</span>。</span></span>
<pre><code class="language-input1">11 3
1 3 3 3 5 7 9 11 13 15 15
2
5
6</code></pre><pre><code class="language-output1">2
6
6</code></pre>

## 输入输出样例 #1

### 输入 #1

```
11 3
1 3 3 3 5 7 9 11 13 15 15
2
5
6
```

### 输出 #1

```
2
6
6
```
