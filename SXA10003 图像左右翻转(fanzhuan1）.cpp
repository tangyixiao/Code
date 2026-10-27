#include <bits/stdc++.h>
using namespace std;

int a[105][105];

signed main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= 1; j--) {
            if (j < m) {
                cout << " ";
            }
            cout << a[i][j];
        }
        cout << "\n";
    }
    return 0;
}
