# 思路解析

本题解包含其他题解没想到的思路，建议阅读。

## 动态规划

考虑动态规划。

设 $dp_i$ 表示 $i$ 的最少元素个数，已经出现的数显然是 $1$。对于每个 $i$ 和 $x$，若 $i \cdot x \le n$，则 $dp_{i \cdot x} = \min(dp_{i \cdot x}, dp_i + 1)$。这里时间复杂度最坏是 $O(n^2)$ 的。

对于每个 $i$，若 $x$ 是 $i$ 的因子，那么 $\frac{x}{i}$ 一定也是 $i$ 的因子。


也就是说，对于每个 $i$，我们只需要枚举它的因子即可，这个东西是调和级数级别的，时间复杂度即为 $O(n \log n)$。

时间复杂度 $O(n \log n)$。

## 图论

考虑建图。

建图的方式非常简单，考虑转化为这样一个问题：若 $u$ 是 $v$ 的真因子，那么 $u$ 和 $v$ 之间有边。每条边的边权都是 $1$。

然后就是直接广搜（BFS）求最短路即可（~~比赛的时候写了个 Dijsktra~~）。

时间复杂度 $O(n \log n)$。


# 代码实现

## 动态规划
```cpp

#include <bits/stdc++.h>
// #define DEBUG
using namespace std;
const int N = 3e5 + 5, inf = 0x3f3f3f3f;
vector<int> fac[N];
int T, n, a[N], dp[N];
bool vis[N];
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int d = 2; d <= N - 5; d++) {
        for (int i = d << 1; i <= N - 5; i += d) {
            fac[i].push_back(d);
        }
    }
#ifdef DEBUG
    cerr << "\nHere\n";
#endif
    cin >> T;
    while (T--) {

#ifdef DEBUG
        cerr << "\nHere\n";
#endif
        cin >> n;
        for (int i = 0; i <= n; i++) {
            dp[i] = inf;
            vis[i] = false;
        }
#ifdef DEBUG
        cerr << "\nHere\n";
#endif
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (a[i] <= n) {
                dp[a[i]] = 1;
                vis[a[i]] = true;
            }
        }
#ifdef DEBUG
        cerr << "\nHere\n";
#endif
        for (int i = 1; i <= n; i++) {
            for (int d : fac[i]) {
                int j = i / d;
                if (vis[d] && dp[j] != inf) {
                    dp[i] = min(dp[i], dp[j] + 1);
                }
                if (vis[j] && dp[d] != inf) {
                    dp[i] = min(dp[i], dp[d] + 1);
                }
            }
        }
#ifdef DEBUG
        cerr << "\nHere\n";
#endif
        for (int i = 1; i <= n; i++) {
            cout << (dp[i] == inf ? -1 : dp[i]) << " \n"[i == n];
        }
#ifdef DEBUG
        cerr << "\nHere\n";
#endif
    }
    return 0;
}
```
## 图论

```cpp
#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5, inf = 0x3f3f3f3f;
int T, n, a[N], dist[N];
bool vis[N];
vector<int> nums;
namespace Graph {
inline void init();
inline void Dijkstra();
} // namespace Graph
using namespace Graph;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 0; i <= n; i++) {
            vis[i] = false;
        }
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (a[i] <= n) {
                vis[a[i]] = true;
            }
            dist[i] = inf;
        }
        init();
        Dijkstra();
        for (int i = 1; i <= n; i++) {
            if (dist[i] == inf) {
                cout << -1;
            } else {
                cout << dist[i];
            }
            cout << " \n"[i == n];
        }
    }
    return 0;
}
namespace Graph {
inline void init() {
    nums.clear();
    for (int i = 1; i <= n; i++) {
        if (vis[i]) {
            nums.push_back(i);
        }
    }
    return;
}
inline void Dijkstra() {
    queue<int> q;
    for (int x : nums) {
        dist[x] = 1;
        q.push(x);
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (u <= n / nums[0]) {
            for (int x : nums) {
                if (u > n / x) {
                    break;
                }
                int v = u * x;
                if (v <= n && dist[u] + 1 < dist[v]) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
    }
    return;
}
} // namespace Graph
```
