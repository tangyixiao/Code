#include <bits/stdc++.h>
using namespace std;

const int N = 5e1 + 5;
int m, n;
long long f[N][N];

inline void input() {
    cin >> m >> n;
}

inline void solve() {
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            f[i][j] = i == 1 || j == 1 ? 1 : f[i - 1][j] + f[i][j - 1];
        }
    }
    cout << f[m][n] << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}