#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
struct E {
    int u, v, w;
} e[N];
int n, m, fa[N];

inline int fd(int t) {
    return fa[t] == t ? t : fa[t] = fd(fa[t]);
}

inline void input() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
    }
    for (int i = 1; i <= m; i++) {
        cin >> e[i].u >> e[i].v >> e[i].w;
        if (e[i].u > e[i].v) {
            swap(e[i].u, e[i].v);
        }
    }
    sort(e + 1, e + m + 1, [](const E &a, const E &b) { return a.w < b.w; });
}

inline void solve() {
    int cnt = 0;
    for (int i = 1; i <= m && cnt < n - 1; i++) {
        int x = fd(e[i].u), y = fd(e[i].v);
        if (x != y) {
            fa[x] = y, e[++cnt] = e[i];
        }
    }
    sort(e + 1, e + cnt + 1, [](const E &a, const E &b) { return a.u != b.u ? a.u < b.u : a.v < b.v; });
    for (int i = 1; i <= cnt; i++) {
        cout << e[i].u << " " << e[i].v << "\n";
    }
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
