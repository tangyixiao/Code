# P8412 「SvR-1」Hack Function! 题解

## 思路分析

先看十进制：$538$ 的数位和是 $5+3+8=16$，再算一次得到 $1+6=7$。原数 $538$、数位和 $16$、最后的 $7$，除以 $9$ 的余数都是 $7$。

原因是 $10$ 除以 $9$ 余 $1$。把一个数写成各位数字乘 $10$ 的幂后，每个 $10^j$ 除以 $9$ 都余 $1$，所以原数和数位和除以 $9$ 的余数相同。换成 $k$ 进制也一样：$k$ 除以 $k-1$ 余 $1$，每做一次数位和，模 $k-1$ 的余数都不变。

令 $q=k-1$。反复做数位和后，结果会落在 $1$ 到 $q$ 之间。因此只要知道 $A\bmod q$，就知道 $f(A)$：余数非零时答案就是这个余数；余数为零时答案是 $q$。题目里的数是 $i^i$，所以接下来只需研究 $i^i\bmod q$。

接下来找数列的周期。

记 $\varphi(q)$ 为欧拉函数，也就是 $1$ 到 $q$ 中与 $q$ 互质的数的个数。取：

$$
P=q\varphi(q).
$$

从 $i=q$ 开始，$f(i^i)$ 每隔 $P$ 项重复一次。

先看为什么。把 $q$ 按质因数拆开，比如 $q=12$，就分别看模 $4$ 和模 $3$ 的结果。一般把其中一块记成 $s^e$，其中 $s$ 是质数。

如果 $s$ 能整除 $i$，那么 $i^i$ 至少含有 $i$ 个因子 $s$。由于 $i\ge q\ge s^e\ge e$，这些因子足够让 $s^e$ 整除 $i^i$，所以余数是 $0$。

$P$ 是 $q$ 的倍数，因此 $i+P$ 也能被 $s$ 整除，指数同样足够大，余数还是 $0$。

如果 $s$ 不能整除 $i$，那 $i$ 与 $s^e$ 互质。这时可以用欧拉定理：指数每增加 $\varphi(s^e)$，幂模 $s^e$ 的余数不变。

$i+P$ 与 $i$ 模 $s^e$ 的余数相同，所以只需要看指数多出的 $P$。$\varphi(q)$ 是各个 $\varphi(s^e)$ 的乘积，$P$ 也是 $\varphi(s^e)$ 的倍数，因此余数仍然相同。

这样，在每个 $s^e$ 下，两项的余数都相同。各个素数幂互质，合起来模 $q$ 的余数也相同。比如一个差同时能被 $4,3$ 整除，也就能被 $12$ 整除。

周期长度不到一百万，可以直接存下一个周期。固定 $i$ 除以 $q$ 的余数 $x$。周期中对应的下标依次是 $q+x,\ q+x+q,\ q+x+2q,\ldots$。这些数模 $q$ 都是 $x$，指数每次增加 $q$，所以幂的余数按下面的式子递推：

$$
(q+x+tq)^{q+x+tq}\equiv x^{q+x}(x^q)^t\pmod q.
$$

让 $x$ 从 $0$ 到 $q-1$，依次填入下标 $x,x+q,x+2q,\ldots$，就能覆盖整个周期。每个 $x$ 只需算出第一项和递推时要乘的数；余数为 $0$ 的位置按前面的规则记作 $q$。

有了周期，再来找和为 $p$ 的区间。

周期前还有 $1$ 到 $q-1$ 这些项，区间可能只在前面、只在周期里，也可能跨过两段。

先看区间完全在前 $q-1$ 项里的情况。

这一段最多只有 $q-1\le998$ 项。枚举左右端点并累加；和等于 $p$ 时输出。若和已经超过 $p$，就停止向右扩展，因为每项都是正数，继续加只会更大。

如果区间从周期里开始，就可以先取完整的周期。

记一个周期的和为 $C$。无论从周期的哪个位置开始，连续走完整个周期，和都是 $C$。

所以先用除法把目标拆成：

$$
p=cC+t,\qquad 0\le t<C.
$$

意思是先取 $c$ 个完整周期，再凑余下的 $t$。

假设一个周期是 $2,3,4$，周期和为 $9$。要凑 $23=2\cdot9+5$，就先取两个完整周期，再接 $2,3$ 这两项。

完整周期走完以后又回到同一个位置，所以接上的部分仍然连续。

$t=0$ 时，直接取 $c$ 个周期就行。否则要在周期数组里找一段和为 $t$ 的连续段；走到数组末尾后，可以绕回开头。

这段长度一定小于 $P$，因为走满 $P$ 项，和就已经是 $C>t$。

各项都是正数，可以用双指针：和不够，就向右加一项；和超过了，就从左边减掉一项。两个指针只向右走，不需要回头。

找到起点和长度后，就从这个位置先走 $c$ 个周期，再接上这段。

还要考虑从前 $q-1$ 项开始，一直延伸到周期里的情况。

若起点是 $l<q$，区间到达周期前，必须先完整经过 $l$ 到 $q-1$。代码用 `sf[l]` 存这段的和。

如果这一段的和已经超过 $p$，这个起点不可能。否则，剩下要凑的和是 $p-sf[l]$。

后面的周期部分固定从下标 $0$ 开始。先取若干完整周期，余下的只能是周期开头的若干项。

因此，枚举 $l$，先用除法算出完整周期数，再在周期的前缀和数组里二分，看看有没有刚好等于余下目标和的位置。

周期各项都是正数，前缀和严格递增，所以可以二分。找到后，根据总共取了多少项算出右端点即可。

以上三种情况覆盖了所有区间起点。都找不到时，输出 -1 -1。

每个 $f(i^i)$ 至少为 $1$，所以和为 $p$ 的区间最多有 $p$ 项。题目给出 $p\le10^8$，故区间长度不超过 $p$，而 $r-l$ 比项数还少 $1$，满足题面范围。构造出的周期起点不超过 $q+P-1$，约一百万；终点再加上至多 $p-1$，也远小于 $10^{18}$。

设 $P=q\varphi(q)$。每组时间复杂度 $O(P+q^2)$，空间复杂度 $O(P)$。

由于 $q\le999$，周期长度不超过 $999\cdot998=997002$，所以 `b`、`ps` 开到 `N = 1e6 + 5` 即可。

`a` 存前 $q-1$ 项，`sf[l]` 存 $l$ 到 $q-1$ 的和，两者开到 `K = 1e3 + 5` 即可。

## 代码

代码只列出模板末尾的 `namespace TANGYIXIAO` 部分。

```cpp
namespace TANGYIXIAO {
using ll = long long;
const int N = 1e6 + 5, K = 1e3 + 5;
int a[K], b[N];
ll ps[N], sf[K];
int k, q, ph, m, st, len;
ll p, cs, c, t, nd, cc, rem, tot;

inline ll pw(ll x, int e, int y) {
    ll r = 1 % y;
    for (; e; e >>= 1) {
        if (e & 1) {
            r = r * x % y;
        }
        x = x * x % y;
    }
    return r;
}

inline int phi(int x) {
    int r = x;
    for (int d = 2; d * d <= x; d++) {
        if (x % d == 0) {
            r = r / d * (d - 1);
            for (; x % d == 0; x /= d) {
            }
        }
    }
    if (x > 1) {
        r = r / x * (x - 1);
    }
    return r;
}

inline bool chk(int *a, int n, ll v, int &st, int &len) {
    if (v <= 0) {
        return false;
    }
    int r = 0;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        for (; r < i + n && sum < v; r++) {
            sum += a[r % n];
        }
        if (sum == v) {
            st = i, len = r - i;
            return true;
        }
        if (r > i) {
            sum -= a[i];
        }
    }
    return false;
}

inline void out(ll l, ll r) {
    cout << l << " " << r << "\n";
    return;
}

inline void solve(int Task_Id) {
    cin >> k >> p;
    q = k - 1, ph = phi(q), m = q * ph;
    ps[0] = 0, sf[q] = 0;
    for (int i = 1; i < q; i++) {
        int x = (int)pw(i, i, q);
        a[i] = x ? x : q;
    }
    for (int x = 0; x < q; x++) {
        if (x == 0) {
            for (int t = 0; t < ph; t++) {
                b[t * q] = q;
            }
            continue;
        }
        ll v = pw(x, q + x, q), r = pw(x, q, q);
        for (int t = 0; t < ph; t++) {
            int j = x + t * q;
            b[j] = v ? (int)v : q;
            v = v * r % q;
        }
    }
    cs = 0;
    for (int i = 0; i < m; i++) {
        cs += b[i];
    }

    for (int l = 1; l < q; l++) {
        ll sum = 0;
        for (int r = l; r < q; r++) {
            sum += a[r];
            if (sum == p) {
                out(l, r);
                return;
            }
            if (sum > p) {
                break;
            }
        }
    }

    c = p / cs, t = p % cs;
    if (t == 0 && c > 0) {
        out(q, q + c * m - 1);
        return;
    }
    if (chk(b, m, t, st, len)) {
        out(q + st, q + st + c * m + len - 1);
        return;
    }

    for (int i = 0; i < m; i++) {
        ps[i + 1] = ps[i] + b[i];
    }
    for (int i = q - 1; i >= 1; i--) {
        sf[i] = sf[i + 1] + a[i];
    }
    for (int l = 1; l < q; l++) {
        if (p < sf[l]) {
            continue;
        }
        nd = p - sf[l], cc = nd / cs, rem = nd % cs;
        ll *it = lower_bound(ps, ps + m, rem);
        if (it == ps + m || *it != rem) {
            continue;
        }
        tot = cc * m + (it - ps);
        if (tot > 0) {
            out(l, q - 1 + tot);
            return;
        }
    }

    out(-1, -1);
    return;
}
} // namespace TANGYIXIAO
```
