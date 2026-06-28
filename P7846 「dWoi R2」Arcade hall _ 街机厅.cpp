#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
const ll INF = 1e18;

struct DSU {
    vector<int> fa, sz;
    DSU(int n) : fa(n + 1), sz(n + 1, 1) {
        for (int i = 1; i <= n; ++i)
            fa[i] = i;
    }
    int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
    void unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y)
            return;
        if (sz[x] < sz[y])
            swap(x, y);
        fa[y] = x;
        sz[x] += sz[y];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, R;
    cin >> n >> R;
    vector<tuple<int, int, int>> edges(n - 1);
    DSU dsu(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v, t;
        cin >> u >> v >> t;
        edges[i] = {u, v, t};
        if (t == 2)
            dsu.unite(u, v);
    }
    
    for (auto [u, v, t] : edges) {
        if (t == 0 && dsu.find(u) == dsu.find(v)) {
            cout << "0 0\n";
            return 0;
        }
    }
    
    vector<int> roots;
    vector<int> root_id(n + 1, -1);
    for (int i = 1; i <= n; ++i) {
        int r = dsu.find(i);
        if (root_id[r] == -1) {
            root_id[r] = roots.size();
            roots.push_back(r);
        }
    }
    int m = roots.size();
    vector<ll> siz(m);
    for (int i = 0; i < m; ++i) {
        int r = roots[i];
        siz[i] = dsu.sz[r];
    }
    
    vector<vector<pair<int, int>>> adj(m);
    for (auto [u, v, t] : edges) {
        if (t == 2)
            continue;
        int ru = dsu.find(u), rv = dsu.find(v);
        if (ru == rv)
            continue;
        int idu = root_id[ru], idv = root_id[rv];
        adj[idu].push_back({idv, t});
        adj[idv].push_back({idu, t});
    }
    
    vector<vector<pair<int, int>>> children(m);
    vector<int> parent(m, -1);
    vector<bool> visited(m, false);
    stack<int> st;
    st.push(0);
    visited[0] = true;
    while (!st.empty()) {
        int u = st.top();
        st.pop();
        for (auto [v, t] : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                parent[v] = u;
                children[u].push_back({v, t});
                st.push(v);
            }
        }
    }
    
    vector<int> order;
    stack<int> st2;
    st2.push(0);
    vector<bool> vis2(m, false);
    while (!st2.empty()) {
        int u = st2.top();
        if (!vis2[u]) {
            vis2[u] = true;
            for (auto [v, t] : children[u])
                st2.push(v);
        } else {
            st2.pop();
            order.push_back(u);
        }
    }
    
    vector<vector<ll>> cnt(m, vector<ll>(R + 1, 0));
    vector<vector<ll>> sum(m, vector<ll>(R + 1, INF));
    for (int u : order) {
        
        for (int c = 1; c <= R; ++c) {
            cnt[u][c] = 1;
            sum[u][c] = c * siz[u];
        }
        
        for (auto [v, t] : children[u]) {
            
            ll sum_cnt_v = 0;
            ll min1 = INF, min2 = INF;
            int cnt_min = 0;
            for (int c = 1; c <= R; ++c) {
                if (cnt[v][c] == 0)
                    continue;
                sum_cnt_v = (sum_cnt_v + cnt[v][c]) % MOD;
                ll val = sum[v][c];
                if (val < min1) {
                    min2 = min1;
                    min1 = val;
                    cnt_min = 1;
                } else if (val == min1) {
                    ++cnt_min;
                } else if (val < min2) {
                    min2 = val;
                }
            }
            
            for (int c = 1; c <= R; ++c) {
                ll factor, child_min;
                if (t == 1) { 
                    factor = sum_cnt_v;
                    child_min = min1;
                } else { 
                    factor = (sum_cnt_v - cnt[v][c] + MOD) % MOD;
                    if (cnt[v][c] == 0) {
                        child_min = min1; 
                    } else {
                        if (sum[v][c] == min1) {
                            child_min = (cnt_min > 1) ? min1 : min2;
                        } else {
                            child_min = min1;
                        }
                    }
                }
                cnt[u][c] = cnt[u][c] * factor % MOD;
                if (child_min >= INF) {
                    sum[u][c] = INF;
                } else if (sum[u][c] < INF) {
                    sum[u][c] += child_min;
                }
            }
        }
    }
    int root = 0;
    ll ans1 = 0, ans2 = INF;
    for (int c = 1; c <= R; ++c) {
        ans1 = (ans1 + cnt[root][c]) % MOD;
        if (cnt[root][c] != 0)
            ans2 = min(ans2, sum[root][c]);
    }
    if (ans2 == INF)
        ans2 = 0;
    cout << ans1 << ' ' << ans2 << '\n';
    return 0;
}