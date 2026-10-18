#include <bits/stdc++.h>
using namespace std;

long long n, x, y;

inline void input() {
    cin >> n >> x >> y;
}

inline void solve() {
    cout << n - (y + x - 1) / x << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}
