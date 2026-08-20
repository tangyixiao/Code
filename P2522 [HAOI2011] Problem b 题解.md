# P2522 [HAOI2011] Problem b 题解

设 $F(n,m,k)$ 表示两个上界内 gcd 为 $k$ 的数对数。两数同除 $k$ 后，用莫比乌斯反演：

$$F(n,m,k)=\sum_{i=1}^{\min(\lfloor n/k\rfloor,\lfloor m/k\rfloor)}\mu(i)\left\lfloor\frac{n/k}{i}\right\rfloor\left\lfloor\frac{m/k}{i}\right\rfloor.$$

预处理 $\mu$ 前缀和，整除分块求 $F$，矩形答案用四次前缀容斥。
