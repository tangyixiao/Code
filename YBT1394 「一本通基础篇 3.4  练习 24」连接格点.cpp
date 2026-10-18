#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int m, n, fa[N], ans;

inline int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

inline void input() {
    cin >> m >> n;
    for (int i = 0; i < m * n; ++i) {
        fa[i] = i;
    }
}

inline void solve() {
    int x1, y1, x2, y2;
    while (cin >> x1 >> y1 >> x2 >> y2) {
        int u = (x1 - 1) * n + y1 - 1, v = (x2 - 1) * n + y2 - 1;
        fa[find(u)] = find(v);
    }
    for (int i = 0; i + 1 < m; ++i) {
        for (int j = 0; j < n; ++j) {
            int u = i * n + j, v = u + n;
            if (find(u) != find(v)) {
                fa[find(u)] = find(v), ans += 1;
            }
        }
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j + 1 < n; ++j) {
            int u = i * n + j, v = u + 1;
            if (find(u) != find(v)) {
                fa[find(u)] = find(v), ans += 2;
            }
        }
    }
    cout << ans << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}