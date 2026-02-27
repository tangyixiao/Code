#include <bits/stdc++.h>
using namespace std;
const int N = 10;
int n, cnt, now, x, y, a[N][N], dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
signed main() {
    cin >> n;
    x = y = 1;
    a[x][y] = cnt = 1;
    for (; cnt < n * n; cnt++) {
        int nx = x + dx[now], ny = y + dy[now];
        if (nx < 1 || nx > n || ny < 1 || ny > n || a[nx][ny]) {
            now = (now + 1) % 4;
            nx = x + dx[now], ny = y + dy[now];
        }
        x = nx, y = ny;
        a[nx][ny] = cnt + 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%3d", a[j][i]);
        }
        cout << "\n";
    }
    return 0;
}