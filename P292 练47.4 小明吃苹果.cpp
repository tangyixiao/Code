#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;

int n, f[N];

inline void input() {
    cin >> n;
}

inline void solve() {
    f[0] = f[1] = 1;
    for (int i = 2; i <= n; i++) {
        f[i] = f[i - 1] + (i >= 3 ? f[i - 3] : 0);
    }
    cout << f[n] << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
