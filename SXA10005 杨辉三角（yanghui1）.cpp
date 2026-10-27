#include <bits/stdc++.h>
using namespace std;
long long c[15][15];
int n, i, j;
signed main() {
    cin >> n;
    for (i = 1; i <= n; i++) {
        c[i][1] = 1, c[i][i] = 1;
        for (j = 2; j < i; j++) {
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
        }
    }
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= i; j++) {
            cout << setw(6) << c[i][j];
        }
        cout << "\n";
    }
    return 0;
}
