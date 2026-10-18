#include <bits/stdc++.h>
using namespace std;

const int N = 32e3 + 5, M = 1e3 + 5;
int n, m, v[M], p[M], q[M], nxt[M][3], nc[M], f[N];

inline void input() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> v[i] >> p[i] >> q[i];
        if (q[i]) {
            nxt[q[i]][nc[q[i]]++] = i;
        }
    }
}

inline void solve() {
    for (int i = 1; i <= m; i++) {
        if (q[i]) {
            continue;
        }
        int c = 1, w[8], val[8];
        w[0] = v[i], val[0] = v[i] * p[i];
        for (int a = 0; a < nc[i]; a++) {
            int k = c, j = nxt[i][a];
            for (int b = 0; b < c; b++) {
                w[k] = w[b] + v[j], val[k] = val[b] + v[j] * p[j];
                k++;
            }
            c = k;
        }
        for (int j = n; j >= 0; j--) {
            for (int a = 0; a < c; a++) {
                if (j >= w[a] && f[j - w[a]] + val[a] > f[j]) {
                    f[j] = f[j - w[a]] + val[a];
                }
            }
        }
    }
    cout << f[n] << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
