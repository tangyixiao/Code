#pragma G++ optimize("O3", "unroll-loops", "omit-frame-pointer", "inline")
#include <bits/stdc++.h>
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
inline void Judge_File(string Name) {
    freopen((Name + Insuffix).c_str(), "r", stdin);
    freopen((Name + Outsuffix).c_str(), "w", stdout);
    return;
}
inline void Local_File(string Name, int Idx) {
    freopen((Name + to_string(Idx) + Insuffix).c_str(), "r", stdin);
    freopen((Name + to_string(Idx) + Outsuffix).c_str(), "w", stdout);
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
inline void Print_Time_Count() {
    cerr << fixed << setprecision(4) << "Time: " << Time_Count() << "s\n";
    return;
}
} // namespace TIME
using namespace TIME;
#define ull unsigned long long
using namespace std;
const int N = 9;
const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int k;
long long ans;
char mp[N][N];
string goal;
unordered_map<ull, int> lmap[N][N];
unordered_map<ull, int> rmap[N][N];
inline void ldfs(int x, int y, int dep, int st, ull mask) {
    if (dep == st) {
        lmap[x][y][mask]++;
        return;
    }
    char nxt = goal[dep];
    for (int d = 0; d < 8; d++) {
        int nx = x + dx[d], ny = y + dy[d];
        if (nx >= 1 && nx <= 8 && ny >= 1 && ny <= 8) {
            if (mp[nx][ny] == nxt) {
                ull bit = 1ULL << ((nx << 3) + ny);
                if (!(mask & bit)) {
                    ldfs(nx, ny, dep + 1, st, mask | bit);
                }
            }
        }
    }
    return;
}

inline void rdfs(int x, int y, int dep, int st, ull mask) {
    if (dep == st) {
        rmap[x][y][mask]++;
        return;
    }
    char nxt = goal[k - 1 - dep];
    for (int d = 0; d < 8; d++) {
        int nx = x + dx[d], ny = y + dy[d];
        if (nx >= 1 && nx <= 8 && ny >= 1 && ny <= 8) {
            if (mp[nx][ny] == nxt) {
                ull bit = 1ULL << ((nx << 3) + ny);
                if (!(mask & bit)) {
                    rdfs(nx, ny, dep + 1, st, mask | bit);
                }
            }
        }
    }
    return;
}
#define DEBUG
signed main() {
    Init_IO();
#ifdef DEBUG
    Start_Time_Count();
#endif
    cin >> k;
    cin >> goal;
    for (int i = 1; i <= 8; i++) {
        for (int j = 1; j <= 8; j++) {
            cin >> mp[i][j];
        }
    }
    if (k == 1) {
        for (int i = 1; i <= 8; i++) {
            for (int j = 1; j <= 8; j++) {
                if (mp[i][j] == goal[0]) {
                    ans++;
                }
            }
        }
        cout << ans << "\n";
        exit(0);
    }
#ifdef DEBUG
    End_Time_Count();
    cerr << "Pre Time: ";
    Print_Time_Count();
#endif

#ifdef DEBUG
    Start_Time_Count();
#endif
    int llen = k >> 1, rlen = k - llen;
    for (int i = 1; i <= 8; i++) {
        for (int j = 1; j <= 8; j++) {
            if (mp[i][j] == goal[0]) {
                ldfs(i, j, 1, llen, 1ULL << ((i << 3) + j));
            }
        }
    }

#ifdef DEBUG
    End_Time_Count();
    cerr << "Ldfs Time: ";
    Print_Time_Count();
#endif
#ifdef DEBUG
    Start_Time_Count();
#endif
    for (int i = 1; i <= 8; i++) {
        for (int j = 1; j <= 8; j++) {
            if (mp[i][j] == goal[k - 1]) {
                rdfs(i, j, 1, rlen, 1ULL << ((i << 3) + j));
            }
        }
    }
#ifdef DEBUG
    End_Time_Count();
    cerr << "Rdfs Time: ";
    Print_Time_Count();
#endif

#ifdef DEBUG
    Start_Time_Count();
#endif
    for (int i = 1; i <= 8; i++) {
        for (int j = 1; j <= 8; j++) {
            if (!lmap[i][j].empty()) {
                for (int d = 0; d < 8; d++) {
                    int nx = i + dx[d], ny = j + dy[d];
                    if (nx >= 1 && nx <= 8 && ny >= 1 && ny <= 8) {
                        if (!rmap[nx][ny].empty()) {
                            for (auto [lmask, lcnt] : lmap[i][j]) {
                                for (auto [rmask, rcnt] : rmap[nx][ny]) {
                                    if (!(lmask & rmask)) {
                                        ans += 1LL * lcnt * rcnt;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

#ifdef DEBUG
    End_Time_Count();
    cerr << "Solve Time: ";
    Print_Time_Count();
#endif
    cout << ans << "\n";
    return 0;
}