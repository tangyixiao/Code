#include <bits/stdc++.h>
using namespace std;

int n;

inline void input() {
    cin >> n;
}

inline void solve() {
    double s = 1, f = 1;
    for (int i = 1; i <= n; ++i) {
        f /= i;
        s += f;
    }
    cout << fixed << setprecision(10) << s << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}