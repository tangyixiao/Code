#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9, dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};

int main() {
    int R, C;
    cin >> R >> C;
    vector<string> grid(R);
    for (int i = 0; i < R; ++i) {
        cin >> grid[i];
    }

    vector<vector<int>> island_id(R, vector<int>(C, -1));
    vector<vector<pair<int, int>>> islands;
    int island_cnt = 0;

    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            if (grid[i][j] == 'X' && island_id[i][j] == -1) {
                vector<pair<int, int>> cells;
                deque<pair<int, int>> q;
                q.push_back({i, j});
                island_id[i][j] = island_cnt;
                cells.push_back({i, j});

                while (!q.empty()) {
                    auto [x, y] = q.front();
                    q.pop_front();
                    for (int d = 0; d < 4; ++d) {
                        int nx = x + dx[d], ny = y + dy[d];
                        if (nx >= 0 && nx < R && ny >= 0 && ny < C &&
                            grid[nx][ny] == 'X' && island_id[nx][ny] == -1) {
                            island_id[nx][ny] = island_cnt;
                            q.push_back({nx, ny});
                            cells.push_back({nx, ny});
                        }
                    }
                }
                islands.push_back(cells);
                ++island_cnt;
            }
        }
    }

    int N = island_cnt;
    vector<vector<int>> dist(N, vector<int>(N, INF));

    for (int i = 0; i < N; ++i) {
        vector<int> d(R * C, INF);
        deque<int> dq;

        for (auto [x, y] : islands[i]) {
            int idx = x * C + y;
            d[idx] = 0;
            dq.push_back(idx);
        }

        while (!dq.empty()) {
            int cur = dq.front();
            dq.pop_front();
            int x = cur / C, y = cur % C;
            int curd = d[cur];

            for (int dir = 0; dir < 4; ++dir) {
                int nx = x + dx[dir], ny = y + dy[dir];
                if (nx < 0 || nx >= R || ny < 0 || ny >= C) {
                    continue;
                }
                char ch = grid[nx][ny];
                if (ch != '.') {
                    int nid = nx * C + ny;
                    int nd = curd + (ch == 'S' ? 1 : 0);
                    if (nd < d[nid]) {
                        d[nid] = nd;
                        if (ch == 'S') {
                            dq.push_back(nid);
                        } else {
                            dq.push_front(nid);
                        }
                    }
                }
            }
        }

        for (int j = 0; j < N; ++j) {
            if (i == j) {
                dist[i][j] = 0;
                continue;
            }
            int mind = INF;
            for (auto [x, y] : islands[j]) {
                int idx = x * C + y;
                mind = min(mind, d[idx]);
            }
            dist[i][j] = mind;
        }
    }

    int fullmask = (1 << N) - 1;
    vector<vector<int>> dp(fullmask + 1, vector<int>(N, INF));

    for (int i = 0; i < N; ++i) {
        dp[1 << i][i] = 0;
    }

    for (int mask = 1; mask <= fullmask; ++mask) {
        for (int i = 0; i < N; ++i) {
            if (!(mask & (1 << i)))
                continue;
            if (dp[mask][i] >= INF)
                continue;
            for (int j = 0; j < N; ++j) {
                if (mask & (1 << j))
                    continue;
                int newmask = mask | (1 << j);
                dp[newmask][j] = min(dp[newmask][j], dp[mask][i] + dist[i][j]);
            }
        }
    }

    int ans = INF;
    for (int i = 0; i < N; ++i) {
        ans = min(ans, dp[fullmask][i]);
    }
    cout << ans << endl;

    return 0;
}