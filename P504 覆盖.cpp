#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, i;
int f[N];
signed main() {
    cin >> n;
    f[0] = 1;
    if (n >= 1) {
        f[1] = 1;
    }
    if (n >= 2) {
        f[2] = 2;
    }
    for (i = 3; i <= n; i++) {
        f[i] = (2 * f[i - 1] + f[i - 3]) % 10000;
    }
    cout << f[n] << "\n";
    return 0;
}
