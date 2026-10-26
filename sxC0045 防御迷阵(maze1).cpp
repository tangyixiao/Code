#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, m, i, j, u, v, nd, ans;
int a[N], d[N];
bool vis[N];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
signed main() {
    scanf("%d%d", &n, &m);
    for (i = 0; i < n * m; i++) {
        scanf("%d", &a[i]);
        d[i] = 1e9;
    }
    for (j = 0; j < m; j++) {
        d[j] = a[j];
        pq.push(make_pair(d[j], j));
    }
    while (!pq.empty()) {
        pair<int, int> t = pq.top();
        pq.pop();
        u = t.second;
        if (vis[u]) {
            continue;
        }
        vis[u] = true;
        int x = u / m, y = u % m;
        for (int k = 0; k < 4; k++) {
            int dx = (k == 0 ? -1 : (k == 1 ? 1 : 0)), dy = (k == 2 ? -1 : (k == 3 ? 1 : 0));
            if (k == 0 || k == 1) {
                dy = 0;
            } else {
                dx = 0;
            }
            int nx = x + dx, ny = y + dy;
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                continue;
            }
            v = nx * m + ny;
            nd = max(d[u], a[v]);
            if (nd < d[v]) {
                d[v] = nd;
                pq.push(make_pair(nd, v));
            }
        }
    }
    ans = 1e9;
    for (j = 0; j < m; j++) {
        ans = min(ans, d[(n - 1) * m + j]);
    }
    printf("%d\n", ans);
    return 0;
}
