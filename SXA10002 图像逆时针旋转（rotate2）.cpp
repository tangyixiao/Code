#include <bits/stdc++.h>
using namespace std;

const int N = 105;
int n, m, a[N][N];

signed main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cout << a[j][m - i + 1];
            if (j < n) {
                cout << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}
