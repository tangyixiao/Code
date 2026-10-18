#include <bits/stdc++.h>
using namespace std;

const int N = 2e2 + 5;

int n, w[N], g[N][N], f[N], nxt[N];

inline void input() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> w[i];
    }
    int x, y;
    while (cin >> x >> y && (x || y)) {
        g[x][y] = 1;
    }
    return;
}

inline void solve() {
    int mx = 0, pos = 0;
    for (int i = 1; i <= n; ++i) {
        f[i] = w[i];
        for (int j = 1; j < i; ++j) {
            if (g[j][i] && f[j] + w[i] > f[i]) {
                f[i] = f[j] + w[i], nxt[i] = j;
            }
        }
        if (f[i] > mx) {
            mx = f[i], pos = i;
        }
    }
    int s[N], k = 0;
    for (int i = pos; i; i = nxt[i]) {
        s[k++] = i;
    }
    for (int i = k - 1; i >= 0; --i) {
        cout << s[i] << (i ? "-" : "\n");
    }
    cout << mx << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    solve();
    return 0;
}
