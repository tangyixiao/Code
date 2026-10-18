#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;

int a[N][N], n, m;

signed main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            cout << a[i][j] << (i + 1 == n ? "\n" : " ");
        }
    }
    return 0;
}
