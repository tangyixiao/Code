#include <bits/stdc++.h>
using namespace std;

long long x, y, k, b;
long long d[70], dp[2][20], nd[2][20];

long long cnt(long long n) {
    if (n <= 0) {
        return 0;
    }
    int len = 0;
    long long t = n;
    for (; t > 0; t /= b) {
        d[len++] = t % b;
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j <= k; j++) {
            dp[i][j] = 0;
        }
    }
    dp[0][0] = 1;
    for (int p = len - 1; p >= 0; p--) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j <= k; j++) {
                nd[i][j] = 0;
            }
        }
        for (int less = 0; less < 2; less++) {
            for (int j = 0; j <= k; j++) {
                if (dp[less][j] == 0) {
                    continue;
                }
                for (int g = 0; g < 2; g++) {
                    if (j + g > k) {
                        continue;
                    }
                    if (less == 0 && g > d[p]) {
                        continue;
                    }
                    int nl = less;
                    if (less == 0 && g < d[p]) {
                        nl = 1;
                    }
                    nd[nl][j + g] += dp[less][j];
                }
            }
        }
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j <= k; j++) {
                dp[i][j] = nd[i][j];
            }
        }
    }
    return dp[0][k] + dp[1][k];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> x >> y >> k >> b;
    cout << cnt(y) - cnt(x - 1) << "\n";
    return 0;
}
