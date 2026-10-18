#include <bits/stdc++.h>
using namespace std;

const int N = 2e4 + 5;
int n, m, fa[N];
string s, buf;

inline void input() {
    return;
}

inline int find(int p) {
    return fa[p] == p ? p : fa[p] = find(fa[p]);
}

inline void merge(int x, int y) {
    fa[find(x)] = find(y);
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
    }
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        merge(x, y);
    }
    cin >> m;
    while (m--) {
        int x, y;
        cin >> x >> y;
        cout << (find(x) == find(y) ? "Yes\n" : "No\n");
    }
    return 0;
}