#include <iostream>
using namespace std;

const int MOD = 998244353;
const int MAX = 2000005;

long long fact[MAX], invfact[MAX];
int a[300005];

long long modpow(long long x, long long e) {
    long long r = 1;
    while (e) {
        if (e & 1)
            r = r * x % MOD;
        x = x * x % MOD;
        e >>= 1;
    }
    return r;
}

long long C(int n, int k) {
    if (k < 0 || k > n)
        return 0;
    return fact[n] * invfact[k] % MOD * invfact[n - k] % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    fact[0] = 1;
    for (int i = 1; i < MAX; ++i)
        fact[i] = fact[i - 1] * i % MOD;
    invfact[MAX - 1] = modpow(fact[MAX - 1], MOD - 2);
    for (int i = MAX - 2; i >= 0; --i)
        invfact[i] = invfact[i + 1] * (i + 1) % MOD;

    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        for (int i = 1; i <= n; ++i)
            cin >> a[i];
        int op, l, r, m;
        cin >> op >> l >> r >> m;
        int k = 0;
        long long S = 0;
        for (int i = l; i <= r; ++i) {
            if (a[i] == -1)
                ++k;
            else
                S += a[i];
        }
        if (S > m) {
            cout << "0\n";
            continue;
        }
        int R = m - S;
        if (k == 0) {
            if (R == 0) {
                long long ans = 0, pre = 0;
                for (int i = l; i <= r; ++i) {
                    pre = (pre + a[i]) % MOD;
                    ans = (ans + pre * pre) % MOD;
                }
                cout << ans << '\n';
            } else {
                cout << "0\n";
            }
            continue;
        }
        long long tot = C(R + k - 1, k - 1);
        long long c1 = C(R + k - 1, k);
        long long c2 = C(R + k - 1, k + 1);
        long long A = 0, ans = 0;
        int cnt = 0;
        for (int i = l; i <= r; ++i) {
            if (a[i] == -1)
                ++cnt;
            else
                A = (A + a[i]) % MOD;
            long long t1 = tot * A % MOD * A % MOD;
            long long t2 = (long long)cnt * (2 * A + 1) % MOD * c1 % MOD;
            long long t3 = (long long)cnt * (cnt + 1) % MOD * c2 % MOD;
            ans = (ans + t1 + t2 + t3) % MOD;
        }
        cout << ans << '\n';
    }
    return 0;
}