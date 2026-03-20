#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 5, M = 2e5 + 5;
int cnt, fa[N];
long long ans;
struct Edge {
    int u, v, w;
    bool operator<(const Edge &other) const {
        return w < other.w;
    }
} edges[M];
inline void init(int n) {
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
    }
    return;
}
inline int find(int x) {
    if (fa[x] != x) {
        fa[x] = find(fa[x]);
    }
    return fa[x];
}
inline bool unite(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) {
        return false;
    }
    fa[x] = y;
    return true;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }
    sort(edges + 1, edges + 1 + m);
    init(n);
    for (int i = 1; i <= m && cnt < n - 1; i++) {
        if (unite(edges[i].u, edges[i].v)) {
            ans += edges[i].w;
            cnt++;
        }
    }
    if (cnt == n - 1) {
        cout << ans << "\n";
    } else {
        cout << "orz\n";
    }
    return 0;
}