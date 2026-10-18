#include <bits/stdc++.h>
using namespace std;

int n, q = 2, p = 1;
double s;

inline void input() {
    cin >> n;
    return;
}

inline void solve() {
    for (int i = 1; i <= n; i++) {
        int t = q;
        s += (double)q / p, q = q + p, p = t;
    }
    cout << fixed << setprecision(4) << s << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}