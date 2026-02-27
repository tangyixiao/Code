#include <bits/stdc++.h>
using namespace std;
long long n, m, mx, my, dp[114][114], vis[114][114], dx[10] = {-2, -2, -1, 1, -1, 1, 2, 2}, dy[10] = {-1, 1, -2, -2, 2, 2, -1, 1};
int main() {
    cin >> n >> m >> mx >> my;
    n += 2, m += 2, mx += 2, my += 2;
    dp[2][1] = 1;
    vis[mx][my] = -1;
    for (int i = 0; i < 8; i++) {
        vis[mx + dx[i]][my + dy[i]] = -1;
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= m; j++) {
            if (vis[i][j] < 0)
                continue;
            dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
        }
    }
    cout << dp[n][m];
    return 0;
}