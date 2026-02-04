#include <bits/stdc++.h>
using namespace std;
const int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0}, N = 1e3 + 5;
int n, m, st[N][N], di[N][N], a[N][N], b[N][N], c[N][N], d[N][N], e[N][N];
struct node {
    int x, y, z;
};
int main() {
    cin >> n >> m;
    int cx, cy, zx, zy;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char x;
            cin >> x;
            if (x == '#')
                st[i][j] = 1;
            if (x == 'C')
                cx = i, cy = j;
            if (x == 'F')
                zx = i, zy = j;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (st[i][j])
                a[i][j] = -1;
            else
                a[i][j] = a[i][j - 1] + 1;
        }
    }

    for (int i = 1; i <= n; i++) {
        int jl = 0;
        for (int j = m; j >= 1; j--) {
            if (st[i][j])
                b[i][j] = -1;
            else
                b[i][j] = b[i][j + 1] + 1;
        }
    }
    for (int j = 1; j <= m; j++) {
        for (int i = 1; i <= n; i++) {
            if (st[i][j])
                c[i][j] = -1;
            else
                c[i][j] = c[i - 1][j] + 1;
        }
    }
    for (int j = 1; j <= m; j++) {
        for (int i = n; i >= 1; i--) {
            if (st[i][j])
                d[i][j] = -1;
            else
                d[i][j] = d[i + 1][j] + 1;
        }
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            e[i][j] = min(a[i][j], min(b[i][j], min(c[i][j], d[i][j])));
    memset(di, 0x3f, sizeof di);
    di[cx][cy] = 0;
    queue<node> q;
    q.push({cx, cy, 0});
    while (q.size()) {
        auto [x, y, z] = q.front();
        q.pop();

        for (int i = 1; i <= 4; i++) {
            int cd = e[x][y] + 1, zd;
            int xx = x, yy = y;
            if (i == 1) {
                zd = a[x][y], yy -= zd;
            }
            if (i == 2) {
                zd = b[x][y], yy += zd;
            }
            if (i == 3) {
                zd = c[x][y], xx -= zd;
            }
            if (i == 4) {
                zd = d[x][y], xx += zd;
            }
            if (cd < zd) {
                if (z + cd < di[xx][yy]) {
                    di[xx][yy] = z + cd;
                    q.push({xx, yy, z + cd});
                }
            }
        }
        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (xx < 1 || xx > n || yy < 1 || yy > m || st[xx][yy] || z + 1 >= di[xx][yy]) {
                continue;
            }
            di[xx][yy] = z + 1;
            q.push({xx, yy, z + 1});
        }
    }
    if (di[zx][zy] == 0x3f3f3f3f) {
        cout << "nemoguce";
    } else {
        cout << di[zx][zy];
    }
    return 0;
}
