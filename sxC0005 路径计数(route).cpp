#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
const int MOD = 199997;

int n, i, j;
int f[N][N];

signed main() {
    cin >> n;
    for (i = 1; i <= n; i++) {
        f[i][1] = 1;
    }
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (i == 1 && j == 1) {
                f[i][j] = 1;
                continue;
            }
            if (i == 1) {
                f[i][j] = f[i][j - 1] % MOD;
            } else if (j == 1) {
                f[i][j] = f[i - 1][j] % MOD;
            } else {
                f[i][j] = (f[i - 1][j] + f[i][j - 1]) % MOD;
            }
        }
    }
    cout << f[n][n] << "\n";
    return 0;
}
