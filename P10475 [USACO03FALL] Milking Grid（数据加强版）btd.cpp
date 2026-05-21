#include <bits/stdc++.h>
#define int long long
using namespace std;
const int P1 = 131, P2 = 13331, mod = 1e9 + 7;
int n, m, h[10006][86];
char mp[10006][86];
int qpow(int x, int y) {
    int z = 1;
    while (y) {
        if (y & 1) {
            z = z * x % mod;
        }
        x = x * x % mod;
        y >>= 1;
    }
    return z;
}
signed main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mp[i][j];
            h[i][j] = (h[i][j - 1] * P1 + (mp[i][j] - 'A')) % mod;
        }
    }
    for (int j = 1; j <= m; j++) {
        for (int i = 1; i <= n; i++) {
            h[i][j] = (h[i - 1][j] * P2 + h[i][j]) % mod;
        }
    }
    int ans = 1e18;
    for (int i = n; i >= 1; i--) {
        for (int j = m; j >= 1; j--) {
            if (h[i][j] == (h[i][m] - h[i][m - j] * qpow(P1, j) % mod + mod) % mod && h[i][m] == (h[n][m] - h[n - i][m] * qpow(P2, i) % mod + mod) % mod) {
                int x = n - i, y = m - j;
                x = (x == 0 ? n : x);
                y = (y == 0 ? m : y);
                ans = min(ans, x * y);
            }
        }
    }
    cout << ans;
    return 0;
}
