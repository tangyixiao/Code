#include <bits/stdc++.h>
using namespace std;
const int N = 20 + 5;
int h, l, c, r, a[N][N];

inline void input() {
    cin >> h >> l >> c >> r;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < l; j++) {
            cin >> a[i][j];
        }
    }
}

inline void solve() {
    int s = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (!i && !j) {
                continue;
            }
            int x = c + i, y = r + j;
            if (x < 0 || x >= h || y < 0 || y >= l) {
                continue;
            }
            s += a[x][y];
        }
    }
    cout << s << "\n";
    return;
}

signed main() {
    input(), solve();
    return 0;
}