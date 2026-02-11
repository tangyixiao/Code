#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5, fx[] = {0, 0, 1, -1}, fy[] = {1, -1, 0, 0};
char s[N][N];
bool vis[N][N];
int n, m, mp[N], sum, tot;
inline int bfs(int sx, int sy) {
    int cnt = 0;
    queue<pair<int, int>> q;
    q.push({sx, sy});
    vis[sx][sy] = true;
    while (!q.empty()) {
        auto [x, y] = q.front();
        cnt++;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int dx = x + fx[i], dy = y + fy[i];
            if (dx < 0 || dx >= n || dy < 0 || dy >= m) {
                continue;
            }
            if (s[dx][dy] != '*' || vis[dx][dy]) {
                continue;
            }
            vis[dx][dy] = true;
            pair<int, int> p = make_pair(dx, dy);
            q.push(p);
        }
    }
    return cnt;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    tot = n * m;
    n = 5 * n + 1, m = 5 * m + 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> s[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '*' && !vis[i][j]) {
                mp[bfs(i, j)]++;
            }
        }
    }
    for (int i = 4; i <= 16; i += 4) {
        printf("%d ", mp[i]);
        sum += mp[i];
    }
    cout << tot - sum << " ";
    printf("\n");
    return 0;
}