# P4692 [Ynoi Easy Round 2016] 谁的梦

## 题目背景

::::info[题目背景已折叠]
6.373 

世界是独立于我的意志的。 

6.374 

就算我们所期望的全部的事情都发生了 

这果然也只能说是命运的恩惠吧。 

要问为什么，那是因为意志和世界之间 

能够保证这件事的逻辑性的关联并不存在 

Ludwig Josef Johann Wittgenstein [逻辑哲学论] 

自从双胞胎的哥哥过世起，已经过了多久了呢… 

从那时起，我一直保存着那个布偶。 

在那以后的我只是个影子…而这个布偶才是我… 

这样也并没有什么不好。 

我觉得只要现在的我消失掉就行了… 

那两个人却救了这样的我。 

一个是由歧姐… 

她又来到了我的身边… 

带着皆守哥…回到了我们的身边… 

水上由岐姐姐…温柔的姐姐 

曾经非常喜欢皆守哥的人……

![](https://cdn.luogu.com.cn/upload/pic/21195.png)

回去的路上…

平时不会经过的坡道…

在登上那个坡道的途中…

我看到了夜晚的太阳。

明明就在附近，却一直不知道的巨大的向日葵。

夜露使它的绒毛泛出了白光。

碧蓝的月光和黄色的向日葵…

就好像太阳和月亮的立场反过来一样…

原本是那么耀眼的的太阳在地上，只能在其背后下发光的月亮在天上…

黄色的向日葵被染成了碧蓝色。

那副样子虽然很美丽…

努力绽放的向日葵，看起来反而是柔弱的存在。

在夜里向天空伸展的向日葵…

我在车内一直追寻着它的身影…

被夜晚的月光映照着的太阳。

被染成碧蓝色的太阳…

它的身影…我一直追寻着……

![](https://cdn.luogu.com.cn/upload/pic/21196.png)

被月光照亮的天台上…

一个人影…

明明只是一个人影…却好像…在和什么东西对峙着一样…

皆守哥…

月下的立像，一个人影。

胸口在风中闪烁。

放在胸前的手里的是…那时的小刀。

和七年前同样的姿势。

唯一不同的是，那里的人影只有一个。

那把小刀，好像是被他自己刺入体内。

![](https://cdn.luogu.com.cn/upload/pic/21197.png)

是诅咒…

这是理所当然的事…

那并不是什么精神病…

那是诅咒…

下在幸存的我们身上的…诅咒…

说不定，不仅仅是卓司哥…连由岐姐也在诅咒我们…

所以变成这种结果…

哥哥刺向了自己的胸口…

破坏了我的半身…

然后…还要把很多人送回到天空…

回归天空的日子。

交还灵魂的日子。

那一天，卓司哥对我做的事情。

杀了由岐姐的…那个行为…

他想要再一次实行…

这次…和很多人一起…

![](https://cdn.luogu.com.cn/upload/pic/21198.png)

不是…

那是…我啊…

是那个…坡道的事情啊…

两个人一起看到向日葵的…那个坡道…

…我说要爬上那个坡道…要去寻找爸爸的灵魂…

我想，如果到了那个坡道的前方，就能取回爸爸的灵魂…爸爸就会复生的…

如果越过向日葵之路…向着向日葵所朝向的天空延伸的…那个大大的坡道的话…
大概，就会有爸爸的灵魂…

爸爸的故乡的…大大的坡道…

![](https://cdn.luogu.com.cn/upload/pic/21199.png)

哥哥的身体浮在空中…

我无言地跳了出去。

啊啊…是这样啊…

由岐姐也是这种心情啊…

并没有什么道理可言…

只是因为喜欢的人向着天空跳下去了…

我想要抓住那个身体…

我——
::::

## 题目描述

您正在打 galgame，突然断电了，于是您跑去物管处问，结果发现是由于一个光头踢了变压器一脚导致的，可能还要修很久，于是您决定想一个之前见过的数据结构题：

定义一个序列的权值为不同数字的个数，例如 $[1,2,3,3]$  权值为 $3$。

现在有 $n$ 个序列，我们在每个序列里面选一个连续非空子串，拼接起来，求所有选法得到的序列的权值之和。

如果一个序列能通过多种方法被选择出来，那么计算多次。

本题带修改操作，格式请参考输入格式。

由于结果可能过大，请输出答案 $\bmod 19260817$ 的结果。

## 输入格式

第一行两个整数 $n,m$，表示有 $n$ 个序列，$m$ 次修改。

第二行 $n$ 个整数，第 $i$ 个数是 $len_i$，表示第 $i$ 个序列的长度。

之后 $n$ 行，每行 $len_i$ 个整数，表示第 $i$ 个序列。

之后 $m$ 行，每行三个整数 $x,y,z$ 表示将第 $x$ 个序列的第 $y$ 个元素改为 $z$。

## 输出格式

输出 $m + 1$ 行，每行一个整数，依次表示初始局面以及每次修改后的答案。

## 输入输出样例 #1

### 输入 #1

```
2 5
6 6
1 3 1 1 3 2 
2 3 3 2 1 1 
1 1 1
1 1 2
1 1 2
1 1 1
1 1 1
```

### 输出 #1

```
1158
1158
1168
1168
1158
1158
```

## 说明/提示

Idea：nzhtl1477，Solution：nzhtl1477，Code：nzhtl1477，Data：nzhtl1477( partially uploaded )

$1 \leq n,m,len_i \leq 10^5$，序列中的元素均为 $32$ 位整型数，$\sum len_i \leq 10^5$。

共 $50$ 组数据。

---

# P4692 [Ynoi Easy Round 2016] Whose Dream

## 题目背景

::::info[题目背景已折叠]
6.373

The world is independent of my will.

6.374

Even if everything we hope for happens,

in the end it can only be called a gift of fate.

If you ask why, it is because between will and the world,

the logical connection that can guarantee this does not exist.

Ludwig Josef Johann Wittgenstein [Tractatus Logico-Philosophicus]

How long has it been since my twin brother passed away…

Since then, I have kept that stuffed doll.

After that, I was only a shadow… and this stuffed doll was the real me…

That is not so bad either.

I think it is enough if the current me disappears…

But those two people saved someone like me.

One of them was Yuki-nee…

She came back to my side again…

Bringing Minamori-nii… back to our side…

Mizukami Yuki-nee, a gentle older sister.

Someone who once liked Minamori-nii very much……

![](https://cdn.luogu.com.cn/upload/pic/21195.png)

On the way back…

A slope we usually would not pass…

While climbing that slope…

I saw the sun at night.

A huge sunflower that was nearby, yet I never noticed it.

The night dew made its fuzz glow white.

The deep blue moonlight and the yellow sunflower…

It was as if the positions of the sun and the moon were reversed…

The sun, originally so dazzling, was on the ground, and the moon, which could only shine behind it, was in the sky…

The yellow sunflower was dyed deep blue.

That sight was very beautiful…

But the sunflower, blooming with all its might, instead looked like something fragile.

The sunflower stretching toward the sky at night…

Inside the car, I kept chasing its silhouette…

The sun illuminated by the moonlight at night.

The sun dyed deep blue…

Its figure… I kept chasing it……

![](https://cdn.luogu.com.cn/upload/pic/21196.png)

On the rooftop lit by moonlight…

A shadow…

Clearly just a shadow… yet it seemed… to be confronting something…

Minamori-nii…

A statue under the moon, a shadow.

His chest flickered in the wind.

In the hand placed before his chest was… that small knife from back then.

The same posture as seven years ago.

The only difference was that there was only one shadow there.

That knife seemed to have been stabbed into his body by himself.

![](https://cdn.luogu.com.cn/upload/pic/21197.png)

It is a curse…

This is only natural…

It is not some mental illness…

It is a curse…

A curse placed on us survivors…

Perhaps, not only Takushi-nii… but even Yuki-nee is cursing us…

So it ended up like this…

My brother stabbed his own chest…

Destroyed my other half…

And then… he will send many people back to the sky…

The day of returning to the sky.

The day of giving back the soul.

What Takushi-nii did to me that day.

That act… of killing Yuki-nee…

He wants to do it once again…

This time… together with many people…

![](https://cdn.luogu.com.cn/upload/pic/21198.png)

No…

That is… me…

It is that… slope…

That slope where two people saw the sunflower together…

…I said I wanted to climb that slope… to look for Dad’s soul…

I thought that if I reached beyond that slope, I could take back Dad’s soul… and Dad would come back to life…

If I crossed the sunflower road… and went toward that big slope that extends into the sky the sunflower faces…
Then, probably, Dad’s soul would be there…

The big slope… of Dad’s hometown…

![](https://cdn.luogu.com.cn/upload/pic/21199.png)

My brother’s body floated in the air…

I jumped out without a word.

Ah… so that is how it is…

Yuki-nee felt like this too…

There is no reason to it…

Just because the person I like jumped toward the sky…

I wanted to grab that body…

I—
::::

## 题目描述

You are playing a galgame when the power suddenly goes out. You run to the property management office to ask, and find out it was because a bald guy kicked the transformer, and it may take a long time to fix. So you decide to think about a data structure problem you saw before:

Define the weight of a sequence as the number of distinct numbers in it. For example, $[1,2,3,3]$ has weight $3$.

Now there are $n$ sequences. For each sequence, we choose a non-empty contiguous substring, and concatenate them. Compute the sum of the weights of the resulting sequence over all choices.

If a sequence can be obtained in multiple ways, count it multiple times.

This problem includes modification operations; see the input format.

Since the result may be too large, output the answer $\bmod 19260817$.

## 输入格式

The first line contains two integers $n,m$, meaning there are $n$ sequences and $m$ modifications.

The second line contains $n$ integers; the $i$-th number is $len_i$, meaning the length of the $i$-th sequence.

Then follow $n$ lines; the $i$-th line contains $len_i$ integers, representing the $i$-th sequence.

Then follow $m$ lines; each line contains three integers $x,y,z$, meaning change the $y$-th element of the $x$-th sequence to $z$.

## 输出格式

Output $m + 1$ lines, each containing one integer, representing the answer for the initial state and after each modification, in order.

## 输入输出样例 #1

### 输入 #1

```
2 5
6 6
1 3 1 1 3 2 
2 3 3 2 1 1 
1 1 1
1 1 2
1 1 2
1 1 1
1 1 1
```

### 输出 #1

```
1158
1158
1168
1168
1158
1158
```

## 说明/提示

Idea: nzhtl1477, Solution: nzhtl1477, Code: nzhtl1477, Data: nzhtl1477 ( partially uploaded )

$1 \leq n,m,len_i \leq 10^5$. The elements in the sequences are all $32$-bit integers, and $\sum len_i \leq 10^5$.

There are $50$ test cases.

Translated by ChatGPT 5