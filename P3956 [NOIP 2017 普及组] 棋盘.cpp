#include <cstring>
#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    int col[101][101];
    memset(col, -1, sizeof(col));
    for (int i = 0; i < n; ++i) {
        int x, y, c;
        cin >> x >> y >> c;
        col[x][y] = c;
    }

    // dist[x][y][c]: 到达 (x,y) 且当前颜色为 c 的最小花费
    int dist[101][101][2];
    memset(dist, 0x3f, sizeof(dist));
    dist[1][1][col[1][1]] = 0;

    // 优先队列，存储 (距离, x, y, 颜色)
    using State = tuple<int, int, int, int>;
    priority_queue<State, vector<State>, greater<State>> pq;
    pq.push({0, 1, 1, col[1][1]});

    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    while (!pq.empty()) {
        auto [d, x, y, c] = pq.top();
        pq.pop();
        if (d != dist[x][y][c])
            continue; // 已经更新过更小的值

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 1 || nx > m || ny < 1 || ny > m)
                continue;

            if (col[nx][ny] != -1) { // 目标格子有颜色
                int newc = col[nx][ny];
                int cost = (c == newc) ? 0 : 1;
                if (d + cost < dist[nx][ny][newc]) {
                    dist[nx][ny][newc] = d + cost;
                    pq.push({dist[nx][ny][newc], nx, ny, newc});
                }
            } else { // 目标格子无色
                if (col[x][y] == -1)
                    continue; // 当前格是临时的，不能用魔法
                // 使用魔法，临时染成当前颜色
                int newc = c;
                int cost = 2;
                if (d + cost < dist[nx][ny][newc]) {
                    dist[nx][ny][newc] = d + cost;
                    pq.push({dist[nx][ny][newc], nx, ny, newc});
                }
            }
        }
    }

    int ans = min(dist[m][m][0], dist[m][m][1]);
    if (ans == 0x3f3f3f3f) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }

    return 0;
}