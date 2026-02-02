#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
const int inv6 = 166374059;
const int N = 5e6 + 5;
int T, n, m, fact[N], inv[N], ans;
inline int qpow(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1)
            res = 1ll * res * a % mod;
        a = 1ll * a * a % mod;
        b >>= 1;
    }
    return res;
}
inline void init() {
    fact[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = 1ll * fact[i - 1] * i % mod;
    }
    inv[N - 1] = qpow(fact[N - 1], mod - 2);
    for (int i = N - 2; i >= 0; i--) {
        inv[i] = 1ll * inv[i + 1] * (i + 1) % mod;
    }
    return;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    init();

    cin >> T;
    while (T--) {
        cin >> n >> m;
        ans ^= ((qpow(inv6, n) * qpow(5, n - m) % mod) * (((fact[n] * inv[m] % mod) * inv[n - m]) % mod) % mod);
    }
    cout << "tou\n";
    cout << ans << '\n';

    return 0;
}