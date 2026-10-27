#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;
int n, m, a[N][N], ans;

inline void dfs(int x, int y) {
    if (x < 1 || x > n || y < 1 || y > m || a[x][y] == 0) {
        return;
    }
    a[x][y] = 0;
    dfs(x - 1, y);
    dfs(x + 1, y);
    dfs(x, y - 1);
    dfs(x, y + 1);
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    int c;
    int i = 1, j = 1;
    for (; i <= n;) {
        c = cin.get();
        if (c >= '0' && c <= '9') {
            a[i][j] = c - '0';
            j++;
            if (j > m) {
                j = 1;
                i++;
            }
        }
        if (c == EOF) {
            break;
        }
    }
    for (int x = 1; x <= n; x++) {
        for (int y = 1; y <= m; y++) {
            if (a[x][y] != 0) {
                ans++;
                dfs(x, y);
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
