#include <bits/stdc++.h>
using namespace std;

const int N = 6, M = 2e6 + 5;

int a[N][N];
bool v[M];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

inline void input() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> a[i][j];
        }
    }
    return;
}

inline void dfs(int x, int y, int s, int d) {
    if (d == 6) {
        v[s] = true;
        return;
    }
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) {
            continue;
        }
        dfs(nx, ny, s * 10 + a[nx][ny], d + 1);
    }
    return;
}

inline void solve() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            dfs(i, j, a[i][j], 1);
        }
    }
    int ans = 0;
    for (int i = 0; i < 1000000; i++) {
        if (v[i]) {
            ans++;
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
