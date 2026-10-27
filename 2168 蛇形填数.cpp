#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;
int n, a[N][N];

signed main() {
    cin >> n;
    int x = 1, y = 1, d = 0, t = 1;
    a[1][1] = 1;
    for (; t < n * n;) {
        int nx = x, ny = y;
        if (d == 0) {
            ny = y + 1;
        }
        if (d == 1) {
            nx = x + 1;
        }
        if (d == 2) {
            ny = y - 1;
        }
        if (d == 3) {
            nx = x - 1;
        }
        if (nx < 1 || nx > n || ny < 1 || ny > n || a[nx][ny]) {
            d = (d + 1) % 4;
            continue;
        }
        x = nx, y = ny, a[x][y] = ++t;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (j < n) {
                printf("%-4d", a[i][j]);
            } else {
                printf("%d", a[i][j]);
            }
        }
        printf("\n");
    }
    return 0;
}
