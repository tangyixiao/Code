#include <bits/stdc++.h>
using namespace std;

long long b, p, k;

inline void input() {
    cin >> b >> p >> k;
}

inline void solve() {
    long long e = p, r = 1 % k, a = b % k;
    while (p) {
        if (p & 1) {
            r = r * a % k;
        }
        a = a * a % k, p >>= 1;
    }
    printf("%lld^%lld mod %lld=%lld\n", b, e, k, r);
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}