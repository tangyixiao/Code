#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int n, m, a[N], b[N], f[N][N], g[N][N];

inline void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }
}

inline void solve() {
    int len = 0, x = 0, y = 0;
    for (int i = 1; i <= n; i++) {
        int t = 0, p = 0;
        for (int j = 1; j <= m; j++) {
            if (b[j] < a[i]) {
                if (f[i - 1][j] > t) {
                    t = f[i - 1][j], p = j;
                }
            } else if (b[j] == a[i]) {
                f[i][j] = t + 1, g[i][j] = p;
                if (f[i][j] > len) {
                    len = f[i][j], x = i, y = j;
                }
            }
        }
    }
    int r[N], k = 0;
    while (x > 0 && y > 0 && f[x][y] > 0) {
        r[k++] = b[y];
        int t = g[x][y];
        x--, y = t;
    }
    cout << k << "\n";
    for (int i = k - 1; i >= 0; i--) {
        cout << r[i] << (i == 0 ? "\n" : " ");
    }
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}