#include <bits/stdc++.h>
using namespace std;

long long n, p;

inline void input() {
    cin >> n >> p;
}

inline void solve() {
    long long ans = -1;
    for (long long q = 2; q * q <= p; ++q) {
        if (p % q) {
            continue;
        }
        int d = 0;
        while (p % q == 0) {
            p /= q;
            ++d;
        }
        long long e = 0, t = n;
        while (t) {
            t /= q;
            e += t;
        }
        e /= d;
        if (ans < 0 || e < ans) {
            ans = e;
        }
    }
    if (p > 1) {
        long long e = 0, t = n;
        while (t) {
            t /= p;
            e += t;
        }
        if (ans < 0 || e < ans) {
            ans = e;
        }
    }
    cout << (ans < 0 ? 0 : ans) << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}
