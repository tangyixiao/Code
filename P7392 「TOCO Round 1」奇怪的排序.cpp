#include <iostream>
using namespace std;

typedef long long ll;
const int N = 1e6 + 5;
const int mod = 1e9 + 7;

ll fac[N], inv_fac[N];

ll qpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void init() {
    fac[0] = 1;
    for (int i = 1; i < N; i++) {
        fac[i] = fac[i - 1] * i % mod;
    }
    inv_fac[N - 1] = qpow(fac[N - 1], mod - 2);
    for (int i = N - 2; i >= 0; i--) {
        inv_fac[i] = inv_fac[i + 1] * (i + 1) % mod;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    init();

    int T;
    cin >> T;

    while (T--) {
        int n, k;
        cin >> n >> k;

        if (k == 0) {
            cout << 1 << '\n';
            continue;
        }

        if (k >= 21 || (1 << k) >= n) {
            cout << fac[n] << '\n';
            continue;
        }

        int segment_cnt = 1 << k;
        int base_len = n / segment_cnt;
        int long_cnt = n % segment_cnt;
        int short_cnt = segment_cnt - long_cnt;

        ll prod = qpow(inv_fac[base_len], short_cnt) * qpow(inv_fac[base_len + 1], long_cnt) % mod;

        ll ans = fac[n] * prod % mod;
        cout << ans << '\n';
    }

    return 0;
}