#include <bits/stdc++.h>
using namespace std;

int n;

inline void input() { cin >> n; }

inline void solve() {
    cout << n % 10 * 100 + n / 10 % 10 * 10 + n / 100 << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}