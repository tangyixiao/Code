# P4824 [USACO15FEB] Censoring S

## 题目描述

Farmer John 为他的奶牛订阅了《Good Hooveskeeping》杂志，但最新一期包含了一篇不恰当的牛排烹饪文章。为此，FJ 需要将杂志文字组成的字符串 $S$（长度不超过 $10^6$）中所有出现的子串 $T$ 进行删除处理。

删除规则如下：反复找到当前 $S$ 中第一个出现的子串 $T$ 并删除，直到 $S$ 中不再包含 $T$。注意，删除操作可能产生新的 $T$ 子串。

请输出最终处理完成的字符串 $S$。

## 输入格式

第一行输入字符串 $S$。  
第二行输入字符串 $T$。  
保证 $T$ 的长度不超过 $S$，且 $S$ 和 $T$ 均由小写字母组成。删除过程中保证 $S$ 不会变为空。

## 输出格式

输出处理完成后的字符串 $S$。

## 输入输出样例 #1

### 输入 #1

```
whatthemomooofun
moo
```

### 输出 #1

```
whatthefun
```

---

# P4824 [USACO15FEB] Censoring S

## 题目描述

Farmer John has purchased a subscription to Good Hooveskeeping magazine for his cows, so they have plenty of material to read while waiting around in the barn during milking sessions. Unfortunately, the latest issue contains a rather inappropriate article on how to cook the perfect steak, which FJ would rather his cows not see (clearly, the magazine is in need of better editorial oversight).

FJ has taken all of the text from the magazine to create the string $S$ of length at most 10^6 characters. From this, he would like to remove occurrences of a substring $T$ to censor the inappropriate content. To do this, Farmer John finds the **_first_** occurrence of $T$ in $S$ and deletes it. He then repeats the process again, deleting the first occurrence of $T$ again, continuing until there are no more occurrences of $T$ in $S$. Note that the deletion of one occurrence might create a new occurrence of $T$ that didn't exist before.

Please help FJ determine the final contents of $S$ after censoring is complete.

## 输入格式

The first line will contain $S$. The second line will contain $T$. The length of $T$ will be at most that of $S$, and all characters of $S$ and $T$ will be lower-case alphabet characters (in the range a..z).

## 输出格式

The string $S$ after all deletions are complete. It is guaranteed that $S$ will not become empty during the deletion process.

## 输入输出样例 #1

### 输入 #1

```
whatthemomooofun
moo
```

### 输出 #1

```
whatthefun
```