#include <bits/stdc++.h>
using namespace std;
int a[105][105], n, m, i, j;
signed main() {
    cin >> n >> m;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    for (i = 2; i < n; i++) {
        for (j = 2; j < m; j++) {
            if (a[i][j] > a[i - 1][j] && a[i][j] > a[i + 1][j] && a[i][j] > a[i][j - 1] && a[i][j] > a[i][j + 1]) {
                cout << a[i][j] << "\n";
            }
        }
    }
    return 0;
}
