#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 5;
int cr[N], cc[N], d1[N * 2], d2[N * 2], cn[N][N], x[100005], y[100005];
int n, k, i, j, ans = 0;
signed main() {
    cin >> n >> k;
    for (i = 1; i <= k; i++) {
        cin >> x[i] >> y[i];
        cr[x[i]]++, cc[y[i]]++;
        d1[x[i] - y[i] + n]++, d2[x[i] + y[i]]++;
        cn[x[i]][y[i]]++;
    }
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            int s = cr[i] + cc[j] + d1[i - j + n] + d2[i + j] - 3 * cn[i][j];
            if (s == k) {
                ans++;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
