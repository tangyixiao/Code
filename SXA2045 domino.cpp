#include <bits/stdc++.h>
using namespace std;

int n;
long long f[35];

signed main() {
    cin >> n;
    f[0] = 1, f[1] = 1, f[2] = 2;
    for (int i = 3; i <= n; i++) {
        f[i] = f[i - 1] + f[i - 2] + f[i - 3];
    }
    cout << f[n] << "\n";
    return 0;
}
