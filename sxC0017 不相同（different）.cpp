#include <bits/stdc++.h>
using namespace std;

long long f[25];

signed main() {
    int n;
    cin >> n;
    f[1] = 0;
    f[2] = 1;
    for (int i = 3; i <= n; i++) {
        f[i] = (i - 1) * (f[i - 1] + f[i - 2]);
    }
    cout << f[n] << "\n";
    return 0;
}
