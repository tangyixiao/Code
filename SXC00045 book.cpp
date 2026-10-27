#include <bits/stdc++.h>
using namespace std;

const int N = 105;
int n, k, m;
int h[N], w[N], p[N];
int f[N][N];

bool cmp(int x, int y) {
    return h[x] < h[y];
}

signed main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> h[i] >> w[i];
        p[i] = i;
    }
    sort(p + 1, p + n + 1, cmp);
    for (int i = 1; i <= n; i++) {
        h[i] = h[p[i]];
        w[i] = w[p[i]];
    }
    m = n - k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            f[i][j] = 1e9;
        }
    }
    for (int i = 1; i <= n; i++) {
        f[i][1] = 0;
        for (int j = 2; j <= m; j++) {
            for (int t = 1; t < i; t++) {
                if (f[t][j - 1] + abs(w[i] - w[t]) < f[i][j]) {
                    f[i][j] = f[t][j - 1] + abs(w[i] - w[t]);
                }
            }
        }
    }
    int ans = 1e9;
    for (int i = 1; i <= n; i++) {
        if (f[i][m] < ans) {
            ans = f[i][m];
        }
    }
    cout << ans << "\n";
    return 0;
}
