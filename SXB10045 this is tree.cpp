#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, cnt, mx, head[N], nxt[2 * N], to[2 * N], dep[N], q[N];

void add(int u, int v) {
    cnt++;
    to[cnt] = v;
    nxt[cnt] = head[u];
    head[u] = cnt;
}

signed main() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        add(x, y);
        add(y, x);
    }
    if (n == 1) {
        cout << 1 << " " << 1 << "\n";
        return 0;
    }
    int h = 1, t = 0, leaves = 0;
    q[++t] = 1;
    dep[1] = 1;
    while (h <= t) {
        int u = q[h++];
        int son = 0;
        for (int i = head[u]; i; i = nxt[i]) {
            int v = to[i];
            if (!dep[v]) {
                dep[v] = dep[u] + 1;
                q[++t] = v;
                son++;
            }
        }
        if (son == 0) {
            leaves++;
        }
        mx = max(mx, dep[u]);
    }
    cout << mx << " " << leaves << "\n";
    return 0;
}
