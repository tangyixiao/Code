#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 9;
const int K = 1005;

long long k, b;
long long d[K], s[K], nd[K], ns[K];

signed main() {
    cin >> k >> b;
    d[0] = 1;
    long long w = 1 % k;
    for (long long t = 0; t < b; t++) {
        for (long long r = 0; r < k; r++) {
            nd[r] = 0;
            ns[r] = 0;
        }
        for (long long r = 0; r < k; r++) {
            if (d[r] == 0 && s[r] == 0) {
                continue;
            }
            nd[r] = (nd[r] + d[r]) % MOD;
            ns[r] = (ns[r] + s[r]) % MOD;
            long long r1 = (r + w) % k;
            nd[r1] = (nd[r1] + d[r]) % MOD;
            ns[r1] = (ns[r1] + s[r] + d[r]) % MOD;
        }
        for (long long r = 0; r < k; r++) {
            d[r] = nd[r];
            s[r] = ns[r];
        }
        w = w * 2 % k;
    }
    cout << s[0] % MOD << "\n";
    return 0;
}
