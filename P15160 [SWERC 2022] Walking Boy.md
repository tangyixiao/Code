# P15160 [SWERC 2022] Walking Boy

## 题目描述

SWERC 的一位裁判有一只名叫 Boy 的狗。除了是一名优秀的竞技程序员外，Boy 还喜欢新鲜空气，因此她每天至少需要被遛两次。遛 Boy 需要连续 $120$ 分钟。两次遛狗时间不能重叠，但可以在前一次结束后立即开始下一次。

:::align{center}
 ![](https://cdn.luogu.com.cn/upload/vjudge_pic/CF1776A/78c7ec3373fdb4aaf6097566a036cee5a4aad5b2.png)
 
Boy 在本题得到 ACCEPTED 之前和之后的样子。
:::

今天，裁判在 SWERC Discord 服务器上发送了 $n$ 条消息。第 $i$ 条消息在午夜过后 $a_i$ 分钟时发送。你知道，当裁判遛 Boy 时，他不会发送任何消息，但他可以在遛狗开始前或结束后立即发送消息。请问裁判今天是否可能至少遛了 Boy 两次？

注意一天有 $1440$ 分钟，一次遛狗被认为发生在今天，如果它在分钟 $s \ge 0$ 开始并在分钟 $e \le 1440$ 之前结束。此时，必须满足 $e - s = 120$，并且对于每个 $i = 1, \, 2 \, \dots, \, n$，要么 $a_i \le s$，要么 $a_i \ge e$。

## 输入格式

每个测试包含多个测试用例。第一行包含一个整数 $t$（$1 \le t \le 100$）——测试用例的数量。接下来是 $t$ 个测试用例的描述。

每个测试用例的第一行包含一个整数 $n$（$1 \le n \le 100$）——裁判发送的消息数量。

每个测试用例的第二行包含 $n$ 个整数 $a_1, \, a_2, \, \dots, \, a_n$（$0 \le a_1 < a_2 < \cdots < a_n < 1440$）——消息发送的时间（从午夜开始经过的分钟数）。

## 输出格式

对于每个测试用例，如果可能 Boy 已经被遛了至少两次，则输出一行包含 $\texttt{YES}$，否则输出 $\texttt{NO}$。

## 输入输出样例 #1

### 输入 #1

```
6
14
100 200 300 400 500 600 700 800 900 1000 1100 1200 1300 1400
12
100 200 300 400 600 700 800 900 1100 1200 1300 1400
13
100 200 300 400 500 600 700 800 900 1100 1200 1300 1400
13
101 189 272 356 463 563 659 739 979 1071 1170 1274 1358
1
42
5
0 1 2 3 4
```

### 输出 #1

```
NO
YES
NO
YES
YES
YES
```

## 说明/提示

在**第一个测试用例**中，裁判在每个 $100$ 的倍数时间（不包括 $0$）发送了消息。他不可能遛过 Boy 哪怕一次。

在**第二个测试用例**中，时间与上面相同，但缺少 $500$ 和 $1000$。裁判可能遛了 Boy，例如在时间区间 $[440, 560]$ 和 $[980, 1100]$。情况如下图所示，遛狗时间用绿色区间表示。

:::align{center}
![](https://cdn.luogu.com.cn/upload/image_hosting/h6p83pdg.png)
:::

在**第三个测试用例**中，时间与第一个测试用例相同，但缺少 $1000$。裁判最多可能遛了 Boy 一次。

在**第四个测试用例**中，Boy 可能在时间区间 $[739, 859]$ 和 $[859, 979]$ 被遛过。

:::align{center}
![](https://cdn.luogu.com.cn/upload/image_hosting/ptex73nl.png)
:::

翻译由 DeepSeek 完成

---

# P15160 [SWERC 2022] Walking Boy

## 题目描述

One of the SWERC judges has a dog named Boy. Besides being a good competitive programmer, Boy loves fresh air, so she wants to be walked at least twice a day. Walking Boy requires $ 120 $ consecutive minutes. Two walks cannot overlap, but one can start as soon as the previous one has finished.

:::align{center}
 ![](https://cdn.luogu.com.cn/upload/vjudge_pic/CF1776A/78c7ec3373fdb4aaf6097566a036cee5a4aad5b2.png)
 
Boy before and after getting ACCEPTED on this problem.
:::

Today, the judge sent $ n $ messages to the SWERC Discord server. The $ i $ -th message was sent $ a_i $ minutes after midnight. You know that, when walking Boy, the judge does not send any messages, but he can send a message right before or right after a walk. Is it possible that the judge walked Boy at least twice today?

Note that a day has $ 1440 $ minutes, and a walk is considered to happen today if it starts at a minute $ s \ge 0 $ and ends right before a minute $ e \le 1440 $ . In that case, it must hold that $ e - s = 120 $ and, for every $ i = 1, \, 2 \, \dots, \, n $ , either $ a_i \le s $ or $ a_i \ge e $ .

## 输入格式

Each test contains multiple test cases. The first line contains an integer $ t $ ( $ 1 \le t \le 100 $ ) — the number of test cases. The descriptions of the $ t $ test cases follow.

The first line of each test case contains an integer $ n $ ( $ 1 \le n \le 100 $ ) — the number of messages sent by the judge.

The second line of each test case contains $ n $ integers $ a_1, \, a_2, \, \dots, \, a_n $ ( $ 0 \le a_1 < a_2 < \cdots < a_n < 1440 $ ) — the times at which the messages have been sent (in minutes elapsed from midnight).

## 输出格式

For each test case, output one line containing $ \texttt{YES} $ if it is possible that Boy has been walked at least twice, and $ \texttt{NO} $ otherwise.

## 输入输出样例 #1

### 输入 #1

```
6
14
100 200 300 400 500 600 700 800 900 1000 1100 1200 1300 1400
12
100 200 300 400 600 700 800 900 1100 1200 1300 1400
13
100 200 300 400 500 600 700 800 900 1100 1200 1300 1400
13
101 189 272 356 463 563 659 739 979 1071 1170 1274 1358
1
42
5
0 1 2 3 4
```

### 输出 #1

```
NO
YES
NO
YES
YES
YES
```

## 说明/提示

In the **first test case**, the judge has sent a message at each time multiple of $100$ (excluding $0$). It is impossible that he has walked Boy even once.

In the **second test case**, the times are the same as above, but $500$ and $1000$ are missing. The judge could have walked Boy, for instance, during the time intervals $[440, 560]$ and $[980, 1100]$. The situation is illustrated in the picture below, where the walks are represented by green intervals.

:::align{center}
![](https://cdn.luogu.com.cn/upload/image_hosting/h6p83pdg.png)
:::

In the **third test case**, the times are the same as in the first test case, but $1000$ is missing. The judge could have walked Boy at most once.

In the **fourth test case**, Boy could have been walked during the time intervals $[739, 859]$ and $[859, 979]$.

:::align{center}
![](https://cdn.luogu.com.cn/upload/image_hosting/ptex73nl.png)
:::