#include <bits/stdc++.h>
using namespace std;

const int N = 1e9 + 5;

long long a, b;

inline void input() {
    cin >> a >> b;
}

inline void solve() {
    cout << (a > b ? a - b : b - a) << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
