#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, m, fa[N], cnt, ans;
struct e {
    int p, u, v, w;
} a[N];

inline int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

inline bool cmp(e x, e y) {
    return x.w < y.w;
}

inline void input() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        fa[i] = i;
    }
    for (int i = 1; i <= m; ++i) {
        cin >> a[i].p >> a[i].u >> a[i].v >> a[i].w;
    }
}

inline void solve() {
    sort(a + 1, a + m + 1, cmp);
    cnt = 0, ans = 0;
    for (int i = 1; i <= m; ++i) {
        int x = find(a[i].u), y = find(a[i].v);
        if (a[i].p == 1) {
            ans += a[i].w;
            if (x != y) {
                fa[x] = y, ++cnt;
            }
        } else if (x != y) {
            fa[x] = y, ++cnt, ans += a[i].w;
        }
    }
    cout << ans << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}