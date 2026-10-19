#include <bits/stdc++.h>
using namespace std;

int x, y, z, n, m, ans;

inline void input() {
    cin >> x >> y >> z >> n >> m;
}

inline void solve() {
    for (int i = 0; i <= m; i++) {
        for (int j = 0; i + j <= m; j++) {
            int k = m - i - j;
            if (k % z != 0) {
                continue;
            }
            if (i * x + j * y + k / z == n) {
                ans++;
            }
        }
    }
    cout << ans << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}