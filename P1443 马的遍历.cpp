#include <bits/stdc++.h>
using namespace std;
struct node {
    int x, y;
};
queue<node> q;
int n, m, sx, sy, nx, ny, a[514][514], dx[10] = {-2, -2, -1, 1, -1, 1, 2, 2},
                                       dy[10] = {-1, 1, -2, -2, 2, 2, -1, 1};
void bfs() {
    q.push({sx, sy});
    a[sx][sy] = 0;
    while (!q.empty()) {
        node now = q.front();
        q.pop();
        for (int i = 0; i < 8; i++) {
            nx = now.x + dx[i], ny = now.y + dy[i];
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && a[nx][ny] == -1) {
                q.push({nx, ny});
                a[nx][ny] = a[now.x][now.y] + 1;
            }
        }
    }
}
int main() {
    scanf("%d%d%d%d", &n, &m, &sx, &sy);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            a[i][j] = -1;
        }
    }
    bfs();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}