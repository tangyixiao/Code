#include <bits/stdc++.h>
using namespace std;

const int N = 35;
int n, k;
long long f[N][N];

inline void input() {
    cin >> n >> k;
    return;
}

inline void solve() {
    f[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            f[i][j] = f[i - 1][j - 1] + j * f[i - 1][j];
        }
    }
    cout << f[n][k] << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}