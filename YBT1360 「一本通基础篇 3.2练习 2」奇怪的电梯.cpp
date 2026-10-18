#include <bits/stdc++.h>
using namespace std;

const int N = 2e2 + 5;
int n, a, b, k[N], f[N];

inline void input() {
    cin >> n >> a >> b;
    for (int i = 1; i <= n; ++i) {
        cin >> k[i];
    }
}

inline void solve() {
    memset(f, 0x3f, sizeof(f));
    f[a] = 0;
    queue<int> q;
    q.push(a);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        int v[2] = {u + k[u], u - k[u]};
        for (int t = 0; t < 2; ++t) {
            int w = v[t];
            if (w < 1 || w > n || f[w] <= f[u] + 1) {
                continue;
            }
            f[w] = f[u] + 1;
            q.push(w);
        }
    }
    cout << (f[b] > 1e8 ? -1 : f[b]) << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}