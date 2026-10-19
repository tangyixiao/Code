#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int M = 1e6 + 5;
int n, m, hd[N], to[M], nx[M], wt[M], tot;
double d[N];
bool inq[N];

inline void add(int u, int v, int w) {
    to[++tot] = v;
    wt[tot] = w;
    nx[tot] = hd[u];
    hd[u] = tot;
    return;
}

inline void input() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        add(x, y, z), add(y, x, z);
    }
}

inline void solve() {
    int a, b;
    cin >> a >> b;
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        d[i] = 1e18;
    }
    d[b] = 100, inq[b] = 1;
    q.push(b);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        inq[u] = 0;
        for (int i = hd[u]; i; i = nx[i]) {
            int v = to[i];
            double nd = d[u] * 100 / (100 - wt[i]);
            if (nd < d[v]) {
                d[v] = nd;
                if (!inq[v]) {
                    inq[v] = 1;
                    q.push(v);
                }
            }
        }
    }
    cout << fixed << setprecision(8) << d[a] << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
