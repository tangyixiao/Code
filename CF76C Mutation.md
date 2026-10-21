# CF76C Mutation

## 题目描述

奥林匹亚星球的科学家正在进行一种原始生物突变实验。这个星球生物的基因组可以表示为由前 $K$ 个大写英文字母组成的字符串。对于每对基因类型，科学家定义了 $a_{i,j}$ —— 当这两种类型的基因在基因组中相邻时，生物患病的风险，其中 $i$ 是第一种基因的编号，$j$ 是第二种基因的编号。'A' 的编号为 1，'B' 的编号为 2，依此类推。例如，$a_{3,2}$ 表示序列片段 'CB' 的风险。当基因组中每一对相邻基因的风险相加时，总风险即为生物患病的风险。

科学家已经获得了一个基础生物。可以通过“突变”获得一些新的生物。突变的方式是删除所有某一类的基因。这样的删除将会额外增加总风险。对于每种类型的基因，科学家给出了 $t_{i}$ —— 删除所有该类型（编号 $i$）基因时，所增加的总风险。例如，$t_{4}$ 表示删除所有 'D' 基因时新增加的总风险。

科学家希望计算，能够通过上述“突变”操作（仅可进行这种操作）从给定的基础生物获得多少种不同的新生物，其总风险不超过 $T$。两个生物不同，是指其基因组字符串不同。基因组至少要包含一个基因。

## 输入格式

输入的第一行包含三个整数 $N$（$1 \leq N \leq 200000$）——基础生物基因组的长度，$K$（$1 \leq K \leq 22$）——基因类型的最大编号，以及 $T$（$1 \leq T \leq 2 \cdot 10^{9}$）——允许的最大总风险。  
第二行是一个长度为 $N$ 的字符串，表示基础生物的基因组，由前 $K$ 个大写英文字母组成。

第三行包含 $K$ 个数 $t_{1}, t_{2}, ..., t_{K}$，其中 $t_{i}$ 是删除编号为 $i$ 的基因类型时增加的总风险。

接下来的 $K$ 行描述了给定的矩阵 $a_{i,j}$。第 $i$ 行的 $K$ 个数，第 $i$ 行的第 $j$ 个数代表一对基因（第 $i$ 个字母和第 $j$ 个字母）相邻时的风险。这个矩阵不一定对称。

输入中所有数均为整数且非负，除了 $T$ 以外的所有数均不超过 $10^9$。保证从给定生物获得的任意新生物的最大可能风险严格小于 $2^{31}$。

## 输出格式

输出能够通过突变获得、且总风险不超过 $T$ 的不同生物的数量。

## 输入输出样例 #1

### 输入 #1

```
5 3 13
BACAC
4 1 2
1 2 3
2 3 4
3 4 10

```

### 输出 #1

```
5

```

## 说明/提示

说明：可以获得以下几种生物（括号中为各自的风险）：BACAC（11）、ACAC（10）、BAA（5）、B（6）、AA（4）。

由 ChatGPT 5 翻译

---

# CF76C Mutation

## 题目描述

Scientists of planet Olympia are conducting an experiment in mutation of primitive organisms. Genome of organism from this planet can be represented as a string of the first $ K $ capital English letters. For each pair of types of genes they assigned $ a_{i,j} $ — a risk of disease occurence in the organism provided that genes of these types are adjacent in the genome, where $ i $ — the 1-based index of the first gene and $ j $ — the index of the second gene. The gene 'A' has index 1, 'B' has index 2 and so on. For example, $ a_{3,2} $ stands for the risk of 'CB' fragment. Risk of disease occurence in the organism is equal to the sum of risks for each pair of adjacent genes in the genome.

Scientists have already obtained a base organism. Some new organisms can be obtained by mutation of this organism. Mutation involves removal of all genes of some particular types. Such removal increases the total risk of disease occurence additionally. For each type of genes scientists determined $ t_{i} $ — the increasement of the total risk of disease occurence provided by removal of all genes having type with index $ i $ . For example, $ t_{4} $ stands for the value of additional total risk increasement in case of removing all the 'D' genes.

Scientists want to find a number of different organisms that can be obtained from the given one which have the total risk of disease occurence not greater than $ T $ . They can use only the process of mutation described above. Two organisms are considered different if strings representing their genomes are different. Genome should contain at least one gene.

## 输入格式

The first line of the input contains three integer numbers $ N $ ( $ 1<=N<=200000 $ ) — length of the genome of base organism, $ K $ ( $ 1<=K<=22 $ ) — the maximal index of gene type in the genome and $ T $ ( $ 1<=T<=2·10^{9} $ ) — maximal allowable risk of disease occurence. The second line contains the genome of the given organism. It is a string of the first $ K $ capital English letters having length $ N $ .

The third line contains $ K $ numbers $ t_{1},t_{2},...,t_{K} $ , where $ t_{i} $ is additional risk value of disease occurence provided by removing of all genes of the $ i $ -th type.

The following $ K $ lines contain the elements of the given matrix $ a_{i,j} $ . The $ i $ -th line contains $ K $ numbers. The $ j $ -th number of the $ i $ -th line stands for a risk of disease occurence for the pair of genes, first of which corresponds to the $ i $ -th letter and second of which corresponds to the $ j $ -th letter. The given matrix is not necessarily symmetrical.

All the numbers in the input are integer, non-negative and all of them except $ T $ are not greater than $ 10^{9} $ . It is guaranteed that the maximal possible risk of organism that can be obtained from the given organism is strictly smaller than $ 2^{31} $ .

## 输出格式

Output the number of organisms that can be obtained from the base one and which have the total risk of disease occurence not greater than $ T $ .

## 输入输出样例 #1

### 输入 #1

```
5 3 13
BACAC
4 1 2
1 2 3
2 3 4
3 4 10

```

### 输出 #1

```
5

```

## 说明/提示

Explanation: one can obtain the following organisms (risks are stated in brackets): BACAC (11), ACAC (10), BAA (5), B (6), AA (4).