#include <bits/stdc++.h>
using namespace std;
const int N = 61;
int n, m, k, sum[N], p[N], w[N], f[N][N][2], c;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> c;
    for (int i = 1; i <= n; i++) {
        cin >> p[i] >> w[i];
        sum[i] = sum[i - 1] + w[i];
    }

    memset(f, 0x7f, sizeof(f));
    f[c][c][0] = f[c][c][1] = 0;

    for (int len = 2; len <= n; len++) {
        for (int i = 1; i + len - 1 <= n; i++) {
            int j = i + len - 1;
            f[i][j][0] = min(f[i + 1][j][0] + (p[i + 1] - p[i]) * (sum[i] + sum[n] - sum[j]),
                             f[i + 1][j][1] + (p[j] - p[i]) * (sum[i] + sum[n] - sum[j]));
            f[i][j][1] =
                min(f[i][j - 1][0] + (p[j] - p[i]) * (sum[i - 1] + sum[n] - sum[j - 1]),
                    f[i][j - 1][1] + (p[j] - p[j - 1]) * (sum[i - 1] + sum[n] - sum[j - 1]));
        }
    }

    cout << min(f[1][n][0], f[1][n][1]);

    return 0;
}