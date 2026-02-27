#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 35;
int n, m, f[N][N];
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    f[0][1] = 1;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (j == 1) {
                f[i][j] = f[i - 1][n] + f[i - 1][2];
            } else {
                if (j == n) {
                    f[i][j] = f[i - 1][1] + f[i - 1][n - 1];
                } else {
                    f[i][j] = f[i - 1][j - 1] + f[i - 1][j + 1];
                }
            }
        }
    }
    cout << f[m][1] << "\n";
    return 0;
}