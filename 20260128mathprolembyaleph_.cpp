#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 5;
vector<pair<int, int>> g[N];
int vis[N], step[N];
inline int classes(int x) {
    if (x <= 18)
        return 1;
    if (x <= 29)
        return 2;
    if (x <= 40)
        return 3;
    if (x <= 51)
        return 4;
    if (x <= 62)
        return 5;
    if (x <= 73)
        return 6;
    return 7;
}
inline void dfs(int u, int cnt) {

#ifdef DEBUG
    cout << "--------------\n";
    cout << "u: " << u << " cnt: " << cnt << "\n";
    for (int i = 1; i <= 7; i++) {
        cout << step[i] << " ";
    }
    cout << "\n";
    cout << "--------------\n";
#endif

    if (cnt == 7) {
        for (int i = 1; i <= 7; i++) {
            cout << step[i] << " ";
        }
        cout << "\n";
        return;
    }
    for (auto [v, c] : g[u]) {
        if (!vis[c]) {
            vis[c] = 1;
            step[cnt + 1] = v;
            dfs(v, cnt + 1);
            vis[c] = 0;
            step[cnt + 1] = 0;
        }
    }
    return;
}
signed main() {
    for (int i = 8; i <= 18; i++) {
        for (int j = 19; j <= 84; j++) {
            if (!(j % i)) {
                g[i].push_back({j, classes(j)});
                g[j].push_back({i, classes(i)});
            }
        }
    }
    for (int i = 19; i <= 29; i++) {
        for (int j = 30; j <= 84; j++) {
            if (!(j % i)) {
                g[i].push_back({j, classes(j)});
                g[j].push_back({i, classes(i)});
            }
        }
    }
    for (int i = 30; i <= 40; i++) {
        for (int j = 41; j <= 84; j++) {
            if (!(j % i)) {
                g[i].push_back({j, classes(j)});
                g[j].push_back({i, classes(i)});
            }
        }
    }
    for (int i = 41; i <= 51; i++) {
        for (int j = 52; j <= 84; j++) {
            if (!(j % i)) {
                g[i].push_back({j, classes(j)});
                g[j].push_back({i, classes(i)});
            }
        }
    }
    for (int i = 52; i <= 62; i++) {
        for (int j = 63; j <= 84; j++) {
            if (!(j % i)) {
                g[i].push_back({j, classes(j)});
                g[j].push_back({i, classes(i)});
            }
        }
    }
    for (int i = 63; i <= 73; i++) {
        for (int j = 74; j <= 84; j++) {
            if (!(j % i)) {
                g[i].push_back({j, classes(j)});
                g[j].push_back({i, classes(i)});
            }
        }
    }
    for (int i = 1; i <= 84; i++) {
        memset(vis, 0, sizeof(vis));
        memset(step, 0, sizeof(step));
        vis[classes(i)] = 1;
        step[1] = i;
        dfs(i, 1);
    }
    return 0;
}
