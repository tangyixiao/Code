#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
long long n, f, p, ans;

signed main() {
    cin >> n;
    f = 1, p = 1;
    for (int i = 1; i <= n; i++) {
        f = f * i % MOD;
        p = p * f % MOD;
    }
    ans = 1;
    for (int i = 1; i <= n; i++) {
        ans = ans * p % MOD;
    }
    cout << ans << "\n";
    return 0;
}
