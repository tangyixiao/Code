#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int M = 1e6 + 5;
int n, m, hd[N], to[M], nx[M], wt[M], tot, d[N];
bool vis[N];

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
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c), add(b, a, c);
    }
}

inline void solve() {
    for (int i = 1; i <= n; i++) {
        d[i] = 1e9;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    d[1] = 0;
    q.push(make_pair(0, 1));
    while (!q.empty()) {
        int u = q.top().second, du = q.top().first;
        q.pop();
        if (vis[u]) {
            continue;
        }
        vis[u] = 1;
        for (int i = hd[u]; i; i = nx[i]) {
            int v = to[i];
            if (d[v] > du + wt[i]) {
                d[v] = du + wt[i];
                q.push(make_pair(d[v], v));
            }
        }
    }
    cout << d[n] << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
