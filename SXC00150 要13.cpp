#include <bits/stdc++.h>
using namespace std;

int d[15], len;
long long f[15][2][2][13][2];

long long go(int pos, int p1, int has, int mod, int tight) {
    if (pos < 0) {
        return (has == 1 && mod == 0) ? 1 : 0;
    }
    if (f[pos][p1][has][mod][tight] >= 0) {
        return f[pos][p1][has][mod][tight];
    }
    int up = tight ? d[pos] : 9;
    long long s = 0;
    for (int b = 0; b <= up; b++) {
        int nh = has;
        if (p1 == 1 && b == 3) {
            nh = 1;
        }
        s += go(pos - 1, b == 1 ? 1 : 0, nh, (mod * 10 + b) % 13, (tight == 1 && b == up) ? 1 : 0);
    }
    f[pos][p1][has][mod][tight] = s;
    return s;
}

long long solve(long long n) {
    if (n < 0) {
        return 0;
    }
    len = 0;
    long long t = n;
    if (t == 0) {
        d[len++] = 0;
    }
    while (t > 0) {
        d[len++] = (int)(t % 10);
        t /= 10;
    }
    memset(f, -1, sizeof(f));
    return go(len - 1, 0, 0, 0, 1);
}

signed main() {
    long long n;
    while (scanf("%lld", &n) == 1) {
        printf("%lld\n", solve(n));
    }
    return 0;
}
