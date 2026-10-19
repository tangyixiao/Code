#include <bits/stdc++.h>
using namespace std;

const int N = 3e1 + 5;
int n, a[N], b[N];

inline void input() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> b[i];
    }
}

inline void solve() {
    double x = 1.0 * b[1] / a[1];
    for (int i = 2; i <= n; ++i) {
        double y = 1.0 * b[i] / a[i];
        if (y - x > 0.05) {
            cout << "better\n";
        } else if (x - y > 0.05) {
            cout << "worse\n";
        } else {
            cout << "same\n";
        }
    }
    return;
}

signed main() {
    input();
    solve();
    return 0;
}