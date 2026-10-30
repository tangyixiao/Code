//  Author: Tangyixiao
//  Time: 2026-10-30 21:30:33
//  Problem: P4779 【模板】单源最短路径（标准版）
//  Contest: Luogu
//  URL: https://www.luogu.com.cn/problem/P4779
//  Memory Limit: 512 MB
//  Time Limit: 1000 ms
//  Interactive: false
//  Test Type: single
//
//  Algorithm:
//  Complexity: O()
//  Note:
//
//  Powered by Visual Studio Code + CPH (Competitive Programming Helper)

#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 10, inf = 1e18;
struct edge {
    int v, w;
};
struct node {
    int dis, u;
    bool operator>(const node &a) const {
        return dis > a.dis;
    }
};
int n, m, s, dis[N];
bool vis[N];
vector<edge> e[N];
priority_queue<node, vector<node>, greater<node>> q;
inline void dijkstra() {
    for (int i = 1; i <= n; i++) {
        dis[i] = inf;
        vis[i] = false;
    }
    dis[s] = 0;
    q.push({0, s});
    while (!q.empty()) {
        int u = q.top().u;
        q.pop();
        if (!vis[u]) {
            vis[u] = true;
            for (auto ed : e[u]) {
                int v = ed.v, w = ed.w;
                if (dis[v] > dis[u] + w) {
                    dis[v] = dis[u] + w;
                    q.push({dis[v], v});
                }
            }
        }
    }
    return;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m >> s;
    for (int i = 1, iu, iv, iw; i <= m; i++) {
        cin >> iu >> iv >> iw;
        e[iu].push_back(edge{iv, iw});
    }
    dijkstra();
    for (int i = 1; i <= n; i++) {
        cout << dis[i] << " ";
    }
    return 0;
}