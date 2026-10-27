#include <bits/stdc++.h>
using namespace std;

unsigned long long A, B, C, K, M;

unsigned long long extgcd(unsigned long long a, unsigned long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long x1, y1;
    unsigned long long g = extgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (long long)(a / b) * y1;
    return g;
}

unsigned long long modinv(unsigned long long a, unsigned long long m) {
    long long x, y;
    extgcd(a, m, x, y);
    x %= (long long)m;
    if (x < 0) {
        x += (long long)m;
    }
    return (unsigned long long)x;
}

signed main() {
    while (scanf("%llu %llu %llu %llu", &A, &B, &C, &K) == 4) {
        if (A == 0 && B == 0 && C == 0 && K == 0) {
            break;
        }
        if (K >= 63) {
            K = 63;
        }
        M = 1ULL << K;
        unsigned long long d;
        if (B >= A) {
            d = B - A;
        } else {
            d = M - (A - B);
        }
        if (C == 0) {
            if (d == 0) {
                printf("0\n");
            } else {
                printf("FOREVER\n");
            }
            continue;
        }
        unsigned long long g = __gcd(C, M);
        if (d % g != 0) {
            printf("FOREVER\n");
            continue;
        }
        unsigned long long mm = M / g;
        unsigned long long dd = (d / g) % mm;
        unsigned long long cc = (C / g) % mm;
        unsigned long long inv = modinv(cc % mm, mm);
        unsigned long long t = (unsigned long long)(((__int128)dd * inv) % mm);
        printf("%llu\n", t);
    }
    return 0;
}
