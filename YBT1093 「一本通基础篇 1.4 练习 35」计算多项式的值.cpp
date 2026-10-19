#include <bits/stdc++.h>
using namespace std;

double x, s, p;
int n;

inline void input() {
    cin >> x >> n;
    return;
}

inline void solve() {
    s = p = 1;
    for (int i = 1; i <= n; i++) {
        p *= x, s += p;
    }
    cout << fixed << setprecision(2) << s << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}