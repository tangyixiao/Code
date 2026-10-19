#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, m, fa[N], siz[N];

inline int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

inline void input() { cin >> n >> m; }

inline void solve() {
    for (int i = 1; i <= n; ++i) {
        fa[i] = i, siz[i] = 1;
    }
    char c;
    for (int i = 1; i <= m; ++i) {
        int x, y;
        cin >> c >> x;
        if (c == 'M') {
            cin >> y;
            int a = find(x), b = find(y);
            if (a != b) {
                fa[b] = a, siz[a] += siz[b];
            }
        } else {
            cout << siz[find(x)] << "\n";
        }
    }
    return;
}

signed main() {
    input();
    solve();
    return 0;
}