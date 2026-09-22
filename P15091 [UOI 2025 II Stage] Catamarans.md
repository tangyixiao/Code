# P15091 [UOI 2025 II Stage] Catamarans

## 题目描述

一个由 $n$ 人组成的小组计划去坐双体船游玩。

作为小组的领队，你的任务是预订双体船。你知道一艘双体船最多可以承载 $100$ 公斤的重量，并且你也知道小组中每个成员的体重。

你知道在你的小组中，一个人的体重可能是 $20$、$40$、$60$、$80$ 或 $100$ 公斤。

为了尽可能省钱，你决定编写一个程序来计算所需双体船的最少数量。

## 输入格式

-   第一行包含一个整数 $n$（$1 \le n \le 1\,000$）——小组中的人数。
-   第二行包含 $n$ 个整数 $a_1, a_2, \dots, a_n$（$a_i \in \{20, 40, 60, 80, 100\}$）——每个人的体重。

## 输出格式

输出一个整数——所需双体船的最少数量。

## 输入输出样例 #1

### 输入 #1

```
4
20 40 80 80
```

### 输出 #1

```
3
```

## 输入输出样例 #2

### 输入 #2

```
4
20 40 20 20
```

### 输出 #2

```
1
```

## 说明/提示

在第一个示例中，我们可以将前两个人安排在一艘双体船上，第三个人安排在第二艘，第四个人安排在第三艘。我们无法将所有人安排在两艘双体船上，因为第 $2$ 个人不能与第 $3$ 或第 $4$ 个人同船，第 $3$ 个人也不能与第 $4$ 个人同船。

在第二个示例中，我们可以将所有人安排在一艘双体船上，因为他们的总重量等于 $100$ 公斤，这意味着双体船可以承载他们。

翻译由 DeepSeek V3 完成

---

# P15091 [UOI 2025 II Stage] Catamarans

## 题目描述

A group of $n$ people plans to go for a ride on catamarans.

As the leader of the group, you have been tasked with ordering the catamarans. You know that one catamaran can hold a weight of no more than $100$ kilograms, and you also know the weight of each group member.

You are aware that in your group, a person can weigh either $20$, $40$, $60$, $80$, or $100$ kilograms.

To spend as little money as possible, you decided to write a program that calculates the minimum number of catamarans needed.

## 输入格式

The first line contains one integer $n$ $(1 \le n \le 1\,000)$~--- the number of people in the group.

The second line contains $n$ integers $a_1, a_2, \dots, a_n$ $(a_i \in \{20, 40, 60, 80, 100\})$~--- the weight of each person.

## 输出格式

Output one integer --- the minimum number of catamarans needed.

## 输入输出样例 #1

### 输入 #1

```
4
20 40 80 80
```

### 输出 #1

```
3
```

## 输入输出样例 #2

### 输入 #2

```
4
20 40 20 20
```

### 输出 #2

```
1
```

## 说明/提示

In the first example, we can seat the first two people in one catamaran, the third person in the second catamaran, and the fourth person in the third catamaran. We cannot seat everyone in two catamarans because person $2$ cannot sit with person $3$ or $4$, and person $3$ cannot sit with person $4$ either.

In the second example, we can seat everyone in one catamaran because their total weight is equal to $100$ kilograms, which means the catamaran can hold them.