#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;
int n, k, fa[N], sz[N];

inline int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

inline void input() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        fa[i] = i, sz[i] = 1;
    }
    for (int i = 1; i <= k; ++i) {
        int x, y;
        cin >> x >> y;
        int a = find(x), b = find(y);
        if (a != b) {
            fa[a] = b, sz[b] += sz[a];
        }
    }
}

inline void solve() {
    int cnt = 0, mx = 0;
    for (int i = 1; i <= n; ++i) {
        if (fa[i] == i) {
            ++cnt;
            mx = max(mx, sz[i]);
        }
    }
    cout << cnt << " " << mx << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}