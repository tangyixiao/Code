#include <bits/stdc++.h>
using namespace std;

int n, i, j, plen;
char buf[2005];
int a[32][32], v[32][32], px[505], py[505];
int mx[4] = {0, -1, 0, 1};
int my[4] = {-1, 0, 1, 0};

int dfs(int x, int y, int dep) {
    px[dep] = x;
    py[dep] = y;
    if (x == n && y == n) {
        plen = dep + 1;
        return 1;
    }
    v[x][y] = 1;
    for (int k = 0; k < 4; k++) {
        int nx = x + mx[k];
        int ny = y + my[k];
        if (nx >= 1 && nx <= n && ny >= 1 && ny <= n && a[nx][ny] == 0 && v[nx][ny] == 0) {
            if (dfs(nx, ny, dep + 1)) {
                return 1;
            }
        }
    }
    v[x][y] = 0;
    return 0;
}

signed main() {
    int tot = 0, c;
    while ((c = getchar()) != EOF) {
        if (tot < 2000) {
            buf[tot] = (char)c;
        }
        tot++;
    }
    int p = 0;
    while (p < tot && p < 2000 && (buf[p] < '0' || buf[p] > '9')) {
        p++;
    }
    n = 0;
    while (p < tot && p < 2000 && buf[p] >= '0' && buf[p] <= '9') {
        n = n * 10 + (buf[p] - '0');
        p++;
    }
    int cnt = 0;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            while (p < tot && p < 2000 && (buf[p] < '0' || buf[p] > '9')) {
                p++;
            }
            if (p < tot && p < 2000) {
                a[i][j] = buf[p] - '0';
                p++;
            }
            cnt++;
        }
    }
    plen = 0;
    v[1][1] = 1;
    dfs(1, 1, 0);
    for (i = 0; i < plen; i++) {
        if (i > 0) {
            printf("->");
        }
        printf("(%d,%d)", px[i], py[i]);
    }
    printf("\n");
    return 0;
}
