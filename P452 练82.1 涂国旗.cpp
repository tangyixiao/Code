#include <bits/stdc++.h>
using namespace std;

const int N = 5005;
int n, m, w[N][N], b[N][N], r[N][N];
char g[N][N];

signed main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> (g[i] + 1);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            w[i][j] = w[i - 1][j] + w[i][j - 1] - w[i - 1][j - 1] + (g[i][j] != 'W');
            b[i][j] = b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1] + (g[i][j] != 'B');
            r[i][j] = r[i - 1][j] + r[i][j - 1] - r[i - 1][j - 1] + (g[i][j] != 'R');
        }
    }
    int ans = 1e9;
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int x = w[i][m], y = b[j][m] - b[i][m], z = r[n][m] - r[j][m];
            ans = min(ans, x + y + z);
        }
    }
    cout << ans << "\n";
    return 0;
}
