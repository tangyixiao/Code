# P3935 Calculating 题解

$f(x)$ 就是约数个数 $\tau(x)$。交换枚举顺序可得其前缀和

$$F(n)=\sum_{x=1}^n\tau(x)=\sum_{d=1}^n\left\lfloor\frac nd\right\rfloor.$$

对整除商分块求 $F(r)-F(l-1)$，每次前缀计算为 $O(\sqrt n)$。
