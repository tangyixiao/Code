#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
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
        stack<pair<int, int>> st;
        for (auto [v, w] : g[i]) {
            st.push({v, w});
        }
        for (; !st.empty(); st.pop()) {
            cout << st.top().first << " " << st.top().second << "\n";
        }
    }
    return 0;
}