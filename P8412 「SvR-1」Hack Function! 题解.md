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

把区间起点分成两类。

- 若 $l\ge q$，区间完全位于周期段。记一个周期和为 $C$，将目标和写成 $p=cC+r$，其中 $0\le r<C$。先取 $c$ 个完整周期，再在周期数组中寻找和为 $r$ 的循环连续段；若 $r=0$，直接输出 $c$ 个周期。循环段用双指针在线性时间内枚举所有起点。
- 若 $l<q$，且区间延伸到周期段，它会先包含固定的前缀 $l\sim q-1$，随后接上从周期下标 $0$ 开始的一段数列。减去前缀和后，同样按 $C$ 分解；周期部分剩余的和必须是周期数组的一个前缀和，用前缀和数组二分查找。

完全落在 $[1,q-1]$ 的区间只有 $O(q^2)$ 个，直接枚举。以上三类覆盖所有可能的区间；若都找不到，就输出 $-1 -1$。

题目要求的区间长度不超过 $p$，而 $p\le10^8$；构造出的端点也远小于 $10^{18}$，满足输出范围。

## 复杂度

设 $P=q\varphi(q)$。每组数据的时间复杂度为 $O(P+q^2)$，空间复杂度为 $O(P)$。

## 代码

代码只列出提交模板末尾的 `namespace TANGYIXIAO` 部分。

```cpp
namespace TANGYIXIAO {
inline long long mod_pow(long long a, int e, int mod) {
    long long r = 1 % mod;
    for (; e; e >>= 1, a = a * a % mod) {
        if (e & 1) {
            r = r * a % mod;
        }
    }
    return r;
}

inline int euler_phi(int x) {
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

inline bool find_cycle_segment(const vector<int> &v, long long target, int &start, int &len) {
    if (target <= 0) {
        return false;
    }
    int n = (int)v.size(), right = 0;
    long long sum = 0;
    for (int left = 0; left < n; left++) {
        for (; right < left + n && sum < target; right++) {
            sum += v[right % n];
        }
        if (sum == target) {
            start = left, len = right - left;
            return true;
        }
        if (right > left) {
            sum -= v[left];
        }
    }
    return false;
}

inline void print_answer(long long l, long long r) {
    cout << l << ' ' << r << '\n';
    return;
}

inline void solve(int Task_Id) {
    int k;
    long long p;
    cin >> k >> p;
    int q = k - 1, phi = euler_phi(q), period_len = q * phi;
    vector<int> pre(q), cyc(period_len);
    for (int i = 1; i < q; i++) {
        int x = (int)mod_pow(i, i, q);
        pre[i] = x ? x : q;
    }
    for (int x = 0; x < q; x++) {
        if (x == 0) {
            for (int t = 0; t < phi; t++) {
                cyc[t * q] = q;
            }
            continue;
        }
        long long value = mod_pow(x, q + x, q);
        long long ratio = mod_pow(x, q, q);
        for (int t = 0; t < phi; t++) {
            int at = x + t * q;
            cyc[at] = value ? (int)value : q;
            value = value * ratio % q;
        }
    }
    long long cycle_sum = 0;
    for (int x : cyc) {
        cycle_sum += x;
    }

    for (int l = 1; l < q; l++) {
        long long sum = 0;
        for (int r = l; r < q; r++) {
            sum += pre[r];
            if (sum == p) {
                print_answer(l, r);
                return;
            }
            if (sum > p) {
                break;
            }
        }
    }

    long long full = p / cycle_sum, rem = p % cycle_sum;
    if (rem == 0 && full > 0) {
        print_answer(q, q + full * period_len - 1);
        return;
    }
    int start, len;
    if (find_cycle_segment(cyc, rem, start, len)) {
        long long l = q + start;
        print_answer(l, l + full * period_len + len - 1);
        return;
    }

    vector<long long> prefix(period_len + 1);
    for (int i = 0; i < period_len; i++) {
        prefix[i + 1] = prefix[i] + cyc[i];
    }
    vector<long long> suffix(q + 1);
    for (int i = q - 1; i >= 1; i--) {
        suffix[i] = suffix[i + 1] + pre[i];
    }
    for (int l = 1; l < q; l++) {
        if (p < suffix[l]) {
            continue;
        }
        long long target = p - suffix[l];
        long long cycles = target / cycle_sum, tail = target % cycle_sum;
        auto it = lower_bound(prefix.begin(), prefix.begin() + period_len, tail);
        if (it == prefix.begin() + period_len || *it != tail) {
            continue;
        }
        long long tail_len = it - prefix.begin();
        long long periodic_len = cycles * period_len + tail_len;
        if (periodic_len > 0) {
            print_answer(l, q - 1 + periodic_len);
            return;
        }
    }

    print_answer(-1, -1);
    return;
}
} // namespace TANGYIXIAO
```
