#include <bits/stdc++.h>
using namespace std;

const long long P = 1e9 + 7;
long long n, k;

long long qpow(long long a, long long b) {
    long long r = 1;
    for (; b; b >>= 1, a = a * a % P) {
        if (b & 1) {
            r = r * a % P;
        }
    }
    return r;
}

signed main() {
    cin >> n;
    k = (long long)sqrtl((long double)n);
    for (; k > 0 && k * k > n; k--) {
    }
    for (; (k + 1) * (k + 1) <= n; k++) {
    }
    long long t = k % P;
    long long s = t * ((t + 1) % P) % P * ((2 * t + 1) % P) % P * qpow(6, P - 2) % P;
    cout << s << "\n";
    return 0;
}
