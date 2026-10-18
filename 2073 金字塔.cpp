#include <bits/stdc++.h>
using namespace std;

const int N = 105;

int r, a[N][N];

inline void input() {
    cin >> r;
    for (int i = 1; i <= r; ++i) {
        for (int j = 1; j <= i; ++j) {
            cin >> a[i][j];
        }
    }
}

inline void solve() {
    for (int i = r - 1; i >= 1; --i) {
        for (int j = 1; j <= i; ++j) {
            a[i][j] += max(a[i + 1][j], a[i + 1][j + 1]);
        }
    }
    cout << a[1][1] << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    solve();
    return 0;
}
