#include <bits/stdc++.h>
using namespace std;

int n;
double x;

inline void input() {
    cin >> n >> x;
    return;
}

inline double h(int k, double y) {
    if (k == 0) {
        return 1;
    }
    if (k == 1) {
        return 2 * y;
    }
    return 2 * y * h(k - 1, y) - 2.0 * (k - 1) * h(k - 2, y);
}

inline void solve() {
    cout << fixed << setprecision(2) << h(n, x) << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}