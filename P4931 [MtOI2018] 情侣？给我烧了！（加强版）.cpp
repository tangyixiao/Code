#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int MAXN = 5000000;

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
    for (int n = 2; n <= MAXN; ++n) {
        D[n] = 4LL * n % MOD * (n - 1) % MOD *
               ((D[n - 1] + 2LL * (n - 1) % MOD * D[n - 2]) % MOD) % MOD;
    }
}

int main() {
    init();
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, k;
        scanf("%d%d", &n, &k);
        int ans = 1LL * fac[n] * fac[n] % MOD *
                  invfac[k] % MOD *
                  invfac[n - k] % MOD *
                  invfac[n - k] % MOD *
                  pow2[k] % MOD *
                  D[n - k] % MOD;
        printf("%d\n", ans);
    }
    return 0;
}