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

const int N = 1e3 + 7;
int n, r, c;
char mp[N][N];
int s, t;
int lf[N][N], rg[N][N], up[N][N], dn[N][N];
vector<pair<int, int>> G[N * N];
int dis[N * N];
bool _vis[N * N];

struct node {
    int dis, id;
    friend bool operator<(node a, node b) { return a.dis > b.dis; }
};

void Dj(int s) {
    memset(_vis, 0, sizeof _vis);
    priority_queue<node> q;
    memset(dis, 80, sizeof dis);
    dis[s] = 0;
    q.push({0, s});
    while (!q.empty()) {
        int u = q.top().id;
        q.pop();
        if (_vis[u])
            continue;
        _vis[u] = 1;
        for (auto i : G[u]) {
            int k = i.first, w = i.second;
            if (dis[k] > dis[u] + w) {
                dis[k] = dis[u] + w;
                q.push({dis[k], k});
            }
        }
    }
    return;
}

bool query(int x, int y) { return (mp[x][y] == '.' || mp[x][y] == 'S' || mp[x][y] == 'C'); }

int get(int x, int y) { return x * c + y - c; }

void add(int u, int v, int w) {
    G[u].push_back(make_pair(v, w));
    return;
}

int main() {
    scanf("%d%d", &r, &c);
    n = r * c;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cin >> mp[i][j];
            if (mp[i][j] == 'S')
                s = get(i, j);
            if (mp[i][j] == 'C')
                t = get(i, j);
        }
    }
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            if (mp[i][j] == '#')
                lf[i][j] = j;
            else
                lf[i][j] = lf[i][j - 1];
        }
    }
    for (int j = 1; j <= c; j++) {
        for (int i = 1; i <= r; i++) {
            if (mp[i][j] == '#')
                up[i][j] = i;
            else
                up[i][j] = up[i - 1][j];
        }
    }
    for (int i = 1; i <= r; i++) {
        rg[i][c + 1] = c + 1;
        for (int j = c; j; j--) {
            if (mp[i][j] == '#')
                rg[i][j] = j;
            else
                rg[i][j] = rg[i][j + 1];
        }
    }
    for (int j = 1; j <= c; j++) {
        dn[r + 1][j] = r + 1;
        for (int i = r; i; i--) {
            if (mp[i][j] == '#')
                dn[i][j] = i;
            else
                dn[i][j] = dn[i + 1][j];
        }
    }
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            if (query(i, j)) {
                int L = lf[i][j] + 1, R = rg[i][j] - 1, U = up[i][j] + 1, D = dn[i][j] - 1;
                int _dis = min({j - L + 1, R - j + 1, i - U + 1, D - i + 1});
                int _L = get(i, L), _R = get(i, R), _U = get(U, j), _D = get(D, j);
                int _pos = get(i, j);
                add(_pos, _L, min(_dis, j - L)), add(_pos, _R, min(_dis, R - j)),
                    add(_pos, _U, min(_dis, i - U)), add(_pos, _D, min(_dis, D - i));
                if (query(i, j + 1))
                    add(_pos, get(i, j + 1), 1);
                if (query(i + 1, j))
                    add(_pos, get(i + 1, j), 1);
                if (query(i - 1, j))
                    add(_pos, get(i - 1, j), 1);
                if (query(i, j - 1))
                    add(_pos, get(i, j - 1), 1);
            }
        }
    }
    Dj(s);
    printf("%d\n", dis[t]);
    return 0;
}
