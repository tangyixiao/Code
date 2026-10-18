#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;

int t, n;
char a[N][N];

inline void input() {
    cin >> t;
}

inline void solve() {
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int x, y, p, q;
        cin >> x >> y >> p >> q;
        bool f[N][N];
        memset(f, 0, sizeof(f));
        queue<pair<int, int>> w;
        w.push(make_pair(x, y));
        f[x][y] = 1;
        int ok = 0;
        while (!w.empty()) {
            int r = w.front().first, c = w.front().second;
            w.pop();
            if (r == p && c == q) {
                ok = 1;
                break;
            }
            int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
            for (int i = 0; i < 4; ++i) {
                int u = r + dx[i], v = c + dy[i];
                if (u < 0 || u >= n || v < 0 || v >= n || f[u][v] || a[u][v] == '#') {
                    continue;
                }
                f[u][v] = 1;
                w.push(make_pair(u, v));
            }
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    solve();
    return 0;
}
