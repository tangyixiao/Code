#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;
int T, r, c, f[N][N];

inline void input() {
    cin >> T;
    return;
}

inline void solve() {
    while (T--) {
        cin >> r >> c;
        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                int x;
                cin >> x;
                f[i][j] = x + max(f[i - 1][j], f[i][j - 1]);
            }
        }
        cout << f[r][c] << "\n";
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