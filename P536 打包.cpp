#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int v, g, n, t[N], x[N], y[N], f[N][N];

inline void input() {
    cin >> v >> g;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> t[i] >> x[i] >> y[i];
    }
}

inline void solve() {
    for (int k = 1; k <= n; k++) {
        for (int i = v; i >= x[k]; i--) {
            for (int j = g; j >= y[k]; j--) {
                if (f[i - x[k]][j - y[k]] + t[k] > f[i][j]) {
                    f[i][j] = f[i - x[k]][j - y[k]] + t[k];
                }
            }
        }
    }
    cout << f[v][g] << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
