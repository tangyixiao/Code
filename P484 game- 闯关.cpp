#include <bits/stdc++.h>
using namespace std;

const int N = 6500 + 5;
const int T = 105;

int n, m, t;
int a[N][T];
int head[N], nxt[N * 3 + 5], to[N * 3 + 5], ecnt;
long long dp[N];
int best[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> t;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= t; j++) {
            cin >> a[i][j];
        }
    }
    ecnt = 0;
    for (int i = 1; i <= n; i++) {
        head[i] = -1;
        best[i] = -1e9;
    }
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        to[ecnt] = v;
        nxt[ecnt] = head[u];
        head[u] = ecnt;
        ecnt++;
    }
    best[1] = 0;
    for (int j = 1; j <= t; j++) {
        for (int i = 1; i <= n; i++) {
            dp[i] = (long long)best[i] + a[i][j];
        }
        int changed = 1;
        for (; changed;) {
            changed = 0;
            for (int u = 1; u <= n; u++) {
                if (dp[u] <= -1e17) {
                    continue;
                }
                for (int e = head[u]; e != -1; e = nxt[e]) {
                    int v = to[e];
                    if (dp[v] < dp[u]) {
                        dp[v] = dp[u];
                        changed = 1;
                    }
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            best[i] = (int)dp[i];
        }
    }
    cout << best[n] << "\n";
    return 0;
}
