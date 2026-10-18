#include <bits/stdc++.h>
using namespace std;

const int N = 2e3 + 5;
int n, m, fa[N];
bool vis[N];

inline int fd(int t) {
    return fa[t] == t ? t : fa[t] = fd(fa[t]);
}

inline void input() {
    cin >> n >> m;
    for (int i = 1; i <= 2 * n; i++) {
        fa[i] = i;
    }
}

inline void solve() {
    while (m--) {
        int p, x, y, a, b;
        cin >> p >> x >> y;
        if (p == 0) {
            fa[fd(x)] = fd(y), fa[fd(x + n)] = fd(y + n);
        } else {
            fa[fd(x)] = fd(y + n), fa[fd(x + n)] = fd(y);
        }
        a = b = 0;
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        int r = fd(i);
        if (!vis[r]) {
            vis[r] = 1, cnt++;
        }
    }
    cout << cnt << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
