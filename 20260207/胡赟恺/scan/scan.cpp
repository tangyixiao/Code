#include <bits/stdc++.h>
using namespace std;
int n, m, h, C;
int v[55][55][55];
int a[55][55][55];
struct node {
    int x;
    int y;
    int z;
};
int dx[] = {-1, 1, 0, 0, 0, 0};
int dy[] = {0, 0, -1, 1, 0, 0};
int dz[] = {0, 0, 0, 0, -1, 1};
void bfs(int sx, int sy, int sz) {
    queue<node> q;
    q.push((node){sx, sy, sz});
    v[sx][sy][sz] = 1;
    while (!q.empty()) {
        node t = q.front();
        q.pop();
        for (int i = 0; i < 6; i++) {
            int xx = t.x + dx[i], yy = t.y + dy[i], zz = t.z + dz[i];
            if (xx < 1 || xx > n || yy < 1 || yy > m || zz < 1 || zz > h)
                continue;
            if (v[xx][yy][zz] || abs(a[xx][yy][zz] - a[t.x][t.y][t.z]) > C)
                continue;
            v[xx][yy][zz] = 1;
            q.push((node){xx, yy, zz});
        }
    }
}
signed main() {
    freopen("scan.in", "r", stdin);
    freopen("scan.out", "w", stdout);
    cin >> n >> m >> h;
    cin >> C;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = 1; k <= h; k++) {
                cin >> a[i][j][k];
            }
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = 1; k <= h; k++) {
                if (!v[i][j][k]) {
                    cnt++;
                    bfs(i, j, k);
                }
            }
        }
    }
    cout << cnt << '\n';
    fclose(stdin);
    fclose(stdout);
    return 0;
}
