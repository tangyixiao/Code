#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 5;
int k[N], g[N][N], d[N];
int q[N * 20];
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, a, b;
    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++) {
        cin >> k[i];
        for (int j = 1; j <= k[i]; j++) {
            cin >> g[i][j];
        }
        d[i] = -1;
    }
    deque<int> q;
    d[a] = 0;
    q.push_back(a);
    for (; !q.empty();) {
        int u = q.front();
        q.pop_front();
        for (int j = 1; j <= k[u]; j++) {
            int v = g[u][j], w = (j == 1 ? 0 : 1);
            if (d[v] < 0 || d[u] + w < d[v]) {
                d[v] = d[u] + w;
                if (w == 0) {
                    q.push_front(v);
                } else {
                    q.push_back(v);
                }
            }
        }
    }
    cout << d[b] << "\n";
    return 0;
}
