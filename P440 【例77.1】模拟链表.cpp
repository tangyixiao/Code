#include <bits/stdc++.h>
using namespace std;

const int N = 5005;
const int M = 2e5 + 5;
int n, m, hd[N], nxt[M], to[M], tot, deg[N];

signed main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        to[++tot] = v, nxt[tot] = hd[u], hd[u] = tot;
        to[++tot] = u, nxt[tot] = hd[v], hd[v] = tot;
        deg[u]++, deg[v]++;
    }
    for (int i = 1; i <= n; i++) {
        cout << deg[i];
        for (int j = hd[i]; j; j = nxt[j]) {
            cout << " " << to[j];
        }
        cout << "\n";
    }
    return 0;
}
