# P8380 Two Hypercubes 题解

## 思路分析

这里的等式是整数等式 $y^x=x^z$，只有最终答案对 $10^9+7$ 取模。

先单独处理 $x=1$。此时必须有 $y=1$，而 $z$ 有 $C$ 种取值，贡献为 $C$。

下面设 $x>1$。令：

$$
g=\gcd(x,z),\qquad a=\frac{x}{g},\qquad b=\frac{z}{g}
$$

于是 $\gcd(a,b)=1$。对 $y^x=x^z$ 两边同时除以指数公因数 $g$，得到：

$$
y^a=x^b
$$

因为 $a,b$ 互质，比较两边每个质因数的指数，可知存在唯一整数 $t\ge 2$，使得：

$$
x=t^a,\qquad y=t^b
$$

代回 $z=gb$，有：

$$
z=\frac{t^a b}{a}
$$

因此还需要 $a\mid t^a b$。又 $\gcd(a,b)=1$，所以等价于 $a\mid t^a$，也就是 $t$ 必须被 $a$ 的每个不同质因子整除。记 $d=\operatorname{rad}(a)$，那么条件就是 $d\mid t$。

固定互质的 $(a,b)$，三个上界分别要求：

$$
t^a\le A,\qquad t^b\le B,\qquad t^a\le\left\lfloor\frac{aC}{b}\right\rfloor
$$

令：

$$
R=\min\left(\left\lfloor\sqrt[a]{A}\right\rfloor,
\left\lfloor\sqrt[b]{B}\right\rfloor,
\left\lfloor\sqrt[a]{\left\lfloor aC/b\right\rfloor}\right\rfloor\right)
$$

那么 $t$ 是 $d$ 的倍数且 $2\le t\le R$。若 $a=1$，$d=1$，要去掉 $t=1$，贡献为 $\max(R-1,0)$；若 $a>1$，则 $d\ge2$，贡献为 $\lfloor R/d\rfloor$。

由于 $t\ge2$ 且 $A,B\le10^{18}$，指数 $a,b$ 都不超过 $59$。枚举所有 $1\le a,b\le59$ 且 $\gcd(a,b)=1$ 的组合即可。

整数根用整数 Newton 迭代求初值，再用 128 位快速幂校正，避免浮点误差影响边界。

## 复杂度

每组数据枚举 $O(\log^2 V)$ 个指数对，其中 $V=10^{18}$；整数根用 Newton 迭代和快速幂校正，时间复杂度为 $O(\log^2 V\log\log V)$。空间复杂度为 $O(\log V)$。

## 代码

```cpp
namespace TANGYIXIAO {
const int N = 6e1, M = 4e3 + 5;
const ll mod = 1e9 + 7;
ull A, B, C, ra[N], rb[N];
int pa[M], pb[M], pc;
ll ans;
inline u128 pw(ull x, int e, u128 lim) {
    u128 v = 1, b = x;
    for (; e;) {
        if (e & 1) {
            if (b > lim / v) {
                return lim + 1;
            }
            v *= b;
        }
        e >>= 1;
        if (e) {
            if (b > lim / b) {
                b = lim + 1;
            } else {
                b *= b;
            }
        }
    }
    return v;
}
inline bool chk(ull x, int e, u128 lim) {
    return pw(x, e, lim) <= lim;
}
inline ull rt(u128 x, int e) {
    if (x == 0) {
        return 0;
    }
    if (e == 1) {
        return (ull)x;
    }
    int k = 0;
    for (u128 v = x; v; v >>= 1) {
        k++;
    }
    ull r = 1ULL << ((k + e - 1) / e);
    for (;;) {
        u128 p = pw(r, e - 1, x);
        u128 q = p > x ? 0 : x / p;
        ull nr = (ull)(((u128)(e - 1) * r + q) / e);
        if (nr >= r) {
            break;
        }
        r = nr;
    }
    for (; chk(r + 1, e, x);) {
        r++;
    }
    for (; !chk(r, e, x);) {
        r--;
    }
    return r;
}
inline int rd(int x) {
    int r = 1;
    for (int p = 2; p * p <= x; p++) {
        if (x % p == 0) {
            r *= p;
            for (; x % p == 0;) {
                x /= p;
            }
        }
    }
    if (x > 1) {
        r *= x;
    }
    return r;
}
inline void ini() {
    if (pc) {
        return;
    }
    for (int a = 1; a < N; a++) {
        for (int b = 1; b < N; b++) {
            if (MATH::gcd(a, b) == 1) {
                pa[pc] = a, pb[pc] = b, pc++;
            }
        }
    }
    return;
}
inline void solve(int Task_Id) {
    cin >> A >> B >> C;
    ini();
    for (int e = 1; e < N; e++) {
        ra[e] = rt(A, e), rb[e] = rt(B, e);
    }
    ans = C % mod;
    for (int i = 0; i < pc; i++) {
        int a = pa[i], b = pb[i];
        int d = rd(a), mn = (a == 1 ? 2 : d);
        if (ra[a] < (ull)mn || rb[b] < (ull)mn) {
            continue;
        }
        u128 lim = (u128)C * a / b;
        ull r = min(rb[b], lim < (u128)A ? rt(lim, a) : ra[a]);
        ull cnt = a == 1 ? (r > 1 ? r - 1 : 0) : r / d;
        ans = (ans + cnt % mod) % mod;
    }
    cout << ans << "\n";
    return;
}
} // namespace TANGYIXIAO
```
