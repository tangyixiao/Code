#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;

int n, m, fa[N], deg[N], odd[N], vis[N];

int find(int x) {
    if (fa[x] != x) {
        fa[x] = find(fa[x]);
    }
    return fa[x];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
    }
    for (int i = 1, a, b; i <= m; i++) {
        cin >> a >> b;
        deg[a]++, deg[b]++, fa[find(a)] = find(b);
    }
    for (int i = 1; i <= n; i++) {
        if (deg[i] & 1) {
            odd[find(i)]++;
        }
        if (deg[i] > 0) {
            vis[find(i)] = 1;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (fa[i] == i && vis[i]) {
            ans += odd[i] == 0 ? 1 : odd[i] / 2;
        }
    }
    cout << ans << "\n";
    return 0;
}
