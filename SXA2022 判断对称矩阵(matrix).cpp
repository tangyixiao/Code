#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;
int n, a[N][N], f;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    f = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j] != a[j][i]) {
                f = 0;
            }
        }
    }
    cout << (f ? "YES" : "NO") << "\n";
    return 0;
}
