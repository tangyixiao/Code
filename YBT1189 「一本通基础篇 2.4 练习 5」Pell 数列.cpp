#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int f[N], n, x;

inline void input() {
    cin >> n;
    f[1] = 1, f[2] = 2;
    for (int i = 3; i <= 1e6; ++i) {
        f[i] = (2 * f[i - 1] + f[i - 2]) % 32767;
    }
}

inline void solve() {
    while (n--) {
        cin >> x;
        cout << f[x] << "\n";
    }
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    solve();
    return 0;
}
