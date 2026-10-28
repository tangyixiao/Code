#include <bits/stdc++.h>
using namespace std;

long long A, B, L, p, q, u, v, bu, bv, ba, bb;

signed main() {
    cin >> A >> B >> L;
    bu = -1, bv = 1, ba = 1, bb = 1;
    for (p = 1; p <= L; p++) {
        for (q = 1; q <= L; q++) {
            if (__gcd(p, q) != 1) {
                continue;
            }
            if (p * B < A * q) {
                continue;
            }
            u = p * B - A * q, v = q * B;
            if (bu < 0 || u * bv < bu * v) {
                bu = u, bv = v, ba = p, bb = q;
            }
        }
    }
    cout << ba << " " << bb << "\n";
    return 0;
}
