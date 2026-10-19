#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e6 + 5;

int n, m, hd[N], nx[N], to[N], du[N], f[N], q[N];
bool sd[N];

inline void input() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        to[i] = b, nx[i] = hd[a], hd[a] = i, du[b]++;
    }
    return;
}

inline void solve() {
    int ft = 0, bk = 0;
    for (int i = 1; i <= n; i++) {
        if (!du[i]) {
            f[i] = 1, q[bk++] = i;
        }
    }
    for (int i = 1; i <= n; i++) {
        sd[i] = du[i] > 0;
    }
    while (ft < bk) {
        int u = q[ft++];
        for (int e = hd[u]; e; e = nx[e]) {
            int v = to[e];
            f[v] += f[u];
            if (!--du[v]) {
                q[bk++] = v;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (!hd[i] && sd[i]) {
            ans += f[i];
        }
    }
    cout << ans << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}