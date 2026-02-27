# P4090 [USACO17DEC] Greedy Gift Takers P

## 题目描述

Farmer John 的死对头 Farmer Nhoj 有 $N$ 头奶牛（$1 \leq N \leq 10^5$），编号为 $1 \dots N$。它们意外地出现在 Farmer John 的农场，因此一贯礼貌的 Farmer John 试图给它们送礼物。

为此，Farmer John 拿出了他无限的礼物供应，Nhoj 的奶牛在他面前排成一队，奶牛 $1$ 在队首，奶牛 $N$ 在队尾。Farmer John 原本以为，在每一时刻，队首的奶牛会从 Farmer John 那里拿走一份礼物，然后走到队尾。然而，他刚刚意识到 Nhoj 的奶牛并不那么礼貌！每头奶牛在收到礼物后，可能不会走到队尾，而是可能会插队到队尾的某些奶牛前面。具体来说，奶牛 $i$ 总是会插队到恰好 $c_i$ 头奶牛前面（$0 \leq c_i \leq N-1$）。

Farmer John 知道有些奶牛可能会收到多份礼物；由于他有无限的礼物供应，这并不让他担心。但他担心的是，如果有些奶牛没有收到任何礼物，它们可能会变得不开心。

请帮助 Farmer John 找出无论送出多少礼物，都无法收到任何礼物的奶牛数量。

## 输入格式

第一行包含一个整数 $N$。

第二行包含 $N$ 个用空格分隔的整数 $c_1, c_2, \dots, c_N$。

## 输出格式

请输出无法收到任何礼物的奶牛数量。

## 输入输出样例 #1

### 输入 #1

```
3
1 2 0
```

### 输出 #1

```
1

```

---

# P4090 [USACO17DEC] Greedy Gift Takers P

## 题目描述

Farmer John's nemesis, Farmer Nhoj, has $N$ cows ($1 \leq N \leq 10^5$), conveniently numbered $1 \dots N$. They have unexpectedly turned up at Farmer John's farm, so the unfailingly polite Farmer John is attempting to give them gifts.

To this end, Farmer John has brought out his infinite supply of gifts, and Nhoj's cows have queued up in front of him, with cow $1$ at the head of the queue and cow $N$ at the tail. Farmer John was expecting that at every timestep, the cow at the head of the queue would take a gift from Farmer John and go to the tail of the queue. However, he has just realized that Nhoj's cows are not that polite! After receiving her gift, each cow may not go to the tail of the queue, but rather may cut some number of cows at the tail, and insert herself in front of them. Specifically, cow $i$ will always cut exactly $c_i$ cows ($0 \leq c_i \leq N-1$).


Farmer John knows that some cows might receive multiple gifts; as he has an infinite supply, this does not worry him. But he is worried that some cows might become unhappy if they do not get any gifts.


Help Farmer John find the number of cows who never receive any gifts, no matter how many gifts are handed out.

## 输入格式

The first line contains a single integer, $N$.

The second line contains $N$ space-separated integers $c_1, c_2, \dots, c_N$.

## 输出格式

Please output the number of cows who cannot receive any gifts.

## 输入输出样例 #1

### 输入 #1

```
3
1 2 0
```

### 输出 #1

```
1

```