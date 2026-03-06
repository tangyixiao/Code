#include <cstdio>
int read() {
    int a = 0, ch = getchar();
    while (ch < 48 || ch > 57)
        ch = getchar();
    while (48 <= ch && ch <= 57) {
        a = a * 10 + (ch ^ 48);
        ch = getchar();
    }
    return a;
}
void print(int a) {
    if (a >= 10)
        print(a / 10);
    putchar((a % 10) | 48);
    return;
}
int n, k;
int s[100010];
int dp[2][50010][2];
int main() {
    freopen("P3620.in", "r", stdin);
    freopen("P3620.out", "w", stdout);
    n = read();
    k = read();
    for (int i = 1; i <= n; i++)
        s[i] = read();
    dp[1][0][0] = 0;
    for (int i = 2; i <= n; i++) {
        dp[i & 1][0][0] = dp[i & 1][0][1] = 0;
        for (int j = (1 >= (k - ((n - i) >> 1) - 1) ? 1 : (k - ((n - i) >> 1) - 1)), t = (k <= (i - 1 >> 1) ? k : (i - 1 >> 1)); j <= t; j++) {
            dp[i & 1][j][0] = dp[i - 1 & 1][j][0] < dp[i - 1 & 1][j][1] ? dp[i - 1 & 1][j][0] : dp[i - 1 & 1][j][1];
            dp[i & 1][j][1] = dp[i - 1 & 1][j - 1][0] + s[i] - s[i - 1];
        }
        (i & 1) ? 0 : (dp[i & 1][i >> 1][0] = 1e9, dp[i & 1][i >> 1][1] = dp[i - 1 & 1][(i >> 1) - 1][0] + s[i] - s[i - 1]);
    }
    print(dp[n & 1][k][0] < dp[n & 1][k][1] ? dp[n & 1][k][0] : dp[n & 1][k][1]);
    return 0;
}
