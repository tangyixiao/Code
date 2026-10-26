#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
const int MOD = 12345;
int n, f[N];

signed main() {
    cin >> n;
    f[0] = 1;
    f[1] = 1;
    for (int i = 2; i <= n; i++) {
        f[i] = (f[i - 1] + 2 * f[i - 2]) % MOD;
    }
    cout << f[n] << "\n";
    return 0;
}
