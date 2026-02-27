#include <bits/stdc++.h>
using namespace std;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int vis[505][505];
int n, m, A, B;
struct node {
    int x, y, step;
} a[100005]; // 领主（终点）的位置
queue<node> que;
void bfs();
int main() {
    memset(vis, -1, sizeof vis); // 初始化数组vis为-1
    cin >> n >> m >> A >> B;
    for (int i = 1; i <= A; i++) // 输入起点（病毒位置）
    {
        int x, y;
        cin >> x >> y;
        vis[x][y] = 0;
        que.push({x, y, 0}); // 起点标记并入队
    }
    for (int i = 1; i <= B; i++) // 输入终点(领主)，记到a[];
    {
        cin >> a[i].x >> a[i].y;
    }
    bfs(); // 搜索
    for (int i = 1; i <= B; i++)
        cout << vis[a[i].x][a[i].y] << '\n'; // 输出每个领主感染的时间
}
void bfs() {
    while (que.size()) {
        node hd = que.front();
        que.pop();
        for (int i = 0; i < 4; i++) // 4个方向
        {
            int r = hd.x + dx[i];
            int c = hd.y + dy[i];
            int step = hd.step + 1;                                  // 计算头能到为位置和步数
            if (r < 1 || c < 1 || r > n || c > m || vis[r][c] != -1) // 出界、已经被感染的点跳过
                continue;
            vis[r][c] = step;
            que.push({r, c, step}); // 标记新点，入队搜索
        }
    }
}