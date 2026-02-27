#include <bits/stdc++.h>
using namespace std;
int r, c, maxn, nx, ny, f[114][114], a[114][114], dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
int dfs(int x, int y) {
    if (f[x][y])
        return f[x][y];
    f[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        nx = x + dx[i], ny = y + dy[i];
        if (nx >= 1 && nx <= r && ny >= 1 && ny <= c) {
            if (a[nx][ny] < a[x][y]) {
                f[x][y] = max(f[x][y], dfs(nx, ny) + 1);
            }
        }
    }
    return f[x][y];
}
int main() {
    scanf("%d%d", &r, &c);
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            maxn = max(maxn, dfs(i, j));
        }
    }
    printf("%d", maxn);
    return 0;
}