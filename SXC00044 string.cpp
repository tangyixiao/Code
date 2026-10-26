#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 5;
int pi[N], dp[N];
int ok(string p, string t) {
    int n = (int)p.size(), m = (int)t.size(), i, j, k = 0;
    int co[2] = {0, 0}, ct[2] = {0, 0};
    for (i = 0; i < n; i++) {
        co[p[i] == 'o' ? 0 : 1]++;
        ct[t[i] == 'o' ? 0 : 1]++;
    }
    if (co[0] != ct[0] || co[1] != ct[1]) {
        return 0;
    }
    int pos[2][N], cp[2] = {0, 0};
    for (i = 0; i < n; i++) {
        int c = p[i] == 'o' ? 0 : 1;
        pos[c][cp[c]++] = i + 1;
    }
    int cn[2] = {0, 0};
    for (i = 0; i < m; i++) {
        int c = t[i] == 'o' ? 0 : 1;
        pi[i] = pos[c][cn[c]++];
    }
    int best = 0;
    for (i = 0; i < m; i++) {
        dp[i] = 1;
        for (j = 0; j < i; j++) {
            if (pi[j] > pi[i] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
            }
        }
        if (dp[i] > best) {
            best = dp[i];
        }
    }
    return best <= 2;
}
signed main() {
    int t, tt;
    string s, g;
    cin >> t;
    for (tt = 1; tt <= t; tt++) {
        cin >> s >> g;
        int n = (int)s.size(), i, ans = 2 * n;
        for (i = n; i >= 0; i--) {
            if (s.substr(n - i) == g.substr(0, i)) {
                if (i == n) {
                    if (s == g) {
                        ans = 0;
                    }
                    continue;
                }
                if (ok(s.substr(0, n - i), g.substr(i))) {
                    ans = 2 * (n - i);
                    break;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
