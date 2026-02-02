#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 61;
int n, m, ar[N][N], f[N][N][N][N], sum[N][N];
inline int dfs(int a, int b, int c, int d) {
    if (f[a][b][c][d]) {
        return f[a][b][c][d];
    }
    if (b == d && a == c) {
        return 0;
    }
    int ma = 1e10;
    for (int i = a; i < c; i++) {
        ma = min(ma, dfs(a, b, i, d) + dfs(i + 1, b, c, d));
    }
    for (int i = b; i < d; i++) {
        ma = min(ma, dfs(a, b, c, i) + dfs(a, i + 1, c, d));
    }
    f[a][b][c][d] = ma + sum[c][d] - sum[a - 1][d] - sum[c][b - 1] + sum[a - 1][b - 1];
    return f[a][b][c][d];
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> ar[i][j];
            sum[i][j] = ar[i][j] + sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1];
        }
    }
    cout << dfs(1, 1, n, m);
    return 0;
}
