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

$t\ge2$，而 $2^{60}$ 已经超过 $10^{18}$，所以 $a,b$ 都不会超过 $59$。枚举所有互质的 $a,b$，把上面的贡献加起来即可。每个三元组的 $a,b$ 由 $\gcd(x,z)$ 唯一确定，$t$ 也由 $x=t^a$ 确定，不会重复统计。

## 避免大数据超时

原来的计数公式正确，但在 $T=2\times10^4$ 的大数据上，反复分解指数、扫描无解指数对，以及整数根中的 128 位除法，造成了超时。实现需要减少这些重复计算。

### 预处理可行的指数对

对于固定的 $a,b$，最小合法底数为 $t_0=\max(2,\operatorname{rad}(a))$。

先预处理每个 $a$ 的不同质因子乘积 $d[a]$。再只保留满足以下条件的互质指数对：

$$
t_0^a\le V,\qquad t_0^b\le V,\qquad bt_0^a\le aV,
\quad V=10^{18}.
$$

三个条件分别对应 $x,y,z$ 的全局最大范围。如果连最小底数都超过范围，更大的底数也不可能合法。这一步只执行一次，得到 419 个可行指数对；后续查询不再分解指数或扫描其他指数对。

### 浮点估计，整数校正

`rt(x,e)` 求最大的整数 $r$，使 $r^e\le x$。

先用 `pow((double)x, 1.0 / e)` 得到候选值，再用精确整数幂向上、向下校正，直到

$$
r^e\le x<(r+1)^e.
$$

浮点结果只提供起点，最终边界由整数比较确定，所以完全幂以及完全幂相邻的数也能正确处理。$x=0$ 和 $e=1$ 直接返回。

`pw(x,e,lim)` 用 128 位乘法计算快速幂，一旦超过 `lim` 就返回 `lim+1`。所有传入的上界都不超过 $10^{18}$，乘法的两个因子也不超过 $10^{18}$；即使候选根需要一次向上检查，其底数也远小于这个界。因此中间乘积不超过 $10^{36}<2^{128}$，可以先乘再判断，不需要每一步都用除法检查溢出。

快速幂中，底数平方后若已经超过上界，且剩余指数非零，最终幂也必定超过上界，可以直接结束。

### 第三个限制有需要时才开根

每组查询先计算 $A,B$ 的各次整数根，记为 `ra`、`rb`。

处理指数对 $a,b$ 时，先取

$$
R=\min(\mathrm{ra}[a],\mathrm{rb}[b]).
$$

如果这个 $R$ 已经满足 $bR^a\le aC$，第三个限制就不会缩小范围，不必再求整数根。

只有 $bR^a>aC$ 时，才更新

$$
R=\left\lfloor\sqrt[a]{\left\lfloor\frac{aC}{b}\right\rfloor}\right\rfloor.
$$

此时 $\lfloor aC/b\rfloor<R^a\le A$，所以新的根上界仍不超过 $10^{18}$，且新 $R$ 一定小于原来的 $R$，不会破坏 $A,B$ 的限制。

计算 $aC$、$bR^a$ 时使用 128 位整数，避免 64 位溢出。最终计数仍为：$a=1$ 时加 $\max(R-1,0)$，$a>1$ 时加 $\lfloor R/d[a]\rfloor$。

设 $L=\lfloor\log_2 V\rfloor=59$，预处理 $O(L^2\log L)$；每组查询处理 $O(L^2)$ 个指数对，幂检查为 $O(\log L)$，整数根候选在本题数值范围内只需常数次边界校正，因此每组时间复杂度为 $O(L^2\log L)$，空间复杂度为 $O(L^2)$。实际每组最多只枚举 419 个指数对。

## 代码

```cpp
namespace TANGYIXIAO {
const int N = 6e1, M = 4e3 + 5;
const ll mod = 1e9 + 7;
const ull V = 1e18;
ull A, B, C, ra[N], rb[N];
int pa[M], pb[M], d[N], pc;
ll ans;
inline ull pw(ull x, int e, ull lim) {
    u128 v = 1, b = x;
    for (; e;) {
        if (e & 1) {
            v *= b;
            if (v > lim) {
                return lim + 1;
            }
        }
        e >>= 1;
        if (e) {
            b *= b;
            if (b > lim) {
                return lim + 1;
            }
        }
    }
    return v;
}
inline ull rt(ull x, int e) {
    if (x == 0) {
        return 0;
    }
    if (e == 1) {
        return x;
    }
    ull r = pow((double)x, 1.0 / e);
    for (; pw(r + 1, e, x) <= x;) {
        r++;
    }
    for (; pw(r, e, x) > x;) {
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
        d[a] = rd(a);
        ull t = max(2, d[a]), x = pw(t, a, V);
        if (x > V) {
            continue;
        }
        for (int b = 1; b < N; b++) {
            if (MATH::gcd(a, b) == 1 && pw(t, b, V) <= V && (u128)x * b <= (u128)V * a) {
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
        int mn = max(2, d[a]);
        if (ra[a] < (ull)mn || rb[b] < (ull)mn) {
            continue;
        }
        ull r = min(ra[a], rb[b]);
        if ((u128)pw(r, a, A) * b > (u128)C * a) {
            r = rt((u128)C * a / b, a);
        }
        ull cnt = a == 1 ? (r > 1 ? r - 1 : 0) : r / d[a];
        ans = (ans + cnt % mod) % mod;
    }
    cout << ans << "\n";
    return;
}
} // namespace TANGYIXIAO
```
