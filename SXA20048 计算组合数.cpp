#include <bits/stdc++.h>
using namespace std;

long long c[15][15];

signed main() {
    int m, n, i, j;
    cin >> m >> n;
    for (i = 0; i <= m; i++) {
        c[i][0] = 1, c[i][i] = 1;
        for (j = 1; j < i; j++) {
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
        }
    }
    cout << c[m][n] << "\n";
    return 0;
}
