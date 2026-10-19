#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;

int t, n;
long long x, a, b;

inline void input() {
    cin >> t;
}

inline void solve() {
    while (t--) {
        cin >> n;
        a = b = 0;
        for (int i = 1; i <= n; i++) {
            cin >> x;
            long long c = max(b, a + x);
            a = b, b = c;
        }
        cout << b << "\n";
    }
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
