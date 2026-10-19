#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;

int n, a[N][N];

inline void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
}

inline void solve() {
    input();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n / 2; j++) {
            swap(a[i][j], a[i][n - 1 - j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << (j == n - 1 ? "\n" : " ");
        }
    }
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}