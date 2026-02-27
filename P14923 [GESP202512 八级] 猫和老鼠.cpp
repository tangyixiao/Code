#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 5;
const int inf = 1e18;
int n, m, a, b, c[N], dis[N], u, v, w, ans;
bool vis[N];
struct edge {
    int v, w;
    bool operator<(const edge& b) const {
        return w > b.w;
    }
};
vector<edge> g[N];
priority_queue<edge> q;
void dij(int s) {
    for (int i = 1; i <= n; i++)
        dis[i] = inf;
    dis[s] = 0;
    q.push({s, 0});
    while (!q.empty()) {
        int u = q.top().v;
        q.pop();
        if (vis[u])
            continue;
        vis[u] = 1;
        for (int i = 0; i < g[u].size(); i++) {
            int x = g[u][i].v, y = g[u][i].w;
            if (dis[u] + y < dis[x]) {
                dis[x] = dis[u] + y;
                q.push({x, dis[x]});
            }
        }
    }
}
main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> a >> b;
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    while (m--) {
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    dij(b);
    for (int i = 1; i <= n; i++)
        if (dis[i] < dis[a])
            ans += c[i];
    cout << ans;
    return 0;
}
