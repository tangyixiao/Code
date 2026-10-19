#include <bits/stdc++.h>
using namespace std;

int n;

inline void input() {
    cin >> n;
}

inline void solve() {
    cout << (n % 3 == 0 && n % 5 == 0 ? "YES" : "NO") << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}