#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;

int n, w[N][N], d[N], e[N], path[N];

inline void input() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> w[i][j];
        }
    }
    return;
}

inline void solve() {
    for (int i = 1; i <= n; ++i) {
        d[i] = e[i] = (1 << 29);
    }
    d[1] = 0, e[n] = 0;
    for (int t = 1; t <= n; ++t) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (i == j || w[i][j] < 1) {
                    continue;
                }
                d[j] = min(d[j], d[i] + w[i][j]);
            }
        }
    }
    for (int t = 1; t <= n; ++t) {
        for (int j = 1; j <= n; ++j) {
            for (int i = 1; i <= n; ++i) {
                if (i == j || w[i][j] < 1) {
                    continue;
                }
                e[i] = min(e[i], w[i][j] + e[j]);
            }
        }
    }
    cout << "minlong=" << d[n] << "\n";
    int k = 0, cur = 1;
    path[k++] = 1;
    while (cur != n) {
        for (int j = cur + 1; j <= n; ++j) {
            if (w[cur][j] > 0 && w[cur][j] + e[j] == e[cur]) {
                path[k++] = j, cur = j;
                break;
            }
        }
    }
    for (int i = 0; i < k; ++i) {
        cout << path[i] << (i + 1 < k ? " " : "\n");
    }
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    solve();
    return 0;
}
