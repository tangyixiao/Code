#include <bits/stdc++.h>
using namespace std;

const int N = 5e4 + 5;

int n, m, a[N];

inline void input() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
}

inline void solve() {
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v, swap(a[u], a[v]);
    }
    for (int i = 1; i <= n; i++) {
        cout << a[i] << (i == n ? "\n" : " ");
    }
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
