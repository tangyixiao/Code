#include <bits/stdc++.h>
#define int long long
using namespace std;
struct node {
    int v, w;
};
const int mod = 1e9 + 7, B = 60, N = 2e5 + 5;
int n, sum[N], pw2[B], ans;
vector<node> g[N];
inline void init() {
    for (int i = 2; i <= n; i++) {
        sum[i] = -1;
    }
    pw2[0] = 1;
    for (int k = 1; k < B; k++) {
        pw2[k] = (pw2[k - 1] * 2) % mod;
    }
    return;
}
inline void bfs() {
    queue<int> q;
    q.push(1);
    for (; !q.empty();) {
        int u = q.front();
        q.pop();
        for (auto [v, w] : g[u]) {
            if (sum[v] == -1) {
                sum[v] = sum[u] ^ w;
                q.push(v);
            }
        }
    }

    return;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1, u, v, w; i < n; i++) {
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    init();
    bfs();
    for (int k = 0, c = 0, d = 0; k < B; k++, c = 0, d = 0) {
        for (int i = 1; i <= n; i++) {
            if (sum[i] >> k & 1) {
                d++;
            } else {
                c++;
            }
        }
        ans = (ans + (c * d % mod) * pw2[k]) % mod;
    }

    cout << ans << '\n';
    return 0;
}