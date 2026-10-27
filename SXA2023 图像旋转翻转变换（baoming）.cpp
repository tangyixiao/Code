#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 5;
int m, n, i, j;
int a[N][N], b[N][N];
signed main() {
    cin >> m >> n;
    for (i = 1; i <= m; i++) {
        for (j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    char op;
    cin >> op;
    if (op == 'A') {
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= m; j++) {
                cout << a[m - j + 1][i] << " ";
            }
            cout << "\n";
        }
    } else if (op == 'B') {
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= m; j++) {
                cout << a[j][n - i + 1] << " ";
            }
            cout << "\n";
        }
    } else if (op == 'C') {
        for (i = 1; i <= m; i++) {
            for (j = 1; j <= n; j++) {
                cout << a[i][n - j + 1] << " ";
            }
            cout << "\n";
        }
    } else {
        for (i = 1; i <= m; i++) {
            for (j = 1; j <= n; j++) {
                cout << a[m - i + 1][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
