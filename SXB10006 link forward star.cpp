#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, m, u, v, i;
int head[N], to[N], nxt[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (i = 1; i <= m; i++) {
        cin >> u >> v;
        to[i] = v, nxt[i] = head[u], head[u] = i;
    }
    for (u = 1; u <= n; u++) {
        cout << u;
        for (i = head[u]; i != 0; i = nxt[i]) {
            cout << " " << to[i];
        }
        cout << "\n";
    }
    return 0;
}
