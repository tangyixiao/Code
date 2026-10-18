#include <bits/stdc++.h>
using namespace std;

const int N = 4000 + 5;

int n, m, d[N];
bool g[N][N];

inline void input() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        if (g[x][y]) {
            continue;
        }
        g[x][y] = g[y][x] = true, d[x]++, d[y]++;
    }
    return;
}

inline void solve() {
    int ans = 0x3f3f3f3f;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (!g[i][j]) {
                continue;
            }
            for (int k = j + 1; k <= n; k++) {
                if (g[i][k] && g[j][k]) {
                    ans = min(ans, d[i] + d[j] + d[k]);
                }
            }
        }
    }
    cout << (ans == 0x3f3f3f3f ? -1 : ans) << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}