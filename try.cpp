#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int MAXN = 200005;

int inv[MAXN];

void precompute_inv() {
    inv[1] = 1;
    for (int i = 2; i < MAXN; ++i) {
        inv[i] = MOD - 1LL * MOD / i * inv[MOD % i] % MOD;
    }
}

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> adj(n + 1);
        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> parent(n + 1);
        vector<vector<int>> children(n + 1);
        vector<int> bfs_order;
        queue<int> q;
        q.push(1);
        parent[1] = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            bfs_order.push_back(u);
            for (int v : adj[u]) {
                if (v == parent[u])
                    continue;
                parent[v] = u;
                children[u].push_back(v);
                q.push(v);
            }
        }

        vector<int> h(n + 1);

        for (int i = n - 1; i >= 0; --i) {
            int u = bfs_order[i];
            if (children[u].empty() && u != 1) {
                h[u] = 0;
            } else {
                int mn = 1e9;
                for (int v : children[u]) {
                    mn = min(mn, h[v] + 1);
                }
                h[u] = mn;
            }
        }

        vector<int> f(n + 1), delta(n + 1);
        delta[1] = inv[h[1]];
        f[1] = 1;

        for (int u : bfs_order) {
            for (int v : children[u]) {
                delta[v] = 1LL * delta[u] * h[u] % MOD * inv[h[v] + 1] % MOD;
                f[v] = (f[u] - delta[v] + MOD) % MOD;
            }
        }

        for (int i = 1; i <= n; ++i) {
            cout << f[i] << " \n"[i == n];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    precompute_inv();
    solve();
    return 0;
}