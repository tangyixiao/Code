#include <bits/stdc++.h>
using namespace std;

const int N = 105;
int xa, ya, xb, yb, d[N][N];
int dx[12] = {1, 2, 2, 1, -1, -2, -2, -1, 2, 2, -2, -2};
int dy[12] = {2, 1, -1, -2, -2, -1, 1, 2, 2, -2, 2, -2};
int que[N * N][2];

inline void input() {
    cin >> xa >> ya >> xb >> yb;
    return;
}

inline int bfs(int x, int y) {
    for (int i = 1; i <= 100; i++) {
        for (int j = 1; j <= 100; j++) {
            d[i][j] = -1;
        }
    }
    int h = 0, t = 0;
    que[t][0] = x, que[t][1] = y, t++;
    d[x][y] = 0;
    while (h < t) {
        int a = que[h][0], b = que[h][1];
        h++;
        if (a == 1 && b == 1) {
            return d[a][b];
        }
        for (int i = 0; i < 12; i++) {
            int p = a + dx[i], q = b + dy[i];
            if (p < 1 || p > 100 || q < 1 || q > 100) {
                continue;
            }
            if (d[p][q] != -1) {
                continue;
            }
            d[p][q] = d[a][b] + 1;
            que[t][0] = p, que[t][1] = q, t++;
        }
    }
    return 0;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    cout << bfs(xa, ya) << "\n";
    cout << bfs(xb, yb) << "\n";
    return 0;
}