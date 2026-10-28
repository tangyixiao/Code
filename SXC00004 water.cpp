#include <bits/stdc++.h>
using namespace std;

const int N = 305;
const long long INF = 1e18;

int n, m, i, j, k, len, l, r, cntneg, z, s1, s2;
int x[N];
long long ans;
long long dp[N][N][2];

signed main() {
    scanf("%d %d", &n, &m);
    for (i = 1; i <= n; i++) {
        scanf("%d", &x[i]);
    }
    sort(x + 1, x + n + 1);
    cntneg = 0;
    z = 0;
    for (i = 1; i <= n; i++) {
        if (x[i] < 0) {
            cntneg = i;
        }
        if (x[i] == 0) {
            z = i;
        }
    }
    ans = 0;
    for (k = 1; k <= n; k++) {
        for (l = 1; l <= n; l++) {
            for (r = 1; r <= n; r++) {
                dp[l][r][0] = INF;
                dp[l][r][1] = INF;
            }
        }
        if (z != 0) {
            dp[z][z][0] = 0;
            dp[z][z][1] = 0;
        } else {
            s1 = cntneg;
            s2 = cntneg + 1;
            if (s1 >= 1) {
                dp[s1][s1][0] = 1LL * k * (0 - x[s1]);
                dp[s1][s1][1] = dp[s1][s1][0];
            }
            if (s2 <= n) {
                dp[s2][s2][0] = 1LL * k * (x[s2] - 0);
                dp[s2][s2][1] = dp[s2][s2][0];
            }
        }
        for (len = 1; len < k; len++) {
            long long c = k - len;
            for (l = 1; l + len - 1 <= n; l++) {
                r = l + len - 1;
                for (int sd = 0; sd < 2; sd++) {
                    long long cur = dp[l][r][sd];
                    if (cur >= INF) {
                        continue;
                    }
                    long long px = (sd == 0) ? x[l] : x[r];
                    if (l - 1 >= 1) {
                        long long d = px - x[l - 1];
                        if (cur + c * d < dp[l - 1][r][0]) {
                            dp[l - 1][r][0] = cur + c * d;
                        }
                    }
                    if (r + 1 <= n) {
                        long long d = x[r + 1] - px;
                        if (cur + c * d < dp[l][r + 1][1]) {
                            dp[l][r + 1][1] = cur + c * d;
                        }
                    }
                }
            }
        }
        for (l = 1; l + k - 1 <= n; l++) {
            r = l + k - 1;
            long long bst = min(dp[l][r][0], dp[l][r][1]);
            if (bst >= INF) {
                continue;
            }
            long long v = 1LL * k * m - bst;
            if (v > ans) {
                ans = v;
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}
