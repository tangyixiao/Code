#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 5;
int n, m;
vector<pair<int, int>> g[N];
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1, u, v, w; i <= m; i++) {
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }
    for (int i = 1; i <= n; i++) {
        cout << i << ":\n";
        sort(g[i].begin(), g[i].end());
        for (auto [v, w] : g[i]) {
            cout << v << " " << w << "\n";
        }
    }
    return 0;
}