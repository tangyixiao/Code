#pragma G++ optimize("O3", "unroll-loops", "omit-frame-pointer", "inline")
#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n, m, s, x, y, dep[N], fa[N][22], lg[N];
vector<int> v[N];
void dfs(int u, int last) {
    dep[u] = dep[last] + 1;
    fa[u][0] = last;
    for (int i = 1; (1 << i) <= dep[u]; i++) {
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
    }
    for (int i = 0; i < v[u].size(); i++) {
        if (v[u][i] ^ last) {
            dfs(v[u][i], u);
        }
    }
    return;
}
int LCA(int x, int y) {
    if (dep[x] < dep[y]) {
        swap(x, y);
    }
    while (dep[x] > dep[y]) {
        x = fa[x][lg[dep[x] - dep[y]] - 1];
    }
    if (x == y) {
        return x;
    }
    for (int k = lg[dep[x]]; k >= 0; k--) {
        if (fa[x][k] ^ fa[y][k]) {
            x = fa[x][k], y = fa[y][k];
        }
    }
    return fa[x][0];
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> s;
    for (int i = 1; i <= n; i++) {
        lg[i] = lg[i - 1];
        if (i == 1 << lg[i - 1]) {
            lg[i]++;
        }
    }
    for (int i = 1; i <= n - 1; i++) {
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(s, 0);
    for (int i = 1; i <= m; i++) {
        cin >> x >> y;
        cout << LCA(x, y) << "\n";
    }
    return 0;
}