#include <bits/stdc++.h>
using namespace std;

const int N = 1005, M = 205, K = 205, P = 1e9 + 7;
int f[2][M][K][2];
char s[N], p[M], a[N], b[M];
int n, m, k;

inline void input() {
    cin >> n >> m >> k;
    cin >> s >> p;
    for (int i = 1; i <= n; ++i) {
        a[i] = s[i - 1];
    }
    for (int j = 1; j <= m; ++j) {
        b[j] = p[j - 1];
    }
}

inline void solve() {
    f[0][0][0][0] = 1;
    int t = 0;
    for (int i = 1; i <= n; ++i) {
        t ^= 1;
        for (int j = 0; j <= m; ++j) {
            for (int l = 0; l <= k; ++l) {
                f[t][j][l][1] = 0;
                int s0 = f[t ^ 1][j][l][0] + f[t ^ 1][j][l][1];
                f[t][j][l][0] = s0 % P;
            }
        }
        for (int j = 1; j <= m; ++j) {
            if (a[i] != b[j]) {
                continue;
            }
            for (int l = 1; l <= k; ++l) {
                int s0 = f[t ^ 1][j - 1][l][1] + f[t ^ 1][j - 1][l - 1][0];
                f[t][j][l][1] = s0 % P;
            }
        }
    }
    cout << (f[t][m][k][0] + f[t][m][k][1]) % P << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}
