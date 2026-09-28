# P4742 [Wind Festival] Running In The Sky

## 题目背景

[Night - 20:02 P.M.]

夜空真美啊……但是……快要结束了呢……

## 题目描述

一天的活动过后，所有学生都停下来欣赏夜空下点亮的风筝。Curtis Nishikino 想要以更近的视角感受一下，所以她跑到空中的风筝上去了（这对于一个妹子来说有点匪夷所思）！每只风筝上的灯光都有一个亮度 $k_i$。 由于风的作用，一些风筝缠在了一起。但是这并不会破坏美妙的气氛，缠在一起的风筝会将灯光汇聚起来，形成更亮的光源！

Curtis Nishikino 已经知道了一些风筝间的关系，比如给出一对风筝 $(a,b)$, 这意味着她可以从 $a$ 跑到 $b$ 上去，但是不能返回。

现在，请帮她找到一条路径（她可以到达一只风筝多次，但只在第一次到达时她会去感受上面的灯光），使得她可以感受到最多的光亮。同时请告诉她这条路径上单只风筝的最大亮度，如果有多条符合条件的路径，输出能产生最大单只风筝亮度的答案。

## 输入格式

第一行两个整数 $n$ 和 $m$。$n$ 是风筝的数量，$m$ 是风筝间关系对的数量。

接下来一行 $n$ 个整数 $k_i$。

接下来 $m$ 行，每行两个整数 $a$ 和 $b$，即 Curtis 可以从 $a$ 跑到 $b$。

## 输出格式

一行两个整数。Curtis 在计算出的路径上感受到的亮度和，这条路径上的单只风筝最大亮度。

## 输入输出样例 #1

### 输入 #1

```
5 5
8 9 11 6 7
1 2
2 3
2 4
4 5
5 2
```

### 输出 #1

```
41 11
```

## 说明/提示

对于 $20\%$ 的数据，$0<n \le 5\times10^3, \ 0 < m \le 10^4$。

对于 $80\%$ 的数据，$0 < n \le 10^5, \ 0 < m \le 3\times10^5$。

对于 $100\%$ 的数据，$0<n\le2\times10^5,\ 0<m\le5\times10^5,\ 0<k\le200$。

---

# P4742 [Wind Festival] Running In The Sky

## 题目背景

[Night - 20:02 P.M.]

The night sky is so beautiful... but... it is about to end soon....

## 题目描述

After a day of activities, all the students stop to admire the kites lit up under the night sky. Curtis Nishikino wants to experience it from a closer view, so she runs onto the kites in the sky (which is a bit unbelievable for a girl)! Each kite’s light has a brightness $k_i$. Because of the wind, some kites get tangled together. This does not ruin the mood—tangled kites pool their lights to form a brighter light source.

Curtis Nishikino already knows some relations between the kites: for a given pair of kites $(a, b)$, she can run from $a$ to $b$, but she cannot return.

Now, please help her find a path (she may reach a kite multiple times, but only the first arrival counts toward the light she experiences) so that she experiences the maximum total brightness. Also tell her the maximum brightness of a single kite on this path. If there are multiple paths that achieve the same total brightness, output the answer that yields the maximum single-kite brightness.

## 输入格式

The first line contains two integers $n$ and $m$. Here, $n$ is the number of kites, and $m$ is the number of relation pairs.

The next line contains $n$ integers $k_i$.

Each of the next $m$ lines contains two integers $a$ and $b$, meaning Curtis can run from $a$ to $b$.

## 输出格式

Output one line with two integers: the total brightness Curtis experiences along the computed path, and the maximum brightness of a single kite on that path.

## 输入输出样例 #1

### 输入 #1

```
5 5
8 9 11 6 7
1 2
2 3
2 4
4 5
5 2
```

### 输出 #1

```
41 11
```

## 说明/提示

For $20\%$ of the testdata, $0<n \le 5\times10^3, \ 0 < m \le 10^4$.

For $80\%$ of the testdata, $0 < n \le 10^5, \ 0 < m \le 3\times10^5$.

For $100\%$ of the testdata, $0<n\le2\times10^5,\ 0<m\le5\times10^5,\ 0<k_i\le200$.

Translated by ChatGPT 5