#include <bits/stdc++.h>
using namespace std;
int n, k, parent[1001], family[1001], w, siz;
inline int find(int x) {
    if (x == parent[x])
        return x;
    return parent[x] = find(parent[x]);
}
inline void merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y)
        return;
    if (family[x] < family[y]) {
        swap(x, y);
    }
    parent[y] = x;
    family[x] += family[y];
    return;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        family[i] = 1;
    }
    for (int i = 1, u, v; i <= k; i++) {
        cin >> u >> v;
        if (find(u) != find(v)) {
            merge(u, v);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (parent[i] == i) {
            siz++;
            w = max(w, family[i]);
        }
    }
    cout << siz << " " << w << endl;
    return 0;
}