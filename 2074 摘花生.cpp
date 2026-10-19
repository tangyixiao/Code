#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;

int r, c, f[N];

inline void input() {
    while (cin >> r >> c) {
        for (int j = 1; j <= c; j++) {
            f[j] = 0;
        }
        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                int x;
                cin >> x;
                f[j] = max(f[j - 1], f[j]) + x;
            }
        }
        cout << f[c] << "\n";
    }
}

inline void solve() {
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
