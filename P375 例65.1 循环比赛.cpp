#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int a[N][N];

signed main() {
    int m;
    cin >> m;
    int n = 1 << m;
    for (int j = 1; j <= n; j++) {
        a[1][j] = j;
    }
    for (int k = 1; k <= m; k++) {
        int t = 1 << (k - 1);
        for (int i = 1; i <= t; i++) {
            for (int j = 1; j <= t; j++) {
                a[i + t][j] = a[i][j] + t;
                a[i][j + t] = a[i][j] + t;
                a[i + t][j + t] = a[i][j];
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (j > 1) {
                cout << " ";
            }
            cout << a[i][j];
        }
        cout << "\n";
    }
    return 0;
}
