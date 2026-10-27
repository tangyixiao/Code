#include <bits/stdc++.h>
using namespace std;

int n, m, cnt;
char a[105][105], b[105][105];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    cin >> m;
    for (int d = 1; d < m; d++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                b[i][j] = a[i][j];
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (a[i][j] != '.') {
                    continue;
                }
                for (int k = 0; k < 4; k++) {
                    int x = i + dx[k], y = j + dy[k];
                    if (x >= 1 && x <= n && y >= 1 && y <= n && a[x][y] == '@') {
                        b[i][j] = '@';
                    }
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                a[i][j] = b[i][j];
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j] == '@') {
                cnt++;
            }
        }
    }
    cout << cnt << "\n";
    return 0;
}
