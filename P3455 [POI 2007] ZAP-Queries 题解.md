# P3455 [POI 2007] ZAP-Queries 题解

把 $x,y$ 同除以 $d$，问题变成统计两个矩形上界内的互质有序对。由莫比乌斯反演，答案为

$$\sum_i\mu(i)\left\lfloor\frac{a/d}{i}\right\rfloor\left\lfloor\frac{b/d}{i}\right\rfloor.$$

线性筛预处理莫比乌斯前缀和，每组询问整除分块，复杂度 $O(\sqrt n)$。
