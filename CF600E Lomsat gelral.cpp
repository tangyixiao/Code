#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
int n, col[N];
vector<int> g[N];

int sz[N], son[N];

void dfs1(int u, int p) {
    sz[u] = 1;
    for (int v : g[u]) {
        if (v == p)
            continue;
        dfs1(v, u);
        sz[u] += sz[v];
        if (sz[v] > sz[son[u]])
            son[u] = v;
    }
}

int cnt[N], max_cnt;
long long sum, ans[N];

void add(int u, int p) {
    int c = col[u];
    cnt[c]++;
    if (cnt[c] > max_cnt) {
        max_cnt = cnt[c];
        sum = c;
    } else if (cnt[c] == max_cnt) {
        sum += c;
    }
    for (int v : g[u]) {
        if (v == p)
            continue;
        add(v, u);
    }
}

void del(int u, int p) {
    cnt[col[u]]--;
    for (int v : g[u]) {
        if (v == p)
            continue;
        del(v, u);
    }
}

void dfs2(int u, int p, bool keep) {
    for (int v : g[u]) {
        if (v == p || v == son[u])
            continue;
        dfs2(v, u, false);
    }

    if (son[u])
        dfs2(son[u], u, true);

    for (int v : g[u]) {
        if (v == p || v == son[u])
            continue;
        add(v, u);
    }

    int c = col[u];
    cnt[c]++;
    if (cnt[c] > max_cnt) {
        max_cnt = cnt[c];
        sum = c;
    } else if (cnt[c] == max_cnt) {
        sum += c;
    }

    ans[u] = sum;

    if (!keep) {
        del(u, p);
        max_cnt = 0;
        sum = 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> col[i];
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs1(1, 0);
    dfs2(1, 0, true);

    for (int i = 1; i <= n; ++i)
        cout << ans[i] << " \n"[i == n];

    return 0;
}