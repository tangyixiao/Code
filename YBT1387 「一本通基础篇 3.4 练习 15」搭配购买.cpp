#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5, M = 1e4 + 5;
int n, m, w, fa[N], c[N], d[N], f[M];

inline int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

inline void input() {
    cin >> n >> m >> w;
    for (int i = 1; i <= n; ++i) {
        cin >> c[i] >> d[i];
        fa[i] = i;
    }
}

inline void solve() {
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        fa[find(u)] = find(v), fa[find(v)] = find(v);
    }
    for (int i = 1; i <= n; ++i) {
        if (find(i) != i) {
            c[find(i)] += c[i], d[find(i)] += d[i];
        }
    }
    for (int i = w; i >= 0; --i) {
        f[i] = 0;
        for (int j = 1; j <= n; ++j) {
            if (find(j) == j && c[j] <= i) {
                f[i] = max(f[i], f[i - c[j]] + d[j]);
            }
        }
    }
    cout << f[w] << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}