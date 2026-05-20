#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5, inf = 2e9, M = 1e5 + 5;
int h, n, a[N], b[N], ans = inf, vis[M];
inline void dfs(int sa, int sb) {
    if (sa >= h) {
        ans = min(ans, sb);
        return;
    }
    if (sb > ans) {
        return;
    }
    if (sb >= vis[sa]) {
        return;
    }
    vis[sa] = min(sb, vis[sa]);
    for (int i = 1; i <= n; i++) {
        dfs(sa + a[i], sb + b[i]);
    }
    return;
}
signed main() {
    freopen("e.in", "r", stdin);
    freopen("e.out", "w", stdout);
    memset(vis, 0x3f, sizeof(vis));
    cin >> h >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
    }
    dfs(0, 0);
    cout << ans;
    return 0;
}
