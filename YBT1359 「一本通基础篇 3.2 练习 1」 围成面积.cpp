#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;
int a[12][12], vis[12][12], n = 10, dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
queue<pair<int, int>> q;

inline void input() {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
        }
    }
}

inline void solve() {
    q.push(make_pair(0, 0));
    vis[0][0] = 1;
    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        for (int k = 0; k < 4; ++k) {
            int tx = x + dx[k], ty = y + dy[k];
            if (tx < 0 || ty < 0 || tx > n + 1 || ty > n + 1 || vis[tx][ty] || a[tx][ty]) {
                continue;
            }
            vis[tx][ty] = 1;
            q.push(make_pair(tx, ty));
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (!a[i][j] && !vis[i][j]) {
                ++ans;
            }
        }
    }
    cout << ans << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}