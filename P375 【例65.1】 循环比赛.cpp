#include <bits/stdc++.h>
using namespace std;

const int N = 128 + 5;

int m, n, a[N][N];

inline void input() {
    cin >> m;
    n = 1 << m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = i ^ j;
        }
    }
    return;
}

inline void solve() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] + 1 << (j + 1 == n ? "\n" : " ");
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