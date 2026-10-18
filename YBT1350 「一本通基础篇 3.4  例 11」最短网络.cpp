#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;
int n, g[N][N], d[N], v[N * N], c;
bool vis[N];

inline void input() {
    cin >> n;
    c = 0;
    int x = 0;
    bool f = 0;
    char ch;
    while (cin.get(ch)) {
        if (ch >= '0' && ch <= '9') {
            x = x * 10 + ch - '0';
            f = 1;
        } else if (f) {
            v[c++] = x;
            x = 0;
            f = 0;
        }
    }
    if (f) {
        v[c++] = x;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            g[i][j] = v[(i - 1) * n + j - 1];
        }
    }
}

inline void solve() {
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        d[i] = g[1][i];
    }
    vis[1] = 1;
    for (int k = 2; k <= n; k++) {
        int t = 0;
        for (int i = 1; i <= n; i++) {
            if (!vis[i] && (t == 0 || d[i] < d[t])) {
                t = i;
            }
        }
        vis[t] = 1;
        ans += d[t];
        for (int i = 1; i <= n; i++) {
            if (!vis[i] && g[t][i] < d[i]) {
                d[i] = g[t][i];
            }
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
