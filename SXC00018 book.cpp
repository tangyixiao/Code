#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;
int n, k, m, ans;
int h[N], w[N], p[N];
int f[N][N];

bool cmp(int x, int y) {
    return h[x] < h[y];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> h[i] >> w[i];
        p[i] = i;
    }
    sort(p + 1, p + n + 1, cmp);
    m = n - k;
    ans = 1e9;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            f[i][j] = 1e9;
        }
    }
    for (int i = 1; i <= n; i++) {
        f[i][1] = 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 2; j <= m; j++) {
            for (int t = 1; t < i; t++) {
                if (f[t][j - 1] < 1e9) {
                    f[i][j] = min(f[i][j], f[t][j - 1] + abs(w[p[i]] - w[p[t]]));
                }
            }
        }
        ans = min(ans, f[i][m]);
    }
    cout << ans << "\n";
    return 0;
}
