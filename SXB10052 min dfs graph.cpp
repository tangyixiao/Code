#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> g[N];
int n, m, c, tp;
int ans[N], stkU[N], stkI[N];
bool vis[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for (int i = 1; i <= n; i++) {
        sort(g[i].begin(), g[i].end());
    }
    vis[1] = 1;
    ans[++c] = 1;
    tp = 1;
    stkU[1] = 1;
    stkI[1] = 0;
    while (tp > 0) {
        int u = stkU[tp];
        if (stkI[tp] < (int)g[u].size()) {
            int v = g[u][stkI[tp]];
            stkI[tp]++;
            if (!vis[v]) {
                vis[v] = 1;
                ans[++c] = v;
                tp++;
                stkU[tp] = v;
                stkI[tp] = 0;
            }
        } else {
            tp--;
        }
    }
    for (int i = 1; i <= c; i++) {
        cout << ans[i];
        if (i < c) {
            cout << " ";
        }
    }
    cout << "\n";
    return 0;
}
