#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 100005;

vector<int> G[N];
int fa[N];
ll a[N];

void dfs(int u, int f) {
    fa[u] = f;
    for (int i = 0; i < G[u].size(); i++)
        if (G[u][i] != f)
            dfs(G[u][i], u);

}

void add_subtree(int u, int f, ll v) {
    a[u] += v;
    for (int i = 0; i < G[u].size(); i++)
        if (G[u][i] != f)
            add_subtree(G[u][i], u, v);
}

int main() {
    freopen("P3178.in", "r", stdin);
    freopen("P3178.ans", "w", stdout);
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1, 0);
    while (m--) {
        int op, x;
        ll v;
        scanf("%d%d", &op, &x);
        if (op == 1) {
            scanf("%lld", &v);
            a[x] += v;
        } else if (op == 2) {
            scanf("%lld", &v);
            add_subtree(x, fa[x], v);
        } else {
            ll ans = 0;
            for (int u = x; u; u = fa[u])
                ans += a[u];
            printf("%lld\n", ans);
        }
    }
    return 0;
}