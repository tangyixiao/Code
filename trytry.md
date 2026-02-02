我们注意到所有节点的权值可分为  $k+b(b \in \mathbb{R})$  与  $-k+b(b \in \mathbb{R})$  两种表示，因此我们将其分为两个集合  $S_{0}=\{x \mid x=-k+b\}$  与  $S_{1}=\{x \mid x=k+b\}$ 
并定义




易得  k  的取值合法当且仅当满足：

$$
\left\{\begin{array}{l}
l_{0}-k>0 \\
l_{1}+k>0 \\
r_{0}-k<\inf \\
r_{1}+k<\inf
\end{array}\right.
$$

化简后即为

$$
\max \left(-l_{1}, r_{0}-i n f\right)<k<\min \left(l_{0}, i n f-r_{1}\right)
$$

最后输出时钦定一个合法的  k  值即可。