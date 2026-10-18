#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
const int P = 1e6 + 7;

int n, m, a[N], f[N], g[N];

inline void input() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
}

inline void solve() {
    f[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            long long s = 0;
            for (int k = 0; k <= a[i] && k <= j; k++) {
                s += f[j - k];
            }
            g[j] = s % P;
        }
        for (int j = 0; j <= m; j++) {
            f[j] = g[j];
        }
    }
    cout << f[m] << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
