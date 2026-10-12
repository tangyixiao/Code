# P8412 「SvR-1」Hack Function! 题解

## 思路分析

先看十进制：\(538\) 的数位和是 \(5+3+8=16\)，再算一次得到 \(1+6=7\)。原数 \(538\)、数位和 \(16\)、最后的 \(7\)，除以 \(9\) 的余数都是 \(7\)。

原因是 \(10\) 除以 \(9\) 余 \(1\)。把一个数写成各位数字乘 \(10\) 的幂后，每个 \(10^j\) 除以 \(9\) 都余 \(1\)，所以原数和数位和除以 \(9\) 的余数相同。换成 \(k\) 进制也一样：\(k\) 除以 \(k-1\) 余 \(1\)，每做一次数位和，模 \(k-1\) 的余数都不变。

令 \(q=k-1\)。反复做数位和后，结果会落在 \(1\) 到 \(q\) 之间。因此只要知道 \(A\bmod q\)，就知道 \(f(A)\)：余数非零时答案就是这个余数；余数为零时答案是 \(q\)。题目里的数是 \(i^i\)，所以接下来只需研究 \(i^i\bmod q\)。

### 从第 \(q\) 项开始会重复

令周期长度 \(P=q\varphi(q)\)。从 \(i=q\) 开始，\(f(i^i)\) 每隔 \(P\) 项重复一次。

说明这个结论时，要考虑 \(q\) 可能有重复的质因子。把 \(q\) 拆成互不相同的素数幂 \(s^e\)，分别看模 \(s^e\) 的结果。

如果 \(s\mid i\)，那么 \(i^i\) 里至少有 \(i\) 个因子 \(s\)。又因为 \(i\ge q\ge s^e\ge e\)，所以 \(s^e\mid i^i\)。\(P\) 是 \(q\) 的倍数，故 \(i+P\) 也能被 \(s\) 整除；而且 \(i+P\ge e\)，所以 \((i+P)^{i+P}\) 同样能被 \(s^e\) 整除。两边模 \(s^e\) 都是 \(0\)。

如果 \(s\nmid i\)，那么 \(i\) 和 \(i+P\) 模 \(s^e\) 的余数相同，而且都不被 \(s\) 整除。它们的底数因此相同，指数相差 \(P\)。由于 \(q\) 是互质的素数幂的乘积，\(\varphi(q)\) 也是这些素数幂的欧拉函数之积；所以 \(\varphi(s^e)\mid\varphi(q)\)，进而 \(\varphi(s^e)\mid P\)。根据欧拉定理，单位底数的指数增加 \(P\) 后，模 \(s^e\) 的幂不变。

这样，每个素数幂 \(s^e\) 下的余数都相同。它们两两互质，因此 \(i^i\) 和 \((i+P)^{i+P}\) 模它们的乘积 \(q\) 也相同。这就说明了周期。

周期长度不到一百万，可以直接存下一个周期。固定 \(i\) 除以 \(q\) 的余数 \(x\)。周期中对应的下标依次是 \(q+x,\ q+x+q,\ q+x+2q,\ldots\)。这些数模 \(q\) 都是 \(x\)，指数每次增加 \(q\)，所以幂的余数按下面的式子递推：

\[
(q+x+tq)^{q+x+tq}\equiv x^{q+x}(x^q)^t\pmod q.
\]

让 \(x\) 从 \(0\) 到 \(q-1\)，依次填入下标 \(x,x+q,x+2q,\ldots\)，就能覆盖整个周期。每个 \(x\) 只需算出第一项和递推时要乘的数；余数为 \(0\) 的位置按前面的规则记作 \(q\)。

### 怎么找和为 \(p\) 的区间

周期前还有 \(1\) 到 \(q-1\) 这些项。区间起点可能在这段，也可能已经进入周期，分三种情况处理。

#### 区间完全在前 \(q-1\) 项里

这一段最多只有 \(q-1\le998\) 项。枚举左右端点并累加；和等于 \(p\) 时输出。若和已经超过 \(p\)，就停止向右扩展，因为每项都是正数，继续加只会更大。

#### 区间从周期里开始

记一个周期的和为 \(C\)。无论区间从周期的哪个位置开始，都可以先拆出若干个完整周期，再看不足一个周期的连续部分。完整周期每个和都是 \(C\)，所以把 \(p\) 除以 \(C\)，得到 \(p=cC+t\)，其中 \(0\le t<C\)。余下部分的和必须是 \(t\)。

若 \(t=0\)，直接取 \(c\) 个完整周期即可。否则，用双指针在周期数组上查找和为 \(t\) 的连续段；段可以从数组末尾绕回开头。因为任何连续 \(P\) 项的和都是 \(C\)，而 \(t<C\)，这段长度一定小于一个周期。找到起点和长度后，就从该位置先走 \(c\) 个周期，再接上这段。

#### 区间从前面开始，并延伸到周期里

若起点是 \(l<q\)，区间进入周期前必须先包含 \(l\) 到 \(q-1\) 这些项。先算这段固定前缀的和；如果它已经超过 \(p\)，这个起点就不可能。

否则，从 \(p\) 中减去前缀和。后面的周期部分从周期下标 \(0\) 开始。把剩余和除以 \(C\)，先取若干个完整周期，再用周期前缀和数组查找余下的部分。由于周期中的项都是正数，前缀和严格递增，二分查找可以确定是否存在这样的周期前缀。

以上三种情况覆盖了所有区间起点。都找不到时，输出 -1 -1。

每个 \(f(i^i)\) 至少为 \(1\)，所以和为 \(p\) 的区间最多有 \(p\) 项。题目给出 \(p\le10^8\)，故区间长度不超过 \(p\)，而 \(r-l\) 比项数还少 \(1\)，满足题面范围。构造出的周期起点不超过 \(q+P-1\)，约一百万；终点再加上至多 \(p-1\)，也远小于 \(10^{18}\)。

## 复杂度

设 \(P=q\varphi(q)\)。每组数据的时间复杂度为 \(O(P+q^2)\)，空间复杂度为 \(O(P)\)。题目给出 \(k\le10^3\)，所以 \(q\le999\)，且 \(P\le999\cdot998=997002\)。周期数组 b 和前缀和数组 ps 按 \(N=1e6+5\) 开辟；数位和结果数组 a 按 \(K=1e3+5\) 开辟；sf[l] 保存前 q-1 项中从位置 l 到 q-1 的和，也就是这段序列的后缀和。

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
