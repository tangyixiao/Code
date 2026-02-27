#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 5, DN = 4;
const int dx[DN] = {1, 0, -1, 0}, dy[DN] = {0, 1, 0, -1};
int n, mp[N][N], sx, sy, ex, ey;
bool vis[N][N][5];
struct node {
    int x, y, st, f;
};
inline int bfs() {
    queue<node> q;
    q.push({sx, sy, 0, 2});
    vis[sx][sy][2] = true;
    for (; !q.empty();) {
        auto [x, y, st, f] = q.front();
        q.pop();
        if (x == ex && y == ey) {
            return st;
        }
        for (int i = 0; i < DN; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= n) {
                if (!vis[nx][ny][f] && f != mp[nx][ny]) {
                    vis[nx][ny][f] = true;
                    q.push({nx, ny, st + 1, mp[nx][ny]});
                }
            }
        }
    }
    return -1;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            char c;
            cin >> c;
            if (c == 'A') {
                sx = i, sy = j;
                mp[i][j] = 2;
            } else {
                if (c == 'B') {
                    ex = i, ey = j;
                    mp[i][j] = 3;
                } else {
                    if (c == '+') {
                        mp[i][j] = 1;
                    }
                }
            }
        }
    }
    cout << bfs() << "\n";
    return 0;
}