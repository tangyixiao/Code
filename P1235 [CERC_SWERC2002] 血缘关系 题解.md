# P1235 [CERC/SWERC2002] 血缘关系

这题递推不难，真正麻烦的是题目要求：

> 有多少精度就输出多少，而且必须准确。

所以不能直接用 `double`。

不过也没必要上高精度库，因为这题出现的概率分母始终都是 $2$ 的幂，可以自己写一个非常简单的高精度整数。

## 相似度递推

设 $f_{x,y}$ 表示妖怪 $x,y$ 的基因相似程度。

首先有

$$
f_{x,x}=1.
$$

对于两个没有父母且不同的妖怪，题目保证它们毫无关系，所以

$$
f_{x,y}=0.
$$

如果妖怪 $x$ 的父母为 $a,b$，那么 $x$ 的一个基因：

* 有 $\frac12$ 概率来自 $a$；
* 有 $\frac12$ 概率来自 $b$。

因此对于任意妖怪 $y$，

$$
f_{x,y}
=
\frac{f_{a,y}+f_{b,y}}2.
$$

所以先把家谱拓扑排序。

按照拓扑序枚举妖怪 $x$，它的父母一定已经计算完成。再枚举拓扑序中位于它前面的妖怪 $y$，直接转移：

$$
f_{x,y}=f_{y,x}
=
\frac{f_{a,y}+f_{b,y}}2.
$$

$n\le300$，直接存整个 $f$ 数组即可。

## 怎么保证精确

连续经过若干代以后，相似度一定可以写成

$$
\frac p{2^d},
$$

其中 $d\le n$。

注意

$$
10^n=2^n5^n,
$$

所以对于任意 $d\le n$，

$$
\frac p{2^d}\times10^n
$$

一定是整数。

于是我们干脆把所有概率统一扩大 $10^n$ 倍。

也就是说实际存储

$$
F_{x,y}=f_{x,y}\times10^n.
$$

那么：

$$
F_{x,x}=10^n,
$$

转移仍然只是

$$
F_{x,y}
=
\frac{F_{a,y}+F_{b,y}}2.
$$

整个过程中不存在任何小数，也就没有精度误差。

$10^{300}$ 普通整数显然存不下，不过我们只需要：

* 高精度加法；
* 高精度除以 $2$；
* 高精度乘一个小整数；
* 转字符串。

直接用数组以 $10^9$ 为一位即可。

$10^{300}$ 只有大约 $34$ 个这样的块，开 $40$ 位已经绰绰有余。

## 输出

现在存储的是

$$
F=f\times10^n.
$$

题目要求百分数，所以需要输出

$$
100f
=
\frac{100F}{10^n}.
$$

因此把高精度整数乘 $100$，转成十进制字符串，然后从右往左数 $n$ 位插入小数点即可。

最后删掉末尾多余的 `0`。

例如：

```text
81.250000% -> 81.25%
50.000000% -> 50%
0.100000% -> 0.1%
```

## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;

namespace TANGYIXIAO {
    const int N=305,K=40;
    const long long B=1000000000LL;

    struct Big {
        int a[K];

        Big() {
            memset(a,0,sizeof(a));
        }
    };

    int n,k,m;
    int fa[N][2],deg[N];
    int e[N][N],ec[N];
    int q[N],p[N],tot;

    Big f[N][N],S;

    void avg(Big &c,const Big &a,const Big &b) {
        long long v=0;

        for (int i=0;i<K;i++) {
            v+=1LL*a.a[i]+b.a[i];
            c.a[i]=v%B;
            v/=B;
        }

        v=0;
        for (int i=K-1;i>=0;i--) {
            long long x=v*B+c.a[i];
            c.a[i]=x/2;
            v=x&1;
        }
    }

    void mul(Big &a,int x) {
        long long v=0;

        for (int i=0;i<K;i++) {
            v+=1LL*a.a[i]*x;
            a.a[i]=v%B;
            v/=B;
        }
    }

    string str(const Big &a) {
        int p=K-1;

        for (;p>0 && !a.a[p];p--) {}

        string s=to_string(a.a[p]);

        for (int i=p-1;i>=0;i--) {
            string t=to_string(a.a[i]);
            s+=string(9-t.size(),'0')+t;
        }

        return s;
    }

    void print(const Big &a) {
        Big x=a;
        mul(x,100);

        string s=str(x);

        if ((int)s.size()<=n) {
            s=string(n+1-s.size(),'0')+s;
        }

        s.insert(s.end()-n,'.');

        for (;!s.empty() && s.back()=='0';) {
            s.pop_back();
        }

        if (!s.empty() && s.back()=='.') {
            s.pop_back();
        }

        cout<<s<<"%\n";
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    using namespace TANGYIXIAO;

    cin>>n>>k;

    for (int i=1;i<=k;i++) {
        int a,b,c;
        cin>>a>>b>>c;

        fa[a][0]=b;
        fa[a][1]=c;

        e[b][++ec[b]]=a;
        e[c][++ec[c]]=a;

        deg[a]+=2;
    }

    int l=1,r=0;

    for (int i=1;i<=n;i++) {
        if (!deg[i]) {
            q[++r]=i;
        }
    }

    for (;l<=r;l++) {
        int x=q[l];
        p[++tot]=x;

        for (int i=1;i<=ec[x];i++) {
            int y=e[x][i];
            deg[y]--;

            if (!deg[y]) {
                q[++r]=y;
            }
        }
    }

    int x=1;

    for (int i=1;i<=n%9;i++) {
        x*=10;
    }

    S.a[n/9]=x;

    for (int i=1;i<=n;i++) {
        int x=p[i];

        f[x][x]=S;

        if (!fa[x][0]) {
            continue;
        }

        int a=fa[x][0],b=fa[x][1];

        for (int j=1;j<i;j++) {
            int y=p[j];

            avg(f[x][y],f[a][y],f[b][y]);
            f[y][x]=f[x][y];
        }
    }

    cin>>m;

    for (int i=1;i<=m;i++) {
        int x,y;
        cin>>x>>y;

        print(f[x][y]);
    }

    return 0;
}
```

这里手写高精度其实很轻，因为根本不需要实现完整的高精度乘除法。

复杂度大概就是 $O(n^2K+mK)$，其中 $K=40$ 是常数，完全够用。
