#include <bits/stdc++.h>
using namespace std;

const int N = 2e2 + 5;
int n, fa[N], cp[N];
double x[N], y[N], d[N][N], ew[N][N], ec[N];

inline int fd(int t) {
    return fa[t] == t ? t : fa[t] = fd(fa[t]);
}

inline void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
        fa[i] = i;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            char c;
            cin >> c;
            ew[i][j] = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
            d[i][j] = c == '1' ? ew[i][j] : 1e9;
            if (c == '1') {
                fa[fd(i)] = fd(j);
            }
        }
        d[i][i] = 0;
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (d[i][k] + d[k][j] < d[i][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cp[i] = fd(i);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (cp[i] == cp[j] && d[i][j] > ec[i]) {
                ec[i] = d[i][j];
            }
        }
    }
}

inline void solve() {
    double ans = 1e18;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (cp[i] != cp[j]) {
                ans = min(ans, ec[i] + ew[i][j] + ec[j]);
            }
        }
    }
    cout << fixed << setprecision(6) << ans << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
