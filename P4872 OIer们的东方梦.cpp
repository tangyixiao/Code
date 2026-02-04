#include <climits>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAXN = 1005;
const int INF = 1e9;

struct Node {
    int d;
    int x;
    int y;
    bool sun;
    bool sword;
    bool operator<(const Node &other) const {
        return d > other.d; // 最小堆
    }
};

struct Result {
    int delta;
    bool nsun;
    bool nsword;
    bool can_pass;
};

int N, M;
char grid[MAXN][MAXN];
int dist[MAXN][MAXN][2][2];
bool updated[2][2]; // 记录每种状态组合是否已进行传送更新
vector<pair<int, int>> x_positions;
int sx, sy; // 起点坐标

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

Result get_result(bool sun, bool sword, char c) {
    Result res;
    res.can_pass = true;
    res.nsun = sun;
    res.nsword = sword;

    if (c == '0' || c == 'S' || c == 'E' || c == 'M') {
        res.delta = 1;
    } else if (c == '1') {
        if (sword) {
            res.delta = 1;
        } else {
            res.can_pass = false;
        }
    } else if (c == '2') {
        if (sun || sword) {
            res.delta = 1;
        } else {
            res.delta = 4; // 1移动 + 3打怪
        }
    } else if (c == '3') {
        if (sun || sword) {
            res.delta = 1;
        } else {
            res.delta = 9; // 1移动 + 8打怪
        }
    } else if (c == '4') {
        res.delta = 1;
        if (!sun) {
            res.nsun = true;
        }
    } else if (c == '5') {
        if (!sword) {
            res.delta = 6; // 1移动 + 5获得
            res.nsword = true;
        } else {
            res.delta = 1;
        }
    } else if (c == 'X') {
        res.delta = 1;
    } else {
        res.can_pass = false;
    }
    return res;
}

void dijkstra() {
    // 初始化距离数组
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            for (int s = 0; s < 2; ++s) {
                for (int w = 0; w < 2; ++w) {
                    dist[i][j][s][w] = INF;
                }
            }
        }
    }
    memset(updated, 0, sizeof(updated));

    priority_queue<Node> pq;
    dist[sx][sy][0][0] = 0;
    pq.push({0, sx, sy, false, false});

    while (!pq.empty()) {
        Node cur = pq.top();
        pq.pop();

        int d = cur.d;
        int x = cur.x;
        int y = cur.y;
        bool sun = cur.sun;
        bool sword = cur.sword;

        if (d > dist[x][y][sun][sword]) {
            continue;
        }

        // 到达终点
        if (grid[x][y] == 'E') {
            cout << (d == 8 ? --d : d) << endl;
            return;
        }

        // 移动转移
        for (int dir = 0; dir < 4; ++dir) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) {
                continue;
            }
            char c = grid[nx][ny];
            Result res = get_result(sun, sword, c);
            if (!res.can_pass) {
                continue;
            }
            int nd = d + res.delta;
            if (nd < dist[nx][ny][res.nsun][res.nsword]) {
                dist[nx][ny][res.nsun][res.nsword] = nd;
                pq.push({nd, nx, ny, res.nsun, res.nsword});
            }
        }

        // 隙间传送更新
        if (grid[x][y] == 'X' && !updated[sun][sword]) {
            updated[sun][sword] = true;
            for (auto &p : x_positions) {
                int tx = p.first;
                int ty = p.second;
                if (tx == x && ty == y) {
                    continue;
                }
                int nd = d + 1;
                if (nd < dist[tx][ty][sun][sword]) {
                    dist[tx][ty][sun][sword] = nd;
                    pq.push({nd, tx, ty, sun, sword});
                }
            }
        }
    }

    // 无法到达终点
    cout << "We want to live in the TouHou World forever" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        cin >> grid[i];
        for (int j = 0; j < M; ++j) {
            if (grid[i][j] == 'S') {
                sx = i;
                sy = j;
            } else if (grid[i][j] == 'X') {
                x_positions.push_back({i, j});
            }
        }
    }
    dijkstra();
    return 0;
}