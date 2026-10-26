#include <bits/stdc++.h>
using namespace std;

namespace TANGYIXIAO {
const int N = 2e5 + 5, M = 7e4 + 5, K = 2e1 + 5, mod = 998244353;
int a[N], l[K], d[M], pc[M], c[M][K], f[M][K], b[N][K];
int n, m, q, S, s, day;
bool vis[M];
long long ans, z;

inline void solve(int) {
    cin >> n >> m >> q;
    S = 1 << m;
    for (int i = 1; i <= n; i++) { cin >> a[i]; }
    for (int s = 1; s < S; s++) { pc[s] = pc[s >> 1] + (s & 1); }
    for (int i = 1; i <= n; i++) {
        for (int x = 0; x < m; x++) {
            if (!(a[i] >> x & 1)) {
                l[x] = i;
            }
        }
    }
    vis[0] = true, d[0] = 1;
    for (int i = 0; i < q; i++) {
        cin >> s >> day;
        vis[s] = true, d[s] = day;
        for (int x = 0; x < m; x++) {
            if (s >> x & 1) {
                d[s] = max(d[s], l[x] + 1);
            }
        }
    }
    for (int i = 0; i <= n; i++) {
        b[i][0] = 1;
        for (int k = 1; k <= m; k++) { b[i][k] = i ? (b[i - 1][k] + b[i - 1][k - 1]) % mod : 0; }
    }
    c[0][0] = 1;
    for (int r = 1; r <= m; r++) {
        for (int s = 0; s < S; s++) {
            for (int k = 0; k < r; k++) { f[s][k] = pc[s] < r ? c[s][k] : 0; }
        }
        for (int x = 0; x < m; x++) {
            for (int s = 0; s < S; s++) {
                if (s >> x & 1) {
                    for (int k = 0; k < r; k++) {
                        f[s][k] += f[s ^ (1 << x)][k];
                        if (f[s][k] >= mod) {
                            f[s][k] -= mod;
                        }
                    }
                }
            }
        }
        for (int s = 1; s < S; s++) {
            if (pc[s] == r && vis[s] && d[s] <= n) {
                for (int k = 0; k < r; k++) { c[s][k + 1] = f[s][k]; }
                z = 0;
                for (int k = 1; k <= r; k++) { z = (z + 1LL * c[s][k] * b[d[s] - 1][k]) % mod; }
                c[s][0] = (mod - z) % mod;
            }
        }
    }
    for (int s = 0; s < S; s++) {
        if (vis[s] && d[s] <= n) {
            for (int k = 0; k <= pc[s]; k++) {
                ans = (ans + 1LL * c[s][k] * b[n][k]) % mod;
            }
        }
    }
    cout << ans << "\n";
}
} // namespace TANGYIXIAO

signed main() {
    freopen("epigraphy.in", "r", stdin);
    freopen("epigraphy.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(nullptr);
    TANGYIXIAO::solve(1);
    return 0;
}
