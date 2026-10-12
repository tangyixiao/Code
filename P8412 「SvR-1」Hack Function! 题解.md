# P8412 「SvR-1」Hack Function! 题解

## 思路分析

先看十进制的例子：$538$ 的数位和是 $5+3+8=16$，再算一次得到 $1+6=7$。原数 $538$、数位和 $16$、最后的 $7$，除以 $9$ 的余数都是 $7$。

这是因为十进制的 $10$ 除以 $9$ 余 $1$。把一个数写成各位数字乘 $10$ 的幂，每个 $10^j$ 除以 $9$ 都余 $1$，所以原数和各位数字之和除以 $9$ 的余数相同。换成 $k$ 进制也是一样：$k$ 除以 $k-1$ 余 $1$，每次做数位和都不改变模 $k-1$ 的余数。

令 $q=k-1$。反复做数位和后，结果会落在 $1$ 到 $q$ 之间。因此只要知道 $Amod q$，就知道 $f(A)$：余数非零时答案就是余数；余数为零时答案是 $q$。接下来只需看 $i^imod q$。

### 从第 $q$ 项开始会重复

令 $P=qarphi(q)$。从 $i=q$ 开始，$f(i^i)$ 每隔 $P$ 项重复一次。

下面说明为什么。把 $q$ 拆成若干互不相同的素数幂 $s^e$ 来看。

- 如果 $s$ 能整除 $i$，那么 $i^i$ 含有足够多个因子 $s$，所以除以 $s^e$ 的余数是 $0$。这里 $i\ge q\ge s^e\ge e$。$P$ 是 $q$ 的倍数，因此 $i+P$ 也能被 $s$ 整除；它的指数也足够大，$(i+P)^{i+P}$ 除以 $s^e$ 仍余 $0$。
- 如果 $s$ 不能整除 $i$，那么 $i$ 和 $i+P$ 除以 $s^e$ 都有逆元。它们的底数除以 $s^e$ 的余数相同，因为 $P$ 是 $q$ 的倍数；指数相差 $P$，而 $P$ 又是 $arphi(s^e)$ 的倍数。根据欧拉定理，指数多出这部分不会改变幂的余数。

所以，对 $q$ 的每个素数幂，$i^i$ 和 $(i+P)^{i+P}$ 的余数都相同；合起来，它们除以 $q$ 的余数也相同。这就说明了周期。

周期长度最多不到一百万，可以直接存下来。固定 $i$ 除以 $q$ 的余数 $x$。周期里对应的项依次是 $i=q+x, q+x+q, q+x+2q,\ldots$：底数除以 $q$ 都是 $x$，指数每次增加 $q$，所以幂的余数每次再乘一次 $x^q$。

$$
(q+x+tq)^{q+x+tq}\equiv x^{q+x}(x^q)^t\pmod q.
$$

每个 $x$ 先算出第一项和每次递推要乘的数，就能用线性时间填好整个周期。余数为 $0$ 的位置按前面的规则记作 $q$。

### 怎么找和为 $p$ 的区间

前 $q-1$ 项还没进入周期。区间起点有三种情况，分别处理。

#### 区间完全在前 $q-1$ 项里

这一段最多只有 $q-1\le998$ 项。枚举左右端点，把区间和加到 $p$ 就输出；和已经超过 $p$ 就可以停止向右扩展，因为每项都是正数。

#### 区间从周期里开始

记一个周期的和为 $C$。把 $p$ 写成 $p=cC+t$，其中 $0\le t<C$。区间里可以先放 $c$ 个完整周期，剩下的部分就是周期数组中一段连续项；如果这段跨过数组末尾，就从数组开头接着找。

若 $t=0$，直接输出 $c$ 个周期。否则用双指针查找和为 $t$ 的循环连续段。因为每项都是正数，而且 $t<C$，这段长度一定小于一个周期。若找到起点 `st` 和长度 `len`，就输出从周期下标 `st` 开始、先走 $c$ 个周期再接这段的区间。

#### 区间从前面开始，并延伸到周期里

如果起点是 $l<q$，区间到达第 $q$ 项之前，必须先完整经过 $l$ 到 $q-1$。代码先算这段固定前缀的和 `sf[l]`。

如果前缀和已经超过 $p$，这个起点不可能。否则，剩下的和是 $p-sf[l]$。周期部分从周期下标 $0$ 开始，因此剩余部分必须是若干完整周期，再接一个周期前缀。枚举 $l$，把剩余和除以周期和；再用前缀和数组二分查找余下的部分。找到后，区间右端点就是前缀结束位置加上周期部分的长度。

这三种情况覆盖了所有起点和终点。都找不到时，才输出 `-1 -1`。

每个 $f(i^i)$ 至少为 $1$，所以和为 $p$ 的区间最多有 $p$ 项。题目中 $p\le10^8$，因此区间长度不超过 $10^8$，满足 $r-l\le10^{15}$；起点至多在周期数组附近，端点也远小于 $10^{18}$。

## 复杂度

设 $P=qarphi(q)$。每组数据的时间复杂度为 $O(P+q^2)$，空间复杂度为 $O(P)$。题目给出 $k\le10^3$，所以 $q\le999$，$P\le999\cdot998=997002$。周期数组 `b` 和前缀和数组 `ps` 按 `N = 1e6 + 5` 开辟；前面的数位根数组 `a` 和前缀和数组 `sf` 按 `K = 1e3 + 5` 开辟。

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
