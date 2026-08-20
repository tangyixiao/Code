# P1829 [集训队互测 2010] Crash的数字表格 _ JZPTAB 题解

令 $i=da,j=db$ 且 $\gcd(a,b)=1$，再对互质条件做莫比乌斯反演并合并 $d$ 与反演变量。最终得到

$$\sum_{k=1}^{\min(n,m)}F(k)S(\lfloor n/k\rfloor)S(\lfloor m/k\rfloor),$$

其中 $S(x)=x(x+1)/2$，$F(k)=k\prod_{p\mid k}(1-p)$。用线性筛求 $F$ 的前缀和，再整除分块，复杂度 $O(n)$。
