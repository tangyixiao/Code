#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
const int LOG = 18;
const int INF = 1e9;

vector<int> g[MAXN];
int depth[MAXN];
int parent[MAXN][LOG];
int distPortal[MAXN];

void dfs(int u, int p) {
    parent[u][0] = p;
    for (int i = 1; i < LOG; ++i)
        parent[u][i] = parent[parent[u][i - 1]][i - 1];
    for (int v : g[u]) {
        if (v == p)
            continue;
        depth[v] = depth[u] + 1;
        dfs(v, u);
    }
}

int lca(int u, int v) {
    if (depth[u] < depth[v])
        swap(u, v);
    int diff = depth[u] - depth[v];
    for (int i = 0; i < LOG; ++i)
        if (diff >> i & 1)
            u = parent[u][i];
    if (u == v)
        return u;
    for (int i = LOG - 1; i >= 0; --i) {
        if (parent[u][i] != parent[v][i]) {
            u = parent[u][i];
            v = parent[v][i];
        }
    }
    return parent[u][0];
}

int distTree(int u, int v) {
    int w = lca(u, v);
    return depth[u] + depth[v] - 2 * depth[w];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, q;
    cin >> n >> k >> q;
    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    depth[1] = 0;
    dfs(1, 1);

    vector<int> portals;
    if (k > 0) {
        portals.resize(k);
        for (int i = 0; i < k; ++i)
            cin >> portals[i];
        queue<int> que;
        fill(distPortal, distPortal + n + 1, -1);
        for (int p : portals) {
            distPortal[p] = 0;
            que.push(p);
        }
        while (!que.empty()) {
            int u = que.front();
            que.pop();
            for (int v : g[u]) {
                if (distPortal[v] == -1) {
                    distPortal[v] = distPortal[u] + 1;
                    que.push(v);
                }
            }
        }
    } else {

        fill(distPortal, distPortal + n + 1, INF);
    }

    while (q--) {
        int u, v;
        cin >> u >> v;
        int ans = distTree(u, v);
        if (k > 0) {
            ans = min(ans, distPortal[u] + distPortal[v]);
        }
        cout << ans << '\n';
    }
    return 0;
}