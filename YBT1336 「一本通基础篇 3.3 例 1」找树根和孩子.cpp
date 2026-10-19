#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int n, m;
int fa[N], deg[N], son[N][N];

inline void input() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        fa[y] = x, deg[x]++, son[x][deg[x]] = y;
    }
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    int rt = 1;
    while (fa[rt]) {
        rt = fa[rt];
    }
    int p = 1;
    for (int i = 2; i <= n; i++) {
        if (deg[i] > deg[p]) {
            p = i;
        }
    }
    cout << rt << "\n";
    cout << p << "\n";
    for (int i = 1; i <= deg[p]; i++) {
        cout << son[p][i] << " \n"[i == deg[p]];
    }
    return 0;
}