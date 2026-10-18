#include <bits/stdc++.h>
using namespace std;

const int H = 1005;
const int W = 105;

int h, w;
char g[H][W];
bool v[H][W];
int dx[5] = {0, -1, 1, -1, 1};

inline void input() {
    string s;
    h = 0;
    while (cin >> s) {
        if (s.find('.') == string::npos && s.find('*') == string::npos) {
            continue;
        }
        w = (int)s.size();
        for (int i = 0; i < w; i++) {
            g[h][i] = s[i];
        }
        h++;
    }
}

int dfs(int x, int y) {
    if (x < 0 || x >= h || y < 0 || y >= w || g[x][y] != '*' || v[x][y]) {
        return 0;
    }
    v[x][y] = 1;
    return dfs(x + dx[1], y) + dfs(x + dx[2], y) + dfs(x, y + dx[3]) +
           dfs(x, y + dx[4]) + 1;
}

inline void solve() {
    int mx = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (g[i][j] == '*') {
                mx = max(mx, dfs(i, j));
            }
        }
    }
    cout << mx << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
