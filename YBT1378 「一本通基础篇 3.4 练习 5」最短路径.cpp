#include <bits/stdc++.h>
using namespace std;

const int N = 5e2 + 5, M = 1e8 + 5;
int n, s, d[N];
int w[N][N];

inline void input() {
    cin >> n >> s;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            string t;
            cin >> t;
            w[i][j] = t == "-" ? M : atoi(t.c_str());
        }
    }
}

inline void solve() {
    for (int i = 1; i <= n; ++i) {
        d[i] = M;
    }
    d[s] = 0;
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                d[i] = min(d[i], d[j] + w[j][i]);
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (i != s) {
            cout << "(" << s << " -> " << i << ") = " << d[i] << "\n";
        }
    }
    return;
}

signed main() {
    input();
    solve();
    return 0;
}