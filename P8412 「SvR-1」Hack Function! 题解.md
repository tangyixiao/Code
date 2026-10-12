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

## 代码

代码只列出模板末尾的 `namespace TANGYIXIAO` 部分。

```cpp
namespace TANGYIXIAO {
inline long long pw(long long a, int e, int mod) {
    long long r = 1 % mod;
    for (; e; e >>= 1) {
        if (e & 1) {
            r = r * a % mod;
        }
        a = a * a % mod;
    }
    return r;
}

inline int getphi(int x) {
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

inline bool findseg(const vector<int> &a, long long need, int &st, int &len) {
    if (need <= 0) {
        return false;
    }
    int n = (int)a.size(), r = 0;
    long long sum = 0;
    for (int l = 0; l < n; l++) {
        for (; r < l + n && sum < need; r++) {
            sum += a[r % n];
        }
        if (sum == need) {
            st = l, len = r - l;
            return true;
        }
        if (r > l) {
            sum -= a[l];
        }
    }
    return false;
}

inline void out(long long l, long long r) {
    cout << l << ' ' << r << '\n';
    return;
}

inline void solve(int Task_Id) {
    int k;
    long long p;
    cin >> k >> p;
    int q = k - 1, ph = getphi(q), m = q * ph;
    vector<int> pre(q), cyc(m);
    for (int i = 1; i < q; i++) {
        int x = (int)pw(i, i, q);
        pre[i] = x ? x : q;
    }
    for (int x = 0; x < q; x++) {
        if (x == 0) {
            for (int t = 0; t < ph; t++) {
                cyc[t * q] = q;
            }
            continue;
        }
        long long value = pw(x, q + x, q), ratio = pw(x, q, q);
        for (int t = 0; t < ph; t++) {
            int at = x + t * q;
            cyc[at] = value ? (int)value : q;
            value = value * ratio % q;
        }
    }
    long long sumc = 0;
    for (int x : cyc) {
        sumc += x;
    }

    for (int l = 1; l < q; l++) {
        long long sum = 0;
        for (int r = l; r < q; r++) {
            sum += pre[r];
            if (sum == p) {
                out(l, r);
                return;
            }
            if (sum > p) {
                break;
            }
        }
    }

    long long cnt = p / sumc, rem = p % sumc;
    if (rem == 0 && cnt > 0) {
        out(q, q + cnt * m - 1);
        return;
    }
    int st, len;
    if (findseg(cyc, rem, st, len)) {
        long long l = q + st;
        out(l, l + cnt * m + len - 1);
        return;
    }

    vector<long long> ps(m + 1);
    for (int i = 0; i < m; i++) {
        ps[i + 1] = ps[i] + cyc[i];
    }
    vector<long long> sf(q + 1);
    for (int i = q - 1; i >= 1; i--) {
        sf[i] = sf[i + 1] + pre[i];
    }
    for (int l = 1; l < q; l++) {
        if (p < sf[l]) {
            continue;
        }
        long long need = p - sf[l], cycles = need / sumc, tail = need % sumc;
        auto it = lower_bound(ps.begin(), ps.begin() + m, tail);
        if (it == ps.begin() + m || *it != tail) {
            continue;
        }
        long long tot = cycles * m + (it - ps.begin());
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
