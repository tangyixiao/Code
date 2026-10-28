#include <bits/stdc++.h>
using namespace std;

const int N = 105;
int k, f[N][N], len[N];

signed main() {
    cin >> k;
    f[1][1] = 1;
    len[1] = 1;
    if (k >= 2) {
        f[2][1] = 1;
        len[2] = 1;
    }
    for (int i = 3; i <= k; i++) {
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
    for (int j = len[k]; j >= 1; j--) {
        cout << f[k][j];
    }
    cout << "\n";
    return 0;
}
