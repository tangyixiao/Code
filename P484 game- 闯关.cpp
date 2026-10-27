#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;
const int T = 1e2 + 5;
const long long NEG = -1e18;

int n, m, t, ec, on;
int he[N], nx[N * 3], to[N * 3], ind[N], ord[N], que[N];
long long a[N][T], f[N], d[N], ans;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> t;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= t; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        ec++, to[ec] = v, nx[ec] = he[u], he[u] = ec, ind[v]++;
    }
    int hd = 1, tl = 0;
    for (int i = 1; i <= n; i++) {
        if (!ind[i]) {
            que[++tl] = i;
        }
    }
    for (; hd <= tl;) {
        int u = que[hd++];
        ord[++on] = u;
        for (int e = he[u]; e; e = nx[e]) {
            if (--ind[to[e]] == 0) {
                que[++tl] = to[e];
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        f[i] = NEG;
    }
    f[1] = 0;
    for (int j = 1; j <= t; j++) {
        for (int i = 1; i <= n; i++) {
            d[i] = f[i] + a[i][j];
        }
        for (int p = 1; p <= on; p++) {
            int u = ord[p];
            if (d[u] <= NEG / 2) {
                continue;
            }
            for (int e = he[u]; e; e = nx[e]) {
                if (d[u] + a[to[e]][j] > d[to[e]]) {
                    d[to[e]] = d[u] + a[to[e]][j];
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            f[i] = d[i];
        }
        if (f[n] > ans) {
            ans = f[n];
        }
    }
    cout << ans << "\n";
    return 0;
}
