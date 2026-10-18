#include <bits/stdc++.h>
using namespace std;

long long a;

inline void solve() {
    cout << (a & -a) << "\n";
    return;
}

inline void input() {
    while (cin >> a && a) {
        solve();
    }
    return;
}

signed main() {
    input();
    return 0;
}