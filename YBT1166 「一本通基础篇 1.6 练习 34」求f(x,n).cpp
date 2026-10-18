#include <bits/stdc++.h>
using namespace std;

int n;
double x, s;

inline void input() {
    cin >> x >> n;
    return;
}

inline void solve() {
    s = sqrt(1 + x);
    for (int i = 2; i <= n; i++) {
        s = sqrt(i + s);
    }
    cout << fixed << setprecision(2) << s << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}