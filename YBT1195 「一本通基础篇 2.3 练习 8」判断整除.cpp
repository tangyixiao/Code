#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;
const int M = 1e2 + 5;

int f[2][M], a[N], n, k;

inline void input() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] %= k;
    }
    return;
}

inline void solve() {
    int p = 0;
    memset(f, 0, sizeof(f));
    f[p][0] = 1;
    for (int i = 1; i <= n; ++i) {
        int q = p ^ 1;
        memset(f[q], 0, sizeof(f[q]));
        for (int j = 0; j < k; ++j) {
            f[q][(j + a[i]) % k] |= f[p][j];
            f[q][(j - a[i] + k) % k] |= f[p][j];
        }
        p = q;
    }
    cout << (f[p][0] ? "YES" : "NO") << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    solve();
    return 0;
}
