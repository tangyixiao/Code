#include <bits/stdc++.h>
using namespace std;

const int N = 41;
int n, m, a[N], c[5], a1, a2, a3, a4;
int f[41][41][41][41];

inline void input() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; ++i) {
        int x;
        cin >> x;
        ++c[x];
    }
    a1 = c[1];
    a2 = c[2];
    a3 = c[3];
    a4 = c[4];
}

inline void solve() {
    f[0][0][0][0] = a[1];
    for (int i = 0; i <= a1; ++i) {
        for (int j = 0; j <= a2; ++j) {
            for (int k = 0; k <= a3; ++k) {
                for (int l = 0; l <= a4; ++l) {
                    if (i == 0 && j == 0 && k == 0 && l == 0) {
                        continue;
                    }
                    int p = i + 2 * j + 3 * k + 4 * l + 1;
                    int mx = -1;
                    if (i > 0) {
                        mx = max(mx, f[i - 1][j][k][l]);
                    }
                    if (j > 0) {
                        mx = max(mx, f[i][j - 1][k][l]);
                    }
                    if (k > 0) {
                        mx = max(mx, f[i][j][k - 1][l]);
                    }
                    if (l > 0) {
                        mx = max(mx, f[i][j][k][l - 1]);
                    }
                    f[i][j][k][l] = mx + a[p];
                }
            }
        }
    }
    cout << f[a1][a2][a3][a4] << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}
