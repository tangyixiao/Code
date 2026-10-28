#include <bits/stdc++.h>
using namespace std;

int k;
long long f[50];

signed main() {
    cin >> k;
    f[1] = 1;
    f[2] = 1;
    for (int i = 3; i <= k; i++) {
        f[i] = f[i - 1] + f[i - 2];
    }
    cout << f[k] << "\n";
    return 0;
}
