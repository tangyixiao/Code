#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, k, fa[N], d[N], ans;

inline int find(int x) {
    if (fa[x] == x) {
        return x;
    }
    int y = fa[x];
    fa[x] = find(y);
    d[x] = (d[x] + d[y]) % 3;
    return fa[x];
}

inline void input() { cin >> n >> k; }

inline void solve() {
    for (int i = 1; i <= n; ++i) {
        fa[i] = i, d[i] = 0;
    }
    for (int i = 1; i <= k; ++i) {
        int c, x, y;
        cin >> c >> x >> y;
        if (x > n || y > n) {
            ++ans;
            continue;
        }
        if (c == 2 && x == y) {
            ++ans;
            continue;
        }
        int a = find(x), b = find(y);
        if (a == b) {
            if ((d[y] - d[x] + 3) % 3 != c - 1) {
                ++ans;
            }
            continue;
        }
        if (c == 1) {
            fa[b] = a, d[b] = (d[x] - d[y] + 3) % 3;
        } else {
            fa[b] = a, d[b] = (d[x] - d[y] + 1) % 3;
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