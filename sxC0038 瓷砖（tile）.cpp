#include <bits/stdc++.h>
using namespace std;
const int N = 55;
int w, h, i, j, cnt;
char g[N][N];
void dfs(int x, int y) {
    if (x < 1 || x > h || y < 1 || y > w) {
        return;
    }
    if (g[x][y] == '#') {
        return;
    }
    if (g[x][y] == 'v') {
        return;
    }
    g[x][y] = 'v';
    cnt++;
    dfs(x - 1, y), dfs(x + 1, y), dfs(x, y - 1), dfs(x, y + 1);
}
signed main() {
    cin >> h >> w;
    int sx = 0, sy = 0;
    for (i = 1; i <= w; i++) {
        for (j = 1; j <= h; j++) {
            cin >> g[j][i];
            if (g[j][i] == '@') {
                sx = j, sy = i;
            }
        }
    }
    dfs(sx, sy);
    cout << cnt << "\n";
    return 0;
}
