#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;

int m, n, f[N];

inline void input() {
    cin >> m >> n;
}

inline void solve() {
    for (int i = 1; i <= n; ++i) {
        int w, c;
        cin >> w >> c;
        for (int j = w; j <= m; ++j) {
            f[j] = max(f[j], f[j - w] + c);
        }
    }
    cout << f[m] << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    solve();
    return 0;
}
