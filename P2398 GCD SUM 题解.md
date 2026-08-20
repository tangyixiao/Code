# P2398 GCD SUM 题解

利用恒等式 $x=\sum_{d\mid x}\varphi(d)$，交换求和顺序：

$$\sum_{i=1}^n\sum_{j=1}^n\gcd(i,j)=\sum_{d=1}^n\varphi(d)\left\lfloor\frac nd\right\rfloor^2.$$

线性筛求出所有欧拉函数后直接累加，复杂度 $O(n)$。
