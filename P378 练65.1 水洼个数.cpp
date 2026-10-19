#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;

int n, m, ans;
char a[N][N];
bool v[N][N];

int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};

inline void input() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    return;
}

inline void dfs(int x, int y) {
    v[x][y] = true;
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m || a[nx][ny] != 'W' || v[nx][ny]) {
            continue;
        }
        dfs(nx, ny);
    }
    return;
}

inline void solve() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 'W' && !v[i][j]) {
                dfs(i, j), ans++;
            }
        }
    }
    cout << ans << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}