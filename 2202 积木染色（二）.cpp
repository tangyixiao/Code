#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
const long long P = 1e9 + 7;
int n, m, p;

inline void input() {
    cin >> n >> m >> p;
}

inline long long qpow(long long a, long long b) {
    long long r = 1;
    for (; b; b >>= 1, a = a * a % P) {
        if (b & 1) {
            r = r * a % P;
        }
    }
    return r;
}

inline void solve() {
    if (p > n - 1 || p < 0) {
        cout << 0 << "\n";
        return;
    }
    long long u = 1, v = 1;
    for (int i = 1; i <= p; ++i) {
        u = u * (n - i) % P;
        v = v * i % P;
    }
    cout << u * qpow(v, P - 2) % P * m % P * qpow(m - 1, p) % P << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}