#include <bits/stdc++.h>
using namespace std;

const int N = 5e1 + 5;

int n, lc[N], rc[N], c[N], md, mw;

inline void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x >> lc[x] >> rc[x];
    }
}

inline void dfs(int u, int d) {
    md = max(md, d), mw = max(mw, ++c[d]);
    if (lc[u]) {
        dfs(lc[u], d + 1);
    }
    if (rc[u]) {
        dfs(rc[u], d + 1);
    }
}

inline void solve() {
    dfs(1, 1);
    cout << md << " " << mw << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
