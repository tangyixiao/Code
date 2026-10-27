#include <bits/stdc++.h>
using namespace std;

const int N = 105, M = 1050;
int n, m, cnt, ans;
int v[M], num[M], bad[N], f[2][M][M];
char s[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> (s + 1);
        int b = 0;
        for (int j = 1; j <= m; j++) {
            if (s[j] == 'H') {
                b |= 1 << (j - 1);
            }
        }
        bad[i] = b;
    }
    for (int k = 0; k < (1 << m); k++) {
        if ((k & (k << 1)) || (k & (k << 2))) {
            continue;
        }
        v[++cnt] = k;
        num[cnt] = __builtin_popcount(k);
    }
    for (int i = 1; i <= cnt; i++) {
        for (int j = 1; j <= cnt; j++) {
            f[0][i][j] = -1e9;
            f[1][i][j] = -1e9;
        }
    }
    f[0][1][1] = 0;
    for (int i = 1; i <= n; i++) {
        int c0 = i & 1, c1 = (i + 1) & 1;
        for (int j = 1; j <= cnt; j++) {
            for (int k = 1; k <= cnt; k++) {
                f[c0][j][k] = -1e9;
            }
        }
        for (int j = 1; j <= cnt; j++) {
            if (v[j] & bad[i]) {
                continue;
            }
            for (int k = 1; k <= cnt; k++) {
                if (v[j] & v[k]) {
                    continue;
                }
                for (int l = 1; l <= cnt; l++) {
                    if (f[c1][k][l] < 0) {
                        continue;
                    }
                    if (v[j] & v[l]) {
                        continue;
                    }
                    int nv = f[c1][k][l] + num[j];
                    if (nv > f[c0][j][k]) {
                        f[c0][j][k] = nv;
                    }
                }
            }
        }
    }
    for (int j = 1; j <= cnt; j++) {
        for (int k = 1; k <= cnt; k++) {
            if (f[n & 1][j][k] > ans) {
                ans = f[n & 1][j][k];
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
