#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int n, a[N][N];

inline void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
}

inline void solve() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << a[i][j] << (j == i ? "\n" : " ");
        }
    }
    return;
}

signed main() {
    input(), solve();
    return 0;
}