#include <bits/stdc++.h>
using namespace std;
const int N = 514;
int ar[N], n, f[N][N];
inline void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> ar[i];
        ar[n + i] = ar[i];
    }
    for (int len = 2; len <= n; len++) {
        for (int l = 1; l <= n * 2 - len + 1; l++) {
            int r = l + len - 1;
            for (int i = l + 1; i <= r; i++) {
                f[l][r] = max(f[l][r], f[l][i - 1] + f[i][r] + ar[l] * ar[i] * ar[r + 1]);
            }
        }
    }
    int res = 0;
    for (int i = 1; i <= n; i++)
        res = max(res, f[i][i + n - 1]);
    cout << res << "\n";
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}