# P8378 [PFOI Round1] Two Sequences

## 题目背景

syzf2222 喜欢并查集！特别是路径压缩的并查集。

## 题目描述

```cpp
inline int find(int x){
	if(x==fa[x])return x;
	return fa[x]=find(fa[x]);
}
inline void merge(int x,int y){
	fx=find(x),fy=find(y);
	if(fx==fy)return;fa[fx]=fy;
}
```

这是他惯用的并查集代码，初始时对于每个 $x$ 有 `fa[x]=x`。

接下来的 $T$ 天中，每天小 h 都给了他一个 $n$，表示并查集的大小（每天的 $n$ 可能是不同的）。

调皮的小 x 见他不在机房，每天都在并查集上不断 `merge`。
注意到小 x 不喜欢 `==`，他觉得这特别像他的眼睛，于是他不会使 `merge` 函数在第二行的条件语句中被 `return`，否则他会十分气愤。

现在的已知信息就只有最终的 $fa$ 数组了。
而 syzf2222 希望还原小 x 的操作序列（即若干次按顺序进行的 `merge` 操作）。由于他名字里有很多个 2 而且本人也非常 2 ，他希望知道对于每一天，有多少个 $fa$ 数组**恰好**能被还原成**两种**操作序列，答案对 $998244353$ 取余数。

两个操作序列不同，当且仅当某次 `merge` 时的变量 `fx,fy` 至少有一个不同。

## 输入格式

第一行一个整数 $T$。

后面 $T$ 行，每行读入一个整数 $n$ 表示小 h 给的数。

## 输出格式

$T$ 行，每行一个整数表示答案对 $998244353$ 取余数的结果。

## 输入输出样例 #1

### 输入 #1

```
4
3
20
8492
114514
```

### 输出 #1

```
3
61560
822256526
988192964

```

## 说明/提示

【样例解释】

对于第一天，$n=3$，共有 $fa=[1,1,1],[2,2,2],[3,3,3]$ 这三种 $fa$ 数组使得恰有两种操作序列。

以 $fa=[1,1,1]$ 为例，两种操作序列分别为 `merge(2,1),merge(3,1)` 和 `merge(3,1),merge(2,1)`，其他 `merge` 参数不同的方案与上述两种的其中一种是本质相同的（每次的 `fx,fy` 都一样）。

---

【数据范围】

**「本题采用捆绑测试」**

- $\texttt{Subtask 1(10 pts)：}T=1,\ n\le 10$；
- $\texttt{Subtask 2(30 pts)：}T=10^2,\ n\le 10^3$；
- $\texttt{Subtask 3(60 pts)：}$无特殊限制。

对于 $100\%$ 的数据，满足 $1\le T\le 10^5,\ 1\le n\le 10^9$。

---

# P8378 [PFOI Round1] Two Sequences

## 题目背景

syzf2222 likes union-find (DSU). In particular, he likes the DSU with path compression.

## 题目描述

```cpp
inline int find(int x){
	if(x==fa[x])return x;
	return fa[x]=find(fa[x]);
}
inline void merge(int x,int y){
	fx=find(x),fy=find(y);
	if(fx==fy)return;fa[fx]=fy;
}
```

This is his commonly used DSU code. Initially, for every $x$, we have `fa[x]=x`.

In the next $T$ days, each day, Xiao h gives him an $n$, which represents the DSU size (the $n$ for each day may be different).

Mischievous Xiao x notices that he is not in the computer room, so every day he keeps calling `merge` on the DSU.
Note that Xiao x does not like `==`. He thinks it looks like his eyes, so he will not allow the `merge` function to `return` at the conditional statement on the second line; otherwise, he will be very angry.

Now, the only known information is the final `fa` array.
syzf2222 wants to restore Xiao x's sequence of operations (i.e., several `merge` operations performed in order). Since his name contains many 2s and he is also very "2" (er, silly), he wants to know, for each day, how many `fa` arrays can be restored into **exactly** **two** operation sequences. Output the answer modulo $998244353$.

Two operation sequences are considered different if and only if, during some `merge`, at least one of the variables `fx,fy` is different.

## 输入格式

The first line contains an integer $T$.

The next $T$ lines each contain an integer $n$, representing the number given by Xiao h.

## 输出格式

Output $T$ lines, each containing one integer: the answer modulo $998244353$.

## 输入输出样例 #1

### 输入 #1

```
4
3
20
8492
114514
```

### 输出 #1

```
3
61560
822256526
988192964

```

## 说明/提示

【Sample Explanation】

For day 1, $n=3$. There are three `fa` arrays, $fa=[1,1,1],[2,2,2],[3,3,3]$, such that there are exactly two operation sequences.

Take $fa=[1,1,1]$ as an example. The two operation sequences are `merge(2,1),merge(3,1)` and `merge(3,1),merge(2,1)`. Other solutions with different `merge` parameters are essentially the same as one of the above (each time, `fx,fy` are the same).

---

【Constraints】

**「This problem uses bundled testdata」**

- $\texttt{Subtask 1(10 pts)：}T=1,\ n\le 10$；
- $\texttt{Subtask 2(30 pts)：}T=10^2,\ n\le 10^3$；
- $\texttt{Subtask 3(60 pts)：}$No special restrictions.

For $100\%$ of the testdata, $1\le T\le 10^5,\ 1\le n\le 10^9$ holds.

Translated by ChatGPT 5