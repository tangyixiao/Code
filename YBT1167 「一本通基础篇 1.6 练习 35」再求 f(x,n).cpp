#include <bits/stdc++.h>
using namespace std;

double x;
int n;

inline void input() {
    cin >> x >> n;
    return;
}

inline double f(int k) {
    if (k == 1) {
        return x / (1 + x);
    }
    return x / (k + f(k - 1));
}

inline void solve() {
    cout << fixed << setprecision(2) << f(n) << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}