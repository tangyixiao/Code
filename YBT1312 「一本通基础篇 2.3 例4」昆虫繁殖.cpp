#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;
int x, y, z;
long long f[N], b[N];

inline void input() {
    cin >> x >> y >> z;
    if (x == 0) {
        x = 1;
    }
    return;
}

inline void solve() {
    b[1] = 1;
    for (int t = 1; t <= z; t++) {
        long long s = 0;
        for (int i = 1; i <= t; i++) {
            int d = i == 1 ? 0 : 1;
            if (t >= i + d && (t - i - d) % x == 0) {
                s += b[i];
            }
        }
        if (t + 2 <= z) {
            b[t + 2] = y * s;
        }
        f[t] = f[t - 1] + b[t];
    }
    cout << f[z] << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}