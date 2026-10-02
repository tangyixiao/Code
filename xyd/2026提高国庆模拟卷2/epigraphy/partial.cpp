#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5, K = 16, S = 1 << K, mod = 998244353;
int a[N], d[S], dp[S], f[S], st[S], n, m, q, lim;
bool vis[S];
long long ans;

signed main() {
    freopen("epigraphy.in", "r", stdin), freopen("epigraphy.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n >> m >> q;
    lim = 1 << m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    vis[0] = true, st[0] = 0;
    for (int i = 0, s, day; i < q; i++) {
        cin >> s >> day;
        vis[s] = true, d[s] = day, st[i + 1] = s;
    }
    if (q <= 10) {
        dp[0] = 1;
        for (int day = 1; day <= n; day++) {
            for (int j = 0; j <= q; j++) {
                int s = st[j];
                long long z = 0;
                if (day >= d[s] && (s & a[day]) == s)
                    for (int k = 0; k <= q; k++) if ((st[k] & s) == st[k]) z += dp[k];
                f[j] = z % mod;
            }
            ans = 0;
            for (int j = 0; j <= q; j++) dp[j] = f[j], ans += dp[j];
            ans %= mod;
        }
        cout << ans << '\n';
        return 0;
    }
    dp[0] = 1;
    for (int day = 1; day <= n; day++) {
        for (int s = 0; s < lim; s++) f[s] = dp[s];
        for (int b = 0; b < m; b++) for (int s = 0; s < lim; s++) if (s >> b & 1) {
            f[s] += f[s ^ (1 << b)];
            if (f[s] >= mod) f[s] -= mod;
        }
        ans = 0;
        for (int s = 0; s < lim; s++) {
            dp[s] = vis[s] && d[s] <= day && (s & a[day]) == s ? f[s] : 0;
            ans += dp[s];
            if (ans >= mod) ans -= mod;
        }
    }
    cout << ans << '\n';
    return 0;
}
