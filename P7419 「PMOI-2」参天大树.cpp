#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int MAXK = 1e6 + 5;

int pow2[MAXK], pow4[MAXK];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    pow2[0] = pow4[0] = 1;
    for (int i = 1; i < MAXK; ++i) {
        pow2[i] = (pow2[i - 1] * 2LL) % MOD;
        pow4[i] = (pow4[i - 1] * 4LL) % MOD;
    }

    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;

        if (k == 0) {
            cout << "0\n";
            continue;
        }
        long long term = (3LL * k - 4) % MOD;
        if (term < 0)
            term += MOD;
        long long ans = (1LL * pow4[k - 1] * term % MOD + pow2[k]) % MOD;
        cout << ans << '\n';
    }
    return 0;
}