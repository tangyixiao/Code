#include <bits/stdc++.h>
using namespace std;

const int N = 105;
int n;
int pop[N], l[N], r[N], s[N], f[N], g[N], ans;

inline void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> pop[i] >> l[i] >> r[i];
    }
    return;
}

inline void dfs(int p) {
    if (l[p]) {
        dfs(l[p]);
    }
    if (r[p]) {
        dfs(r[p]);
    }
    s[p] = pop[p] + s[l[p]] + s[r[p]];
    f[p] = f[l[p]] + f[r[p]] + s[l[p]] + s[r[p]];
    return;
}

inline void rg(int p, int v) {
    g[v] = g[p] + s[1] - 2 * s[v];
    ans = min(ans, g[v]);
    if (l[v]) {
        rg(v, l[v]);
    }
    if (r[v]) {
        rg(v, r[v]);
    }
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    dfs(1);
    ans = g[1] = f[1];
    rg(1, l[1]);
    rg(1, r[1]);
    cout << ans << "\n";
    return 0;
}