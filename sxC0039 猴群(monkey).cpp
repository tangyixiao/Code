#include <bits/stdc++.h>
using namespace std;

int m, n, i, j, ans;
char a[105][105];

void dfs(int x, int y) {
    if (x < 1 || x > m || y < 1 || y > n) {
        return;
    }
    if (a[x][y] == '0') {
        return;
    }
    a[x][y] = '0';
    dfs(x - 1, y);
    dfs(x + 1, y);
    dfs(x, y - 1);
    dfs(x, y + 1);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> m >> n;
    for (i = 1; i <= m; i++) {
        for (j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    ans = 0;
    for (i = 1; i <= m; i++) {
        for (j = 1; j <= n; j++) {
            if (a[i][j] != '0') {
                ans++;
                dfs(i, j);
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
