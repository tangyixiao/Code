#include <bits/stdc++.h>
using namespace std;
const int N = 21;
int n, w[N], ans;
bool path[N];
vector<int> g[N];
vector<int> res;
inline void dfs(int u, int sw) {
    if (sw > ans) {
        ans = sw;
        res.clear();
        for (int i = 1; i <= n; i++) {
            if (path[i]) {
                res.push_back(i);
            }
        }
    }
    for (int v : g[u]) {
        path[v] = true;
        dfs(v, sw + w[v]);
        path[v] = false;
    }
    return;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
    }
    for (int i = 1; i <= n - 1; i++) {
        for (int j = i + 1; j <= n; j++) {
            bool flag;
            cin >> flag;
            if (flag) {
                g[i].push_back(j);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        path[i] = true;
        dfs(i, w[i]);
        path[i] = false;
    }
    for (int i : res) {
        cout << i << " ";
    }
    cout << "\n" + to_string(ans) + "\n";
    return 0;
}