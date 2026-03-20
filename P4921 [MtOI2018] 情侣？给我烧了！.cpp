#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int MAXN = 1000;

int fac[MAXN + 5], invfac[MAXN + 5], pow2[MAXN + 5], D[MAXN + 5];

int modpow(int a, int e) {
    int res = 1;
    while (e) {
        if (e & 1)
            res = 1LL * res * a % MOD;
        a = 1LL * a * a % MOD;
        e >>= 1;
    }
    return res;
}

void init() {
    fac[0] = 1;
    for (int i = 1; i <= MAXN; ++i)
        fac[i] = 1LL * fac[i - 1] * i % MOD;

    invfac[MAXN] = modpow(fac[MAXN], MOD - 2);
    for (int i = MAXN; i >= 1; --i)
        invfac[i - 1] = 1LL * invfac[i] * i % MOD;

    pow2[0] = 1;
    for (int i = 1; i <= MAXN; ++i)
        pow2[i] = 1LL * pow2[i - 1] * 2 % MOD;

    D[0] = 1;
    D[1] = 0;
    for (int m = 2; m <= MAXN; ++m) {
        D[m] = 4LL * m % MOD * (m - 1) % MOD *
               ((D[m - 1] + 2LL * (m - 1) % MOD * D[m - 2]) % MOD) % MOD;
    }
}

int main() {
    init();
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        for (int k = 0; k <= n; ++k) {
            // 组合数 C(n, k)
            int C = 1LL * fac[n] * invfac[k] % MOD * invfac[n - k] % MOD;
            // 排列数 P(n, k) = n! / (n-k)!
            int P = 1LL * fac[n] * invfac[n - k] % MOD;
            int ans = 1LL * C * P % MOD * pow2[k] % MOD * D[n - k] % MOD;
            printf("%d\n", ans);
        }
    }
    return 0;
}