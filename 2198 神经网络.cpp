#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;
const int M = 1e4 + 5;
int n, p, c[N], u[N], hd[N], ed[M], nx[M], w[M], deg[N], in[N], out[N], q[N], ec;

inline void add(int x, int y, int z) {
    ed[ec] = y;
    w[ec] = z;
    nx[ec] = hd[x];
    hd[x] = ec++;
}

inline void input() {
    cin >> n >> p;
    for (int i = 1; i <= n; ++i) {
        cin >> c[i] >> u[i];
        hd[i] = -1;
        deg[i] = 0;
        in[i] = 1;
        out[i] = 0;
    }
    ec = 0;
    for (int i = 1; i <= p; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        add(x, y, z);
        in[y] = 0;
        out[x] = 1;
        ++deg[y];
    }
}

inline void solve() {
    int h = 0, t = 0;
    for (int i = 1; i <= n; ++i) {
        if (!deg[i]) {
            q[t++] = i;
        }
    }
    for (; h < t; ++h) {
        int x = q[h];
        for (int i = hd[x]; i != -1; i = nx[i]) {
            int y = ed[i];
            c[y] += w[i] * c[x];
            if (!--deg[y]) {
                q[t++] = y;
            }
        }
    }
    bool ok = false;
    for (int i = 1; i <= n; ++i) {
        if (in[i]) {
            continue;
        }
        c[i] -= u[i];
        if (c[i] > 0 && !out[i]) {
            cout << i << " " << c[i] << "\n";
            ok = true;
        }
    }
    if (!ok) {
        cout << "NULL\n";
    }
    return;
}

signed main() {
    input();
    solve();
    return 0;
}