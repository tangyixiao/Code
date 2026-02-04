# 思路解析

我们看到如此之大的地图，在我们学过的两种方法中只剩下 BFS 可以用。但是我们发现，进行传送门移动时，BFS 按距离原点的距离来判断先后到达就是不成立的。


---

一个浅显的想法是，我们把地图抽象化，抽象成一个图，每个格子代表一个节点，然后对于每个点，对它的上、下、左、右四个方向进行扩展，如果有路可走，就把边权为 $1$ 加入到图中。这样子我们就可以用优先队列来进行 BFS，也就是 Dijkstra 算法来按照与原点的距离来进行搜索。

## 错误实现

那么我们如何维护传送门呢？一个错误的想法是，存储每堵墙出现的位置，再二分查找，找到最近的墙，建边。这样子时间复杂度是 $O(n m  \log (\max(n,m)))$。

```cpp
#include <bits/stdc++.h>
#define DEFENDERS
#define DEBUG_TEST
#define DEBUG_VENI
#define DEBUG_VEDI
#define DEBUG_VECI


#define DEBUG_RECALL

using namespace std;
const int N = 1e3 + 20, inf = 0x3f3f3f3f, dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
struct node {
    int x, y, d;
    bool operator<(const node &rhs) const { return d > rhs.d; }
};
int n, m, sx, sy, cx, cy, dist[N][N];
char a[N][N];
set<int> idx[N], idy[N];
vector<node> g[N][N];
priority_queue<node> q;

inline void Dijkstra() {
    memset(dist, 0x3f, sizeof dist);
    dist[sx][sy] = 0;
    q.push({sx, sy, 0});
    while (!q.empty()) {
        auto [x, y, d] = q.top();
        q.pop();
        if (d > dist[x][y]) {
            continue;
        }
        if (x == cx && y == cy) {
            cout << dist[cx][cy];
            return;
        }
        for (auto [nx, ny, nd] : g[x][y]) {
            if (dist[x][y] + nd < dist[nx][ny]) {
                dist[nx][ny] = dist[x][y] + nd;
                q.push({nx, ny, dist[nx][ny]});
            }
        }
    }
#ifdef DEFENDERS
    cerr << "I AK OIO\n";
#endif
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int R, C;
    cin >> R >> C;

    n = R + 2, m = C + 2;

    for (int i = 0; i <= n + 1; i++) {
        for (int j = 0; j <= m + 1; j++) {
            a[i][j] = '#';
        }
    }

    for (int i = 0; i <= n + 1; i++) {
        idx[i].insert(0);
        idx[i].insert(m + 1);
    }
    for (int j = 0; j <= m + 1; j++) {
        idy[j].insert(0);
        idy[j].insert(n + 1);
    }

    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'S') {
                sx = i, sy = j;
                a[i][j] = '.';
            } else if (a[i][j] == 'C') {
                cx = i, cy = j;
                a[i][j] = '.';
            } else if (a[i][j] == '#') {
                idx[i].insert(j);
                idy[j].insert(i);
            }
        }
    }

    // 建图
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] != '.')
                continue;

            // 普通移动
            for (int k = 0; k < 4; k++) {
                int nx = i + dx[k], ny = j + dy[k];
                if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && a[nx][ny] == '.') {
                    g[i][j].push_back({nx, ny, 1});
                }
            }

            // 传送门边

            // 向上发射
            auto it_up = idy[j].lower_bound(i);
            if (it_up != idy[j].begin()) {
                --it_up;
                int wx = *it_up;
                int nx = wx + 1, ny = j;
                if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && a[nx][ny] == '.') {
                    g[i][j].push_back({nx, ny, 1});
                }
            }
            // 向下发射
            auto it_down = idy[j].upper_bound(i);
            if (it_down != idy[j].end()) {
                int wx = *it_down;
                int nx = wx - 1, ny = j;
                if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && a[nx][ny] == '.') {
                    g[i][j].push_back({nx, ny, 1});
                }
            }
            // 向左发射
            auto it_left = idx[i].lower_bound(j);
            if (it_left != idx[i].begin()) {
                --it_left;
                int wy = *it_left;
                int nx = i, ny = wy + 1;
                if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && a[nx][ny] == '.') {
                    g[i][j].push_back({nx, ny, 1});
                }
            }
            // 向右发射
            auto it_right = idx[i].upper_bound(j);
            if (it_right != idx[i].end()) {
                int wy = *it_right;
                int nx = i, ny = wy - 1;
                if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && a[nx][ny] == '.') {
                    g[i][j].push_back({nx, ny, 1});
                }
            }
        }
    }

    Dijkstra();
#ifdef DEBUG_TEST
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cerr << dist[i][j] << " ";
        }
        cerr << "\n";
    }
#endif
#ifdef DEBUG_RECALL
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (auto [nx, ny, nd] : g[i][j]) {
                cerr << "{" << i << "," << j << "}" << " " << "{" << nx << "," << ny << "}" << " "
                     << nd << endl;
            }
        }
    }
#endif
    return 0;
}
```

为什么这个想法是错误的呢？

反例：

```plaintext
4 6
S...#.
##....
......
C#...#
```

假设我们的走法是红色，正确走法是绿色，就有下图：

![](https://cdn.luogu.com.cn/upload/image_hosting/7drzkv3j.png)

看出不同了吗？最大的问题是，我们没有理清题意，题意说的是可以向上、下、左、右四个方向发射传送门，然后这两个传送门之间可以相互传送。也就是说传送门不是单独的类似于象棋里的车的概念！传送门是成对的！

还有一点就是这里的终点是 $\tt{C}$，而不是 $\tt{E}$。（~~估计这种错误也只有我会犯~~）

## 正确实现
