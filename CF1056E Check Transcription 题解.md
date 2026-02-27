# 题意简析

给你一个 $01$ 串 $s$，字母串 $t$，用两个不同且非空的字符串 $r_0$ 和 $r_1$ 分别替换 $s$ 中的所有 $0$ 和 $1$，使 $t$，求满足条件的 $(r_0, r_1)$ 的数量。

# 思路解析

因为 $0$ 和 $1$ 的数量和总的目标串长度是固定的，所以考虑枚举 $0$ 和 $1$ 中较多的长度，然后再检查是否满足条件。

为什么这里要枚举较多的？

因为发现这一个过程很可能是 $O(nm)$ 的，所以需要优化。

可以类比为一个线性方程组，这里为方便讨论设 $a > b > 0$，$m,n >  0$：



$$
ax + b(n-x) = m
$$

就有

$$
ax + bn = bx + m
$$

根据我们初中数学知识知道，直线的斜率的绝对值越大，直线越倾斜，那么其与坐标轴的两个交点的横坐标的差值也会越小，即 $\frac{c}{b} < \frac{c}{a}$，枚举的 $x$ 也就越少。

上界不会超过 $\frac{m}{n}$，这样的复杂度就大大降低了。

---


但我们怎么快速查询 $t$ 的子串是否合法呢？我们想到了用哈希。

哈希是可以 $O(1)$ 查询子串是否相同的，因为题目中说要用不同且非空的字符串。但是这题用自然溢出哈希显然会被卡（毕竟看看是哪个 OJ 出的比赛），所以我们要用双哈希或者随机化。

---


如果每次快速幂求底数的幂次，那么查询一多就显得很浪费而且带个 $\log$；但如果递推求底数的幂次就不会有这个问题。

别忘了特判 $r_0 = r_1$ 的情况。

时空复杂度为 $O(m)$。

# 代码实现

```cpp
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int M = 1e6 + 5, Base1 = 131, Base2 = 137, Mod1 = 1e9 + 9, Mod2 = 1e9 + 7;
int n, m, pow1[M], pow2[M], h1[M], h2[M], lx, ly, ans, cnt0, cnt1;
char x = '0', y = '1';
string s, t;
namespace Mathematics {
inline int qpow(int a, int b, int MOD) {
    int res = 1;
    while (b) {
        if (b & 1) {
            res = res * a % MOD;
        }
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}
} // namespace Mathematics
inline void Init() {
    pow1[0] = pow2[0] = 1;
    for (int i = 1; i <= m; i++) {
        pow1[i] = pow1[i - 1] * Base1 % Mod1;
        pow2[i] = pow2[i - 1] * Base2 % Mod2;
    }
    h1[0] = h2[0] = 0;
    for (int i = 1; i <= m; i++) {
        h1[i] = (h1[i - 1] * Base1 + t[i - 1]) % Mod1;
        h2[i] = (h2[i - 1] * Base2 + t[i - 1]) % Mod2;
    }
    return;
}
inline pair<int, int> get_hash(int l, int r) {
    int hash1 = (h1[r] - h1[l] * pow1[r - l] % Mod1 + Mod1) % Mod1;
    int hash2 = (h2[r] - h2[l] * pow2[r - l] % Mod2 + Mod2) % Mod2;
    return {hash1, hash2};
}
inline bool check() {
    int now = 0, px = -1, py = -1;
    pair<int, int> hashx, hashy;
    for (int i = 0, l, r; i < n; i++) {
        if (s[i] == x) {
            l = now, r = now + lx;
            pair<int, int> h = get_hash(l, r);
            if (px == -1) {
                hashx = h;
                px = l;
            } else if (h != hashx) {
                return false;
            }
            now = r;
        } else {
            l = now, r = now + ly;
            pair<int, int> h = get_hash(l, r);
            if (py == -1) {
                hashy = h;
                py = l;
            } else if (h != hashy) {
                return false;
            }
            now = r;
        }
    }
    if (hashx == hashy) {
        if (lx == ly) {
            if (t.substr(px, lx) == t.substr(py, ly)) {
                return false;
            }
        }
    }
    return true;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> s >> t;
    n = s.size(), m = t.size();
    Init();
    cnt0 = count(s.begin(), s.end(), '0'), cnt1 = n - cnt0;
    if (cnt0 < cnt1) {
        swap(x, y);
        swap(cnt0, cnt1);
    }
    for (lx = 1; lx <= m; lx++) {
        int totx = cnt0 * lx;
        if (totx >= m) {
            break;
        }
        int rem = m - totx;
        if (!(rem % cnt1)) {
            ly = rem / cnt1;
            if (ly > 0) {
                ans += check();
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
```

# 后记

还记得滴叉在去年暑假的某节字符串课讲过，出题人卡不卡自然溢出哈希纯看良心。但如果你用双哈希再加上 `std::mt19937` 在 $10^9$ 级别的随机选取大质数，那么发生哈希冲突的概率比你被飞机创的概率还低。

当然，[Codeforces](https://codeforces.com/) 的出题人和其他选手肯定会卡你的自然溢出哈希，所以建议大家还是多用用双哈希（~~毕竟 [Hash Killer III](https://www.luogu.com.cn/problem/P12199)  还没有人做出来过~~）。