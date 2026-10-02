#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;
const int maxm = 16;
const int maxs = 1 << maxm;
int a[200005], d[maxs], dp[maxs], sum[maxs], stamp[maxs];
bool has[maxs];

signed main() {
    freopen("epigraphy.in", "r", stdin);
    freopen("epigraphy.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int lim = 1 << m;
    has[0] = true;
    stamp[0] = 0;
    for (int i = 0, s, day; i < q; i++) {
        cin >> s >> day;
        has[s] = true;
        d[s] = day;
        stamp[i + 1] = s;
    }
    if (q <= 10) {
        int cnt = q + 1;
        dp[0] = 1;
        long long ans = 1;
        for (int day = 1; day <= n; day++) {
            for (int j = 0; j < cnt; j++) {
                int s = stamp[j];
                long long ways = 0;
                if (day >= d[s] && (s & a[day]) == s) {
                    for (int k = 0; k < cnt; k++) {
                        int t = stamp[k];
                        if ((t & s) == t) ways += dp[k];
                    }
                }
                sum[j] = ways % mod;
            }
            ans = 0;
            for (int j = 0; j < cnt; j++) {
                dp[j] = sum[j];
                ans += dp[j];
            }
            ans %= mod;
        }
        cout << ans << '\n';
        return 0;
    }
    dp[0] = 1;
    long long ans = 1;
    for (int day = 1; day <= n; day++) {
        for (int s = 0; s < lim; s++) {
            sum[s] = dp[s];
        }
        for (int b = 0; b < m; b++) {
            for (int s = 0; s < lim; s++) {
                if (s >> b & 1) {
                    sum[s] += sum[s ^ (1 << b)];
                    if (sum[s] >= mod) {
                        sum[s] -= mod;
                    }
                }
            }
        }
        ans = 0;
        for (int s = 0; s < lim; s++) {
            dp[s] = has[s] && d[s] <= day && (s & a[day]) == s ? sum[s] : 0;
            ans += dp[s];
            if (ans >= mod) {
                ans -= mod;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
