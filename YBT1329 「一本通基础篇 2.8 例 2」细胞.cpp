#include <bits/stdc++.h>
using namespace std;

const int N = 105;
int n, m, a[N][N];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

inline void input() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char c;
            cin >> c;
            a[i][j] = c - '0';
        }
    }
    return;
}

inline void solve(int x, int y) {
    a[x][y] = 0;
    for (int i = 0; i < 4; i++) {
        int p = x + dx[i], q = y + dy[i];
        if (p < 1 || p > n || q < 1 || q > m) {
            continue;
        }
        if (a[p][q] == 0) {
            continue;
        }
        solve(p, q);
    }
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == 0) {
                continue;
            }
            ans++;
            solve(i, j);
        }
    }
    cout << ans << "\n";
    return 0;
}