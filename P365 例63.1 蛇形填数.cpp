#include <bits/stdc++.h>
using namespace std;

const int N = 25;

int n, i, j, x, y, dir, cnt, tot;
int a[N][N];
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, -1, 0, 1};

signed main() {
    cin >> n;
    x = 1, y = n, dir = 0;
    for (tot = 1; tot <= n * n; tot++) {
        a[x][y] = tot;
        int nx = x + dx[dir], ny = y + dy[dir];
        if (nx < 1 || nx > n || ny < 1 || ny > n || a[nx][ny] != 0) {
            dir = (dir + 1) % 4;
            nx = x + dx[dir], ny = y + dy[dir];
        }
        x = nx, y = ny;
    }
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (j > 1) {
                cout << " ";
            }
            cout << a[i][j];
        }
        cout << "\n";
    }
    return 0;
}
