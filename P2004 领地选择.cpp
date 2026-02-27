#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e3 + 5;
int n, m, c, a[N][N], f[N][N], ans = -1e18, x = 1, y = 1;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> c;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            f[i][j] = f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1] + a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i + c - 1 <= n && j + c - 1 <= m) {
                if (ans < f[i + c - 1][j + c - 1] - f[i - 1][j + c - 1] - f[i + c - 1][j - 1] + f[i - 1][j - 1]) {
                    ans = f[i + c - 1][j + c - 1] - f[i - 1][j + c - 1] - f[i + c - 1][j - 1] + f[i - 1][j - 1];
                    x = i;
                    y = j;
                }
            }
        }
    }
    cout << x << " " << y;
    return 0;
}