#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 5;
int n, i, j, ans, c;
char g[N][N];
signed main() {
    cin >> n;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            cin >> g[i][j];
        }
    }
    for (i = 1; i <= n; i++) {
        c = 0;
        for (j = 1; j <= n; j++) {
            if (g[i][j] == 'C') {
                c++;
            }
        }
        ans += c * (c - 1) / 2;
        c = 0;
        for (j = 1; j <= n; j++) {
            if (g[j][i] == 'C') {
                c++;
            }
        }
        ans += c * (c - 1) / 2;
    }
    cout << ans << "\n";
    return 0;
}
