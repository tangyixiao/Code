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