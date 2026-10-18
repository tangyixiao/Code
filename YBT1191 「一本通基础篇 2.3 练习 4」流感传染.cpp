#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;

char a[N][N], b[N][N];
int n, m, c;
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};

inline void input() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cin >> m;
}

inline void solve() {
    for (int t = 1; t < m; ++t) {
        memcpy(b, a, sizeof(a));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (a[i][j] != '.') {
                    continue;
                }
                for (int k = 0; k < 4; ++k) {
                    int x = i + dx[k], y = j + dy[k];
                    if (x < 0 || x >= n || y < 0 || y >= n) {
                        continue;
                    }
                    if (a[x][y] == '@') {
                        b[i][j] = '@';
                    }
                }
            }
        }
        memcpy(a, b, sizeof(a));
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            c += (a[i][j] == '@');
        }
    }
    cout << c << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    solve();
    return 0;
}
