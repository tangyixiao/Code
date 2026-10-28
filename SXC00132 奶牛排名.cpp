#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int n, m, x, y, ans;
bitset<N> r[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> x >> y;
        r[x][y] = 1;
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            if (r[i][k]) {
                r[i] |= r[k];
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (!r[i][j] && !r[j][i]) {
                ans++;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
