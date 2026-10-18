#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int L, n, x, a, b;

inline void input() {
    cin >> L >> n;
    a = 0, b = 0;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        a = max(a, min(x, L - x)), b = max(b, max(x, L - x));
    }
}

inline void solve() {
    cout << a << " " << b << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}