#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;
int m, n, a[N][N];

inline void input() {
    cin >> m;
    return;
}

inline void solve() {
    n = 1 << m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = (i ^ j) + 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << a[i - 1][j - 1] << (j == n ? "\n" : " ");
        }
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