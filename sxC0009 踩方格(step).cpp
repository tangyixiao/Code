#include <bits/stdc++.h>
using namespace std;
const int N = 3e1 + 5;
long long f[N];
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    f[1] = 3;
    f[2] = 7;
    for (int i = 3; i <= n; i++) {
        f[i] = 2 * f[i - 1] + f[i - 2];
    }
    cout << f[n] << "\n";
    return 0;
}
