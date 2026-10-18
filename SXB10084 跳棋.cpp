#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
const int INF = 0x3f3f3f3f;

int n;
int a[N];
int f[N][N];

inline void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            f[i][j] = INF;
        }
    }
}

inline void solve() {
    f[2][1] = a[2];
    for (int k = 1; k < n; k++) {
        for (int p = n; p >= 1; p--) {
            if (f[p][k] == INF) {
                continue;
            }
            int u = p + k + 1, v = p - k;
            if (u <= n && f[u][k + 1] > f[p][k] + a[u]) {
                f[u][k + 1] = f[p][k] + a[u];
            }
            if (v >= 1 && f[v][k] > f[p][k] + a[v]) {
                f[v][k] = f[p][k] + a[v];
            }
        }
    }
    int ans = INF;
    for (int k = 1; k < n; k++) {
        ans = min(ans, f[n][k]);
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
