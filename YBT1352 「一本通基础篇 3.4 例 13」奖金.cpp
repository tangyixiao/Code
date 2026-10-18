#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;
const int M = 2e4 + 5;
int n, m;
int hd[N], nx[M], to[M], deg[N], val[N], que[N];

inline void input() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        to[i] = a, nx[i] = hd[b], hd[b] = i;
        deg[a]++;
    }
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    int h = 0, t = 0;
    for (int i = 1; i <= n; i++) {
        if (!deg[i]) {
            que[t++] = i;
        }
    }
    while (h < t) {
        int u = que[h++];
        for (int i = hd[u]; i; i = nx[i]) {
            if (val[to[i]] < val[u] + 1) {
                val[to[i]] = val[u] + 1;
            }
            if (--deg[to[i]] == 0) {
                que[t++] = to[i];
            }
        }
    }
    if (t < n) {
        cout << "Poor Xed\n";
        return 0;
    }
    int s = 0;
    for (int i = 1; i <= n; i++) {
        s += max(val[i], 0) + 100;
    }
    cout << s << "\n";
    return 0;
}