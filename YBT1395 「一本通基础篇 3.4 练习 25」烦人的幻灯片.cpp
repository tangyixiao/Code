#include <bits/stdc++.h>
using namespace std;

const int N = 30;
int n, xl[N], xr[N], yl[N], yr[N], px[N], py[N], g[N][N], mt[N], vis[N], ans[N];

bool aug(int u) {
    for (int v = 1; v <= n; ++v) {
        if (g[u][v] && !vis[v]) {
            vis[v] = 1;
            if (!mt[v] || aug(mt[v])) {
                mt[v] = u;
                return true;
            }
        }
    }
    return false;
}

inline void input() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> xl[i] >> xr[i] >> yl[i] >> yr[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> px[i] >> py[i];
    }
}

inline void solve() {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            g[i][j] = xl[i] <= px[j] && px[j] <= xr[i] && yl[i] <= py[j] && py[j] <= yr[i];
        }
    }
    for (int i = 1; i <= n; ++i) {
        memset(vis, 0, sizeof vis);
        if (!aug(i)) {
            cout << "None\n";
            return;
        }
    }
    for (int j = 1; j <= n; ++j) {
        ans[mt[j]] = j;
    }
    for (int i = 1; i <= n; ++i) {
        cout << char('A' + i - 1) << " " << ans[i] << "\n";
    }
    return;
}

signed main() {
    input();
    solve();
    return 0;
}