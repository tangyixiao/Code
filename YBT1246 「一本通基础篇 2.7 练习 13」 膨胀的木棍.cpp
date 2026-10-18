#include <bits/stdc++.h>
using namespace std;

const double P = 3.14159265358979323846;

double l, n, c, r;

inline void input() {
    cin >> l >> n >> c;
    return;
}

inline void solve() {
    double k = 1 + n * c, a = 1e-12, b = P, m;
    for (int i = 0; i < 100; ++i) {
        m = (a + b) / 2;
        if (m / sin(m) < k) {
            a = m;
        } else {
            b = m;
        }
    }
    m = (a + b) / 2;
    r = l / (2 * sin(m)) * (1 - cos(m));
    printf("%.3f\n", r);
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    solve();
    return 0;
}
