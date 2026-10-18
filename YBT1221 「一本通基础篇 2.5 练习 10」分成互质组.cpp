#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;

int a[N], n, g[N][N], u[N][N], best;

inline void input() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            g[i][j] = __gcd(a[i], a[j]);
        }
    }
}

inline void dfs(int i, int k) {
    if (k >= best) {
        return;
    }
    if (i > n) {
        best = k;
        return;
    }
    for (int j = 1; j <= k; ++j) {
        int ok = 1;
        for (int p = 1; p < i; ++p) {
            if (u[j][p] && g[p][i] > 1) {
                ok = 0;
                break;
            }
        }
        if (!ok) {
            continue;
        }
        u[j][i] = 1;
        dfs(i + 1, k);
        u[j][i] = 0;
    }
    u[k + 1][i] = 1;
    dfs(i + 1, k + 1);
    u[k + 1][i] = 0;
}

inline void solve() {
    best = n;
    u[1][1] = 1;
    dfs(2, 1);
    cout << best << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    solve();
    return 0;
}
