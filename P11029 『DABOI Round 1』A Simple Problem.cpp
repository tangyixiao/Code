#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
int n, ans = 1;
int qpow(int a, int b) {
    int ret = 1;
    for (; b; b >>= 1, a = a * a % mod) {
        if (b & 1) {
            ret = ret * a % mod;
        }
    }
    return ret % mod;
}
main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    for (int i = 1; i <= n; i++) {
        ans = ans * qpow(i, i * ((n - i + 1) * (n - i + 2) / 2 % (mod - 1)) % (mod - 1)) % mod;
    }
    cout << ans;
    return 0;
}