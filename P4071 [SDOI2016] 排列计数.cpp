#include <cstdio>

const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 5;

int fac[MAXN], invfac[MAXN], D[MAXN];

int qpow(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1)
            res = 1LL * res * a % MOD;
        a = 1LL * a * a % MOD;
        b >>= 1;
    }
    return res;
}

void init(int n) {
    fac[0] = 1;
    for (int i = 1; i <= n; ++i)
        fac[i] = 1LL * fac[i - 1] * i % MOD;

    invfac[n] = qpow(fac[n], MOD - 2);
    for (int i = n - 1; i >= 0; --i)
        invfac[i] = 1LL * invfac[i + 1] * (i + 1) % MOD;

    D[0] = 1;
    D[1] = 0;
    for (int i = 2; i <= n; ++i)
        D[i] = 1LL * (i - 1) * (D[i - 1] + D[i - 2]) % MOD;
}

int C(int n, int m) {
    if (m < 0 || m > n)
        return 0;
    return 1LL * fac[n] * invfac[m] % MOD * invfac[n - m] % MOD;
}

int main() {
    int T;
    scanf("%d", &T);

    init(1000000);

    while (T--) {
        int n, m;
        scanf("%d%d", &n, &m);

        if (m > n) {
            puts("0");
        } else {
            int ans = 1LL * C(n, m) * D[n - m] % MOD;
            printf("%d\n", ans);
        }
    }
    return 0;
}