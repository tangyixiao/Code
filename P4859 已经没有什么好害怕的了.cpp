#pragma G++ optimize("O3", "unroll-loops", "omit-frame-pointer", "inline")
#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 5, mod = 1e9 + 9;
int n, k, a[N], b[N], l[N], f[N][N], fac[N], ifac[N], g[N];
int C(int n, int m) {
    return 1ll * fac[n] * ifac[m] % mod * ifac[n - m] % mod;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> k;
    if ((n + k) & 1) {
        puts("0");
        exit(0);
    }
    k = (n + k) >> 1;
    ifac[0] = ifac[1] = fac[0] = fac[1] = 1;
    for (int i = 2; i < N; i++) {
        ifac[i] = -1ll * mod / i * ifac[mod % i] % mod;
    }
    for (int i = 2; i < N; i++) {
        fac[i] = 1ll * fac[i - 1] * i % mod, ifac[i] = 1ll * ifac[i - 1] * ifac[i] % mod;
    }

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);
    int loc = 0;
    for (int i = 1; i <= n; i++) {
        while (loc < n && b[loc + 1] < a[i]) {
            ++loc;
        }
        l[i] = loc;
    }
    f[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        f[i][0] = f[i - 1][0];
        for (int j = 1; j <= i; j++) {
            f[i][j] = (1ll * f[i - 1][j] + 1ll * f[i - 1][j - 1] * max(0, l[i] - j + 1) % mod) % mod;
        }
    }
    for (int i = 0; i <= n; i++) {
        g[i] = 1ll * f[n][i] * fac[n - i] % mod;
    }
    int ans = 0;
    for (int i = k; i <= n; i++) {
        if ((i - k) & 1) {
            (ans -= 1ll * C(i, k) * g[i] % mod) %= mod;
        } else {
            (ans += 1ll * C(i, k) * g[i] % mod) %= mod;
        }
    }
    cout << (ans + mod) % mod << "\n";
    return 0;
}