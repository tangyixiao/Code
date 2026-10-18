#include <bits/stdc++.h>
using namespace std;

long long l, r;

inline long long f(long long x) {
    long long a = 0;
    for (long long p = 1; p <= x; p *= 10) {
        long long h = x / (p * 10), c = x / p % 10, d = x % p;
        a += h * p, a += c > 2 ? p : c == 2 ? d + 1
                                            : 0;
    }
    return a;
}

inline void input() {
    cin >> l >> r;
}

inline void solve() {
    cout << f(r) - f(l - 1) << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    solve();
    return 0;
}
