#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;

int w, h;
char a[N][N], f[N][N];

inline void solve() {
    int x = 0, y = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (a[i][j] == '@') {
                x = i, y = j;
            }
        }
    }
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    f[x][y] = 1;
    int c = 0;
    while (!q.empty()) {
        int r = q.front().first, d = q.front().second;
        q.pop();
        ++c;
        int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
        for (int i = 0; i < 4; ++i) {
            int u = r + dx[i], v = d + dy[i];
            if (u < 0 || u >= h || v < 0 || v >= w || f[u][v] || a[u][v] == '#') {
                continue;
            }
            f[u][v] = 1;
            q.push(make_pair(u, v));
        }
    }
    cout << c << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> w >> h && (w || h)) {
        for (int i = 0; i < h; ++i) {
            cin >> a[i];
        }
        memset(f, 0, sizeof(f));
        solve();
    }
    return 0;
}
