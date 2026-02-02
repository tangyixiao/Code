#include <bits/stdc++.h>
using namespace std;

const int N = 1000002, mod = 10000;

int n, f[N], g[N];

int main() {

    cin >> n;

    f[0] = 1;

    f[1] = g[1] = 1;

    for (int i = 2; i <= n; i++) {
        f[i] = ((f[i - 1] + f[i - 2]) % mod + 2 * g[i - 2] % mod) % mod;

        g[i] = (g[i - 1] + f[i - 1]) % mod;
    }

    cout << f[n];

    return 0;
}
