#include <bits/stdc++.h>
using namespace std;
const int N = 1e1 + 5;
int a[N][N], n, i, j, k, x = 1, y = 1, d = 0;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
signed main() {
    cin >> n;
    a[1][1] = 1;
    for (k = 2; k <= n * n; k++) {
        int nx = x + dx[d], ny = y + dy[d];
        if (nx < 1 || nx > n || ny < 1 || ny > n || a[nx][ny] != 0) {
            d = (d + 1) % 4;
            nx = x + dx[d], ny = y + dy[d];
        }
        x = nx, y = ny, a[x][y] = k;
    }
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            cout << setw(3) << a[i][j];
        }
        cout << "\n";
    }
    return 0;
}
