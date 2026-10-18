#include <bits/stdc++.h>
using namespace std;

const int N = 105;
int n, k, a[N];

signed main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    long long ans = 0;
    for (int m = 1; m < (1 << n); m++) {
        if (__builtin_popcount(m) != k) {
            continue;
        }
        long long s = 0;
        for (int i = 0; i < n; i++) {
            if (m >> i & 1) {
                s += a[i];
            }
        }
        bool ok = s > 1;
        for (long long i = 2; ok && i * i <= s; i++) {
            if (s % i == 0) {
                ok = false;
            }
        }
        ans += ok;
    }
    cout << ans << "\n";
    return 0;
}
