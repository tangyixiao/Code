#include <bits/stdc++.h>
using namespace std;
int n, f[25], k;
signed main() {
    cin >> n;
    f[0] = f[1] = 1;
    f[k] = 0;
    for (int i = 2; i <= n; i++) {
        if (i != k) {
            f[i] = f[i - 1] + f[i - 2];
        }
    }
    cout << f[n];
    return 0;
}