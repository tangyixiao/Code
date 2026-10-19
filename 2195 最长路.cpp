#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int P = -1e9;
int n, m;
int hd[N], ed[N], wt[N], nxt[N], f[N];

inline void input() {
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        nxt[i] = hd[u];
        hd[u] = i;
        ed[i] = v;
        wt[i] = w;
    }
}

inline void solve() {
    for (int i = 1; i <= n; ++i) {
        f[i] = P;
    }
    f[1] = 0;
    for (int u = 1; u <= n; ++u) {
        for (int i = hd[u]; i; i = nxt[i]) {
            f[ed[i]] = max(f[ed[i]], f[u] + wt[i]);
        }
    }
    cout << (f[n] == P ? -1 : f[n]) << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}