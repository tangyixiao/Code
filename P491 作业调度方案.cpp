#include <bits/stdc++.h>
using namespace std;

const int N = 25;
const int M = 4e2 + 5;

int m, n, seq[M], mc[N][N], us[N][N], step[N], cnt[M], e[M][M], tot[N];

inline void input() {
    cin >> m >> n;
    for (int i = 1; i <= m * n; ++i) {
        cin >> seq[i];
    }
    for (int j = 1; j <= n; ++j) {
        for (int k = 1; k <= m; ++k) {
            cin >> mc[j][k];
        }
    }
    for (int j = 1; j <= n; ++j) {
        for (int k = 1; k <= m; ++k) {
            cin >> us[j][k];
        }
    }
}

inline void solve() {
    for (int i = 1; i <= m * n; ++i) {
        int j = seq[i], k = ++step[j], p = mc[j][k], d = us[j][k], s = tot[j];
        for (int q = 1; q <= cnt[p] + 1; ++q) {
            if (q > cnt[p] || s + d <= e[p][q]) {
                for (int t = cnt[p]; t >= q; --t) {
                    e[p][t + 1] = e[p][t];
                }
                e[p][q] = s + d, ++cnt[p];
                break;
            }
            s = max(s, e[p][q]);
        }
        tot[j] = s + d;
    }
    int ans = 0;
    for (int p = 1; p <= m; ++p) {
        for (int q = 1; q <= cnt[p]; ++q) {
            ans = max(ans, e[p][q]);
        }
    }
    cout << ans << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    solve();
    return 0;
}
