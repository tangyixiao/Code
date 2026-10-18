#include <bits/stdc++.h>
using namespace std;

double x, r;
int n;

inline void input() {
    cin >> x >> n;
    return;
}

inline void solve() {
    r = x;
    for (int i = 1; i <= n; i++) {
        r *= 1.001;
    }
    cout << fixed << setprecision(4) << r << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}