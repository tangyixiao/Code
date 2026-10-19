#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5, M = 1e9 + 5;
int n, m, v;
int d[N];
vector<pair<int, int>> e[N];
bool vis[N];

inline void input() { cin >> n >> m; }

inline void solve() {
    for (int i = 1; i <= m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        e[a].push_back({b, c}), e[b].push_back({a, c});
    }
    for (int i = 1; i <= n; ++i) {
        d[i] = M;
    }
    d[1] = 0;
    for (int i = 1; i <= n; ++i) {
        v = 0;
        for (int j = 1; j <= n; ++j) {
            if (!vis[j] && (!v || d[j] < d[v])) {
                v = j;
            }
        }
        if (!v || d[v] >= M) {
            break;
        }
        vis[v] = true;
        for (int j = 0; j < e[v].size(); ++j) {
            d[e[v][j].first] = min(d[e[v][j].first], d[v] + e[v][j].second);
        }
    }
    cout << (d[n] >= M ? -1 : d[n]) << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}