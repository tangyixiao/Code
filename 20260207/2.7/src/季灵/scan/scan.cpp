#include <bits/stdc++.h>
using namespace std;
const int N = 55;
int a[N][N][N], vis[N][N][N];
int l, w, h, m, cnt;
bool check(int x, int y, int z) {
    return x >= 1 && x <= l && y >= 1 && y <= w && z >= 1 && z <= h;
}
void dfs(int x, int y, int z) {
    int dx[6] = {1, -1, 0, 0, 0, 0};
    int dy[6] = {0, 0, 1, -1, 0, 0};
    int dz[6] = {0, 0, 0, 0, 1, -1};
    for (int i = 0; i < 6; i++) {
        int nx = x + dx[i], ny = y + dy[i], nz = z + dz[i];
        if (check(nx, ny, nz) && !vis[nx][ny][nz] && abs(a[x][y][z] - a[nx][ny][nz]) <= m) {
            vis[nx][ny][nz] = 1;
            dfs(nx, ny, nz);
        }
    }
}

int main() {
    freopen("scan.in", "r", stdin);
    freopen("scan.out", "w", stdout);
    cin >> l >> w >> h >> m;
    for (int x = 1; x <= l; x++)
        for (int y = 1; y <= w; y++)
            for (int z = 1; z <= h; z++)
                cin >> a[x][y][z];
    for (int x = 1; x <= l; x++)
        for (int y = 1; y <= w; y++)
            for (int z = 1; z <= h; z++)
                if (!vis[x][y][z]) {
                    cnt++;
                    vis[x][y][z] = 1;
                    dfs(x, y, z);
                }
    cout << cnt;
    return 0;
}