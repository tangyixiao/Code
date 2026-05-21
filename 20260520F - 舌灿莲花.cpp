#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1005;
int n, m, d[MAXN][MAXN], ans;
vector<pair<int, char>> g[MAXN], rg[MAXN];
queue<pair<int, int>> q;
int main() {
    freopen("f.in", "r", stdin);
    freopen("f.out", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        char c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
        rg[b].push_back({a, c});
    }
    memset(d, -1, sizeof(d));
    d[1][n] = 0;
    q.push({1, n});
    ans = 1e9;
    while (!q.empty()) {
        auto [u, v] = q.front();
        q.pop();
        int cur = d[u][v];
        if (u == v)
            ans = min(ans, cur * 2);
        for (auto &e1 : g[u]) {
            int nu = e1.first;
            char c1 = e1.second;
            if (nu == v)
                ans = min(ans, cur * 2 + 1);
            for (auto &e2 : rg[v]) {
                int nv = e2.first;
                char c2 = e2.second;
                if (c1 == c2 && d[nu][nv] == -1) {
                    d[nu][nv] = cur + 1;
                    q.push({nu, nv});
                }
            }
        }
    }
    if (ans == 1e9)
        cout << -1 << endl;
    else
        cout << ans << endl;
    return 0;
}