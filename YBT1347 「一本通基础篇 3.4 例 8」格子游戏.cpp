#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, m;
int fa[N];

inline void input() {
    cin >> n >> m;
    for (int i = 0; i <= n * n; i++) {
        fa[i] = i;
    }
    return;
}

inline int find(int p) {
    return fa[p] == p ? p : fa[p] = find(fa[p]);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    for (int i = 1; i <= m; i++) {
        int x, y;
        char c;
        cin >> x >> y >> c;
        int u = (x - 1) * n + y, v = c == 'D' ? u + n : u + 1;
        if (find(u) == find(v)) {
            cout << i << "\n";
            return 0;
        }
        fa[find(u)] = find(v);
    }
    cout << "draw\n";
    return 0;
}