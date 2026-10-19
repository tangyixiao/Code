#include <bits/stdc++.h>
using namespace std;

const int N = 5e2 + 5;

int m, n, x[N];
long long w[N][N], f[N][N];

inline void input() {
    cin >> m >> n;
    x[1] = 0;
    for (int i = 2; i <= m; ++i) {
        int d;
        cin >> d;
        x[i] = x[i - 1] + d;
    }
}

inline void solve() {
    for (int i = 1; i <= m; ++i) {
        for (int j = i; j <= m; ++j) {
            w[i][j] = -1;
            for (int k = i; k <= j; ++k) {
                long long s = 0;
                for (int p = i; p <= j; ++p) {
                    s += abs(x[p] - x[k]);
                }
                if (w[i][j] == -1 || s < w[i][j]) {
                    w[i][j] = s;
                }
            }
        }
    }
    for (int i = 1; i <= m; ++i) {
        f[i][0] = -1;
    }
    f[0][0] = 0;
    for (int j = 1; j <= n; ++j) {
        for (int i = 1; i <= m; ++i) {
            f[i][j] = -1;
            for (int t = 1; t <= i; ++t) {
                if (f[t - 1][j - 1] == -1) {
                    continue;
                }
                if (f[i][j] == -1 || f[t - 1][j - 1] + w[t][i] < f[i][j]) {
                    f[i][j] = f[t - 1][j - 1] + w[t][i];
                }
            }
        }
    }
    cout << f[m][n] << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    solve();
    return 0;
}
