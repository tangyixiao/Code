#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10, inf = 1e9;
const int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};

int n, C = inf, S;
char s[N][N]; // 改为字符数组，更容易控制边界
bool vis[N][N];

inline pair<int, int> bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    vis[x][y] = true;
    int per = 1, are = 0;

    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];

            // 检查是否在扩展后的网格范围内 (0到n+1)
            if (nx < 0 || nx > n + 1 || ny < 0 || ny > n + 1) {
                continue;
            }

            // 如果相邻是空地，周长+1
            if (s[nx][ny] == '.') {
                are++;
            }

            // 如果相邻是未访问的冰激凌，加入队列
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= n) {
                if (s[nx][ny] == '#' && !vis[nx][ny]) {
                    vis[nx][ny] = true;
                    q.push({nx, ny});
                    per++;
                }
            }
        }
    }
    return {per, are};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    // 初始化整个网格为'.'
    for (int i = 0; i <= n + 1; i++) {
        for (int j = 0; j <= n + 1; j++) {
            s[i][j] = '.';
        }
    }

    // 读入网格，只填充1到n的区域
    for (int i = 1; i <= n; i++) {
        string row;
        cin >> row;
        for (int j = 1; j <= n; j++) {
            s[i][j] = row[j - 1];
        }
    }

    // 遍历所有冰激凌连通块
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (s[i][j] == '#' && !vis[i][j]) {
                auto [per, are] = bfs(i, j);
                if (S < per) {
                    S = per;
                    C = are;
                } else if (S == per) {
                    C = min(C, are);
                }
            }
        }
    }

    cout << S << ' ' << C << '\n';
    return 0;
}