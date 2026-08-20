# P5542 [USACO19FEB] Painting The Barn S

## 中文题面

在坐标范围 $[0,1000]$ 内依次涂 $n$ 个轴对齐矩形。矩形由左下角 $(x_1,y_1)$ 和右上角 $(x_2,y_2)$ 描述，边界不计面积。求最终恰好被涂 $K$ 层的面积。

### 输入

第一行 $n,K$。随后 $n$ 行为 $x_1,y_1,x_2,y_2$。

$1\le K\le n\le10^5$，所有坐标在 $[0,1000]$ 内，矩形面积为正。

### 输出

恰好覆盖 $K$ 次的面积。

### 样例

```text
3 2
1 1 5 5
4 4 7 6
3 3 8 7
```

```text
8
```

## English Statement

Paint $n$ axis-aligned rectangles whose coordinates lie between 0 and 1000. Output the area covered exactly $K$ times after all rectangles have been painted.
