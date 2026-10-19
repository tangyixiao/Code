#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5, M = 1e9 + 5;
int t, c, a, b, v;
int d[N];
vector<pair<int, int>> e[N];
bool vis[N];

inline void input() { cin >> t >> c >> a >> b; }

inline void solve() {
    for (int i = 1; i <= c; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        e[x].push_back({y, z}), e[y].push_back({x, z});
    }
    for (int i = 1; i <= t; ++i) {
        d[i] = M;
    }
    d[a] = 0;
    for (int i = 1; i <= t; ++i) {
        v = 0;
        for (int j = 1; j <= t; ++j) {
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
    cout << (d[b] >= M ? -1 : d[b]) << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}