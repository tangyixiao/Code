#include <bits/stdc++.h>
using namespace std;
int n, m, parent[100010], u, v, w, q;
inline int find(int x) {
    if (x == parent[x])
        return x;
    return parent[x] = find(parent[x]);
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
        parent[i] = i;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        parent[find(y)] = find(x);
    }
    for (int i = 1; i <= q; i++) {
        cin >> u >> v;
        if (find(u) == find(v))
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}