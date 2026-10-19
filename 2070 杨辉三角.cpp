#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;
int n, a[N][N];

inline void input() { cin >> n; }

inline void solve() {
    a[0][0] = 1;
    for (int i = 1; i < n; ++i) {
        a[i][0] = a[i][i] = 1;
        for (int j = 1; j < i; ++j) {
            a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            cout << a[i][j] << (j == i ? "\n" : " ");
        }
    }
    return;
}

signed main() {
    input();
    solve();
    return 0;
}