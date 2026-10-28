#include <bits/stdc++.h>
using namespace std;

long long n, f[60][3][2];
int d[60], len;

long long dp(int pos, int r, int tight) {
    if (pos < 0) {
        return r == 0 ? 1 : 0;
    }
    if (f[pos][r][tight] >= 0) {
        return f[pos][r][tight];
    }
    int up = tight ? d[pos] : 1;
    long long s = 0;
    for (int b = 0; b <= up; b++) {
        s += dp(pos - 1, (r + b) % 3, (tight && b == up) ? 1 : 0);
    }
    f[pos][r][tight] = s;
    return s;
}

signed main() {
    scanf("%lld", &n);
    len = 0;
    long long t = n;
    while (t > 0) {
        d[len++] = (int)(t & 1);
        t >>= 1;
    }
    if (len == 0) {
        d[len++] = 0;
    }
    memset(f, -1, sizeof(f));
    long long ans = dp(len - 1, 0, 1);
    if (n >= 0) {
        ans--;
    }
    printf("%lld\n", ans);
    return 0;
}
