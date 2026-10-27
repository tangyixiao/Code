#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;
int n, m, a[N][N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= 1; j--) {
            cout << a[i][j];
            if (j > 1) {
                cout << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}
