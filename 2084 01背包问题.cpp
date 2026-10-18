#include <bits/stdc++.h>
using namespace std;

const int N = 2e4 + 5;

int m, n, f[N];

inline void input() {
    cin >> m >> n;
}

inline void solve() {
    for (int i = 1; i <= n; ++i) {
        int w, c;
        cin >> w >> c;
        for (int j = m; j >= w; --j) {
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
