#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;
int n, m, f[N];

inline void input() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int v, w, s;
        cin >> v >> w >> s;
        for (int j = m; j >= v; j--) {
            for (int k = 1; k <= s && k * v <= j; k++) {
                f[j] = max(f[j], f[j - k * v] + k * w);
            }
        }
    }
    return;
}

inline void solve() {
    cout << f[m] << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
