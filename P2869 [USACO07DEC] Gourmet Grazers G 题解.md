# P2869 [USACO07DEC] Gourmet Grazers G 题解

## 思路分析

每份牧草只能分给一头奶牛。奶牛同时提出价格下限和口感下限，因此直接按价格或口感排序都不能马上确定分配。先按口感从高到低处理奶牛：当处理当前奶牛时，所有口感已经达标的牧草都加入候选集合，之后的奶牛口感要求只会更低。

候选牧草中，价格低于当前奶牛要求的无法使用；在剩下的牧草里，选择价格最低的一份。

这样选择不会使答案变差。考虑一个最优方案中当前奶牛使用牧草 $g$，而贪心选择了另一份更便宜且口感达标的牧草 $h$。如果 $h$ 原本分给了后面某头奶牛，就把 $g$ 改分给那头奶牛：后面奶牛的口感要求不高于当前奶牛，故 $g$ 仍然达标，且总价格不变或更低。若 $h$ 没有被使用，直接用 $h$ 替换 $g$ 也不会增加花费。因此每一步都可以安全地取当前可用的最低价牧草。

用一个按价格维护的 `multiset` 保存候选牧草。若其中不存在价格不低于当前要求的牧草，则无法完成所有分配，输出 $-1$。

## 复杂度

排序和集合操作的总复杂度为 $O((n+m)\log(n+m))$，空间复杂度为 $O(n+m)$。

## 代码

```cpp
namespace TANGYIXIAO {
const int N = 1e5 + 5;
struct C {
    ll x, y;
} a[N];
struct G {
    ll x, y;
} b[N];
inline bool cc(const C &x, const C &y) { return x.y > y.y; }
inline bool cg(const G &x, const G &y) { return x.y > y.y; }
inline void solve(int Task_Id) {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].x >> a[i].y;
    }
    for (int i = 1; i <= m; i++) {
        cin >> b[i].x >> b[i].y;
    }
    sort(a + 1, a + n + 1, cc);
    sort(b + 1, b + m + 1, cg);
    multiset<ll> s;
    ll ans = 0;
    int j = 1;
    for (int i = 1; i <= n; i++) {
        for (; j <= m && b[j].y >= a[i].y; j++) {
            s.insert(b[j].x);
        }
        auto it = s.lower_bound(a[i].x);
        if (it == s.end()) {
            cout << -1 << '\n';
            return;
        }
        ans += *it;
        s.erase(it);
    }
    cout << ans << '\n';
    return;
}
} // namespace TANGYIXIAO
```
