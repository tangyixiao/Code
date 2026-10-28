#include <bits/stdc++.h>
using namespace std;

int a[15][15];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    int dr[4] = {0, 1, 0, -1}, dc[4] = {1, 0, -1, 0};
    int r = 1, c = 1, d = 0;
    for (int i = 1; i <= n * m; i++) {
        a[r][c] = i;
        int nr = r + dr[d], nc = c + dc[d];
        if (nr < 1 || nr > n || nc < 1 || nc > m || a[nr][nc]) {
            d = (d + 1) % 4;
            nr = r + dr[d];
            nc = c + dc[d];
        }
        r = nr;
        c = nc;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << setw(3) << a[i][j];
        }
        cout << "\n";
    }
    return 0;
}
