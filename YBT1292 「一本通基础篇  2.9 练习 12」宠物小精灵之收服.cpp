#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
const int M = 5e2 + 5;

int n, m, k;
int f[N][M], a[M], b[M];

inline void input() {
    cin >> n >> m >> k;
    for (int i = 1; i <= k; ++i) {
        cin >> a[i] >> b[i];
    }
}

inline void solve() {
    for (int i = 1; i <= k; ++i) {
        for (int j = n; j >= a[i]; --j) {
            for (int t = m - 1; t >= b[i]; --t) {
                f[j][t] = max(f[j][t], f[j - a[i]][t - b[i]] + 1);
            }
        }
    }
    int r = 0, s = 0;
    for (int j = 0; j <= n; ++j) {
        for (int t = 0; t < m; ++t) {
            if (f[j][t] > r || (f[j][t] == r && t < s)) {
                r = f[j][t], s = t;
            }
        }
    }
    cout << r << " " << m - s << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    solve();
    return 0;
}
