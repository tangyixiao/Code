#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
int n, ec, i, a, b, u, v, e, best;
int head[N], nxt[N * 2], to[N * 2], dp[N][3];
void add(int x, int y) {
    ec++;
    to[ec] = y;
    nxt[ec] = head[x];
    head[x] = ec;
}
void dfs(int x, int p) {
    int c = 0, mn = 1e9, d;
    dp[x][0] = 1;
    dp[x][1] = 0;
    dp[x][2] = 1e9;
    for (int t = head[x]; t; t = nxt[t]) {
        int y = to[t];
        if (y == p) {
            continue;
        }
        dfs(y, x);
        d = min(dp[y][0], dp[y][2]);
        dp[x][0] += min(dp[y][0], min(dp[y][1], dp[y][2]));
        dp[x][1] += d;
        if (dp[y][0] - d < mn) {
            mn = dp[y][0] - d;
        }
        c++;
    }
    if (c > 0) {
        dp[x][2] = dp[x][1] + mn;
    }
}
signed main() {
    scanf("%d", &n);
    for (i = 1; i < n; i++) {
        scanf("%d %d", &a, &b);
        add(a, b);
        add(b, a);
    }
    dfs(1, 0);
    best = min(dp[1][0], dp[1][2]);
    printf("%d\n", best);
    return 0;
}
