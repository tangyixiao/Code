#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int n;

inline void input() {
    cin >> n;
}

inline void solve() {
    double s = 1;
    for (int i = 1; i <= n; ++i) {
        s = 1.0 / (i + s);
    }
    printf("%.5f\n", s);
    return;
}

signed main() {
    input();
    solve();
    return 0;
}