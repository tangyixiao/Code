#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int n, f[N][2];

inline void input() {
    cin >> n;
}

inline void solve() {
    f[1][0] = 8;
    f[1][1] = 1;
    for (int i = 2; i <= n; i++) {
        f[i][0] = (f[i - 1][0] * 9 + f[i - 1][1]) % 12345;
        f[i][1] = (f[i - 1][1] * 9 + f[i - 1][0]) % 12345;
    }
    cout << f[n][0] << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}