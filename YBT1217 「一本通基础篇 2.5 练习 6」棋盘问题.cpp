#include <bits/stdc++.h>
using namespace std;

const int N = 1e1 + 5;

int n, k, c, u[N];
char g[N][N];

inline void dfs(int r, int p) {
    if (r > n) {
        c += p == k;
        return;
    }
    if (p + n - r + 1 < k) {
        return;
    }
    for (int i = 1; i <= n; ++i) {
        if (g[r][i] != '#' || u[i]) {
            continue;
        }
        u[i] = 1;
        dfs(r + 1, p + 1);
        u[i] = 0;
    }
    dfs(r + 1, p);
}

inline void solve() {
    for (int i = 1; i <= n; ++i) {
        cin >> g[i] + 1;
    }
    memset(u, 0, sizeof(u));
    c = 0;
    dfs(1, 0);
    cout << c << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> n >> k && (n != -1 || k != -1)) {
        solve();
    }
    return 0;
}
