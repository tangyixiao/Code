#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, m, fa[N];
struct e {
    int u, v, w;
} a[N];

inline int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

inline bool cmp(e x, e y) {
    return x.w < y.w;
}

inline void input() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        fa[i] = i;
    }
    for (int i = 1; i <= m; ++i) {
        cin >> a[i].u >> a[i].v >> a[i].w;
    }
}

inline void solve() {
    sort(a + 1, a + m + 1, cmp);
    int s = 0;
    for (int i = 1; i <= m; ++i) {
        s += a[i].w;
    }
    for (int i = 1; i <= m; ++i) {
        int x = find(a[i].u), y = find(a[i].v);
        if (x != y) {
            fa[x] = y, s -= a[i].w;
        }
    }
    cout << s << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}