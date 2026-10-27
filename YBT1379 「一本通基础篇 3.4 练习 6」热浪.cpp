#include <bits/stdc++.h>
using namespace std;

const int N = 3e3 + 5, INF = 1e9;
int t, c, a, b, v;
int d[N];
vector<pair<int, int>> e[N];
bool vis[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t >> c >> a >> b;
    for (int i = 1; i <= c; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        e[x].push_back({y, z}), e[y].push_back({x, z});
    }
    for (int i = 1; i <= t; ++i) {
        d[i] = INF, vis[i] = false;
    }
    d[a] = 0;
    for (int i = 1; i <= t; ++i) {
        v = 0;
        for (int j = 1; j <= t; ++j) {
            if (!vis[j] && (!v || d[j] < d[v])) {
                v = j;
            }
        }
        if (!v || d[v] >= INF) {
            break;
        }
        vis[v] = true;
        for (int j = 0; j < (int)e[v].size(); ++j) {
            d[e[v][j].first] = min(d[e[v][j].first], d[v] + e[v][j].second);
        }
    }
    cout << d[b] << "\n";
    return 0;
}
