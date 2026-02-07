#include <bits/stdc++.h>
#define Judge
#define DEBUG
using namespace std;
namespace IO {
inline void Init_IO() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return;
}
} // namespace IO
using namespace IO;
namespace FILE_IO {
const string Insuffix = ".in";
const string Outsuffix = ".out";
const string Anssuffix = ".ans";
inline void Judge_File(string File_Name) {
    freopen((File_Name + Insuffix).c_str(), "r", stdin);
    freopen((File_Name + Outsuffix).c_str(), "w", stdout);
    return;
}
inline void Local_File(string File_Name, int File_Idx) {
    freopen((File_Name + to_string(File_Idx) + Insuffix).c_str(), "r", stdin);
    freopen((File_Name + to_string(File_Idx) + Outsuffix).c_str(), "w", stdout);
    return;
}
} // namespace FILE_IO
using namespace FILE_IO;
namespace TIME {
clock_t Start_Time, End_Time;
inline void Start_Time_Count() {
    Start_Time = clock();
    return;
}
inline void End_Time_Count() {
    End_Time = clock();
    return;
}
inline double Time_Count() {
    double Time = (double)(End_Time - Start_Time) / CLOCKS_PER_SEC;
    return Time;
}
inline void Print_Time_Count(string Programe_Name) {
    cerr << fixed << setprecision(4) << "\n" << Programe_Name << " Time: " << Time_Count() << "s\n";
    return;
}
} // namespace TIME
using namespace TIME;
const int N = 65, dx[] = {1, -1, 0, 0, 0, 0}, dy[] = {0, 0, 1, -1, 0, 0},
          dz[] = {0, 0, 0, 0, 1, -1};
int l, w, h, m, cnt, c[N][N][N];
bool vis[N][N][N];
struct node {
    int x, y, z;
};
inline void dfs(int x, int y, int z) {
    queue<node> q;
    q.push({x, y, z});
    while (!q.empty()) {
        node now = q.front();
        q.pop();
        for (int i = 0; i < 6; i++) {
            int nx = now.x + dx[i], ny = now.y + dy[i], nz = now.z + dz[i];
            if (nx < 1 || nx > l || ny < 1 || ny > w || nz < 1 || nz > h)
                continue;
            if (abs(c[now.x][now.y][now.z] - c[nx][ny][nz]) <= m && !vis[nx][ny][nz]) {
                vis[nx][ny][nz] = true;
                q.push({nx, ny, nz});
            }
        }
    }
    return;
}
inline void solve() {
    cin >> l >> w >> h;
    cin >> m;
    for (int i = 1; i <= l; i++) {
        for (int j = 1; j <= w; j++) {
            for (int k = 1; k <= h; k++) {
                cin >> c[i][j][k];
            }
        }
    }

    for (int i = 1; i <= l; i++) {
        for (int j = 1; j <= w; j++) {
            for (int k = 1; k <= h; k++) {
                if (!vis[i][j][k]) {
                    vis[i][j][k] = true;
                    dfs(i, j, k);
                    cnt++;
                }
            }
        }
    }
    cout << cnt << "\n";
    return;
}
signed main() {
    Init_IO();
#ifdef Judge
    Judge_File("scan");
#else
    Local_File("scan", 0);
#endif
    solve();
    return 0;
}