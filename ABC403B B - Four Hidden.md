# AT_abc403_b [ABC403B] Four Hidden

## 题目描述

[problemUrl]: https://atcoder.jp/contests/abc403/tasks/abc403_b

给定一个由小写字母和 `?` 组成的字符串 $T$，以及一个仅由小写字母组成的字符串 $U$。

字符串 $T$ 是通过将某个仅由小写字母组成的字符串 $S$ 中的恰好 $4$ 个字符替换为 `?` 而得到的。

请判断是否存在这样的 $S$，使得 $S$ 包含 $U$ 作为连续子字符串。

## 输入格式

输入通过标准输入给出，格式如下：

> $T$  
> $U$

## 输出格式

如果存在可能的 $S$ 包含 $U$ 作为连续子字符串，则输出 `Yes`；否则输出 `No`。

## 输入输出样例 #1

### 输入 #1

```
tak??a?h?
nashi
```

### 输出 #1

```
Yes
```

## 输入输出样例 #2

### 输入 #2

```
??e??e
snuke
```

### 输出 #2

```
No
```

## 输入输出样例 #3

### 输入 #3

```
????
aoki
```

### 输出 #3

```
Yes
```

## 说明/提示

### 约束条件

- $T$ 是长度为 $4$ 到 $10$ 的由小写字母和 `?` 组成的字符串
- $T$ 中恰好包含 $4$ 个 `?`
- $U$ 是长度为 $1$ 到 $|T|$ 的仅由小写字母组成的字符串

### 样例解释 #1

例如，当 $S$ 为 `takanashi` 时，它包含 `nashi` 作为连续子字符串。

### 样例解释 #2

无论 `?` 被替换为何种字符，$S$ 都不可能包含 `snuke` 作为连续子字符串。

翻译由 DeepSeek V3 完成

---


# AT_abc403_b [ABC403B] Four Hidden

## 题目描述

You are given a string  $ T $  consisting of lowercase English letters and `?`, and a string  $ U $  consisting of lowercase English letters.

The string  $ T $  is obtained by taking some lowercase-only string  $ S $  and replacing exactly four of its characters with `?`.

Determine whether it is possible that the original string  $ S $  contained  $ U $  as a contiguous substring.

## 输入格式

The input is given from Standard Input in the following format:

> $ T $  $ U $

## 输出格式

Print `Yes` if it is possible that the original string  $ S $  contained  $ U $  as a contiguous substring; otherwise, print `No`.

## 输入输出样例 #1

### 输入 #1

```
tak??a?h?
nashi
```

### 输出 #1

```
Yes
```

## 输入输出样例 #2

### 输入 #2

```
??e??e
snuke
```

### 输出 #2

```
No
```

## 输入输出样例 #3

### 输入 #3

```
????
aoki
```

### 输出 #3

```
Yes
```

## 说明/提示

### Sample Explanation 1

For example, if  $ S $  is `takanashi`, it contains `nashi` as a contiguous substring.

### Sample Explanation 2

No matter what characters replace the `?`s in  $ T $ ,  $ S $  cannot contain `snuke` as a contiguous substring.

### Constraints

- $ T $  is a string of length between  $ 4 $  and  $ 10 $ , inclusive, consisting of lowercase letters and `?`.
- $ T $  contains exactly four occurrences of `?`.
- $ U $  is a string of length between  $ 1 $  and  $ |T| $ , inclusive, consisting of lowercase letters.