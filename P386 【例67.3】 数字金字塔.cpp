#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int a[N][N], r;

inline void input() {
    cin >> r;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> a[i][j];
        }
    }
    return;
}

inline void solve() {
    for (int i = r - 1; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            a[i][j] += max(a[i + 1][j], a[i + 1][j + 1]);
        }
    }
    int ans = 0;
    for (int j = 1; j <= r; j++) {
        ans = max(ans, a[j][j]);
    }
    cout << ans << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}
