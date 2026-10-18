#include <bits/stdc++.h>
using namespace std;

const int N = 105, M = 25005;
int t, a[N][N], c[N], f[M];

inline void input() {
    cin >> t;
    for (int k = 1; k <= t; ++k) {
        cin >> c[k];
        for (int i = 1; i <= c[k]; ++i) {
            cin >> a[k][i];
        }
    }
}

inline void solve() {
    for (int k = 1; k <= t; ++k) {
        sort(a[k] + 1, a[k] + c[k] + 1);
        int mx = a[k][c[k]];
        for (int j = 0; j <= mx; ++j) {
            f[j] = 0;
        }
        int cnt = 0;
        for (int i = 1; i <= c[k]; ++i) {
            if (f[a[k][i]] == a[k][i]) {
                continue;
            }
            ++cnt;
            for (int j = a[k][i]; j <= mx; ++j) {
                f[j] = max(f[j], f[j - a[k][i]] + a[k][i]);
            }
        }
        cout << cnt << "\n";
    }
    return;
}

signed main() {
    input();
    solve();
    return 0;
}
