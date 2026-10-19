#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int f;
vector<int> e[N], ans;

void dfs(int u) {
    while (!e[u].empty()) {
        sort(e[u].begin(), e[u].end());
        int v = e[u][0];
        e[u].erase(e[u].begin());
        for (int i = 0; i < e[v].size(); ++i) {
            if (e[v][i] == u) {
                e[v].erase(e[v].begin() + i);
                break;
            }
        }
        dfs(v);
    }
    ans.push_back(u);
    return;
}

inline void input() { cin >> f; }

inline void solve() {
    for (int i = 1; i <= f; ++i) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v), e[v].push_back(u);
    }
    int s = 0;
    for (int i = 1; i <= 5e2; ++i) {
        if (e[i].size() & 1) {
            s = i;
            break;
        }
    }
    if (!s) {
        for (int i = 1; i <= 5e2; ++i) {
            if (!e[i].empty()) {
                s = i;
                break;
            }
        }
    }
    dfs(s);
    for (int i = ans.size() - 1; i >= 0; --i) {
        cout << ans[i] << "\n";
    }
    return;
}

signed main() {
    input();
    solve();
    return 0;
}