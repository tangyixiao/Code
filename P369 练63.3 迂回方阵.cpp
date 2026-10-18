#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int n, a[N][N];

inline void input() { cin >> n; }

inline void solve() {
    int k = 1;
    a[n][1] = k;
    for (int t = 1; t < n; t++) {
        int r = n - t;
        for (int j = 1; j <= t + 1; j++) {
            a[r][j] = ++k;
        }
        for (int i = r + 1; i <= n; i++) {
            a[i][t + 1] = ++k;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%4d", a[i][j]);
        }
        printf("\r\n");
    }
    return;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    input(), solve();
    return 0;
}
