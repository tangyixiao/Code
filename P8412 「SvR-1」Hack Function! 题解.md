# P8412 「SvR-1」Hack Function! 题解

## 思路分析

令 $q=k-1$。对正整数 $A$，反复进行 $k$ 进制数位和后得到的数，与 $A$ 模 $q$ 同余，且最终结果在 $1$ 到 $q$ 之间。因此

$$
f(A)=\begin{cases}A\bmod q,&A\not\equiv0\pmod q,\\q,&A\equiv0\pmod q.\end{cases}
$$

于是只需研究 $i^i\bmod q$，并把余数 $0$ 映射为 $q$。

### 从 $q$ 开始的周期

设 $P=q\varphi(q)$。当 $i\ge q$ 时，数列 $f(i^i)$ 以 $P$ 为周期。

对任意素数幂 $s^e\mid q$，若 $s\mid i$，则 $i\ge q\ge e$，所以 $i^i\equiv0\pmod {s^e}$；$i+P$ 也满足这一点。若 $s\nmid i$，则 $i$ 是模 $s^e$ 的单位，而 $P$ 是 $\varphi(s^e)$ 的倍数，因此

$$
(i+P)^{i+P}\equiv i^i\pmod {s^e}.
$$

由中国剩余定理，$i^i\bmod q$ 的周期整除 $P$。

可以用 $O(P)$ 时间生成这个周期。固定余数 $x=i\bmod q$，周期中的位置为 $i=q+x+tq$，因此

$$
i^i\equiv x^{q+x}(x^q)^t\pmod q.
$$

对每个 $x$ 先计算初值和公比，再递推 $\varphi(q)$ 次即可。

### 构造区间

把区间按起点和终点分成三类。记周期段一个周期的和为 $C$。

- 若区间完全位于 $[1,q-1]$，直接枚举所有子区间。
- 若 $l\ge q$，区间完全位于周期段。把目标和写成 $p=cC+t$，其中 $0\le t<C$。先取 $c$ 个完整周期，再在周期数组中寻找和为 $t$ 的循环连续段；若 $t=0$，直接输出 $c$ 个周期。由于各项为正且 $t<C$，循环段长度小于 $P$，用双指针在线性时间内枚举所有起点即可。
- 若 $l<q$ 且右端点 $r\ge q$，区间先包含固定的前缀 $l\sim q-1$，随后接上从周期下标 $0$ 开始的一段数列。减去前缀和后，周期部分可写成若干完整周期加一个短前缀；短前缀的和用周期前缀和数组二分查找。

以上三类覆盖所有可能的区间；若都找不到，就输出 $-1 -1$。

题目要求的区间长度不超过 $p$，而 $p\le10^8$；构造出的端点也远小于 $10^{18}$，满足输出范围。

## 复杂度

设 $P=q\varphi(q)$。每组数据的时间复杂度为 $O(P+q^2)$，空间复杂度为 $O(P)$。

题目保证 $k\le10^3$，所以 $q\le999$ 且 $P\le999\cdot998=997002$。周期数组按 `N = 1e6 + 5` 开辟；前缀数组长度 $m+1$ 也在该范围内。瞬态数组按 `K = 1e3 + 5` 开辟。

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
