#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i <= b; i++)
#define int long long

#define pii pair<int, int>
#define fi first
#define se second

const int N = 2e5 + 10;

int n;
vector<pii> g[N];

int dis[N], dia[N], fa[N];
void dfs1(int u, int fa) {
    for (auto [v, w] : g[u]) {
        if (v == fa)
            continue;
        ::fa[v] = u;
        dfs1(v, u);
        dia[u] = max(dia[u], dis[u] + dis[v] + w);
        if (dis[u] < dis[v] + w) {
            dis[u] = dis[v] + w;
        }
    }
}

int ans = 0, tag[N];
vector<int> v;

void dfs2(int u, int fa) {
    bool flag = 0;
    for (auto [v, w] : g[u]) {
        if (v == fa)
            continue;
        dfs2(v, u);
        if (tag[v])
            tag[u] = 1, flag = 1;
    }
    if (tag[u] && !flag) {
        v.push_back(u);
    }
}

int Ans = 0;

void dfs3(int u, int fa) {
    int mx = 0, cnt = 0, pt;
    for (auto [v, w] : g[u]) {
        if (v == fa)
            continue;
        mx = max(mx, w + dis[v]);
    }
    for (auto [v, w] : g[u]) {
        if (v == fa)
            continue;
        if (w + dis[v] == mx) {
            cnt++;
            pt = v;
        }
    }
    if (cnt == 1) {
        Ans++;
        dfs3(pt, u);
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    rep(i, 1, n - 1) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    dfs1(1, 0);
    rep(i, 1, n) {
        ans = max(ans, dia[i]);
    }
    rep(i, 1, n) if (dia[i] == ans) tag[i] = 1;
    dfs2(1, 0);
    if (v.size() > 1)
        cout << 0 << endl;
    int u = v[0];
    memset(dis, 0, sizeof dis);
    memset(dia, 0, sizeof dia);
    memset(fa, 0, sizeof fa);
    dfs1(u, 0);
    vector<pii> vp;
    for (auto [v, w] : g[u]) {
        vp.push_back({w + dis[v], v});
    }
    sort(vp.begin(), vp.end(), greater<pii>());
    set<int> s;
    int mx = 0, smx = 0;
    for (auto [w, v] : vp) {
        s.insert(w);
        if (s.size() == 1)
            mx++;
        if (s.size() == 2)
            smx++;
    }
    if (mx > 2)
        Ans = 0;
    else if (mx == 2) {
        dfs3(vp[0].se, u);
        dfs3(vp[1].se, u);
        Ans += 2;
    } else if (mx == 1) {
        if (smx >= 2) {
            dfs3(vp[0].se, u);
            Ans++;
        } else if (smx == 1) {
            dfs3(vp[0].se, u);
            Ans++;
            dfs3(vp[1].se, u);
            Ans++;
        }
    }
    cout << ans << '\n'
         << Ans;
}