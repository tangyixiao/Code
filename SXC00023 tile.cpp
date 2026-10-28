#include <bits/stdc++.h>
using namespace std;

const int MOD = 100003;
const int N = 65;
int n, m;
int trans[N][N], tc[N];
int dp[N], nd[N];
int cur, nxt, t;

void dfs(int col, int row, int out) {
    if (row == n) {
        trans[cur][tc[cur]++] = out;
        return;
    }
    if ((col >> row) & 1) {
        dfs(col, row + 1, out);
        return;
    }
    dfs(col, row + 1, out | (1 << row));
    if (row + 1 < n && !((col >> (row + 1)) & 1)) {
        dfs(col, row + 2, out);
    }
}

signed main() {
    scanf("%d%d", &n, &m);
    if (n > m) {
        t = n;
        n = m;
        m = t;
    }
    for (cur = 0; cur < (1 << n); cur++) {
        tc[cur] = 0;
        dfs(cur, 0, 0);
    }
    dp[0] = 1;
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < (1 << n); j++) {
            nd[j] = 0;
        }
        for (int j = 0; j < (1 << n); j++) {
            if (dp[j] == 0) {
                continue;
            }
            for (int e = 0; e < tc[j]; e++) {
                int k = trans[j][e];
                nd[k] = (nd[k] + dp[j]) % MOD;
            }
        }
        for (int j = 0; j < (1 << n); j++) {
            dp[j] = nd[j];
        }
    }
    printf("%d\n", dp[0]);
    return 0;
}
