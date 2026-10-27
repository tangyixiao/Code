#include <bits/stdc++.h>
using namespace std;

int n, m, a[105][105];

signed main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= m; j++) {
            cout << a[i][j];
            if (j != m) {
                cout << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}
