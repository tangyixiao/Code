#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;
int n, a[N];

inline void input() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
}

inline void solve() {
    double s = 0;
    for (int i = 1; i <= n; ++i) {
        s += a[i];
    }
    cout << fixed << setprecision(2) << s / n << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}