#include <bits/stdc++.h>
using namespace std;

long long exgcd(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    long long g = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return g;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n;
    while (cin >> n) {
        long long m1, r1, m2, r2, i, bad = 0;
        cin >> m1 >> r1;
        for (i = 2; i <= n; i++) {
            cin >> m2 >> r2;
            if (bad) {
                continue;
            }
            long long x, y;
            long long g = exgcd(m1, m2, x, y);
            long long d = r2 - r1;
            if (d % g != 0) {
                bad = 1;
                continue;
            }
            long long l = m2 / g;
            long long t = (long long)((__int128)d / g * x % l);
            if (t < 0) {
                t += l;
            }
            long long nm = (long long)((__int128)m1 * l);
            r1 = (long long)(((__int128)r1 + (__int128)m1 * t) % nm);
            m1 = nm;
        }
        if (bad) {
            cout << -1 << "\n";
        } else {
            long long a = r1 % m1;
            if (a < 0) {
                a += m1;
            }
            if (a == 0) {
                a = m1;
            }
            cout << a << "\n";
        }
    }
    return 0;
}
