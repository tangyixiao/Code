# P2869 [USACO07DEC] Gourmet Grazers G 题解

## 思路分析

每头牛要买一份草。草的价格和口感都要达标，而且一份草只能给一头牛。先处理口感要求最高的牛。

把牛按口感要求从高到低排好，草也按口感从高到低排好。处理一头牛时，把所有口感够的草放进候选池。后面的牛口感要求更低，所以池里的草也都能满足它们的口感要求。

比如当前这头牛要求口感至少 $8$、价格至少 $5$。候选池里有三份草：$(4,10)$、$(7,9)$、$(9,8)$，括号里依次是价格和口感。第一份草口感够，但价格不够；另外两份都能用，所以选价格为 $7$ 的草。

为什么能选价格最低的合格草？把贪心选中的草叫 $h$。先看最优方案：如果当前牛原本拿到的是另一份草 $g$，那么 $g$ 也在候选池里，并且价格不低于当前要求。因此贪心选出的 $h$ 价格不高于 $g$。

如果最优方案把 $h$ 留着没用，就让当前牛改用 $h$，花费不会增加。如果 $h$ 原本分给了后面的一头牛，就交换两份草：当前牛拿 $h$，后面那头牛拿 $g$。$g$ 的口感不低于当前牛的要求，也就不低于后面那头牛的要求。价格方面，后面那头牛原本能用 $h$，而 $g$ 的价格不低于 $h$，所以 $g$ 的价格要求也一定达标。交换后两头牛都能吃到合格的草，总花费也不变。

用 `multiset` 按价格保存候选池。对当前牛从它的价格下限开始找第一份草，也就是池中最便宜的合格草。如果找不到，当前牛没有可用的草，输出 $-1$。

## 复杂度

排序和集合操作的总复杂度为 $O((n+m)\log(n+m))$，空间复杂度为 $O(n+m)$。

## 代码

```cpp
namespace TANGYIXIAO {
const int N = 1e5 + 5;
int n, m, j;
ll ans;
multiset<ll> s;
struct C {
    ll x, y;
} a[N];
struct G {
    ll x, y;
} b[N];
inline bool cc(const C &x, const C &y) { return x.y > y.y; }
inline bool cg(const G &x, const G &y) { return x.y > y.y; }
inline void solve(int Task_Id) {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].x >> a[i].y;
    }
    for (int i = 1; i <= m; i++) {
        cin >> b[i].x >> b[i].y;
    }
    sort(a + 1, a + n + 1, cc);
    sort(b + 1, b + m + 1, cg);
    s.clear(), ans = 0, j = 1;
    for (int i = 1; i <= n; i++) {
        for (; j <= m && b[j].y >= a[i].y; j++) {
            s.insert(b[j].x);
        }
        auto it = s.lower_bound(a[i].x);
        if (it == s.end()) {
            cout << -1 << "\n";
            return;
        }
        ans += *it;
        s.erase(it);
    }
    cout << ans << "\n";
    return;
}
} // namespace TANGYIXIAO
```
