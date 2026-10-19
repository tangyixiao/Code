#include <bits/stdc++.h>
using namespace std;

const int N = 1000 + 5;

int n, m, a[N][N];

inline void input() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    return;
}

inline void solve() {
    int o = 0, in = 0, e = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (!a[i][j]) {
                continue;
            }
            e++;
            if (i == m) {
                o++;
            }
            if (j == m) {
                in++;
            }
        }
    }
    cout << m << " " << o << " " << in << "\n"
         << e << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}