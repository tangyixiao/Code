#include <bits/stdc++.h>
using namespace std;

const int N = 3e2 + 5;

int n, l, x1, y1, x2, y2, d[N][N];
const int dx[8] = {1, 1, -1, -1, 2, 2, -2, -2};
const int dy[8] = {2, -2, 2, -2, 1, -1, 1, -1};

void solve();

inline void input() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> l;
        cin >> x1 >> y1;
        cin >> x2 >> y2;
        memset(d, -1, sizeof d);
        solve();
    }
    return;
}

inline void solve() {
    queue<pair<int, int>> q;
    d[x1][y1] = 0, q.push({x1, y1});
    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        for (int i = 0; i < 8; ++i) {
            int u = x + dx[i], v = y + dy[i];
            if (u < 0 || u >= l || v < 0 || v >= l || d[u][v] > -1) {
                continue;
            }
            d[u][v] = d[x][y] + 1, q.push({u, v});
        }
    }
    cout << d[x2][y2] << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    return 0;
}
