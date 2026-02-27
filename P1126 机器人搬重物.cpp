#include <bits/stdc++.h>
using namespace std;
const int N = 65, Nto = 5, dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
struct node {
    int x, y, st, to;
    bool operator<(const node &rhs) const { return st > rhs.st; }
};
int n, m, sx, sy, ex, ey;
bool mp[N][N], tmp[N][N], vis[N][N][Nto];
char toword;
priority_queue<node> q;
map<char, int> towards;
inline void init() {
    towards['E'] = 0, towards['S'] = 1, towards['W'] = 2, towards['N'] = 3;
    return;
}
inline void bfs() {
    q.push({sx, sy, 0, towards[toword]});
    vis[sx][sy][towards[toword]] = true;
    for (; !q.empty();) {
        auto [x, y, st, to] = q.top();
        q.pop();
        if (x == ex && y == ey) {
            cout << st;
            return;
        }
        for (int i = 1, nx, ny; i <= 3; i++) {
            nx = x + dx[to] * i, ny = y + dy[to] * i;
            if (mp[nx][ny]) {
                break;
            }
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && !vis[nx][ny][to]) {
                vis[nx][ny][to] = true;
                q.push({nx, ny, st + 1, to});
            }
        }
        int turn_left = (to + 1) % 4, turn_right = (to + 3) % 4;
        if (!vis[x][y][turn_left]) {
            vis[x][y][turn_left] = true;
            q.push({x, y, st + 1, turn_left});
        }
        if (!vis[x][y][turn_right]) {
            vis[x][y][turn_right] = true;
            q.push({x, y, st + 1, turn_right});
        }
    }
    cout << "-1";
    return;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> tmp[i][j];
            if (tmp[i][j]) {
                mp[i][j] = mp[i + 1][j] = mp[i][j + 1] = mp[i + 1][j + 1] = true;
            }
        }
    }
    cin >> sx >> sy >> ex >> ey >> toword;
    n++, m++, sx++, sy++, ex++, ey++;
    for (int i = 1; i <= n; i++) {
        mp[i][1] = mp[i][m] = mp[i][0] = mp[i][m + 1] = true;
    }
    for (int i = 1; i <= m; i++) {
        mp[1][i] = mp[n][i] = mp[0][i] = mp[n + 1][i] = true;
    }
    bfs();
    return 0;
}