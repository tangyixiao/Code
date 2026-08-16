# CF1B Spreadsheets

## 题目描述

在流行的电子表格系统（例如 Excel）中，采用如下的列编号方式。第一列标号为 A，第二列为 B，依此类推，直到第 26 列被标为 Z。之后是双字母编号：第 27 列标为 AA，28 为 AB，第 52 列为 AZ。在 ZZ 之后，接下来是三字母编号，依此类推。

行以从 1 开始的整数编号。单元格的名称由列号和行号拼接而成。例如，BC23 表示第 55 列，第 23 行的单元格。

有时也使用另一种编号系统：RXCY，其中 X 和 Y 分别是整数，表示列号和行号。例如，R23C55 表示上面例子中的单元格。

你的任务是编写一个程序，读取给定的单元格坐标序列，并将每个坐标按照另一种编号系统的规则输出。

## 输入格式

输入的第一行为整数 $n$（$1 \leq n \leq 10^{5}$），表示测试中的坐标数量。接下来有 $n$ 行，每行包含一个坐标。所有坐标均为合法坐标，且没有任意列或行编号大于 $10^{6}$ 的单元格。

## 输出格式

输出 $n$ 行，每行应为转换后的单元格坐标，按照另一种编号系统的规则输出。

## 输入输出样例 #1

### 输入 #1

```
2
R23C55
BC23

```

### 输出 #1

```
BC23
R23C55

```

## 说明/提示

由 ChatGPT 5 翻译


---

# CF1B Spreadsheets

## 题目描述

In the popular spreadsheets systems (for example, in Excel) the following numeration of columns is used. The first column has number A, the second — number B, etc. till column 26 that is marked by Z. Then there are two-letter numbers: column 27 has number AA, 28 — AB, column 52 is marked by AZ. After ZZ there follow three-letter numbers, etc.

The rows are marked by integer numbers starting with 1. The cell name is the concatenation of the column and the row numbers. For example, BC23 is the name for the cell that is in column 55, row 23.

Sometimes another numeration system is used: RXCY, where X and Y are integer numbers, showing the column and the row numbers respectfully. For instance, R23C55 is the cell from the previous example.

Your task is to write a program that reads the given sequence of cell coordinates and produce each item written according to the rules of another numeration system.

## 输入格式

The first line of the input contains integer number $ n $ ( $ 1<=n<=10^{5} $ ), the number of coordinates in the test. Then there follow $ n $ lines, each of them contains coordinates. All the coordinates are correct, there are no cells with the column and/or the row numbers larger than $ 10^{6} $ .

## 输出格式

Write $ n $ lines, each line should contain a cell coordinates in the other numeration system.

## 输入输出样例 #1

### 输入 #1

```
2
R23C55
BC23

```

### 输出 #1

```
BC23
R23C55

```