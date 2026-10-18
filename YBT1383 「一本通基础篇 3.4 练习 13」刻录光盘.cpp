#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int n, dfn[N], low[N], bel[N], tim, scc;
int st[N], top;
vector<int> e[N];

void tarjan(int u) {
    dfn[u] = low[u] = ++tim;
    st[++top] = u;
    for (int i = 0; i < e[u].size(); ++i) {
        int v = e[u][i];
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (low[u] == dfn[u]) {
        scc++;
        for (int v = 0; v <= top; ++v) {
            bel[st[v]] = scc;
        }
        top = 0;
    }
    return;
}

inline void input() { cin >> n; }

inline void solve() {
    for (int i = 1; i <= n; ++i) {
        int v;
        while (cin >> v && v) {
            e[i].push_back(v);
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (!dfn[i]) {
            tarjan(i);
        }
    }
    bool in[N] = {};
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < e[i].size(); ++j) {
            if (bel[i] != bel[e[i][j]]) {
                in[bel[e[i][j]]] = true;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= scc; ++i) {
        if (!in[i]) {
            ans++;
        }
    }
    cout << ans << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}