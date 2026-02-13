#include <bits/stdc++.h>
using namespace std;
const int R = 1005;
int r, a[R][R], dp[R][R];
signed main() {
    scanf("%d", &r);
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= i; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    dp[1][1] = a[1][1];
    for (int i = 2; i <= r; i++) {
        dp[i][1] = dp[i - 1][1] + a[i][1];
        dp[i][i] = dp[i - 1][i - 1] + a[i][i];
        for (int j = 2; j < i; j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + a[i][j];
        }
    }
    int res = dp[r][1];
    for (int i = 2; i <= r; i++) {
        res = max(res, dp[r][i]);
    }
    printf("%d", res);
    return 0;
}
