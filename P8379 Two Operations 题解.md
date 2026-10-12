# P8379 Two Operations 题解

## 思路分析

先考虑一次 `Query` 中，最后哪一组作为合并目标。假设最后保留的是组 $i$，这组当前人数为 $s$，糖果总数为 $c_i$，组内最多糖果数为 $m_i$。所有组的糖果总数记为 $C$，学生总数为 $n$。

可以先把其余所有组互相合并，最后再把它们整体合并进组 $i$。最后这一步中，其余学生都会被清零，再各自得到：

$$
\frac{C-c_i}{n}
$$

颗糖。原来在组 $i$ 的学生则都增加同样的数，因此最后最多糖果数是：

$$
m_i+\frac{C-c_i}{n}
=\frac{C+(n m_i-c_i)}{n}.
$$

这个值也是以组 $i$ 为最终目标时的下界。因为在任何合并顺序中，组 $i$ 原有的学生都不会作为合并源被清零；其余组的糖果总量最终都要并入这条目标组链。每次并入时，分摊的分母至多为 $n$，所以这些学生累计增加的糖果数至少为 $(C-c_i)/n$。把其余组先合成一组再整体并入，正好达到这个下界。

因此答案只需在所有当前组中取：

$$
\min_i\left(m_i+\frac{C-c_i}{n}\right)
=\frac{C+\min_i(nm_i-c_i)}{n}.
$$

总糖果数 $C$ 和总人数 $n$ 在操作中不变。每组维护糖果总数 $c_i$、组内最大值 $m_i$，并用有序集合维护键值 $nm_i-c_i$。`Change X Y` 时合并两组的总数与最大值，再更新集合；`Query` 时取集合最小键即可。最后乘以 $n$ 在模 $10^9+7$ 下的逆元。

## 复杂度

初始化为 $O(n+k)$，每次 `Change` 为 $O(\log k)$，每次 `Query` 为 $O(1)$；空间复杂度为 $O(n+k)$。

## 代码

```cpp
namespace TANGYIXIAO {
constexpr long long MOD = 1e9 + 7;
inline long long qpow(long long a, long long b) {
    long long r = 1;
    for (; b; b >>= 1, a = a * a % MOD) {
        if (b & 1) {
            r = r * a % MOD;
        }
    }
    return r;
}
inline void solve(int Task_Id) {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> g(n + 1);
    vector<long long> s(k + 1), mx(k + 1);
    for (int i = 1; i <= n; i++) {
        cin >> g[i];
    }
    long long tot = 0;
    for (int i = 1; i <= n; i++) {
        long long x;
        cin >> x;
        s[g[i]] += x, mx[g[i]] = max(mx[g[i]], x), tot += x;
    }
    set<pair<long long, int>> st;
    auto get = [&](int x) { return 1LL * n * mx[x] - s[x]; };
    for (int i = 1; i <= k; i++) {
        st.emplace(get(i), i);
    }
    long long iv = qpow(n, MOD - 2);
    for (int i = 1; i <= m; i++) {
        string op;
        cin >> op;
        if (op == "Query") {
            cout << (tot + st.begin()->first) % MOD * iv % MOD << '\n';
        } else {
            int x, y;
            cin >> x >> y;
            if (x == y) {
                continue;
            }
            st.erase({get(x), x}), st.erase({get(y), y});
            s[y] += s[x], mx[y] = max(mx[y], mx[x]);
            s[x] = mx[x] = 0;
            st.emplace(get(y), y);
        }
    }
    return;
}
} // namespace TANGYIXIAO
```
