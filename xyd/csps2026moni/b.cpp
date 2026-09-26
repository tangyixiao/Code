#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int n, m, q[N], p[N];
bool b[N];
vector<int> g[N], c[N], s;
inline void build(int u) {
    int f = 0;
    for (auto w : c[u]) {
        if (c[w].empty()) {
            f = w;
        }
    }
    s.push_back(u);
    if (c[u].empty()) {
        return;
    }
    if (f) {
        for (auto w : c[u]) {
            if (w != f) {
                build(w);
            }
        }
        s.push_back(f);
    } else {
        for (auto w : c[u]) {
            for (auto z : c[w]) {
                build(z);
            }
            s.push_back(w);
        }
    }
    return;
}
signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    freopen("cov.in", "r", stdin), freopen("cov.out", "w", stdout);
    cin >> n >> m;
    vector<pair<int, int>> e(m);
    for (auto &[x, y] : e) {
        cin >> x >> y, g[x].push_back(y), g[y].push_back(x);
    }
    q[0] = 1, b[1] = true;
    for (int h = 0, t = 1; h < t; h++) {
        int u = q[h];
        for (auto w : g[u]) {
            if (!b[w]) {
                b[w] = true, c[u].push_back(w), q[t++] = w;
            }
        }
    }
    build(1);
    for (int i = 0; i < n; i++) {
        p[s[i]] = i;
    }
    for (int x = 1, o; x <= n; x++) {
        o = p[x];
        for (int k = 0; k <= n; k++) {
            cout << s[(o + k) % n] << (k == n ? "\n" : " ");
        }
    }
    return 0;
}
