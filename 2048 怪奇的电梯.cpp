#include <bits/stdc++.h>
using namespace std;

const int N = 2e4 + 5;

int n, a, b, k[N], d[N];
queue<int> q;

inline void input() {
    cin >> n >> a >> b;
    for (int i = 1; i <= n; ++i) {
        cin >> k[i];
    }
}

inline void solve() {
    memset(d, -1, sizeof(d));
    d[a] = 0, q.push(a);
    while (q.size()) {
        int u = q.front();
        q.pop();
        if (u == b) {
            break;
        }
        int v[2] = {u + k[u], u - k[u]};
        for (int i = 0; i < 2; ++i) {
            if (v[i] < 1 || v[i] > n || d[v[i]] != -1) {
                continue;
            }
            d[v[i]] = d[u] + 1, q.push(v[i]);
        }
    }
    cout << d[b] << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    solve();
    return 0;
}
