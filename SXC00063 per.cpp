#include <bits/stdc++.h>
using namespace std;

const int N = 505;
const long long MOD = 998244353;
int n, w[N][N], row[N];
long long f, ans;

long long pw(long long b, long long e) {
    long long r = 1;
    b %= MOD;
    while (e > 0) {
        if (e & 1) {
            r = r * b % MOD;
        }
        b = b * b % MOD;
        e >>= 1;
    }
    return r;
}

signed main() {
    if (fopen("per.in", "r")) {
        freopen("per.in", "r", stdin);
        freopen("per.out", "w", stdout);
    }
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        for (int j = i; j <= n; j++) {
            scanf("%d", &w[i][j]);
            row[i] = (row[i] + w[i][j]) % MOD;
        }
    }
    f = 1;
    for (int i = 2; i <= n; i++) {
        f = f * i % MOD;
    }
    ans = 0;
    for (int i = 1; i < n; i++) {
        long long d = n - i + 1;
        long long g = f * pw(d, MOD - 2) % MOD;
        ans = (ans + g * row[i]) % MOD;
    }
    printf("%lld\n", ans);
    return 0;
}
