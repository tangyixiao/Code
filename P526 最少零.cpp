#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5, INF = 1e9;
int n, a[N][N], f2[N][N], f5[N][N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i <= n + 1; i++) {
        f2[0][i] = f2[i][0] = INF;
        f5[0][i] = f5[i][0] = INF;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            f2[i][j] = f5[i][j] = INF;
            if (a[i][j] == 0) {
                continue;
            }
            int c2 = 0, c5 = 0, v = a[i][j];
            for (; v % 2 == 0; v /= 2) {
                c2++;
            }
            for (; v % 5 == 0; v /= 5) {
                c5++;
            }
            if (i == 1 && j == 1) {
                f2[i][j] = c2, f5[i][j] = c5;
                continue;
            }
            int p2 = min(f2[i - 1][j], f2[i][j - 1]);
            int p5 = min(f5[i - 1][j], f5[i][j - 1]);
            if (p2 < INF) {
                f2[i][j] = p2 + c2;
            }
            if (p5 < INF) {
                f5[i][j] = p5 + c5;
            }
        }
    }
    cout << min(f2[n][n], f5[n][n]) << "\n";
    return 0;
}
