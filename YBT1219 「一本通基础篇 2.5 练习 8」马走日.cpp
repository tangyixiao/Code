#include <bits/stdc++.h>
using namespace std;

const int N = 1e1 + 5;

int t, n, m, x, y, c;
int dx[8] = {2, 2, -2, -2, 1, 1, -1, -1}, dy[8] = {1, -1, 1, -1, 2, -2, 2, -2};
bool f[N][N];

inline void dfs(int i, int j, int k) {
    if (k == n * m) {
        ++c;
        return;
    }
    for (int z = 0; z < 8; ++z) {
        int u = i + dx[z], v = j + dy[z];
        if (u < 0 || u >= n || v < 0 || v >= m || f[u][v]) {
            continue;
        }
        f[u][v] = 1;
        dfs(u, v, k + 1);
        f[u][v] = 0;
    }
}

inline void input() {
    cin >> t;
}

inline void solve() {
    while (t--) {
        cin >> n >> m >> x >> y;
        memset(f, 0, sizeof(f));
        f[x][y] = 1;
        c = 0;
        dfs(x, y, 1);
        cout << c << "\n";
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
