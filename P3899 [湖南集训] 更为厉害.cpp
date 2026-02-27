#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 300005;

int n, q;
vector<int> adj[MAXN];
int parent[MAXN], depth[MAXN], in[MAXN], out[MAXN], sz[MAXN];
int timer = 0, maxDepth = 0;
vector<int> nodes_at_depth[MAXN];

void dfs() {
    stack<pair<int, int>> st;
    st.push({1, 0});
    parent[1] = 0;
    depth[1] = 1;
    while (!st.empty()) {
        auto [u, state] = st.top();
        st.pop();
        if (state == 0) {
            in[u] = ++timer;
            maxDepth = max(maxDepth, depth[u]);
            nodes_at_depth[depth[u]].push_back(u);
            st.push({u, 1});
            for (int v : adj[u]) {
                if (v == parent[u])
                    continue;
                parent[v] = u;
                depth[v] = depth[u] + 1;
                st.push({v, 0});
            }
        } else {
            out[u] = timer;
            sz[u] = 1;
            for (int v : adj[u])
                if (v != parent[u])
                    sz[u] += sz[v];
        }
    }
}

struct Node {
    int lc, rc;
    ll sum;
} tree[MAXN * 20];
int root[MAXN], tot = 0;

int build(int l, int r) {
    int rt = ++tot;
    tree[rt].sum = 0;
    if (l == r)
        return rt;
    int mid = (l + r) >> 1;
    tree[rt].lc = build(l, mid);
    tree[rt].rc = build(mid + 1, r);
    return rt;
}

int update(int pre, int l, int r, int pos, ll val) {
    int rt = ++tot;
    tree[rt] = tree[pre];
    tree[rt].sum += val;
    if (l == r)
        return rt;
    int mid = (l + r) >> 1;
    if (pos <= mid)
        tree[rt].lc = update(tree[pre].lc, l, mid, pos, val);
    else
        tree[rt].rc = update(tree[pre].rc, mid + 1, r, pos, val);
    return rt;
}

ll query(int u, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr)
        return tree[u].sum;
    int mid = (l + r) >> 1;
    ll res = 0;
    if (ql <= mid)
        res += query(tree[u].lc, l, mid, ql, qr);
    if (qr > mid)
        res += query(tree[u].rc, mid + 1, r, ql, qr);
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> q;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs();

    root[0] = build(1, n);
    for (int d = 1; d <= maxDepth; ++d) {
        root[d] = root[d - 1];
        for (int u : nodes_at_depth[d])
            root[d] = update(root[d], 1, n, in[u], sz[u] - 1);
    }

    while (q--) {
        int p, k;
        cin >> p >> k;

        ll anc_cnt = min(depth[p] - 1, k);
        ll ans = anc_cnt * (sz[p] - 1);

        int L = depth[p];
        int R = min(depth[p] + k, maxDepth);
        if (L < R) {
            ll sumR = query(root[R], 1, n, in[p], out[p]);
            ll sumL = query(root[L], 1, n, in[p], out[p]);
            ans += sumR - sumL;
        }
        cout << ans << '\n';
    }
    return 0;
}