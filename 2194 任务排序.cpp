#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int n, m;
int hd[N], ed[N], nxt[N], deg[N], a[N];

inline void input() {
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        nxt[i] = hd[u];
        hd[u] = i;
        ed[i] = v;
        deg[v]++;
    }
}

inline void solve() {
    for (int i = 1; i <= n; ++i) {
        a[i] = 1;
    }
    int c = 0;
    for (; c < n; ++c) {
        int u = 0;
        for (int i = 1; i <= n; ++i) {
            if (a[i] && !deg[i]) {
                u = i;
                break;
            }
        }
        if (!u) {
            break;
        }
        a[u] = 0;
        cout << u << (c == n - 1 ? "\n" : " ");
        for (int i = hd[u]; i; i = nxt[i]) {
            if (!--deg[ed[i]]) {
                a[ed[i]] = 1;
            }
        }
    }
    return;
}

signed main() {
    input();
    solve();
    return 0;
}