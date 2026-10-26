#include <bits/stdc++.h>
using namespace std;

const int N = 4e2 + 5;
int n, m, i, j;
int a[N], b[5];
int f[45][45][45][45];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (i = 1; i <= m; i++) {
        int x;
        cin >> x;
        b[x]++;
    }
    f[0][0][0][0] = a[1];
    for (int c1 = 0; c1 <= b[1]; c1++) {
        for (int c2 = 0; c2 <= b[2]; c2++) {
            for (int c3 = 0; c3 <= b[3]; c3++) {
                for (int c4 = 0; c4 <= b[4]; c4++) {
                    if (c1 == 0 && c2 == 0 && c3 == 0 && c4 == 0) {
                        continue;
                    }
                    int pos = 1 + c1 + 2 * c2 + 3 * c3 + 4 * c4;
                    int best = -1;
                    if (c1 > 0) {
                        best = max(best, f[c1 - 1][c2][c3][c4]);
                    }
                    if (c2 > 0) {
                        best = max(best, f[c1][c2 - 1][c3][c4]);
                    }
                    if (c3 > 0) {
                        best = max(best, f[c1][c2][c3 - 1][c4]);
                    }
                    if (c4 > 0) {
                        best = max(best, f[c1][c2][c3][c4 - 1]);
                    }
                    f[c1][c2][c3][c4] = best + a[pos];
                }
            }
        }
    }
    cout << f[b[1]][b[2]][b[3]][b[4]] << "\n";
    return 0;
}
