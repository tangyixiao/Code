#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
const int M = 3e2 + 5;
int n, len[N], f[N][M];

signed main() {
    cin >> n;
    if (n <= 2) {
        cout << 1 << "\n";
        return 0;
    }
    f[1][1] = 1;
    len[1] = 1;
    f[2][1] = 1;
    len[2] = 1;
    for (int i = 3; i <= n; i++) {
        int L = max(len[i - 1], len[i - 2]);
        for (int j = 1; j <= L; j++) {
            f[i][j] = f[i - 1][j] + f[i - 2][j];
        }
        for (int j = 1; j <= L; j++) {
            f[i][j + 1] += f[i][j] / 10;
            f[i][j] %= 10;
        }
        len[i] = L;
        if (f[i][L + 1] > 0) {
            len[i] = L + 1;
        }
    }
    for (int j = len[n]; j >= 1; j--) {
        cout << f[n][j];
    }
    cout << "\n";
    return 0;
}
