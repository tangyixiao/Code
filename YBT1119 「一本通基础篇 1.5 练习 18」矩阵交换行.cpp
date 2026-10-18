#include <bits/stdc++.h>
using namespace std;

const int N = 5;
int a[N][N], m, n;

inline void input() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> a[i][j];
        }
    }
    cin >> m >> n;
    return;
}

inline void solve() {
    for (int j = 0; j < N; j++) {
        swap(a[m - 1][j], a[n - 1][j]);
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << a[i][j] << " \n"[j == N - 1];
        }
    }
    return;
}

signed main() {
    input();
    solve();
    return 0;
}