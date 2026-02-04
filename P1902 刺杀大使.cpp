#include <bits/stdc++.h>
using namespace std;
struct node {
    int x, y, step;
};
const int N = 1e3 + 5, dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0}, inf = 0x3f3f3f3f;
bool vis[N][N];
int n, m, p[N][N], l, r, mid, ans;
inline bool bfs() {
    queue<node> q;
    ans = 0;
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= m; i++) {
        q.push({1, i, 0});
    }
    for (; !q.empty();) {
        auto [x, y, step] = q.front();
        q.pop();
        if (x != n) {
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx > 0 && nx <= n && ny > 0 && ny <= m && !vis[nx][ny] && p[nx][ny] <= mid) {
                    vis[nx][ny] = true;
                    q.push({nx, ny, step + 1});
                }
            }
        } else {
            ans = max(ans, step);
        }
    }
    return ans >= mid;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> p[i][j];
            l = min(l, p[i][j]), r = max(r, p[i][j]);
        }
    }
    for (; l <= r;) {
        mid = (l + r) >> 1;
        if (bfs()) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << l;
    return 0;
}