#include <bits/stdc++.h>
using namespace std;
int n, cnt, i, j;
int vis[10][10], px[50], py[50];
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
void dfs(int x, int y, int d) {
    if (x == n && y == n) {
        cnt++;
        cout << cnt << ":" << px[0] << "," << py[0];
        for (i = 1; i <= d; i++) {
            cout << "->" << px[i] << "," << py[i];
        }
        cout << "\n";
        return;
    }
    for (int k = 0; k < 4; k++) {
        int nx = x + dx[k], ny = y + dy[k];
        if (nx >= 1 && nx <= n && ny >= 1 && ny <= n && vis[nx][ny] == 0) {
            vis[nx][ny] = 1;
            px[d + 1] = nx;
            py[d + 1] = ny;
            dfs(nx, ny, d + 1);
            vis[nx][ny] = 0;
        }
    }
}
signed main() {
    cin >> n;
    px[0] = 1;
    py[0] = 1;
    vis[1][1] = 1;
    dfs(1, 1, 0);
    return 0;
}
