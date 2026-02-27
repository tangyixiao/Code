# 题意简析

树有 $n$ 个点，选择点使得每个点到被选择的点距离不超过 $K$，要求选择点的个数最小。

# 思路解析

虽然说求一张图的最小边支配集是 NP-hard 问题，但是本题所求的是树上最小 $K$ 支配集，所以还是可做的。

## 贪心

贪心的思路是直观的，先假设有一个根，然后从叶子节点向上处理，维护每个节点的状态，当发现某个点离最近的仓库覆盖不到的点距离等于 $K$ 时，就在这里放置仓库。

## 树形 DP

如果是设 $dp_{u,d}$ 为以 $u$ 为根的子树被仓库完全覆盖，根和最近的仓库的距离为 $d$ 时，所需的最小数量。但是这样子做显然是冗余的，时空复杂度可以达到 $O(nK)$，根本无法通过此题。

所以，实际上我们可以设 $f_u$ 和 $g_u$ 分别为未被覆盖的最远点的距离以及代表最近的仓库的距离，这样常数虽然增加但是次数减一，可以通过此题。

考虑设计状态：$f_u=-1$ 为全部覆盖，$g_u = 0$ 为 $u$ 处即为仓库。

设根 $u$ 的子节点为 $son$，则有状态转移如下：


$$
g_u = \min (g_{son_1} + 1,g_{son_2} + 1,\cdots,g_{son_{siz}} + 1)
$$


$$
f_u = \max (f_{son_1} + 1,f_{son_2} + 1,\cdots,f_{son_{siz}} + 1)
$$


- 若 $ g_u +f_u \le K$，那么 $f_u = -1$，即为覆盖所有未覆盖节点。
- 若 $ f_u = K$，同上一条，额外使得 $ g_u =0$。

### 正确性

#### 无后效性

树的结构是递归的，子问题独立。

#### 最优子结构

每个子树的最优解组合起来就是整棵树的最优解。


# 代码实现

最高用时 48ms，快得飞起。

```cpp
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, inf = 0x3f3f3f3f;
vector<int> tree[N];
vector<int> g[N];
int dp[N][2], n, k, ans;
inline void build(int u, int fa) {
    for (auto v : g[u]) {
        if (v != fa) {
            tree[u].push_back(v);
            build(v, u);
        }
    }
    return;
}
inline void dfs(int u) {
    dp[u][0] = inf;
    dp[u][1] = 0;
    for (auto v : tree[u]) {
        dfs(v);
        dp[u][0] = min(dp[v][0] + 1, dp[u][0]);
        if (dp[v][1] >= 0) {
            dp[u][1] = max(dp[v][1] + 1, dp[u][1]);
        }
    }

    if (dp[u][1] == k) {
        ans++;
        dp[u][0] = 0;
        dp[u][1] = -1;
        return;
    }
    if (dp[u][0] < inf && dp[u][1] >= 0 && dp[u][0] + dp[u][1] <= k) {
        dp[u][1] = -1;
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    build(1, -1);
    if (k == 0) {
        cout << n;
        exit(0);
    }
    dfs(1);
    ans += (dp[1][1] >= 0);
    cout << ans;
    return 0;
}
```