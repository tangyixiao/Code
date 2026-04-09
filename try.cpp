#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 8;
const int INF = 0x3f3f3f3f;
int dsu[MAXN], c[MAXN];
int n, m, dis[MAXN], res;
bool vis[MAXN];
struct node {
    int u, v, w;
    bool operator<(const node &rhs) const { return w < rhs.w; }
};
vector<node> ed;
int find(int u) { return (dsu[u] == u ? u : dsu[u] = find(dsu[u])); }
void unite(int u, int v) { dsu[find(u)] = find(v); }
int kruskal() {
    int ret = 0, cnt = 0;
    for (auto [u, v, w] : ed) {
        if (find(u) != find(v))
            ret += w, cnt++, unite(u, v);
        if (cnt == n - 1)
            break;
    }
    return ret;
}
int main() {
    cin >> n >> m;
    int mn = INF;
    for (int i = 1; i <= n; i++)
        cin >> c[i], mn = min(mn, c[i]);
    for (int i = 1, u, v, w; i <= m; i++)
        cin >> u >> v >> w, ed.push_back({u, v, w * 2 + c[u] + c[v]});
    sort(ed.begin(), ed.end());
    for (int i = 1; i <= n; i++)
        dsu[i] = i;
    cout << kruskal() + mn << endl;
    return 0;
}
