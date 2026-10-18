#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, p, c, m;
vector<int> e[N];
int d[N];

inline void input() { cin >> n >> p >> c; }

inline void solve() {
    cin >> m;
    for (int i = 1; i <= p; ++i) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v), e[v].push_back(u);
    }
    d[c] = 1;
    int mx = 1;
    for (int i = 1; i <= n; ++i) {
        if (!d[i]) {
            continue;
        }
        mx = max(mx, d[i]);
        for (int j = 0; j < e[i].size(); ++j) {
            if (!d[e[i][j]]) {
                d[e[i][j]] = d[i] + 1;
            }
        }
    }
    cout << mx + m << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}