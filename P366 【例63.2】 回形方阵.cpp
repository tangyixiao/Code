#include <bits/stdc++.h>
using namespace std;

const int N = 2e2 + 5;

int n, a[N][N];

inline void input() {
    cin >> n;
    return;
}

inline void solve() {
    for (int i = 0; i < 2 * n + 1; i++) {
        for (int j = 0; j < 2 * n + 1; j++) {
            a[i][j] = min(min(i, 2 * n - i), min(j, 2 * n - j));
        }
    }
    for (int i = 0; i < 2 * n + 1; i++) {
        for (int j = 0; j < 2 * n + 1; j++) {
            cout << setw(2) << n - a[i][j];
        }
        cout << "\n";
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