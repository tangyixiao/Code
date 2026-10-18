#include <bits/stdc++.h>
using namespace std;

int n;
double s;

inline void input() {
    cin >> n;
    return;
}

inline void solve() {
    for (int i = 1; i <= n; i++) {
        if (i & 1) {
            s += 1.0 / i;
        } else {
            s -= 1.0 / i;
        }
    }
    cout << fixed << setprecision(4) << s << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}