#include <bits/stdc++.h>
using namespace std;

const long long P = 1000000007;
int n;

inline void input() {
    cin >> n;
}

inline void solve() {
    if (n <= 2) {
        cout << n << "\n";
        return;
    }
    long long a = 1, b = 1, c = 2;
    for (int i = 3; i <= n; i++) {
        long long t = (2 * c + a) % P;
        a = b, b = c, c = t;
    }
    cout << c << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
