#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;
int n, m, x, y, z;
int g[N][N];

signed main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> x >> y >> z;
        g[x][y] = z;
    }
    for (int i = 1; i <= n; i++) {
        cout << i << ":" << "\n";
        for (int j = 1; j <= n; j++) {
            if (g[i][j]) {
                cout << j << " " << g[i][j] << "\n";
            }
        }
    }
    return 0;
}
