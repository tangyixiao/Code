#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int n, t, x, y, ans;
int f[N][N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> t;
    for (int i = 1; i <= t; i++) {
        cin >> x >> y;
        f[x][y] = -1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (f[i][j] == -1) {
                f[i][j] = 0;
            } else {
                f[i][j] = min(f[i - 1][j], min(f[i][j - 1], f[i - 1][j - 1])) + 1;
                ans = max(ans, f[i][j]);
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
