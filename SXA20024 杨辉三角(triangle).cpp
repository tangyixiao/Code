#include <bits/stdc++.h>
using namespace std;

int i, j;
long long c[15][15];

signed main() {
    cin >> i >> j;
    for (int a = 1; a <= i; a++) {
        c[a][1] = 1, c[a][a] = 1;
        for (int b = 2; b < a; b++) {
            c[a][b] = c[a - 1][b - 1] + c[a - 1][b];
        }
    }
    cout << c[i][j] << "\n";
    return 0;
}
