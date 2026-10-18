#include <bits/stdc++.h>
using namespace std;

const int N = 25 + 5;

char s[N][N], c;
int n, len[N], u[N], ans;

inline void input() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> s[i] + 1;
        len[i] = strlen(s[i] + 1);
    }
    cin >> c;
}

inline void dfs(int t, int d) {
    if (d > ans) {
        ans = d;
    }
    for (int i = 1; i <= n; ++i) {
        if (u[i] >= 2) {
            continue;
        }
        int a = len[t], b = len[i], m = a < b ? a : b;
        for (int k = m; k >= 1; --k) {
            bool ok = 1;
            for (int j = 0; j < k; ++j) {
                if (s[t][a - k + 1 + j] != s[i][1 + j]) {
                    ok = 0;
                }
            }
            if (!ok) {
                continue;
            }
            ++u[i];
            dfs(i, d + b - k);
            --u[i];
            break;
        }
    }
}

inline void solve() {
    for (int i = 1; i <= n; ++i) {
        if (s[i][1] != c) {
            continue;
        }
        ++u[i];
        dfs(i, len[i]);
        --u[i];
    }
    cout << ans << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    solve();
    return 0;
}
