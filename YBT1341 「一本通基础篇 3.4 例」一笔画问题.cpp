#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;
const int M = 1e3 + 5;
int n, m, hd[N], to[M], nx[M], tot, deg[N];
bool vis[M];
int stk[M], top;

inline void add(int x, int y) {
    to[++tot] = y;
    nx[tot] = hd[x];
    hd[x] = tot;
    return;
}

inline void input() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        add(x, y), add(y, x);
        deg[x]++, deg[y]++;
    }
}

inline void dfs(int u) {
    for (int i = hd[u]; i; i = nx[i]) {
        if (!vis[i]) {
            vis[i] = vis[i & 1 ? i + 1 : i - 1] = 1;
            dfs(to[i]);
        }
    }
    stk[top++] = u;
    return;
}

inline void solve() {
    int s = 1;
    for (int i = 1; i <= n; i++) {
        if (deg[i] & 1) {
            s = i;
            break;
        }
    }
    dfs(s);
    for (int i = top - 1; i >= 0; i--) {
        cout << stk[i] << (i ? " " : "\n");
    }
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
