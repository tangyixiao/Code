#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
struct query {
    int u, d;
};
int n, q, u[N], d[N], ans[N], dep[N], cnt[N];
vector<int> g[N];
vector<query> qu[N];
inline void dfs(int u) {
    for (auto [d, id] : qu[u]) {
        if (d <= n) {
            ans[id] = cnt[d];
        }
    }
    cnt[dep[u]]++;
    for (int v : g[u]) {
        dep[v] = dep[u] + 1;
        dfs(v);
    }
    for (auto [d, id] : qu[u]) {
        if (d <= n) {
            ans[id] = cnt[d] - ans[id];
        }
    }
    return;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 2, fa; i <= n; i++) {
        cin >> fa;
        g[fa].push_back(i);
    }
    cin >> q;
    for (int i = 1; i <= q; i++) {
        cin >> u[i] >> d[i];
        qu[u[i]].push_back({d[i], i});
    }
    dfs(1);
    for (int i = 1; i <= q; i++) {
        cout << ans[i] << '\n';
    }
    return 0;
}