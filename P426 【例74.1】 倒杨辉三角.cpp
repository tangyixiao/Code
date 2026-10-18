#include <bits/stdc++.h>
using namespace std;

int a[6][6], n;

inline void input() {
    cin >> n;
    a[0][0] = 1;
    for (int i = 1; i < n; i++) {
        a[i][0] = a[i][i] = 1;
        for (int j = 1; j < i; j++) {
            a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
        }
    }
    return;
}

inline void solve() {
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            cout << a[i][j] << (j == i ? "" : " ");
        }
        cout << "\n";
    }
    return;
}

signed main() {
    input();
    solve();
    return 0;
}
