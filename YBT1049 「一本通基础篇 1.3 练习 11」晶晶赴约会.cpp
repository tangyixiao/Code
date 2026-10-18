#include <bits/stdc++.h>
using namespace std;

int n;

inline void input() {
    cin >> n;
}

inline void solve() {
    cout << ((n == 1 || n == 3 || n == 5) ? "NO" : "YES") << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}
