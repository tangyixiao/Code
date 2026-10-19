#include <bits/stdc++.h>
using namespace std;
const int N = 15;
int n, a[N][N], b[N][N];

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
        for (int j = 1; j <= n; j++) {
            for (int x = i - 1; x <= i + 1; x++) {
                for (int y = j - 1; y <= j + 1; y++) {
                    if (x < 1 || x > n || y < 1 || y > n) {
                        continue;
                    }
                    b[i][j] += a[x][y];
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << b[i][j] << (j == n ? "\n" : " ");
        }
    }
    return;
}

signed main() {
    input(), solve();
    return 0;
}