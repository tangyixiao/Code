#include <bits/stdc++.h>
using namespace std;

int n;
long long f[25];

signed main() {
    cin >> n;
    f[1] = 0;
    f[2] = 1;
    for (int i = 3; i <= n; i++) {
        f[i] = (long long)(i - 1) * (f[i - 1] + f[i - 2]);
    }
    cout << f[n] << "\n";
    return 0;
}
