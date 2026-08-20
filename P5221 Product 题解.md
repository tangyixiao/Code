# P5221 Product 题解

有 $\operatorname{lcm}(i,j)/\gcd(i,j)=ij/\gcd(i,j)^2$。分质数统计指数。对质数 $p$ 的每个幂 $p^k$，令 $q=\lfloor N/p^k\rfloor$：分子贡献指数 $2Nq$，所有 gcd 的平方贡献 $2q^2$，净贡献为 $2q(N-q)$。

筛出所有质数，枚举其幂并快速幂累乘即可，复杂度 $O(N\log\log N)$。
