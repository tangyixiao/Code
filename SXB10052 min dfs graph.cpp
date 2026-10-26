#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int M = 2e5 + 5;
int n, m, cnt, head[N], nxt[M], to[M], ans[N], c;
bool vis[N];

void add(int u, int v) {
    cnt++;
    to[cnt] = v;
    nxt[cnt] = head[u];
    head[u] = cnt;
}

void dfs(int u) {
    vis[u] = 1;
    ans[++c] = u;
    for (int i = head[u]; i; i = nxt[i]) {
        int v = to[i];
        if (!vis[v]) {
            dfs(v);
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        add(x, y);
        add(y, x);
    }
    dfs(1);
    for (int i = 1; i <= c; i++) {
        cout << ans[i];
        if (i < c) {
            cout << " ";
        }
    }
    cout << "\n";
    return 0;
}
