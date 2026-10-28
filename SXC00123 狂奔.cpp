#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5, M = 1e5 + 5;
int n, m, ec, ans;
long long s;
int head[N], nxt[M], to[M], w[M], din[N], q[N];
long long f[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (; t--;) {
        cin >> n >> m >> s;
        ec = 0;
        for (int i = 0; i <= n; i++) {
            head[i] = 0, din[i] = 0, f[i] = 0;
        }
        for (int i = 1; i <= m; i++) {
            int u, v, c;
            cin >> u >> v >> c;
            nxt[++ec] = head[u], to[ec] = v, w[ec] = c, head[u] = ec;
            din[v]++;
        }
        int h = 0, tl = 0;
        for (int i = 1; i <= n; i++) {
            if (!din[i]) {
                q[tl++] = i;
            }
        }
        for (; h < tl;) {
            int u = q[h];
            h++;
            for (int e = head[u]; e; e = nxt[e]) {
                int v = to[e];
                if (f[u] + w[e] > f[v]) {
                    f[v] = f[u] + w[e];
                }
                if (--din[v] == 0) {
                    q[tl++] = v;
                }
            }
        }
        int yes = 0;
        if (tl < n) {
            yes = 1;
        }
        for (int i = 1; i <= n; i++) {
            if (f[i] >= s) {
                yes = 1;
            }
        }
        if (yes) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}
