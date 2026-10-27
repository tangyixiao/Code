#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5, INF = 1e9;

int n, w[N][N], d[N], e[N], path[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> w[i][j];
        }
    }
    for (int i = 1; i <= n; ++i) {
        d[i] = e[i] = INF;
    }
    d[1] = 0, e[n] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            if (w[i][j] > 0 && d[i] < INF) {
                d[j] = min(d[j], d[i] + w[i][j]);
            }
        }
    }
    for (int i = n - 1; i >= 1; --i) {
        for (int j = i + 1; j <= n; ++j) {
            if (w[i][j] > 0 && e[j] < INF) {
                e[i] = min(e[i], w[i][j] + e[j]);
            }
        }
    }
    cout << "minlong=" << e[1] << "\n";
    int k = 0, cur = 1;
    path[k++] = 1;
    for (; cur != n;) {
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
    return 0;
}
