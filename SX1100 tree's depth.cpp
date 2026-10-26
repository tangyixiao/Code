#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, h, dep[N], deg[N], q[N];
int ec, head[N], nxt[2 * N], to[2 * N];

void add(int u, int v) {
    nxt[++ec] = head[u], to[ec] = v, head[u] = ec;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        add(x, y), add(y, x);
        deg[x]++, deg[y]++;
    }
    if (n == 1) {
        cout << 1 << " " << 1 << "\n";
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        dep[i] = -1;
    }
    dep[1] = 1, h = 0;
    int tl = 1, mx = 1, leaf = 0;
    q[0] = 1;
    for (; h < tl;) {
        int u = q[h];
        h++;
        mx = max(mx, dep[u]);
        if (u != 1 && deg[u] == 1) {
            leaf++;
        }
        for (int e = head[u]; e; e = nxt[e]) {
            int v = to[e];
            if (dep[v] == -1) {
                dep[v] = dep[u] + 1;
                q[tl++] = v;
            }
        }
    }
    cout << mx << " " << leaf << "\n";
    return 0;
}
