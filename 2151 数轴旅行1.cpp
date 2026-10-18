#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

long long n, x, d;

inline void input() {
    cin >> n;
    d = 0;
    for (long long i = 1; i <= n; i++) {
        cin >> x;
        d = __gcd(d, x < 0 ? -x : x);
    }
}

inline void solve() {
    cout << d << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}