#include <bits/stdc++.h>
using namespace std;

int c;
double q;

inline void input() {
    int n, m;
    cin >> n >> m >> c;
    q = (m - n) * 1.0 / (m + n);
}

inline void solve() {
    printf("%.5f\n", (1 + pow(q, c)) / 2);
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    solve();
    return 0;
}
