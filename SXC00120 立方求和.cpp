#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5, MOD = 10007;
int cnt, sp[N], pr[N];

long long pw(long long b, long long e) {
    long long r = 1;
    b %= MOD;
    for (; e > 0; e >>= 1) {
        if (e & 1) {
            r = r * b % MOD;
        }
        b = b * b % MOD;
    }
    return r;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    for (int i = 2; i < N; i++) {
        if (!sp[i]) {
            sp[i] = i;
            pr[cnt++] = i;
        }
        for (int j = 0; j < cnt && 1LL * i * pr[j] < N; j++) {
            sp[i * pr[j]] = pr[j];
            if (i % pr[j] == 0) {
                break;
            }
        }
    }
    long long inv2 = pw(2, MOD - 2);
    long long a, b;
    int cs = 0;
    for (; cin >> a >> b;) {
        cs++;
        long long ans = 1, x = a;
        for (; x > 1;) {
            int p = sp[x], e = 0;
            for (; x % p == 0; x /= p) {
                e++;
            }
            long long em = (e * b + 1) % MOD;
            long long mm = (em + 1) % MOD;
            long long s = em * mm % MOD * inv2 % MOD;
            ans = ans * (s * s % MOD) % MOD;
        }
        cout << "Case " << cs << ": " << ans % MOD << "\n";
    }
    return 0;
}
