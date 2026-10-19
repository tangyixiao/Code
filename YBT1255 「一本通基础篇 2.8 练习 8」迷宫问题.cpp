#include <bits/stdc++.h>
using namespace std;

const int N = 5 + 5;

int n, m, a[N][N], f[N][N], l[N][N];
const int dx[4] = {0, -1, 0, 1};
const int dy[4] = {-1, 0, 1, 0};

inline void input() {
    n = m = 5;
    for (int i = 1; i <= 5; ++i) {
        for (int j = 1; j <= 5; ++j) {
            cin >> a[i][j];
        }
    }
    return;
}

inline void solve() {
    queue<pair<int, int>> q;
    f[1][1] = 1, l[1][1] = 0, q.push({1, 1});
    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int u = x + dx[i], v = y + dy[i];
            if (u < 1 || u > n || v < 1 || v > m || a[u][v] || f[u][v]) {
                continue;
            }
            f[u][v] = 1, l[u][v] = l[x][y] + 1, q.push({u, v});
        }
    }
    int x = n, y = m, cnt = l[n][m] + 1;
    int s[N][N];
    memset(s, 0, sizeof s);
    while (cnt-- > 0) {
        s[x][y] = 1;
        for (int i = 0; i < 4; ++i) {
            int u = x + dx[i], v = y + dy[i];
            if (u < 1 || u > n || v < 1 || v > m || l[u][v] != l[x][y] - 1) {
                continue;
            }
            x = u, y = v;
            break;
        }
    }
    for (int i = 1; i <= l[n][m] + 1; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (!s[i][j]) {
                continue;
            }
            printf("(%d, %d)\n", i - 1, j - 1);
        }
    }
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    solve();
    return 0;
}
