#include <bits/stdc++.h>
using namespace std;

const int N = 13, M = 1 << 12, MOD = 100000000;
int n, m, a[N], ok[M];
long long f[M], g[M];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int s = 0, x;
        for (int j = 0; j < m; j++) {
            cin >> x;
            if (x) {
                s |= 1 << j;
            }
        }
        a[i] = s;
    }
    int lim = 1 << m;
    for (int s = 0; s < lim; s++) {
        ok[s] = ((s & (s << 1)) == 0);
    }
    f[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int s = 0; s < lim; s++) {
            g[s] = 0;
            if (!ok[s] || (s & ~a[i]) != 0) {
                continue;
            }
            for (int t = 0; t < lim; t++) {
                if (ok[t] && (s & t) == 0) {
                    g[s] = (g[s] + f[t]) % MOD;
                }
            }
        }
        for (int s = 0; s < lim; s++) {
            f[s] = g[s];
        }
    }
    long long ans = 0;
    for (int s = 0; s < lim; s++) {
        ans = (ans + f[s]) % MOD;
    }
    cout << ans << "\n";
    return 0;
}
