#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, mod = 100003;
int n, k, f[N];
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    f[0] = f[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (i <= k) {
            f[i] = (f[i - 1] * 2) % mod;
        } else {
            f[i] = (f[i - 1] * 2 - f[i - k - 1] + mod) % mod;
        }
    }
    cout << (f[n] + mod) % mod;
    return 0;
}