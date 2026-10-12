# P8380 Two Hypercubes 题解

## 思路分析

直接枚举 $x,y,z$ 肯定不行，范围有 $10^{18}$。先把等式整理一下，看看哪些数能满足。

$x=1$ 时，$y$ 也只能是 $1$，$z$ 随便取，贡献 $C$。

下面考虑 $x>1$。令 $g=\gcd(x,z)$，把 $x,z$ 写成 $ag,bg$，那么 $a,b$ 互质。原式两边同时开 $g$ 次方根，得到：

$$
y^a=x^b.
$$

因为 $a,b$ 互质，所以 $x,y$ 一定能写成同一个底数的幂：

$$
x=t^a,\qquad y=t^b.
$$

比如 $a=2,b=3$，等式就是 $y^2=x^3$。某个质因子在 $x$ 里出现 $r$ 次，在 $y$ 里出现 $s$ 次，就有 $2s=3r$，所以 $r=2k,s=3k$。把每个质因子取 $k$ 次乘起来，就是这个底数 $t$。$x=4,y=8$ 时，$t$ 就是 $2$。

一般的 $a,b$ 同理。这样就可以改成枚举 $a,b$，再数有多少个 $t$。$x>1$，所以 $t$ 至少是 $2$。

由 $x=ag=t^a$，还能算出：

$$
z=bg=\frac{bt^a}{a}.
$$

$z$ 必须是整数，因此 $a$ 要能整除 $bt^a$。$a,b$ 互质，这个条件就是 $a$ 能整除 $t^a$。

把 $a$ 的不同质因子乘起来，记成 $d$，那么 $t$ 必须是 $d$ 的倍数。

比如 $a=12=2^2\cdot3$，$d=2\cdot3=6$。$t$ 只要同时含有 $2,3$ 就够了，因为乘 $12$ 次以后，这两个质因子的次数肯定够用。反过来，$t$ 如果缺少其中一个质因子，乘多少次也补不出来。

$a,b$ 定下来以后，$t$ 越大，$x,y,z$ 都越大。分别根据 $A,B,C$ 算出 $t$ 最多能取多少，再取最小值，记成 $R$。

举个例子，$a=2,b=3$，$A=100,B=1000,C=96$。

$x=t^2\le100$，所以 $t\le10$；$y=t^3\le1000$，也要求 $t\le10$。

$z=3t^2/2\le96$，也就是 $t^2\le64$，要求 $t\le8$。

三个条件一起满足，就只能取到 $8$。又因为 $a=2$，$t$ 必须是偶数，所以只有 $2,4,6,8$，这一组 $a,b$ 贡献 $4$。

一般情况下也是这样。$a>1$ 时，$d\ge2$，合法底数就是 $d,2d,3d,\ldots$，不超过 $R$ 的一共有 $\lfloor R/d\rfloor$ 个。

$a=1$ 时，$d=1$，但 $t=1$ 已经在开头统计过，所以只数 $2$ 到 $R$，贡献 $\max(R-1,0)$。

计算上界时，前两个条件分别求 $A$ 的整数 $a$ 次方根、$B$ 的整数 $b$ 次方根。第三个条件先整理成 $t^a\le\lfloor aC/b\rfloor$，再求整数 $a$ 次方根。三个结果取最小即可。

代码里的 `rt(x,k)` 就是求最大的整数 $t$，使 $t^k\le x$。算出候选值后，用整数快速幂检查边界；中间计算用 128 位整数，幂超过上界后就不必继续算出完整结果。

$t\ge2$，而 $2^{60}$ 已经超过 $10^{18}$，所以 $a,b$ 都不会超过 $59$。枚举所有互质的 $a,b$，把上面的贡献加起来即可。每个三元组的 $a,b$ 由 $\gcd(x,z)$ 唯一确定，$t$ 也由 $x=t^a$ 确定，不会重复统计。

每组枚举 $O(\log^2 V)$ 个指数对，其中 $V=10^{18}$。计入整数根计算，时间复杂度 $O(\log^2 V\log\log V)$，空间复杂度 $O(\log^2 V)$。

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
