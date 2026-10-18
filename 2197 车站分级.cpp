#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
const int M = 1.2e6 + 5;
const int P = 1e5 + 5;
int n, m, hd[N], ed[M], nx[M], deg[N], d[N], l[N], r[N], len[N], of[N], sp[P], q[N], ec;

inline void add(int u, int v) {
    ed[ec] = v;
    nx[ec] = hd[u];
    hd[u] = ec++;
}

inline void input() {
    cin >> n >> m;
    for (int i = 0; i <= n + m; ++i) {
        hd[i] = -1;
        deg[i] = 0;
    }
    ec = 0;
    int c = 0;
    for (int i = 1; i <= m; ++i) {
        cin >> len[i];
        of[i] = c;
        l[i] = 1e9;
        r[i] = 0;
        for (int j = 0; j < len[i]; ++j) {
            cin >> sp[c + j];
            l[i] = min(l[i], sp[c + j]);
            r[i] = max(r[i], sp[c + j]);
        }
        c += len[i];
    }
}

inline void solve() {
    for (int i = 1; i <= m; ++i) {
        int u = n + i, c = 0;
        for (int j = l[i]; j <= r[i]; ++j) {
            int t = 0;
            for (int k = 0; k < len[i]; ++k) {
                if (sp[of[i] + k] == j) {
                    t = 1;
                    break;
                }
            }
            if (t) {
                add(u, j);
                ++deg[j];
            } else {
                add(j, u);
                ++deg[u];
            }
        }
    }
    int h = 0, t = 0;
    for (int i = 1; i <= n + m; ++i) {
        if (!deg[i]) {
            q[t++] = i;
        }
    }
    for (; h < t; ++h) {
        int x = q[h];
        for (int i = hd[x]; i != -1; i = nx[i]) {
            int y = ed[i];
            d[y] = max(d[y], d[x] + (y <= n));
            if (!--deg[y]) {
                q[t++] = y;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans = max(ans, d[i]);
    }
    cout << ans + 1 << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}