# P8380 Two Hypercubes 题解

## 思路分析

我们要数满足等式的三元组。逐个枚举 $x,y,z$ 太多；不过等式会把它们限制成固定的幂关系，所以可以改为枚举指数 $a,b$，再一次数出对应的底数 $t$。

先看 $x=1$。这时 $y^1=1^z$，所以 $y=1$；$z$ 可以是 $1$ 到 $C$ 的任意整数，贡献就是 $C$。

接下来只看 $x>1$。把 $x$ 和 $z$ 的最大公因数记作 $g$，并写成：

$$
x=ag,\qquad z=bg
$$

这样得到的 $a,b$ 没有大于 $1$ 的公因数，也就是互质。代回原等式：

$$
y^{ag}=x^{bg}
$$

两边都是正整数的 $g$ 次方。正整数取 $g$ 次方不会把两个不同的数变成相同结果，所以可以去掉这个相同的指数：

$$
y^a=x^b
$$

现在固定一组互质的 $a,b$，这个等式会把 $x,y$ 限制成同一个数的幂：

$$
x=t^a,\qquad y=t^b
$$

为什么？看每个质数在 $x,y$ 里分别出现几次。

比如 $a=2,b=3$，等式是 $y^2=x^3$。如果某个质数在 $x$ 里出现 $r$ 次、在 $y$ 里出现 $s$ 次，那么：

$$
2s=3r.
$$

所以 $r=2k,s=3k$：$x$ 里的次数是 $2$ 的倍数，$y$ 里的次数是 $3$ 的倍数，而且来自同一个 $k$。

把每个质数取 $k$ 次乘起来，记成 $t$，就有 $x=t^2,y=t^3$。例如 $x=4,y=8$ 时，就是 $t=2$。

一般的互质 $a,b$ 也是这样：若某个质数在 $x,y$ 中的次数分别为 $r,s$，就有 $as=br$。因为 $a,b$ 互质，必有 $r=ak,s=bk$。所以所有质数都能按同一个底数 $t$ 写成 $x=t^a,y=t^b$。因为这里 $x>1$，所以 $t\ge2$。

这样枚举的对象就从 $x,y,z$ 变成了互质的指数 $a,b$ 和底数 $t$。而且它们不会重复计数：给定一组 $x,z$，$g$ 是唯一的；得到 $a,b$ 后，$t$ 也由 $x=t^a$ 唯一确定。

还要保证 $z$ 是整数。由 $x=ag=t^a$ 可得 $g=t^a/a$，于是：

$$
z=bg=\frac{t^a b}{a}
$$

所以需要 $a\mid t^a b$。$a,b$ 互质，$b$ 不会提供 $a$ 所需的质因子，于是条件等价于 $a\mid t^a$。

这不要求 $t$ 是 $a$ 的倍数，只要求 $t$ 含有 $a$ 里的每种质因子。比如 $a=12=2^2\cdot3$ 时，$t=6$ 已经同时含有 $2$ 和 $3$，虽然 $6$ 不是 $12$ 的倍数，仍有 $12\mid6^{12}$。

如果质因数 $p$ 在 $a$ 中出现 $h$ 次，那么肯定有 $h\le a$。$t$ 里只要有一个 $p$，乘 $a$ 次以后就有 $p^a$，已经足够。

反过来，$t$ 如果没有这个质因数，乘多少次也不会有它。

把 $a$ 里不同的质因子各取一次相乘，记作 $d$。比如 $a=12$ 时 $d=2\cdot3=6$。于是整除条件就是 $d\mid t$。

接下来，对每一组互质的 $(a,b)$，分别看三个上界：

$$
t^a\le A,\qquad t^b\le B,\qquad \frac{t^a b}{a}\le C
$$

最后一个式子等价于 $t^a\le\lfloor aC/b\rfloor$。因此 $t$ 不能超过下面三个数中的最小值：

$$
R=\min\left(\left\lfloor\sqrt[a]{A}\right\rfloor,
\left\lfloor\sqrt[b]{B}\right\rfloor,
\left\lfloor\sqrt[a]{\left\lfloor aC/b\right\rfloor}\right\rfloor\right)
$$

这里的 $k$ 次方根都向下取整，意思是最大的整数 $r$，满足 $r^k$ 不超过对应上界。

现在只需数 $2\le t\le R$ 中有多少个 $d$ 的倍数。

如果 $a>1$，那么 $d\ge2$，所有这些倍数都满足 $t\ge2$，数量是 $\lfloor R/d\rfloor$。

如果 $a=1$，则 $d=1$，要数的是 $2,3,\ldots,R$，数量为 $\max(R-1,0)$。

最后，$t\ge2$ 且 $t^a=x\le A\le10^{18}$，所以 $2^a\le10^{18}$，从而 $a\le59$。同理，由 $y=t^b\le B$ 得 $b\le59$。因此只需枚举 $1\le a,b\le59$ 且互质的组合，把每组贡献加起来，再对 $10^9+7$ 取模。

整数根不能直接用浮点数估。比如 $64$ 的三次方根是 $4$，估成 $3.999\ldots$ 再向下取整，就会少算一个底数。

对上界 $q$ 和指数 $k$，我们要找的是满足 $r^k\le q$ 的最大整数 $r$。代码里的 `rt` 先用整数 牛顿 迭代快速找到根附近的值；可以把它理解为每轮根据当前估值算出一个更接近答案的新估值，不必从小到大试每个整数。

牛顿 迭代只负责找候选值，最后仍用 `pw` 精确检查并向上或向下修正，直到满足：

$$
r^k\le q<(r+1)^k
$$

这样得到的就是 $q$ 的向下取整 $k$ 次方根。`pw` 用 128 位整数计算；一旦幂已经超过 $q$，就把结果记作 $q+1$，这样既能安全比较，也不会让大幂溢出。

## 复杂度

每组数据枚举 $O(\log^2 V)$ 个指数对，其中 $V=10^{18}$；整数根用 牛顿 迭代和快速幂校正，时间复杂度为 $O(\log^2 V\log\log V)$。空间复杂度为 $O(\log^2 V)$（预处理所有指数对）。

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
